void __thiscall sub_570030(int this)
{
  int v1; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int v8; // ebp
  int i; // edx
  int v10; // ecx
  int *v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // edi
  float *v15; // eax
  long double v16; // st7
  double v17; // st6
  float v18; // edx
  long double v19; // st5
  int v20; // ecx
  double v21; // st5
  double v22; // st5
  double v23; // st5
  long double v24; // st7
  bool v25; // c0
  float *v26; // ecx
  int v27; // edi
  _DWORD *v28; // ebp
  double v29; // st7
  float *v30; // ebp
  float v31; // eax
  float v32; // ecx
  double v33; // st6
  double v34; // st6
  double v35; // st6
  double v36; // st6
  int v37; // edi
  float v38; // edx
  float *v39; // ebx
  long double v40; // st7
  float v41; // [esp+Ch] [ebp-50h]
  float v42; // [esp+Ch] [ebp-50h]
  float v43; // [esp+Ch] [ebp-50h]
  float v44; // [esp+Ch] [ebp-50h]
  float v45; // [esp+Ch] [ebp-50h]
  float v46; // [esp+Ch] [ebp-50h]
  float *v47; // [esp+Ch] [ebp-50h]
  int v48; // [esp+10h] [ebp-4Ch]
  int v49; // [esp+14h] [ebp-48h]
  float v50; // [esp+24h] [ebp-38h]
  float v51; // [esp+24h] [ebp-38h]
  float v52; // [esp+24h] [ebp-38h]
  float v53; // [esp+24h] [ebp-38h]
  float v54; // [esp+24h] [ebp-38h]
  float v55; // [esp+24h] [ebp-38h]
  float v56; // [esp+24h] [ebp-38h]
  float v57; // [esp+24h] [ebp-38h]
  float v58; // [esp+28h] [ebp-34h]
  float v59; // [esp+28h] [ebp-34h]
  float v60; // [esp+28h] [ebp-34h]
  float v61; // [esp+28h] [ebp-34h]
  float v62; // [esp+28h] [ebp-34h]
  float v63; // [esp+28h] [ebp-34h]
  float v64; // [esp+28h] [ebp-34h]
  float v65; // [esp+28h] [ebp-34h]
  float v66; // [esp+2Ch] [ebp-30h]
  float v67; // [esp+2Ch] [ebp-30h]
  float v68; // [esp+2Ch] [ebp-30h]
  float v69; // [esp+2Ch] [ebp-30h]
  float v70; // [esp+2Ch] [ebp-30h]
  float v71; // [esp+2Ch] [ebp-30h]
  float v72; // [esp+2Ch] [ebp-30h]
  float v73; // [esp+2Ch] [ebp-30h]
  float v74; // [esp+30h] [ebp-2Ch] BYREF
  float v75; // [esp+34h] [ebp-28h]
  float v76; // [esp+38h] [ebp-24h]
  int v77; // [esp+3Ch] [ebp-20h] BYREF
  int v78; // [esp+40h] [ebp-1Ch]
  int v79; // [esp+44h] [ebp-18h]
  int v80; // [esp+48h] [ebp-14h]
  _DWORD v81[4]; // [esp+4Ch] [ebp-10h] BYREF

  v1 = 0;
  v3 = *(_DWORD *)(this + 476);
  v4 = *(_DWORD *)(this + 772);
  v5 = *(_DWORD *)(this + 1068);
  *(_DWORD *)(this + 644) = v3;
  v6 = *(_DWORD *)(this + 1364);
  *(_DWORD *)(this + 636) = 0;
  *(_DWORD *)(this + 640) = 0;
  *(_DWORD *)(this + 932) = 0;
  *(_DWORD *)(this + 936) = 0;
  *(_DWORD *)(this + 940) = v4;
  *(_DWORD *)(this + 1228) = 0;
  *(_DWORD *)(this + 1232) = 0;
  *(_DWORD *)(this + 1236) = v5;
  *(_DWORD *)(this + 1524) = 0;
  *(_DWORD *)(this + 1528) = 0;
  *(_DWORD *)(this + 1532) = v6;
  v7 = *(_DWORD *)(this + 2444);
  v77 = 2139095039;
  memset(v81, 0, sizeof(v81));
  v78 = 2139095039;
  v79 = 2139095039;
  v80 = 2139095039;
  *(_DWORD *)(this + 2548) = 0;
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 544);
    for ( i = 0; i < v8; ++i )
    {
      v10 = i;
      if ( i >= 0 && i < *(_DWORD *)(v7 + 544) )
      {
        v11 = *(int **)(v7 + 532);
        if ( i <= 0 )
        {
LABEL_8:
          if ( v11 )
          {
            v12 = *v11;
            goto LABEL_11;
          }
        }
        else
        {
          while ( v11 )
          {
            v11 = (int *)v11[1];
            if ( --v10 <= 0 )
              goto LABEL_8;
          }
        }
      }
      v12 = 0;
LABEL_11:
      if ( *(float *)(v12 + 240) == 0.0 )
        *(_DWORD *)(this + 2548) = v12;
    }
    v13 = *(_DWORD *)(this + 2548);
    if ( v13 )
    {
      v14 = 0;
      v49 = sub_5EA5B0(v13);
      if ( v49 > 0 )
      {
        do
        {
          v15 = (float *)sub_5EB140(v14, 1);
          v16 = *v15;
          v17 = 3.4028235e38;
          v18 = v15[2];
          v19 = v16 - *(float *)(this + 468);
          v75 = v15[1];
          v76 = v18;
          v20 = 0;
          v50 = v19;
          v58 = v75 - *(float *)(this + 472);
          v66 = v18 - *(float *)(this + 476);
          v21 = v66 * v66 + v58 * v58 + v50 * v50;
          if ( v21 < 3.4028235e38 )
          {
            v41 = v21;
            v17 = v41;
          }
          v51 = v16 - *(float *)(this + 764);
          v59 = v75 - *(float *)(this + 768);
          v67 = v76 - *(float *)(this + 772);
          v22 = v67 * v67 + v59 * v59 + v51 * v51;
          if ( v22 < v17 )
          {
            v20 = 1;
            v42 = v22;
            v17 = v42;
          }
          v52 = v16 - *(float *)(this + 1060);
          v60 = v75 - *(float *)(this + 1064);
          v68 = v76 - *(float *)(this + 1068);
          v23 = v68 * v68 + v60 * v60 + v52 * v52;
          if ( v23 < v17 )
          {
            v20 = 2;
            v43 = v23;
            v17 = v43;
          }
          v53 = v16 - *(float *)(this + 1356);
          v61 = v75 - *(float *)(this + 1360);
          v69 = v76 - *(float *)(this + 1364);
          if ( v69 * v69 + v61 * v61 + v53 * v53 < v17 )
            v20 = 3;
          v24 = fabs(v16);
          ++v81[v20];
          v25 = v24 < *((float *)&v77 + v20);
          v26 = (float *)(&v77 + v20);
          if ( v25 )
            *v26 = v24;
          ++v14;
        }
        while ( v14 < v49 );
      }
      v77 = 1036831949;
      v78 = 1036831949;
      v79 = 1036831949;
      v80 = 1036831949;
      v27 = 0;
      v28 = (_DWORD *)(this + 640);
      do
      {
        *v28 = operator new(32 * v81[v27++]);
        v28 += 74;
      }
      while ( v27 < 4 );
      v48 = 0;
      if ( v49 > 0 )
      {
        while ( 1 )
        {
          v29 = 3.4028235e38;
          v30 = (float *)sub_5EB140(v48, 1);
          v31 = v30[1];
          v32 = v30[2];
          v74 = *v30;
          v33 = v74 - *(float *)(this + 468);
          v75 = v31;
          v76 = v32;
          v54 = v33;
          v62 = v31 - *(float *)(this + 472);
          v70 = v32 - *(float *)(this + 476);
          v34 = v70 * v70 + v62 * v62 + v54 * v54;
          if ( v34 < 3.4028235e38 )
          {
            v44 = v34;
            v29 = v44;
          }
          v55 = v74 - *(float *)(this + 764);
          v63 = v75 - *(float *)(this + 768);
          v71 = v76 - *(float *)(this + 772);
          v35 = v71 * v71 + v63 * v63 + v55 * v55;
          if ( v35 < v29 )
          {
            v1 = 1;
            v45 = v35;
            v29 = v45;
          }
          v56 = v74 - *(float *)(this + 1060);
          v64 = v75 - *(float *)(this + 1064);
          v72 = v76 - *(float *)(this + 1068);
          v36 = v72 * v72 + v64 * v64 + v56 * v56;
          if ( v36 < v29 )
          {
            v1 = 2;
            v46 = v36;
            v29 = v46;
          }
          v57 = v74 - *(float *)(this + 1356);
          v65 = v75 - *(float *)(this + 1360);
          v73 = v76 - *(float *)(this + 1364);
          if ( v73 * v73 + v65 * v65 + v57 * v57 < v29 )
            v1 = 3;
          v37 = *(_DWORD *)(296 * v1 + this + 640) + 32 * *(_DWORD *)(296 * v1 + this + 636);
          v38 = v74;
          ++*(_DWORD *)(296 * v1 + this + 636);
          *(float *)v37 = v38;
          *(float *)(v37 + 4) = v75;
          *(float *)(v37 + 8) = v76;
          v47 = (float *)(296 * v1 + this + 468);
          sub_4F09D0((float *)(296 * v1 + this + 492), v47, &v74, (float *)(v37 + 12));
          *(_DWORD *)(v37 + 28) = v30;
          v39 = (float *)(&v77 + v1);
          v40 = fabs(*v47) - *v39 - 0.090000004;
          if ( v40 > 0.0 )
            *(float *)(v37 + 24) = (fabs(v74) - *v39) / v40;
          else
            *(_DWORD *)(v37 + 24) = 0;
          if ( ++v48 >= v49 )
            break;
          v1 = 0;
        }
      }
    }
  }
}
