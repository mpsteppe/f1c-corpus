// f1c  0x0050b27c  size=257
int __thiscall sub_50B27C(int this)
{
  int v1; // eax
  double v2; // st7
  int result; // eax
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]

  v1 = *(_DWORD *)(this + 4);
  if ( v1 == 844388420 || v1 == 861165636 )
    v2 = 15.0;
  else
    v2 = 255.0;
  *(float *)(this + 4204) = v2;
  *(float *)(this + 4208) = 1.0 / *(float *)(this + 4204);
  v7 = *(float *)(this + 28) * 31.0 + 0.5;
  *(float *)(this + 28) = (double)(int)v7 * 0.032258064;
  v4 = *(float *)(this + 32) * 63.0 + 0.5;
  *(float *)(this + 32) = (double)(int)v4 * 0.015873017;
  v5 = *(float *)(this + 36) * 31.0 + 0.5;
  *(float *)(this + 36) = (double)(int)v5 * 0.032258064;
  v6 = *(float *)(this + 4204) * *(float *)(this + 40) + 0.5;
  result = this;
  *(float *)(this + 40) = (double)(int)v6 * *(float *)(this + 4208);
  return result;
}
