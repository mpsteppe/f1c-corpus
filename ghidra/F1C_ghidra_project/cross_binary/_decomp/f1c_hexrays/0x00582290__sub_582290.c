// f1c  0x00582290  size=17
char __thiscall sub_582290(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 8);
  if ( result )
    return sub_587BCF(*(LPVOID *)this);
  return result;
}
