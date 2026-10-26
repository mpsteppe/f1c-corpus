// f1c  0x004e9300  size=761
double __thiscall sub_4E9300(int this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  double v8; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  double v11; // st7
  int v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st7
  int v16; // eax
  double v17; // st7
  int v18; // edx
  unsigned int v19; // ebx
  float *v20; // ecx
  int v21; // edi
  double v22; // st7
  double v23; // st7
  double v24; // st7
  int v25; // ecx
  int v26; // eax
  double v27; // st7
  double v28; // st7
  int v29; // eax
  double v30; // st7
  double v31; // st7
  double v33; // st7
  float v34; // [esp+18h] [ebp-20h]
  float v35; // [esp+18h] [ebp-20h]
  float v36; // [esp+18h] [ebp-20h]
  float v37; // [esp+1Ch] [ebp-1Ch]
  float v38; // [esp+20h] [ebp-18h]
  int v39; // [esp+24h] [ebp-14h]
  float v40; // [esp+24h] [ebp-14h]
  float v41; // [esp+24h] [ebp-14h]
  float v42; // [esp+28h] [ebp-10h]
  float v43; // [esp+28h] [ebp-10h]
  float v44; // [esp+28h] [ebp-10h]
  float v45; // [esp+28h] [ebp-10h]
  float v46; // [esp+2Ch] [ebp-Ch]
  float v47; // [esp+2Ch] [ebp-Ch]
  float v48; // [esp+2Ch] [ebp-Ch]
  int v49; // [esp+2Ch] [ebp-Ch]
  float v50; // [esp+30h] [ebp-8h]
  float v51; // [esp+34h] [ebp-4h]
  float v52; // [esp+34h] [ebp-4h]

  v5 = a2 * a2;
  v37 = v5;
  v38 = v5 * *(float *)(this + 14960) - (v37 * a3 + a4[1]) * *(float *)(this + 13588);
  v42 = fabs(v37 * a5 - *a4) * *(float *)(this + 13588);
  v8 = v38;
  if ( v9 | v10 )
  {
    v11 = v8 * *(float *)(this + 15420);
    v34 = v11;
    sub_5895A2(v11);
    v46 = v11;
    v12 = (int)v46;
    v39 = v12;
    if ( v12 < 0 )
    {
      v35 = *(float *)(this + 15424);
      goto LABEL_13;
    }
    if ( v12 >= 14 )
    {
      v12 = 13;
      v39 = 13;
    }
    v13 = *(float *)(this + 4 * v12 + 15424);
    v14 = *(float *)(this + 4 * v12 + 15428);
  }
  else
  {
    v15 = v8 * *(float *)(this + 15484);
    v34 = v15;
    sub_5895A2(v15);
    v47 = v15;
    v16 = (int)v47;
    v39 = v16;
    if ( v16 < 0 )
    {
      v35 = *(float *)(this + 15488);
      goto LABEL_13;
    }
    if ( v16 >= 14 )
    {
      v16 = 13;
      v39 = 13;
    }
    v13 = *(float *)(this + 4 * v16 + 15488);
    v14 = *(float *)(this + 4 * v16 + 15492);
  }
  v35 = (v14 - v13) * (v34 - (double)v39) + v13;
LABEL_13:
  v48 = v35 * v35 - v42 * v42;
  v17 = 0.0;
  if ( v48 > 0.0 )
  {
    v18 = *(_DWORD *)(this + 14840);
    v40 = 0.0;
    v19 = 1;
    if ( v18 >= 1 )
    {
      v20 = (float *)(this + 14800);
      while ( 1 )
      {
        v21 = this + 13696;
        if ( *(_DWORD *)(this + 14772) != 2 )
          v21 = this + 14192;
        v22 = a2 / *(float *)(v21 + 144) * *v20;
        if ( v22 < *(float *)(this + 14744) )
          break;
        if ( ++v19 == 8 )
          v20 += 918;
        else
          ++v20;
        if ( (int)v19 > v18 )
          goto LABEL_24;
      }
      v23 = v22 * 0.03125;
      v51 = v23;
      v43 = v23;
      sub_5895A2(v23);
      v41 = v23;
      v24 = v43 - v41;
      v25 = (int)v41;
      v26 = *(_DWORD *)(this + 14756);
      v44 = (*(float *)(v26 + 8 * v25 + 8) - *(float *)(v26 + 8 * v25)) * v24 + *(float *)(v26 + 8 * v25);
      v50 = (*(float *)(v26 + 8 * v25 + 12) - *(float *)(v26 + 8 * v25 + 4)) * v24 + *(float *)(v26 + 8 * v25 + 4);
      sub_5895A2(v51);
      v27 = v50 + v44;
      if ( v19 > 7 )
        v33 = v27 * *(float *)(this + 4 * v19 + 18464);
      else
        v33 = v27 * *(float *)(this + 4 * v19 + 14796);
      v40 = v33 / (*(float *)(v21 + 144) * *(float *)(this + 13588));
    }
LABEL_24:
    v36 = sqrt(v48) / v35;
    v28 = v38 * *(float *)(this + 15548);
    v45 = v28;
    sub_5895A2(v28);
    v52 = v28;
    v29 = (int)v52;
    v49 = v29;
    if ( v29 >= 0 )
    {
      if ( v29 >= 14 )
      {
        v29 = 13;
        v49 = 13;
      }
      v31 = *(float *)(this + 4 * v29 + 15552);
      v30 = v31 + (*(float *)(this + 4 * v29 + 15556) - v31) * (v45 - (double)v49);
    }
    else
    {
      v30 = *(float *)(this + 15552);
    }
    v17 = v30 * *(float *)(this + 13592) * v36;
    if ( v17 > v40 )
      v17 = v40;
  }
  return v17 - *(float *)(this + 15684) * *(float *)(this + 13592) * v37 - a4[2];
}
