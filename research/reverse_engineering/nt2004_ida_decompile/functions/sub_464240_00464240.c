char __thiscall sub_464240(int *this)
{
  char result; // al

  if ( sub_4B99F0(&byte_766124) )
    return 0;
  if ( dword_75CBB0 == 7 )
    sub_462B30((_DWORD *)*this);
  sub_461DA0((_DWORD *)*this);
  sub_460970(*this, -1);
  result = 1;
  *(_BYTE *)(*this + 636) = 1;
  return result;
}
