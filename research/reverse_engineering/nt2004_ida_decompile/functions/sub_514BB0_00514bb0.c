double __thiscall sub_514BB0(int this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  double v8; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  double X; // st7
  int v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st7
  int v16; // eax
  double v17; // st7
  int v18; // edx
  int v19; // ebx
  float *v20; // ecx
  int v21; // edi
  double v22; // st7
  double v23; // st7
  double v24; // st7
  int v25; // ecx
  int v26; // eax
  double v27; // st7
  int v28; // eax
  double v29; // st7
  double v30; // st7
  float v32; // [esp+18h] [ebp-20h]
  float v33; // [esp+18h] [ebp-20h]
  float v34; // [esp+18h] [ebp-20h]
  float v35; // [esp+1Ch] [ebp-1Ch]
  float v36; // [esp+20h] [ebp-18h]
  int v37; // [esp+24h] [ebp-14h]
  float v38; // [esp+24h] [ebp-14h]
  float v39; // [esp+24h] [ebp-14h]
  float v40; // [esp+28h] [ebp-10h]
  float v41; // [esp+28h] [ebp-10h]
  float v42; // [esp+28h] [ebp-10h]
  float v43; // [esp+28h] [ebp-10h]
  float v44; // [esp+2Ch] [ebp-Ch]
  float v45; // [esp+2Ch] [ebp-Ch]
  float v46; // [esp+2Ch] [ebp-Ch]
  int v47; // [esp+2Ch] [ebp-Ch]
  float v48; // [esp+30h] [ebp-8h]
  float v49; // [esp+34h] [ebp-4h]
  float v50; // [esp+34h] [ebp-4h]

  v5 = a2 * a2;
  v35 = v5;
  v36 = v5 * *(float *)(this + 18956) - (v35 * a3 + a4[1]) * *(float *)(this + 17584);
  v40 = fabs(v35 * a5 - *a4) * *(float *)(this + 17584);
  v8 = v36;
  if ( v9 | v10 )
  {
    X = v8 * *(float *)(this + 19428);
    v32 = X;
    v44 = floor(X);
    v12 = (int)v44;
    v37 = v12;
    if ( v12 < 0 )
    {
      v33 = *(float *)(this + 19432);
      goto LABEL_13;
    }
    if ( v12 >= 14 )
    {
      v12 = 13;
      v37 = 13;
    }
    v13 = *(float *)(this + 4 * v12 + 19432);
    v14 = *(float *)(this + 4 * v12 + 19436);
  }
  else
  {
    v15 = v8 * *(float *)(this + 19492);
    v32 = v15;
    v45 = floor(v15);
    v16 = (int)v45;
    v37 = v16;
    if ( v16 < 0 )
    {
      v33 = *(float *)(this + 19496);
      goto LABEL_13;
    }
    if ( v16 >= 14 )
    {
      v16 = 13;
      v37 = 13;
    }
    v13 = *(float *)(this + 4 * v16 + 19496);
    v14 = *(float *)(this + 4 * v16 + 19500);
  }
  v33 = (v14 - v13) * (v32 - (double)v37) + v13;
LABEL_13:
  v46 = v33 * v33 - v40 * v40;
  v17 = 0.0;
  if ( v46 > 0.0 )
  {
    v18 = *(_DWORD *)(this + 18836);
    v38 = 0.0;
    v19 = 1;
    if ( v18 >= 1 )
    {
      v20 = (float *)(this + 18796);
      while ( 1 )
      {
        v21 = this + 17692;
        if ( *(_DWORD *)(this + 18768) != 2 )
          v21 = this + 18188;
        v22 = a2 / *(float *)(v21 + 144) * *v20;
        if ( v22 < *(float *)(this + 18740) )
          break;
        ++v19;
        ++v20;
        if ( v19 > v18 )
          goto LABEL_22;
      }
      v23 = v22 * 0.03125;
      v49 = v23;
      v41 = v23;
      v39 = floor(v23);
      v24 = v41 - v39;
      v25 = (int)v39;
      v26 = *(_DWORD *)(this + 18752);
      v42 = (*(float *)(v26 + 8 * v25 + 8) - *(float *)(v26 + 8 * v25)) * v24 + *(float *)(v26 + 8 * v25);
      v48 = (*(float *)(v26 + 8 * v25 + 12) - *(float *)(v26 + 8 * v25 + 4)) * v24 + *(float *)(v26 + 8 * v25 + 4);
      floor(v49);
      v38 = (v48 + v42) * *(float *)(this + 4 * v19 + 18792) / (*(float *)(v21 + 144) * *(float *)(this + 17584));
    }
LABEL_22:
    v34 = sqrt(v46) / v33;
    v27 = v36 * *(float *)(this + 19556);
    v43 = v27;
    v50 = floor(v27);
    v28 = (int)v50;
    v47 = v28;
    if ( v28 >= 0 )
    {
      if ( v28 >= 14 )
      {
        v28 = 13;
        v47 = 13;
      }
      v30 = *(float *)(this + 4 * v28 + 19560);
      v29 = v30 + (*(float *)(this + 4 * v28 + 19564) - v30) * (v43 - (double)v47);
    }
    else
    {
      v29 = *(float *)(this + 19560);
    }
    v17 = v29 * *(float *)(this + 17588) * v34;
    if ( v17 > v38 )
      v17 = v38;
  }
  return v17 - *(float *)(this + 19692) * *(float *)(this + 17588) * v35 - a4[2];
}
