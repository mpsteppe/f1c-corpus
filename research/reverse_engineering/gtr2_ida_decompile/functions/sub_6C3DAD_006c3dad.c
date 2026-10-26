int __thiscall sub_6C3DAD(int this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  int v7; // edi
  _DWORD *v10; // ebx
  _DWORD *v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx

  v7 = a6;
  if ( !a6 )
    return 1;
  v10 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * a6 - 4);
  if ( sub_680F76(v10) || (*v10 & 0xF0000000) == 0x60000000 )
    return 1;
  while ( 1 )
  {
    --a6;
    v11 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * a6);
    if ( v11[9] != v7 && (*v11 & 0xFFF00000) != 0 )
    {
      if ( (*v11 & 0xF0000000) == 0x60000000 || sub_680F76(v11) )
        return 1;
      sub_6BB9A9(a5, v11, v7);
      v12 = *(_DWORD *)(this + 24);
      v13 = *(_DWORD *)(v12 + 4 * v7 - 4);
      v14 = *(_DWORD *)(v12 + 4 * a6);
      if ( *(_DWORD *)(v13 + 12) )
      {
        if ( *(_DWORD *)(v14 + 12) )
          break;
      }
    }
LABEL_18:
    if ( !a6 )
      return 1;
  }
  v15 = *(_DWORD *)(this + 20);
  v16 = *(_DWORD *)(v15 + 4 * **(_DWORD **)(v13 + 16));
  v17 = *(_DWORD *)(v15 + 4 * **(_DWORD **)(v14 + 16));
  if ( *(_DWORD *)(v16 + 20) != *(_DWORD *)(v17 + 20) || *(_DWORD *)(v16 + 24) != *(_DWORD *)(v17 + 24) )
    return 1;
  sub_6C3B64((_DWORD *)this, v7 - 1, a6);
  if ( (*(_BYTE *)(this + 111) & 0x10) == 0 && sub_68E712(v18, a2, 0) < 0 || a7 && sub_68E712(this, a3, 0) < 0 )
  {
    sub_6C3B64((_DWORD *)this, a6, v7 - 1);
    sub_6BB9A9(a5, v11, v7);
    goto LABEL_18;
  }
  return 0;
}
