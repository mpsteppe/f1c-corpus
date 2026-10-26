void __thiscall sub_50CCE0(float *this, int a2, float *a3, const void *a4, const void *a5)
{
  float *v5; // ebx
  double v6; // st7
  float *v7; // esi
  long double v8; // st7
  long double v9; // st6
  long double v10; // st7
  float v11; // [esp+10h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-8h]
  float v13; // [esp+18h] [ebp-4h]

  v5 = &this[76 * a2 + 55];
  v11 = *a3 - this[18];
  v12 = a3[1] - this[19];
  v6 = a3[2] - this[20];
  v7 = &this[76 * a2 + 86];
  *v7 = v11;
  v13 = v6;
  v7[1] = v12;
  v7[2] = v13;
  v5[48] = v11;
  v5[49] = v12;
  v5[50] = v13;
  qmemcpy(&this[76 * a2 + 92], a4, 0x24u);
  v5[34] = -asin(this[76 * a2 + 97]);
  if ( fabs(this[76 * a2 + 97]) == 1.0 )
  {
    v8 = -this[76 * a2 + 98];
    v9 = this[76 * a2 + 92];
    this[76 * a2 + 91] = 0.0;
    this[76 * a2 + 90] = atan2(v8, v9);
  }
  else
  {
    this[76 * a2 + 90] = atan2(this[76 * a2 + 94], this[76 * a2 + 100]);
    this[76 * a2 + 91] = atan2(this[76 * a2 + 95], this[76 * a2 + 96]);
  }
  qmemcpy(&this[76 * a2 + 109], a5, 0x24u);
  this[76 * a2 + 106] = -asin(this[76 * a2 + 114]);
  if ( fabs(this[76 * a2 + 114]) == 1.0 )
  {
    v10 = atan2(-this[76 * a2 + 115], this[76 * a2 + 109]);
    this[76 * a2 + 108] = 0.0;
    this[76 * a2 + 107] = v10;
  }
  else
  {
    this[76 * a2 + 107] = atan2(this[76 * a2 + 111], this[76 * a2 + 117]);
    this[76 * a2 + 108] = atan2(this[76 * a2 + 112], this[76 * a2 + 113]);
  }
}
