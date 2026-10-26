void __thiscall sub_5514C0(float *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  double v5; // st7
  int v6; // ecx

  if ( *((_DWORD *)this + 7) )
  {
    v3 = *((_DWORD *)this + 1);
    if ( (v3 & 0x1000) != 0 )
    {
      v4 = *(_DWORD *)this;
      *((_DWORD *)this + 1) = v3 & 0xFFFF6FFF | 0x8000;
      this[2] = 0.0;
      HighResolutionTimerReset(v4);
    }
    if ( (BYTE1(*((_DWORD *)this + 1)) & 0x80u) != 0 )
    {
      v5 = HighPrecisionTimerCounterArithmetic(*(_DWORD *)this);
      this[4] = v5;
      v6 = *((_DWORD *)this + 7);
      if ( v5 >= *(float *)(v6 + 8) )
      {
        this[4] = *(float *)(v6 + 8);
        if ( ((_DWORD)this[1] & 0x20000) != 0 )
        {
          FlagUpdateWithCascade(this);
          sub_551210(this, a2, this[4]);
          return;
        }
        EntityFlagSetSubInitChain(this);
        AudioFlagSet(this);
      }
      sub_551210(this, a2, this[4]);
    }
  }
}
