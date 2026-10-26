int __thiscall sub_4359A0(_DWORD *this, int a2, int a3, int a4)
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
  double v23; // [esp+10h] [ebp-158h]
  int v24; // [esp+1Ch] [ebp-14Ch]
  double v25[3]; // [esp+20h] [ebp-148h] BYREF
  int v26; // [esp+38h] [ebp-130h]
  _DWORD *v27; // [esp+3Ch] [ebp-12Ch]
  double v28; // [esp+40h] [ebp-128h]
  double v29[3]; // [esp+48h] [ebp-120h] BYREF
  double v30; // [esp+60h] [ebp-108h] BYREF
  double v31; // [esp+68h] [ebp-100h]
  double v32; // [esp+70h] [ebp-F8h]
  double v33; // [esp+78h] [ebp-F0h] BYREF
  double v34; // [esp+80h] [ebp-E8h]
  double v35; // [esp+88h] [ebp-E0h]
  double v36; // [esp+90h] [ebp-D8h]
  double v37; // [esp+98h] [ebp-D0h]
  double v38; // [esp+A0h] [ebp-C8h]
  double v39; // [esp+A8h] [ebp-C0h]
  double v40; // [esp+B0h] [ebp-B8h]
  double v41; // [esp+B8h] [ebp-B0h]
  double v42; // [esp+C0h] [ebp-A8h]
  double v43; // [esp+C8h] [ebp-A0h]
  double v44; // [esp+D0h] [ebp-98h]
  double v45; // [esp+D8h] [ebp-90h]
  double v46; // [esp+E0h] [ebp-88h]
  double v47; // [esp+E8h] [ebp-80h]
  double v48; // [esp+F0h] [ebp-78h]
  double v49; // [esp+100h] [ebp-68h]
  double v50[3]; // [esp+108h] [ebp-60h] BYREF
  double v51[4]; // [esp+120h] [ebp-48h] BYREF
  double v52; // [esp+140h] [ebp-28h]
  double v53; // [esp+148h] [ebp-20h]
  double v54; // [esp+160h] [ebp-8h]

  v4 = this;
  v5 = *this;
  result = 0;
  v27 = v4;
  if ( v5 )
  {
    v7 = v4[38] <= 0;
    v26 = 0;
    if ( !v7 )
    {
      v24 = 0;
      do
      {
        v8 = v24 + v4[39];
        sub_435E00(v8 + 28, &v30);
        v9 = *v4;
        v10 = v32 * *(double *)(*v4 + 132) - v31 * *(double *)(*v4 + 140);
        v11 = v30 * *(double *)(v9 + 140) - v32 * *(double *)(v9 + 124);
        v41 = v31 * *(double *)(*v4 + 124) - v30 * *(double *)(*v4 + 132);
        v39 = v10 + *(double *)(v9 + 100);
        v40 = v11 + *(double *)(v9 + 108);
        v41 = v41 + *(double *)(v9 + 116);
        v42 = v30 + *(double *)(v9 + 4);
        v43 = v31 + *(double *)(v9 + 12);
        v44 = v32 + *(double *)(v9 + 20);
        sub_435E00(v8 + 52, &v33);
        v12 = v35 * *(double *)(a2 + 132) - v34 * *(double *)(a2 + 140);
        v13 = v33 * *(double *)(a2 + 140) - v35 * *(double *)(a2 + 124);
        v49 = v34 * *(double *)(a2 + 124) - v33 * *(double *)(a2 + 132);
        v48 = v12 + *(double *)(a2 + 100);
        v14 = *(_DWORD *)v8 == 0;
        v15 = v13 + *(double *)(a2 + 108);
        v16 = v49 + *(double *)(a2 + 116);
        v17 = v33 + *(double *)(a2 + 4);
        v18 = v34 + *(double *)(a2 + 12);
        v54 = v35 + *(double *)(a2 + 20);
        v29[0] = v17 - v42;
        v29[1] = v18 - v43;
        v29[2] = v54 - v44;
        v36 = v48 - v39;
        v37 = v15 - v40;
        v38 = v16 - v41;
        if ( v14 )
        {
          sub_435E00(v8 + 4, v25);
        }
        else
        {
          qmemcpy(v25, v29, sizeof(v25));
          v4 = v27;
          v19 = v29[2] * v29[2] + v29[1] * v29[1] + v29[0] * v29[0];
          if ( v19 > 0.0 )
          {
            v20 = 1.0 / sqrt(v19);
            v25[0] = v29[0] * v20;
            v25[1] = v25[1] * v20;
            v25[2] = v25[2] * v20;
          }
        }
        v23 = v25[2] * v29[2] + v25[1] * v29[1] + v25[0] * v29[0];
        if ( *(double *)(v8 + 76) <= 0.0 || fabs(v23) >= *(double *)(v8 + 76) )
        {
          if ( *(_DWORD *)v8 == 2 )
          {
            v21 = *(double *)(v8 + 92);
            v52 = v37 * v21;
            v53 = v38 * v21;
            v22 = v23 * *(double *)(v8 + 84);
            v45 = v25[0] * v22;
            v46 = v25[1] * v22;
            v47 = v25[2] * v22;
            v50[0] = v45 + v36 * v21;
            v50[1] = v46 + v52;
            v50[2] = v47 + v53;
            sub_569AD0(&v30, v50);
          }
          else
          {
            v28 = (v38 * v25[2] + v37 * v25[1] + v25[0] * v36) * *(double *)(v8 + 92) + v23 * *(double *)(v8 + 84);
            if ( *(double *)(v8 + 76) <= 0.0 || (v23 <= 0.0 || v28 >= 0.0) && (v23 >= 0.0 || v28 <= 0.0) )
            {
              v51[0] = v25[0] * v28;
              v51[1] = v25[1] * v28;
              v51[2] = v25[2] * v28;
              sub_569AD0(&v30, v51);
            }
          }
        }
        result = v26 + 1;
        v7 = ++v26 < v4[38];
        v24 += 100;
      }
      while ( v7 );
    }
  }
  return result;
}
