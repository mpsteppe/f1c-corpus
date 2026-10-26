// f1c  0x00562010  size=120
int __fastcall sub_562010(char *cp, u_short hostshort, int a3, _DWORD *a4)
{
  int result; // eax

  *(_WORD *)a3 = 2;
  *(_WORD *)(a3 + 2) = htons(hostshort);
  if ( cp )
    *(_DWORD *)(a3 + 4) = inet_addr(cp);
  else
    *(_DWORD *)(a3 + 4) = 0;
  if ( *(_DWORD *)(a3 + 4) != -1 || !strcmp(cp, a255255255255) )
  {
    result = a3;
  }
  else
  {
    result = (int)gethostbyname(cp);
    if ( !result )
      return result;
    *(_DWORD *)(a3 + 4) = ***(_DWORD ***)(result + 12);
  }
  if ( a4 )
    *a4 = result;
  return 1;
}
