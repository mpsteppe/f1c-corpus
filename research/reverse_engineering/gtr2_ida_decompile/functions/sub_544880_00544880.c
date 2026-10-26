int __thiscall sub_544880(int this, float *a2, int a3, float *a4, int a5, int a6)
{
  int result; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  float *v12; // eax
  float v13; // ecx
  float v14; // edx
  double v15; // st7
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // esi
  int v20; // eax
  int v21; // ecx
  int v22; // esi
  int v23; // edx
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  float v32; // edx
  double v33; // st7
  double v34; // st7
  float v35; // [esp+4h] [ebp-BCh] BYREF
  float v36; // [esp+8h] [ebp-B8h]
  float v37; // [esp+Ch] [ebp-B4h]
  float v38; // [esp+10h] [ebp-B0h]
  float v39; // [esp+14h] [ebp-ACh]
  float v40; // [esp+18h] [ebp-A8h]
  float v41; // [esp+1Ch] [ebp-A4h]
  float v42; // [esp+20h] [ebp-A0h]
  float v43; // [esp+24h] [ebp-9Ch]
  float v44; // [esp+28h] [ebp-98h]
  float v45; // [esp+2Ch] [ebp-94h]
  float v46; // [esp+30h] [ebp-90h]
  float v47; // [esp+34h] [ebp-8Ch]
  int v48; // [esp+38h] [ebp-88h]
  float v49; // [esp+3Ch] [ebp-84h]
  float v50; // [esp+40h] [ebp-80h]
  float v51; // [esp+44h] [ebp-7Ch]
  float v52; // [esp+48h] [ebp-78h]
  float v53; // [esp+4Ch] [ebp-74h]
  float v54; // [esp+50h] [ebp-70h]
  int v55; // [esp+54h] [ebp-6Ch]
  float v56; // [esp+58h] [ebp-68h]
  float v57; // [esp+5Ch] [ebp-64h]
  float v58; // [esp+60h] [ebp-60h]
  float v59; // [esp+64h] [ebp-5Ch]
  float v60; // [esp+68h] [ebp-58h]
  float v61; // [esp+6Ch] [ebp-54h]
  float v62; // [esp+70h] [ebp-50h]
  float v63; // [esp+74h] [ebp-4Ch]
  float v64; // [esp+78h] [ebp-48h]
  float v65[3]; // [esp+7Ch] [ebp-44h] BYREF
  double v66[6]; // [esp+88h] [ebp-38h] BYREF
  int v67; // [esp+B8h] [ebp-8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v8 = (double)a5;
    v44 = 0.0078125 * v8;
    v45 = v8 * 0.015625;
    v35 = *a4 * 0.5;
    v9 = a4[1];
    v38 = v35;
    v36 = v9 * 0.5;
    v10 = a4[2];
    v39 = v36;
    v37 = v10 * 0.5;
    v40 = v37;
    if ( dword_BE1204 == 2 )
      v11 = sub_5210D0(&dword_BE120C) == 5 ? 0.0 : sub_5210C0(&dword_BE120C);
    else
      v11 = dbl_FB1D10;
    v41 = v38 * v11;
    v38 = v41;
    v67 = a6;
    v42 = v39 * v11;
    v39 = v42;
    v43 = v40 * v11;
    v40 = v43;
    v66[0] = *a2;
    v66[1] = a2[1];
    v66[2] = a2[2];
    v66[3] = 0.25;
    v66[4] = 9.999999933815813e36;
    if ( sub_45D210(dbl_B68610, v66, &v35) )
    {
      v47 = v66[5] * v36 + v35 * *a2 + v37 * a2[2];
    }
    else
    {
      v35 = 0.0;
      v36 = 1.0;
      v37 = 0.0;
      v47 = -3.4028235e38;
    }
    result = sub_40DCE0(&dword_91BF20);
    if ( result )
    {
      v12 = (float *)(result + 36);
      v13 = *v12;
      v14 = v12[1];
      v64 = v12[2];
      v62 = v13;
      v63 = v14;
      v15 = dword_BE1204 == 2 ? sub_5210A0(&dword_BE120C) : dbl_FB1D18;
      v16 = *(_DWORD *)(this + 8);
      result = a3 >> v16;
      v46 = v15;
      if ( a3 >> v16 > 0 )
      {
        v48 = a3 >> v16;
        do
        {
          v18 = *(_DWORD *)(this + 96);
          v55 = *(_DWORD *)(this + 104);
          v17 = v55;
          *(_DWORD *)(this + 104) = v55 + 1;
          if ( v17 + 1 >= v18 )
            *(_DWORD *)(this + 104) = 0;
          v19 = *(_DWORD *)(this + 100);
          v20 = 108 * v17;
          v21 = *(_DWORD *)(v19 + v20 + 4);
          v22 = v20 + v19;
          if ( v21 < 0 )
          {
            *(_DWORD *)(v22 + 4) = *(_DWORD *)(this + 108);
            *(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *(_DWORD *)(this + 108)) = v20 + *(_DWORD *)(this + 100);
            v23 = v55;
            ++*(_DWORD *)(this + 108);
            sub_5FCAC0(v23);
          }
          v24 = v46 + *(float *)(v22 + 16);
          *(float *)(v22 + 8) = v46;
          *(float *)(v22 + 12) = v24;
          v25 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
          v41 = v38 * v25;
          v49 = v41;
          v42 = v39 * v25;
          v50 = v42;
          v43 = v40 * v25;
          v51 = v43;
          v26 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
          *(float *)(v22 + 44) = v26 * v44 + *a2 + v41;
          v27 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * v44;
          *(float *)(v22 + 48) = v27 + a2[1] + v50;
          v28 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * v44;
          *(float *)(v22 + 52) = v28 + v51 + a2[2];
          v29 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * v45;
          *(float *)(v22 + 56) = v29 + *a4;
          v30 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * v45;
          *(float *)(v22 + 60) = v30 + a4[1];
          v31 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * v45;
          *(float *)(v22 + 64) = v31 + a4[2];
          *(float *)(v22 + 84) = v35;
          *(float *)(v22 + 88) = v36;
          v32 = v47;
          *(float *)(v22 + 92) = v37;
          *(float *)(v22 + 100) = v32;
          v59 = *(float *)(v22 + 56) - v62;
          v33 = *(float *)(v22 + 60);
          v52 = v59;
          v60 = v33 - v63;
          v34 = *(float *)(v22 + 64);
          v53 = v60;
          v61 = v34 - v64;
          v54 = v61;
          v56 = v59 * 0.03125;
          v65[0] = v56;
          v57 = v60 * 0.03125;
          v65[1] = v57;
          v58 = v61 * 0.03125;
          v65[2] = v58;
          result = sub_542590((float *)this, v22, v65);
          --v48;
        }
        while ( v48 );
      }
    }
  }
  return result;
}
