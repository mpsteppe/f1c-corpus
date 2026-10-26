void **__stdcall sub_569EB0(void **a1, const void *a2, unsigned int a3)
{
  void **result; // eax

  result = a1;
  qmemcpy(*a1, a2, a3);
  *a1 = (char *)*a1 + a3;
  return result;
}
