void **__fastcall sub_5BC5F0(void **a1, const void *a2, unsigned int a3, _DWORD *a4)
{
  void **result; // eax

  result = a1;
  qmemcpy(*a1, a2, a3);
  *a4 += a3;
  *a1 = (char *)*a1 + a3;
  return result;
}
