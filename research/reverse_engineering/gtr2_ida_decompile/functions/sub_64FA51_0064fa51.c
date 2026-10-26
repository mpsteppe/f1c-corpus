int __thiscall sub_64FA51(int this)
{
  int v1; // eax
  double v2; // st7
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+0h] [ebp-8h]
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]

  v1 = *(_DWORD *)(this + 4);
  if ( v1 == 844388420 || v1 == 861165636 )
    v2 = 15.0;
  else
    v2 = 255.0;
  *(float *)(this + 128) = v2;
  *(float *)(this + 132) = 1.0 / v2;
  v7 = *(float *)(this + 36) * 31.0 + 0.5;
  *(float *)(this + 36) = (double)(int)v7 * 0.032258064;
  v4 = *(float *)(this + 40) * 63.0 + 0.5;
  *(float *)(this + 40) = (double)(int)v4 * 0.015873017;
  v5 = *(float *)(this + 44) * 31.0 + 0.5;
  *(float *)(this + 44) = (double)(int)v5 * 0.032258064;
  v6 = *(float *)(this + 128) * *(float *)(this + 48) + 0.5;
  result = (int)v6;
  *(float *)(this + 48) = (double)result * *(float *)(this + 132);
  return result;
}
