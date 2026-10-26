CHAR *__thiscall sub_49FE70(_DWORD *this, int a2)
{
  CHAR *result; // eax
  int v3; // ecx
  int v4; // edx

  result = &byte_629120;
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
      result = *(CHAR **)(v3 + 272);
      if ( !result )
        return &byte_629120;
    }
  }
  return result;
}
