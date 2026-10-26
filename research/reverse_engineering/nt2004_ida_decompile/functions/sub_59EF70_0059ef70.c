int __thiscall sub_59EF70(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  if ( this[17] && a3 )
    result = sub_59EF70(a2, a3, 1);
  if ( this[19] && (a3 & a4) != 0 )
    result = sub_59EF70(a2, a3, 1);
  if ( this[140] )
  {
    if ( a2 )
      return sub_5B88F0();
    else
      return sub_5B8900();
  }
  return result;
}
