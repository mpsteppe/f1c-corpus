int __thiscall sub_431F80(_DWORD *this, double a2)
{
  int v3; // eax
  int v4; // ecx
  int result; // eax

  if ( a2 < 0.5 )
    v3 = sub_431910((double)(int)this[6] * (a2 + a2));
  else
    v3 = this[6] + sub_431910((double)(this[4] - this[6] - 1) * (a2 + a2 - 1.0));
  this[5] = v3;
  v4 = this[5];
  result = this[4] - 1;
  if ( v4 >= 0 )
  {
    if ( v4 > result )
      this[5] = result;
  }
  else
  {
    this[5] = 0;
  }
  return result;
}
