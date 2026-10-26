void __thiscall sub_4432F0(int this)
{
  int v2; // ecx
  int v3; // eax
  float v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // edi
  double v8; // st5
  double v9; // st5
  double v10; // st6
  double v11; // st7
  int v12; // edi
  double v13; // st7
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  double v18; // st7
  double v19; // st6
  int v20; // ecx
  double v21; // st5
  double v22; // st5
  double v23; // st6
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // edi
  double v28; // st7
  double v29; // st6
  double v30; // st6
  double v31; // st6
  double v32; // st7
  int v33; // ecx
  int v34; // esi
  double v35; // st7
  double v36; // st6
  double v37; // [esp+10h] [ebp-E8h] BYREF
  double v38; // [esp+18h] [ebp-E0h]
  double v39; // [esp+20h] [ebp-D8h]
  double v40; // [esp+28h] [ebp-D0h]
  double v41; // [esp+30h] [ebp-C8h]
  double v42; // [esp+38h] [ebp-C0h] BYREF
  double v43; // [esp+40h] [ebp-B8h]
  double v44; // [esp+48h] [ebp-B0h]
  double v45; // [esp+50h] [ebp-A8h] BYREF
  double v46; // [esp+58h] [ebp-A0h]
  double v47; // [esp+60h] [ebp-98h]
  double v48; // [esp+68h] [ebp-90h] BYREF
  double v49; // [esp+70h] [ebp-88h]
  double v50; // [esp+78h] [ebp-80h]
  double v51; // [esp+80h] [ebp-78h] BYREF
  double v52; // [esp+88h] [ebp-70h]
  double v53; // [esp+90h] [ebp-68h]
  double v54; // [esp+98h] [ebp-60h] BYREF
  double v55; // [esp+A0h] [ebp-58h]
  double v56; // [esp+A8h] [ebp-50h]
  double v57; // [esp+B0h] [ebp-48h] BYREF
  double v58; // [esp+B8h] [ebp-40h]
  double v59; // [esp+C0h] [ebp-38h]
  double v60; // [esp+C8h] [ebp-30h] BYREF
  double v61; // [esp+D0h] [ebp-28h]
  double v62; // [esp+D8h] [ebp-20h]
  double v63[2]; // [esp+E0h] [ebp-18h] BYREF
  double v64; // [esp+F0h] [ebp-8h]

  v41 = (*(double *)(this + 5880) + *(double *)(this + 5872)) * 0.5;
  if ( v41 >= 0.0 )
  {
    if ( v41 > *(double *)(this + 6900) )
    {
      v2 = *(_DWORD *)(this + 6904);
      LODWORD(v41) = *(_DWORD *)(this + 6900);
      HIDWORD(v41) = v2;
    }
  }
  else
  {
    v41 = 0.0;
  }
  v40 = (*(double *)(this + 5896) + *(double *)(this + 5888)) * 0.5;
  if ( v40 >= 0.0 )
  {
    if ( v40 > *(double *)(this + 6900) )
    {
      v3 = *(_DWORD *)(this + 6904);
      LODWORD(v40) = *(_DWORD *)(this + 6900);
      HIDWORD(v40) = v3;
    }
  }
  else
  {
    v40 = 0.0;
  }
  v4 = *(float *)(*(_DWORD *)(this + 7936) + 14952);
  v5 = *(_DWORD *)(*(_DWORD *)(this + 7936) + 14956);
  LODWORD(v37) = *(_DWORD *)(*(_DWORD *)(this + 7936) + 14948);
  v57 = *(float *)&v37;
  *((float *)&v37 + 1) = v4;
  LODWORD(v38) = v5;
  v6 = *(_DWORD *)(this + 5616);
  v58 = v4;
  v59 = *(float *)&v38;
  sub_4388D0((double *)(v6 + 28), &v57, &v54);
  *(long double *)(this + 7068) = fabs(v41 - v40) * *(double *)(this + 6892)
                                + (v40 + v41) * *(double *)(this + 6884) * 0.5
                                + *(double *)(this + 6876);
  v7 = *(_DWORD *)(this + 5616);
  sub_435E00((double *)(v7 + 28), (double *)(this + 6908), &v51);
  sub_4388D0((double *)(v7 + 28), (double *)(v7 + 100), &v37);
  v37 = v37 - v54;
  v38 = v38 - v55;
  v39 = v39 - v56;
  sub_4388D0((double *)(v7 + 28), (double *)(v7 + 124), v63);
  sub_436230((double *)(this + 6932), &v37, v63, &v45, &v42);
  sub_435E00((double *)(*(_DWORD *)(this + 5616) + 28), &v45, &v60);
  sub_569AD0(&v51, &v60);
  if ( *(_BYTE *)(this + 7100) && v39 < 0.0 )
  {
    v8 = v37 * v37 + v39 * v39;
    if ( v8 <= 0.0 )
    {
      v10 = 1.0;
    }
    else
    {
      v9 = v39 * v39 / v8 * (v39 * v39 / v8);
      v10 = 1.0 - (1.0 - v9 * v9) * *(double *)(this + 7136);
    }
    v11 = (v40 * *(double *)(this + 7120) * v40
         + v40 * *(double *)(this + 7112)
         + v41 * *(double *)(this + 7128)
         + *(double *)(this + 7104))
        * v10;
    if ( v11 < 0.0 )
    {
      v12 = *(_DWORD *)(this + 5616);
      v13 = v11 * v39 * v39;
      v60 = v13 * *(double *)(v12 + 36);
      v61 = v13 * *(double *)(v12 + 60);
      v62 = v13 * *(double *)(v12 + 84);
      sub_435E00((double *)(v12 + 28), (double *)(this + 7144), &v51);
      sub_569AD0(&v51, &v60);
    }
  }
  sub_443150((_DWORD *)this, this + 6200, &v54);
  sub_443150((_DWORD *)this, this + 6300, &v54);
  if ( *(_BYTE *)(this + 6400) )
  {
    v14 = *(_DWORD *)(this + 7936);
    v15 = *(_DWORD *)(v14 + 3284);
    v16 = v14 + 3284;
    if ( !v15 || *(_BYTE *)(v16 + 64) )
    {
      v17 = *(_DWORD *)(this + 5616);
      v18 = *(double *)(this + 6440) * *(double *)(v17 + 132) - *(double *)(this + 6432) * *(double *)(v17 + 140);
      v19 = *(double *)(v17 + 140) * *(double *)(this + 6424) - *(double *)(this + 6440) * *(double *)(v17 + 124);
      v50 = *(double *)(this + 6432) * *(double *)(v17 + 124) - *(double *)(v17 + 132) * *(double *)(this + 6424);
      v48 = v18 + *(double *)(v17 + 100);
      v49 = v19 + *(double *)(v17 + 108);
      v50 = v50 + *(double *)(v17 + 116);
      sub_4388D0((double *)(v17 + 28), &v48, &v37);
      v37 = v37 - v54;
      v38 = v38 - v55;
      v39 = v39 - v56;
      if ( *(double *)(this + 6408) >= 0.0 )
      {
        if ( *(double *)(this + 6408) > *(double *)(this + 6416) )
        {
          v20 = *(_DWORD *)(this + 6420);
          *(_DWORD *)(this + 6408) = *(_DWORD *)(this + 6416);
          *(_DWORD *)(this + 6412) = v20;
        }
      }
      else
      {
        *(_DWORD *)(this + 6408) = 0;
        *(_DWORD *)(this + 6412) = 0;
      }
      v21 = v37 * v37 + v39 * v39;
      if ( v21 <= 0.0 )
      {
        v23 = 1.0;
      }
      else
      {
        v22 = v39 * v39 / v21 * (v39 * v39 / v21);
        v23 = 1.0 - (1.0 - v22 * v22) * *(double *)(this + 6464);
      }
      *(double *)(this + 6624) = v23 * (*(double *)(this + 6456) * *(double *)(this + 6408) + *(double *)(this + 6448));
      sub_436230((double *)(this + 6496), &v37, v63, &v45, &v57);
      sub_435E00((double *)(*(_DWORD *)(this + 5616) + 28), &v45, &v60);
      sub_569AD0(this + 6424, &v60);
      v42 = v57 + v42;
      v43 = v43 + v58;
      v44 = v44 + v59;
    }
  }
  if ( *(_BYTE *)(this + 6664) )
  {
    v24 = *(_DWORD *)(this + 7936);
    v25 = *(_DWORD *)(v24 + 3352);
    v26 = v24 + 3352;
    if ( !v25 || *(_BYTE *)(v26 + 64) )
    {
      v27 = *(_DWORD *)(this + 5616);
      sub_435E00((double *)(v27 + 28), (double *)(this + 6684), &v51);
      v28 = v53 * *(double *)(v27 + 132) - v52 * *(double *)(v27 + 140);
      v29 = v51 * *(double *)(v27 + 140) - v53 * *(double *)(v27 + 124);
      v50 = v52 * *(double *)(v27 + 124) - v51 * *(double *)(v27 + 132);
      v48 = v28 + *(double *)(v27 + 100);
      v49 = v29 + *(double *)(v27 + 108);
      v50 = v50 + *(double *)(v27 + 116);
      sub_4388D0((double *)(v27 + 28), &v48, &v37);
      v37 = v37 - v54;
      v38 = v38 - v55;
      v39 = v39 - v56;
      v30 = v37 * v37 + v39 * v39;
      if ( v30 <= 0.0 )
      {
        v32 = 1.0;
      }
      else
      {
        v31 = v39 * v39 / v30 * (v39 * v39 / v30);
        v32 = 1.0 - (1.0 - v31 * v31) * *(double *)(this + 6676);
      }
      *(double *)(this + 6836) = v32 * *(double *)(this + 6668);
      sub_436230((double *)(this + 6708), &v37, v63, &v45, &v57);
      v33 = *(_DWORD *)(this + 5616);
      v60 = v47 * *(double *)(v33 + 44) + v46 * *(double *)(v33 + 36) + v45 * *(double *)(v33 + 28);
      v61 = v47 * *(double *)(v33 + 68) + v46 * *(double *)(v33 + 60) + v45 * *(double *)(v33 + 52);
      v62 = v47 * *(double *)(v33 + 92) + v46 * *(double *)(v33 + 84) + v45 * *(double *)(v33 + 76);
      sub_569AD0(&v51, &v60);
      v42 = v57 + v42;
      v43 = v43 + v58;
      v44 = v44 + v59;
    }
  }
  v34 = *(_DWORD *)(this + 5616);
  v35 = v43 * *(double *)(v34 + 36) + v44 * *(double *)(v34 + 44) + v42 * *(double *)(v34 + 28);
  v36 = v42 * *(double *)(v34 + 52) + v44 * *(double *)(v34 + 68) + v43 * *(double *)(v34 + 60);
  v64 = v42 * *(double *)(v34 + 76) + v44 * *(double *)(v34 + 92) + v43 * *(double *)(v34 + 84);
  *(double *)(v34 + 332) = v35 + *(double *)(v34 + 332);
  *(double *)(v34 + 340) = v36 + *(double *)(v34 + 340);
  *(double *)(v34 + 348) = v64 + *(double *)(v34 + 348);
}
