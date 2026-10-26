unsigned int __fastcall sub_59D490(void *a1, int a2, unsigned int a3)
{
  unsigned int result; // eax

  result = a3;
  qmemcpy(a1, (const void *)(a2 + dword_7F5E74), a3);
  dword_7F5E74 += a3;
  return result;
}
