int __thiscall sub_4D2F20(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  this[15] = a2;
  v2 = *(_DWORD *)(a2 + 24);
  result = *(_DWORD *)(a2 + 20);
  this[1] = result;
  this[2] = v2;
  return result;
}
