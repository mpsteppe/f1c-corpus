void __thiscall sub_4497C0(int this, char a2)
{
  bool v2; // c0
  double v3; // st7

  if ( *(double *)(this + 8656) <= 0.5 )
  {
    v2 = *(double *)(this + 8656) < *(double *)(this + 8696);
    *(_BYTE *)(this + 8650) = 1;
    if ( a2 )
    {
      if ( v2 )
        *(double *)(this + 8656) = *(double *)(this + 8696);
    }
    else if ( v2 )
    {
      v3 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
      *(double *)(this + 8840) = v3 * *(double *)(this + 8856) + *(double *)(this + 8864) + *(double *)(this + 8848);
    }
  }
}
