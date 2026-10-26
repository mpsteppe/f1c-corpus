void __thiscall sub_546900(int *this, int a2, float a3, float *a4, float *a5, float *a6, int a7)
{
  int v8; // esi
  int v9; // ecx
  double v10; // st7
  double v11; // st6
  float *v12; // esi
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  bool v18; // cc
  float v19; // [esp+0h] [ebp-78h]
  int v21[3]; // [esp+24h] [ebp-54h] BYREF
  float v22; // [esp+30h] [ebp-48h]
  float v23; // [esp+34h] [ebp-44h]
  float v24; // [esp+38h] [ebp-40h]
  float v25; // [esp+3Ch] [ebp-3Ch]
  float v26; // [esp+40h] [ebp-38h]
  float v27; // [esp+44h] [ebp-34h]
  float v28[3]; // [esp+48h] [ebp-30h] BYREF
  float v29[3]; // [esp+54h] [ebp-24h] BYREF
  float v30[3]; // [esp+60h] [ebp-18h] BYREF
  int v31[3]; // [esp+6Ch] [ebp-Ch] BYREF
  int v32; // [esp+7Ch] [ebp+4h]

  if ( this[11] )
  {
    if ( *(float *)(a2 + 8) != 0.0 )
    {
      v8 = *(_DWORD *)(a2 + 12);
      if ( v8 )
      {
        if ( !byte_B71428 )
          a7 = -1;
        if ( (dword_B7129C > 2 || dword_BE1204 == 2 || !(dword_91E230 % 20)) && *(float *)a2 != 0.0 )
        {
          v9 = (int)a4;
          if ( fabs(a3 - *(float *)(a2 + 4)) > 0.050000001
            || (v11 = a4[2] - *(float *)(a2 + 24), v10 = *a4 - *(float *)(a2 + 16), v11 * v11 + v10 * v10 > 0.090000004) )
          {
            v32 = 0;
            if ( v8 > 0 )
            {
              v12 = (float *)(a2 + 32);
              do
              {
                sub_416420(a5, (float *)v9, v12 - 1, v29);
                v22 = v12[11] - *(v12 - 1);
                v13 = v12[12];
                v28[0] = v22;
                v23 = v13 - *v12;
                v14 = v12[13];
                v28[1] = v23;
                v24 = v14 - v12[1];
                v28[2] = v24;
                sub_407380(a5, v28, v30);
                v15 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.1;
                *(float *)v31 = v15 + v29[0];
                *(float *)&v31[1] = v29[1];
                v16 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
                *(float *)&v31[2] = v16 * 0.1 + v29[2];
                v25 = *a6 * 0.1;
                v17 = a6[1];
                *(float *)v21 = v25;
                v26 = v17 * 0.1;
                v27 = a6[2] * 0.1;
                *(float *)v21 = v30[0] + v25;
                *(float *)&v21[1] = v30[1] + v26;
                *(float *)&v21[2] = v30[2] + v27;
                v19 = *(float *)a2 * *(float *)(a2 + 8);
                sub_543B10(this[11], a3, (float *)v31, (float *)v21, v19, 0, 0, a7);
                v12 += 3;
                v18 = v32 + 1 < *(_DWORD *)(a2 + 12);
                v9 = (int)a4;
                ++v32;
              }
              while ( v18 );
            }
            *(_DWORD *)(a2 + 16) = *(_DWORD *)v9;
            *(_DWORD *)(a2 + 20) = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(a2 + 24) = *(_DWORD *)(v9 + 8);
            *(float *)(a2 + 4) = a3;
          }
        }
      }
    }
  }
}
