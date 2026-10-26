int __thiscall sub_6A11E8(_DWORD *this, int *a2, unsigned int *a3)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edi
  bool v11; // zf
  _DWORD *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  int v20; // ebx
  int v21; // edi
  unsigned int *v22; // eax
  _DWORD v23[36]; // [esp+8h] [ebp-A8h] BYREF
  int v24; // [esp+98h] [ebp-18h]
  unsigned int v25; // [esp+9Ch] [ebp-14h]
  int v26; // [esp+A0h] [ebp-10h]
  int v27; // [esp+A4h] [ebp-Ch]
  unsigned int v28; // [esp+A8h] [ebp-8h]
  unsigned int v29; // [esp+ACh] [ebp-4h]

  if ( !a2 )
    return 1;
  v5 = *a2;
  v6 = *a2 & 0xFFF00000;
  if ( !v6 || v6 == 544210944 )
    return 0;
  v26 = v5 & 0xFFFFF;
  v28 = a2[1] / (v5 & 0xFFFFFu);
  if ( v6 == 1884291072 || v6 == 1885339648 || v6 == 1886388224 )
    v28 = 2;
  if ( v28 <= 1 )
    return 0;
  v7 = this[34];
  v8 = this[31];
  v9 = this[32];
  v23[v9 + 18] = 0;
  v7 *= 4;
  v8 *= 4;
  *(_DWORD *)((char *)&v23[18] + v7) = 0;
  *(_DWORD *)((char *)&v23[18] + v8) = 0;
  v10 = this[37];
  v23[v9] = 1;
  v10 *= 4;
  *(_DWORD *)((char *)&v23[18] + v10) = 0;
  *(_DWORD *)((char *)v23 + v7) = 3;
  *(_DWORD *)((char *)v23 + v8) = 1;
  v11 = v28 == 0;
  *(_DWORD *)((char *)v23 + v10) = 1;
  v24 = 0;
  v29 = 0;
  if ( v11 )
  {
LABEL_35:
    v29 = 0;
    if ( v28 )
    {
      v20 = 0;
      v27 = 4 * v26;
      while ( 1 )
      {
        if ( (*a2 & 0xF0000000) == 0x60000000 )
        {
          v21 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v20 + a2[2]));
          if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(v21 + 108)) == 18
            && *(_DWORD *)(v21 + 4) == this[32] )
          {
            break;
          }
        }
        ++v29;
        v20 += v27;
        if ( v29 >= v28 )
          return 0;
      }
      if ( a3 )
        *a3 = v29;
      return 1;
    }
    return 0;
  }
  v27 = 0;
  while ( 1 )
  {
    v12 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v27 + a2[2]));
    v13 = *(_DWORD *)(this[4] + 4 * v12[1]);
    if ( v12[27] == 17 && (*(_BYTE *)(v13 + 4) & 0x10) != 0 )
      goto LABEL_34;
    v14 = *(_DWORD *)(v13 + 4);
    if ( (v14 & 0x200) != 0 )
    {
      if ( (v14 & 0x80u) == 0 )
      {
        v15 = this[31];
        goto LABEL_24;
      }
LABEL_18:
      v15 = this[37];
      goto LABEL_24;
    }
    if ( (v14 & 0x80u) != 0 )
      goto LABEL_18;
    v15 = (v14 & 0x10) == 0
       || (v14 & 0x200) != 0
       || (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v12[27]) == 0xFFFF
        ? this[34]
        : this[32];
LABEL_24:
    v25 = 0;
    if ( v29 )
    {
      v16 = (_DWORD *)a2[2];
      do
      {
        v17 = *(_DWORD **)(this[5] + 4 * *v16);
        if ( v12[1] == v17[1] && v12[2] == v17[2] && v12[3] == v17[3] )
          break;
        ++v25;
        v16 += v26;
      }
      while ( v25 < v29 );
    }
    v18 = v29;
    if ( v25 == v29 )
    {
      v19 = &v23[v15 + 18];
      if ( ++*v19 > v23[v15] )
      {
        v22 = a3;
        if ( !a3 )
          return 1;
        goto LABEL_43;
      }
    }
    if ( this[31] == v15 && (unsigned int)++v24 > 2 )
      break;
LABEL_34:
    ++v29;
    v27 += 4 * v26;
    if ( v29 >= v28 )
      goto LABEL_35;
  }
  v22 = a3;
  if ( a3 )
  {
    v18 = v29;
LABEL_43:
    *v22 = v18;
  }
  return 1;
}
