int __thiscall sub_577780(float *this, float *a2, _DWORD *a3)
{
  float *v3; // esi
  double v4; // st7
  double v5; // st6
  int result; // eax
  float v7[3]; // [esp+4h] [ebp-Ch] BYREF

  v3 = this;
  v4 = this[4104] - this[4136];
  v5 = this[4041] - this[4073];
  v7[2] = this[699];
  v7[1] = (v4 + v5) * 0.5;
  v7[0] = 0.0;
  sub_416420(this + 3984, this + 3993, v7, a2);
  v3 += 3996;
  *a3 = *(_DWORD *)v3;
  result = *((_DWORD *)v3 + 1);
  a3[1] = result;
  a3[2] = *((_DWORD *)v3 + 2);
  return result;
}
