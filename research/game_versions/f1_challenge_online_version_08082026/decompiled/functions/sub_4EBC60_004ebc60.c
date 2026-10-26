char __thiscall sub_4EBC60(void *this, float *a2, char a3)
{
  float *v5; // ebp
  float *v6; // eax
  float v7; // ecx
  float v8; // edx
  double v9; // st7
  float *v10; // edi
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st7
  int v18; // eax
  _WORD *v19; // ebp
  float *v20; // eax
  double v22; // [esp+8h] [ebp-74h]
  double v23; // [esp+10h] [ebp-6Ch]
  float v24; // [esp+14h] [ebp-68h]
  float v25; // [esp+28h] [ebp-54h] BYREF
  float v26; // [esp+2Ch] [ebp-50h]
  float v27; // [esp+30h] [ebp-4Ch]
  int v28; // [esp+34h] [ebp-48h] BYREF
  float v29; // [esp+38h] [ebp-44h]
  float v30; // [esp+3Ch] [ebp-40h]
  double v31; // [esp+40h] [ebp-3Ch] BYREF
  float v32; // [esp+48h] [ebp-34h]
  float v33[2]; // [esp+58h] [ebp-24h] BYREF
  float v34; // [esp+60h] [ebp-1Ch]
  int v35[2]; // [esp+64h] [ebp-18h] BYREF
  double v36; // [esp+6Ch] [ebp-10h]
  double v37; // [esp+74h] [ebp-8h]
  float v38; // [esp+80h] [ebp+4h]

  v5 = a2 + 5;
  v6 = sub_4EA930(a2 + 5, (float *)this + 3381, v33);
  v7 = *v6;
  v8 = v6[1];
  v27 = v6[2];
  v9 = v27 * *((float *)this + 3378);
  v26 = v8;
  v25 = v7;
  v10 = a2 + 8;
  *(float *)&v28 = v9 + v8 * *((float *)this + 3375) + v7 * *((float *)this + 3372);
  v29 = v27 * *((float *)this + 3379) + v8 * *((float *)this + 3376) + v7 * *((float *)this + 3373);
  v30 = v27 * *((float *)this + 3380) + v8 * *((float *)this + 3377) + v7 * *((float *)this + 3374);
  v11 = *((float *)this + 3378) * a2[10] + *((float *)this + 3375) * a2[9] + a2[8] * *((float *)this + 3372);
  v12 = *((float *)this + 3373) * a2[8] + *((float *)this + 3379) * a2[10] + *((float *)this + 3376) * a2[9];
  v38 = a2[1];
  v34 = *((float *)this + 3374) * a2[8] + *((float *)this + 3380) * a2[10] + *((float *)this + 3377) * a2[9];
  v25 = v38 * v11;
  v33[0] = v25;
  v26 = v12 * v38;
  v33[1] = v26;
  v27 = v34 * v38;
  v13 = *((float *)this + 3398);
  v34 = v27;
  *((float *)&v31 + 1) = v26 * v13;
  v32 = v27 * v13;
  *((float *)this + 3390) = v25 * v13 + *((float *)this + 3390);
  *((float *)this + 3391) = *((float *)&v31 + 1) + *((float *)this + 3391);
  *((float *)this + 3392) = v32 + *((float *)this + 3392);
  *((float *)this + 3387) = *((float *)this + 3374) * *((float *)this + 3392)
                          + *((float *)this + 3373) * *((float *)this + 3391)
                          + *((float *)this + 3372) * *((float *)this + 3390);
  *((float *)this + 3388) = *((float *)this + 3377) * *((float *)this + 3392)
                          + *((float *)this + 3376) * *((float *)this + 3391)
                          + *((float *)this + 3375) * *((float *)this + 3390);
  *((float *)this + 3389) = *((float *)this + 3380) * *((float *)this + 3392)
                          + *((float *)this + 3379) * *((float *)this + 3391)
                          + *((float *)this + 3378) * *((float *)this + 3390);
  v32 = v26 * *(float *)&v28 - v29 * v25;
  v14 = v30 * v25 - v27 * *(float *)&v28;
  v25 = (v29 * v27 - v30 * v26) * *((float *)this + 3402);
  v15 = v14 * *((float *)this + 3403);
  v16 = v32 * *((float *)this + 3404);
  *((float *)this + 3393) = v25 + *((float *)this + 3393);
  *((float *)this + 3394) = v15 + *((float *)this + 3394);
  *((float *)this + 3395) = v16 + *((float *)this + 3395);
  if ( !*((_DWORD *)this + 3247) )
  {
    *(double *)v35 = *v5;
    v36 = a2[6];
    v37 = a2[7];
    v17 = a2[1] * 40.0;
    v23 = v17 * a2[10];
    v22 = v17 * a2[9];
    sub_4EC050(
      COERCE_UNSIGNED_INT64(v17 * *v10),
      HIDWORD(COERCE_UNSIGNED_INT64(v17 * *v10)),
      LODWORD(v22),
      HIDWORD(v22),
      LODWORD(v23),
      HIDWORD(v23));
    sub_43E5D0((int)&dbl_7C7428, (double *)v35, &v31);
  }
  v18 = *((_DWORD *)this + 3247);
  if ( v18 >= 0 )
  {
    if ( v18 <= 1 )
    {
      LOBYTE(v18) = a3;
      if ( a3 )
        LOBYTE(v18) = sub_4EC1A0((int)&v28, COERCE_FLOAT(v33), a2[1]);
    }
    else if ( v18 == 2 )
    {
      v18 = sub_463DC0(dword_7CD25C, *(_DWORD *)(*(_DWORD *)this + 18580));
      if ( v18 )
      {
        v19 = (_WORD *)(v18 + 8);
        sub_4B2580((__int16 *)(v18 + 8), &v25);
        v24 = a2[1] * *((float *)this + 3398);
        v20 = sub_45EB00(a2 + 8, (float *)v35, v24);
        v31 = *(double *)v20;
        v32 = v20[2];
        sub_4EC020(&v31);
        LOBYTE(v18) = sub_4B2480(v19, &v25);
      }
    }
  }
  return v18;
}
