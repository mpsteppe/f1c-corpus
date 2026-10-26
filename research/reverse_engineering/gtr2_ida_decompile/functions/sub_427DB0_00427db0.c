char __thiscall sub_427DB0(char *this)
{
  float *v2; // ebx
  float *v3; // edi
  int v4; // eax
  int v5; // eax
  float *v6; // ebp
  double v7; // st7
  double v8; // st6
  int v9; // eax
  int v11; // eax
  int v12; // edx
  char *v13; // ebp
  int *v14; // edi
  int v15; // eax
  double v16; // st7
  int v17; // ecx
  double v18; // st7
  double v19; // st7
  double v20; // st7
  int v21; // edx
  double v22; // st6
  double v23; // st6
  int v24; // edi
  int v25; // ecx
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st4
  int v30; // ebx
  double v31; // st7
  long double v32; // st7
  double v33; // st7
  long double v34; // st7
  long double v35; // st7
  float *v36; // eax
  long double v37; // st7
  double v38; // st6
  double v39; // st5
  long double v40; // st4
  long double v41; // st7
  long double v42; // st7
  double v43; // st7
  int v44; // ecx
  int v45; // ecx
  int v46; // ecx
  int v47; // ecx
  int v48; // ecx
  double v49; // st7
  int v50; // [esp-8h] [ebp-58h]
  float v51; // [esp+10h] [ebp-40h]
  float v52; // [esp+10h] [ebp-40h]
  float v53; // [esp+14h] [ebp-3Ch]
  float v54; // [esp+18h] [ebp-38h]
  int v55; // [esp+1Ch] [ebp-34h]
  float v56; // [esp+1Ch] [ebp-34h]
  float v57; // [esp+20h] [ebp-30h]
  float v58; // [esp+20h] [ebp-30h]
  float v59; // [esp+20h] [ebp-30h]
  float v60; // [esp+2Ch] [ebp-24h]
  float v61; // [esp+34h] [ebp-1Ch]
  float v62; // [esp+38h] [ebp-18h]
  float v63; // [esp+40h] [ebp-10h]
  float v64; // [esp+44h] [ebp-Ch]
  float v65; // [esp+4Ch] [ebp-4h]

  v2 = (float *)*((_DWORD *)this + 5046);
  v3 = (float *)(this + 15988);
  *((float *)this + 5119) = sqrt(
                              *((float *)this + 4003) * *((float *)this + 4003)
                            + *((float *)this + 4004) * *((float *)this + 4004)
                            + *((float *)this + 4005) * *((float *)this + 4005));
  if ( !v2 )
  {
    v4 = sub_4031C0();
    *((_DWORD *)this + 5046) = v4;
    if ( v4 )
    {
LABEL_5:
      v6 = (float *)*((_DWORD *)this + 5046);
      v2 = v6;
      goto LABEL_13;
    }
    v5 = sub_4031C0();
    *((_DWORD *)this + 5046) = v5;
    if ( v5 )
    {
      *((_DWORD *)this + 5213) = 0;
      goto LABEL_5;
    }
    return 0;
  }
  v7 = *v3 - v2[38];
  v8 = *((float *)this + 3999) - v2[40];
  if ( v8 * v8 + v7 * v7 > 3200.0 )
  {
    v9 = sub_4031C0();
    *((_DWORD *)this + 5046) = v9;
    if ( !v9 )
      return 0;
    v2 = (float *)v9;
    this[20580] = 1;
  }
  v6 = (float *)*((_DWORD *)this + 5046);
  if ( v6[6] * (v6[40] - *((float *)this + 3999)) + v6[4] * (v6[38] - *v3) >= 0.0 )
    goto LABEL_14;
  v2 = (float *)*((_DWORD *)this + 5046);
  if ( *(float *)(*((_DWORD *)this + 5047) + 76) < (double)v6[19] )
    ++*((_DWORD *)this + 5125);
LABEL_13:
  this[20580] = 1;
LABEL_14:
  if ( !this[20580] )
  {
    if ( !this[19652] )
      return 1;
    goto LABEL_43;
  }
  v11 = *((_DWORD *)v6 + 19);
  v12 = *((_DWORD *)this + 5047);
  v50 = *((_DWORD *)this + 5213);
  v13 = this + 20188;
  *((_DWORD *)this + 5123) = v11;
  *((_DWORD *)this + 5046) = sub_403390((float *)this + 3997, v12, v50, 1);
  v14 = (int *)(this + 20188);
  v55 = 19;
  do
  {
    *v14++ = sub_4209D0();
    --v55;
  }
  while ( v55 );
  v15 = *((_DWORD *)this + 5213);
  if ( v15 || *(_DWORD *)(*(_DWORD *)v13 + 304) != 1 )
  {
    if ( v15 == 1 && !*(_DWORD *)(*(_DWORD *)v13 + 304) )
      sub_4FB0C0(this, 0, 0);
  }
  else
  {
    sub_427C40((int)this, 14, *((_DWORD *)this + 5213));
    sub_4FB0C0(this, 1, 1);
  }
  v16 = *((float *)this + 5180);
  v17 = *(_DWORD *)(*(_DWORD *)v13 + 304);
  v6 = (float *)*((_DWORD *)this + 5046);
  *((_DWORD *)this + 5213) = v17;
  v18 = v16 * v6[36] + *((float *)this + 5179);
  if ( v18 <= 75.0 )
  {
    if ( v17 == 1 )
      v18 = *(float *)&dword_FADE50;
    v19 = *((float *)this + 5119) / v18;
    *((float *)this + 5120) = v19;
    if ( v19 <= 1.0 )
      goto LABEL_34;
  }
  else if ( !*((_DWORD *)this + 5087) )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 14820) )
      *((_DWORD *)this + 5120) = *((_DWORD *)this + 5116);
    else
      *((_DWORD *)this + 5120) = *((_DWORD *)this + 4037);
    goto LABEL_34;
  }
  *((_DWORD *)this + 5120) = 1065353216;
