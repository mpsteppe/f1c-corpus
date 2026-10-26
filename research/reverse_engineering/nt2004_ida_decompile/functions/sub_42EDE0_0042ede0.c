size_t sub_42EDE0()
{
  signed int v0; // edi
  float *v1; // ecx
  int v2; // edx
  double v3; // st7
  int v4; // edx
  float *v5; // esi
  double v6; // st5
  float *v7; // eax
  int v8; // ebx
  double v9; // st7
  double v10; // st7
  double v11; // st7
  long double v12; // st6
  long double v13; // st5
  double v15; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  size_t result; // eax
  signed int v19; // edx
  signed int v20; // ecx
  signed int v21; // ebp
  int v22; // eax
  int v23; // ebp
  float *v24; // ebx
  char v26; // c0
  long double v27; // st7
  long double v28; // st7
  double v29; // st6
  double v30; // st4
  long double v31; // st7
  int v32; // esi
  int v33; // eax
  int v34; // edi
  double v35; // st7
  long double v36; // st7
  float *v37; // ecx
  long double v38; // st7
  float v39; // [esp+1Ch] [ebp-884h]
  float v40; // [esp+1Ch] [ebp-884h]
  float v41; // [esp+1Ch] [ebp-884h]
  float v42; // [esp+1Ch] [ebp-884h]
  float v43; // [esp+20h] [ebp-880h]
  float v44; // [esp+20h] [ebp-880h]
  float v45; // [esp+24h] [ebp-87Ch]
  float v46; // [esp+24h] [ebp-87Ch]
  float v47; // [esp+28h] [ebp-878h]
  float v48; // [esp+28h] [ebp-878h]
  float v49; // [esp+2Ch] [ebp-874h]
  float v50; // [esp+2Ch] [ebp-874h]
  float v51; // [esp+30h] [ebp-870h]
  float v52; // [esp+30h] [ebp-870h]
  float v53; // [esp+34h] [ebp-86Ch]
  float v54; // [esp+38h] [ebp-868h]
  float v55; // [esp+38h] [ebp-868h]
  signed int j; // [esp+3Ch] [ebp-864h]
  float v57; // [esp+40h] [ebp-860h]
  float v58; // [esp+48h] [ebp-858h]
  float v59; // [esp+4Ch] [ebp-854h]
  signed int i; // [esp+50h] [ebp-850h]
  _BYTE v61[32]; // [esp+68h] [ebp-838h] BYREF
  char v62; // [esp+88h] [ebp-818h] BYREF

  v0 = 0;
  if ( (int)NumOfElements > 0 )
  {
    v1 = (float *)&v62;
    do
    {
      v2 = dword_75AAD0[v0];
      v3 = *(float *)(v2 + 17636);
      v4 = v2 + 84;
      v5 = (float *)(v4 + 17520);
      v6 = *(float *)(v4 + 17544) * *(float *)(v4 + 17544);
      v7 = v1 - 10;
      *v7 = *(float *)(v4 + 17520);
      v8 = *(_DWORD *)(v4 + 17528);
      v7[1] = *(float *)(v4 + 17524);
      v47 = v6 + v3 * v3;
      *((_DWORD *)v7 + 2) = v8;
      v43 = sqrt(v47);
      *(v1 - 7) = v43;
      v45 = sqrt(v43) * 0.82499999;
      v9 = v43 * 1.39;
      v39 = v9;
      *(v1 - 6) = v9 * v39 + v45 * v45;
      if ( v43 != 0.0 )
      {
        if ( v45 == 0.0 )
          *(v1 - 5) = 0.0;
        else
          *(v1 - 5) = 16.0 / v45;
        if ( v39 == 0.0 )
          *(v1 - 4) = 0.0;
        else
          *(v1 - 4) = 128.0 / v39;
        v10 = 1.0 / v43;
        v40 = v10 * *(float *)(v4 + 17544);
        v11 = v10 * *(float *)(v4 + 17552);
        v12 = (v11 * *(float *)(v4 + 17616) - v40 * *(float *)(v4 + 17624)) * 0.25;
        if ( v12 == 0.0 || (v13 = v47 / fabs(v12), *v1 = v13, v13 > 1000000.0) )
          *v1 = 1000000.0;
        v15 = v11 * *v1;
        if ( v16 | v17 )
        {
          *(v1 - 2) = *v5 - v15;
          *(v1 - 1) = v40 * *v1 + *(float *)(v4 + 17528);
          *(v1 - 7) = -v43;
        }
        else
        {
          *(v1 - 2) = v15 + *v5;
          *(v1 - 1) = *(float *)(v4 + 17528) - v40 * *v1;
        }
        *(v1 - 3) = atan2(*v5 - *(v1 - 2), *(float *)(v4 + 17528) - *(v1 - 1));
      }
      ++v0;
      v1 += 11;
    }
    while ( v0 < (int)NumOfElements );
  }
  result = NumOfElements;
  v19 = 0;
  for ( i = 0; v19 < (int)NumOfElements; i = v19 )
  {
    v57 = *(float *)(dword_75AAD0[v19] + 17604);
    v58 = *(float *)(dword_75AAD0[v19] + 17612);
    v51 = 0.0;
    v54 = 0.0;
    v44 = 0.0;
    v48 = 0.0;
    v20 = 0;
    for ( j = v19; ; j = NumOfElements )
    {
      v21 = j;
      if ( v20 < j )
      {
        v22 = 44 * v20;
        v23 = j - v20;
        v20 = j;
        v24 = (float *)&v61[v22];
        do
        {
          if ( v26 )
          {
            v46 = atan2(v57 - v24[6], v58 - v24[7]);
            if ( v24[1] <= 0.0 )
              v27 = v46 - v24[5];
            else
              v27 = v24[5] - v46;
            if ( fabs(v27) > 3.1415927 )
            {
              if ( v27 < 0.0 )
                v27 = v27 + 6.2831855;
              else
                v27 = v27 - 6.2831855;
            }
            v28 = v27 * v24[8] * v24[4] + 16.0;
            v41 = v28;
            if ( v28 >= 0.0 && v41 < 127.0 )
            {
              v29 = v24[7] - v58;
              v30 = v24[6] - v57;
              v31 = fabs(v24[8] - sqrt(v29 * v29 + v30 * v30)) * v24[3];
              v59 = v31;
              if ( v31 < 15.0 )
              {
                v49 = floor(v41);
                v42 = v41 - v49;
                v32 = (int)v49;
                v50 = floor(v59);
                v33 = (int)v50;
                v34 = 16 * (v32 + 1);
                v32 *= 16;
                v19 = i;
                v35 = (flt_75ABA8[v34 + v33] - flt_75ABA8[v33 + v32]) * v42 + flt_75ABA8[v33 + v32];
                v20 = j;
                v36 = (v35
                     + ((flt_75ABA8[v34 + 1 + v33] - flt_75ABA8[v33 + 1 + v32]) * v42 + flt_75ABA8[v33 + 1 + v32] - v35)
                     * (v59 - v50))
                    * v24[1];
                v51 = cos(v46) * v36 + v51;
                v54 = v54 - sin(v46) * v36;
                v44 = fabs(v36) + v44;
                v48 = v36 * v36 + v48;
              }
            }
          }
          v24 += 11;
          --v23;
        }
        while ( v23 );
        v21 = j;
      }
      if ( v21 != v19 )
        break;
      ++v20;
    }
    if ( v44 > 0.0 )
    {
      v37 = (float *)(dword_75AAD0[v19] + 19016);
      v38 = sqrt(v48) / v44;
      v52 = v51 * v38;
      *v37 = v52;
      v53 = 0.0 * v38;
      v37[1] = v53;
      v55 = v38 * v54;
      v37[2] = v55;
    }
    result = NumOfElements;
    ++v19;
  }
  return result;
}
