_DWORD *__cdecl sub_5952E9(int a1, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx

  result = a2;
  v3 = 3;
  do
  {
    *(_DWORD *)((char *)result + a1 - (_DWORD)a2) = *result;
    ++result;
    --v3;
  }
  while ( v3 );
  return result;
}

