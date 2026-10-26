int __stdcall sub_561620(int a1)
{
  int result; // eax

  if ( (*(_BYTE *)(a1 + 60) & 2) == 0 )
  {
    if ( *(_DWORD *)(a1 + 68) )
      RecursiveTreeNodeTraversal(*(_DWORD *)(a1 + 68));
    if ( *(_DWORD *)(a1 + 64) )
    {
      if ( *(_DWORD *)(a1 + 76) )
        RecursiveTreeNodeTraversal(*(_DWORD *)(a1 + 76));
    }
    return sub_561660(a1);
  }
  return result;
}

