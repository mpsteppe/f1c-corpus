int __stdcall sub_53A2B0(int a1, int a2, char *String1, char *a4)
{
  _DWORD *v4; // eax
  char *v5; // eax

  if ( !sub_53A250(a4) )
    return 1;
  v4 = (_DWORD *)sub_616630(String1);
  if ( !v4 )
    return 1;
  v5 = sub_48D380(v4);
  sub_630FE0(a1, v5, a2 - 1);
  *(_BYTE *)(a2 - 1 + a1) = 0;
  return 0;
}
