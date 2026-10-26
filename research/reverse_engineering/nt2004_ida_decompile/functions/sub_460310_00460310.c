char *__thiscall sub_460310(_DWORD *this, int ArgList)
{
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // esi

  v2 = this[1628];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    if ( dword_75CBA8 != 5 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 3569) )
        sub_500FE0((int)&unk_7D7920, aCouldNotFindNa, ArgList);
    }
    return asc_5FFD4C;
  }
  else
  {
    v4 = this + 1580;
    while ( *v4 != ArgList )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    return (char *)&this[29 * v3 + 189];
  }
}
