int __stdcall sub_6B92EA(_DWORD *a1, int a2)
{
  unsigned int v2; // ebp
  unsigned int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned __int8 v10; // cl
  __int16 v11; // ax
  unsigned __int16 v12; // ax
  _WORD *v13; // ecx
  int v14; // eax
  int v15; // eax
  BOOL v16; // ebx
  unsigned int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // ecx
  unsigned __int8 v25; // al
  int v26; // ecx
  int v27; // eax
  unsigned __int8 v28; // cl
  int v29; // ecx
  int v30; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 < 0x106 )
    {
      sub_6B8DC8((int)a1);
      v3 = a1[27];
      if ( v3 < 0x106 && !a2 )
        return 0;
      if ( !v3 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = a1[25];
      v5 = a1[19] & (*(unsigned __int8 *)(a1[12] + v4 + 2) ^ (a1[16] << a1[20]));
      v6 = a1[15];
      a1[16] = v5;
      v2 = *(unsigned __int16 *)(v6 + 2 * v5);
      *(_WORD *)(a1[14] + 2 * (v4 & a1[11])) = v2;
      *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
    }
    a1[28] = a1[22];
    a1[23] = a1[26];
    a1[22] = 2;
    if ( v2 && a1[28] < a1[30] && a1[25] - v2 <= a1[9] - 262 )
    {
      if ( a1[32] != 2 )
        a1[22] = sub_6B8C7E(a1, v2);
      v7 = a1[22];
      if ( v7 <= 5 && (a1[32] == 1 || v7 == 3 && (unsigned int)(a1[25] - a1[26]) > 0x1000) )
        a1[22] = 2;
    }
    v8 = a1[28];
    if ( v8 < 3 || a1[22] > v8 )
    {
      if ( a1[24] )
      {
        v25 = *(_BYTE *)(a1[25] + a1[12] - 1);
        *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
        *(_BYTE *)(a1[1444] + a1[1446]++) = v25;
        ++LOWORD(a1[v25 + 35]);
        if ( a1[1446] == a1[1445] - 1 )
        {
          v26 = a1[21];
          if ( v26 < 0 )
            v27 = 0;
          else
            v27 = v26 + a1[12];
          sub_6DAAC0(a1, v27, a1[25] - v26, 0);
          a1[21] = a1[25];
          sub_6B88EE(*a1);
        }
        ++a1[25];
        --a1[27];
        goto LABEL_32;
      }
      ++a1[25];
      --a1[27];
      a1[24] = 1;
    }
    else
    {
      v9 = a1[25] + a1[27] - 3;
      v10 = *((_BYTE *)a1 + 112) - 3;
      v11 = *((_WORD *)a1 + 50) - *((_WORD *)a1 + 46) - 1;
      *(_WORD *)(a1[1447] + 2 * a1[1446]) = v11;
      *(_BYTE *)(a1[1444] + a1[1446]++) = v10;
      v12 = v11 - 1;
      v13 = &a1[(unsigned __int8)byte_748810[v10] + 292];
      ++*v13;
      if ( v12 >= 0x100u )
        v14 = (unsigned __int8)byte_748710[v12 >> 7];
      else
        v14 = (unsigned __int8)byte_748610[v12];
      ++LOWORD(a1[v14 + 608]);
      v15 = a1[28];
      v16 = a1[1446] == a1[1445] - 1;
      a1[27] += 1 - v15;
      a1[28] = v15 - 2;
      do
      {
        v17 = ++a1[25];
        if ( v17 <= v9 )
        {
          v18 = a1[19] & (*(unsigned __int8 *)(a1[12] + v17 + 2) ^ (a1[16] << a1[20]));
          v19 = a1[15];
          a1[16] = v18;
          v2 = *(unsigned __int16 *)(v19 + 2 * v18);
          *(_WORD *)(a1[14] + 2 * (v17 & a1[11])) = v2;
          *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
        }
      }
      while ( a1[28]-- != 1 );
      a1[24] = 0;
      v21 = ++a1[25];
      a1[22] = 2;
      if ( v16 )
      {
        v22 = a1[21];
        if ( v22 < 0 )
          v23 = 0;
        else
          v23 = v22 + a1[12];
        sub_6DAAC0(a1, v23, v21 - v22, 0);
        a1[21] = a1[25];
        sub_6B88EE(*a1);
LABEL_32:
        if ( !*(_DWORD *)(*a1 + 16) )
          return 0;
      }
    }
  }
  if ( a1[24] )
  {
    v28 = *(_BYTE *)(a1[25] + a1[12] - 1);
    *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
    *(_BYTE *)(a1[1444] + a1[1446]++) = v28;
    ++LOWORD(a1[v28 + 35]);
    a1[24] = 0;
  }
  v29 = a1[21];
  if ( v29 < 0 )
    v30 = 0;
  else
    v30 = v29 + a1[12];
  sub_6DAAC0(a1, v30, a1[25] - v29, a2 == 4);
  a1[21] = a1[25];
  sub_6B88EE(*a1);
  if ( *(_DWORD *)(*a1 + 16) )
    return 2 * (a2 == 4) + 1;
  if ( a2 != 4 )
    return 0;
  return 2;
}
