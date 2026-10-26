int __stdcall sub_6D4540(int *a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  result = (int)a1;
  v3 = (_DWORD *)a1[88];
  v4 = a1[63];
  v5 = 1;
  v3[2] = 0;
  if ( v4 <= 1 )
  {
    v6 = a1[64];
    if ( a1[62] == 1 )
      v5 = *(_DWORD *)(v6 + 72);
    else
      v5 = *(_DWORD *)(v6 + 12);
  }
  v3[5] = v5;
  v3[3] = 0;
  v3[4] = 0;
  if ( a2 )
  {
    if ( a2 == 2 )
    {
      if ( !v3[16] )
      {
        v9 = *a1;
        *(_DWORD *)(v9 + 20) = 4;
        result = (*(int (__stdcall **)(int *))v9)(a1);
      }
      v3[1] = sub_6D4130;
    }
    else if ( a2 == 3 )
    {
      if ( !v3[16] )
      {
        v8 = *a1;
        *(_DWORD *)(v8 + 20) = 4;
        result = (*(int (__stdcall **)(int *))v8)(a1);
      }
      v3[1] = sub_6D4340;
    }
    else
    {
      v7 = *a1;
      *(_DWORD *)(v7 + 20) = 4;
      return (*(int (__stdcall **)(int *))v7)(a1);
    }
  }
  else
  {
    if ( v3[16] )
    {
      v10 = *a1;
      *(_DWORD *)(v10 + 20) = 4;
      result = (*(int (__stdcall **)(int *))v10)(a1);
    }
    v3[1] = sub_6D3E70;
  }
  return result;
}
