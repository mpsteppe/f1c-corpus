int __thiscall sub_4FB260(float *this, float a2)
{
  float *v2; // ecx
  double v3; // st7
  double v4; // st7
  int result; // eax
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+8h] [ebp-10h]
  float v9; // [esp+10h] [ebp-8h]
  float v10; // [esp+14h] [ebp-4h]

  v2 = this + 37;
  v3 = (1.0 - a2) * *(v2 - 30) + a2 * *(v2 - 31);
  v2[3] = v3;
  v9 = v3 * *(v2 - 28);
  v10 = v3 * *(v2 - 27);
  v6 = v3 * *(v2 - 29) + *(v2 - 37);
  v7 = v9 + *(v2 - 36);
  v4 = v10 + *(v2 - 35);
  *v2 = v6;
  v2[1] = v7;
  v8 = v4;
  result = LODWORD(v8);
  v2[2] = v8;
  return result;
}
