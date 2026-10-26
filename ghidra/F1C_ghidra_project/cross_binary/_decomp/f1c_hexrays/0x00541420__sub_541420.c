// f1c  0x00541420  size=70
int __thiscall sub_541420(_DWORD *this)
{
  int result; // eax

  result = this[1107];
  if ( result )
  {
    sub_540EB0(this, this[1107]);
    sub_540EB0(this, this[1107] + 36);
    result = this[1107];
    if ( result )
      result = sub_587BCF((LPVOID)(result - 4));
    this[1107] = 0;
  }
  return result;
}
