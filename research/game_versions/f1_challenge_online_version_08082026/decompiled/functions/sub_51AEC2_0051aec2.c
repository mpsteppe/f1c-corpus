_DWORD *__cdecl sub_51AEC2(int a1)
{
  _DWORD *v1; // eax
  int v2; // ecx
  _DWORD *result; // eax

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 88);
  *(_DWORD *)(a1 + 404) = v1;
  v2 = 4;
  *v1 = sub_51AD93;
  v1[1] = sub_51A9C6;
  result = v1 + 13;
  do
  {
    result[4] = 0;
    *result++ = 0;
    --v2;
  }
  while ( v2 );
  return result;
}
