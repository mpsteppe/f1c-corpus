void __thiscall sub_52E5D0(int this, float a2, int a3)
{
  double v3; // st7

  v3 = *(float *)(a3 + 4);
  if ( v3 > a2 || v3 <= *(float *)(this + 220) )
  {
    if ( v3 > a2 && *(float *)(a3 + 4) < (double)*(float *)(this + 12) )
      sub_4D1850((_DWORD *)(this + 8), (_DWORD *)a3);
  }
  else
  {
    sub_4D1850((_DWORD *)(this + 216), (_DWORD *)a3);
  }
}
