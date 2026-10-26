int __stdcall sub_53C5D0(int a1)
{
  int result; // eax
  int i; // ecx

  result = dword_8B8F28;
  if ( dword_8B8F28 )
  {
    for ( i = *(_DWORD *)(dword_8B8F28 + 488); i; i = *(_DWORD *)(i + 488) )
      result = i;
    *(_DWORD *)(result + 488) = a1;
    *(_DWORD *)(a1 + 484) = result;
    *(_DWORD *)(a1 + 488) = 0;
  }
  else
  {
    result = a1;
    dword_8B8F28 = a1;
    *(_DWORD *)(a1 + 484) = 0;
    *(_DWORD *)(a1 + 488) = 0;
  }
  return result;
}

