char __thiscall sub_414250(int this)
{
  char result; // al
  unsigned __int8 v2; // bl
  char *v3; // ecx
  int v4; // edx

  result = 0;
  if ( *(_DWORD *)(this + 8) )
  {
    v2 = *(_BYTE *)(this + 2);
    if ( v2 )
    {
      v3 = *(char **)(this + 8);
      v4 = v2;
      do
      {
        if ( *v3 > 0 )
          ++result;
        ++v3;
        --v4;
      }
      while ( v4 );
    }
  }
  return result;
}
