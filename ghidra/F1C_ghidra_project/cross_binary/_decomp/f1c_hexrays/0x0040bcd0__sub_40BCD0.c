// f1c  0x0040bcd0  size=61
char __thiscall sub_40BCD0(_DWORD *this, int a2, char a3)
{
  int v4; // eax

  if ( !a2 )
    return 0;
  v4 = sub_40B6C0(this, a2);
  if ( v4 < 0 )
    return 0;
  sub_40B6F0(this, v4);
  if ( a3 )
    (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
  return 1;
}
