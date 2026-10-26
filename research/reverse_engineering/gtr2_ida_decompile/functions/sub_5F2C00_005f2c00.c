int __thiscall sub_5F2C00(int ArgList, int a2, int a3, char a4)
{
  int v5; // eax
  int result; // eax

  v5 = *(_DWORD *)(ArgList + 68);
  if ( !v5 )
  {
    sub_5D8C80(ArgList, (char *)0xFFFFFFFF, "No hw query object for %s", ArgList);
    return -1;
  }
  if ( !*(_BYTE *)(ArgList + 72) )
  {
    sub_5D8C80(ArgList, (char *)0xFFFFFFFF, "No pending query for %s", ArgList);
    return -1;
  }
  result = (*(int (__stdcall **)(int, int, int, bool))(*(_DWORD *)v5 + 28))(v5, a2, a3, a4 != 0);
  if ( result )
    return -1;
  *(_BYTE *)(ArgList + 72) = 0;
  return result;
}
