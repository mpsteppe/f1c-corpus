// f1c  0x004d8840  size=23
int __thiscall sub_4D8840(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 == -1 || this[a2 + 29] )
    this[1] = a2;
  return result;
}
