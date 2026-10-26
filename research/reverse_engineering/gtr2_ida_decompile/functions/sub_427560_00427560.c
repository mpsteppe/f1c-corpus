void __thiscall sub_427560(int this)
{
  unsigned __int64 v1; // rax
  double v2; // st7

  if ( dword_B72E08 )
  {
    v1 = (unsigned __int64)(*(float *)(this + 17196) * *(float *)(this + 15568) - 0.2);
    if ( (int)v1 < 2 && !*(_DWORD *)(this + 20852) && dword_B64134 == 5 )
    {
      if ( (int)v1 < 1 || (v2 = flt_BE08A4[(unsigned __int8)dword_BE08A0], ++dword_BE08A0, v2 < 0.050000001) )
        sub_421A90((_DWORD *)this);
    }
  }
}
