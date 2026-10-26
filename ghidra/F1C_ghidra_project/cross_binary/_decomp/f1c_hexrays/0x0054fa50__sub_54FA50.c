// f1c  0x0054fa50  size=49
LPVOID *__thiscall sub_54FA50(LPVOID *this)
{
  LPVOID *result; // eax

  result = (LPVOID *)this[120];
  if ( result )
  {
    sub_587BCF(result[2]);
    result = (LPVOID *)sub_587BCF(this[120]);
    this[120] = 0;
  }
  return result;
}
