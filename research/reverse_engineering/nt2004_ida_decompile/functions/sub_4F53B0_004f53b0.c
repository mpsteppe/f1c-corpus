int __thiscall sub_4F53B0(_DWORD *this, float a2)
{
  int v3; // ebx
  int result; // eax
  int v5; // ebx
  int i; // ebp
  _DWORD *v7; // edi
  float v8; // [esp+8h] [ebp+4h]

  v8 = a2 * 254.0;
  v3 = (int)v8;
  if ( v3 )
  {
    if ( (int)this[24] > 0 && !this[27] )
      sub_402940((int)&flt_628F60, 1, 0);
    result = this[27];
    v5 = (v3 << 24) + 0xFFFFFF;
    for ( i = 0; i < result; ++i )
    {
      v7 = *(_DWORD **)(this[28] + 4 * i);
      sub_5B0D00(*v7, 0, v5);
      sub_5B0D00(*v7, 1, v5);
      sub_5B0D00(*v7, 2, v5);
      sub_5B0D00(*v7, 3, v5);
      result = this[27];
    }
  }
  else
  {
    result = this[27];
    if ( result > 0 )
      return sub_4F2B80(this);
  }
  return result;
}
