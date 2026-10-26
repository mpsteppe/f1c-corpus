_DWORD *__fastcall sub_599610(float *a1, float *a2, float *a3, float *a4, float a5, _DWORD *a6)
{
  double v9; // st7
  double v10; // st7
  long double v11; // st7
  _DWORD *result; // eax
  double v14; // st7
  float *v15; // eax
  float v16; // ecx
  float v17; // edx
  float v18; // eax
  float *v19; // eax
  float v20; // ecx
  float v21; // edx
  float v22; // eax
  float v23; // ecx
  float v24; // edx
  float v25; // ecx
  float v26; // edx
  float v27; // eax
  float *v28; // eax
  float v29; // ecx
  float v30; // edx
  float v31; // eax
  float *v32; // eax
  double v33; // st7
  float v34; // ecx
  double v35; // st6
  float v36; // edx
  double v37; // st7
  float v38; // [esp+Ch] [ebp-5Ch]
  float v39; // [esp+Ch] [ebp-5Ch]
  float v40; // [esp+10h] [ebp-58h]
  int v41[3]; // [esp+14h] [ebp-54h] BYREF
  float v42; // [esp+20h] [ebp-48h] BYREF
  int v43; // [esp+24h] [ebp-44h]
  int v44; // [esp+28h] [ebp-40h]
  int v45[3]; // [esp+2Ch] [ebp-3Ch] BYREF
  float v46; // [esp+38h] [ebp-30h]
  float v47; // [esp+3Ch] [ebp-2Ch]
  float v48; // [esp+40h] [ebp-28h]
  float v49; // [esp+44h] [ebp-24h]
  float v50; // [esp+48h] [ebp-20h]
  float v51; // [esp+4Ch] [ebp-1Ch]
  float v52; // [esp+50h] [ebp-18h]
  float v53; // [esp+54h] [ebp-14h]
  float v54; // [esp+58h] [ebp-10h]
  float v55; // [esp+5Ch] [ebp-Ch]
  float v56; // [esp+60h] [ebp-8h]
  float v57; // [esp+64h] [ebp-4h]
  float v58; // [esp+6Ch] [ebp+4h]
  float v59; // [esp+70h] [ebp+8h]
  float v60; // [esp+74h] [ebp+Ch]

  v42 = *a3 - *a1;
  v9 = a3[1];
  *(float *)v41 = v42;
  *(float *)&v43 = v9 - a1[1];
  v10 = a3[2];
  v41[1] = v43;
  *(float *)&v44 = v10 - a1[2];
  v41[2] = v44;
  v11 = sqrt(*(float *)&v44 * *(float *)&v44 + *(float *)&v43 * *(float *)&v43 + v42 * v42);
  v38 = v11;
  if ( v11 <= 0.0 || a5 == 0.0 )
  {
    result = a6;
    *a6 = *(_DWORD *)a1;
    a6[1] = *((_DWORD *)a1 + 1);
    a6[2] = *((_DWORD *)a1 + 2);
  }
  else if ( a5 == 1.0 )
  {
    result = a6;
    *a6 = *(_DWORD *)a3;
    a6[1] = *((_DWORD *)a3 + 1);
    a6[2] = *((_DWORD *)a3 + 2);
  }
  else
  {
    sub_409390(a2);
    sub_409390(a4);
    v14 = a5 * a5;
    v58 = v14;
    v59 = v14 * a5;
    v15 = sub_4012D0(a2, (float *)v41, v38);
    v16 = *v15;
    v17 = v15[1];
    v18 = v15[2];
    v42 = v16;
    *(float *)&v43 = v17;
    *(float *)&v44 = v18;
    v19 = sub_401290(a1, &v42, (float *)v45);
    v20 = v19[1];
    v46 = *v19;
    v21 = v19[2];
    v22 = *a1;
    v47 = v20;
    v23 = a1[1];
    v49 = v22;
    v48 = v21;
    v24 = a1[2];
    v50 = v23;
    v25 = *a3;
    v51 = v24;
    v26 = a3[1];
    v27 = a3[2];
    v52 = v25;
    v53 = v26;
    v54 = v27;
    v28 = sub_4012D0(a4, (float *)v45, v38);
    v29 = *v28;
    v30 = v28[1];
    v31 = v28[2];
    v42 = v29;
    *(float *)&v43 = v30;
    *(float *)&v44 = v31;
    v32 = sub_401250(a3, &v42, (float *)v41);
    v33 = v59 * 3.0;
    v34 = v32[1];
    v35 = a5 * 0.0;
    v55 = *v32;
    v36 = v32[2];
    v56 = v34;
    v57 = v36;
    v40 = v33 - v58 * 5.0 + v35 + 2.0;
    result = a6;
    v39 = v58 * 4.0 - v33 + a5;
    v60 = v58 + v58 - v59 - a5;
    v37 = v59 - v58 + v35;
    *(float *)a6 = (v55 * v37 + v60 * v46 + v39 * v52 + v40 * v49) * 0.5;
    *((float *)a6 + 1) = (v56 * v37 + v60 * v47 + v39 * v53 + v40 * v50) * 0.5;
    *((float *)a6 + 2) = (v37 * v57 + v60 * v48 + v39 * v54 + v40 * v51) * 0.5;
  }
  return result;
}
