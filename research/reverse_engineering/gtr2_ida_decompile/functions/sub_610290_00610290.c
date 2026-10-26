unsigned int __stdcall sub_610290(unsigned int *a1)
{
  signed int v1; // edi
  int v2; // ebx
  signed int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  signed int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int result; // eax

  v1 = 0;
  if ( (int)a1[90] > 0 )
  {
    v2 = 0;
    do
    {
      v3 = a1[90];
      if ( v1 >= v3 )
        v4 = 0;
      else
        v4 = v2 + a1[91];
      if ( *(_DWORD *)(v4 + 44) )
      {
        v5 = v1 >= v3 ? 0 : v2 + a1[91];
        v6 = *(_DWORD *)(v5 + 44);
        v7 = *(_DWORD *)(v6 + 12);
        if ( v7 <= 0 || (v8 = v7 - 1, (*(_DWORD *)(v6 + 12) = v8) == 0) )
          sub_60B4D0();
      }
      v9 = a1[90];
      if ( v1 >= v9 )
        v10 = 0;
      else
        v10 = v2 + a1[91];
      if ( *(_DWORD *)(v10 + 48) )
      {
        v11 = v1 >= v9 ? 0 : v2 + a1[91];
        v12 = *(_DWORD *)(v11 + 48);
        v13 = *(_DWORD *)(v12 + 12);
        if ( v13 <= 0 || (v14 = v13 - 1, (*(_DWORD *)(v12 + 12) = v14) == 0) )
        {
          if ( v1 >= (int)a1[90] )
            v15 = 0;
          else
            v15 = v2 + a1[91];
          sub_60BA90(*(char **)(v15 + 48));
        }
      }
      if ( v1 >= (int)a1[90] )
        v16 = 0;
      else
        v16 = v2 + a1[91];
      *(_DWORD *)(v16 + 44) = 0;
      if ( v1 >= (int)a1[90] )
        v17 = 0;
      else
        v17 = v2 + a1[91];
      *(_DWORD *)(v17 + 52) = 0;
      if ( v1 >= (int)a1[90] )
        v18 = 0;
      else
        v18 = v2 + a1[91];
      *(_DWORD *)(v18 + 48) = 0;
      if ( v1 >= (int)a1[90] )
        v19 = 0;
      else
        v19 = v2 + a1[91];
      *(_DWORD *)(v19 + 56) = 0;
      ++v1;
      v2 += 108;
    }
    while ( v1 < (int)a1[90] );
  }
  result = *a1 & 0xFFFEE7FF;
  *a1 = result;
  return result;
}
