int __thiscall sub_47BFC0(_DWORD **this)
{
  int v2; // eax

  sub_419110(byte_6292D0);
  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 1);
  if ( v2 )
    sub_47C540(v2);
  byte_7683F0 = 0;
  if ( byte_7683F2 )
    byte_7683F0 = byte_7683F2;
  if ( *(_DWORD *)dword_7689CC == 5 )
    sub_4AD720(aMprulessetting, 1);
  else
    dword_608F60 = 1;
  return -1;
}
