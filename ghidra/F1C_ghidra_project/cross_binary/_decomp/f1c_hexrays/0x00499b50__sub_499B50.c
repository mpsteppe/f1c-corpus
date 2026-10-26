// f1c  0x00499b50  size=43
int __thiscall sub_499B50(_DWORD *this)
{
  int result; // eax

  result = this[12];
  if ( result )
  {
    result = sub_5539F0(result);
    this[12] = 0;
  }
  if ( this[11] )
    return sub_5502C0();
  return result;
}
