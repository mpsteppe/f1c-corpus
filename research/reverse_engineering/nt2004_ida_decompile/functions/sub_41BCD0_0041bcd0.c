int sub_41BCD0()
{
  int result; // eax

  result = dword_75AACC;
  if ( *(_DWORD *)(dword_75AACC + 16584) == 1 )
  {
    result = sub_42DBA0(&unk_62BF64);
    if ( (_BYTE)result )
      return sub_45D100(aPrepareForManu, 3, 16909060, 0);
  }
  return result;
}
