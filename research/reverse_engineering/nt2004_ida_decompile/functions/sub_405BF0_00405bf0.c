bool __thiscall sub_405BF0(void *this)
{
  int v1; // ecx
  int v2; // eax
  bool result; // al

  result = 0;
  if ( sub_405BE0(this) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)v1 + 36);
    if ( v2 > 0 && v2 <= 2 )
      return 1;
  }
  return result;
}
