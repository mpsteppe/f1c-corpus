int __thiscall sub_4A5E80(int this)
{
  int result; // eax
  _DWORD *v2; // ecx

  result = 0;
  *(_DWORD *)(this + 388) = 0;
  *(_BYTE *)(this + 384) = 0;
  v2 = *(_DWORD **)(this + 20);
  if ( v2 )
    return ShortComputation_3fe0(v2);
  return result;
}
