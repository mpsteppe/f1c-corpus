int __thiscall sub_4A5E10(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int result; // eax

  v1 = this[97];
  if ( !v1 )
    return StateChangeNotify((int)this, 1);
  v2 = v1 - 1;
  if ( !v2 )
    return StateChangeNotify((int)this, 0);
  result = v2 - 3;
  if ( !result )
    return StateChangeNotify((int)this, 1);
  return result;
}
