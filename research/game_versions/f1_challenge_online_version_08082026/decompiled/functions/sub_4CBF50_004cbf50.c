void __stdcall sub_4CBF50(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v6; // st7
  double v7; // st6
  double v8; // st5
  char v9; // fps^1
  char v10; // ah
  bool v11; // c0
  bool v12; // c3
  double v13; // st7
  float v14; // [esp+0h] [ebp-30h]
  float v15; // [esp+4h] [ebp-2Ch]
  float v16; // [esp+8h] [ebp-28h]
  float v17; // [esp+Ch] [ebp-24h]
  float v18; // [esp+10h] [ebp-20h]
  float v19; // [esp+14h] [ebp-1Ch]
  float v20; // [esp+18h] [ebp-18h]
  float v21; // [esp+1Ch] [ebp-14h]
  float v22; // [esp+20h] [ebp-10h]
  float v23; // [esp+24h] [ebp-Ch]
  float v24; // [esp+28h] [ebp-8h]
  float v25; // [esp+2Ch] [ebp-4h]

  v20 = a3[30];
  v21 = a3[31];
  v22 = a3[32];
  v23 = a3[33];
  v24 = a3[34];
  v3 = *a1 - a3[2];
  v25 = a3[35];
  v4 = a1[1] - a3[3];
  v5 = a1[2] - a3[4];
  v17 = v5 * a3[14] + v4 * a3[11] + v3 * a3[8];
  v18 = v5 * a3[15] + v4 * a3[12] + v3 * a3[9];
  v19 = v5 * a3[16] + v4 * a3[13] + v3 * a3[10];
  v6 = *a2 - a3[2];
  v7 = a2[1] - a3[3];
  v8 = a2[2] - a3[4];
  v14 = v8 * a3[14] + v7 * a3[11] + v6 * a3[8];
  v15 = v8 * a3[15] + v7 * a3[12] + v6 * a3[9];
  v16 = v8 * a3[16] + v7 * a3[13] + v6 * a3[10];
  if ( (v17 < (double)v23 && v14 > (double)v20 || v17 > (double)v20 && v14 < (double)v23)
    && (v19 < (double)v25 && v16 > (double)v22 || v19 > (double)v22 && v16 < (double)v25)
    && (v18 < (double)v24 && v15 > (double)v21 || v18 > (double)v21 && v15 < (double)v24) )
  {
    v10 = v9;
    v11 = v17 < (double)v14;
    v12 = v17 == v14;
    if ( (v10 & 0x41) != 0 )
    {
      if ( v11 || v12 )
        v13 = v14 - v17 + v23;
      else
        v13 = v23;
    }
    else if ( v11 || v12 )
    {
      v13 = v20;
    }
    else
    {
      v13 = v20 - (v17 - v14);
    }
    *a2 = v15 * a3[9] + v16 * a3[10] + v13 * a3[8];
    a2[1] = v15 * a3[12] + v16 * a3[13] + v13 * a3[11];
    a2[2] = v15 * a3[15] + v16 * a3[16] + v13 * a3[14];
    *a2 = *a2 + a3[2];
    a2[1] = a3[3] + a2[1];
    a2[2] = a3[4] + a2[2];
  }
}
