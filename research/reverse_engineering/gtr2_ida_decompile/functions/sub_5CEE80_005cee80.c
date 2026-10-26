int __thiscall sub_5CEE80(int *this, float a2, int a3)
{
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2

  if ( !*this || a2 >= (double)*(float *)(this[2] + 8 * *this - 4) )
    return sub_5C7140();
  if ( !(v5 | v6) )
    sub_5C6F60(this, a2);
  return sub_5C71A0();
}
