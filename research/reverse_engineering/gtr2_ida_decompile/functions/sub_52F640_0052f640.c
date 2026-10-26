int __thiscall sub_52F640(_DWORD *this, int a2, int a3, float *a4, float a5)
{
  int i; // ebx
  int v7; // ecx
  double v8; // st7
  int result; // eax
  int j; // ebx
  int v11; // ecx
  double v12; // st7
  float v13; // [esp+1Ch] [ebp-Ch]
  float v14; // [esp+1Ch] [ebp-Ch]
  float v15; // [esp+20h] [ebp-8h]
  float v16; // [esp+20h] [ebp-8h]
  float v17; // [esp+24h] [ebp-4h]
  float v18; // [esp+24h] [ebp-4h]

  for ( i = 0; i < this[1]; ++i )
  {
    v7 = *(_DWORD *)(this[2] + 4 * i);
    v13 = *a4 - *(float *)(v7 + 16);
    v15 = a4[1] - *(float *)(v7 + 20);
    v17 = a4[2] - *(float *)(v7 + 24);
    v8 = a5 + *(float *)(v7 + 28);
    if ( v8 * v8 >= v17 * v17 + v15 * v15 + v13 * v13 && a3 != *(_DWORD *)(v7 + 36) && *(_DWORD *)(v7 + 4) != a2 )
    {
      *(_DWORD *)(v7 + 4) = a2;
      sub_418690((_DWORD *)v7, a3);
    }
  }
  result = this[4];
  for ( j = 0; j < result; ++j )
  {
    v11 = *(_DWORD *)(this[5] + 4 * j);
    v14 = *a4 - *(float *)(v11 + 16);
    v16 = a4[1] - *(float *)(v11 + 20);
    v18 = a4[2] - *(float *)(v11 + 24);
    v12 = a5 + *(float *)(v11 + 28);
    if ( v12 * v12 >= v18 * v18 + v16 * v16 + v14 * v14 && *(_DWORD *)(v11 + 4) != a2 )
    {
      *(_DWORD *)(v11 + 4) = a2;
      sub_418690((_DWORD *)v11, a3);
    }
    result = this[4];
  }
  return result;
}
