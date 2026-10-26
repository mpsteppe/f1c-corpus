void __thiscall sub_600940(_DWORD *this, int a2, int a3, float *a4, int a5)
{
  int v5; // esi
  float *v6; // eax
  bool v7; // zf
  float v8; // ecx
  double v9; // st4
  double v10; // st3
  double v11; // st4
  double v12; // st3
  double v13; // st7
  double v14; // st6
  int v15; // eax
  float *v16; // eax
  int v17; // ecx
  int v18; // eax
  float *v19; // ecx
  float v21[512]; // [esp+Ch] [ebp-800h] BYREF

  v5 = 0;
  if ( a5 )
  {
    *(_DWORD *)(a3 + 568) = 0;
    v6 = *(float **)a5;
    v7 = *(_DWORD *)a5 == 0;
    *(_DWORD *)(a5 + 8) = *(_DWORD *)a5;
    if ( !v7 )
    {
      v8 = *v6;
      if ( *(_DWORD *)v6 )
      {
        do
        {
          if ( (*(_DWORD *)LODWORD(v8) & 1) != 0 )
          {
            v9 = *(float *)(LODWORD(v8) + 204) - a4[57];
            v10 = *(float *)(LODWORD(v8) + 208) - a4[58];
            v11 = v9 * v9 + v10 * v10;
            v12 = *(float *)(LODWORD(v8) + 212) - a4[59];
            v13 = v11 + v12 * v12;
            v14 = *(float *)(LODWORD(v8) + 96) + a4[5];
            if ( v13 <= v14 * v14 )
            {
              if ( (*(_DWORD *)LODWORD(v8) & 0x80u) != 0 )
                v13 = v13 + 1000000.0;
              v21[2 * v5] = v13;
              v21[2 * v5++ + 1] = v8;
            }
          }
          v15 = *(_DWORD *)(a5 + 8);
          if ( !v15 )
            break;
          v16 = *(float **)(v15 + 4);
          *(_DWORD *)(a5 + 8) = v16;
          if ( !v16 )
            break;
          v8 = *v16;
        }
        while ( *(_DWORD *)v16 );
        if ( v5 > 0 )
        {
          if ( v5 > this[185] )
            sub_632C60(v21, v5);
          v17 = this[185];
          if ( v17 >= v5 )
            v17 = v5;
          v18 = 0;
          *(_DWORD *)(a3 + 568) = v17;
          if ( v17 > 0 )
          {
            v19 = (float *)(a3 + 572);
            do
              *v19++ = v21[2 * v18++ + 1];
            while ( v18 < *(_DWORD *)(a3 + 568) );
          }
        }
      }
    }
  }
}
