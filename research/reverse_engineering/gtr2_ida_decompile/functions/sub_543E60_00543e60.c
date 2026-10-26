int __thiscall sub_543E60(int this, float a2, float *a3, float *a4, float *a5, float a6, int a7, int a8)
{
  int result; // eax
  int v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  float *v15; // esi
  double v16; // st7
  long double v17; // st7
  double v18; // st6
  int v19; // ecx
  long double v20; // st6
  long double v21; // st7
  double v22; // st5
  double v23; // st7
  double v24; // st7
  double v25; // st7
  int v26; // [esp+10h] [ebp-88h]
  float v27; // [esp+10h] [ebp-88h]
  double *v28; // [esp+14h] [ebp-84h]
  float v29; // [esp+18h] [ebp-80h]
  int v30; // [esp+1Ch] [ebp-7Ch]
  float v31; // [esp+20h] [ebp-78h]
  float v32; // [esp+24h] [ebp-74h]
  float v33; // [esp+2Ch] [ebp-6Ch]
  float v34; // [esp+30h] [ebp-68h]
  float v35; // [esp+34h] [ebp-64h]
  float v36; // [esp+38h] [ebp-60h]
  float v37; // [esp+3Ch] [ebp-5Ch]
  float v38; // [esp+40h] [ebp-58h]
  float v39; // [esp+4Ch] [ebp-4Ch]
  float v40; // [esp+58h] [ebp-40h]
  float v41; // [esp+5Ch] [ebp-3Ch]
  double v42[6]; // [esp+60h] [ebp-38h] BYREF
  double *v43; // [esp+90h] [ebp-8h]

  result = *(_DWORD *)(this + 96);
  v28 = 0;
  if ( result > 0 )
  {
    result = a7;
    if ( a7 > 0 )
    {
      v30 = a7;
      do
      {
        v10 = *(_DWORD *)(this + 104);
        v11 = *(_DWORD *)(this + 96);
        v26 = v10;
        *(_DWORD *)(this + 104) = v10 + 1;
        if ( v10 + 1 >= v11 )
          *(_DWORD *)(this + 104) = 0;
        v12 = *(_DWORD *)(this + 100);
        v13 = 108 * v10;
        v14 = *(_DWORD *)(v12 + v13 + 4);
        v15 = (float *)(v13 + v12);
        if ( v14 < 0 )
        {
          v15[1] = *(float *)(this + 108);
          *(_DWORD *)(*(_DWORD *)(this + 112) + 4 * (*(_DWORD *)(this + 108))++) = v13 + *(_DWORD *)(this + 100);
          sub_5FCAC0(v26);
        }
        v16 = a2 + v15[7];
        v15[2] = a2;
        v15[3] = v16;
        v15[11] = *a3;
        v15[12] = a3[1];
        v15[13] = a3[2];
        v17 = atan2(a5[2], *a5);
        v18 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * a6;
        v19 = dword_BE08A0 + 1;
        v27 = v18 * 10.0;
        v20 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v29 = sqrt(fabs(v20)) * 1.570796326794897;
        if ( v20 < 0.0 )
          v21 = v17 - v29;
        else
          v21 = v17 + v29;
        v22 = flt_BE0CA4[(unsigned __int8)v19];
        dword_BE08A0 = v19 + 1;
        v39 = a4[2];
        v31 = *a4;
        v32 = a4[1];
        v40 = v22 * a6 * 3.0 + 3.0;
        v15[17] = 0.0;
        v41 = sin(v21) * v27;
        v33 = v31 + cos(v21) * v27;
        v15[14] = v33;
        v34 = v32 + v40;
        v15[15] = v34;
        v35 = v39 + v41;
        v15[16] = v35;
        v42[0] = *a3;
        v43 = v28;
        v42[1] = a3[1];
        v42[2] = a3[2];
        v42[3] = 0.25;
        v42[4] = 9.999999933815813e36;
        v28 = sub_45D210(dbl_B68610, v42, v15 + 21);
        v15[25] = v42[5] * v15[22] + v15[23] * a3[2] + *a3 * v15[21];
        v23 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.75;
        v36 = (v23 + 0.25) * *(float *)(this + 12);
        v24 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
        v37 = (v24 * 0.75 + 0.25) * *(float *)(this + 16);
        v25 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
        v38 = (v25 * 0.75 + 0.25) * *(float *)(this + 20);
        sub_5FCCB0(*(_DWORD *)v15, *((_DWORD *)v15 + 11), *((_DWORD *)v15 + 12), *((_DWORD *)v15 + 13));
        sub_5FCD10(*(_DWORD *)v15, LODWORD(v36), LODWORD(v37), LODWORD(v38));
        result = sub_5FC760(*(_DWORD *)v15, a8 | 0xFF000000);
        --v30;
      }
      while ( v30 );
    }
  }
  return result;
}
