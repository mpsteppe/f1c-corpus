int __thiscall sub_4CE990(_DWORD *this, int a2)
{
  int result; // eax

  if ( sub_579060(a2, aPlayerno) )
    this[5609] = 1;
  result = sub_579060(a2, aGentelem);
  if ( result )
    dword_75ABA0 = 1;
  return result;
}
