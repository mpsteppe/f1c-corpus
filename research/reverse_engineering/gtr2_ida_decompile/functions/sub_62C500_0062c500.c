int __thiscall sub_62C500(_DWORD *this)
{
  _DWORD *v1; // eax

  if ( !this )
    return -2;
  v1 = (_DWORD *)this[7];
  if ( !v1 )
    return -2;
  this[5] = 0;
  this[2] = 0;
  this[6] = 0;
  *v1 = v1[3] != 0 ? 7 : 0;
  sub_62E710(0);
  return 0;
}
