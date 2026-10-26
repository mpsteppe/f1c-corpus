void __thiscall sub_56ED00(float *this, float *a2, int a3, float *a4)
{
  const void *v5; // esi
  float v6[3]; // [esp+Ch] [ebp-30h] BYREF
  float v7[9]; // [esp+18h] [ebp-24h] BYREF

  v5 = this + 9;
  v6[0] = this[711] + this[708] + *a4;
  v6[1] = this[712] + this[709] + a4[1] + flt_B70EF4;
  v6[2] = this[713] + this[710] + a4[2] + flt_B70ED0;
  sub_416420(this + 9, this + 3, v6, a2);
  qmemcpy(v7, v5, sizeof(v7));
  sub_614F40(this + 714);
  sub_40D5D0(v7, a3);
}
