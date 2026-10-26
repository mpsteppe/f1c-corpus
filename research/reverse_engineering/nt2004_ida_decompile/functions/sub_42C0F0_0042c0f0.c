int __thiscall sub_42C0F0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = this[6005];
  this[6178] = 0;
  this[5926] = 0;
  result = a2;
  if ( v2 != a2 )
    this[6005] = a2;
  return result;
}
