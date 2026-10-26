int __stdcall sub_6D0F00(int *a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  bool v5; // zf

  result = (int)a1;
  v3 = (_DWORD *)a1[109];
  if ( a2 )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 4;
    result = (*(int (__stdcall **)(int *))v4)(a1);
    v3[6] = 0;
    v3[5] = 0;
    return result;
  }
  if ( a1[21] )
  {
    v5 = v3[3] == 0;
    v3[1] = sub_6D0E80;
    if ( v5 )
    {
      result = (*(int (__stdcall **)(int *, _DWORD, _DWORD, _DWORD, int))(a1[1] + 28))(a1, v3[2], 0, v3[4], 1);
      v3[6] = 0;
      v3[5] = 0;
      v3[3] = result;
      return result;
    }
  }
  else
  {
    result = a1[114];
    v3[1] = *(_DWORD *)(result + 4);
  }
  v3[6] = 0;
  v3[5] = 0;
  return result;
}
