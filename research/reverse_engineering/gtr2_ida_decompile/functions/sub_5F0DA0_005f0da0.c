char __stdcall sub_5F0DA0(int a1)
{
  char result; // al

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 6328))-- == 1 )
    {
      sub_5F0BF0(a1);
      return sub_5F06E0(&dword_FB287C, a1, 1);
    }
  }
  return result;
}
