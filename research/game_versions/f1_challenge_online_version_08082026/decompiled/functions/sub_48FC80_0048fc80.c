int __thiscall sub_48FC80(_DWORD *this, int a2)
{
  int result; // eax

  this[14] = a2;
  this[3] = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 28);
  result = *(_DWORD *)(a2 + 12);
  this[4] = *(_DWORD *)(result + 32);
  return result;
}
