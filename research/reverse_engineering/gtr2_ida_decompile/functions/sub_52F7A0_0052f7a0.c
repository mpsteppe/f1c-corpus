int __thiscall sub_52F7A0(_DWORD *this, int a2, int a3, float *a4, float a5)
{
  int result; // eax
  int i; // edi
  int v8; // ecx
  double v9; // st7
  int v10; // eax
  float v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+18h] [ebp-8h]
  float v13; // [esp+1Ch] [ebp-4h]

  result = this[7];
  for ( i = 0; i < result; ++i )
  {
    v8 = *(_DWORD *)(this[8] + 4 * i);
    v11 = *a4 - *(float *)(v8 + 16);
    v12 = a4[1] - *(float *)(v8 + 20);
    v13 = a4[2] - *(float *)(v8 + 24);
    v9 = a5 + *(float *)(v8 + 28);
    if ( v9 * v9 >= v13 * v13 + v12 * v12 + v11 * v11 && *(_DWORD *)(v8 + 4) != a2 )
    {
      v10 = *(_DWORD *)(v8 + 36);
      *(_DWORD *)(v8 + 4) = a2;
      sub_5ED820(v10, 1);
    }
    result = this[7];
  }
  return result;
}
