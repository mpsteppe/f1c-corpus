void __thiscall sub_458C90(float *this, float a2, float a3)
{
  int v4; // eax
  double v5; // st6
  float v6; // [esp+4h] [ebp-18h]
  float v7; // [esp+8h] [ebp-14h]
  float v8; // [esp+10h] [ebp-Ch]
  float v9; // [esp+14h] [ebp-8h]

  if ( a2 > 0.0 )
  {
    v6 = (float)(sub_4586B0() % 2 != 0 ? -1 : 1);
    v7 = (float)(sub_4586B0() % 2 != 0 ? -1 : 1);
    v4 = sub_4586B0() % 2;
    v5 = a2 * a3 * 0.34999999;
    if ( v5 > 0.34999999 )
      v5 = 0.34999999;
    v8 = v6 * v5;
    v9 = v7 * v5;
    this[40] = v8 + this[40];
    this[41] = v9 + this[41];
    this[42] = (double)(v4 != 0 ? -1 : 1) * v5 + this[42];
  }
}
