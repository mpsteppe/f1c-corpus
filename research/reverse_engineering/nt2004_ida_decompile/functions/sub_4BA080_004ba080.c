int __stdcall sub_4BA080(int a1)
{
  int v1; // eax
  int v2; // eax

  v1 = *(_DWORD *)(a1 + 20848);
  if ( *(_DWORD *)(a1 + 20884) == 1 && v1 >= 2 )
  {
    v2 = v1 - 2;
    if ( !(v2 % 2) && v2 < dword_7D74B8 - 1 && !sub_463490(dword_764D70) )
      sub_501F60(4, 0);
  }
  return 0;
}
