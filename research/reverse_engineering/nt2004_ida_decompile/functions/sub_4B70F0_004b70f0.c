int __stdcall sub_4B70F0(int a1, float a2, float a3)
{
  int result; // eax
  int v5; // esi
  int v6; // esi
  double *v7; // ebx
  double v8; // st7
  int v9; // edi
  float v10; // [esp+14h] [ebp-24h]
  char Buffer[29]; // [esp+18h] [ebp-20h] BYREF
  __int16 v12; // [esp+35h] [ebp-3h]
  char v13; // [esp+37h] [ebp-1h]
  int v14; // [esp+3Ch] [ebp+4h]
  float v15; // [esp+3Ch] [ebp+4h]

  result = 304 * a1;
  if ( *(_BYTE *)(304 * a1 + dword_75AAC4 + 2296) )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x1Cu);
    v12 = 0;
    v13 = 0;
    v5 = dword_75AAC4;
    result = sub_42DBA0() ? dword_75AACC : 0;
    if ( v5 == result )
    {
      v6 = 0;
      v14 = 0;
      v7 = &dbl_75EF84[157 * a1];
      do
      {
        v10 = (double)v14 * 0.145 + a2;
        v8 = *v7 - 273.16;
        if ( v8 <= 170.0 )
        {
          if ( v8 <= 120.0 )
            v9 = -1;
          else
            v9 = -256;
        }
        else
        {
          v9 = -65536;
        }
        if ( dword_7689F0 == 1 )
        {
          v15 = (v8 - -40.0) * 1.8 - 40.0;
          v8 = (double)(int)v15;
        }
        sprintf(Buffer, "%d", (unsigned int)(__int64)v8);
        result = sub_5070D0(Buffer, v10, a3, v9, 8, -1.0, -1.0, 0, 0);
        ++v6;
        ++v7;
        v14 = v6;
      }
      while ( v6 < 3 );
    }
  }
  return result;
}
