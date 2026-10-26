unsigned int __stdcall sub_5D70A0(void *a1, const void *a2, unsigned int a3)
{
  unsigned int result; // eax

  result = a3;
  qmemcpy(a1, a2, a3);
  return result;
}
