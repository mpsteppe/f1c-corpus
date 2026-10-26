int __stdcall sub_676B92(int a1, int a2, unsigned int a3)
{
  int v3; // eax

  if ( a2 )
  {
    if ( a2 >= 0 )
    {
      if ( sub_6768C8((_DWORD *)a1, a2, &a1) < 0 )
        return 0;
    }
    else
    {
      a1 = -a2;
    }
    v3 = sub_6736C9((_DWORD *)a1, a3);
    if ( v3 )
      return -v3;
  }
  else if ( a3 < *(_DWORD *)(a1 + 24) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * a3);
    return -v3;
  }
  return 0;
}
