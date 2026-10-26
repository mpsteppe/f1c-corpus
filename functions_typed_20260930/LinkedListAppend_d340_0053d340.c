int __stdcall sub_53D340(int a1)
{
  int result; // eax
  int i; // ecx

  result = dword_8B8E20;
  if ( dword_8B8E20 )
  {
    for ( i = *(_DWORD *)(dword_8B8E20 + 2160); i; i = *(_DWORD *)(i + 2160) )
      result = i;
    *(_DWORD *)(result + 2160) = a1;
    *(_DWORD *)(a1 + 2156) = result;
    *(_DWORD *)(a1 + 2160) = 0;
  }
  else
  {
    result = a1;
    dword_8B8E20 = a1;
    *(_DWORD *)(a1 + 2156) = 0;
    *(_DWORD *)(a1 + 2160) = 0;
  }
  return result;
}

