int __thiscall sub_666E91(_DWORD *this, _DWORD *a2, unsigned int *a3, unsigned int a4, int a5, int a6, int a7, int a8)
{
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+4h] [ebp-4h] BYREF

  if ( !a2 )
    return 0;
  v10 = this[2];
  v17 = 0;
  if ( a4 >= *(_DWORD *)(v10 + 4) )
    v11 = 0;
  else
    v11 = *(_DWORD *)(*(_DWORD *)(v10 + 16) + 4 * a4);
  if ( !v11 )
    return -2147467259;
  v12 = sub_681B61(v11);
  v13 = this[2];
  if ( v12 >= *(_DWORD *)(v13 + 4) )
    v14 = 0;
  else
    v14 = *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * v12);
  if ( !v14 )
    return -2147024882;
  *(_DWORD *)(v14 + 4) |= 0x40u;
  v15 = *(_DWORD *)(v14 + 4);
  if ( (v15 & 0x10) != 0 && (v15 & 0x80u) == 0 )
  {
    if ( (v15 & 0x200) != 0 && (*(_DWORD *)(this[2] + 112) & 0x200) != 0 )
      *(_DWORD *)(v14 + 4) = v15 | 0x400;
    v16 = *(_DWORD *)(v14 + 4);
    if ( (v16 & 0x200) == 0 && (*(_DWORD *)(this[2] + 112) & 0x400) != 0 )
      *(_DWORD *)(v14 + 4) = v16 | 0x100400;
  }
  return sub_664A70(this, a2, a3, v12, a5, a6, a7, &v17, a7, a8, 0);
}
