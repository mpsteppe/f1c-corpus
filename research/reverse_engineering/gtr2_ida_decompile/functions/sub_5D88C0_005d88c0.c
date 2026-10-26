float *__stdcall sub_5D88C0(float a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  double v4; // st7
  float *result; // eax
  double v6; // st6
  float v7; // [esp+4h] [ebp-18h]
  float v8; // [esp+8h] [ebp-14h] BYREF
  float v9; // [esp+Ch] [ebp-10h] BYREF
  float v10; // [esp+10h] [ebp-Ch] BYREF
  float v11; // [esp+14h] [ebp-8h] BYREF
  float v12; // [esp+18h] [ebp-4h] BYREF

  v7 = 1.0;
  if ( a1 == 0.0 )
  {
    v10 = 1.0;
    v11 = 1.0;
    v12 = 1.0;
  }
  else
  {
    v7 = sub_600770(2);
    sub_6006C0(2, &v10, &v11, &v12);
  }
  v3 = a2;
  if ( a2 )
  {
    sub_5E86C0(2, &a1, &v8, &v9);
    if ( ((unsigned int)&dword_1000000 & *v3) != 0 )
    {
      a1 = a1 * v7;
      v8 = v8 * v7;
      v4 = v9 * v7;
    }
    else
    {
      v4 = v9;
    }
  }
  else
  {
    v4 = 0.0;
    a1 = 0.0;
    v8 = 0.0;
  }
  result = (float *)a3;
  v6 = a1 * v10;
  *(_DWORD *)(a3 + 12) = 0;
  *result = v6 * v7;
  result[1] = v8 * v11 * v7;
  result[2] = v4 * v12 * v7;
  return result;
}
