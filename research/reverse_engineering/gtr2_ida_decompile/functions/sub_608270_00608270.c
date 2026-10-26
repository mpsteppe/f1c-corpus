int __thiscall sub_608270(_DWORD *this, int a2)
{
  int result; // eax
  float v4; // edx
  long double v5; // st7
  long double v6; // st7
  float v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  float v13; // ebx
  int v14; // ebp
  int *v15; // eax
  int v16; // esi
  int *v17; // eax
  int v18; // edi
  bool v19; // zf
  float v20; // [esp+4h] [ebp-FCh] BYREF
  float v21; // [esp+8h] [ebp-F8h]
  float v22; // [esp+Ch] [ebp-F4h]
  int v23; // [esp+10h] [ebp-F0h]
  float v24; // [esp+14h] [ebp-ECh]
  float v25; // [esp+18h] [ebp-E8h]
  float v26; // [esp+1Ch] [ebp-E4h]
  float v27; // [esp+20h] [ebp-E0h]
  float v28; // [esp+24h] [ebp-DCh]
  float v29; // [esp+28h] [ebp-D8h] BYREF
  int v30; // [esp+2Ch] [ebp-D4h]
  float v31; // [esp+30h] [ebp-D0h] BYREF
  int v32; // [esp+34h] [ebp-CCh]
  float v33; // [esp+38h] [ebp-C8h] BYREF
  float v34; // [esp+3Ch] [ebp-C4h] BYREF
  _DWORD v35[24]; // [esp+40h] [ebp-C0h] BYREF
  float v36[3]; // [esp+A0h] [ebp-60h] BYREF
  float v37[3]; // [esp+ACh] [ebp-54h] BYREF
  float v38[3]; // [esp+B8h] [ebp-48h] BYREF
  float v39[3]; // [esp+C4h] [ebp-3Ch] BYREF
  float v40[3]; // [esp+D0h] [ebp-30h] BYREF
  float v41[3]; // [esp+DCh] [ebp-24h] BYREF
  float v42[3]; // [esp+E8h] [ebp-18h] BYREF
  float v43[3]; // [esp+F4h] [ebp-Ch] BYREF

  result = (int)(this + 13);
  if ( this != (_DWORD *)-52 )
  {
    v4 = *(float *)(a2 + 40);
    v24 = *(float *)(a2 + 36);
    v25 = v4;
    sub_5E4DB0((_DWORD *)a2, &v33, &v34);
    v5 = tan(v33 * 0.5);
    v22 = v24;
    v28 = v24 * v5;
    v31 = v5 * v25;
    v6 = tan(v34 * 0.5);
    v26 = v24 * v6;
    *(float *)&v23 = v6 * v25;
    v27 = -v28;
    v20 = v27;
    v21 = v26;
    sub_5D7810(&v20, v36, (float *)(a2 + 564));
    v29 = -v31;
    v20 = v29;
    v21 = *(float *)&v23;
    v22 = v25;
    sub_5D7810(&v20, v37, (float *)(a2 + 564));
    v7 = v29;
    v29 = -*(float *)&v23;
    v21 = v29;
    v20 = v7;
    v22 = v25;
    sub_5D7810(&v20, v38, (float *)(a2 + 564));
    v20 = v27;
    v27 = -v26;
    v21 = v27;
    v22 = v24;
    sub_5D7810(&v20, v39, (float *)(a2 + 564));
    v20 = v28;
    v21 = v26;
    v22 = v24;
    sub_5D7810(&v20, v40, (float *)(a2 + 564));
    v20 = v28;
    v21 = v27;
    v22 = v24;
    sub_5D7810(&v20, v41, (float *)(a2 + 564));
    v20 = v31;
    v21 = v29;
    v22 = v25;
    sub_5D7810(&v20, v42, (float *)(a2 + 564));
    v20 = v31;
    v21 = *(float *)&v23;
    v22 = v25;
    sub_5D7810(&v20, v43, (float *)(a2 + 564));
    memset(&v35[9], 0, 60);
    LOBYTE(v35[0]) = 0;
    v35[2] = this[1];
    v35[1] = 2;
    if ( this != (_DWORD *)-36 )
    {
      v8 = this[10];
      v9 = this[11];
      v35[3] = this[9];
      v35[4] = v8;
      v35[5] = v9;
    }
    if ( this != (_DWORD *)-12 )
    {
      v10 = this[4];
      v11 = this[5];
      v35[6] = this[3];
      v35[7] = v10;
      v35[8] = v11;
    }
    sub_6078F0((int)v35, (int)v36, 8);
    sub_607C60(v35, &v29, &v31);
    LODWORD(v27) = *(_DWORD *)(*(_DWORD *)(a2 + 764) + 744) + 1;
    result = LODWORD(v31);
    if ( SLODWORD(v29) <= SLODWORD(v31) )
    {
      v12 = v30;
      LODWORD(v13) = &this[292 * LODWORD(v29) + 82 + 73 * v30];
      v26 = v13;
      v23 = LODWORD(v31) - LODWORD(v29) + 1;
      do
      {
        if ( v12 <= v32 )
        {
          v14 = v32 - v12 + 1;
          do
          {
            v15 = *(int **)(LODWORD(v13) - 8);
            *(_DWORD *)LODWORD(v13) = v15;
            if ( v15 )
            {
              v16 = *v15;
              if ( *v15 )
              {
                do
                {
                  sub_5EA5A0((const char *)v16);
                  if ( *(_DWORD *)LODWORD(v13)
                    && (v17 = *(int **)(*(_DWORD *)LODWORD(v13) + 4), (*(_DWORD *)LODWORD(v13) = v17) != 0) )
                  {
                    v18 = *v17;
                  }
                  else
                  {
                    v18 = 0;
                  }
                  if ( *(_DWORD *)(v16 + 8) < LODWORD(v27) )
                  {
                    *(float *)(v16 + 8) = v27;
                    sub_5FBCC0((char *)v16, a2);
                  }
                  v16 = v18;
                }
                while ( v18 );
              }
            }
            LODWORD(v13) += 292;
            --v14;
          }
          while ( v14 );
          v12 = v30;
        }
        LODWORD(v13) = LODWORD(v26) + 1168;
        result = v23 - 1;
        v19 = v23 == 1;
        LODWORD(v26) += 1168;
        --v23;
      }
      while ( !v19 );
    }
  }
  return result;
}
