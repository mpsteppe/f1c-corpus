const CHAR *__thiscall sub_4CE4B0(_DWORD *this, int a2)
{
  const CHAR *result; // eax
  int v3; // ecx
  int v4; // edx

  result = WindowName;
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
      result = *(const CHAR **)(v3 + 276);
      if ( !result )
        return WindowName;
    }
  }
  return result;
}
