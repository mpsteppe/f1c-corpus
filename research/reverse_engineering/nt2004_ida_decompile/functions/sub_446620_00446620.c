void __thiscall sub_446620(int this)
{
  int v2; // ecx
  int v3; // eax
  float v4; // eax
  int v5; // ecx
  int v6; // ecx
  double v7; // st7
  int v8; // edi
  long double v9; // st7
  long double v10; // st7
  int v11; // edi
  long double v12; // st7
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  double v17; // st7
  double v18; // st6
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  double v24; // st7
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st7
  int v29; // ecx
  int v30; // esi
  double v31; // st7
  double v32; // st6
  long double v33; // [esp+10h] [ebp-E8h] BYREF
  double v34; // [esp+18h] [ebp-E0h]
  double v35; // [esp+20h] [ebp-D8h]
  double v36; // [esp+28h] [ebp-D0h]
  double v37; // [esp+30h] [ebp-C8h]
  double v38; // [esp+38h] [ebp-C0h] BYREF
  double v39; // [esp+40h] [ebp-B8h]
  double v40; // [esp+48h] [ebp-B0h]
  double v41; // [esp+50h] [ebp-A8h] BYREF
  double v42; // [esp+58h] [ebp-A0h]
  double v43; // [esp+60h] [ebp-98h]
  double v44; // [esp+68h] [ebp-90h] BYREF
  double v45; // [esp+70h] [ebp-88h]
  double v46; // [esp+78h] [ebp-80h]
  double v47; // [esp+80h] [ebp-78h] BYREF
  double v48; // [esp+88h] [ebp-70h]
  double v49; // [esp+90h] [ebp-68h]
  double v50; // [esp+98h] [ebp-60h] BYREF
  double v51; // [esp+A0h] [ebp-58h]
  double v52; // [esp+A8h] [ebp-50h]
  double v53; // [esp+B0h] [ebp-48h] BYREF
  double v54; // [esp+B8h] [ebp-40h]
  double v55; // [esp+C0h] [ebp-38h]
  double v56[2]; // [esp+C8h] [ebp-30h] BYREF
  double v57; // [esp+D8h] [ebp-20h]
  double v58[2]; // [esp+E0h] [ebp-18h] BYREF
  double v59; // [esp+F0h] [ebp-8h]

  v37 = (*(double *)(this + 6428) + *(double *)(this + 6420)) * 0.5;
  if ( v37 >= 0.0 )
  {
    if ( v37 > *(double *)(this + 7552) )
    {
      v2 = *(_DWORD *)(this + 7556);
      LODWORD(v37) = *(_DWORD *)(this + 7552);
      HIDWORD(v37) = v2;
    }
  }
  else
  {
    v37 = 0.0;
  }
  v36 = (*(double *)(this + 6444) + *(double *)(this + 6436)) * 0.5;
  if ( v36 >= 0.0 )
  {
    if ( v36 > *(double *)(this + 7552) )
    {
      v3 = *(_DWORD *)(this + 7556);
      LODWORD(v36) = *(_DWORD *)(this + 7552);
      HIDWORD(v36) = v3;
    }
  }
  else
  {
    v36 = 0.0;
  }
  v4 = *(float *)(*(_DWORD *)(this + 8620) + 19020);
  v5 = *(_DWORD *)(*(_DWORD *)(this + 8620) + 19024);
  LODWORD(v33) = *(_DWORD *)(*(_DWORD *)(this + 8620) + 19016);
  v53 = *(float *)&v33;
  *((float *)&v33 + 1) = v4;
  LODWORD(v34) = v5;
  v6 = *(_DWORD *)(this + 6164);
  v54 = v4;
  v55 = *(float *)&v34;
  sub_43B1D0((double *)(v6 + 28), &v53, &v41);
  v7 = *(double *)(this + 8700);
  v41 = v41 * v7;
  v42 = v42 * v7;
  v43 = v43 * v7;
  *(long double *)(this + 7720) = fabs(v37 - v36) * *(double *)(this + 7544)
                                + (v36 + v37) * *(double *)(this + 7536) * 0.5
                                + *(double *)(this + 7528);
  v8 = *(_DWORD *)(this + 6164);
  sub_438520((double *)(v8 + 28), (double *)(this + 7560), &v47);
  sub_43B1D0((double *)(v8 + 28), (double *)(v8 + 100), &v33);
  v33 = v33 - v41;
  v34 = v34 - v42;
  v35 = v35 - v43;
  sub_43B1D0((double *)(v8 + 28), (double *)(v8 + 124), v58);
  sub_438950((double *)(this + 7584), &v33, v58, &v44, &v38);
  sub_438520((double *)(*(_DWORD *)(this + 6164) + 28), &v44, &v50);
  sub_57C860(&v47, &v50);
  if ( *(_BYTE *)(this + 7752) )
  {
    if ( v35 < 0.0 )
    {
      v9 = sub_438B50((double *)(this + 7788), v33, v35);
      v10 = v9
          * (v36 * *(double *)(this + 7772) * v36
           + v36 * *(double *)(this + 7764)
           + v37 * *(double *)(this + 7780)
           + *(double *)(this + 7756));
      if ( v10 < 0.0 )
      {
        v11 = *(_DWORD *)(this + 6164);
        v12 = v10 * v35 * v35;
        v50 = v12 * *(double *)(v11 + 36);
        v51 = v12 * *(double *)(v11 + 60);
        v52 = v12 * *(double *)(v11 + 84);
        sub_438520((double *)(v11 + 28), (double *)(this + 7820), &v47);
        sub_57C860(&v47, &v50);
      }
    }
  }
  sub_4464A0((_DWORD *)this, this + 6756, &v41);
  sub_4464A0((_DWORD *)this, this + 6880, &v41);
  if ( *(_BYTE *)(this + 7004) )
  {
    v13 = *(_DWORD *)(this + 8620);
    v14 = *(_DWORD *)(v13 + 3448);
    v15 = v13 + 3448;
    if ( !v14 || *(_BYTE *)(v15 + 64) )
    {
      v16 = *(_DWORD *)(this + 6164);
      v17 = *(double *)(this + 7044) * *(double *)(v16 + 132) - *(double *)(this + 7036) * *(double *)(v16 + 140);
      v18 = *(double *)(this + 7028) * *(double *)(v16 + 140) - *(double *)(this + 7044) * *(double *)(v16 + 124);
      v57 = *(double *)(this + 7036) * *(double *)(v16 + 124) - *(double *)(this + 7028) * *(double *)(v16 + 132);
      v56[0] = v17 + *(double *)(v16 + 100);
      v56[1] = v18 + *(double *)(v16 + 108);
      v57 = v57 + *(double *)(v16 + 116);
      sub_43B1D0((double *)(v16 + 28), v56, &v33);
      v33 = v33 - v41;
      v34 = v34 - v42;
      v35 = v35 - v43;
      if ( *(double *)(this + 7012) >= 0.0 )
      {
        if ( *(double *)(this + 7012) > *(double *)(this + 7020) )
        {
          v19 = *(_DWORD *)(this + 7024);
          *(_DWORD *)(this + 7012) = *(_DWORD *)(this + 7020);
          *(_DWORD *)(this + 7016) = v19;
        }
      }
      else
      {
        *(_DWORD *)(this + 7012) = 0;
        *(_DWORD *)(this + 7016) = 0;
      }
      *(long double *)(this + 7252) = sub_438B50((double *)(this + 7068), v33, v35)
                                    * (*(double *)(this + 7060) * *(double *)(this + 7012) + *(double *)(this + 7052));
      sub_438950((double *)(this + 7124), &v33, v58, &v44, &v53);
      sub_438520((double *)(*(_DWORD *)(this + 6164) + 28), &v44, &v50);
      sub_57C860(this + 7028, &v50);
      v38 = v53 + v38;
      v39 = v39 + v54;
      v40 = v40 + v55;
    }
  }
  if ( *(_BYTE *)(this + 7292) )
  {
    v20 = *(_DWORD *)(this + 8620);
    v21 = *(_DWORD *)(v20 + 3516);
    v22 = v20 + 3516;
    if ( !v21 || *(_BYTE *)(v22 + 64) )
    {
      v23 = *(_DWORD *)(this + 6164);
      v47 = *(double *)(v23 + 44) * *(double *)(this + 7352)
          + *(double *)(v23 + 36) * *(double *)(this + 7344)
          + *(double *)(v23 + 28) * *(double *)(this + 7336);
      v48 = *(double *)(v23 + 52) * *(double *)(this + 7336)
          + *(double *)(v23 + 68) * *(double *)(this + 7352)
          + *(double *)(v23 + 60) * *(double *)(this + 7344);
      v49 = *(double *)(v23 + 76) * *(double *)(this + 7336)
          + *(double *)(v23 + 92) * *(double *)(this + 7352)
          + *(double *)(v23 + 84) * *(double *)(this + 7344);
      v24 = v49 * *(double *)(v23 + 132) - v48 * *(double *)(v23 + 140);
      v25 = v47 * *(double *)(v23 + 140) - v49 * *(double *)(v23 + 124);
      v57 = v48 * *(double *)(v23 + 124) - v47 * *(double *)(v23 + 132);
      v56[0] = v24 + *(double *)(v23 + 100);
      v26 = v25 + *(double *)(v23 + 108);
      v27 = v57 + *(double *)(v23 + 116);
      v33 = v27 * *(double *)(v23 + 76) + v26 * *(double *)(v23 + 52) + v56[0] * *(double *)(v23 + 28);
      v34 = v27 * *(double *)(v23 + 84) + v26 * *(double *)(v23 + 60) + v56[0] * *(double *)(v23 + 36);
      v28 = v27 * *(double *)(v23 + 92) + v26 * *(double *)(v23 + 68) + v56[0] * *(double *)(v23 + 44);
      v33 = v33 - v41;
      v34 = v34 - v42;
      v35 = v28 - v43;
      *(long double *)(this + 7488) = sub_438B50((double *)(this + 7304), v33, v35) * *(double *)(this + 7296);
      sub_438950((double *)(this + 7360), &v33, v58, &v44, &v53);
      v29 = *(_DWORD *)(this + 6164);
      v50 = v46 * *(double *)(v29 + 44) + v45 * *(double *)(v29 + 36) + v44 * *(double *)(v29 + 28);
      v51 = v46 * *(double *)(v29 + 68) + v45 * *(double *)(v29 + 60) + v44 * *(double *)(v29 + 52);
      v52 = v46 * *(double *)(v29 + 92) + v45 * *(double *)(v29 + 84) + v44 * *(double *)(v29 + 76);
      sub_57C860(&v47, &v50);
      v38 = v53 + v38;
      v39 = v39 + v54;
      v40 = v40 + v55;
    }
  }
  v30 = *(_DWORD *)(this + 6164);
  v31 = v40 * *(double *)(v30 + 44) + v39 * *(double *)(v30 + 36) + v38 * *(double *)(v30 + 28);
  v32 = v38 * *(double *)(v30 + 52) + v40 * *(double *)(v30 + 68) + v39 * *(double *)(v30 + 60);
  v59 = v38 * *(double *)(v30 + 76) + v40 * *(double *)(v30 + 92) + v39 * *(double *)(v30 + 84);
  *(double *)(v30 + 332) = v31 + *(double *)(v30 + 332);
  *(double *)(v30 + 340) = v32 + *(double *)(v30 + 340);
  *(double *)(v30 + 348) = v59 + *(double *)(v30 + 348);
}
