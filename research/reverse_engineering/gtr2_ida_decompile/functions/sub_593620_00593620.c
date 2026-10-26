float *__stdcall sub_593620(float *a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8)
{
  float *result; // eax
  float v9; // [esp+0h] [ebp-Ch]
  float v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-Ch]
  float v12; // [esp+4h] [ebp-8h]
  float v13; // [esp+4h] [ebp-8h]
  float v14; // [esp+4h] [ebp-8h]
  float v15; // [esp+8h] [ebp-4h]
  float v16; // [esp+8h] [ebp-4h]
  float v17; // [esp+8h] [ebp-4h]

  v9 = a2 - a5;
  v12 = a3 - a6;
  v15 = a4 - a7;
  v10 = v9 * a8;
  result = a1;
  v13 = v12 * a8;
  v16 = v15 * a8;
  v11 = v10 + a5;
  *a1 = v11;
  v14 = v13 + a6;
  a1[1] = v14;
  v17 = v16 + a7;
  a1[2] = v17;
  return result;
}
