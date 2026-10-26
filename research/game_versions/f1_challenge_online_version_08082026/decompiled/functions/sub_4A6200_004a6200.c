void __thiscall sub_4A6200(float **this, float *a2)
{
  float *v3; // ecx
  float v4; // eax
  double v5; // st7
  float *v6; // eax
  float v7; // [esp+4h] [ebp-18h] BYREF
  float v8; // [esp+8h] [ebp-14h]
  float v9; // [esp+Ch] [ebp-10h]
  _DWORD v10[3]; // [esp+10h] [ebp-Ch] BYREF

  v3 = *this;
  *((_BYTE *)this + 400) = 1;
  v7 = v3[3390];
  v4 = v3[3392];
  v8 = v3[3391];
  v9 = v4;
  if ( v8 * v8 + v4 * v4 + v7 * v7 > 0.040000003 )
    *((_BYTE *)this + 400) = 0;
  sub_4F1B50(1);
  if ( *((_DWORD *)*this + 3250) == 1 )
  {
    sub_4EF930(0);
    *((_BYTE *)this + 400) = sub_42A3D0(*this);
  }
  else if ( dword_7CE048 == 1 )
  {
    *((_BYTE *)this + 400) = 0;
  }
  if ( *((_BYTE *)this + 400) )
  {
    this[104] = a2;
    v5 = sub_4A6340(this);
    v6 = this[2];
    *((float *)this + 105) = v5 + *((float *)this + 104);
    if ( v6 )
    {
      sub_4EFB20(v10, &v7);
      sub_4A3320(this[2], v10, (int)&v7);
    }
    if ( *this == (float *)dword_7C54E8 && !*((_BYTE *)this + 428) && !dword_7CE814 )
    {
      *((_BYTE *)this + 428) = 1;
      if ( byte_5EA3EC )
        sub_40D3C0((int)&dword_5EA510, 10);
      else
        sub_40D3C0((int)&dword_5EA510, 9);
    }
  }
}
