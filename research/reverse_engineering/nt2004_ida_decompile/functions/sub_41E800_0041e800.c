void __stdcall sub_41E800(char *Str)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char String[80]; // [esp+8h] [ebp-50h] BYREF

  if ( Str )
  {
    v1 = strstr(Str, aConfig);
    if ( v1 && sscanf(v1, "config=%s", String) == 1 )
      sub_578600(String);
    v2 = strstr(Str, aSound);
    if ( v2 && sscanf(v2, "sound=%s", String) == 1 )
    {
      _strupr(String);
      byte_7D6B78 = strstr(String, off_5FC938) == 0;
    }
    v3 = strstr(Str, aMsgfont);
    if ( v3 && strtok(v3, Delimiter) )
    {
      v4 = strtok(0, word_5FD024);
      if ( v4 )
        sub_45CFC0(v4);
    }
  }
}
