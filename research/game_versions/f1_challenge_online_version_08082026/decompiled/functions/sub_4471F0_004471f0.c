void __thiscall sub_4471F0(int this, char a2)
{
  bool v2; // c0
  int v3; // edx
  double v4; // st7

  v2 = *(double *)(this + 7260) < *(double *)(this + 7300);
  *(_BYTE *)(this + 7257) = 1;
  if ( a2 )
  {
    if ( v2 )
    {
      v3 = *(_DWORD *)(this + 7304);
      *(_DWORD *)(this + 7260) = *(_DWORD *)(this + 7300);
      *(_DWORD *)(this + 7264) = v3;
    }
  }
  else if ( v2 )
  {
    v4 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
    *(double *)(this + 7440) = v4 * *(double *)(this + 7456) + *(double *)(this + 7464) + *(double *)(this + 7448);
  }
}
