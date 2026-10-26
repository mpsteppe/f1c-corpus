// f1c  0x004e9100  size=497
double __thiscall sub_4E9100(float *this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  double v9; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  double v12; // st7
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st7
  int v18; // eax
  long double v19; // st6
  double v20; // st7
  int v21; // eax
  double v22; // st7
  double v23; // st7
  float v25; // [esp+10h] [ebp-8h]
  float v26; // [esp+14h] [ebp-4h]
  float v27; // [esp+1Ch] [ebp+4h]
  float v28; // [esp+20h] [ebp+8h]
  float v29; // [esp+20h] [ebp+8h]
  int v30; // [esp+20h] [ebp+8h]
  float v31; // [esp+24h] [ebp+Ch]
  int v32; // [esp+24h] [ebp+Ch]
  float v33; // [esp+24h] [ebp+Ch]
  int v34; // [esp+24h] [ebp+Ch]
  float v35; // [esp+28h] [ebp+10h]

  v5 = a2 * a2;
  v27 = v5;
  v28 = v5 * this[3740] - (v27 * a3 + a4[1]) * this[3397];
  v25 = fabs(v27 * a5 - *a4) * this[3397];
  v9 = v28;
  if ( v10 | v11 )
  {
    v12 = v9 * this[3855];
    v35 = v12;
    sub_5895A2(v12);
    v31 = v12;
    v13 = (int)v31;
    v32 = v13;
    if ( v13 < 0 )
    {
      v14 = this[3856];
      goto LABEL_13;
    }
    if ( v13 >= 14 )
    {
      v13 = 13;
      v32 = 13;
    }
    v15 = this[v13 + 3856];
    v16 = this[v13 + 3857];
  }
  else
  {
    v17 = v9 * this[3871];
    v35 = v17;
    sub_5895A2(v17);
    v33 = v17;
    v18 = (int)v33;
    v32 = v18;
    if ( v18 < 0 )
    {
      v14 = this[3872];
      goto LABEL_13;
    }
    if ( v18 >= 14 )
    {
      v18 = 13;
      v32 = 13;
    }
    v15 = this[v18 + 3872];
    v16 = this[v18 + 3873];
  }
  v14 = v15 + (v16 - v15) * (v35 - (double)v32);
LABEL_13:
  v19 = v14 * v14 - v25 * v25;
  if ( v19 <= 0.0 )
  {
    v22 = 0.0;
  }
  else
  {
    v26 = sqrt(v19) / v14;
    v20 = v28 * this[3839];
    *(float *)&v34 = v20;
    sub_5895A2(v20);
    v29 = v20;
    v21 = (int)v29;
    v30 = v21;
    if ( v21 >= 0 )
    {
      if ( v21 >= 14 )
      {
        v21 = 13;
        v30 = 13;
      }
      v23 = this[v21 + 3840];
      v22 = (v23 + (this[v21 + 3841] - v23) * (*(float *)&v34 - (double)v30)) * this[3398] * v26;
    }
    else
    {
      v22 = this[3840] * this[3398] * v26;
    }
  }
  if ( v22 > this[3919] )
    v22 = this[3919];
  return v22 + this[3921] * this[3398] * v27 + a4[2];
}
