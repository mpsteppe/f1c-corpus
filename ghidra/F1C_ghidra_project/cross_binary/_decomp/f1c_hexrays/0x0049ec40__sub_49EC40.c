// f1c  0x0049ec40  size=29
int __thiscall sub_49EC40(int *this)
{
  int result; // eax

  result = *this;
  if ( *this )
  {
    result = sub_5539F0(result);
    *this = 0;
  }
  return result;
}
