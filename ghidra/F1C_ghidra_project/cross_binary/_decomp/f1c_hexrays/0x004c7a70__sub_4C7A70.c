// f1c  0x004c7a70  size=38
unsigned int __thiscall sub_4C7A70(_DWORD *this, char a2)
{
  int v2; // eax
  unsigned int result; // eax

  v2 = this[4655];
  if ( a2 )
    result = v2 | 1;
  else
    result = v2 & 0xFFFFFFFE;
  this[4655] = result;
  return result;
}
