void __thiscall sub_4EDF00(int this)
{
  const char *v2; // esi
  char *v3; // eax
  char Source[16]; // [esp+Ch] [ebp-50h] BYREF
  char Str[64]; // [esp+1Ch] [ebp-40h] BYREF

  v2 = (const char *)(this + 24772);
  if ( this != -24772 )
  {
    if ( sub_41F230(dword_62A170, (const char *)(this + 24772), Destination) )
    {
      if ( v2 )
      {
        strncpy(Destination, v2, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        Destination[0] = 0;
      }
    }
    strncpy(Str, Destination, 0x3Fu);
    Str[63] = 0;
    v3 = strstr(Str, word_5FBEBC);
    if ( v3 )
      sprintf(Source, "%c. %-.12s", Str[0], v3 + 1);
    else
      sprintf(Source, "%-.15s", Str);
    _strupr(Source);
    strncpy((char *)(this + 24972), Source, 0xFu);
    *(_BYTE *)(this + 24987) = 0;
  }
}
