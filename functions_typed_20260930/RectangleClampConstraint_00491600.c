int __thiscall sub_491600(__int16 *this, int a2, int a3, __int16 a4, int a5)
{
  int v5; // edx
  int v6; // esi
  __int16 v7; // ax
  int result; // eax
  int v9; // edx

  v5 = this[1];
  if ( v5 < a3 )
  {
    this[3] -= a3 - v5;
    this[1] = a3;
  }
  v6 = *this;
  if ( v6 < a2 )
  {
    this[2] -= a2 - v6;
    *this = a2;
  }
  v7 = a4 + a2 + 1;
  if ( (__int16)(*this + this[2] + 1) > v7 )
    this[2] = v7 - *this;
  result = a3 + a5;
  v9 = (unsigned __int16)this[1];
  if ( (__int16)v9 + this[3] > a3 + a5 )
  {
    result -= v9;
    this[3] = result;
  }
  return result;
}

