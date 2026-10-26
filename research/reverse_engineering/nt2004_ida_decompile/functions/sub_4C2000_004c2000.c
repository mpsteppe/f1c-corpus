char __thiscall sub_4C2000(float **this, float *a2)
{
  float *v3; // ecx
  float v4; // eax
  char result; // al
  double v6; // st7
  double v7; // st7
  double v8; // st7
  float *v9; // ecx
  float v10; // [esp+4h] [ebp-1Ch] BYREF
  float v11; // [esp+8h] [ebp-18h] BYREF
  float v12; // [esp+Ch] [ebp-14h]
  float v13; // [esp+10h] [ebp-10h]
  _BYTE v14[12]; // [esp+14h] [ebp-Ch] BYREF
  float v15; // [esp+24h] [ebp+4h]

  v3 = *this;
  *((_BYTE *)this + 836) = 1;
  v11 = v3[4407];
  v4 = v3[4409];
  v12 = v3[4408];
  v13 = v4;
  if ( v12 * v12 + v4 * v4 + v11 * v11 > 0.040000003 )
    *((_BYTE *)this + 836) = 0;
  sub_51E770(1);
  if ( *((_DWORD *)*this + 4146) != 1 || (unsigned __int8)sub_4EED40(*this) && sub_42DBA0() )
  {
    if ( dword_765E88 == 4 )
      dword_765E88 = -1;
  }
  else
  {
    sub_51BFD0(0);
    sub_4276F0(*this);
  }
  result = *((_BYTE *)this + 836);
  if ( result )
  {
    sub_4C0840(this);
    this[213] = a2;
    v10 = 0.0;
    v15 = sub_4C21B0(&v10);
    v6 = sub_4BF120((float *)dword_766238, (int)this[2]);
    if ( v6 >= v10 )
      v7 = sub_4BF120((float *)dword_766238, (int)this[2]);
    else
      v7 = v10;
    v8 = v7 + v15;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 100.0 )
        v8 = 100.0;
    }
    else
    {
      v8 = 0.0;
    }
    v9 = *this;
    *((float *)this + 214) = v8 + *((float *)this + 213);
    if ( (unsigned __int8)sub_4EED40(v9) && !*((_BYTE *)this + 864) && !*(_DWORD *)dword_76693C )
      *((_BYTE *)this + 864) = 1;
    sub_4F8F10(*this, v14, &v11);
    return sub_51BE20(v14, &v11);
  }
  return result;
}
