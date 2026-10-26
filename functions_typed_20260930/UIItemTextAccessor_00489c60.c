char *__thiscall sub_489C60(_DWORD *this, int a2)
{
  char *result; // eax
  int v3; // ecx
  int v4; // edx

  result = byte_5EA438;
  if ( a2 < this[37] && a2 >= 0 )
  {
    v3 = this[36];
    v4 = 0;
    if ( v3 )
    {
      while ( v4 < a2 )
      {
        v3 = *(_DWORD *)(v3 + 140);
        ++v4;
        if ( !v3 )
          return result;
      }
      result = *(char **)(v3 + 160);
      if ( !result )
        return byte_5EA438;
    }
  }
  return result;
}

