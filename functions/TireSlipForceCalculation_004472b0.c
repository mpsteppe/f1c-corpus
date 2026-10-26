int __thiscall sub_4472B0(int this, float *a2)
{
  char *v3; // ebx
  float *v4; // esi
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  double v8; // st7
  int v9; // ecx
  int v10; // eax
  double v11; // st7
  int v12; // edx
  double v13; // st6
  double v14; // st7
  double v15; // st6
  int v16; // esi
  double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double v21; // st6
  double v22; // st7
  int v23; // ebx
  int v24; // esi
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st7
  double v29; // st7
  int result; // eax
  float *v31; // ecx
  double *v32; // edx
  int v33; // esi
  __int16 v34; // fps
  double v35; // st7
  bool v36; // c0
  char v37; // c2
  bool v38; // c3
  bool v39; // c0
  char v40; // c2
  bool v41; // c3
  float v42; // [esp+0h] [ebp-84h]
  float v43; // [esp+4h] [ebp-80h]
  double *v44; // [esp+24h] [ebp-60h]
  int v45; // [esp+28h] [ebp-5Ch]
  int v46; // [esp+2Ch] [ebp-58h]
  double *v47; // [esp+2Ch] [ebp-58h]
  int v48; // [esp+30h] [ebp-54h] BYREF
  float v49; // [esp+34h] [ebp-50h]
  float v50; // [esp+38h] [ebp-4Ch]
  int v51; // [esp+3Ch] [ebp-48h] BYREF
  float v52; // [esp+40h] [ebp-44h]
  float v53; // [esp+44h] [ebp-40h]
  float v54[3]; // [esp+48h] [ebp-3Ch] BYREF
  double v55; // [esp+54h] [ebp-30h] BYREF
  double v56; // [esp+5Ch] [ebp-28h]
  double v57; // [esp+64h] [ebp-20h]
  double v58[3]; // [esp+6Ch] [ebp-18h] BYREF

  v3 = (char *)&unk_7C7810;
  v4 = a2 + 61;
  v46 = 4;
  do
  {
    if ( *((double *)v3 - 4) <= 0.0 )
    {
      v5 = 0.0;
    }
    else
    {
      v5 = 1.0 - *((double *)v3 - 2);
      if ( v5 > 0.66000003 )
      {
        *(v4 - 1) = (v5 - 0.66000003) * 2.941176697457143;
        goto LABEL_7;
      }
    }
    *(v4 - 1) = 0.0;
LABEL_7:
    if ( v5 <= 0.38999999 )
      *v4 = 0.0;
    else
      *v4 = (v5 - 0.38999999) * 1.639344223850808;
    v6 = *v4;
    v7 = *((_DWORD *)v4 - 1);
    v4[3] = *v4;
    *((_DWORD *)v4 + 2) = v7;
    *((_DWORD *)v4 + 5) = CRTFtol(v6 * 16.0);
    if ( *((double *)v3 - 4) <= 0.0 )
      v8 = 0.0;
    else
      v8 = *(double *)(v3 + 276);
    v4[1] = v8;
    v4[4] = 0.0;
    if ( v8 > 0.0 )
    {
      *(v4 - 1) = 0.0;
      v4[2] = 0.0;
      v4[3] = 0.0;
    }
    v9 = *((_DWORD *)v3 + 66);
    if ( v9 )
    {
      v10 = *(_DWORD *)v3;
      v11 = *(double *)(*(_DWORD *)v3 + 20);
      v12 = *(_DWORD *)(this + 7936);
      v13 = *(double *)(*(_DWORD *)v3 + 12);
      *(float *)&v51 = *(double *)(*(_DWORD *)v3 + 4);
      v52 = v13;
      v53 = v11;
      v14 = *(double *)(v10 + 116);
      v15 = *(double *)(v10 + 108);
      *(float *)&v48 = *(double *)(v10 + 100);
      v49 = v15;
      v50 = v14;
      v42 = *(double *)(this + 96);
      CollisionEffectDispatch((int)(v4 - 8), v42, (int)&v51, (int)&v48, v9, *(_DWORD *)(v12 + 18580));
    }
    v3 += 1124;
    v4 += 74;
    --v46;
  }
  while ( v46 );
  if ( *(double *)(this + 7652) == 0.0 && *(double *)(this + 7660) == 0.0 && *(double *)(this + 7668) == 0.0 )
  {
    a2[38] = 0.0;
    a2[43] = 0.0;
    a2[48] = 0.0;
  }
  else
  {
    v16 = *(_DWORD *)(this + 5616);
    TransformApply3D((double *)(v16 + 28), (double *)(v16 + 4), (double *)(this + 7676), &v55);
    *(float *)&v51 = v55;
    v52 = v56;
    v53 = v57;
    v17 = *(double *)(v16 + 116);
    v18 = *(double *)(v16 + 108);
    *(float *)&v48 = *(double *)(v16 + 100);
    v49 = v18;
    v50 = v17;
    v19 = -1.0 / *(double *)(this + 7388) * *(double *)(this + 7260) * *(double *)(this + 8);
    if ( v19 >= -1.0 )
    {
      if ( v19 > 0.0 )
        v19 = 0.0;
    }
    else
    {
      v19 = -1.0;
    }
    if ( *(double *)(this + 7652) <= 0.0 )
      v20 = v19 * *(double *)(this + 7652);
    else
      v20 = *(double *)(this + 7652);
    a2[38] = v20;
    if ( *(double *)(this + 7660) <= 0.0 )
      v21 = v19 * *(double *)(this + 7660);
    else
      v21 = *(double *)(this + 7660);
    a2[43] = v21;
    if ( *(double *)(this + 7668) <= 0.0 )
      v22 = v19 * *(double *)(this + 7668);
    else
      v22 = *(double *)(this + 7668);
    a2[48] = v22;
    v43 = *(double *)(this + 96);
    ParticleCollisionEffect((int)(a2 + 38), v43, (int)&v51, (int)&v48, *(_DWORD *)(*(_DWORD *)(this + 7936) + 18580));
  }
  v23 = 0;
  v47 = (double *)(this + 5728);
  v45 = this + 5856;
  v44 = (double *)(this + 5872);
  do
  {
    if ( *v44 < 0.0 )
    {
      if ( *(_DWORD *)v45 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v45 + 84) + 40) )
        {
          v24 = *(_DWORD *)(this + 5616);
          TransformApply3D((double *)(v24 + 28), (double *)(v24 + 4), v47, v58);
          v25 = v58[0] - *(double *)(v24 + 4);
          v26 = v58[1] - *(double *)(v24 + 12);
          v27 = v58[2] - *(double *)(v24 + 20);
          v55 = v27 * *(double *)(v24 + 132) - v26 * *(double *)(v24 + 140);
          v56 = v25 * *(double *)(v24 + 140) - v27 * *(double *)(v24 + 124);
          v28 = v26 * *(double *)(v24 + 124) - v25 * *(double *)(v24 + 132);
          v55 = v55 + *(double *)(v24 + 100);
          v56 = v56 + *(double *)(v24 + 108);
          v29 = v28 + *(double *)(v24 + 116);
          if ( v55 * v55 + v56 * v56 + v29 * v29 > 25.0 )
          {
            v54[0] = v55 * 0.5;
            v54[1] = v56 * 0.5 + 3.0;
            v54[2] = v29 * 0.5;
            SetWheelContactFlags(v23, 15, 10, v54);
          }
        }
      }
    }
    ++v23;
    ++v44;
    v45 += 4;
    v47 += 3;
  }
  while ( v23 < 4 );
  HIWORD(result) = HIWORD(a2);
  v31 = a2 + 122;
  v32 = (double *)(this + 1680);
  v33 = 4;
  do
  {
    v35 = (*v32 - 1023.16) * 0.004;
    v36 = v35 < 0.0;
    v37 = 0;
    v38 = v35 == 0.0;
    LOWORD(result) = v34;
    if ( v35 >= 0.0 )
    {
      v39 = v35 < 1.0;
      v40 = 0;
      v41 = v35 == 1.0;
      LOWORD(result) = v34;
      if ( v35 > 1.0 )
        v35 = 1.0;
    }
    else
    {
      v35 = 0.0;
    }
    *v31 = v35;
    v32 = (double *)((char *)v32 + 1124);
    v31 += 74;
    --v33;
  }
  while ( v33 );
  return result;
}
