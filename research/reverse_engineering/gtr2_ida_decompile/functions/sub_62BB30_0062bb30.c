int __fastcall sub_62BB30(int a1, int a2)
{
  int v2; // ebp
  unsigned int v3; // edi
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  __int16 v9; // ax
  unsigned __int8 v10; // cl
  unsigned __int16 v11; // ax
  int v12; // eax
  unsigned int v13; // edx
  BOOL v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  unsigned int v24; // ecx
  unsigned __int8 *v25; // edx
  int v26; // ecx
  int v27; // eax
  unsigned __int8 v28; // al
  BOOL v29; // edx
  int v30; // eax
  int v31; // esi
  unsigned int v32; // edx
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  _DWORD *v36; // eax
  int v38; // eax
  int v39; // eax
  unsigned int v40; // [esp+10h] [ebp-8h]

  v2 = a2;
  v3 = 0;
  v40 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(a1 + 106);
    if ( v5 < 0x106 )
    {
      sub_62B790((int *)a1);
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
      *(_DWORD *)(a1 + 62) = v8;
      v3 = *(unsigned __int16 *)(v7 + 2 * v8);
      *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (v6 & *(_DWORD *)(a1 + 42))) = v3;
      v40 = v3;
      *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
    }
    if ( v3 && *(_DWORD *)(a1 + 98) - v3 <= *(_DWORD *)(a1 + 34) - 262 && *(_DWORD *)(a1 + 126) != 2 )
      *(_DWORD *)(a1 + 86) = sub_62B620(v3, a1);
    if ( *(_DWORD *)(a1 + 86) < 3u )
    {
      v28 = *(_BYTE *)(*(_DWORD *)(a1 + 98) + *(_DWORD *)(a1 + 46));
      *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v28;
      ++*(_WORD *)(a1 + 4 * v28 + 138);
      v29 = *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1;
      --*(_DWORD *)(a1 + 106);
      v14 = v29;
    }
    else
    {
      v9 = *(_WORD *)(a1 + 98) - *(_WORD *)(a1 + 102);
      v10 = *(_DWORD *)(a1 + 86) - 3;
      *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = v9;
      *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v10;
      v11 = v9 - 1;
      ++*(_WORD *)(a1 + 4 * (unsigned __int8)byte_72FB50[v10] + 1166);
      if ( v11 >= 0x100u )
        v12 = (unsigned __int8)byte_72FA50[v11 >> 7];
      else
        v12 = (unsigned __int8)byte_72F950[v11];
      ++*(_WORD *)(a1 + 4 * v12 + 2430);
      v13 = *(_DWORD *)(a1 + 118);
      v14 = *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1;
      v15 = *(_DWORD *)(a1 + 86);
      v16 = *(_DWORD *)(a1 + 106) - v15;
      *(_DWORD *)(a1 + 106) = v16;
      if ( v15 > v13 || v16 < 3 )
      {
        v24 = v15 + *(_DWORD *)(a1 + 98);
        v25 = (unsigned __int8 *)(v24 + *(_DWORD *)(a1 + 46));
        *(_DWORD *)(a1 + 98) = v24;
        v26 = *(_DWORD *)(a1 + 78);
        *(_DWORD *)(a1 + 86) = 0;
        v27 = *v25;
        *(_DWORD *)(a1 + 62) = v27;
        *(_DWORD *)(a1 + 62) = *(_DWORD *)(a1 + 74) & (v25[1] ^ (v27 << v26));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 86) = v15 - 1;
      do
      {
        v17 = *(_DWORD *)(a1 + 46);
        v18 = *(_DWORD *)(a1 + 62);
        v19 = *(_DWORD *)(a1 + 98) + 1;
        *(_DWORD *)(a1 + 98) = v19;
        v20 = *(unsigned __int8 *)(v19 + v17 + 2);
        v21 = *(_DWORD *)(a1 + 58);
        v22 = *(_DWORD *)(a1 + 74) & ((v18 << *(_DWORD *)(a1 + 78)) ^ v20);
        *(_DWORD *)(a1 + 62) = v22;
        v3 = *(unsigned __int16 *)(v21 + 2 * v22);
        *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (*(_DWORD *)(a1 + 42) & v19)) = v3;
        *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
        v23 = *(_DWORD *)(a1 + 86) - 1;
        v40 = v3;
        *(_DWORD *)(a1 + 86) = v23;
      }
      while ( v23 );
    }
    ++*(_DWORD *)(a1 + 98);
LABEL_24:
    if ( v14 )
    {
      sub_62E530(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), 0);
      v30 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
      v31 = *(_DWORD *)(v30 + 28);
      v32 = *(_DWORD *)(v31 + 20);
      if ( v32 > *(_DWORD *)(v30 + 16) )
        v32 = *(_DWORD *)(v30 + 16);
      if ( v32 )
      {
        qmemcpy(*(void **)(v30 + 12), *(const void **)(v31 + 16), v32);
        v33 = *(_DWORD *)(v30 + 28);
        *(_DWORD *)(v30 + 12) += v32;
        *(_DWORD *)(v33 + 16) += v32;
        v34 = *(_DWORD *)(v30 + 16);
        v35 = *(_DWORD *)(v30 + 28);
        *(_DWORD *)(v30 + 20) += v32;
        v2 = a2;
        *(_DWORD *)(v30 + 16) = v34 - v32;
        v3 = v40;
        *(_DWORD *)(v35 + 20) -= v32;
        v36 = *(_DWORD **)(v30 + 28);
        if ( !v36[5] )
          v36[4] = v36[2];
      }
      if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
        return 0;
    }
  }
  sub_62E530(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), v2 == 4);
  v38 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
  sub_62B1F0(v38);
  v39 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
    return v2 != 4 ? 0 : 2;
  LOBYTE(v39) = v2 == 4;
  return 2 * v39 + 1;
}
