int __fastcall sub_536A70(int a1, int a2)
{
  int v2; // ebp
  int v4; // edi
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebp
  __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  BOOL v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // edx
  _DWORD *v25; // ecx
  int v27; // ecx
  _DWORD *v28; // ecx
  _DWORD *v29; // eax
  int v30; // edx
  int v31; // eax
  _DWORD *v32; // ecx
  int v33; // eax
  unsigned __int8 v35; // [esp+14h] [ebp-Ch]
  unsigned __int8 v36; // [esp+1Ch] [ebp-4h]
  unsigned __int8 v37; // [esp+1Ch] [ebp-4h]

  v2 = a2;
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(a1 + 106);
    if ( v5 < 0x106 )
    {
      sub_536440((char *)a1);
      v5 = *(_DWORD *)(a1 + 106);
      if ( v5 < 0x106 && !v2 )
        return 0;
      if ( !v5 )
        break;
    }
    if ( v5 >= 3 )
    {
      v6 = *(_DWORD *)(a1 + 98);
      v7 = *(_DWORD *)(a1 + 58);
      v8 = *(_DWORD *)(a1 + 74)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 46) + v6 + 2)
          ^ (*(_DWORD *)(a1 + 62) << *(_DWORD *)(a1 + 78)));
      HIWORD(v4) = 0;
      *(_DWORD *)(a1 + 62) = v8;
      LOWORD(v4) = *(_WORD *)(v7 + 2 * v8);
      *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (v6 & *(_DWORD *)(a1 + 42))) = v4;
      *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
    }
    v9 = *(_DWORD *)(a1 + 86);
    v10 = *(_DWORD *)(a1 + 102);
    *(_DWORD *)(a1 + 110) = v9;
    *(_DWORD *)(a1 + 90) = v10;
    *(_DWORD *)(a1 + 86) = 2;
    if ( v4 && v9 < *(_DWORD *)(a1 + 118) && *(_DWORD *)(a1 + 98) - v4 <= (unsigned int)(*(_DWORD *)(a1 + 34) - 262) )
    {
      if ( *(_DWORD *)(a1 + 126) != 2 )
        *(_DWORD *)(a1 + 86) = sub_536900(a1, v4);
      v11 = *(_DWORD *)(a1 + 86);
      if ( v11 <= 5
        && (*(_DWORD *)(a1 + 126) == 1
         || v11 == 3 && (unsigned int)(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 102)) > 0x1000) )
      {
        *(_DWORD *)(a1 + 86) = 2;
      }
    }
    v12 = *(_DWORD *)(a1 + 110);
    if ( v12 < 3 || *(_DWORD *)(a1 + 86) > v12 )
    {
      v27 = *(_DWORD *)(a1 + 98);
      if ( *(_DWORD *)(a1 + 94) )
      {
        v36 = *(_BYTE *)(v27 + *(_DWORD *)(a1 + 46) - 1);
        *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = 0;
        *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v36;
        ++*(_WORD *)(a1 + 4 * v36 + 138);
        if ( *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1 )
        {
          sub_5381F0(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), 0);
          v28 = *(_DWORD **)a1;
          *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
          sub_536160(v28);
        }
        v29 = *(_DWORD **)a1;
        v30 = *(_DWORD *)(a1 + 106) - 1;
        ++*(_DWORD *)(a1 + 98);
        *(_DWORD *)(a1 + 106) = v30;
        if ( !v29[4] )
          return 0;
      }
      else
      {
        v31 = *(_DWORD *)(a1 + 106) - 1;
        *(_DWORD *)(a1 + 94) = 1;
        *(_DWORD *)(a1 + 98) = v27 + 1;
        *(_DWORD *)(a1 + 106) = v31;
      }
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 98) + *(_DWORD *)(a1 + 106) - 3;
      v14 = *(_DWORD *)(a1 + 98) - *(_WORD *)(a1 + 90) - 1;
      v35 = *(_BYTE *)(a1 + 110) - 3;
      *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = v14;
      v15 = v14 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v35;
      ++*(_WORD *)(a1 + 4 * (unsigned __int8)byte_5B84F8[v35] + 1166);
      if ( v15 >= 0x100u )
        v16 = (unsigned __int8)byte_5B83F8[v15 >> 7];
      else
        v16 = (unsigned __int8)byte_5B82F8[v15];
      ++*(_WORD *)(a1 + 4 * v16 + 2430);
      v17 = *(_DWORD *)(a1 + 110);
      v18 = *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1;
      *(_DWORD *)(a1 + 106) += 1 - v17;
      *(_DWORD *)(a1 + 110) = v17 - 2;
      do
      {
        v19 = *(_DWORD *)(a1 + 98) + 1;
        *(_DWORD *)(a1 + 98) = v19;
        if ( v19 <= v13 )
        {
          v20 = *(_DWORD *)(a1 + 58);
          v21 = *(_DWORD *)(a1 + 74)
              & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 46) + v19 + 2)
               ^ (*(_DWORD *)(a1 + 62) << *(_DWORD *)(a1 + 78)));
          HIWORD(v4) = 0;
          *(_DWORD *)(a1 + 62) = v21;
          LOWORD(v4) = *(_WORD *)(v20 + 2 * v21);
          *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (v19 & *(_DWORD *)(a1 + 42))) = v4;
          *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
        }
        v22 = *(_DWORD *)(a1 + 110) - 1;
        *(_DWORD *)(a1 + 110) = v22;
      }
      while ( v22 );
      v23 = *(_DWORD *)(a1 + 98);
      *(_DWORD *)(a1 + 94) = 0;
      v24 = v23 + 1;
      *(_DWORD *)(a1 + 86) = 2;
      *(_DWORD *)(a1 + 98) = v24;
      if ( v18 )
      {
        sub_5381F0(v24 - *(_DWORD *)(a1 + 82), 0);
        v25 = *(_DWORD **)a1;
        *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
        sub_536160(v25);
        if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
          return 0;
      }
      v2 = a2;
    }
  }
  if ( *(_DWORD *)(a1 + 94) )
  {
    v37 = *(_BYTE *)(*(_DWORD *)(a1 + 98) + *(_DWORD *)(a1 + 46) - 1);
    *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = 0;
    *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v37;
    ++*(_WORD *)(a1 + 4 * v37 + 138);
    *(_DWORD *)(a1 + 94) = 0;
  }
  sub_5381F0(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), v2 == 4);
  v32 = *(_DWORD **)a1;
  *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
  sub_536160(v32);
  v33 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
    return v2 != 4 ? 0 : 2;
  LOBYTE(v33) = v2 == 4;
  return 2 * v33 + 1;
}
