const void **__stdcall sub_57A1B0(const void **a1, void *a2, unsigned int a3)
{
  const void **result; // eax

  result = a1;
  qmemcpy(a2, *a1, a3);
  *a1 = (char *)*a1 + a3;
  return result;
}

