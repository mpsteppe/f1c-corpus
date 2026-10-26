int __thiscall sub_47AF50(float *this, int a2)
{
  int v2; // ebx
  float v3; // esi
  float v4; // edi
  float v5; // eax
  int v6; // ebx
  int v7; // ebp
  int v8; // edx
  double v9; // st7
  double v10; // st7
  long double v11; // st5
  long double v12; // st7
  float *v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  float *v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  float v21; // edx
  float v22; // eax
  float *v23; // eax
  int v24; // ecx
  int result; // eax
  float v26; // eax
  int v27; // edx
  float v28; // ecx
  float *v29; // ebx
  float v30; // edx
  float v31; // [esp+20h] [ebp-80h]
  float v32; // [esp+24h] [ebp-7Ch]
  int v33; // [esp+28h] [ebp-78h] BYREF
  float v34; // [esp+2Ch] [ebp-74h]
  int v35; // [esp+30h] [ebp-70h]
  float v36; // [esp+34h] [ebp-6Ch]
  float v37; // [esp+38h] [ebp-68h]
  float v38; // [esp+3Ch] [ebp-64h]
  float v39[5]; // [esp+40h] [ebp-60h] BYREF
  float v40; // [esp+54h] [ebp-4Ch]
  int v41; // [esp+58h] [ebp-48h]
  int v42; // [esp+5Ch] [ebp-44h]
  int v43; // [esp+60h] [ebp-40h]
  int v44; // [esp+64h] [ebp-3Ch] BYREF
  float v45; // [esp+68h] [ebp-38h]
  float v46; // [esp+6Ch] [ebp-34h]
  int v47; // [esp+70h] [ebp-30h] BYREF
  float v48; // [esp+74h] [ebp-2Ch]
  float v49; // [esp+78h] [ebp-28h]
  int v50; // [esp+7Ch] [ebp-24h] BYREF
  int v51; // [esp+80h] [ebp-20h]
  int v52; // [esp+84h] [ebp-1Ch]
  float v53[6]; // [esp+88h] [ebp-18h] BYREF

  v31 = dbl_FB1D10;
  v2 = (unsigned __int8)*(_DWORD *)a2;
  if ( dbl_FB1D10 >= 0.0 )
  {
    if ( v31 > 0.033333335 )
      v31 = 0.033333335;
  }
  else
  {
    v31 = 0.0;
  }
  v35 = a2 + 36;
  v3 = *(float *)(a2 + 36);
  v4 = *(float *)(a2 + 40);
  v5 = *(float *)(a2 + 44);
  v6 = (int)&this[14 * v2 + 75692];
  v7 = v6 + 8;
  v39[3] = v3;
  v40 = v5;
  v39[4] = v4;
  v8 = *(_DWORD *)(a2 + 844);
  *(float *)&v47 = v3 - *(float *)(v6 + 8);
  v44 = v47;
  v48 = v4 - *(float *)(v6 + 12);
  v45 = v48;
  v49 = v5 - *(float *)(v6 + 16);
  v9 = 1.0 / v31;
  v36 = *(float *)&v47 * v9;
  v44 = LODWORD(v36);
  v37 = v48 * v9;
  v45 = v37;
  v38 = v49 * v9;
  v46 = v38;
  v32 = *(float *)&dword_B736B4;
  v34 = flt_B735A0 - *(float *)&dword_B736B4;
  if ( sub_47AC90(this + 73173, v8, (int)&v33, 1) && *(float *)&v33 > (double)v32 && v34 > 0.0 )
  {
    v10 = (*(float *)&v33 - v32) / v34;
    if ( v10 >= 1.0 )
      v10 = 1.0;
    v11 = (flt_B736FC - flt_B736D8) * (1.0 - v10) + flt_B736D8;
    if ( fabs(v11 - *(float *)v6) > 5.0 )
    {
      *(float *)v6 = v11;
      v12 = sqrt(v11);
      *(float *)(v6 + 4) = v12 * flt_B73720 + v12 * flt_B73720;
    }
    v13 = sub_4012D0((float *)(v6 + 44), (float *)&v47, v31);
    v14 = *(_DWORD *)v13;
    v15 = *((_DWORD *)v13 + 1);
    v16 = *((_DWORD *)v13 + 2);
    v50 = v14;
    v51 = v15;
    v52 = v16;
    v17 = sub_401250((float *)(v6 + 32), (float *)&v50, v39);
    v18 = *((_DWORD *)v17 + 1);
    v41 = *(_DWORD *)v17;
    v19 = *((_DWORD *)v17 + 2);
    v42 = v18;
    v20 = *(int *)(v6 + 44);
    v43 = v19;
    v21 = *(float *)(v6 + 48);
    v22 = *(float *)(v6 + 52);
    v47 = v20;
    v48 = v21;
    v49 = v22;
    v33 = v6 + 20;
    v23 = sub_401290((float *)&v44, (float *)(v6 + 20), v53);
    v24 = *((_DWORD *)v23 + 1);
    v50 = *(_DWORD *)v23;
    v51 = v24;
    return off_16C9660(a2);
  }
  else
  {
    v26 = v40;
    *(float *)(v6 + 32) = v3;
    *(float *)(v6 + 36) = v4;
    v27 = v6 + 44;
    *(float *)(v6 + 40) = v26;
    *(float *)(v6 + 44) = v36;
    *(float *)(v6 + 48) = v37;
    v28 = v38;
    *(float *)v7 = v3;
    *(float *)(v6 + 12) = v4;
    v29 = (float *)(v6 + 20);
    *(float *)(v27 + 8) = v28;
    v30 = v36;
    *(float *)(v7 + 8) = v26;
    result = LODWORD(v37);
    *v29 = v30;
    *((_DWORD *)v29 + 1) = result;
    v29[2] = v28;
  }
  return result;
}
