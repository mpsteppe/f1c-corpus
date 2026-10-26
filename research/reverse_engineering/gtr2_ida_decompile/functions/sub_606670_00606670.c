int __stdcall sub_606670(int *a1, int a2)
{
  if ( (*(_BYTE *)a1 & 1) != 0 && !sub_5E7120(a1, 1) )
    sub_5E7180(a1, 0, 1);
  if ( (*(_BYTE *)a1 & 2) != 0 && !sub_5E7120(a1, 2) )
    sub_5E7180(a1, 0, 2);
  if ( (*(_BYTE *)a1 & 4) != 0 )
    sub_5E71A0(a1, 0, 4);
  if ( (*(_BYTE *)a1 & 8) != 0 )
    sub_5E71A0(a1, 0, 2);
  return 0;
}
