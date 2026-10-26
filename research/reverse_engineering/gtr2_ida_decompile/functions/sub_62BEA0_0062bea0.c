int __fastcall sub_62BEA0(int *a1, int a2)
{
  int v2; // edi
  unsigned int v4; // ebp
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned __int8 v14; // cl
  __int16 v15; // ax
  unsigned __int16 v16; // ax
  int v17; // eax
  int v18; // eax
  BOOL v19; // ebx
  unsigned int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v24; // edx
  int v25; // eax
  unsigned __int8 v27; // al
  int v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // ecx
  int v32; // eax
  unsigned __int8 v33; // al
  int v34; // eax
  int v35; // eax

  v2 = a2;
  v4 = 0;
  while ( 1 )
  {
    v5 = *(int *)((char *)a1 + 106);
    if ( v5 < 0x106 )
    {
      sub_62B790(a1);
      v5 = *(int *)((char *)a1 + 106);
      if ( v5 < 0x106 && !v2 )
        return 0;
      if ( !v5 )
        break;
    }
    if ( v5 >= 3 )
    {
      v6 = *(int *)((char *)a1 + 98);
      v7 = *(int *)((char *)a1 + 58);
      v8 = *(int *)((char *)a1 + 74)
         & (*(unsigned __int8 *)(*(int *)((char *)a1 + 46) + v6 + 2)
          ^ (*(int *)((char *)a1 + 62) << *(int *)((char *)a1 + 78)));
      *(int *)((char *)a1 + 62) = v8;
      v4 = *(unsigned __int16 *)(v7 + 2 * v8);
      *(_WORD *)(*(int *)((char *)a1 + 54) + 2 * (v6 & *(int *)((char *)a1 + 42))) = v4;
      *(_WORD *)(*(int *)((char *)a1 + 58) + 2 * *(int *)((char *)a1 + 62)) = *((_WORD *)a1 + 49);
    }
    v9 = *(int *)((char *)a1 + 86);
    v10 = *(int *)((char *)a1 + 102);
    *(int *)((char *)a1 + 110) = v9;
    *(int *)((char *)a1 + 90) = v10;
    *(int *)((char *)a1 + 86) = 2;
    if ( v4 && v9 < *(int *)((char *)a1 + 118) && *(int *)((char *)a1 + 98) - v4 <= *(int *)((char *)a1 + 34) - 262 )
    {
      if ( *(int *)((char *)a1 + 126) != 2 )
        *(int *)((char *)a1 + 86) = sub_62B620(v4, (int)a1);
      v11 = *(int *)((char *)a1 + 86);
      if ( v11 <= 5
        && (*(int *)((char *)a1 + 126) == 1
         || v11 == 3 && (unsigned int)(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 102)) > 0x1000) )
      {
        *(int *)((char *)a1 + 86) = 2;
      }
    }
    v12 = *(int *)((char *)a1 + 110);
    if ( v12 < 3 || *(int *)((char *)a1 + 86) > v12 )
    {
      if ( *(int *)((char *)a1 + 94) )
      {
        v27 = *(_BYTE *)(*(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 46) - 1);
        *(_WORD *)(*(int *)((char *)a1 + 5783) + 2 * *(int *)((char *)a1 + 5779)) = 0;
        *(_BYTE *)(*(int *)((char *)a1 + 5771) + (*(int *)((char *)a1 + 5779))++) = v27;
        ++HIWORD(a1[v27 + 34]);
        if ( *(int *)((char *)a1 + 5779) == *(int *)((char *)a1 + 5775) - 1 )
        {
          sub_62E530(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82), 0);
          v28 = *a1;
          *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
          sub_62B1F0(v28);
        }
        v29 = *a1;
        v30 = *(int *)((char *)a1 + 106) - 1;
        ++*(int *)((char *)a1 + 98);
        *(int *)((char *)a1 + 106) = v30;
        if ( !*(_DWORD *)(v29 + 16) )
          return 0;
      }
      else
      {
        v31 = *(int *)((char *)a1 + 98) + 1;
        v32 = *(int *)((char *)a1 + 106) - 1;
        *(int *)((char *)a1 + 94) = 1;
        *(int *)((char *)a1 + 98) = v31;
        *(int *)((char *)a1 + 106) = v32;
      }
    }
    else
    {
      v13 = *(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 106) - 3;
      v14 = *((_BYTE *)a1 + 110) - 3;
      v15 = *(int *)((char *)a1 + 98) - *((_WORD *)a1 + 45) - 1;
      *(_WORD *)(*(int *)((char *)a1 + 5783) + 2 * *(int *)((char *)a1 + 5779)) = v15;
      *(_BYTE *)(*(int *)((char *)a1 + 5771) + (*(int *)((char *)a1 + 5779))++) = v14;
      v16 = v15 - 1;
      ++HIWORD(a1[(unsigned __int8)byte_72FB50[v14] + 291]);
      if ( v16 >= 0x100u )
        v17 = (unsigned __int8)byte_72FA50[v16 >> 7];
      else
        v17 = (unsigned __int8)byte_72F950[v16];
      ++HIWORD(a1[v17 + 607]);
      v18 = *(int *)((char *)a1 + 110);
      v19 = *(int *)((char *)a1 + 5779) == *(int *)((char *)a1 + 5775) - 1;
      *(int *)((char *)a1 + 106) += 1 - v18;
      *(int *)((char *)a1 + 110) = v18 - 2;
      do
      {
        v20 = *(int *)((char *)a1 + 98) + 1;
        *(int *)((char *)a1 + 98) = v20;
        if ( v20 <= v13 )
        {
          v21 = *(int *)((char *)a1 + 58);
          v22 = *(int *)((char *)a1 + 74)
              & (*(unsigned __int8 *)(*(int *)((char *)a1 + 46) + v20 + 2)
               ^ (*(int *)((char *)a1 + 62) << *(int *)((char *)a1 + 78)));
          *(int *)((char *)a1 + 62) = v22;
          v4 = *(unsigned __int16 *)(v21 + 2 * v22);
          *(_WORD *)(*(int *)((char *)a1 + 54) + 2 * (v20 & *(int *)((char *)a1 + 42))) = v4;
          *(_WORD *)(*(int *)((char *)a1 + 58) + 2 * *(int *)((char *)a1 + 62)) = *((_WORD *)a1 + 49);
        }
      }
      while ( (*(int *)((char *)a1 + 110))-- != 1 );
      v24 = *(int *)((char *)a1 + 98) + 1;
      *(int *)((char *)a1 + 94) = 0;
      *(int *)((char *)a1 + 86) = 2;
      *(int *)((char *)a1 + 98) = v24;
      if ( v19 )
      {
        sub_62E530(v24 - *(int *)((char *)a1 + 82), 0);
        v25 = *a1;
        *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
        sub_62B1F0(v25);
        if ( !*(_DWORD *)(*a1 + 16) )
          return 0;
      }
      v2 = a2;
    }
  }
  if ( *(int *)((char *)a1 + 94) )
  {
    v33 = *(_BYTE *)(*(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 46) - 1);
    *(_WORD *)(*(int *)((char *)a1 + 5783) + 2 * *(int *)((char *)a1 + 5779)) = 0;
    *(_BYTE *)(*(int *)((char *)a1 + 5771) + (*(int *)((char *)a1 + 5779))++) = v33;
    ++HIWORD(a1[v33 + 34]);
    *(int *)((char *)a1 + 94) = 0;
  }
  sub_62E530(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82), v2 == 4);
  v34 = *a1;
  *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
  sub_62B1F0(v34);
  v35 = 0;
  if ( !*(_DWORD *)(*a1 + 16) )
    return v2 != 4 ? 0 : 2;
  LOBYTE(v35) = v2 == 4;
  return 2 * v35 + 1;
}
