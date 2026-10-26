int *__cdecl sub_5975F4(int *a1)
{
  int *result; // eax
  unsigned int v2; // edx
  int v3; // edi
  int v4; // ecx

  result = a1;
  v2 = a1[2];
  v3 = a1[1];
  a1[1] = *(__int64 *)(a1 + 1) >> 1;
  v4 = (v3 << 31) | ((unsigned int)*a1 >> 1);
  a1[2] = v2 >> 1;
  *a1 = v4;
  return result;
}
