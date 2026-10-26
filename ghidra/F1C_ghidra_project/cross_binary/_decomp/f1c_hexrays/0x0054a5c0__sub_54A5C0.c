// f1c  0x0054a5c0  size=51
unsigned int __fastcall sub_54A5C0(void *a1, int a2, unsigned int a3)
{
  unsigned int result; // eax

  result = a3;
  qmemcpy(a1, (const void *)(a2 + dword_8B8F3C), a3);
  dword_8B8F3C += a3;
  return result;
}
