int __thiscall sub_4EEC50(_DWORD *this, char a2)
{
  int v3; // eax

  if ( a2 )
  {
    this[6324] |= 6u;
    if ( (unsigned __int8)sub_4EED40(this) )
    {
      v3 = sub_40C470(&dword_6291CC);
      return sub_50B4E0(v3, 0);
    }
    else
    {
      return sub_50B4E0(0, 0);
    }
  }
  else
  {
    if ( (this[6324] & 2) != 0 && dword_75CBA8 == 5 )
      sub_526140(this + 23);
    this[6324] &= 0xFFFFFFF9;
    return sub_50B4E0(3, 0);
  }
}
