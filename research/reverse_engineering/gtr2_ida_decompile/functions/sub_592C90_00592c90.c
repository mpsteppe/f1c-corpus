void __thiscall sub_592C90(float *this, float a2, float a3, float a4)
{
  long double v4; // st7
  long double v6; // st6
  long double v7; // st5
  long double v8; // st7
  double v9; // st6
  float *v10; // ecx
  long double v11; // st3
  double v12; // st7
  double v13; // st6
  double v14; // st7
  float v15; // ecx
  double v16; // st7
  long double v17; // st7
  char v19; // c0
  double v20; // st6
  float v21; // [esp+0h] [ebp-24h]
  float v22; // [esp+4h] [ebp-20h]
  float v23; // [esp+Ch] [ebp-18h]
  float v24; // [esp+10h] [ebp-14h]
  float v25; // [esp+18h] [ebp-Ch]
  float v26; // [esp+18h] [ebp-Ch]
  float v27; // [esp+18h] [ebp-Ch]
  float v28; // [esp+1Ch] [ebp-8h]
  float v29; // [esp+1Ch] [ebp-8h]
  float v30; // [esp+1Ch] [ebp-8h]
  float v31; // [esp+20h] [ebp-4h]
  float v32; // [esp+20h] [ebp-4h]
  float v33; // [esp+20h] [ebp-4h]
  float v34; // [esp+28h] [ebp+4h]
  float v35; // [esp+28h] [ebp+4h]
  float v36; // [esp+2Ch] [ebp+8h]
  float v37; // [esp+2Ch] [ebp+8h]
  float v38; // [esp+30h] [ebp+Ch]
  float v39; // [esp+30h] [ebp+Ch]

  v4 = a2 * 0.017453292;
  v6 = a3 * 0.017453292;
  this[1] = a3;
  *this = a2;
  this[2] = a4;
  v7 = cos((a4 - 0.47) * 6.2831855) * 0.41015238;
  v36 = sin(v7) * 1.49669e11;
  v34 = cos(v7) * 1.49669e11;
  v38 = cos(v4);
  v23 = -(sin(v6) * v38);
  v24 = sin(v4);
  v8 = -(cos(v6) * v38);
  v25 = v23 * v36;
  this[3] = v25;
  v28 = v24 * v36;
  this[4] = v28;
  v31 = v36 * v8;
  this[5] = v31;
  v9 = v24 * 0.0;
  v26 = v9 - v8 * -1.0;
  v10 = this + 6;
  v29 = v8 * 0.0 - v23 * 0.0;
  *v10 = v26;
  v10[1] = v29;
  v32 = v23 * -1.0 - v9;
  v10[2] = v32;
  if ( *v10 == 0.0 && v10[1] == 0.0 && v10[2] == 0.0 )
  {
    *v10 = 1.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
  }
  else
  {
    v11 = sqrt(*v10 * *v10 + v10[1] * v10[1] + v10[2] * v10[2]);
    *v10 = 1.0 / v11 * *v10;
    v10[1] = 1.0 / v11 * v10[1];
    v10[2] = 1.0 / v11 * v10[2];
  }
  v27 = v8 * v10[1] - v24 * v10[2];
  v30 = v23 * v10[2] - v8 * *v10;
  v12 = v24 * *v10;
  v13 = v23 * v10[1];
  this[9] = v27;
  this[10] = v30;
  v33 = v12 - v13;
  this[11] = v33;
  *v10 = v34 * *v10;
  v10[1] = v34 * v10[1];
  v10[2] = v34 * v10[2];
  this[9] = v34 * this[9];
  this[10] = v34 * this[10];
  v14 = v34;
  v35 = 0.0;
  this[11] = v14 * this[11];
  v15 = this[4];
  this[12] = -1.0;
  this[13] = -1.0;
  v16 = v15 + this[10];
  v21 = this[10];
  v22 = this[7];
  do
  {
    v37 = cos(v35) * v21 + sin(v35) * v22 + v15;
    if ( v37 * v16 <= 0.0 )
    {
      v39 = -v16 / (v37 - v16) * (v35 - (v35 - 0.065449849)) + v35 - 0.065449849;
      v17 = v39;
      if ( v19 )
        this[13] = fmod(v17, 6.283185482025146) * 13750.986;
      else
        this[12] = fmod(v17, 6.283185482025146) * 13750.986;
    }
    v16 = v37;
    v20 = v35 + 0.065449849;
    v35 = v20;
  }
  while ( v20 < 6.3486352 );
}
