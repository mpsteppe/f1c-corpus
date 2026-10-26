// f1c  0x00411680  size=35
_WORD *__thiscall sub_411680(_WORD *this)
{
  _WORD *result; // eax
  _WORD *v2; // edx
  int v3; // esi

  result = this;
  v2 = this;
  v3 = 537;
  do
  {
    *v2 = 1;
    v2[1] = 0;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  return result;
}
