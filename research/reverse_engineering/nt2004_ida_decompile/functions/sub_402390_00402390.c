double __stdcall sub_402390(int a1)
{
  int v2; // edx
  int v3; // edi
  int v4; // ebp
  int v5; // eax
  int v6; // esi
  int v7; // edx
  double result; // st7
  float v9; // [esp+10h] [ebp-4h]
  int i; // [esp+18h] [ebp+4h]
  float v11; // [esp+18h] [ebp+4h]

  v2 = *(_DWORD *)(a1 + 308);
  if ( (v2 & 0x20) == 0 )
  {
    v3 = 1;
    v4 = a1;
    for ( i = 1; i <= 50; ++i )
    {
      v4 = *(_DWORD *)(v4 + 292);
      if ( !v4 || (((unsigned __int8)v2 ^ *(_BYTE *)(v4 + 308)) & 0x1F) != 0 )
        break;
      if ( (*(_DWORD *)(v4 + 308) & 0x20) != 0 )
      {
        v5 = a1;
        v6 = v2 & 0x1F;
        while ( 1 )
        {
          v5 = *(_DWORD *)(v5 + 296);
          if ( !v5 )
            break;
          v7 = *(_DWORD *)(v5 + 308);
          if ( (v7 & 0x1F) != v6 )
            break;
          if ( (v7 & 0x20) != 0 )
          {
            v9 = sub_5299B0(v5);
            v11 = (v9 - sub_5299B0(v4)) * ((double)i / (double)(i + v3));
            result = sub_5299B0(v4) + v11;
            if ( result < 0.0 )
              return 0.0;
            if ( result > 1.0 )
              return 1.0;
            return result;
          }
          if ( ++v3 > 50 )
            return sub_5299B0(a1);
        }
        return sub_5299B0(a1);
      }
    }
  }
  return sub_5299B0(a1);
}
