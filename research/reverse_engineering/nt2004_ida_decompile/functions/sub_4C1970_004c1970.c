int __thiscall sub_4C1970(int *this, int a2)
{
  int result; // eax

  if ( !a2 )
    goto LABEL_4;
  if ( a2 != 2 )
  {
    result = a2 - 3;
    if ( a2 != 3 )
    {
LABEL_6:
      this[237] = a2;
      return result;
    }
LABEL_4:
    result = sub_4EED40(*this);
    if ( (_BYTE)result )
      result = sub_427260((_DWORD *)*this);
    goto LABEL_6;
  }
  result = sub_4271B0(*this, 1);
  dword_765E88 = 4;
  this[237] = 2;
  return result;
}
