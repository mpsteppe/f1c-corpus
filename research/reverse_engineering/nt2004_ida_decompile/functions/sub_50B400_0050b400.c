void __thiscall sub_50B400(int this)
{
  int v2; // ecx

  if ( *(_DWORD *)(this + 2596) )
    sub_59ECC0(0, 0, 0, 0);
  if ( *(_DWORD *)(this + 2592) )
    sub_59ECC0(0, 0, 0, 0);
  if ( *(float *)(this + 2896) <= 0.2 )
  {
    if ( *(_DWORD *)(this + 2588) )
      sub_59ECC0(0, 0, 0, 0);
  }
  else if ( *(float *)(this + 2896) <= 0.80000001 )
  {
    v2 = *(_DWORD *)(this + 2588);
    goto LABEL_11;
  }
  v2 = *(_DWORD *)(this + 2584);
LABEL_11:
  if ( v2 )
    sub_59ECC0(0, 0, 0, 0);
}
