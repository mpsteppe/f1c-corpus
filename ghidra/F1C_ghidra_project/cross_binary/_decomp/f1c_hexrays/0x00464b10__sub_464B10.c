// f1c  0x00464b10  size=37
int __thiscall sub_464B10(_BYTE *this, int a2)
{
  int i; // esi
  int result; // eax

  for ( i = 0; i < 104; ++i )
    result = sub_464A10(&this[i], a2);
  return result;
}
