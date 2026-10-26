void __thiscall sub_50B490(int this)
{
  int v1; // ecx

  if ( *(float *)(this + 2896) > 0.2 )
  {
    if ( *(float *)(this + 2896) <= 0.80000001 )
      v1 = *(_DWORD *)(this + 2592);
    else
      v1 = *(_DWORD *)(this + 2596);
    if ( v1 )
      sub_59ECC0(1, 1, 0, 0);
  }
}
