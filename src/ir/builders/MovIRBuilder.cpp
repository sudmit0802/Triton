#include <iostream>
#include <sstream>
#include <stdexcept>

#include "MovIRBuilder.h"
#include "SMT2Lib.h"
#include "SymbolicEngine.h"


MovIRBuilder::MovIRBuilder(uint64_t address, const std::string &disassembly):
  BaseIRBuilder(address, disassembly) {

}


void MovIRBuilder::regImm(const ContextHandler &ctxH, AnalysisProcessor &ap, Inst &inst) const {
  std::stringstream expr;
  uint64_t          reg = std::get<1>(_operands[0]);
  uint64_t          imm = std::get<1>(_operands[1]);

  expr << smt2lib::bv(imm, ctxH.getRegisterSize(reg));

  inst.addElement(ap.createRegSE(expr, ctxH.translateRegID(reg)));
}


void MovIRBuilder::regReg(const ContextHandler &ctxH, AnalysisProcessor &ap, Inst &inst) const {
  std::stringstream expr;
  uint64_t          reg1    = std::get<1>(_operands[0]);
  uint64_t          reg2    = std::get<1>(_operands[1]);

  uint64_t          symReg2 = ap.getRegSymbolicID(ctxH.translateRegID(reg2));

  if (symReg2 != UNSET)
    expr << "#" << std::dec << symReg2;
  else
    expr << smt2lib::bv(ctxH.getRegisterValue(reg2), ctxH.getRegisterSize(reg1));

  inst.addElement(ap.createRegSE(expr, ctxH.translateRegID(reg1)));
}


void MovIRBuilder::regMem(const ContextHandler &ctxH, AnalysisProcessor &ap, Inst &inst) const {
  std::stringstream expr;
  uint32_t          readSize = std::get<2>(_operands[1]);
  uint64_t          mem      = std::get<1>(_operands[1]);
  uint64_t          reg      = std::get<1>(_operands[0]);

  uint64_t          symMem   = ap.getMemorySymbolicID(mem);

  if (symMem != UNSET)
    expr << "#" << std::dec << symMem;
  else
    expr << smt2lib::bv(ctxH.getMemoryValue(mem, readSize), readSize);

  inst.addElement(ap.createRegSE(expr, ctxH.translateRegID(reg)));
}


void MovIRBuilder::memImm(const ContextHandler &ctxH, AnalysisProcessor &ap, Inst &inst) const {
  std::stringstream expr;
  uint32_t          writeSize = std::get<2>(_operands[0]);
  uint64_t          mem       = std::get<1>(_operands[0]);
  uint64_t          imm       = std::get<1>(_operands[1]);

  expr << smt2lib::bv(imm, writeSize);

  inst.addElement(ap.createMemSE(expr, mem));
}


void MovIRBuilder::memReg(const ContextHandler &ctxH, AnalysisProcessor &ap, Inst &inst) const {
  std::stringstream expr;
  uint32_t          writeSize = std::get<2>(_operands[0]);
  uint64_t          mem       = std::get<1>(_operands[0]);
  uint64_t          reg       = std::get<1>(_operands[1]);

  uint64_t          symReg    = ap.getRegSymbolicID(ctxH.translateRegID(reg));

  if (symReg != UNSET)
    expr << "#" << std::dec << symReg;
  else
    expr << smt2lib::bv(ctxH.getRegisterValue(reg), writeSize);

  inst.addElement(ap.createMemSE(expr, mem));
}


Inst *MovIRBuilder::process(const ContextHandler &ctxH, AnalysisProcessor &ap) const {
  checkSetup();

  Inst *inst = new Inst(_address, _disas);

  try {
    templateMethod(ctxH, ap, *inst, _operands, "MOV");
  }
  catch (std::exception &e) {
    delete inst;
    throw e;
  }

  return inst;
}

