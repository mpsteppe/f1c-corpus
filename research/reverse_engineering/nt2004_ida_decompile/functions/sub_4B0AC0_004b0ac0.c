int __thiscall sub_4B0AC0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = a2;
  v3 = 0;
  this[7] = a2;
  *this = 0;
  this[2] = 0;
  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 24);
    result = *(_DWORD *)(a2 + 20);
    this[1] = result;
  }
  else
  {
    this[1] = 0;
  }
  this[3] = v3;
  return result;
}
