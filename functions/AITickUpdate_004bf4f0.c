void *__thiscall sub_4BF4F0(float *this)
{
  int v1; // edx
  int v2; // esi
  int v4; // ebp
  int v5; // ecx
  int v6; // eax
  double v7; // st7
  double v8; // st6
  int v9; // eax
  void *result; // eax
  int v11; // [esp+8h] [ebp-4h]

  v1 = dword_5C329C;
  v2 = 0;
  byte_8ACFA0 = 1;
  v11 = dword_5C329C;
  if ( dword_5C329C > 0 )
  {
    v4 = (char *)this - (char *)dword_7C54F0;
    do
    {
      v5 = dword_7C54F0[v2];
      v6 = *(_DWORD *)(v5 + 16484);
      if ( v6 != 3 && v6 != 2 )
      {
        if ( *(float *)(v4 + 4 * v2 + 8148208) > 0.0 )
        {
          v7 = *(float *)(v4 + 4 * v2 + 8148208) - *(float *)(v4 + 4 * v2 + 8148624);
          ++*(_DWORD *)(v5 + 16444);
          v8 = v7 + this[213];
          if ( v8 < 0.0 )
            v8 = 0.0;
          *(float *)(v5 + 16536) = v8;
          *(float *)(v5 + 16568) = this[213] - flt_8ACF90 + v7;
          if ( *(_DWORD *)(v5 + 16484) != 3 )
            *(_DWORD *)(v5 + 16484) = 1;
          AIDriverSorting(v5);
          v1 = v11;
        }
        v9 = dword_7C54F0[v2];
        if ( !*(_DWORD *)(v9 + 16484) )
          *(_DWORD *)(v9 + 16484) = 1;
      }
      ++v2;
    }
    while ( v2 < v1 );
  }
  dword_83EE5C = (int)&unk_7D2E54;
  dword_83EE58 = (int)&unk_7D2E54;
  dword_83EE54 = (int)&unk_7D2E54;
  result = &unk_83EE64;
  dword_7D2E50 = 0;
  dword_8AAE6C = (int)&unk_83EE64;
  dword_8AAE68 = (int)&unk_83EE64;
  dword_8AAE64 = (int)&unk_83EE64;
  dword_83EE60 = 0;
  return result;
}
