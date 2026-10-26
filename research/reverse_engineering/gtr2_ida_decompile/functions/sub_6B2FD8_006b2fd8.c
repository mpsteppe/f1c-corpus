int __thiscall sub_6B2FD8(_DWORD *this, _DWORD *a2, unsigned int *a3)
{
  _DWORD *v3; // ebx
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  _DWORD *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  _DWORD *v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // ecx
  int v21; // edx
  _DWORD *v22; // eax
  _DWORD v23[36]; // [esp+8h] [ebp-ACh] BYREF
  int v24; // [esp+98h] [ebp-1Ch]
  int v25; // [esp+9Ch] [ebp-18h]
  int v26; // [esp+A0h] [ebp-14h]
  unsigned int v27; // [esp+A4h] [ebp-10h]
  unsigned int v28; // [esp+A8h] [ebp-Ch]
  unsigned int v29; // [esp+ACh] [ebp-8h]
  int v30; // [esp+B0h] [ebp-4h]

  v3 = a2;
  if ( !a2 )
    return 1;
  v6 = *a2;
  v7 = *a2 & 0xFFF00000;
  if ( !v7 || v7 == 544210944 )
    return 0;
  v8 = v6 & 0xFFFFF;
  v27 = a2[1] / (v6 & 0xFFFFFu);
  if ( v7 == 1884291072 || v7 == 1885339648 || v7 == 1886388224 )
    v27 = 2;
  if ( v27 <= 1 )
    return 0;
  v9 = this[34];
  v10 = this[31];
  v11 = this[32];
  v23[v11 + 18] = 0;
  v9 *= 4;
  *(_DWORD *)((char *)&v23[18] + v9) = 0;
  v10 *= 4;
  *(_DWORD *)((char *)&v23[18] + v10) = 0;
  v23[v11] = 1;
  v12 = 0;
  v13 = v27 == 0;
  *(_DWORD *)((char *)v23 + v9) = 3;
  *(_DWORD *)((char *)v23 + v10) = 1;
  v26 = 0;
  v28 = 0;
  if ( v13 )
    return 0;
  v25 = 0;
  v24 = 4 * v8;
  while ( 1 )
  {
    v14 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v12 + v3[2]));
    v15 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v14[1]) + 4);
    if ( (v15 & 0x200) != 0 )
    {
      if ( (v15 & 0x80u) == 0 )
      {
        v16 = this[31];
        goto LABEL_22;
      }
LABEL_17:
      v16 = this[37];
      goto LABEL_22;
    }
    if ( (v15 & 0x80u) != 0 )
      goto LABEL_17;
    v16 = (v15 & 0x10) == 0 || (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v14[27]) == 0xFFFF
        ? this[34]
        : this[32];
LABEL_22:
    v29 = 0;
    v30 = v16;
    if ( v28 )
    {
      v17 = this[5];
      v18 = (_DWORD *)v3[2];
      do
      {
        v19 = *(_DWORD **)(v17 + 4 * *v18);
        if ( v14[1] == v19[1] && v14[2] == v19[2] && v14[3] == v19[3] )
          break;
        ++v29;
        v18 = (_DWORD *)((char *)v18 + v24);
      }
      while ( v29 < v28 );
      v3 = a2;
    }
    v20 = v28;
    if ( v29 == v28 )
    {
      v21 = v30;
      v22 = &v23[v30 + 18];
      if ( ++*v22 > v23[v21] )
        break;
    }
    if ( (unsigned __int16)this[50] >= 0x200u && this[31] == v30 && (unsigned int)++v26 > 2 )
      break;
    v12 = v24 + v25;
    v28 = v20 + 1;
    v25 += v24;
    if ( v20 + 1 >= v27 )
      return 0;
  }
  if ( a3 )
    *a3 = v20;
  return 1;
}
