int __thiscall sub_6B0B98(_DWORD *this, int *a2, unsigned int *a3)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  bool v11; // zf
  _DWORD *v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // ecx
  _DWORD *v20; // eax
  _DWORD v21[36]; // [esp+8h] [ebp-B0h] BYREF
  int v22; // [esp+98h] [ebp-20h]
  unsigned int v23; // [esp+9Ch] [ebp-1Ch]
  int v24; // [esp+A0h] [ebp-18h]
  int v25; // [esp+A4h] [ebp-14h]
  int v26; // [esp+A8h] [ebp-10h]
  unsigned int v27; // [esp+ACh] [ebp-Ch]
  unsigned int v28; // [esp+B0h] [ebp-8h]
  unsigned int v29; // [esp+B4h] [ebp-4h]

  if ( !a2 )
    return 1;
  v5 = *a2;
  if ( (*a2 & 0xFFF00000) == 0 || (*a2 & 0xFFF00000) == 0x20700000 )
    return 0;
  v29 = v5 & 0xFFFFF;
  v23 = a2[1] / (v5 & 0xFFFFFu);
  if ( v23 <= 1 )
    return 0;
  v6 = this[34];
  v7 = this[31];
  v8 = this[32];
  v21[v8 + 18] = 0;
  v6 *= 4;
  *(_DWORD *)((char *)&v21[18] + v6) = 0;
  v7 *= 4;
  *(_DWORD *)((char *)&v21[18] + v7) = 0;
  v9 = this[37];
  v21[v8] = 1;
  v9 *= 4;
  *(_DWORD *)((char *)&v21[18] + v9) = 0;
  v10 = 0;
  v11 = v23 == 0;
  *(_DWORD *)((char *)v21 + v6) = 3;
  *(_DWORD *)((char *)v21 + v7) = 1;
  *(_DWORD *)((char *)v21 + v9) = 1;
  v26 = 0;
  v27 = 0;
  if ( v11 )
    return 0;
  v24 = 0;
  v25 = 4 * v29;
  while ( 1 )
  {
    v12 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v10 + a2[2]));
    v22 = *(_DWORD *)(this[4] + 4 * v12[1]);
    v13 = *(_DWORD *)(v22 + 4);
    if ( (v13 & 0x200) != 0 )
    {
      if ( (v13 & 0x80u) == 0 )
      {
        v14 = this[31];
        goto LABEL_18;
      }
LABEL_13:
      v14 = this[37];
      goto LABEL_18;
    }
    if ( (v13 & 0x80u) != 0 )
      goto LABEL_13;
    v14 = (v13 & 0x10) == 0 || (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v12[27]) == 0xFFFF
        ? this[34]
        : this[32];
LABEL_18:
    v29 = 0;
    v28 = v14;
    if ( v27 )
    {
      v15 = this[5];
      v16 = (_DWORD *)a2[2];
      do
      {
        v17 = *(_DWORD **)(v15 + 4 * *v16);
        if ( v12[1] == v17[1] && v12[2] == v17[2] && v12[3] == v17[3] )
          break;
        ++v29;
        v16 = (_DWORD *)((char *)v16 + v25);
      }
      while ( v29 < v27 );
    }
    v18 = v27;
    if ( v29 == v27 && v28 < 0x12 )
    {
      v19 = v28;
      v20 = &v21[v28 + 18];
      if ( ++*v20 > v21[v19] )
        break;
    }
    if ( (*(_BYTE *)(v22 + 5) & 2) != 0 && (unsigned int)++v26 > 2 )
      break;
    v10 = v25 + v24;
    v27 = v18 + 1;
    v24 += v25;
    if ( v18 + 1 >= v23 )
      return 0;
  }
  if ( a3 )
    *a3 = v18;
  return 1;
}
