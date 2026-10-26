void __thiscall sub_51C0E0(int this, char a2)
{
  int v2; // eax
  double v3; // st7

  v2 = *(_DWORD *)(this + 16500);
  if ( v2 )
  {
    if ( a2 || v2 == 3 )
    {
      if ( *(float *)(this + 18736) < (double)*(float *)(this + 18744) )
        *(_DWORD *)(this + 18736) = *(_DWORD *)(this + 18744);
    }
    else
    {
      v3 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      *(float *)(this + 18772) = v3 * *(float *)(this + 18780) + *(float *)(this + 18784) + *(float *)(this + 18776);
      sub_526050(40, 2, 1.0, 1065353216);
    }
  }
  else
  {
    sub_449840((int)&dbl_75E930, a2);
  }
}
