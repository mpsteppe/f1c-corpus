float *__stdcall sub_5D8A70(int a1, float a2, float *a3)
{
  double v3; // st7
  float *result; // eax
  float v5; // [esp+4h] [ebp-18h]
  float v6; // [esp+8h] [ebp-14h] BYREF
  float v7; // [esp+Ch] [ebp-10h] BYREF
  float v8; // [esp+10h] [ebp-Ch] BYREF
  float v9; // [esp+14h] [ebp-8h] BYREF
  float v10; // [esp+18h] [ebp-4h] BYREF

  v5 = 1.0;
  if ( a2 == 0.0 )
  {
    a2 = 0.5;
    v6 = 0.5;
    v7 = 0.5;
    v8 = 1.0;
    v9 = 1.0;
    v10 = 1.0;
  }
  else
  {
    sub_6006C0(1, &a2, &v6, &v7);
    sub_6006C0(2, &v8, &v9, &v10);
  }
  v3 = 1.0;
  if ( a1 )
  {
    sub_5DCE20(&a2, &v6, &v7);
    v3 = *(float *)(a1 + 268);
    v5 = *(float *)(a1 + 264);
  }
  result = a3;
  a2 = 1.0 - (v8 - a2 * v3) * v5;
  *a3 = a2;
  result[1] = 1.0 - (v9 - v6 * v3) * v5;
  result[2] = 1.0 - (v10 - v3 * v7) * v5;
  result[3] = a2 * 0.30000001 + a2 * 0.58999997 + a2 * 0.11;
  return result;
}
