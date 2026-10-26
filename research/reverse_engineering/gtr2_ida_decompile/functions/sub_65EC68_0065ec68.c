// bad sp value at call has been detected, the output may be wrong!
int sub_65EC68(double *a1, char *Format, ...)
{
  int result; // eax
  char Buffer[255]; // [esp+0h] [ebp-1000h] BYREF
  _DWORD **v4; // [esp+FD8h] [ebp-28h]
  int v5; // [esp+FDCh] [ebp-24h]
  const char *v6; // [esp+FE0h] [ebp-20h]
  char *v7; // [esp+FE4h] [ebp-1Ch]
  int savedregs; // [esp+1000h] [ebp+0h]
  va_list va; // [esp+1010h] [ebp+10h] BYREF

  va_start(va, Format);
  sub_631BD0(0x1000u, savedregs);
  *((_DWORD *)a1 + 19) = 1;
  if ( !strcmp(Format, "syntax error") )
  {
    result = sub_65DF43(*(_DWORD **)a1, 2000, a1 + 2);
    if ( *((_DWORD *)a1 + 4) == 9 )
    {
      if ( *((_DWORD *)a1 + 21) == 2023 )
        sub_65DD1F(
          *(_DWORD **)a1,
          (int)(a1 + 2),
          2023,
          "'%s' is not a valid instruction in this shader version",
          *((const char **)a1 + 6));
      result = 2024;
      if ( *((_DWORD *)a1 + 21) == 2024 )
        return sub_65DD1F(
                 *(_DWORD **)a1,
                 (int)(a1 + 2),
                 2024,
                 "invalid instruction modifiers '%s'",
                 *((const char **)a1 + 6));
    }
  }
  else
  {
    _vsnprintf(Buffer, 0x1000u, Format, va);
    v7 = Buffer;
    v6 = "%s";
    v5 = 0;
    v4 = (_DWORD **)(a1 + 2);
    return sub_65DD1F(*(_DWORD **)a1, (int)(a1 + 2), 0, "%s", Buffer);
  }
  return result;
}
