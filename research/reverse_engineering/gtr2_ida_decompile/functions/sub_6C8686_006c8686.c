int __thiscall sub_6C8686(int this)
{
  _DWORD *v2; // ecx
  int result; // eax
  int v4; // edx
  char *v5; // eax
  char *v6; // ecx
  int v7; // esi
  int v8; // ebx
  int v9; // edx
  unsigned int v10; // ebx
  char *v11; // edx
  int v12; // ecx
  _BYTE *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  int v17; // eax
  _DWORD *v18; // edx
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // esi
  int v25; // eax
  _DWORD *v26; // ecx
  int v27; // edx
  char *v28; // eax
  _DWORD v29[4]; // [esp+14h] [ebp-2Ch]
  _DWORD v30[3]; // [esp+24h] [ebp-1Ch] BYREF
  int v31; // [esp+30h] [ebp-10h]
  char *v32; // [esp+34h] [ebp-Ch]
  unsigned int v33; // [esp+38h] [ebp-8h]
  char *v34; // [esp+3Ch] [ebp-4h]

  v2 = *(_DWORD **)(this + 256);
  if ( (*v2 & 0xFFF00000) != 0x20400000 )
    return 1;
  v4 = *v2 & 0xFFFFF;
  v5 = (char *)v2[2];
  v6 = &v5[4 * v4];
  v7 = *(_DWORD *)(this + 20);
  v8 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v6) + 4);
  v33 = v4;
  v9 = *(_DWORD *)(this + 16);
  if ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * v8) + 5) & 1) != 0 )
  {
    v31 = 0;
    v34 = v5;
    v5 = v6;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v5) + 4)) + 5) & 1) == 0 )
      return 1;
    v31 = 1;
    v34 = v6;
  }
  v10 = v33;
  *(_DWORD *)(this + 348) = 0;
  v32 = 0;
  if ( v10 )
  {
    v11 = v34;
    v12 = v5 - v34;
    while ( *(double *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)&v11[v12]) + 32) == -0.5 )
    {
      v13 = *(_BYTE **)(v7 + 4 * *(_DWORD *)v11);
      if ( (v13[61] & 2) == 0 && (*v13 & 4) == 0 && (*(_BYTE *)(this + 110) & 4) != 0 )
        *(_DWORD *)(this + 348) = 1;
      ++v32;
      v11 += 4;
      if ( (unsigned int)v32 >= v10 )
        goto LABEL_15;
    }
    return 1;
  }
LABEL_15:
  v14 = *(_DWORD *)(this + 256);
  v15 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * **(_DWORD **)(v14 + 16)) + 4);
  if ( v15 == *(_DWORD *)(this + 136) )
  {
    v16 = sub_6C73E9(this, 0x20000, 0, v34, 0x20000, 0, 0);
    if ( *(_DWORD *)(this + 348) == 2 )
      sub_686816(
        this,
        *(_DWORD *)(*(_DWORD *)(this + 256) + 60),
        (const char *)0x125D,
        "_bias opportunity missed because source was not clamped 0 to 1");
    return v16;
  }
  if ( v15 != *(_DWORD *)(this + 132) )
    return 1;
  result = sub_6C5283((_DWORD *)this, v10 & 0xFFFFF | 0x20400000, (_DWORD *)v14, v30, 2);
  if ( result )
    return result;
  v32 = (char *)&v30[v31];
  v17 = *(_DWORD *)v32;
  if ( !*(_DWORD *)v32 )
    return 1;
  v34 = 0;
  if ( v10 )
  {
    v18 = *(_DWORD **)(v17 + 8);
    do
    {
      v19 = *(_DWORD *)(v7 + 4 * *v18);
      if ( (*(_BYTE *)(v19 + 62) & 0x1F) != 0 )
        break;
      if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v19 + 4)) + 4) & 0x200) != 0
        || (*(_DWORD *)(v19 + 60) & 0x200) == 0 && (*(_BYTE *)v19 & 4) == 0 )
      {
        v10 = v33;
        break;
      }
      v31 = 0;
      ++v34;
      v10 = v33;
      ++v18;
    }
    while ( (unsigned int)v34 < v33 );
  }
  if ( v34 != (char *)v10 )
  {
    v34 = 0;
    if ( v10 )
    {
      v20 = (_DWORD *)(4 * v10 + *(_DWORD *)(*(_DWORD *)v32 + 8));
      do
      {
        v21 = *(_DWORD *)(v7 + 4 * *v20);
        if ( (*(_BYTE *)(v21 + 62) & 0x1F) != 0 )
          break;
        if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v21 + 4)) + 4) & 0x200) != 0
          || (*(_DWORD *)(v21 + 60) & 0x200) == 0 && (*(_BYTE *)v21 & 4) == 0 )
        {
          v10 = v33;
          break;
        }
        ++v34;
        v10 = v33;
        ++v20;
      }
      while ( (unsigned int)v34 < v33 );
    }
    if ( v34 != (char *)v10 )
    {
      v22 = v10;
      goto LABEL_44;
    }
    return 1;
  }
  v22 = v31;
LABEL_44:
  v34 = 0;
  if ( v10 )
  {
    v23 = 4 * v22;
    while ( 1 )
    {
      v24 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v23 + *(_DWORD *)(*(_DWORD *)v32 + 8)));
      v25 = sub_681AAA(
              (void *)this,
              *(_DWORD *)(v24 + 4),
              *(_DWORD *)(v24 + 12),
              *(_DWORD *)(v24 + 16),
              *(double *)(v24 + 32));
      v31 = v25;
      v29[(_DWORD)v34] = v25;
      if ( v25 == -1 )
        return -2147024882;
      v26 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * v25);
      v27 = *(_DWORD *)v32;
      v26[14] = *(_DWORD *)(v23 + *(_DWORD *)(*(_DWORD *)v32 + 8));
      v26[18] = *(_DWORD *)(v24 + 72);
      v26[20] = *(_DWORD *)(v24 + 80);
      v26[21] = *(_DWORD *)(v24 + 84);
      v26[22] = *(_DWORD *)(v24 + 84);
      v26[15] = *(_DWORD *)(v24 + 60) | 0x20000;
      *(_DWORD *)(v23 + *(_DWORD *)(v27 + 8)) = v31;
      v28 = v34;
      *(_DWORD *)(*(_DWORD *)(v27 + 16) + 4 * (_DWORD)v34) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 16)
                                                                       + 4 * (_DWORD)v34);
      v23 += 4;
      v34 = v28 + 1;
      if ( (unsigned int)(v28 + 1) >= v33 )
        goto LABEL_48;
    }
  }
  else
  {
LABEL_48:
    **(_DWORD **)(this + 256) = 0;
    return 0;
  }
}
