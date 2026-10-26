bool __thiscall sub_404F10(void *this)
{
  int v1; // ecx
  int v2; // eax
  bool result; // al

  result = 0;
  if ( sub_404F00(this) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)v1 + 32);
    if ( v2 > 0 && v2 <= 2 )
      return 1;
  }
  return result;
}
