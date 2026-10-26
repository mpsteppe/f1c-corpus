// f1c  0x004915a0  size=83
bool __thiscall sub_4915A0(__int16 *this, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // eax
  bool result; // al

  v5 = *this;
  result = 0;
  if ( v5 >= a2 && v5 < a2 + a4 )
  {
    v6 = this[1];
    if ( v6 >= a3 && v6 < a5 + a3 && v5 + this[2] <= a2 + a4 && v6 + this[3] <= a5 + a3 )
      return 1;
  }
  return result;
}
