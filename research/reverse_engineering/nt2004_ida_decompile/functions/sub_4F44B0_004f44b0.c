void __thiscall sub_4F44B0(float *this, float *a2, int a3, float *a4, int a5, int a6, int a7, float a8)
{
  double v9; // st7
  double v10; // st7
  int *v11; // eax
  double v12; // st7
  int v13; // ebp
  int v14; // eax
  double v16; // st7
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c3
  double v19; // st7
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st6
  float v29; // [esp+10h] [ebp-98h]
  float v30; // [esp+14h] [ebp-94h]
  float v31; // [esp+18h] [ebp-90h]
  float v32; // [esp+18h] [ebp-90h]
  float v33; // [esp+1Ch] [ebp-8Ch]
  float v34; // [esp+1Ch] [ebp-8Ch]
  float v35; // [esp+20h] [ebp-88h]
  float v36; // [esp+20h] [ebp-88h]
  float v37; // [esp+24h] [ebp-84h]
  float v38; // [esp+28h] [ebp-80h] BYREF
  float v39; // [esp+2Ch] [ebp-7Ch]
  float v40; // [esp+30h] [ebp-78h]
  float v41; // [esp+34h] [ebp-74h]
  float v42; // [esp+38h] [ebp-70h] BYREF
  float v43; // [esp+3Ch] [ebp-6Ch]
  float v44; // [esp+40h] [ebp-68h]
  float v45; // [esp+44h] [ebp-64h]
  float v46; // [esp+48h] [ebp-60h]
  float v47; // [esp+4Ch] [ebp-5Ch]
  float v48[4]; // [esp+50h] [ebp-58h] BYREF
  float v49; // [esp+60h] [ebp-48h]
  float v50; // [esp+64h] [ebp-44h]
  double v51[3]; // [esp+68h] [ebp-40h] BYREF
  int v52; // [esp+80h] [ebp-28h]
  int v53; // [esp+84h] [ebp-24h]
  int v54; // [esp+88h] [ebp-20h]
  int v55; // [esp+8Ch] [ebp-1Ch]
  double v56; // [esp+90h] [ebp-18h]
  int v57; // [esp+98h] [ebp-10h]
  float v58; // [esp+A4h] [ebp-4h]

  if ( *((int *)this + 24) > 0 )
  {
    v9 = (double)a5;
    v37 = 0.0078125 * v9;
    v30 = v9 * 0.015625;
    v31 = *a4 * 0.5;
    v33 = a4[1] * 0.5;
    v35 = a4[2] * 0.5;
    if ( dword_7D5DA4 == 2 )
      v10 = sub_4DA080(&dword_7D5DAC) == 5 ? 0.0 : sub_4D9E30(&dword_7D5DAC);
    else
      v10 = dbl_7DA9C8;
    v45 = v31 * v10;
    v52 = 0;
    v53 = 1070596096;
    v46 = v33 * v10;
    v54 = 0x40000000;
    v55 = 1201543096;
    v57 = a6;
    v47 = v35 * v10;
    v51[0] = *a2;
    v51[1] = a2[1];
    v51[2] = a2[2];
    if ( sub_44E990(dbl_760B48, v51, &v38) )
    {
      v41 = v56 * v39 + v40 * a2[2] + v38 * *a2;
    }
    else
    {
      v38 = 0.0;
      v39 = 1.0;
      v40 = 0.0;
      v41 = -3.4028235e38;
    }
    v11 = (int *)sub_40C460(&dword_6291CC);
    if ( v11 )
    {
      sub_459BE0(v11, &v42);
    }
    else
    {
      v42 = 0.0;
      v43 = 0.0;
      v44 = 0.0;
    }
    v12 = dword_7D5DA4 == 2 ? sub_4D9E20(&dword_7D5DAC) : dbl_7DA9D0;
    v13 = a3 >> *((_DWORD *)this + 2);
    v29 = v12;
    if ( v13 > 0 )
    {
      do
      {
        v14 = sub_4F2AE0(this);
        v16 = v29;
        *(float *)(v14 + 8) = v29;
        if ( v17 | v18 )
          v19 = v16 + *(float *)(v14 + 16);
        else
          v19 = v16 + a8;
        *(float *)(v14 + 12) = v19;
        v20 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v49 = v20 * v46;
        v50 = v20 * v47;
        v21 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        *(float *)(v14 + 44) = v21 * v37 + v45 * v20 + *a2;
        v22 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        *(float *)(v14 + 48) = v22 * v37 + a2[1] + v49;
        v23 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        *(float *)(v14 + 52) = v23 * v37 + a2[2] + v50;
        v24 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        *(float *)(v14 + 56) = v24 * v30 + *a4;
        v25 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * v30;
        *(float *)(v14 + 60) = v25 + a4[1];
        v26 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        *(float *)(v14 + 64) = v26 * v30 + a4[2];
        *(float *)(v14 + 84) = v38;
        *(float *)(v14 + 88) = v39;
        *(float *)(v14 + 92) = v40;
        *(float *)(v14 + 100) = v41;
        *(_DWORD *)(v14 + 96) ^= (a7 ^ *(_DWORD *)(v14 + 96)) & 0xFFFFFF;
        v27 = *(float *)(v14 + 56) - v42;
        v28 = *(float *)(v14 + 60) - v43;
        v58 = *(float *)(v14 + 64) - v44;
        v32 = v27 * 0.03125;
        v48[0] = v32;
        v34 = v28 * 0.03125;
        v48[1] = v34;
        v36 = v58 * 0.03125;
        v48[2] = v36;
        sub_4F3B10(this, (float *)v14, v48);
        --v13;
      }
      while ( v13 );
    }
  }
}
