int __thiscall sub_4D1D40(int this, float a2)
{
  int v3; // eax
  int v4; // ecx

  v3 = CRTFtol(a2 * *(float *)(this + 264));
  v4 = *(_DWORD *)(this + 268) - 1;
  if ( v3 < 0 )
  {
    v3 = 0;
    return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v3);
  }
  if ( v3 <= v4 )
    return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v3);
  return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v4);
}
