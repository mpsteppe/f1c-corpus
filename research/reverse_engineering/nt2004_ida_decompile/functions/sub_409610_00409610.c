int __stdcall sub_409610(int a1)
{
  int v1; // eax

  v1 = 0;
  if ( (int)NumOfElements <= 0 )
    return 0;
  while ( *(_DWORD *)(dword_75AAD0[v1] + 20884) != a1 )
  {
    if ( ++v1 >= (int)NumOfElements )
      return 0;
  }
  return dword_75AAD0[v1];
}
