void __thiscall sub_4A55A0(_DWORD *this, float a2, float a3)
{
  float *v4; // ecx
  float *v5; // ecx
  int v6; // ecx

  v4 = (float *)this[4];
  if ( v4 )
    sub_4A3570(v4, a3);
  v5 = (float *)this[3];
  if ( v5 )
    sub_4A3570(v5, a3);
  v6 = this[5];
  if ( v6 )
    AccumulatorWithStateSwitch(v6, a2);
}

