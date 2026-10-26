// f1c  0x004fb2e0  size=742
void __thiscall sub_4FB2E0(int this)
{
  float *v1; // edi
  int v2; // edx
  float *v3; // esi
  double v4; // st5
  double v5; // st7
  long double v6; // st5
  long double v7; // st7
  float *v8; // edx
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st6
  double v13; // st7
  long double v14; // st5
  long double v15; // st7
  float v16; // [esp+Ch] [ebp-38h]
  float v17; // [esp+Ch] [ebp-38h]
  float v18; // [esp+10h] [ebp-34h]
  float v19; // [esp+10h] [ebp-34h]
  float v20; // [esp+18h] [ebp-2Ch]
  float v21; // [esp+18h] [ebp-2Ch]
  float v22; // [esp+1Ch] [ebp-28h]
  float v23; // [esp+1Ch] [ebp-28h]
  float v24; // [esp+24h] [ebp-20h]
  float v25; // [esp+24h] [ebp-20h]
  float v26; // [esp+30h] [ebp-14h]
  float v27; // [esp+30h] [ebp-14h]
  float v28; // [esp+38h] [ebp-Ch]
  float v29; // [esp+38h] [ebp-Ch]
  float v30; // [esp+40h] [ebp-4h]
  float v31; // [esp+40h] [ebp-4h]

  v1 = *(float **)(this + 268);
  if ( v1 )
  {
    v2 = *(_DWORD *)(this + 272);
    if ( v2 )
    {
      if ( *(_DWORD *)(v2 + 272) )
      {
        v22 = *(float *)(v2 + 148);
        v24 = *(float *)(v2 + 156);
        v28 = -*(float *)(this + 172);
        v3 = (float *)(this + 148);
        v18 = *(float *)(this + 148);
        v20 = *(float *)(this + 156);
        v30 = *(float *)(this + 164);
        v4 = v30 * *(float *)(v2 + 172) + v28 * *(float *)(v2 + 164);
        if ( v4 > -0.00001 && v4 < 0.00001 )
        {
          if ( v2 == this )
            *(_DWORD *)(this + 176) = 0;
          else
            *(_DWORD *)(this + 176) = 1232348144;
          return;
        }
        v5 = v28
           * ((v20
             - v24
             - *(float *)(v2 + 164) / -*(float *)(v2 + 172) * v18
             + *(float *)(v2 + 164) / -*(float *)(v2 + 172) * v22)
            / (*(float *)(v2 + 164) / -*(float *)(v2 + 172) * v28 - v30))
           + v18;
        v26 = (v20
             - v24
             - *(float *)(v2 + 164) / -*(float *)(v2 + 172) * v18
             + *(float *)(v2 + 164) / -*(float *)(v2 + 172) * v22)
            / (*(float *)(v2 + 164) / -*(float *)(v2 + 172) * v28 - v30)
            * v30
            + v20;
        v16 = sqrt((v26 - v24) * (v26 - v24) + (v5 - v22) * (v5 - v22));
        v6 = sqrt((v26 - v20) * (v26 - v20) + (v5 - v18) * (v5 - v18));
        v7 = v6;
        if ( v2 == this )
        {
          *(_DWORD *)(this + 176) = 0;
        }
        else
        {
          if ( v16 <= v6 )
            v7 = v16;
          *(float *)(this + 176) = v7;
        }
        v8 = *(float **)(this + 276);
        if ( v8 )
        {
          v23 = *v3;
          v25 = *(float *)(this + 156);
          v19 = v1[37];
          v29 = -v1[43];
          v21 = v1[39];
          v31 = v1[41];
          v11 = v31 * *(float *)(this + 172) + v29 * *(float *)(this + 164);
          if ( v11 > -0.00001 && v11 < 0.00001 )
          {
            if ( v8 != (float *)this )
            {
              *(_DWORD *)(this + 180) = 2139095039;
              return;
            }
            goto LABEL_23;
          }
          v10 = -(v8[2] - *(float *)(this + 156));
          v9 = *v8 - *v3;
          v12 = (v21 - v25 - v9 / v10 * v19 + v9 / v10 * v23) / (v9 / v10 * v29 - v31);
          v13 = v29 * v12 + v19;
          v27 = v12 * v31 + v21;
          v17 = sqrt((v27 - v25) * (v27 - v25) + (v13 - v23) * (v13 - v23));
          v14 = sqrt((v27 - v21) * (v27 - v21) + (v13 - v19) * (v13 - v19));
          v15 = v14;
          if ( v8 == (float *)this )
          {
LABEL_23:
            *(_DWORD *)(this + 180) = 0;
            return;
          }
          if ( v17 <= v14 )
            v15 = v17;
          *(float *)(this + 180) = v15;
        }
      }
    }
  }
}
