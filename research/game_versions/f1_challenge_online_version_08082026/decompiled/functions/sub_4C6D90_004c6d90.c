void __thiscall sub_4C6D90(int *this, float a2)
{
  _BYTE v3[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v4[12]; // [esp+18h] [ebp-Ch] BYREF

  sub_4E0800(SLOBYTE(a2));
  sub_4E45B0(this + 3);
  sub_410B60(dword_5EA560, (int)(this + 3));
  if ( LOBYTE(a2) )
    sub_4BB810(this + 4109);
  sub_4D10E0(this, v4, v3);
  sub_4D1100(this, v4, v3);
  sub_4D1140(this, v4, v3);
  if ( LOBYTE(a2) )
  {
    sub_4D1180(this, v4, v3);
    sub_4EF7C0(v4, v3);
  }
  sub_424790(this, a2);
  sub_4C6B60(this, 1);
  this[4653] = -8388609;
  sub_4D1670(&unk_8ACEE0);
  if ( flt_5EA408 <= 0.0 )
    sub_4E4910(this + 3);
}
