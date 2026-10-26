int __thiscall sub_5FE010(void *this, int a2, const char *ArgList)
{
  const char *v4; // eax

  v4 = sub_5FDEA0(ArgList);
  if ( v4 )
  {
    *(_DWORD *)(a2 + 548) = v4;
    return 0;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Could not find actor %s", (char)ArgList);
    return -1;
  }
}
