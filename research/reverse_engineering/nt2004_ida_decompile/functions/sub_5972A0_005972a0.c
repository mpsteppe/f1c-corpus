int __thiscall sub_5972A0(_DWORD *this, int a2)
{
  int result; // eax
  int i; // ecx

  result = this[63];
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 632); i; i = *(_DWORD *)(i + 632) )
      result = i;
    *(_DWORD *)(result + 632) = a2;
    *(_DWORD *)(a2 + 628) = result;
    *(_DWORD *)(a2 + 632) = 0;
  }
  else
  {
    result = a2;
    this[63] = a2;
    *(_DWORD *)(a2 + 628) = 0;
    *(_DWORD *)(a2 + 632) = 0;
  }
  return result;
}
