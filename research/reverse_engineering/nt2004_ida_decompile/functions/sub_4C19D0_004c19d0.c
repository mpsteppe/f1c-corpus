char __thiscall sub_4C19D0(_DWORD *this)
{
  char result; // al
  int v3; // ecx
  double v4; // st7
  float *v5; // [esp-4h] [ebp-48h]
  char Buffer[61]; // [esp+4h] [ebp-40h] BYREF
  __int16 v7; // [esp+41h] [ebp-3h]
  char v8; // [esp+43h] [ebp-1h]

  result = *((_BYTE *)this + 824);
  if ( !result )
  {
    v3 = *this;
    this[236] = dword_7D7540;
    if ( (unsigned __int8)sub_4EED40(v3) )
    {
      if ( (unsigned __int8)sub_4DEB10(*this + 20836) )
        sub_4DF490(0.0, 3);
      sub_51F3D0(1, 2);
      sub_51F3D0(0, 4);
      sub_4C0840(this);
      v4 = flt_7D74DC;
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0x3Cu);
      v7 = 0;
      v8 = 0;
      if ( dword_7689F0 )
        sub_405480(Buffer, 0x3Fu, "Pit Lane Speed Limit: %d MPH", (unsigned int)(__int64)(v4 * 2.236936292054402 + 0.5));
      else
        sub_405480(Buffer, 0x3Fu, "Pit Lane Speed Limit: %d KPH", (unsigned int)(__int64)(v4 * 3.6 + 0.5));
      sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
      if ( *(int *)(dword_75AACC + 20900) > 0 && dword_7D7540 > 0 )
        sub_45D100(&byte_764D68, (int)aCannotServeSto, 3, 16909060, 0);
    }
    sub_4C1970(this, 0);
    sub_514F70(*this + 84);
    sub_4C1790((float *)this, 2);
    v5 = (float *)*this;
    *((_BYTE *)this + 824) = 1;
    sub_41B220(v5);
    sub_4F81A0(*this);
    sub_4DE950(*this + 20836);
    sub_4DCE30(*this + 20836);
    result = dword_7D74FC - 2;
    if ( dword_7D74FC == 2 && dword_767310 == 2 )
    {
      if ( dword_75CBB0 == 7 )
        return sub_4DCCC0(aEnteringPitsUn);
      else
        return sub_4DC460(aEnteringPitsUn, 1000.0);
    }
  }
  return result;
}
