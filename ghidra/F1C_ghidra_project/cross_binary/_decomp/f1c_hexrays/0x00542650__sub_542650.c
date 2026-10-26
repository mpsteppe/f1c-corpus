// f1c  0x00542650  size=38
unsigned int __thiscall sub_542650(_DWORD *this, int a2)
{
  int v2; // eax
  unsigned int result; // eax

  v2 = this[32];
  if ( a2 )
    result = v2 | 0x20;
  else
    result = v2 & 0xFFFFFFDF;
  this[32] = result;
  return result;
}
