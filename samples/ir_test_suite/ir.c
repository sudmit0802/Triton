
// gcc -masm=intel ./ir.c -o ir

void check(void)
{
  int tab[4] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};

  // Check concat symbolic expression
  asm("mov sil, 0x99");
  asm("cmp rsi, 0xffffffffffffff99");

  asm("mov rax, -1");
  asm("mov al, 0x99");
  asm("mov ax, 0x99");
  asm("mov eax, 0x99");

  asm("mov rax, -1");
  asm("xor al, 0x99");
  asm("xor ax, 0x99");
  asm("xor eax, 0x99");

  asm("clc");
  asm("cld");
  asm("cmc");
  asm("mov eax, 32");
  asm("cbw");
  asm("mov ecx, 1");
  asm("mov ebx, eax");
  asm("mov rbx, qword ptr [rsp-0x2]");
  asm("mov rax, 2");
  asm("mov rcx, qword ptr [rsp+rax*1]");
  asm("mov qword ptr [rsp+rax*1], rcx");
  asm("add ecx, ebx");
  asm("adc eax, ecx");
  asm("inc eax");
  asm("test eax, eax");
  asm("sbb eax, ecx");
  asm("cmp ecx, eax");
  asm("mov ecx, 3");
  asm("mov ebx, 5");
  asm("cmp ecx, 3");
  asm("cmovb eax, ebx");
  asm("cmovl eax, ebx");
  asm("cmovno eax, ebx");
  asm("cmovnp eax, ebx");
  asm("cmovns eax, ebx");
  asm("cmovnz eax, ebx");
  asm("cmovo eax, ebx");
  asm("cmovp eax, ebx");
  asm("cmovs eax, ebx");
  asm("cmovz eax, ebx");
  asm("mov al, -1");
  asm("movsx eax, al");
  asm("movzx ecx, al");
  asm("movzx rcx, al");
  asm("movzx rdx, word ptr [rsp-0x2]");
  asm("movsx rax, word ptr [rsp-0x2]");
  asm("setz al");
  asm("mov rax, 3");
  asm("neg rax");
  asm("mov rax, 3");
  asm("mov rbx, 5");
  asm("xchg rax, rbx");
  asm("xchg [rsp-0x2], rax");
  asm("mov rbx, 9");
  asm("mov rax, 8");
  asm("lea rsi, [rbx]");
  asm("lea rsi, [rbx+8]");
  asm("lea rsi, [rbx+8*rax]");
  asm("lea rsi, [rbx+8*rax+4]");
  asm("lea rsi, [rbx+8+4*rax]");
  asm("cqo");

  // Check concat symbolic expression
  asm("mov rsi, 0xffffffffffffffff");
  asm("mov sil, 0x99");
  asm("cmp rsi, 0xffffffffffffff99");

  // SSE
  asm("movapd xmm0, xmmword ptr [%0]" :: "r"(tab));
  asm("movapd xmm1, xmm2");
  asm("movapd xmm3, xmm0");
  asm("movaps xmm0, xmmword ptr [%0]" :: "r"(tab));
  asm("movaps xmm1, xmm2");
  asm("movaps xmm3, xmm0");
  asm("movdqa xmm4, xmm2");
  asm("movdqu xmm5, xmm0");
  asm("orpd xmm0, xmm1");
  asm("orps xmm1, xmm3");
  asm("xorpd xmm0, xmm1");
  asm("xorps xmm1, xmm3");
  asm("andpd xmm1, xmm3");
  asm("andps xmm1, xmm3");
  asm("andnpd xmm1, xmm3");
  asm("andnps xmm1, xmm3");
}

int main(){
  check();
}

