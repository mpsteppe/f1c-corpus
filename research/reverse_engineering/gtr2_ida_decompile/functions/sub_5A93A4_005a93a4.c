int __stdcall sub_5A93A4(int a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int i; // ebx
  unsigned int v5; // ecx
  int v6; // edx
  int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // ecx

  result = a1;
  for ( i = 0; i < a3; ++i )
  {
    v5 = *(_DWORD *)(a2 + 4 * i) & 0x7FFFFFFF;
    v6 = HIWORD(*(_DWORD *)(a2 + 4 * i)) & 0x8000;
    if ( v5 <= 0x47FFEFFF )
    {
      if ( v5 >= 0x38800000 )
      {
        v10 = ((v5 >> 13) & 1) + v5 - 939520001;
      }
      else
      {
        v8 = v5 >> 23;
        if ( (int)(113 - v8) <= 31 )
          v9 = ((unsigned int)&byte_800000 | (unsigned int)&unk_7FFFFF & *(_DWORD *)(a2 + 4 * i) & 0x7FFFFFFF) >> (113 - v8);
        else
          v9 = 0;
        v10 = ((v9 >> 13) & 1) + v9 + 4095;
      }
      v7 = v6 | (v10 >> 13);
    }
    else
    {
      LOWORD(v7) = v6 | 0x7FFF;
    }
    *(_WORD *)(a1 + 2 * i) = v7;
  }
  return result;
}
