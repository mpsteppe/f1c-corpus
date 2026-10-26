int __thiscall sub_464B10(_BYTE *this, int a2)
{
  int i; // esi
  int result; // eax

  for ( i = 0; i < 104; ++i )
    result = SaturatedByteAdd(&this[i], a2);
  return result;
}
