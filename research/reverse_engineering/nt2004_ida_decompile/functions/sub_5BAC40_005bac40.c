int __fastcall sub_5BAC40(char *name, u_short hostshort, int a3, _DWORD *a4)
{
  int result; // eax

  *(_WORD *)a3 = 2;
  *(_WORD *)(a3 + 2) = htons(hostshort);
  if ( name )
    *(_DWORD *)(a3 + 4) = inet_addr(name);
  else
    *(_DWORD *)(a3 + 4) = 0;
  if ( *(_DWORD *)(a3 + 4) != -1 || !strcmp(name, a255255255255) )
  {
    result = a3;
  }
  else
  {
    result = (int)gethostbyname(name);
    if ( !result )
      return result;
    *(_DWORD *)(a3 + 4) = ***(_DWORD ***)(result + 12);
  }
  if ( a4 )
    *a4 = result;
  return 1;
}
