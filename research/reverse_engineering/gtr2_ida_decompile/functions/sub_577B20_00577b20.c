char __thiscall sub_577B20(int this)
{
  float *v1; // edx
  double v2; // st7
  double v3; // st7
  char result; // al
  float v5; // [esp+4h] [ebp-18h]
  float v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+Ch] [ebp-10h]

  v1 = *(float **)(this + 17476);
  if ( !v1 )
    return 0;
  v5 = *(float *)(this + 15972) - v1[1];
  v6 = *(float *)(this + 15976) - v1[2];
  v7 = *(float *)(this + 15980) - v1[3];
  v2 = v7 * v1[11] + v6 * v1[10] + v5 * v1[9];
  v3 = v2 >= 0.0 ? v2 - v1[13] : -v2 - v1[12];
  result = 1;
  if ( v3 <= 2.0 )
    return 0;
  return result;
}
