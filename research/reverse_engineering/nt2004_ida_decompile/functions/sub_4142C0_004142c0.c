char __thiscall sub_4142C0(int this)
{
  char *v1; // edx
  char result; // al
  unsigned __int8 v3; // cl
  int v4; // esi

  v1 = *(char **)(this + 8);
  result = 0;
  if ( v1 )
  {
    v3 = *(_BYTE *)(this + 2);
    if ( v3 )
    {
      v4 = v3;
      do
      {
        if ( *v1 > 0 && *v1 <= 5 )
          ++result;
        ++v1;
        --v4;
      }
      while ( v4 );
    }
  }
  return result;
}
