// f1c  0x005644b0  size=58
char *__fastcall sub_5644B0(struct in_addr *a1, const char *a2, int a3)
{
  int v4; // eax

  if ( !strcmp(a2, aHostaddr) )
    return sub_564490(a1);
  v4 = sub_5644F0(a1);
  if ( v4 )
    return *(char **)(v4 + 4);
  else
    return (char *)a3;
}
