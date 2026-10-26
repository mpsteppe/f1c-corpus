int __thiscall sub_576A50(int *this)
{
  int result; // eax

  if ( this[4603] == 1 )
    this[4603] = 0;
  result = *this;
  if ( *(_DWORD *)(*this + 22468) == *(_DWORD *)(dword_91E084 + 22468) )
  {
    if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
      return sub_4503F0((int)&dbl_B66040);
    result = sub_473630(&dword_B6CBA8);
    if ( !(_BYTE)result )
      return sub_4503F0((int)&dbl_B66040);
  }
  return result;
}
