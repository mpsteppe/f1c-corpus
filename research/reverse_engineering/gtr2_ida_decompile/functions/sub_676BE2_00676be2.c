int __stdcall sub_676BE2(int a1, int a2, int a3)
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
    v3 = (int)sub_67677A((_DWORD *)a1, (char *)a3, 1);
    if ( v3 )
      return -v3;
  }
  else
  {
    if ( a3 < 0 )
    {
      v3 = -a3;
      return -v3;
    }
    if ( sub_6768C8((_DWORD *)a1, a3, &a1) >= 0 )
    {
      v3 = a1;
      return -v3;
    }
  }
  return 0;
}
