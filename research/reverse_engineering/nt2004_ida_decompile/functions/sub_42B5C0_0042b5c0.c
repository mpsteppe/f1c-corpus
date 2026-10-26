void __thiscall sub_42B5C0(int this)
{
  double v2; // st7

  if ( *(float *)(this + 64) < (double)*(float *)(this + 23852) )
  {
    *(_DWORD *)(this + 64) = 2139095039;
    if ( dword_75CBB4 == 8 )
      sub_4271B0(this, 0);
    else
      sub_4272D0(this);
  }
  v2 = *(float *)(this + 23856) + *(float *)(this + 12);
  if ( v2 > 1.0 )
    v2 = 1.0;
  *(float *)(this + 12) = v2;
  if ( *(float *)(this + 23852) > (double)*(float *)(this + 23616) )
  {
    if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 20892) == 2 && *(float *)(this + 23764) < 1.0 )
      *(_DWORD *)(this + 24024) = 3;
    *(float *)(this + 23616) = flt_5FD200 + *(float *)(this + 23852);
    sub_426770(this);
    if ( dword_75CBB0 == 7 )
      sub_42CFB0(this);
  }
}
