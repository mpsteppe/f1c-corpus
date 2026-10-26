int __thiscall sub_498D80(int this)
{
  const char *v2; // eax
  char *v3; // eax

  if ( byte_B65C78 )
  {
    v2 = (const char *)sub_4CFC00(0);
    v3 = sub_41D840(&byte_91CC38, v2);
    sub_615860(v3);
    sub_4CDE20(0);
    *(_DWORD *)(this + 308) = 1056964608;
    return 0;
  }
  else
  {
    sub_615860(WindowName);
    sub_4CDE20(1);
    if ( !*(_BYTE *)(this + 304) )
      *(_DWORD *)(this + 308) = dword_B65F7C[*(_DWORD *)(this + 312)];
    return 0;
  }
}
