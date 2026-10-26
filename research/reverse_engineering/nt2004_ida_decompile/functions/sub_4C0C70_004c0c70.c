int __thiscall sub_4C0C70(_DWORD *this, int ArgList)
{
  if ( ArgList < 0 || ArgList >= *(_DWORD *)(this[195] + 16) )
    return 0;
  else
    return sub_5009C0(ArgList);
}
