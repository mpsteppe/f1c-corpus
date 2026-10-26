int __thiscall sub_4E2570(int *this, int a2, char *String2, const char *ArgList)
{
  int v4; // esi
  char Buffer[509]; // [esp+10h] [ebp-200h] BYREF
  __int16 v7; // [esp+20Dh] [ebp-3h]
  char v8; // [esp+20Fh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v7 = 0;
  v8 = 0;
  sub_4E2510(this);
  sub_405480(Buffer, 0x1FFu, "%s AND: %s NOT: NotAI", ArgList, aTvfavorite);
  v4 = sub_4E26F0(a2, String2, (int)Buffer, 0);
  if ( v4 < a2 )
  {
    sub_405480(Buffer, 0x1FFu, "%s AND: %s NOT: NotAI", ArgList, aWinstoncup);
    v4 += sub_4E26F0(a2 - v4, String2, (int)Buffer, 0);
    if ( v4 < a2 )
    {
      sub_405480(Buffer, 0x1FFu, "%s AND: %s NOT: NotAI", ArgList, aBusch);
      v4 += sub_4E26F0(a2 - v4, String2, (int)Buffer, 0);
      if ( v4 < a2 )
      {
        sub_405480(Buffer, 0x1FFu, "%s AND: %s NOT: NotAI", ArgList, aLegends);
        v4 += sub_4E26F0(a2 - v4, String2, (int)Buffer, 0);
        if ( v4 < a2 )
        {
          sub_405480(Buffer, 0x1FFu, "%s NOT: NotAI", ArgList);
          v4 += sub_4E26F0(a2 - v4, String2, (int)Buffer, 1);
        }
      }
    }
  }
  return v4;
}
