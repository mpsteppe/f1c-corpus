int __thiscall sub_50C6A0(float *this, float *a2, int a3)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  _BYTE v8[36]; // [esp+8h] [ebp-24h] BYREF

  v4 = this[683] + this[686];
  v5 = this[684] + this[687];
  v6 = this[685] + this[688];
  *a2 = v6 * this[10] + v5 * this[9] + v4 * this[8];
  a2[1] = v6 * this[13] + v5 * this[12] + v4 * this[11];
  a2[2] = v6 * this[16] + v5 * this[15] + v4 * this[14];
  *a2 = this[2] + *a2;
  a2[1] = this[3] + a2[1];
  a2[2] = this[4] + a2[2];
  qmemcpy(v8, this + 8, sizeof(v8));
  return sub_579930(this + 689, a3);
}
