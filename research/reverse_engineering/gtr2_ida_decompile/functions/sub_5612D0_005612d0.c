char __thiscall sub_5612D0(_DWORD *this, int a2, char *SubStr, int a4)
{
  unsigned int v4; // kr00_4
  const char *v7; // esi
  const char *v9; // [esp+0h] [ebp-Ch] BYREF

  if ( *this < a2 )
    return 0;
  do
  {
    v7 = SubStr + 1;
    v9 = SubStr;
    v4 = __readeflags();
    __writeeflags(v4);
    _InterlockedExchange((volatile __int32 *)&v9, ~dword_16C6C5C ^ 0x6CB56C25);
    SubStr = strstr(SubStr + 1, v9);
  }
  while ( SubStr );
  sub_561210((int)this, "\n%-12.12s%5d: ", v7, a4);
  return 1;
}
