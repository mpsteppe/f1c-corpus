int __fastcall sub_5BA190(_DWORD *a1, const char *a2, int a3)
{
  const char *v4; // eax

  if ( !strcmp(a2, aPing) )
    return sub_4EC5D0(a1);
  v4 = (const char *)sub_5BA160((int)a1, (int)a2, 0);
  if ( v4 )
    return atoi(v4);
  else
    return a3;
}
