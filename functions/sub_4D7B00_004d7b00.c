int __thiscall sub_4D7B00(int this)
{
  int i; // eax
  int j; // edx
  int v3; // esi
  int result; // eax
  int v5; // edi
  int v6; // eax
  float v7; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 3; ++i )
  {
    *(_DWORD *)(this + 4 * i) = -1;
    *(_DWORD *)(this + 4 * i + 12) = -1;
  }
  for ( j = 0; j < 3; ++j )
  {
    if ( j == 1 )
    {
      *(_DWORD *)(this + 28) = 0;
    }
    else if ( j )
    {
      *(float *)(this + 4 * j + 24) = flt_5EA3F8[j];
    }
    else
    {
      *(float *)(this + 24) = flt_5EA404;
    }
    v3 = 0;
    *(float *)(this + 4 * j + 36) = flt_5EA3FC[j];
    result = dword_8ACFEC;
    if ( dword_8ACFEC > 0 )
    {
      v5 = dword_8ACFF0;
      do
      {
        v7 = *(float *)(v5 + 8 * v3 + 4);
        if ( *(float *)(this + 4 * j + 24) <= (double)v7 && v7 <= (double)*(float *)(this + 4 * j + 36) )
        {
          v6 = *(_DWORD *)(this + 4 * j);
          if ( v6 == -1 || *(float *)(v5 + 8 * v6 + 4) > (double)v7 )
          {
            *(_DWORD *)(this + 4 * j) = v3;
            v5 = dword_8ACFF0;
          }
          if ( *(_DWORD *)(this + 4 * j + 12) == -1 || *(float *)(v5 + 8 * *(_DWORD *)(this + 4 * j) + 4) < (double)v7 )
          {
            *(_DWORD *)(this + 4 * j + 12) = v3;
            v5 = dword_8ACFF0;
          }
        }
        result = dword_8ACFEC;
        ++v3;
      }
      while ( v3 < dword_8ACFEC );
    }
  }
  return result;
}
