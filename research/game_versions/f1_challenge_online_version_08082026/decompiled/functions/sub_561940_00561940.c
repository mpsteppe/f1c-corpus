LPVOID __thiscall sub_561940(LPVOID *this)
{
  LPVOID result; // eax

  result = this[123];
  if ( result )
  {
    result = (LPVOID)sub_587BCF(this[123]);
    this[123] = 0;
  }
  return result;
}
