int __thiscall sub_65EBEC(_DWORD *this, CHAR *lpString2)
{
  int i; // esi

  for ( i = this[sub_65EBAB(lpString2)]; ; i = *(_DWORD *)(i + 32) )
  {
    if ( !i )
      return 0;
    if ( !lstrcmpiA(*(LPCSTR *)i, lpString2) )
      break;
  }
  return i;
}
