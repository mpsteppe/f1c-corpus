void *__thiscall sub_4D6800(_DWORD *this)
{
  void *result; // eax

  sub_566650(byte_5EA438);
  result = (void *)this[5];
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  if ( result )
  {
    result = (void *)sub_587BCF(result);
    this[5] = 0;
  }
  return result;
}
