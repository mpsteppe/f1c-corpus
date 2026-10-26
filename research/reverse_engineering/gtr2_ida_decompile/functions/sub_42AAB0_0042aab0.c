int __thiscall sub_42AAB0(_DWORD *this)
{
  int v1; // edx
  char v2; // bl
  float *v3; // eax
  double v4; // st7
  double v5; // st7
  float i; // [esp+4h] [ebp-1Ch]
  float v8; // [esp+14h] [ebp-Ch]
  float v9; // [esp+18h] [ebp-8h]
  float v10; // [esp+1Ch] [ebp-4h]

  v1 = this[2];
  v2 = 15;
  for ( i = 10000.0; v1; --v2 )
  {
    if ( !v2 )
      break;
    v3 = (float *)this[6];
    v4 = v3[3993];
    v3 += 3993;
    v8 = v4 - *(float *)v1;
    v9 = v3[1] - *(float *)(v1 + 4);
    v10 = v3[2] - *(float *)(v1 + 8);
    v5 = v10 * v10 + v9 * v9 + v8 * v8;
    if ( v5 < i )
    {
      i = v5;
      this[2] = v1;
    }
    v1 = *(_DWORD *)(v1 + 56);
  }
  return this[2];
}
