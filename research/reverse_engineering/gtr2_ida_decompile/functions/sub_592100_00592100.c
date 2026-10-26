int __thiscall sub_592100(float *this, float a2)
{
  float *v2; // ecx
  double v3; // st7
  int result; // eax
  double v5; // st7
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+0h] [ebp-18h]
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+4h] [ebp-14h]
  float v10; // [esp+8h] [ebp-10h]
  float v11; // [esp+8h] [ebp-10h]

  v2 = this + 38;
  v3 = (1.0 - a2) * *(v2 - 30) + a2 * *(v2 - 31);
  v2[3] = v3;
  v6 = v3 * *(v2 - 29);
  v8 = v3 * *(v2 - 28);
  v10 = v3 * *(v2 - 27);
  v7 = v6 + *(v2 - 37);
  v9 = v8 + *(v2 - 36);
  result = LODWORD(v9);
  v5 = v10 + *(v2 - 35);
  *v2 = v7;
  v2[1] = v9;
  v11 = v5;
  v2[2] = v11;
  return result;
}
