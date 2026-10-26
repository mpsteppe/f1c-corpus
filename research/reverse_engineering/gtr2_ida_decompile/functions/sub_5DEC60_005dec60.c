unsigned int __stdcall sub_5DEC60(void *a1, _DWORD *a2, unsigned int a3)
{
  unsigned int result; // eax

  result = a3;
  qmemcpy(a1, (const void *)(a2[3] + *a2), a3);
  a2[3] += a3;
  return result;
}
