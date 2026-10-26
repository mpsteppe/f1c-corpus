int __thiscall sub_401340(_DWORD *this, int a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edi
  float *v5; // eax
  int v6; // eax
  float *v7; // eax
  float v8; // ecx
  float v9; // edx
  float v10; // eax
  float v11; // ecx
  float v12; // edx
  float v13; // ecx
  float v14; // edx
  double v15; // st7
  double v16; // st6
  double v17; // st5
  long double v18; // st7
  long double v19; // st7
  long double v20; // st7
  long double v21; // st6
  long double v22; // st5
  double v23; // st4
  double v24; // st3
  double v25; // st3
  double v26; // st2
  double v27; // st3
  long double v28; // st2
  double v29; // st7
  long double v30; // st7
  long double v31; // st7
  bool v32; // zf
  float v33; // [esp+40h] [ebp-C8h] BYREF
  float v34; // [esp+44h] [ebp-C4h]
  float v35; // [esp+48h] [ebp-C0h]
  float v36; // [esp+4Ch] [ebp-BCh]
  float v37; // [esp+50h] [ebp-B8h]
  float v38; // [esp+54h] [ebp-B4h]
  float v39; // [esp+58h] [ebp-B0h]
  float v40; // [esp+5Ch] [ebp-ACh]
  float v41; // [esp+60h] [ebp-A8h]
  float v42; // [esp+64h] [ebp-A4h]
  float v43; // [esp+68h] [ebp-A0h]
  float v44; // [esp+6Ch] [ebp-9Ch]
  float v45; // [esp+70h] [ebp-98h]
  float v46; // [esp+74h] [ebp-94h]
  float v47; // [esp+78h] [ebp-90h]
  float v48; // [esp+7Ch] [ebp-8Ch]
  float v49; // [esp+80h] [ebp-88h]
  float v50; // [esp+84h] [ebp-84h]
  int v51; // [esp+88h] [ebp-80h]
  float *v52; // [esp+8Ch] [ebp-7Ch]
  int v53; // [esp+90h] [ebp-78h]
  float v54; // [esp+94h] [ebp-74h]
  float v55; // [esp+98h] [ebp-70h]
  float v56; // [esp+9Ch] [ebp-6Ch]
  float v57; // [esp+A0h] [ebp-68h]
  float v58; // [esp+A4h] [ebp-64h]
  float v59; // [esp+A8h] [ebp-60h]
  double v60; // [esp+ACh] [ebp-5Ch] BYREF
  double v61; // [esp+B4h] [ebp-54h]
  double v62; // [esp+BCh] [ebp-4Ch]
  int v63; // [esp+C4h] [ebp-44h]
  int v64; // [esp+C8h] [ebp-40h]
  int v65; // [esp+CCh] [ebp-3Ch]
  int v66; // [esp+D0h] [ebp-38h]
  double v67; // [esp+D4h] [ebp-34h]
  int v68; // [esp+DCh] [ebp-2Ch]
  _DWORD *v69; // [esp+E0h] [ebp-28h]
  int v70; // [esp+E4h] [ebp-24h]
  int v71; // [esp+E8h] [ebp-20h]
  int v72; // [esp+ECh] [ebp-1Ch]
  float v73; // [esp+F8h] [ebp-10h]
  float v74; // [esp+104h] [ebp-4h]

  v2 = a2;
  v69 = this;
  v70 = 0;
  v71 = -1055066685;
  v72 = 0;
  if ( a2 )
    result = 1;
  else
    result = this[76];
  v4 = 0;
  if ( result > 0 )
  {
    v51 = 0;
    v53 = result;
    while ( 1 )
    {
      if ( !v2 )
        v2 = v51 + this[77];
      v5 = *(float **)(v2 + 272);
      *(_DWORD *)(v2 + 112) = 0;
      *(_DWORD *)(v2 + 116) = 0;
      *(_DWORD *)(v2 + 120) = v70;
      *(_DWORD *)(v2 + 124) = v71;
      v52 = v5;
      v6 = *(_DWORD *)(v2 + 268);
      *(_DWORD *)(v2 + 128) = v72;
      if ( v52 )
      {
        if ( v6 )
        {
          v7 = (float *)(v6 + 148);
          v8 = *v7;
          v9 = v7[1];
          v10 = v7[2];
          v39 = v8;
          v40 = v9;
          v60 = v8;
          v41 = v10;
          v61 = v9;
          v62 = v10;
          v63 = 0;
          v64 = 1072693248;
          v65 = 0x40000000;
          v66 = 1201543096;
          v68 = v4;
          v4 = SpatialGridQuery(&v60);
          if ( v4 )
          {
            v11 = *(float *)(v2 + 152);
            v12 = *(float *)(v2 + 156);
            v42 = *(float *)(v2 + 148);
            v40 = v67;
            v43 = v11;
            v60 = v42;
            v44 = v12;
            v61 = v11;
            v62 = v12;
            v63 = 0;
            v64 = 1072693248;
            v65 = 0x40000000;
            v66 = 1201543096;
            v68 = v4;
            v4 = CollisionNormalFromFeature(&v60, &v33);
            if ( v4 )
            {
              v13 = v52[38];
              v14 = v52[39];
              v45 = v52[37];
              v43 = v67;
              v46 = v13;
              v60 = v45;
              v47 = v14;
              v61 = v13;
              v62 = v14;
              v63 = 0;
              v64 = 1072693248;
              v65 = 0x40000000;
              v66 = 1201543096;
              v68 = v4;
              v4 = SpatialGridQuery(&v60);
              if ( v4 )
              {
                v46 = v67;
                v15 = v39 - v45;
                v16 = v40 - v46;
                v17 = v41 - v47;
                if ( sqrt(v17 * v17 + v16 * v16 + v15 * v15) != 0.0 )
                {
                  v48 = v34 * v17 - v35 * v16;
                  v36 = v48;
                  v49 = v35 * v15 - v33 * v17;
                  v37 = v49;
                  v50 = v33 * v16 - v34 * v15;
                  v38 = v50;
                  v18 = v50 * v50 + v49 * v49 + v48 * v48;
                  if ( sqrt(v18) != 0.0 )
                  {
                    v19 = 1.0 / sqrt(v18);
                    v36 = v48 * v19;
                    v37 = v37 * v19;
                    v20 = v19 * v38;
                    v21 = v37 * v35 - v20 * v34;
                    v22 = v20 * v33 - v35 * v36;
                    v23 = v34 * v36 - v37 * v33;
                    v24 = v35 * 0.0 + v34 * -9.8100004 + v33 * 0.0;
                    *(float *)(v2 + 120) = v20 * 0.0 + v37 * -9.8100004 + v36 * 0.0;
                    *(float *)(v2 + 124) = v24;
                    *(float *)(v2 + 128) = 0.0 * v23 + v22 * -9.8100004 + v21 * 0.0;
                    v25 = v39 - v42;
                    v26 = v40 - v43;
                    v74 = v41 - v44;
                    v57 = v20 * v74 + v37 * v26 + v25 * v36;
                    v58 = v35 * v74 + v34 * v26 + v25 * v33;
                    v59 = v74 * v23 + v26 * v22 + v25 * v21;
                    v27 = v45 - v42;
                    v73 = v47 - v44;
                    v28 = v20;
                    v29 = v46 - v43;
                    v54 = v28 * v73 + v37 * v29 + v27 * v36;
                    v55 = v35 * v73 + v34 * v29 + v27 * v33;
                    v56 = v73 * v23 + v29 * v22 + v27 * v21;
                    v30 = RaySphereQuadraticIntersectionTest(v57, v59, 0.0, 0.0, v54, v56);
                    *(float *)(v2 + 112) = v30;
                    if ( v57 + v54 < 0.0 )
                      *(float *)(v2 + 112) = -v30;
                    v31 = RaySphereQuadraticIntersectionTest(v58, v59, 0.0, 0.0, v55, v56);
                    *(float *)(v2 + 116) = v31;
                    if ( v58 + v55 > 0.0 )
                      *(float *)(v2 + 116) = -v31;
                  }
                }
              }
            }
          }
        }
      }
      result = v53 - 1;
      v32 = v53 == 1;
      v51 += 316;
      --v53;
      if ( v32 )
        break;
      v2 = a2;
      this = v69;
    }
  }
  return result;
}
