int __cdecl sub_597568(unsigned int *a1, unsigned int *a2)
{
  if ( OverflowCheckedUnsignedAddition(*a1, *a2, a1) && OverflowCheckedUnsignedAddition(a1[1], 1u, a1 + 1) )
    ++a1[2];
  if ( OverflowCheckedUnsignedAddition(a1[1], a2[1], a1 + 1) )
    ++a1[2];
  return OverflowCheckedUnsignedAddition(a1[2], a2[2], a1 + 2);
}

