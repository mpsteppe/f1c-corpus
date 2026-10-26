int __thiscall sub_54ABE0(_DWORD *this, int a2)
{
  int result; // eax
  int i; // ecx

  result = this[129];
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 16); i; i = *(_DWORD *)(i + 16) )
      result = i;
    *(_DWORD *)(result + 16) = a2;
    *(_DWORD *)(a2 + 320) = result;
    *(_DWORD *)(a2 + 16) = 0;
  }
  else
  {
    result = a2;
    this[129] = a2;
    *(_DWORD *)(a2 + 320) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  return result;
}
