char *__cdecl _expandlocale(char *Str2, char *Destination, _WORD *a3, _DWORD *a4)
{
  const CHAR *v4; // esi
  char *result; // eax
  char Source[144]; // [esp+4h] [ebp-94h] BYREF
  int v7; // [esp+94h] [ebp-4h]

  v4 = Str2;
  v7 = dword_912B08;
  if ( !Str2 )
    return 0;
  if ( *Str2 != 67 || Str2[1] )
  {
    if ( sub_6354D0(Str2) >= 0x82u || strcmp(Str1, Str2) && strcmp(aC_7, Str2) )
    {
      if ( __lc_strtolc(Source, Str2) || !__get_qualified_locale((int)Source, (int)&unk_FB8184, Source) )
        return 0;
      dword_FB818C = (unsigned __int16)word_FB8188;
      __lc_lctostr(Str1, Source);
      if ( !*Str2 || sub_6354D0(Str2) >= 0x82u )
        v4 = WindowName;
      byte_9129BA = 0;
      sub_630FE0((int)aC_7, (int)v4, 130);
    }
    if ( a3 )
      memcpy_0(a3, &unk_FB8184, 6u);
    if ( a4 )
      memcpy_0(a4, &dword_FB818C, sizeof(_DWORD));
    strcpy(Destination, Str1);
    return Str1;
  }
  else
  {
    result = Destination;
    *Destination = 67;
    Destination[1] = 0;
    if ( a3 )
    {
      *a3 = 0;
      a3[1] = 0;
      a3[2] = 0;
    }
    if ( a4 )
      *a4 = 0;
  }
  return result;
}
