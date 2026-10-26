int __thiscall sub_42E290(_DWORD *this, double a2)
{
  int v2; // edx
  int result; // eax

  if ( a2 < 0.5 )
    this[5] = (int)((double)(int)this[6] * (a2 + a2));
  else
    this[5] = (int)((double)(this[4] - this[6] - 1) * (a2 + a2 - 1.0)) + this[6];
  v2 = this[5];
  result = this[4] - 1;
  if ( v2 >= 0 )
  {
    if ( v2 > result )
      this[5] = result;
  }
  else
  {
    this[5] = 0;
  }
  return result;
}

