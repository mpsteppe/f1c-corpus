int __thiscall sub_584FF0(_BYTE *this, int a2)
{
  int result; // eax
  _BYTE *v3; // esi

  result = a2;
  v3 = this + 100;
  this[100] = 0;
  if ( a2 )
  {
    result = sub_587DD0(this + 100, a2, 16);
    v3[16] = 0;
  }
  return result;
}

