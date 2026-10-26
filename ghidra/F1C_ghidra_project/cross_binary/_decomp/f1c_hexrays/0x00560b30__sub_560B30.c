// f1c  0x00560b30  size=34
LPVOID __thiscall sub_560B30(LPVOID *this)
{
  LPVOID result; // eax

  result = this[107];
  if ( result )
  {
    result = (LPVOID)sub_587BCF(this[107]);
    this[107] = 0;
  }
  return result;
}
