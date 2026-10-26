int __thiscall sub_5E7070(void *this, const char *ArgList)
{
  void **v3; // eax

  v3 = (void **)sub_5E0740(this, ArgList, 0);
  if ( v3 )
  {
    sub_5DF6E0(v3);
    return 0;
  }
  else
  {
    sub_5D8C80(
      (int)this,
      (char *)0xFFFFFFFE,
      "File %s not found along any search paths or in any MAS file",
      (char)ArgList);
    sub_5D8CE0();
    return -2;
  }
}
