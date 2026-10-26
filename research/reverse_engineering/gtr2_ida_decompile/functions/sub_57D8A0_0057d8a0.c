void __thiscall sub_57D8A0(char *this)
{
  int v2; // edi
  int v3; // ebp
  double **v4; // ebx
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6
  double *v11; // eax
  double v12; // st7
  char *v13; // ebp
  int v14; // edi
  double v15; // st7
  double v16; // st6
  double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double *v21; // ebx
  double v22; // st7
  double v23; // st7
  double v24; // st7
  unsigned int v25; // ebp
  double v26; // st7
  double v27; // st7
  int v28; // eax
  unsigned int v29; // ebx
  float v30; // [esp+30h] [ebp-64h]
  float v31; // [esp+34h] [ebp-60h]
  float v32; // [esp+38h] [ebp-5Ch]
  float v33; // [esp+38h] [ebp-5Ch]
  float *v34; // [esp+3Ch] [ebp-58h]
  char *v35; // [esp+40h] [ebp-54h]
  float v36; // [esp+44h] [ebp-50h] BYREF
  float v37; // [esp+48h] [ebp-4Ch]
  float v38; // [esp+4Ch] [ebp-48h]
  float v39[3]; // [esp+50h] [ebp-44h] BYREF
  double v40; // [esp+5Ch] [ebp-38h] BYREF
  double v41; // [esp+64h] [ebp-30h]
  double v42; // [esp+6Ch] [ebp-28h]
  double v43; // [esp+74h] [ebp-20h]
  double v44; // [esp+7Ch] [ebp-18h]
  double v45; // [esp+84h] [ebp-10h]
  double *v46; // [esp+8Ch] [ebp-8h]

  if ( (*(_DWORD *)(*(_DWORD *)this + 22580) & 2) != 0 )
  {
    v2 = 0;
    v3 = (int)(this + 3040);
    v4 = (double **)(this + 0x4000);
    do
    {
      v5 = *(float *)&this[v2 + 3164] * *((float *)this + 683) + *(float *)&this[v2 + 3160] * *((float *)this + 682);
      v6 = *(float *)&this[v2 + 3156] * *((float *)this + 681);
      v46 = *v4;
      v7 = v5 + v6;
      v8 = *(float *)&this[v2 + 3160] * *((float *)this + 685)
         + *((float *)this + 684) * *(float *)&this[v2 + 3156]
         + *(float *)&this[v2 + 3164] * *((float *)this + 686);
      v38 = *(float *)&this[v2 + 3164] * *((float *)this + 689)
          + *((float *)this + 687) * *(float *)&this[v2 + 3156]
          + *(float *)&this[v2 + 3160] * *((float *)this + 688);
      v36 = v7 + *((float *)this + 675);
      v9 = v8 + *((float *)this + 676);
      v37 = v9;
      v10 = v38 + *((float *)this + 677);
      v38 = v10;
      v40 = v36;
      v41 = v9;
      v42 = v10;
      v43 = 0.1000000014901161;
      v44 = 9.999999933815813e36;
      v11 = sub_45D210(dbl_B68610, &v40, v39);
      if ( v11 )
      {
        v12 = v45;
        *v4 = v11;
        v37 = v12 + flt_B715F0;
        sub_545860(*((int **)v11 + 21), v3, &v36, v39);
      }
      v2 += 296;
      v4 += 63;
      v3 += 296;
    }
    while ( v2 < 1184 );
    if ( *((int *)this + 3701) >= 2 )
    {
      v13 = this + 16292;
      v14 = 0;
      v35 = this + 16292;
      v34 = (float *)(this + 3068);
      do
      {
        v15 = *(float *)&this[v14 + 3156] * *((float *)this + 681)
            + *((float *)this + 683) * *(float *)&this[v14 + 3164];
        v16 = *((float *)this + 682) * *(float *)&this[v14 + 3160];
        v46 = (double *)*((_DWORD *)v13 + 23);
        v17 = v15 + v16;
        v18 = *((float *)this + 685) * *(float *)&this[v14 + 3160]
            + *((float *)this + 684) * *(float *)&this[v14 + 3156]
            + *(float *)&this[v14 + 3164] * *((float *)this + 686);
        v38 = *(float *)&this[v14 + 3156] * *((float *)this + 687)
            + *((float *)this + 688) * *(float *)&this[v14 + 3160]
            + *((float *)this + 689) * *(float *)&this[v14 + 3164];
        v36 = v17 + *((float *)this + 675);
        v19 = v18 + *((float *)this + 676);
        v37 = v19;
        v20 = v38 + *((float *)this + 677);
        v38 = v20;
        v40 = v36;
        v41 = v19;
        v42 = v20;
        v43 = 0.1000000014901161;
        v44 = 9.999999933815813e36;
        v21 = sub_45D210(dbl_B68610, &v40, v39);
        if ( v21 )
        {
          v22 = (v45 + *(float *)v13 + 0.050000001 - v37) * 10.0;
          v30 = v22;
          if ( v22 > 0.0 )
          {
            if ( v30 > 1.0 )
              v30 = 1.0;
            v31 = sqrt(
                    *((float *)this + 19) * *((float *)this + 19)
                  + *((float *)this + 20) * *((float *)this + 20)
                  + *((float *)this + 21) * *((float *)this + 21));
            if ( v31 <= 1.0 )
              v23 = v31;
            else
              v23 = 1.0;
            v24 = v23 * *v34 * v30;
            if ( v24 > 0.0099999998 )
            {
              v25 = *(_DWORD *)(*((_DWORD *)v21 + 21) + 48);
              if ( v25 <= 0x3A )
              {
                v32 = v24;
                if ( sub_58C190(v25) < v32 )
                  sub_58C630(v25);
              }
            }
            if ( v31 <= 32.0 )
              v26 = v31;
            else
              v26 = 32.0;
            v27 = v26 * v30 * 0.015625;
            if ( v27 > 0.0099999998 )
            {
              v28 = *((_DWORD *)v21 + 21);
              v29 = *(_DWORD *)(v28 + 44);
              if ( v29 <= 0x3A )
              {
                v33 = v27;
                if ( sub_58C190(*(_DWORD *)(v28 + 44)) < v33 )
                  sub_58C630(v29);
              }
            }
          }
        }
        v13 = v35 + 252;
        v14 += 296;
        v35 += 252;
        v34 += 74;
      }
      while ( v14 < 1184 );
    }
  }
}
