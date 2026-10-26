int __thiscall sub_54A270(_DWORD *this, int a2)
{
  int result; // eax
  int i; // ecx

  result = this[64];
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 260); i; i = *(_DWORD *)(i + 260) )
      result = i;
    *(_DWORD *)(result + 260) = a2;
    *(_DWORD *)(a2 + 256) = result;
    *(_DWORD *)(a2 + 260) = 0;
  }
  else
  {
    result = a2;
    this[64] = a2;
    *(_DWORD *)(a2 + 256) = 0;
    *(_DWORD *)(a2 + 260) = 0;
  }
  return result;
}

