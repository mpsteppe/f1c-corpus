float *__stdcall sub_5D89B0(float a1, _DWORD *a2, float *a3)
{
  _DWORD *v3; // edi
  float *result; // eax
  float v5; // [esp+8h] [ebp-18h] BYREF
  float v6; // [esp+Ch] [ebp-14h] BYREF
  float v7; // [esp+10h] [ebp-10h]
  float v8; // [esp+14h] [ebp-Ch] BYREF
  float v9; // [esp+18h] [ebp-8h] BYREF
  float v10; // [esp+1Ch] [ebp-4h] BYREF

  v7 = sub_600770(2);
  v3 = a2;
  if ( a2 )
  {
    sub_5E86C0(3, &a1, &v5, &v6);
    if ( (*v3 & 0x8000000) != 0 )
    {
      a1 = a1 * v7;
      v5 = v5 * v7;
      v6 = v6 * v7;
    }
  }
  else
  {
    a1 = 0.0;
    v5 = 0.0;
    v6 = 0.0;
  }
  sub_6006C0(2, &v8, &v9, &v10);
  result = a3;
  *a3 = v8 * a1;
  result[1] = v9 * v5;
  result[2] = v10 * v6;
  return result;
}
