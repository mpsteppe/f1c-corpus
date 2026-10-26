void __thiscall sub_40DEA0(float *this)
{
  double v2; // st7
  double v3; // st7
  int v4; // [esp-4h] [ebp-20h]
  float v5; // [esp+14h] [ebp-8h]
  float v6; // [esp+18h] [ebp-4h]

  if ( byte_B7117C == 1 )
    *this = this[1];
  v5 = this[4] * *this * flt_75770C;
  v6 = this[4] - v5;
  if ( *this == 0.0 )
  {
    if ( *((_BYTE *)this + 21) )
    {
      sub_562DD0(1);
      *((_BYTE *)this + 21) = 0;
    }
  }
  else
  {
    if ( dword_FAE990 && !byte_B7117C )
    {
      sub_562DD0(0);
      *((_BYTE *)this + 21) = 1;
    }
    if ( byte_B7117C == 1 )
    {
      (*(void (__fastcall **)(int, _DWORD, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 308))(
        dword_FB27A4,
        (unsigned __int64)this[3] >> 32,
        dword_FB2790,
        0,
        0,
        (unsigned __int64)this[3],
        (unsigned __int64)v5,
        0);
      (*(void (__thiscall **)(int, void *, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int))(*(_DWORD *)dword_FB27A4 + 308))(
        dword_FB27A4,
        dword_FB2790,
        0,
        (unsigned __int64)v6,
        (unsigned __int64)this[3],
        (unsigned __int64)(this[4] - v6 + 1.0),
        0x80000000);
      v4 = (unsigned __int64)(this[4] - flt_75770C * this[4]);
      (*(void (__fastcall **)(int, _DWORD, void *, _DWORD, int, _DWORD, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 308))(
        dword_FB27A4,
        (unsigned __int64)this[3] >> 32,
        dword_FB2790,
        0,
        v4,
        (unsigned __int64)this[3],
        v4,
        0);
    }
  }
  if ( *this >= (double)this[1] )
  {
    if ( *this > (double)this[1] )
    {
      v3 = *this - dbl_FB1D08 * this[2];
      *this = v3;
      if ( v3 < this[1] )
        *this = this[1];
    }
  }
  else
  {
    v2 = dbl_FB1D08 * this[2] + *this;
    *this = v2;
    if ( v2 > this[1] )
      *this = this[1];
  }
}
