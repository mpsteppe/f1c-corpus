int __thiscall sub_6A02D7(_BYTE *this, int a2, unsigned int *a3, _DWORD *a4, int *a5)
{
  int v6; // ebx
  unsigned int v7; // eax
  int v8; // edi

  v6 = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108));
  v7 = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 88))(this, *(_DWORD *)(a2 + 108));
  *a3 = v7;
  if ( (this[112] & 0x40) != 0 )
  {
    if ( a5 )
      *a5 = 0;
    if ( v6 == 5 )
    {
      if ( *a3 || !a5 )
        goto LABEL_10;
      *a5 = 1;
    }
    if ( v6 == 0xFFFF )
    {
      *a4 = 0;
      return 0;
    }
LABEL_10:
    *a4 = 6;
    *a3 = *(_DWORD *)(a2 + 12);
    return 0;
  }
  v8 = 0;
  if ( v6 != 11 )
  {
    switch ( v6 )
    {
      case 0xD:
        if ( v7 )
          return -2147467259;
        v8 = 1;
        *a4 = 9;
        break;
      case 0x11:
        if ( v7 )
          return -2147467259;
        *a4 = 17;
        *a3 = 1;
        break;
      case 0x12:
        if ( v7 )
          return -2147467259;
        *a4 = 17;
        *a3 = 0;
        break;
      case 0xFFFF:
        *a4 = 0;
        v8 = 0;
        break;
      default:
        return -2147467259;
    }
LABEL_25:
    if ( a5 )
      *a5 = v8;
    return 0;
  }
  if ( v7 < 4 )
  {
    *a4 = 8;
    goto LABEL_25;
  }
  return -2147467259;
}
