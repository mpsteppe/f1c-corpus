int __thiscall sub_4B48D0(char *this)
{
  int v1; // eax
  int result; // eax

  v1 = dword_B7231C;
  *(_DWORD *)dword_B72314 = 5;
  if ( dword_B7231C > 5 || (v1 = dword_B72320, dword_B72320 < 5) )
    *(_DWORD *)dword_B72314 = v1;
  this[280] = *(_BYTE *)(dword_B6CBA8 + 1412);
  this[281] = *(_BYTE *)(dword_B6CBA8 + 1414);
  result = dword_B6CBA8;
  this[282] = *(_BYTE *)(dword_B6CBA8 + 1413);
  strcpy(this + 288, (const char *)(dword_B6CBA8 + 154));
  strcpy(this + 543, (const char *)(dword_B6CBA8 + 282));
  strcpy(this + 798, (const char *)(dword_B6CBA8 + 410));
  strcpy(this + 1053, (const char *)(dword_B6CBA8 + 538));
  strcpy(this + 1308, (const char *)(dword_B6CBA8 + 794));
  strcpy(this + 1563, (const char *)(dword_B6CBA8 + 666));
  return result;
}
