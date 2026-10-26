int __thiscall sub_4A5E60(int this)
{
  _DWORD *v1; // ecx
  int result; // eax

  *(_DWORD *)(this + 388) = 4;
  *(_BYTE *)(this + 384) = 1;
  v1 = *(_DWORD **)(this + 20);
  if ( v1 )
    return ShortComputation_3fe0(v1);
  return result;
}
