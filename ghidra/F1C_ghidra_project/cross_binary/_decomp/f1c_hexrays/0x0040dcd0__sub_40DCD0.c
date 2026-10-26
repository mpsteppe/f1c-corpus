// f1c  0x0040dcd0  size=96
char __thiscall sub_40DCD0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax

  v3 = this[34];
  this[33] = 0;
  *this = 1;
  sub_40D490(v3);
  v4 = sub_568210(a2);
  this[33] = v4;
  if ( !v4 )
    return 0;
  *this = 2;
  if ( (unsigned __int8)sub_40DDF0(this) )
    return 1;
  *this = -1;
  return 0;
}
