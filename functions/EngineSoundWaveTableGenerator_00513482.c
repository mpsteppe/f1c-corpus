void __cdecl sub_513482(int a1)
{
  int v2; // eax
  double v3; // st7
  char v4; // al
  int v5; // edx
  int v6; // eax
  unsigned int v7; // edi
  int v8; // ebx
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // edx
  double v13; // st7
  __int16 v14; // cx
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // ebx
  double v18; // st7
  double v19; // [esp+4h] [ebp-28h]
  unsigned int v20; // [esp+14h] [ebp-18h]
  unsigned int v21; // [esp+18h] [ebp-14h]
  char v22; // [esp+1Ch] [ebp-10h]
  unsigned int v23; // [esp+20h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-4h]
  int v25; // [esp+34h] [ebp+8h]
  int v26; // [esp+34h] [ebp+8h]
  int v27; // [esp+34h] [ebp+8h]

  if ( *(float *)(a1 + 304) != 0.0 )
  {
    if ( *(_BYTE *)(a1 + 279) > 8u )
    {
      if ( (*(_BYTE *)(a1 + 278) & 2) != 0 )
      {
        v6 = *(unsigned __int8 *)(a1 + 336);
        if ( *(unsigned __int8 *)(a1 + 337) > v6 )
          v6 = *(unsigned __int8 *)(a1 + 337);
        if ( *(unsigned __int8 *)(a1 + 338) > v6 )
          v6 = *(unsigned __int8 *)(a1 + 338);
      }
      else
      {
        v6 = *(unsigned __int8 *)(a1 + 339);
      }
      v7 = 0;
      if ( v6 <= 0 )
        v24 = 0;
      else
        v24 = 16 - v6;
      if ( (*(_BYTE *)(a1 + 97) & 4) != 0 && v24 < 5 )
        v24 = 5;
      if ( v24 > 8 )
        v24 = 8;
      if ( v24 < 0 )
        v24 = 0;
      v8 = 1 << (8 - v24);
      v22 = 8 - v24;
      *(_DWORD *)(a1 + 300) = (unsigned __int8)v24;
      v9 = sub_517E92(a1, 4 * v8);
      v10 = (*(_WORD *)(a1 + 96) & 0x480) == 0;
      *(_DWORD *)(a1 + 324) = v9;
      v26 = 0;
      if ( v10 )
      {
        if ( v8 > 0 )
        {
          do
          {
            *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v26) = sub_517E92(a1, 512);
            v17 = 0;
            v23 = (unsigned int)(v26 * dword_5D799C[v24]) >> 4;
            do
            {
              v18 = (double)v23 * 0.00001525902189669642;
              sub_5881F0(v18);
              v23 += 256;
              *(_WORD *)(v17 + *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v26)) = CRTFtol(v18 * 65535.0 + 0.5);
              v17 += 2;
            }
            while ( v17 < 512 );
            ++v26;
          }
          while ( v26 < 1 << (8 - v24) );
        }
      }
      else
      {
        if ( v8 > 0 )
        {
          do
          {
            v11 = sub_517E92(a1, 512);
            v12 = v26++;
            *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * v12) = v11;
          }
          while ( v26 < v8 );
          v7 = 0;
        }
        v27 = 0;
        v21 = v8 << 8;
        v19 = (double)(unsigned int)(v8 << 8);
        do
        {
          v13 = ((double)v27 + 0.5) * 0.00390625;
          sub_5881F0(v13);
          v20 = CRTFtol(v13 * v19);
          if ( v7 <= v20 )
          {
            LOBYTE(v14) = 0;
            HIBYTE(v14) = v27;
            do
            {
              v15 = v7 >> v22;
              v16 = *(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * (v7++ & (255 >> v24)));
              *(_WORD *)(v16 + 2 * v15) = v27 | v14;
            }
            while ( v7 <= v20 );
          }
          ++v27;
        }
        while ( v27 < 256 );
        for ( ; v7 < v21; ++v7 )
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 324) + 4 * (v7 & (255 >> v24))) + 2 * (v7 >> v22)) = -1;
      }
    }
    else
    {
      v2 = sub_517E92(a1, 256);
      v25 = 0;
      *(_DWORD *)(a1 + 312) = v2;
      do
      {
        v3 = (double)v25 * 0.00392156862745098;
        sub_5881F0(v3);
        v4 = CRTFtol(v3 * 255.0 + 0.5);
        v5 = v25++;
        *(_BYTE *)(v5 + *(_DWORD *)(a1 + 312)) = v4;
      }
      while ( v25 < 256 );
    }
  }
}
