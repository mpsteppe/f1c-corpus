int __thiscall sub_567300(float *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // eax

  v2 = *((_DWORD *)this + 4);
  if ( !v2 )
  {
    *((_DWORD *)this + 4) = 2;
    v6 = sub_5511F0(dword_FADD40, 0);
    if ( v6 >= 0 && v6 < dword_757C10 && !dword_925054[5654 * v6] )
    {
      *((_DWORD *)this + 4) = 1;
      this[6] = 2.0;
    }
    return 0;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    if ( this[6] <= 0.0 )
    {
      result = 0;
      *((_DWORD *)this + 4) = 2;
      return result;
    }
    return 0;
  }
  if ( v3 != 1 )
    return 0;
  if ( !*((_DWORD *)this + 9) )
    *((_DWORD *)this + 9) = dword_924FF4[5654 * sub_5511F0(dword_FADD40, 0)];
  if ( sub_565F40((int)this) )
    this[7] = 2.0;
  *((_DWORD *)this + 8) = sub_565F00();
  if ( !sub_565FD0((int)this) )
    return 0;
  if ( dword_B6FA78 || dword_925054[5654 * sub_5511F0(dword_FADD40, 0)] != 1 || !*(_DWORD *)(dword_91E084 + 19380) )
    return 1;
  sub_53E6A0((void *)dword_91E084, 1);
  sub_412EB0(&dword_91BF20, 5, 1);
  v4 = sub_5511F0(off_16C9A10, 0);
  sub_414450(&dword_91BF20, v4);
  sub_562430();
  return 0;
}
