// Address: 0x005365d0
// Size: 809 bytes
// Name: sub_5365D0
// Type: int __fastcall(int *, int)
// Source: IDA Hex-Rays decompilation

int __fastcall sub_5365D0(int *a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  char v8; // cl
  __int16 v9; // ax
  unsigned __int16 v10; // ax
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  BOOL v15; // ebp
  unsigned int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  unsigned int v23; // ecx
  unsigned __int8 *v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v29; // ecx
  int v30; // eax
  unsigned __int8 v32; // [esp+1Ch] [ebp-4h]

  v3 = 0;
  while ( 1 )
  {
    v4 = *(int *)((char *)a1 + 106);
    if ( v4 < 0x106 )
    {
      sub_536440((char *)a1);
      v4 = *(int *)((char *)a1 + 106);
      if ( v4 < 0x106 && !a2 )
        return 0;
      if ( !v4 )
        break;
    }
    if ( v4 >= 3 )
    {
      v5 = *(int *)((char *)a1 + 98);
      v6 = *(int *)((char *)a1 + 58);
      v7 = *(int *)((char *)a1 + 74)
         & (*(unsigned __int8 *)(*(int *)((char *)a1 + 46) + v5 + 2)
          ^ (*(int *)((char *)a1 + 62) << *(int *)((char *)a1 + 78)));
      HIWORD(v3) = 0;
      *(int *)((char *)a1 + 62) = v7;
      LOWORD(v3) = *(_WORD *)(v6 + 2 * v7);
      *(_WORD *)(*(int *)((char *)a1 + 54) + 2 * (v5 & *(int *)((char *)a1 + 42))) = v3;
      *(_WORD *)(*(int *)((char *)a1 + 58) + 2 * *(int *)((char *)a1 + 62)) = *((_WORD *)a1 + 49);
    }
    if ( v3
      && *(int *)((char *)a1 + 98) - v3 <= (unsigned int)(*(int *)((char *)a1 + 34) - 262)
      && *(int *)((char *)a1 + 126) != 2 )
    {
      *(int *)((char *)a1 + 86) = sub_536900(a1, v3);
    }
    if ( *(unsigned int *)((char *)a1 + 86) < 3 )
    {
      v32 = *(_BYTE *)(*(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 46));
      *(_WORD *)(*(int *)((char *)a1 + 5783) + 2 * *(int *)((char *)a1 + 5779)) = 0;
      *(_BYTE *)(*(int *)((char *)a1 + 5771) + (*(int *)((char *)a1 + 5779))++) = v32;
      ++HIWORD(a1[v32 + 34]);
      v15 = *(int *)((char *)a1 + 5779) == *(int *)((char *)a1 + 5775) - 1;
      --*(int *)((char *)a1 + 106);
    }
    else
    {
      v8 = *(int *)((char *)a1 + 86);
      v9 = *((_WORD *)a1 + 49) - *((_WORD *)a1 + 51);
      *(_WORD *)(*(int *)((char *)a1 + 5783) + 2 * *(int *)((char *)a1 + 5779)) = v9;
      v10 = v9 - 1;
      *(_BYTE *)(*(int *)((char *)a1 + 5771) + (*(int *)((char *)a1 + 5779))++) = v8 - 3;
      v11 = (unsigned __int8)byte_5B84F8[(unsigned __int8)(v8 - 3)];
      ++HIWORD(a1[v11 + 291]);
      if ( v10 >= 0x100u )
        v12 = (unsigned __int8)byte_5B83F8[v10 >> 7];
      else
        v12 = (unsigned __int8)byte_5B82F8[v10];
      ++HIWORD(a1[v12 + 607]);
      v13 = *(int *)((char *)a1 + 86);
      v14 = *(int *)((char *)a1 + 118);
      v15 = *(int *)((char *)a1 + 5779) == *(int *)((char *)a1 + 5775) - 1;
      v16 = *(int *)((char *)a1 + 106) - v13;
      *(int *)((char *)a1 + 106) = v16;
      if ( v13 > v14 || v16 < 3 )
      {
        v23 = v13 + *(int *)((char *)a1 + 98);
        v24 = (unsigned __int8 *)(v23 + *(int *)((char *)a1 + 46));
        *(int *)((char *)a1 + 98) = v23;
        v25 = *(int *)((char *)a1 + 78);
        *(int *)((char *)a1 + 86) = 0;
        v26 = *v24;
        *(int *)((char *)a1 + 62) = v26;
        *(int *)((char *)a1 + 62) = *(int *)((char *)a1 + 74) & (v24[1] ^ (v26 << v25));
        goto LABEL_24;
      }
      *(int *)((char *)a1 + 86) = v13 - 1;
      do
      {
        v17 = *(int *)((char *)a1 + 46);
        v18 = *(int *)((char *)a1 + 62);
        v19 = *(int *)((char *)a1 + 98) + 1;
        *(int *)((char *)a1 + 98) = v19;
        v20 = *(int *)((char *)a1 + 58);
        v21 = *(int *)((char *)a1 + 74) & ((v18 << *(int *)((char *)a1 + 78)) ^ *(unsigned __int8 *)(v19 + v17 + 2));
        HIWORD(v3) = 0;
        *(int *)((char *)a1 + 62) = v21;
        LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
        *(_WORD *)(*(int *)((char *)a1 + 54) + 2 * (*(int *)((char *)a1 + 42) & v19)) = v3;
        *(_WORD *)(*(int *)((char *)a1 + 58) + 2 * *(int *)((char *)a1 + 62)) = *((_WORD *)a1 + 49);
        v22 = *(int *)((char *)a1 + 86) - 1;
        *(int *)((char *)a1 + 86) = v22;
      }
      while ( v22 );
    }
    ++*(int *)((char *)a1 + 98);
LABEL_24:
    if ( v15 )
    {
      sub_5381F0(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82), 0);
      v27 = *a1;
      *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
      sub_536160(v27);
      if ( !*(_DWORD *)(*a1 + 16) )
        return 0;
    }
  }
  sub_5381F0(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82), a2 == 4);
  v29 = *a1;
  *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
  sub_536160(v29);
  v30 = 0;
  if ( !*(_DWORD *)(*a1 + 16) )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v30) = a2 == 4;
  return 2 * v30 + 1;
}
