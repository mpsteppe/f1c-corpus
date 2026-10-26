void __stdcall sub_67C5F0(int a1)
{
  long double v2; // st7
  int v3; // eax
  __int64 v4; // rax
  int v5; // eax
  unsigned int v6; // edi
  int v7; // ebx
  long double v8; // st7
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // edx
  __int16 v13; // cx
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // ebx
  __int64 v17; // rax
  double v18; // [esp+4h] [ebp-28h]
  unsigned int v19; // [esp+14h] [ebp-18h]
  unsigned int v20; // [esp+18h] [ebp-14h]
  char v21; // [esp+1Ch] [ebp-10h]
  unsigned int v22; // [esp+20h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-4h]
  int v24; // [esp+34h] [ebp+8h]
  int v25; // [esp+34h] [ebp+8h]
  int v26; // [esp+34h] [ebp+8h]

  if ( 0.0 != *(float *)(a1 + 304) )
  {
    if ( *(_BYTE *)(a1 + 279) > 8u )
    {
      if ( (*(_BYTE *)(a1 + 278) & 2) != 0 )
      {
        v5 = *(unsigned __int8 *)(a1 + 336);
        if ( *(unsigned __int8 *)(a1 + 337) > v5 )
          v5 = *(unsigned __int8 *)(a1 + 337);
        if ( *(unsigned __int8 *)(a1 + 338) > v5 )
          v5 = *(unsigned __int8 *)(a1 + 338);
      }
      else
      {
        v5 = *(unsigned __int8 *)(a1 + 339);
      }
      v6 = 0;
      if ( v5 <= 0 )
        v23 = 0;
      else
        v23 = 16 - v5;
      if ( (*(_BYTE *)(a1 + 97) & 4) != 0 && v23 < 5 )
        v23 = 5;
      if ( v23 > 8 )
        v23 = 8;
      if ( v23 < 0 )
        v23 = 0;
      v7 = 1 << (8 - v23);
      v21 = 8 - v23;
      *(_DWORD *)(a1 + 300) = (unsigned __int8)v23;
      if ( *(float *)(a1 + 308) <= 0.000001 )
        v8 = 1.0;
      else
        v8 = 1.0 / (*(float *)(a1 + 308) * *(float *)(a1 + 304));
      v9 = sub_6B7269(a1, 4 * v7);
      v10 = (*(_WORD *)(a1 + 96) & 0x480) == 0;
      *(_DWORD *)(a1 + 324) = v9;
      v25 = 0;
      if ( v10 )
      {
        if ( v7 > 0 )
        {
          do
          {
            *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v25) = sub_6B7269(a1, 0x200u);
            v16 = 0;
            v22 = (unsigned int)(v25 * dword_915630[v23]) >> 4;
            do
            {
              v17 = (__int64)(pow((double)v22 * 0.00001525902189669642, v8) * 65535.0 + 0.5);
              v22 += 256;
              *(_WORD *)(v16 + *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v25)) = v17;
              v16 += 2;
            }
            while ( v16 < 512 );
            ++v25;
          }
          while ( v25 < 1 << (8 - v23) );
        }
      }
      else
      {
        if ( v7 > 0 )
        {
          do
          {
            v11 = sub_6B7269(a1, 0x200u);
            v12 = v25++;
            *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v12) = v11;
          }
          while ( v25 < v7 );
          v6 = 0;
        }
        v26 = 0;
        v20 = v7 << 8;
        v18 = (double)(unsigned int)(v7 << 8);
        do
        {
          v19 = (__int64)(pow(((double)v26 + 0.5) * 0.00390625, 1.0 / v8) * v18);
          if ( v6 <= v19 )
          {
            LOBYTE(v13) = 0;
            HIBYTE(v13) = v26;
            do
            {
              v14 = v6 >> v21;
              v15 = *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * (v6++ & (255 >> v23)));
              *(_WORD *)(v15 + 2 * v14) = v26 | v13;
            }
            while ( v6 <= v19 );
          }
          ++v26;
        }
        while ( v26 < 256 );
        for ( ; v6 < v20; ++v6 )
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * (v6 & (255 >> v23))) + 2 * (v6 >> v21)) = -1;
      }
    }
    else
    {
      if ( *(float *)(a1 + 308) <= 0.000001 )
        v2 = 1.0;
      else
        v2 = 1.0 / (*(float *)(a1 + 308) * *(float *)(a1 + 304));
      v3 = sub_6B7269(a1, 0x100u);
      v24 = 0;
      *(_DWORD *)(a1 + 312) = v3;
      do
      {
        v4 = (__int64)(pow((double)v24 * 0.00392156862745098, v2) * 255.0 + 0.5);
        HIDWORD(v4) = v24++;
        *(_BYTE *)(HIDWORD(v4) + *(_DWORD *)(a1 + 312)) = v4;
      }
      while ( v24 < 256 );
    }
  }
}
