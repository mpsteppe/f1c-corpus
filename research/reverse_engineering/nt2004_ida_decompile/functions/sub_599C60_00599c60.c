int __thiscall sub_599C60(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  int i; // edx

  v2 = this[10];
  result = 0;
  if ( v2 )
  {
    result = this[10];
    for ( i = *(_DWORD *)(v2 + 12); i; i = *(_DWORD *)(i + 12) )
      result = i;
    *(_DWORD *)(result + 12) = a2;
    *(_DWORD *)(a2 + 8) = result;
    *(_DWORD *)(a2 + 12) = 0;
    ++this[3];
  }
  else
  {
    this[10] = a2;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 0;
    ++this[3];
  }
  return result;
}
