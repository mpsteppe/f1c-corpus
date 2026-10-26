bool __thiscall SeasonRaceCountCheck(int *this)
{
  _DWORD *v2; // eax
  int v3; // eax
  bool result; // al

  result = 0;
  if ( this )
  {
    v2 = (_DWORD *)LinkedListDereference(dword_7D2DB0);
    v3 = FlagsGetter(v2);
    if ( v3 > 0 && this[v3 + 5] <= 4 )
      return 1;
  }
  return result;
}

