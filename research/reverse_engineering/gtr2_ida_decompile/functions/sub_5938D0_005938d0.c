void __thiscall sub_5938D0(int this, int a2)
{
  float *v3; // ecx

  if ( (dword_B640C4 & 1) == 0 || dword_BE1204 == 2 && !sub_521050(&dword_BE120C) )
  {
    sub_5928B0((float *)(this + 36), a2);
    if ( fabs(*(float *)(this + 8) - *v3) <= 0.5 )
      *(_DWORD *)(this + 4) = 0x40000000;
    else
      *(_DWORD *)(this + 4) = 0;
    sub_592990((float *)this);
  }
}
