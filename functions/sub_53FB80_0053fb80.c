int __thiscall sub_53FB80(int *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( (*(_BYTE *)(a2 + 24) & 4) != 0 )
  {
    v3 = *(_DWORD *)(a2 + 16);
    if ( v3 )
    {
      if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 16)) )
        goto LABEL_19;
      *(_DWORD *)(a2 + 24) &= ~4u;
    }
  }
  v4 = *(_DWORD *)(a2 + 24);
  if ( (v4 & 8) != 0 && *(_DWORD *)(a2 + 20) )
  {
    if ( (v4 & 0x40000) != 0 && *(_DWORD *)(a2 + 4) )
      sub_53F6E0(this, *(_DWORD *)(a2 + 4));
    if ( (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 20) + 8))(*(_DWORD *)(a2 + 20)) )
      goto LABEL_19;
    *(_DWORD *)(a2 + 24) &= ~8u;
  }
  if ( (*(_BYTE *)(a2 + 24) & 1) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 8);
    if ( v5 )
    {
      if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(a2 + 8)) )
      {
        *(_DWORD *)(a2 + 24) &= ~1u;
        goto LABEL_16;
      }
LABEL_19:
      sub_53C590(-1, aInvalidParamet);
      return -1;
    }
  }
LABEL_16:
  if ( (*(_BYTE *)(a2 + 24) & 2) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 12);
    if ( v6 )
    {
      if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(*(_DWORD *)(a2 + 12)) )
        goto LABEL_19;
      *(_DWORD *)(a2 + 24) &= ~2u;
    }
  }
  return 0;
}
