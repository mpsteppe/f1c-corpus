void __thiscall sub_4FEAF0(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebp
  double v5; // st7
  char v6; // bl
  double v7; // st6
  int v8; // ecx
  int v9; // edx
  long double v10; // st7
  long double v11; // st6
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // ecx
  int v18; // edi
  int v19; // eax
  double v20; // st7
  int v21; // edi
  double v22; // st7
  int v23; // eax
  double v24; // st7
  double v25; // st7
  int v26; // ecx
  _DWORD *v27; // ebx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // edx
  int v32; // edi
  int v33; // esi
  int v34; // eax
  int v35; // ecx
  int v36; // edx
  int v37; // edi
  int v38; // eax
  int v39; // edx
  int i; // eax
  float v41; // [esp+0h] [ebp-B74h]
  float v42; // [esp+4h] [ebp-B70h]
  int v43; // [esp+8h] [ebp-B6Ch]
  int v44; // [esp+1Ch] [ebp-B58h]
  float v45; // [esp+1Ch] [ebp-B58h]
  float v46; // [esp+20h] [ebp-B54h]
  int v47; // [esp+24h] [ebp-B50h]
  float v48; // [esp+24h] [ebp-B50h]
  float v49; // [esp+28h] [ebp-B4Ch]
  float v50; // [esp+2Ch] [ebp-B48h]
  float v51; // [esp+30h] [ebp-B44h]
  float v52; // [esp+30h] [ebp-B44h]
  float v53[720]; // [esp+34h] [ebp-B40h]

  v2 = *(_DWORD *)(this + 60);
  v3 = 0;
  if ( !v2 )
    return;
  sub_4FDE00(this, *(float *)(v2 + 8));
  *(_DWORD *)(this + 56) = *(_DWORD *)(this + 60);
  *(_DWORD *)(this + 4) = 0;
  v4 = dword_5C329C;
  v5 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.125;
  v6 = 0;
  v47 = 0;
  do
  {
    v51 = v5 + 0.375;
    v7 = *(float *)(this + 36) - v51;
    v53[v3] = v7;
    if ( v7 > 0.0 )
      v6 = 1;
    v42 = ((double)v47 * 10.0 + 10.0) * *(float *)this;
    v41 = *(float *)this * 10.0;
    sub_4FDEB0((_DWORD *)this, v41, v42, v4);
    v47 = ++v3;
  }
  while ( v3 < 720 );
  if ( !v6 )
    return;
  v8 = dword_8AAE70;
  v49 = 0.0;
  do
  {
    v9 = 0;
    v48 = 0.0;
    v50 = 3.4028235e38;
    v44 = 0;
    do
    {
      if ( v53[v9] <= 0.0 )
        goto LABEL_19;
      v10 = fabs(v49 - (double)v44 * 10.0);
      if ( v10 == 0.0 )
      {
LABEL_14:
        v11 = 0.0049999999;
        goto LABEL_15;
      }
      v11 = v53[v9] / v10;
      if ( v11 >= 0.0 )
      {
        if ( v11 > 0.0049999999 )
          goto LABEL_14;
      }
      else
      {
        v11 = 0.0;
      }
LABEL_15:
      if ( v48 < v11 )
        v48 = v11;
      if ( v50 > v10 )
        v50 = v10;
LABEL_19:
      v44 = ++v9;
    }
    while ( v9 < 720 );
    if ( v48 > 0.0 && v50 < 300.0 )
    {
      v12 = (unsigned __int8)v8++;
      v45 = v50 * 0.0033333334;
      v13 = flt_8AAE74[v12];
      dword_8AAE70 = v8;
      if ( v13 < 0.12 - v45 * 0.059999999 )
      {
        v14 = flt_8AAE74[(unsigned __int8)v8++];
        dword_8AAE70 = v8;
        v15 = v48 * 200.0 * 0.25 + 0.80000001 - v45 * 0.30000001 - v14 * 0.34999999;
        v46 = v15;
        if ( v15 > 0.0 )
        {
          if ( v46 > 1.0 )
            v46 = 1.0;
          v16 = flt_8AAE74[(unsigned __int8)v8];
          v17 = v8 + 1;
          dword_8AAE70 = v17;
          v52 = v45 * 0.5;
          if ( v16 < flt_7CF8CC - v52 )
          {
            v18 = sub_587C03(12);
            *(float *)v18 = v49;
            *(_DWORD *)(v18 + 4) = 1;
            *(float *)(v18 + 8) = v46;
            v19 = sub_587C03(12);
            if ( v19 )
            {
              *(_DWORD *)v19 = v18;
              *(_DWORD *)(v19 + 4) = 0;
              *(_BYTE *)(v19 + 8) = 1;
            }
            else
            {
              v19 = 0;
            }
            if ( *(_DWORD *)(this + 84) )
            {
              *(_DWORD *)(*(_DWORD *)(this + 88) + 4) = v19;
            }
            else
            {
              *(_DWORD *)(this + 84) = v19;
              *(_DWORD *)(this + 92) = v19;
            }
            *(_DWORD *)(this + 88) = v19;
            ++*(_DWORD *)(this + 96);
            v17 = dword_8AAE70;
          }
          v20 = flt_8AAE74[(unsigned __int8)v17];
          v8 = v17 + 1;
          dword_8AAE70 = v8;
          if ( v20 < flt_7CF8F0 - v52 )
          {
            v21 = sub_587C03(12);
            v22 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
            *(_DWORD *)(v21 + 4) = 0;
            *(float *)(v21 + 8) = v46;
            *(float *)v21 = (v45 + 1.0) * v22 + v45 * 6.0 + v49;
            v23 = sub_587C03(12);
            if ( v23 )
            {
              *(_DWORD *)v23 = v21;
              *(_DWORD *)(v23 + 4) = 0;
              *(_BYTE *)(v23 + 8) = 1;
            }
            else
            {
              v23 = 0;
            }
            if ( *(_DWORD *)(this + 84) )
            {
              *(_DWORD *)(*(_DWORD *)(this + 88) + 4) = v23;
            }
            else
            {
              *(_DWORD *)(this + 84) = v23;
              *(_DWORD *)(this + 92) = v23;
            }
            *(_DWORD *)(this + 88) = v23;
            ++*(_DWORD *)(this + 96);
            v8 = dword_8AAE70;
          }
        }
      }
    }
    v24 = flt_8AAE74[(unsigned __int8)v8++];
    dword_8AAE70 = v8;
    v25 = v24 + v24 + 2.0 + v49;
    v49 = v25;
  }
  while ( v25 < 7200.0 );
  v26 = *(_DWORD *)(this + 84);
  v27 = (_DWORD *)(this + 84);
  v28 = 0;
  v29 = v26;
  if ( v26 )
  {
    do
    {
      v29 = *(_DWORD *)(v29 + 4);
      ++v28;
    }
    while ( v29 );
    if ( v28 >= 2 )
    {
      v30 = v28 / 2 - 1;
      v31 = *(_DWORD *)(this + 84);
      if ( v30 > 0 )
      {
        do
        {
          --v30;
          v31 = *(_DWORD *)(v31 + 4);
        }
        while ( v30 );
      }
      v32 = *(_DWORD *)(v31 + 4);
      v43 = *(_DWORD *)(this + 84);
      *(_DWORD *)(v31 + 4) = 0;
      v33 = sub_4FF2B0(v43);
      v34 = sub_4FF2B0(v32);
      v35 = v34;
      v36 = v33;
      if ( v33 )
      {
        if ( v34 )
        {
          if ( **(float **)v33 >= (double)**(float **)v34 )
          {
            v33 = v34;
            v37 = v34;
            v35 = *(_DWORD *)(v34 + 4);
          }
          else
          {
            v36 = *(_DWORD *)(v33 + 4);
            v37 = v33;
          }
          if ( v36 )
          {
            while ( v35 )
            {
              if ( **(float **)v36 >= (double)**(float **)v35 )
              {
                v38 = v35;
                v35 = *(_DWORD *)(v35 + 4);
              }
              else
              {
                v38 = v36;
                v36 = *(_DWORD *)(v36 + 4);
              }
              *(_DWORD *)(v37 + 4) = v38;
              v37 = v38;
              if ( !v36 )
                goto LABEL_59;
            }
            *(_DWORD *)(v37 + 4) = v36;
          }
          else
          {
LABEL_59:
            if ( v35 )
              *(_DWORD *)(v37 + 4) = v35;
            else
              *(_DWORD *)(v37 + 4) = 0;
          }
        }
      }
      else
      {
        v33 = v34;
      }
      v26 = v33;
    }
  }
  *v27 = v26;
  v39 = v26;
  if ( v26 )
  {
    for ( i = *(_DWORD *)(v26 + 4); i; i = *(_DWORD *)(i + 4) )
      v39 = i;
  }
  v27[1] = v39;
  v27[2] = v26;
}
