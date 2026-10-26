int __thiscall sub_53B240(int this, float a2, float a3, float a4)
{
  int result; // eax
  long double v6; // st6
  long double v7; // st5
  long double v8; // rt0
  long double v9; // st4
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+Ch] [ebp+8h]
  float v13; // [esp+10h] [ebp+Ch]

  InterruptDispatch(a2);
  *(float *)(this + 16) = a2;
  InterruptDispatch(a3);
  *(float *)(this + 20) = a3;
  InterruptDispatch(a4);
  *(float *)(this + 24) = a4;
  result = 0;
  v6 = sin(a2);
  *(_DWORD *)(this + 52) = 0;
  v11 = cos(a2);
  v7 = sin(a3);
  v12 = cos(a3);
  v8 = sin(a4);
  v9 = cos(a4);
  v10 = v9 * v12;
  v13 = v8 * v12;
  *(float *)(this + 40) = v7 * v6 * v8 + v10;
  *(float *)(this + 44) = v8 * v11;
  *(float *)(this + 48) = v13 * v6 - v9 * v7;
  *(_DWORD *)(this + 68) = 0;
  *(float *)(this + 56) = v7 * v6 * v9 - v13;
  *(float *)(this + 60) = v9 * v11;
  *(float *)(this + 64) = v10 * v6 + v8 * v7;
  *(_DWORD *)(this + 84) = 0;
  *(float *)(this + 72) = v7 * v11;
  *(float *)(this + 76) = -v6;
  *(float *)(this + 80) = v12 * v11;
  return result;
}

