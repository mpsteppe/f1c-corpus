double __thiscall sub_575FB0(int this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  long double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // edx
  int v11; // ebp
  float *v12; // ecx
  int v13; // edi
  double v14; // st7
  double X; // st7
  int v16; // eax
  double v17; // st7
  double v18; // st7
  float X_4; // [esp+4h] [ebp-1Ch]
  float v21; // [esp+10h] [ebp-10h]
  float v22; // [esp+14h] [ebp-Ch]
  float v23; // [esp+18h] [ebp-8h]
  float v24; // [esp+1Ch] [ebp-4h]
  float v25; // [esp+1Ch] [ebp-4h]
  float v26; // [esp+24h] [ebp+4h]
  int v27; // [esp+24h] [ebp+4h]
  float v28; // [esp+28h] [ebp+8h]
  float v29; // [esp+28h] [ebp+8h]
  float v30; // [esp+30h] [ebp+10h]
  float v31; // [esp+30h] [ebp+10h]

  v5 = a2 * a2;
  v21 = v5;
  v22 = v5 * *(float *)(this + 17432) - (v21 * a3 + a4[1]) * *(float *)(this + 16036);
  v7 = fabs(v21 * a5 - *a4) * *(float *)(this + 16036);
  v30 = v7;
  if ( v7 >= 0.0 )
    v8 = sub_5738D0((float *)(this + 18180), v22);
  else
    v8 = sub_5738D0((float *)(this + 18116), v22);
  v28 = v8;
  v24 = v28 * v28 - v30 * v30;
  v9 = 0.0;
  if ( v24 > 0.0 )
  {
    v10 = *(_DWORD *)(this + 17312);
    v31 = 0.0;
    v11 = 1;
    if ( v10 >= 1 )
    {
      v12 = (float *)(this + 17272);
      while ( 1 )
      {
        v13 = this + 16148;
        if ( *(_DWORD *)(this + 17244) != 2 )
          v13 = this + 16652;
        v14 = a2 / *(float *)(v13 + 144) * *v12;
        v23 = v14;
        if ( v14 < *(float *)(this + 17216) )
          break;
        ++v11;
        ++v12;
        if ( v11 > v10 )
          goto LABEL_13;
      }
      v26 = sub_573930((_DWORD *)(this + 17228), v23, 1.0);
      sub_573930((_DWORD *)(this + 17228), v23, 0.0);
      v31 = v26 * *(float *)(this + 4 * v11 + 17268) / (*(float *)(v13 + 144) * *(float *)(this + 16036));
    }
LABEL_13:
    v25 = sqrt(v24) / v28;
    X = v22 * *(float *)(this + 18244);
    v29 = X;
    X_4 = floor(X);
    v16 = sub_4015C0(X_4);
    v27 = v16;
    if ( v16 >= 0 )
    {
      if ( v16 >= 14 )
      {
        v16 = 13;
        v27 = 13;
      }
      v18 = *(float *)(this + 4 * v16 + 18248);
      v17 = v18 + (*(float *)(this + 4 * v16 + 18252) - v18) * (v29 - (double)v27);
    }
    else
    {
      v17 = *(float *)(this + 18248);
    }
    v9 = v17 * *(float *)(this + 16040) * v25;
    if ( v9 > v31 )
      v9 = v31;
  }
  return v9 - *(float *)(this + 18380) * *(float *)(this + 16040) * v21 - a4[2];
}
