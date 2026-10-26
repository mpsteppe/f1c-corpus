int __stdcall sub_6B5A60(int *a1, _DWORD *a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v5; // ebx
  int *v6; // edi
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  unsigned int v13; // edi
  int v14; // eax
  unsigned int v15; // edi
  unsigned int i; // ebx
  int v18; // eax
  int v19; // [esp+14h] [ebp+8h]

  v5 = a3 + a4;
  if ( a3 + a4 <= a2[1] && a4 <= a2[3] && *a2 )
  {
    v6 = a1;
  }
  else
  {
    v6 = a1;
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 22;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  v8 = a2[6];
  if ( a3 < v8 || v5 > v8 + a2[4] )
  {
    if ( !a2[10] )
    {
      v9 = *v6;
      *(_DWORD *)(v9 + 20) = 69;
      (*(void (__stdcall **)(int *))v9)(v6);
    }
    if ( a2[9] )
    {
      sub_6B5910((int)a2, (int)v6, 1);
      a2[9] = 0;
    }
    v10 = a3;
    if ( a3 <= a2[6] )
    {
      v10 = v5 - a2[4];
      if ( v10 < 0 )
        v10 = 0;
    }
    a2[6] = v10;
    sub_6B5910((int)a2, (int)v6, 0);
  }
  v11 = a2[7];
  if ( v11 >= v5 )
  {
LABEL_27:
    if ( !a5 )
      return *a2 + 4 * (a3 - a2[6]);
LABEL_28:
    a2[9] = 1;
    return *a2 + 4 * (a3 - a2[6]);
  }
  if ( v11 >= a3 )
  {
    v13 = a2[7];
  }
  else
  {
    if ( a5 )
    {
      v12 = *v6;
      *(_DWORD *)(v12 + 20) = 22;
      (*(void (__stdcall **)(int *))v12)(v6);
    }
    v13 = a3;
  }
  if ( a5 )
    a2[7] = v5;
  if ( a2[8] )
  {
    v19 = a2[2];
    v14 = a2[6];
    v15 = v13 - v14;
    for ( i = v5 - v14; v15 < i; ++v15 )
      sub_6B6070(*(_DWORD *)(*a2 + 4 * v15), v19);
    goto LABEL_27;
  }
  if ( a5 )
    goto LABEL_28;
  v18 = *a1;
  *(_DWORD *)(v18 + 20) = 22;
  (*(void (__stdcall **)(int *))v18)(a1);
  return *a2 + 4 * (a3 - a2[6]);
}
