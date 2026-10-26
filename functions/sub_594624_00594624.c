int __cdecl sub_594624(_DWORD *a1, int a2, int a3)
{
  int v3; // eax
  signed int v4; // esi
  unsigned int v5; // edx
  int v6; // ecx
  int v7; // ebx
  int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  _BYTE *v11; // ecx
  int v12; // ebx
  bool v13; // zf
  unsigned int v14; // ebx
  _BYTE *v15; // ecx
  int v16; // ebx
  unsigned int v17; // edi
  int v18; // ecx
  _DWORD *v19; // eax
  char v20; // cl
  int v21; // edx
  int *v22; // eax
  int v24; // ecx
  int *v25; // ebx
  unsigned int v26; // esi
  unsigned int v27; // esi
  unsigned int v28; // ebx
  _BYTE *v29; // esi
  int v30; // ebx
  _BYTE *v31; // ecx
  unsigned int v32; // ebx
  unsigned int v33; // ecx
  _DWORD *v34; // eax
  char v35; // cl
  int v36; // [esp+Ch] [ebp-Ch]
  int v37; // [esp+10h] [ebp-8h]
  int v38; // [esp+14h] [ebp-4h]
  int v39; // [esp+14h] [ebp-4h]
  int *v40; // [esp+24h] [ebp+Ch]
  char v41; // [esp+27h] [ebp+Fh]
  int v42; // [esp+28h] [ebp+10h]
  unsigned int v43; // [esp+28h] [ebp+10h]
  int v44; // [esp+28h] [ebp+10h]
  char v45; // [esp+2Bh] [ebp+13h]

  v3 = a1[4];
  v4 = (a3 + 23) & 0xFFFFFFF0;
  v5 = (unsigned int)(a2 - a1[3]) >> 15;
  v36 = 516 * v5 + v3 + 324;
  v6 = *(_DWORD *)(a2 - 4) - 1;
  v42 = v6;
  v7 = *(_DWORD *)(v6 + a2 - 4);
  v8 = v6 + a2 - 4;
  v38 = v7;
  if ( v4 <= v6 )
  {
    if ( v4 < v6 )
    {
      v44 = v6 - v4;
      v24 = v4 + 1;
      *(_DWORD *)(a2 - 4) = v4 + 1;
      v25 = (int *)(a2 + v4 - 4);
      v40 = v25;
      v26 = (v44 >> 4) - 1;
      *(v25 - 1) = v24;
      if ( v26 > 0x3F )
        v26 = 63;
      if ( (v38 & 1) == 0 )
      {
        v27 = (v38 >> 4) - 1;
        if ( v27 > 0x3F )
          v27 = 63;
        if ( *(_DWORD *)(v8 + 4) == *(_DWORD *)(v8 + 8) )
        {
          if ( v27 >= 0x20 )
          {
            v31 = (_BYTE *)(v27 + v3 + 4);
            v32 = ~(0x80000000 >> (v27 - 32));
            *(_DWORD *)(v3 + 4 * v5 + 196) &= v32;
            v13 = (*v31)-- == 1;
            if ( v13 )
              a1[1] &= v32;
          }
          else
          {
            v28 = 0x80000000 >> v27;
            v29 = (_BYTE *)(v27 + v3 + 4);
            v30 = ~v28;
            *(_DWORD *)(v3 + 4 * v5 + 68) &= v30;
            v13 = (*v29)-- == 1;
            if ( v13 )
              *a1 &= v30;
          }
          v25 = v40;
        }
        *(_DWORD *)(*(_DWORD *)(v8 + 8) + 4) = *(_DWORD *)(v8 + 4);
        *(_DWORD *)(*(_DWORD *)(v8 + 4) + 8) = *(_DWORD *)(v8 + 8);
        v44 += v38;
        v26 = (v44 >> 4) - 1;
        if ( v26 > 0x3F )
          v26 = 63;
      }
      v33 = v36 + 8 * v26;
      v25[1] = *(_DWORD *)(v33 + 4);
      v25[2] = v33;
      *(_DWORD *)(v33 + 4) = v25;
      *(_DWORD *)(v25[1] + 8) = v25;
      if ( v25[1] == v25[2] )
      {
        v41 = *(_BYTE *)(v26 + v3 + 4);
        *(_BYTE *)(v26 + v3 + 4) = v41 + 1;
        if ( v26 >= 0x20 )
        {
          if ( !v41 )
            a1[1] |= 0x80000000 >> (v26 - 32);
          v34 = (_DWORD *)(v3 + 4 * v5 + 196);
          v35 = v26 - 32;
        }
        else
        {
          if ( !v41 )
            *a1 |= 0x80000000 >> v26;
          v34 = (_DWORD *)(v3 + 4 * v5 + 68);
          v35 = v26;
        }
        *v34 |= 0x80000000 >> v35;
      }
      *v25 = v44;
      *(int *)((char *)v25 + v44 - 4) = v44;
    }
  }
  else
  {
    if ( (v7 & 1) != 0 || v4 > v6 + v7 )
      return 0;
    v9 = (v7 >> 4) - 1;
    v37 = v9;
    if ( v9 > 0x3F )
    {
      v9 = 63;
      v37 = 63;
    }
    if ( *(_DWORD *)(v8 + 4) == *(_DWORD *)(v8 + 8) )
    {
      if ( v9 >= 0x20 )
      {
        v14 = 0x80000000 >> (v9 - 32);
        v15 = (_BYTE *)(v37 + v3 + 4);
        v16 = ~v14;
        *(_DWORD *)(v3 + 4 * v5 + 196) &= v16;
        v13 = (*v15)-- == 1;
        if ( v13 )
          a1[1] &= v16;
      }
      else
      {
        v10 = 0x80000000 >> v9;
        v11 = (_BYTE *)(v37 + v3 + 4);
        v12 = ~v10;
        *(_DWORD *)(v3 + 4 * v5 + 68) &= v12;
        v13 = (*v11)-- == 1;
        if ( v13 )
          *a1 &= v12;
      }
    }
    *(_DWORD *)(*(_DWORD *)(v8 + 8) + 4) = *(_DWORD *)(v8 + 4);
    *(_DWORD *)(*(_DWORD *)(v8 + 4) + 8) = *(_DWORD *)(v8 + 8);
    v39 = v42 - v4 + v38;
    if ( v39 <= 0 )
    {
      v21 = a2;
    }
    else
    {
      v17 = (v39 >> 4) - 1;
      v18 = a2 + v4 - 4;
      if ( v17 > 0x3F )
        v17 = 63;
      v43 = v36 + 8 * v17;
      *(_DWORD *)(a2 + v4) = *(_DWORD *)(v43 + 4);
      *(_DWORD *)(v18 + 8) = v43;
      *(_DWORD *)(v43 + 4) = v18;
      *(_DWORD *)(*(_DWORD *)(a2 + v4) + 8) = a2 + v4 - 4;
      if ( *(_DWORD *)(a2 + v4) == *(_DWORD *)(a2 + v4 - 4 + 8) )
      {
        v45 = *(_BYTE *)(v17 + v3 + 4);
        *(_BYTE *)(v17 + v3 + 4) = v45 + 1;
        if ( v17 >= 0x20 )
        {
          if ( !v45 )
            a1[1] |= 0x80000000 >> (v17 - 32);
          v19 = (_DWORD *)(v3 + 4 * v5 + 196);
          v20 = v17 - 32;
        }
        else
        {
          if ( !v45 )
            *a1 |= 0x80000000 >> v17;
          v19 = (_DWORD *)(v3 + 4 * v5 + 68);
          v20 = v17;
        }
        *v19 |= 0x80000000 >> v20;
      }
      v21 = a2;
      v22 = (int *)(a2 + v4 - 4);
      *v22 = v39;
      *(int *)((char *)v22 + v39 - 4) = v39;
    }
    *(_DWORD *)(v21 - 4) = v4 + 1;
    *(_DWORD *)(v21 + v4 - 8) = v4 + 1;
  }
  return 1;
}
