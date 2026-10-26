int __thiscall sub_6B37C1(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // edx
  int v6; // ecx

  result = sub_6C5921(2);
  if ( result >= 0 )
  {
    v5 = this[67];
    v6 = this[68];
    *(_DWORD *)(v5 + 4 * v6) = a2;
    *(_DWORD *)(v5 + 4 * v6 + 4) = a3;
    this[68] += 2;
    return 0;
  }
  return result;
}
