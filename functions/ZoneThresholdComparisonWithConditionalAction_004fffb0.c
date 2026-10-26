void __thiscall sub_4FFFB0(int this, float a2, int a3)
{
  double v3; // st7

  v3 = *(float *)(a3 + 4);
  if ( v3 > a2 || v3 <= *(float *)(this + 444) )
  {
    if ( v3 > a2 && *(float *)(a3 + 4) < (double)*(float *)(this + 12) )
      ArithmeticComparison_3a90((_DWORD *)(this + 8), (_DWORD *)a3);
  }
  else
  {
    ArithmeticComparison_3a90((_DWORD *)(this + 440), (_DWORD *)a3);
  }
}
