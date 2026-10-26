_DWORD *__usercall sub_6B4A10@<eax>(int *a1@<esi>)
{
  _DWORD *v1; // ebx
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  BOOL v8; // eax
  _DWORD *result; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edx

  v1 = (_DWORD *)a1[106];
  sub_6B4780(a1);
  sub_6B4990((int)a1);
  v1[3] = 0;
  v1[4] = sub_6B4700(v2, a1);
  v3 = a1[21];
  v1[5] = 0;
  v1[6] = 0;
  if ( !v3 || !a1[16] )
  {
    a1[25] = 0;
    a1[26] = 0;
    a1[27] = 0;
  }
  if ( v3 )
  {
    if ( a1[17] )
    {
      v4 = *a1;
      *(_DWORD *)(v4 + 20) = 47;
      (*(void (__stdcall **)(int *))v4)(a1);
    }
    if ( a1[30] == 3 )
    {
      if ( a1[34] )
      {
        a1[26] = 1;
        goto LABEL_10;
      }
      if ( a1[23] )
      {
        a1[27] = 1;
        goto LABEL_10;
      }
    }
    else
    {
      a1[26] = 0;
      a1[27] = 0;
      a1[34] = 0;
    }
    a1[25] = 1;
LABEL_10:
    if ( a1[25] )
    {
      v5 = *a1;
      *(_DWORD *)(v5 + 20) = 48;
      (*(void (__stdcall **)(int *))v5)(a1);
    }
    if ( a1[27] || a1[26] )
    {
      v6 = *a1;
      *(_DWORD *)(v6 + 20) = 48;
      (*(void (__stdcall **)(int *))v6)(a1);
    }
  }
  if ( !a1[17] )
  {
    if ( v1[4] )
    {
      sub_6D3A70(a1);
    }
    else
    {
      sub_6D2DE0(a1);
      sub_6D1E70(a1);
    }
    sub_6D0F80(a1, a1[27]);
  }
  sub_6D0DF0(a1);
  if ( a1[57] )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 1;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  else if ( a1[56] )
  {
    sub_6D0A20(a1);
  }
  else
  {
    sub_6CFE20(a1);
  }
  v8 = *(_DWORD *)(a1[110] + 16) || a1[16];
  sub_6CF290(a1, v8);
  if ( !a1[17] )
    sub_6CE3F0(a1, 0);
  (*(void (__stdcall **)(int *))(a1[1] + 24))(a1);
  (*(void (__stdcall **)(int *))(a1[110] + 8))(a1);
  result = (_DWORD *)a1[2];
  if ( result && !a1[16] && *(_DWORD *)(a1[110] + 16) )
  {
    v10 = a1[9];
    if ( a1[56] )
      v10 = 3 * v10 + 2;
    v11 = v10 * a1[81];
    result[1] = 0;
    result[2] = v11;
    v12 = a1[27];
    result[3] = 0;
    result[4] = (v12 != 0) + 2;
    ++v1[3];
  }
  return result;
}
