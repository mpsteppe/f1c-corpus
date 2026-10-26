int __stdcall sub_6B5BA0(int *a1, _DWORD *a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v6; // edi
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edi
  int v15; // ebx
  bool v16; // cf
  int v18; // eax
  unsigned int v19; // [esp+20h] [ebp+14h]
  unsigned int v20; // [esp+20h] [ebp+14h]

  v6 = a3 + a4;
  v19 = a3 + a4;
  if ( v19 > a2[1] || a4 > a2[3] || !*a2 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 22;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  v8 = a2[6];
  if ( a3 < v8 || v6 > v8 + a2[4] )
  {
    if ( !a2[10] )
    {
      v9 = *a1;
      *(_DWORD *)(v9 + 20) = 69;
      (*(void (__stdcall **)(int *))v9)(a1);
    }
    if ( a2[9] )
    {
      sub_6B59B0((int)a2, (int)a1, 1);
      a2[9] = 0;
    }
    v10 = a3;
    if ( a3 <= a2[6] )
    {
      v10 = v6 - a2[4];
      if ( v10 < 0 )
        v10 = 0;
    }
    a2[6] = v10;
    sub_6B59B0((int)a2, (int)a1, 0);
  }
  v11 = a2[7];
  if ( v11 >= v19 )
  {
LABEL_25:
    if ( !a5 )
      return *a2 + 4 * (a3 - a2[6]);
LABEL_26:
    a2[9] = 1;
    return *a2 + 4 * (a3 - a2[6]);
  }
  if ( v11 < a3 )
  {
    if ( a5 )
    {
      v12 = *a1;
      *(_DWORD *)(v12 + 20) = 22;
      (*(void (__stdcall **)(int *))v12)(a1);
    }
    v11 = a3;
  }
  if ( a5 )
    a2[7] = v19;
  if ( a2[8] )
  {
    v13 = a2[6];
    v14 = v11 - v13;
    v15 = a2[2] << 7;
    v16 = v14 < v19 - v13;
    v20 = v19 - v13;
    if ( v16 )
    {
      do
        sub_6B6070(*(_DWORD *)(*a2 + 4 * v14++), v15);
      while ( v14 < v20 );
    }
    goto LABEL_25;
  }
  if ( a5 )
    goto LABEL_26;
  v18 = *a1;
  *(_DWORD *)(v18 + 20) = 22;
  (*(void (__stdcall **)(int *))v18)(a1);
  return *a2 + 4 * (a3 - a2[6]);
}
