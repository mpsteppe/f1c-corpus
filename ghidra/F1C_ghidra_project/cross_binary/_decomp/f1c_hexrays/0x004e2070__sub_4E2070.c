// f1c  0x004e2070  size=185
int __thiscall sub_4E2070(float *this, float *a2, int a3)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  _BYTE v8[36]; // [esp+8h] [ebp-24h] BYREF

  v4 = this[573] + this[576];
  v5 = this[574] + this[577];
  v6 = this[575] + this[578];
  *a2 = v6 * this[10] + v5 * this[9] + v4 * this[8];
  a2[1] = v6 * this[13] + v5 * this[12] + v4 * this[11];
  a2[2] = v6 * this[16] + v5 * this[15] + v4 * this[14];
  *a2 = this[2] + *a2;
  a2[1] = this[3] + a2[1];
  a2[2] = this[4] + a2[2];
  qmemcpy(v8, this + 8, sizeof(v8));
  return sub_567120(this + 579, a3);
}
