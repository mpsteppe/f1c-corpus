char __thiscall sub_4DCA60(_DWORD *this)
{
  int v1; // esi
  char result; // al
  int v3; // edx
  _DWORD *i; // ecx

  v1 = this[16];
  result = 0;
  v3 = 0;
  if ( v1 > 0 )
  {
    for ( i = this + 17; *i != 3; i += 3 )
    {
      if ( ++v3 >= v1 )
        return result;
    }
    return 1;
  }
  return result;
}
