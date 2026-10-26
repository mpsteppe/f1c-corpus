void __thiscall sub_52C320(int this, int a2)
{
  float *v3; // ecx

  if ( (dword_75CBAC & 1) == 0 || dword_7D5DA4 == 2 && !sub_4D9AE0(&dword_7D5DAC) )
  {
    sub_52AB90((float *)(this + 28), a2);
    if ( fabs(*(float *)(this + 8) - *v3) <= 0.5 )
      *(_DWORD *)(this + 4) = 0x40000000;
    else
      *(_DWORD *)(this + 4) = 0;
    sub_52B7E0((float *)this);
  }
}
