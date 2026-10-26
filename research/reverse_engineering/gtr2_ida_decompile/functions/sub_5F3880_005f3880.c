int __thiscall sub_5F3880(int ArgList, const char *a2, int a3, int a4)
{
  char v6; // [esp+0h] [ebp-8h]

  if ( a4 )
  {
    if ( a2 )
      sub_5D8EF0(ArgList, a2, 63);
    else
      sub_5D8EF0(ArgList, "UnnamedQuery", 63);
    *(_DWORD *)(ArgList + 64) = a3;
    *(_BYTE *)(ArgList + 72) = 0;
    return -(sub_5F2B70((_DWORD *)ArgList, a4) != 0);
  }
  else
  {
    sub_5D8C80(ArgList, (char *)0xFFFFFFFF, "No HW device available for creating device query", v6);
    return -1;
  }
}
