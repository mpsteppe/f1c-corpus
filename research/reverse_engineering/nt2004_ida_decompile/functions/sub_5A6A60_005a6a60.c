int __thiscall sub_5A6A60(int *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( (*(_BYTE *)(a2 + 56) & 4) != 0 )
  {
    v3 = *(_DWORD *)(a2 + 20);
    if ( v3 )
    {
      if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 20)) )
        goto LABEL_19;
      *(_DWORD *)(a2 + 56) &= ~4u;
    }
  }
  v4 = *(_DWORD *)(a2 + 56);
  if ( (v4 & 8) != 0 && *(_DWORD *)(a2 + 24) )
  {
    if ( (v4 & 0x40000) != 0 && *(_DWORD *)(a2 + 8) )
      sub_5A65C0(this, *(_DWORD *)(a2 + 8));
    if ( (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 8))(*(_DWORD *)(a2 + 24)) )
      goto LABEL_19;
    *(_DWORD *)(a2 + 56) &= ~8u;
  }
  if ( (*(_BYTE *)(a2 + 56) & 1) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 12);
    if ( v5 )
    {
      if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(a2 + 12)) )
      {
        *(_DWORD *)(a2 + 56) &= ~1u;
        goto LABEL_16;
      }
LABEL_19:
      sub_591C60((int)this, -1, aInvalidParamet);
      return -1;
    }
  }
LABEL_16:
  if ( (*(_BYTE *)(a2 + 56) & 2) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 16);
    if ( v6 )
    {
      if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(*(_DWORD *)(a2 + 16)) )
        goto LABEL_19;
      *(_DWORD *)(a2 + 56) &= ~2u;
    }
  }
  return 0;
}
