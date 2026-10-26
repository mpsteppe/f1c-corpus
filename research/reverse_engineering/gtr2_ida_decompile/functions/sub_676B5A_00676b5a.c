int __stdcall sub_676B5A(_DWORD *a1, int a2)
{
  int v2; // eax

  if ( a2 >= 0 )
  {
    if ( sub_6768C8(a1, a2, &a2) < 0 )
      return -1;
    v2 = a2;
  }
  else
  {
    v2 = -a2;
  }
  if ( *(_WORD *)(v2 + 8) != 3 )
    return -1;
  return *(unsigned __int16 *)(v2 + 10);
}
