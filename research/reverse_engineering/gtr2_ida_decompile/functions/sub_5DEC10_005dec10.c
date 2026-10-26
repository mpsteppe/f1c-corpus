int __stdcall sub_5DEC10(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx

  if ( a3 )
  {
    result = a1;
    if ( a3 == 2 )
      v4 = *(_DWORD *)(a1 + 8) - a2;
    else
      v4 = a2 + *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 12) = v4;
  }
  else
  {
    result = a2;
    *(_DWORD *)(a1 + 12) = a2;
  }
  return result;
}
