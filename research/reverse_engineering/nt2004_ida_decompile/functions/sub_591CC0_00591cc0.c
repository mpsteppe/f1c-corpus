int __stdcall sub_591CC0(int a1)
{
  int result; // eax
  int i; // ecx

  result = dword_7E8E5C;
  if ( dword_7E8E5C )
  {
    for ( i = *(_DWORD *)(dword_7E8E5C + 504); i; i = *(_DWORD *)(i + 504) )
      result = i;
    *(_DWORD *)(result + 504) = a1;
    *(_DWORD *)(a1 + 500) = result;
    *(_DWORD *)(a1 + 504) = 0;
  }
  else
  {
    result = a1;
    dword_7E8E5C = a1;
    *(_DWORD *)(a1 + 500) = 0;
    *(_DWORD *)(a1 + 504) = 0;
  }
  return result;
}
