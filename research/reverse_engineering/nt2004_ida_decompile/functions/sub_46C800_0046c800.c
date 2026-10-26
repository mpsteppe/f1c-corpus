int __thiscall sub_46C800(_BYTE *this, int a2)
{
  int i; // esi
  int result; // eax

  for ( i = 0; i < 49; ++i )
    result = sub_46C6E0(&this[i], a2);
  return result;
}
