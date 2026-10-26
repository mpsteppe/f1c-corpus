int sub_42D2C0()
{
  int result; // eax
  int v1; // eax
  const char *v2; // eax
  int v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  float *v6; // esi
  double v7; // st7
  __int16 v8; // fps
  bool v9; // c0
  char v10; // c2
  bool v11; // c3
  long double v12; // st7
  long double v13; // st6
  int v14; // edx
  long double v15; // st7
  float *v16; // ecx
  double v17; // st6
  __int16 v18; // fps
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c2
  __int16 v21; // fps
  bool v22; // c0
  char v23; // c2
  bool v24; // c3
  long double v25; // st6
  __int16 v26; // fps
  double v27; // st5
  bool v28; // c0
  char v29; // c2
  bool v30; // c3
  long double v31; // st5
  float v32; // [esp+4h] [ebp-1Ch]
  float v33; // [esp+8h] [ebp-18h]
  float v34; // [esp+Ch] [ebp-14h]
  float v35; // [esp+Ch] [ebp-14h]
  int v36; // [esp+10h] [ebp-10h]
  float v37; // [esp+14h] [ebp-Ch]
  float v38; // [esp+18h] [ebp-8h]
  int v39; // [esp+1Ch] [ebp-4h]
  float v40; // [esp+1Ch] [ebp-4h]

  v33 = 0.19499999;
  v37 = 2.0;
  v38 = 2.0;
  result = sub_616840("Drafting");
  if ( result )
  {
    v1 = sub_616630("BaseDropoff");
    if ( v1 )
    {
      v2 = (const char *)sub_48D380(v1);
      v33 = atof(v2);
    }
    v3 = sub_616630("LeadingExponent");
    if ( v3 )
    {
      v4 = (const char *)sub_48D380(v3);
      v37 = atof(v4);
    }
    result = sub_616630("FollowingExponent");
    if ( result )
    {
      v5 = (const char *)sub_48D380(result);
      v38 = atof(v5);
    }
  }
  v36 = 0;
  v6 = &flt_91E240;
  do
  {
    v7 = (double)v36;
    v34 = v7;
    v32 = 0.06666667 * v7 + 1.0;
    v9 = v7 < 25.002501;
    v10 = 0;
    v11 = v7 == 25.002501;
    LOWORD(result) = v8;
    if ( v7 >= 25.002501 )
    {
      v12 = 1.0 - (v34 - 25.002501) * 0.0089287711;
      v13 = v38;
    }
    else
    {
      v12 = 1.0 - (25.002501 - v34) * 0.039995998;
      v13 = v37;
    }
    v14 = 0;
    v15 = pow(v12, v13) * v33;
    v39 = 0;
    v16 = v6;
    do
    {
      if ( v6 == (float *)&unk_920440 || v14 == 15 )
        goto LABEL_24;
      v17 = (double)v39;
      v35 = v17;
      LOWORD(result) = v18;
      if ( v19 | v20 )
      {
        *v16 = (1.0 - v17 / v32) * v15;
        goto LABEL_25;
      }
      v40 = v32 + 5.0;
      v22 = v17 < v40;
      v23 = 0;
      v24 = v17 == v40;
      LOWORD(result) = v21;
      if ( v17 >= v40 )
      {
LABEL_24:
        *v16 = 0.0;
      }
      else
      {
        v25 = v15 / v32 * 3.0;
        if ( v25 > v15 )
          v25 = v15;
        v27 = v32 + 2.5;
        v28 = v27 < v35;
        v29 = 0;
        v30 = v27 == v35;
        LOWORD(result) = v26;
        if ( v27 <= v35 )
          v31 = (v40 - v35) * v25 * -0.40000001;
        else
          v31 = (v35 - v32) * v25 * -0.40000001;
        *v16 = v31;
      }
LABEL_25:
      ++v14;
      ++v16;
      v39 = v14;
    }
    while ( v14 < 16 );
    v6 += 16;
    ++v36;
  }
  while ( (int)v6 < (int)&dword_920480 );
  return result;
}
