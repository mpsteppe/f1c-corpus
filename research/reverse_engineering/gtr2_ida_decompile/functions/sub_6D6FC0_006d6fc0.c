int __stdcall sub_6D6FC0(int *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  int result; // eax
  int v5; // ecx

  v2 = (_DWORD *)a1[87];
  if ( a2 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 4;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  result = a1[8];
  v5 = 2 * a1[61];
  v2[12] = result;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = v5;
  return result;
}
