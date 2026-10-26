int __thiscall sub_6AB647(_DWORD *this, int *a2, unsigned int *a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  unsigned int v9; // ebx
  bool v10; // zf
  _DWORD *v11; // eax
  int v12; // edx
  unsigned int v13; // edi
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // esi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  int v19; // eax
  int v20; // edx
  unsigned int v21; // esi
  _DWORD *v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  _DWORD *v25; // eax
  _DWORD v26[36]; // [esp+4h] [ebp-ACh] BYREF
  _DWORD *v27; // [esp+94h] [ebp-1Ch]
  unsigned int v28; // [esp+98h] [ebp-18h]
  int v29; // [esp+9Ch] [ebp-14h]
  _DWORD *v30; // [esp+A0h] [ebp-10h]
  unsigned int v31; // [esp+A4h] [ebp-Ch]
  int v32; // [esp+A8h] [ebp-8h]
  int v33; // [esp+ACh] [ebp-4h]
  unsigned int v34; // [esp+B8h] [ebp+8h]

  if ( !a2 )
    return 1;
  v4 = *a2;
  if ( (*a2 & 0xFFF00000) == 0 || (*a2 & 0xFFF00000) == 0x20700000 )
    return 0;
  v32 = v4 & 0xFFFFF;
  v28 = a2[1] / (v4 & 0xFFFFFu);
  if ( v28 <= 1 )
    return 0;
  v5 = this[32];
  v6 = this[34];
  v7 = this[31];
  v8 = this[37];
  v33 = 0;
  v5 *= 4;
  *(_DWORD *)((char *)&v26[18] + v5) = 0;
  v6 *= 4;
  *(_DWORD *)((char *)&v26[18] + v6) = 0;
  v7 *= 4;
  v8 *= 4;
  *(_DWORD *)((char *)&v26[18] + v7) = 0;
  *(_DWORD *)((char *)&v26[18] + v8) = 0;
  *(_DWORD *)((char *)v26 + v5) = 2;
  *(_DWORD *)((char *)v26 + v6) = 3;
  *(_DWORD *)((char *)v26 + v7) = 2;
  v9 = 0;
  v10 = v28 == 0;
  *(_DWORD *)((char *)v26 + v8) = 1;
  v31 = 0;
  if ( v10 )
    return 0;
  v11 = (_DWORD *)a2[2];
  v27 = v11;
  v29 = 4 * v32;
  v30 = v11;
  while ( 1 )
  {
    v12 = *(_DWORD *)(this[5] + 4 * *v11);
    v34 = 0;
    v13 = *(_DWORD *)(v12 + 4);
    if ( v9 )
    {
      v14 = v27;
      v32 = (int)v27;
      do
      {
        v15 = *(_DWORD *)(this[5] + 4 * *v14);
        if ( v13 == *(_DWORD *)(v15 + 4)
          && *(_DWORD *)(v12 + 8) == *(_DWORD *)(v15 + 8)
          && *(_DWORD *)(v12 + 12) == *(_DWORD *)(v15 + 12) )
        {
          v16 = this[4];
          if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * v13) + 5) & 1) == 0
            || (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v15 + 4)) + 5) & 1) == 0
            || *(double *)(v12 + 32) == *(double *)(v15 + 32) )
          {
            break;
          }
        }
        ++v34;
        v14 = (_DWORD *)(v29 + v32);
        v32 += v29;
      }
      while ( v34 < v31 );
    }
    v17 = v31;
    if ( v34 != v31 )
      goto LABEL_44;
    v18 = this[32];
    if ( v13 == v18 )
    {
      if ( *(_BYTE *)(v12 + 108) == 3 )
      {
        if ( (unsigned __int16)this[50] == 257 && (unsigned int)++v33 > 2 && !a3 )
          return 1;
        v18 = this[34];
      }
    }
    else
    {
      v19 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v13) + 4);
      if ( (v19 & 0x200) == 0 )
      {
        if ( (v19 & 0x80u) == 0 )
        {
          v18 = v13;
          goto LABEL_31;
        }
LABEL_29:
        v18 = this[37];
        goto LABEL_31;
      }
      if ( (v19 & 0x80u) != 0 )
        goto LABEL_29;
      v18 = this[31];
    }
LABEL_31:
    v20 = *(_DWORD *)(v12 + 72);
    if ( v20 != -1 )
    {
      v21 = this[34];
      if ( v13 == v21 && (unsigned __int16)this[50] == 257 )
      {
        v22 = *(_DWORD **)(this[6] + 4 * v20);
        if ( v22 )
        {
          v23 = *v22 & 0xFFF00000;
          if ( (v23 == 1626341376 || v23 == 1615855616 || v23 == 1621098496 || v23 == 1610612736)
            && (unsigned int)++v33 > 2
            && !a3 )
          {
            return 1;
          }
        }
        v18 = v21;
      }
    }
    if ( v18 < 0x12 )
    {
      v24 = v18;
      v25 = &v26[v18 + 18];
      if ( ++*v25 > v26[v24] )
        break;
    }
LABEL_44:
    v11 = &v30[v29 / 4u];
    v9 = v17 + 1;
    v31 = v9;
    v30 = (_DWORD *)((char *)v30 + v29);
    if ( v9 >= v28 )
      return 0;
  }
  if ( a3 )
    *a3 = v17;
  return 1;
}
