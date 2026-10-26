int __thiscall sub_593580(int this, float a2, float a3, float a4)
{
  long double v5; // st7
  long double v6; // st6
  int result; // eax
  long double v8; // st5
  long double v9; // st4
  long double v10; // rt0
  long double v11; // st3
  double v12; // st7
  double v13; // st6
  float v14; // [esp+0h] [ebp-Ch]
  float v15; // [esp+4h] [ebp-8h]
  float v16; // [esp+8h] [ebp-4h]
  float v17; // [esp+10h] [ebp+4h]
  float v18; // [esp+10h] [ebp+4h]
  float v19; // [esp+10h] [ebp+4h]
  float v20; // [esp+14h] [ebp+8h]
  float v21; // [esp+14h] [ebp+8h]
  float v22; // [esp+18h] [ebp+Ch]

  v17 = fmod(a2, 6.283185482025146);
  v20 = fmod(a3, 6.283185482025146);
  v5 = fmod(a4, 6.283185482025146);
  *(float *)(this + 56) = v5;
  v6 = sin(v17);
  *(float *)(this + 48) = v17;
  *(float *)(this + 52) = v20;
  result = 0;
  *(_DWORD *)(this + 360) = 0;
  v8 = cos(v17);
  v9 = sin(v20);
  v21 = cos(v20);
  v10 = sin(v5);
  v11 = cos(v5);
  v18 = v11;
  v15 = v11 * v21;
  v22 = v21 * v10;
  v14 = v18 * v9;
  v16 = v10 * v9;
  *(float *)(this + 348) = v15 - v10 * v9 * v6;
  *(float *)(this + 356) = -(v9 * v8);
  *(float *)(this + 352) = v14 * v6 + v22;
  *(_DWORD *)(this + 376) = 0;
  *(float *)(this + 364) = -(v10 * v8);
  *(float *)(this + 372) = v6;
  *(float *)(this + 368) = v18 * v8;
  *(_DWORD *)(this + 392) = 0;
  v19 = v22 * v6 + v14;
  *(float *)(this + 380) = v19;
  *(float *)(this + 388) = v21 * v8;
  *(float *)(this + 384) = v16 - v15 * v6;
  *(float *)(this + 396) = *(float *)(this + 348) * *(float *)(this + 36)
                         + v19 * *(float *)(this + 44)
                         + *(float *)(this + 40) * *(float *)(this + 364);
  *(float *)(this + 400) = *(float *)(this + 44) * *(float *)(this + 384)
                         + *(float *)(this + 40) * *(float *)(this + 368)
                         + *(float *)(this + 36) * *(float *)(this + 352);
  v12 = *(float *)(this + 372) * *(float *)(this + 40) + *(float *)(this + 44) * *(float *)(this + 388);
  v13 = *(float *)(this + 36) * *(float *)(this + 356);
  *(_DWORD *)(this + 408) = 1065353216;
  *(float *)(this + 404) = v12 + v13;
  return result;
}
