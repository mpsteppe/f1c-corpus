float *__stdcall sub_54AA2B(float *a1, int a2, float a3)
{
  float *result; // eax
  float v5; // [esp+0h] [ebp-14h]
  float v6; // [esp+4h] [ebp-10h]
  float v7; // [esp+8h] [ebp-Ch]
  float *v8; // [esp+10h] [ebp-4h]
  float v9; // [esp+1Ch] [ebp+8h]
  float v10; // [esp+20h] [ebp+Ch]

  sub_5490B9();
  v8 = a1 + 3;
  v9 = a3 * 0.5;
  *v8 = cos(v9);
  v10 = sin(v9);
  result = a1;
  *a1 = v5 * v10;
  a1[1] = v6 * v10;
  a1[2] = v7 * v10;
  return result;
}
