int __thiscall sub_54BCD0(_DWORD *this, int a2, int a3, int a4)
{
  if ( this[17] )
    RecursiveTraversal(a2, a3, a4);
  if ( this[19] )
    RecursiveTraversal(a2, a3, a4);
  if ( a4 )
    return StateArrayWordSignExtension(a4);
  else
    return UIElementBitfieldStateSetter(a2, a3, 0);
}
