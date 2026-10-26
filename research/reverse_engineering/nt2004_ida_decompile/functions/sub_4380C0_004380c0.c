int __thiscall sub_4380C0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // edi
  int v5; // ecx
  int result; // eax
  bool v7; // cc
  int v8; // esi
  int v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st6
  bool v14; // zf
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // st4
  long double v19; // st7
  long double v20; // st7
  double v21; // st7
  double v22; // st5
  int v23; // ecx
  double v24; // [esp+10h] [ebp-158h]
  int v25; // [esp+1Ch] [ebp-14Ch]
  double v26[3]; // [esp+20h] [ebp-148h] BYREF
  int v27; // [esp+38h] [ebp-130h]
  _DWORD *v28; // [esp+3Ch] [ebp-12Ch]
  double v29; // [esp+40h] [ebp-128h]
  double v30[3]; // [esp+48h] [ebp-120h] BYREF
  double v31; // [esp+60h] [ebp-108h] BYREF
  double v32; // [esp+68h] [ebp-100h]
  double v33; // [esp+70h] [ebp-F8h]
  double v34; // [esp+78h] [ebp-F0h] BYREF
  double v35; // [esp+80h] [ebp-E8h]
  double v36; // [esp+88h] [ebp-E0h]
  double v37; // [esp+90h] [ebp-D8h]
  double v38; // [esp+98h] [ebp-D0h]
  double v39; // [esp+A0h] [ebp-C8h]
  double v40; // [esp+A8h] [ebp-C0h]
  double v41; // [esp+B0h] [ebp-B8h]
  double v42; // [esp+B8h] [ebp-B0h]
  double v43; // [esp+C0h] [ebp-A8h]
  double v44; // [esp+C8h] [ebp-A0h]
  double v45; // [esp+D0h] [ebp-98h]
  double v46; // [esp+D8h] [ebp-90h]
  double v47; // [esp+E0h] [ebp-88h]
  double v48; // [esp+E8h] [ebp-80h]
  double v49; // [esp+F0h] [ebp-78h]
  double v50; // [esp+100h] [ebp-68h]
  double v51[3]; // [esp+108h] [ebp-60h] BYREF
  double v52[4]; // [esp+120h] [ebp-48h] BYREF
  double v53; // [esp+140h] [ebp-28h]
  double v54; // [esp+148h] [ebp-20h]
  double v55; // [esp+160h] [ebp-8h]

  v4 = this;
  v5 = *this;
  result = 0;
  v28 = v4;
  if ( v5 )
  {
    v7 = v4[38] <= 0;
    v27 = 0;
    if ( !v7 )
    {
      v25 = 0;
      do
      {
        v8 = v25 + v4[39];
        sub_438520(v8 + 28, &v31);
        v9 = *v4;
        v10 = v33 * *(double *)(*v4 + 132) - v32 * *(double *)(*v4 + 140);
        v11 = v31 * *(double *)(v9 + 140) - v33 * *(double *)(v9 + 124);
        v42 = v32 * *(double *)(*v4 + 124) - v31 * *(double *)(*v4 + 132);
        v40 = v10 + *(double *)(v9 + 100);
        v41 = v11 + *(double *)(v9 + 108);
        v42 = v42 + *(double *)(v9 + 116);
        v43 = v31 + *(double *)(v9 + 4);
        v44 = v32 + *(double *)(v9 + 12);
        v45 = v33 + *(double *)(v9 + 20);
        sub_438520(v8 + 52, &v34);
        v12 = v36 * *(double *)(a2 + 132) - v35 * *(double *)(a2 + 140);
        v13 = v34 * *(double *)(a2 + 140) - v36 * *(double *)(a2 + 124);
        v50 = v35 * *(double *)(a2 + 124) - v34 * *(double *)(a2 + 132);
        v49 = v12 + *(double *)(a2 + 100);
        v14 = *(_DWORD *)v8 == 0;
        v15 = v13 + *(double *)(a2 + 108);
        v16 = v50 + *(double *)(a2 + 116);
        v17 = v34 + *(double *)(a2 + 4);
        v18 = v35 + *(double *)(a2 + 12);
        v55 = v36 + *(double *)(a2 + 20);
        v30[0] = v17 - v43;
        v30[1] = v18 - v44;
        v30[2] = v55 - v45;
        v37 = v49 - v40;
        v38 = v15 - v41;
        v39 = v16 - v42;
        if ( v14 )
        {
          sub_438520(v8 + 4, v26);
        }
        else
        {
          qmemcpy(v26, v30, sizeof(v26));
          v4 = v28;
          v19 = v30[2] * v30[2] + v30[1] * v30[1] + v30[0] * v30[0];
          if ( v19 > 0.0 )
          {
            v20 = 1.0 / sqrt(v19);
            v26[0] = v30[0] * v20;
            v26[1] = v26[1] * v20;
            v26[2] = v26[2] * v20;
          }
        }
        v24 = v26[2] * v30[2] + v26[1] * v30[1] + v26[0] * v30[0];
        if ( *(double *)(v8 + 76) <= 0.0 || fabs(v24) >= *(double *)(v8 + 76) )
        {
          if ( *(_DWORD *)v8 == 2 )
          {
            v21 = *(double *)(v8 + 92);
            v53 = v38 * v21;
            v54 = v39 * v21;
            v22 = v24 * *(double *)(v8 + 84);
            v46 = v26[0] * v22;
            v47 = v26[1] * v22;
            v48 = v26[2] * v22;
            v51[0] = v46 + v37 * v21;
            v51[1] = v47 + v53;
            v51[2] = v48 + v54;
            sub_57C860(&v31, v51);
          }
          else
          {
            v29 = (v39 * v26[2] + v38 * v26[1] + v26[0] * v37) * *(double *)(v8 + 92) + v24 * *(double *)(v8 + 84);
            if ( *(double *)(v8 + 76) <= 0.0 || (v24 <= 0.0 || v29 >= 0.0) && (v24 >= 0.0 || v29 <= 0.0) )
            {
              v52[0] = v26[0] * v29;
              v52[1] = v26[1] * v29;
              v52[2] = v26[2] * v29;
              sub_57C860(&v31, v52);
            }
          }
        }
        v23 = v4[38];
        result = ++v27;
        v25 += 100;
      }
      while ( v27 < v23 );
    }
  }
  return result;
}
