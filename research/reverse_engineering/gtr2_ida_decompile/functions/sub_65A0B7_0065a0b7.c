void sub_65A0B7(_DWORD *a1, char *Format, ...)
{
  bool v2; // zf
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF
  va_list va; // [esp+114h] [ebp+10h] BYREF

  va_start(va, Format);
  v2 = a1[20] == 0;
  a1[17] = 1;
  if ( !v2 )
  {
    if ( !strcmp(Format, "syntax error") )
    {
      if ( a1[19] && a1[158] == 9 )
        sub_65DD1F((int)(a1 + 6), (int)(a1 + 158), 1504, "invalid preprocessor command '%s'", a1[160]);
      else
        sub_65DF43((int)(a1 + 6), 1500, (int)(a1 + 158));
    }
    else
    {
      _vsnprintf(Buffer, 0x100u, Format, va);
      Buffer[255] = 0;
      sub_65DD1F((int)(a1 + 6), (int)(a1 + 158), 0, "%s", (char)Buffer);
    }
  }
}
