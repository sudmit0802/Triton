//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_AARCH64OPERANDPROPERTIES
#define TRITON_AARCH64OPERANDPROPERTIES

#include <triton/archEnums.hpp>
#include <triton/dllexport.hpp>
#include <triton/tritonTypes.hpp>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  //! The Triton namespace
  namespace arch {
  /*!
   *  \ingroup triton
   *  \addtogroup arch
   *  @{
   */

    /*! \class AArch64OperandProperties
     *  \brief This class is used to represent specific properties of an AArch64 operand.
     */
    class AArch64OperandProperties {
      protected:
        //! The extend type.
        triton::arch::aarch64::extend_e extendType;

        //! The shift type.
        triton::arch::aarch64::shift_e shiftType;

        //! The shift value.
        triton::uint32 shiftValue;

      public:
        //! Constructor.
        TRITON_EXPORT AArch64OperandProperties();

        //! Constructor.
        TRITON_EXPORT AArch64OperandProperties(triton::arch::aarch64::extend_e extendType, triton::arch::aarch64::shift_e shiftType, triton::uint32 shiftValue);

        //! Constructor by copy.
        TRITON_EXPORT AArch64OperandProperties(const AArch64OperandProperties& other);

        //! Returns the type of the shift.
        TRITON_EXPORT triton::arch::aarch64::shift_e getShiftType(void) const;

        //! Returns the type of the extend.
        TRITON_EXPORT triton::arch::aarch64::extend_e getExtendType(void) const;

        //! Returns the value of the shift.
        TRITON_EXPORT triton::uint32 getShiftValue(void) const;

        //! Sets the type of the shift.
        TRITON_EXPORT void setShiftType(triton::arch::aarch64::shift_e type);

        //! Sets the type of the extend.
        TRITON_EXPORT void setExtendType(triton::arch::aarch64::extend_e type);

        //! Sets the value of the shift.
        TRITON_EXPORT void setShiftValue(triton::uint32 value);

        //! Copy an AArch64OperandProperties.
        TRITON_EXPORT AArch64OperandProperties& operator=(const AArch64OperandProperties& other);
    };

  /*! @} End of arch namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_AARCH64OPERANDPROPERTIES */
