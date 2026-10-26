// f1c  0x00462160  size=231
char __thiscall sub_462160(int *this, int a2, char a3, char a4)
{
  int v4; // eax

  v4 = *this;
  if ( *(_DWORD *)(*this + 112540) )
  {
    if ( a3 )
      *(_BYTE *)(v4 + 196) = a2 != dword_7D1020 || *(_BYTE *)(v4 + 196) == 0;
    dword_7D1020 = a2;
    if ( a2 >= dword_7D1028 )
    {
      if ( a2 > dword_7D102C )
        dword_7D1020 = dword_7D102C;
    }
    else
    {
      dword_7D1020 = dword_7D1028;
    }
    v4 = sub_461FC0(this);
    if ( v4 )
      goto LABEL_19;
    switch ( dword_7D1020 )
    {
      case 1:
        sub_563EC0(aPing, 0);
        break;
      case 2:
        sub_563EC0(aMapname, 3);
        break;
      case 3:
        sub_563EC0(aNumplayers, 0);
        break;
      default:
        sub_563EC0(aHostname, 3);
        break;
    }
    LOBYTE(v4) = a4;
    if ( a4 )
LABEL_19:
      byte_7CD2A0 = 1;
  }
  return v4;
}
