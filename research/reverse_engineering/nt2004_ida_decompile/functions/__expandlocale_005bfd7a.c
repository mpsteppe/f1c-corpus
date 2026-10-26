char *__cdecl _expandlocale(char *Str2, char *Destination, _WORD *a3, _DWORD *a4)
{
  char *result; // eax
  char Source[136]; // [esp+Ch] [ebp-88h] BYREF

  if ( !Str2 )
    return 0;
  if ( *Str2 == 67 && !Str2[1] )
  {
    result = Destination;
    Destination[1] = 0;
    *Destination = 67;
    if ( a3 )
    {
      *a3 = 0;
      a3[1] = 0;
      a3[2] = 0;
    }
    if ( a4 )
      *a4 = 0;
    return result;
  }
  if ( strcmp(aC_1, Str2) && strcmp(aC_2, Str2) )
  {
    if ( __lc_strtolc(Source, Str2) || !__get_qualified_locale(Source, &unk_7FF0F4, Source) )
      return 0;
    dword_7FF0FC = (unsigned __int16)word_7FF0F8;
    __lc_lctostr(aC_1, Source);
    if ( *Str2 )
      strcpy(aC_2, Str2);
    else
      strcpy(aC_2, aC_1);
  }
  if ( a3 )
    memcpy_0(a3, &unk_7FF0F4, 6u);
  if ( a4 )
    memcpy_0(a4, &dword_7FF0FC, sizeof(_DWORD));
  strcpy(Destination, aC_1);
  return aC_1;
}
