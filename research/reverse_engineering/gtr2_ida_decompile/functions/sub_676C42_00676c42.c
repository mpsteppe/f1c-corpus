int __stdcall sub_676C42(_DWORD *a1, int a2, unsigned int a3)
{
  int v3; // eax

  if ( a2 >= 0 )
  {
    if ( sub_6768C8(a1, a2, &a2) < 0 )
      return 0;
  }
  else
  {
    a2 = -a2;
  }
  v3 = sub_676393(a2, a3);
  if ( !v3 )
    return 0;
  return -v3;
}
