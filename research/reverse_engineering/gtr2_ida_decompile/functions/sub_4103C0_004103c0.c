int __thiscall sub_4103C0(_DWORD *this, char *String2)
{
  int result; // eax
  int v4; // esi
  int i; // ebx
  const char *v6; // eax

  result = 0;
  if ( String2 )
  {
    v4 = 0;
    if ( (int)this[4] > 0 )
    {
      for ( i = 0; ; i += 272 )
      {
        v6 = *(const char **)(this[3] + i + 4);
        if ( !v6 )
          v6 = WindowName;
        if ( !_stricmp(v6, String2) )
          break;
        if ( ++v4 >= this[4] )
          return 0;
      }
      return this[3] + 272 * v4;
    }
  }
  return result;
}