LABEL_34:
  *((float *)this + 5124) = (double)*((int *)this + 5125) * flt_91BDE4 + *((float *)this + 5123);
  if ( *((float *)this + 5119) >= 15.0 || *((_DWORD *)this + 5213) == 1 )
  {
    if ( *((float *)this + 5119) >= 30.0 )
    {
      if ( *((float *)this + 5119) >= 65.0 )
        *((_DWORD *)this + 5136) = 4;
      else
        *((_DWORD *)this + 5136) = 3;
    }
    else
    {
      *((_DWORD *)this + 5136) = 2;
    }
  }
  else
  {
    *((_DWORD *)this + 5136) = 1;
  }
  v20 = v6[38] - *((float *)this + 3997);
  v21 = *((_DWORD *)this + 3999);
  v22 = v6[40];
  *((_DWORD *)this + 5149) = *((_DWORD *)this + 3997);
  v23 = v22 - *((float *)this + 3999);
  *((_DWORD *)this + 5151) = v21;
  *((float *)this + 5086) = sqrt(v23 * v23 + v20 * v20);
LABEL_43:
  v24 = *((_DWORD *)this + 5136);
  if ( *(_DWORD *)&this[4 * v24 + 20184] )
  {
    v25 = *((_DWORD *)this + 5047);
    v26 = v2[38] - *((float *)this + 3997);
    v27 = v2[40] - *((float *)this + 3999);
    v28 = v2[9];
    v29 = v2[11];
    v30 = *((_DWORD *)this + 4607);
    *((_DWORD *)this + 5199) = 1065353216;
    *((_DWORD *)this + 5198) = 1065353216;
    *((float *)this + 5112) = -(v29 * v27 + v28 * v26);
    v31 = (1.0 - *((float *)this + 5120)) * 0.15000001 + *(float *)(v25 + 4 * v24 + 192);
    v53 = v31;
    v54 = v31 + *((float *)this + 4001);
    v56 = *((float *)this + 4001) - v31;
    if ( v30 != 2 || *((float *)this + 4299) > 0.001 )
    {
      if ( *(float *)(v25 + 4 * v24 + 192) > 0.02421 )
      {
        v32 = *(float *)(*((_DWORD *)this + 5050) + 188) - v6[47];
        if ( fabs(v32) >= 3.141592653589793 )
        {
          if ( v32 >= 0.0 )
            v32 = v32 - 6.2831855;
          else
            v32 = v32 + 6.2831855;
        }
        if ( v32 <= 0.0 )
        {
          *((_DWORD *)this + 5199) = -1082130432;
          v33 = *(float *)(v25 + 188) - *(float *)(v25 + 4 * v24 + 192);
        }
        else
        {
          *((_DWORD *)this + 5198) = -1082130432;
          v33 = *(float *)(v25 + 188) + *(float *)(v25 + 4 * v24 + 192);
        }
        v51 = v33;
      }
      else
      {
        v51 = *(float *)(v25 + 188);
      }
      if ( *(_DWORD *)(*(_DWORD *)this + 14820) != 1 )
        return 1;
      v34 = v54 - v51;
      if ( fabs(v34) >= 3.141592653589793 )
      {
        if ( v34 >= 0.0 )
          v34 = v34 - 6.2831855;
        else
          v34 = v34 + 6.2831855;
      }
      if ( v34 > v53 && v30 != 2 && *((float *)this + 4299) > 0.001 )
      {
        if ( sub_41FE80(v51, *((float *)this + 4001)) <= v53 )
          v54 = v51 + v53;
        else
          v54 = *((float *)this + 4001);
      }
      v35 = v56 - v51;
      if ( fabs(v35) >= 3.141592653589793 )
      {
        if ( v35 >= 0.0 )
          v35 = v35 - 6.2831855;
        else
          v35 = v35 + 6.2831855;
      }
      if ( v35 < -v53 && v30 != 2 && *((float *)this + 4299) > 0.001 )
      {
        if ( sub_41FE80(*((float *)this + 4001), v51) <= v53 )
          v56 = v51 - v53;
        else
          v56 = *((float *)this + 4001);
      }
    }
    v36 = *(float **)&this[4 * v24 + 20184];
    v62 = v36[38];
    v61 = *((float *)this + 3999);
    v63 = v36[40];
    v57 = -sin(v54);
    v37 = -cos(v54);
    v38 = v36[9];
    v39 = v36[11];
    v60 = *((float *)this + 3997);
    v40 = 1.0 / sqrt(v39 * v39 + v38 * v38);
    v64 = v40 * v38;
    v65 = v40 * v39;
    if ( v57 == 0.0 )
      *((_DWORD *)this + 5107) = 0;
    else
      *((float *)this + 5107) = (v62 * (v37 / v57) + v61 - v60 * (v37 / v57) - v63) / (v65 - v64 * (v37 / v57));
    v58 = -sin(v56);
    v41 = -cos(v56);
    if ( v58 == 0.0 )
      *((_DWORD *)this + 5108) = 0;
    else
      *((float *)this + 5108) = (v62 * (v41 / v58) + v61 - v60 * (v41 / v58) - v63) / (v65 - v64 * (v41 / v58));
    v59 = -sin(*((float *)this + 4001));
    v42 = -cos(*((float *)this + 4001));
    if ( v59 == 0.0 )
      *((_DWORD *)this + 5109) = 0;
    else
      *((float *)this + 5109) = (v62 * (v42 / v59) + v61 - v60 * (v42 / v59) - v63) / (v65 - v64 * (v42 / v59));
    if ( v30 != 2 && *((float *)this + 4299) > 0.001 )
    {
      v43 = v6[21];
      v44 = *((_DWORD *)this + 5047);
      v52 = v6[22];
      if ( v52 >= (double)*(float *)(v44 + 88) )
        v52 = *(float *)(v44 + 88);
      if ( v43 >= *(float *)(v44 + 84) )
        v43 = *(float *)(v44 + 84);
      v45 = *((_DWORD *)this + 5048);
      if ( v52 >= (double)*(float *)(v45 + 88) )
        v52 = *(float *)(v45 + 88);
      if ( v43 >= *(float *)(v45 + 84) )
        v43 = *(float *)(v45 + 84);
      v46 = *((_DWORD *)this + 5049);
      if ( v52 >= (double)*(float *)(v46 + 88) )
        v52 = *(float *)(v46 + 88);
      if ( v43 >= *(float *)(v46 + 84) )
        v43 = *(float *)(v46 + 84);
      v47 = *((_DWORD *)this + 5050);
      if ( v52 >= (double)*(float *)(v47 + 88) )
        v52 = *(float *)(v47 + 88);
      if ( v43 >= *(float *)(v47 + 84) )
        v43 = *(float *)(v47 + 84);
      v48 = *((_DWORD *)this + 5051);
      if ( v52 >= (double)*(float *)(v48 + 88) )
        v52 = *(float *)(v48 + 88);
      if ( v43 >= *(float *)(v48 + 84) )
        v43 = *(float *)(v48 + 84);
      if ( *((float *)this + 5107) > (double)v52 )
      {
        if ( v52 <= (double)*((float *)this + 5108) )
          *((_DWORD *)this + 5107) = *((_DWORD *)this + 5108);
        else
          *((float *)this + 5107) = v52;
      }
      v49 = -v43;
      if ( v49 > *((float *)this + 5108) )
      {
        if ( v49 < *((float *)this + 5107) )
        {
          *((float *)this + 5108) = v49;
          this[19652] = 0;
          return 1;
        }
        *((_DWORD *)this + 5108) = *((_DWORD *)this + 5107);
      }
    }
    this[19652] = 0;
  }
  return 1;
}
