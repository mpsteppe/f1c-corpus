int __thiscall sub_5CF6F0(_DWORD *this)
{
  int i; // edi
  int *v3; // ecx
  int result; // eax
  int j; // edi
  int *v6; // ecx
  float v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h] BYREF

  v7 = sub_5C68E0(this);
  for ( i = 0; i < this[9]; ++i )
  {
    v3 = *(int **)(this[11] + 4 * i);
    if ( v3 && *v3 > 0 && *(float *)(v3[2] + 8 * *v3 - 4) < (double)v7 )
    {
      v8 = 0;
      sub_5CEE80(v3, v7, (int)&v8);
    }
  }
  result = this[6];
  for ( j = 0; j < result; ++j )
  {
    v6 = *(int **)(this[8] + 4 * j);
    if ( v6 && *v6 > 0 && *(float *)(v6[2] + 8 * *v6 - 4) < (double)v7 )
    {
      v8 = 0;
      sub_5CEE80(v6, v7, (int)&v8);
    }
    result = this[6];
  }
  return result;
}
