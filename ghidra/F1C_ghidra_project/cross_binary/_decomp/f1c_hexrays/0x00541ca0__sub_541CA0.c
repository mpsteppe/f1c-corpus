// f1c  0x00541ca0  size=38
unsigned int __thiscall sub_541CA0(_DWORD *this, int a2)
{
  int v2; // eax
  unsigned int result; // eax

  v2 = this[32];
  if ( a2 )
    result = v2 | 8;
  else
    result = v2 & 0xFFFFFFF7;
  this[32] = result;
  return result;
}
