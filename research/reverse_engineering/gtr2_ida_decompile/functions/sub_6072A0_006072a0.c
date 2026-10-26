int __thiscall sub_6072A0(_DWORD *this, const char *ArgList, _DWORD *a3)
{
  int v4; // eax

  v4 = sub_5DA9A0(a3, ArgList, 0);
  if ( v4 )
  {
    sub_5FDFB0(this + 22, v4, 0);
    return 0;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Could not locate reflector instance %s", (char)ArgList);
    return -1;
  }
}
