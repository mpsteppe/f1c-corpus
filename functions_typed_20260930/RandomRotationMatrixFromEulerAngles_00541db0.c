int __thiscall sub_541DB0(int this, float a2, float a3, float a4)
{
  long double v5; // st6
  int result; // eax
  long double v7; // st5
  long double v8; // st4
  long double v9; // rt0
  long double v10; // st3
  double v11; // st7
  double v12; // st6
  float v13; // [esp+0h] [ebp-Ch]
  float v14; // [esp+4h] [ebp-8h]
  float v15; // [esp+8h] [ebp-4h]
  float v16; // [esp+10h] [ebp+4h]
  float v17; // [esp+10h] [ebp+4h]
  float v18; // [esp+14h] [ebp+8h]
  float v19; // [esp+18h] [ebp+Ch]

  InterruptDispatch(a2);
  InterruptDispatch(a3);
  InterruptDispatch(a4);
  *(float *)(this + 56) = a4;
  v5 = sin(a2);
  *(float *)(this + 48) = a2;
  *(float *)(this + 52) = a3;
  result = 0;
  *(_DWORD *)(this + 360) = 0;
  v7 = cos(a2);
  v8 = sin(a3);
  v18 = cos(a3);
  v9 = sin(a4);
  v10 = cos(a4);
  v16 = v10;
  v14 = v10 * v18;
  v19 = v18 * v9;
  v13 = v16 * v8;
  v15 = v9 * v8;
  *(float *)(this + 348) = v14 - v9 * v8 * v5;
  *(float *)(this + 356) = -(v8 * v7);
  *(float *)(this + 352) = v13 * v5 + v19;
  *(_DWORD *)(this + 376) = 0;
  *(float *)(this + 364) = -(v9 * v7);
  *(float *)(this + 372) = v5;
  *(float *)(this + 368) = v16 * v7;
  *(_DWORD *)(this + 392) = 0;
  v17 = v19 * v5 + v13;
  *(float *)(this + 380) = v17;
  *(float *)(this + 388) = v18 * v7;
  *(float *)(this + 384) = v15 - v14 * v5;
  *(float *)(this + 396) = *(float *)(this + 348) * *(float *)(this + 36)
                         + v17 * *(float *)(this + 44)
                         + *(float *)(this + 40) * *(float *)(this + 364);
  *(float *)(this + 400) = *(float *)(this + 44) * *(float *)(this + 384)
                         + *(float *)(this + 40) * *(float *)(this + 368)
                         + *(float *)(this + 36) * *(float *)(this + 352);
  v11 = *(float *)(this + 372) * *(float *)(this + 40) + *(float *)(this + 44) * *(float *)(this + 388);
  v12 = *(float *)(this + 36) * *(float *)(this + 356);
  *(_DWORD *)(this + 408) = 1065353216;
  *(float *)(this + 404) = v11 + v12;
  return result;
}

