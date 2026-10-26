int __thiscall sub_48CAD0(int *this)
{
  int v1; // edx
  double v2; // st7
  long double v4; // st7
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  char Buffer[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v9; // [esp+49h] [ebp-3h]
  char v10; // [esp+4Bh] [ebp-1h]

  v1 = *this;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v9 = 0;
  v10 = 0;
  v2 = *(float *)(*(int (__thiscall **)(int *))(v1 + 172))(this) * 100.0;
  sprintf(Buffer, "%d%%", (unsigned int)(__int64)v2);
  sub_578600(Buffer);
  flt_76AD70 = fabs(*(float *)&dword_76AFD4);
  sub_466720(&flt_76AD70, flt_76AD78, flt_76AD7C);
  v4 = flt_76AEB4;
  if ( v5 | v6 )
  {
    flt_76AEB4 = -fabs(v4);
    if ( flt_76AEB4 >= (double)flt_76AEBC )
    {
      if ( flt_76AEB4 > (double)*(float *)&dword_76AEC0 )
        LODWORD(flt_76AEB4) = dword_76AEC0;
    }
    else
    {
      flt_76AEB4 = flt_76AEBC;
    }
    flt_76B1CC = -fabs(flt_76B1CC);
    if ( flt_76B1CC < (double)flt_76B1D4 )
    {
      flt_76B1CC = flt_76B1D4;
      return 0;
    }
    if ( flt_76B1CC > (double)*(float *)&dword_76B1D8 )
    {
      LODWORD(flt_76B1CC) = dword_76B1D8;
      return 0;
    }
  }
  else
  {
    flt_76AEB4 = fabs(v4);
    if ( flt_76AEB4 >= (double)flt_76AEBC )
    {
      if ( flt_76AEB4 > (double)*(float *)&dword_76AEC0 )
        LODWORD(flt_76AEB4) = dword_76AEC0;
    }
    else
    {
      flt_76AEB4 = flt_76AEBC;
    }
    flt_76B1CC = fabs(flt_76B1CC);
    if ( flt_76B1CC < (double)flt_76B1D4 )
    {
      flt_76B1CC = flt_76B1D4;
      return 0;
    }
    if ( flt_76B1CC > (double)*(float *)&dword_76B1D8 )
      LODWORD(flt_76B1CC) = dword_76B1D8;
  }
  return 0;
}
