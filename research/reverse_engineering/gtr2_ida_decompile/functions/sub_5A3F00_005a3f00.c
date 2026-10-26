int __thiscall sub_5A3F00(_BYTE *this, int a2)
{
  int result; // eax
  _BYTE *v3; // esi

  result = a2;
  v3 = this + 104;
  this[104] = 0;
  if ( a2 )
  {
    result = sub_630FE0(this + 104);
    v3[16] = 0;
  }
  return result;
}
