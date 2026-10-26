void __thiscall sub_489EE0(_DWORD *this)
{
  int v1; // eax
  double v2; // st7

  v1 = this[88];
  this[83] = 0;
  if ( v1 )
  {
    v2 = (double)(int)this[85];
    if ( v2 > 0.0 )
      this[83] = CRTFtol(v2);
  }
}

