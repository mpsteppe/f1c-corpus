void __thiscall sub_430ED0(int this, int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  _BYTE *v12; // ecx
  int v13; // edi
  int v14; // ebx
  char v15; // al
  char v16; // al
  char v17; // al
  char v18; // al
  int v19; // ebx
  int v20; // edi
  char v21; // al
  char v22; // al
  char v23; // bl
  int v24; // edi
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int *v30; // edi
  int v31; // ebx
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // ecx
  int v38; // eax
  int v39; // edi
  int v40; // eax
  bool v41; // bl
  char v42; // al
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // edx
  int v47; // ecx
  int v48; // edx
  int v49; // edi
  int v50; // ecx
  int v51; // ebx
  long double v52; // st5
  char v53; // [esp+Fh] [ebp-79h]
  double v54; // [esp+10h] [ebp-78h]
  int v55; // [esp+10h] [ebp-78h]
  double v56; // [esp+18h] [ebp-70h]
  double v57; // [esp+18h] [ebp-70h]
  double v58; // [esp+18h] [ebp-70h]
  double v59; // [esp+18h] [ebp-70h]
  double v60; // [esp+18h] [ebp-70h]
  double v61; // [esp+18h] [ebp-70h]
  double v62; // [esp+18h] [ebp-70h]
  char String[32]; // [esp+28h] [ebp-60h] BYREF
  char String1[64]; // [esp+48h] [ebp-40h] BYREF

  v3 = a3;
  if ( a2 == -1 || a3 == -1 )
  {
    v53 = 1;
    v5 = 44;
    v6 = 50;
LABEL_8:
    v7 = v5;
    if ( v5 <= v6 )
    {
      v8 = (v5 << 6) + this + 3012;
      do
      {
        if ( v7 < 50 )
        {
          if ( *(_BYTE *)(v8 + 72) )
          {
            v9 = *(_DWORD *)(v8 + 64);
            if ( *(_DWORD *)v8 >= v9 )
            {
              v3 = a3;
              *(_DWORD *)v8 = v9 - 1 < 0 ? 0 : v9 - 1;
            }
          }
        }
        if ( v7 > 44 )
        {
          v10 = *(_DWORD *)(v8 - 64);
          if ( *(_DWORD *)v8 <= v10 )
          {
            v11 = v10 + 1;
            if ( *(_DWORD *)(v8 - 4) - 1 < v11 )
              v11 = *(_DWORD *)(v8 - 4) - 1;
            v3 = a3;
            *(_DWORD *)v8 = v11;
          }
        }
        ++v7;
        v8 += 64;
      }
      while ( v7 <= v6 );
    }
    goto LABEL_20;
  }
  v53 = 0;
  if ( a2 == 4 && a3 >= 44 && a3 <= 50 )
  {
    v5 = a3;
    v6 = a3;
    goto LABEL_8;
  }
LABEL_20:
  if ( *(_BYTE *)(this + 6536) )
  {
    sub_430E10((_BYTE *)this, this + 4080, this + 4144);
    sub_430E10(v12, this + 4208, this + 4272);
    sub_430E10((_BYTE *)this, this + 4464, this + 4528);
    sub_430E10((_BYTE *)this, this + 4592, this + 4656);
    v13 = this + 496;
    v14 = 4;
    do
    {
      sub_430E10((_BYTE *)this, v13, v13 + 64);
      sub_430E10((_BYTE *)this, v13 + 128, v13 + 192);
      v13 += 704;
      --v14;
    }
    while ( v14 );
  }
  else
  {
    v15 = a2 == -1 && v3 == 17;
    sub_430E40(this + 4080, this + 4144, v15);
    v16 = a2 == -1 && a3 == 19;
    sub_430E40(this + 4208, this + 4272, v16);
    v17 = a2 == -1 && a3 == 23;
    sub_430E40(this + 4464, this + 4528, v17);
    v18 = a2 == -1 && a3 == 25;
    sub_430E40(this + 4592, this + 4656, v18);
    v19 = 0;
    v20 = this + 496;
    do
    {
      v21 = a2 == v19 && a3 == 5;
      sub_430E40(v20, v20 + 64, v21);
      v22 = a2 == v19 && a3 == 7;
      sub_430E40(v20 + 128, v20 + 192, v22);
      ++v19;
      v20 += 704;
    }
    while ( v19 < 4 );
  }
  if ( *(_DWORD *)(this + 6544) != 1 )
    return;
  v23 = v53;
  v24 = a2;
  if ( v53 )
    goto LABEL_145;
  if ( a2 != 4 )
  {
LABEL_64:
    if ( a2 != 2 && a2 != 3 || a3 != 4 )
    {
LABEL_86:
      if ( a2 != 4 )
        goto LABEL_109;
      goto LABEL_87;
    }
    v24 = a2;
LABEL_68:
    if ( v24 == 2 || v24 == 3 )
      v28 = v24;
    else
      v28 = 2;
    if ( v24 == 2 || v24 == 3 )
      v29 = v24;
    else
      v29 = 3;
    if ( v28 <= v29 )
    {
      v30 = (int *)(704 * v28 + this + 452);
      v31 = v29 - v28 + 1;
      do
      {
        if ( !sub_4E8E50(String, 32, aMinrearspring, 0) )
        {
          v58 = atof(String);
          if ( (double)*v30 * *(double *)(v30 - 3) + *(double *)(v30 - 5) <= v58 )
          {
            v32 = *(v30 - 1) - 1;
            do
            {
              v33 = *v30;
              if ( *v30 >= v32 )
                break;
              *v30 = v33 + 1;
            }
            while ( (double)(v33 + 1) * *(double *)(v30 - 3) + *(double *)(v30 - 5) <= v58 );
          }
        }
        v30 += 176;
        --v31;
      }
      while ( v31 );
      v23 = v53;
    }
    if ( v23 )
      goto LABEL_88;
    goto LABEL_86;
  }
  if ( a3 == 28 )
  {
LABEL_145:
    if ( !sub_4E8E50(String, 32, aMinrearspoiler, 0) )
    {
      v56 = atof(String);
      if ( (double)*(int *)(this + 4804) * *(double *)(this + 4792) + *(double *)(this + 4784) <= v56 )
      {
        v25 = *(_DWORD *)(this + 4800) - 1;
        do
        {
          v26 = *(_DWORD *)(this + 4804);
          if ( v26 >= v25 )
            break;
          *(_DWORD *)(this + 4804) = v26 + 1;
        }
        while ( (double)(v26 + 1) * *(double *)(this + 4792) + *(double *)(this + 4784) <= v56 );
      }
    }
    if ( !sub_4E8E50(String, 32, aMaxrearspoiler, 0) )
    {
      v57 = atof(String);
      if ( (double)*(int *)(this + 4804) * *(double *)(this + 4792) + *(double *)(this + 4784) >= v57 )
      {
        do
        {
          v27 = *(_DWORD *)(this + 4804);
          if ( v27 <= 0 )
            break;
          *(_DWORD *)(this + 4804) = v27 - 1;
        }
        while ( (double)(v27 - 1) * *(double *)(this + 4792) + *(double *)(this + 4784) >= v57 );
      }
    }
    if ( v53 )
      goto LABEL_68;
    goto LABEL_64;
  }
LABEL_87:
  if ( a3 != 2 )
    goto LABEL_94;
LABEL_88:
  if ( !sub_4E8E50(String, 32, aMaxrearweight, 0) )
  {
    v59 = atof(String);
    if ( (double)*(int *)(this + 3140) * *(double *)(this + 3128) + *(double *)(this + 3120) >= v59 )
    {
      do
      {
        v34 = *(_DWORD *)(this + 3140);
        if ( v34 <= 0 )
          break;
        *(_DWORD *)(this + 3140) = v34 - 1;
      }
      while ( (double)(v34 - 1) * *(double *)(this + 3128) + *(double *)(this + 3120) >= v59 );
    }
  }
  if ( v23 )
    goto LABEL_95;
  if ( a2 != 4 )
  {
LABEL_109:
    v39 = a2;
    goto LABEL_110;
  }
LABEL_94:
  if ( a3 != 4 )
    goto LABEL_109;
LABEL_95:
  if ( !sub_4E8E50(String, 32, aMaxfuelcapacit, 0) )
  {
    v60 = atof(String);
    if ( (double)(*(_DWORD *)(this + 3264) - 1) * *(double *)(this + 3256) + *(double *)(this + 3248) >= v60 )
    {
      do
      {
        v35 = *(_DWORD *)(this + 3264);
        if ( v35 <= 1 )
          break;
        v36 = v35 - 1;
        *(_DWORD *)(this + 3264) = v36;
      }
      while ( (double)(v36 - 1) * *(double *)(this + 3256) + *(double *)(this + 3248) >= v60 );
    }
    v37 = *(_DWORD *)(this + 3268);
    v38 = *(_DWORD *)(this + 3264) - 1;
    if ( v37 >= 0 )
    {
      if ( v37 > v38 )
        *(_DWORD *)(this + 3268) = v38;
    }
    else
    {
      *(_DWORD *)(this + 3268) = 0;
    }
  }
  v39 = a2;
  if ( v23 || a2 == 4 && a3 == 4 )
  {
    if ( dword_75CBB0 )
    {
      v40 = *(_DWORD *)(this + 3264);
      if ( v40 >= 1 )
        *(_DWORD *)(this + 3268) = v40 - 1;
    }
  }
LABEL_110:
  v41 = 0;
  if ( !sub_4E8E50(String1, 64, aTrackType, 0) )
    v41 = _strcmpi(String1, aRoadCourse) == 0;
  v42 = v53;
  if ( v53 )
    goto LABEL_115;
  if ( v39 != 4 )
  {
    if ( a3 != 2 )
    {
LABEL_130:
      if ( v39 != 4 )
        goto LABEL_136;
      goto LABEL_131;
    }
LABEL_115:
    if ( v41 )
    {
      v43 = this + 1712;
      v61 = (double)*(int *)(this + 1732) * *(double *)(this + 1720) + *(double *)(this + 1712);
      if ( v61 < 0.1523746 )
      {
        v54 = (double)*(int *)(this + 2436) * *(double *)(this + 2424) + *(double *)(this + 2416);
        if ( v54 < 0.1523746 )
        {
          if ( v39 != 2 && (v39 == 3 || v61 <= v54) )
            v43 = this + 2416;
          v44 = *(_DWORD *)(v43 + 16);
          if ( *(_DWORD *)(v43 + 20) < v44 )
          {
            do
            {
              v45 = *(_DWORD *)(v43 + 20);
              if ( (double)v45 * *(double *)(v43 + 8) + *(double *)v43 >= 0.1523746 )
                break;
              *(_DWORD *)(v43 + 20) = v45 + 1;
            }
            while ( v45 + 1 < v44 );
          }
        }
      }
    }
    else
    {
      v46 = *(_DWORD *)(this + 2432);
      if ( *(_DWORD *)(this + 2436) < v46 )
      {
        do
        {
          v47 = *(_DWORD *)(this + 2436);
          if ( (double)v47 * *(double *)(this + 2424) + *(double *)(this + 2416) >= 0.1523746 )
            break;
          *(_DWORD *)(this + 2436) = v47 + 1;
        }
        while ( v47 + 1 < v46 );
      }
    }
    v42 = v53;
    v39 = a2;
    if ( v53 )
      goto LABEL_132;
    goto LABEL_130;
  }
LABEL_131:
  if ( a3 )
    return;
LABEL_132:
  if ( !v41 )
    *(_DWORD *)(this + 3012) = 0;
  if ( !v42 )
  {
    if ( v39 == 4 )
      return;
LABEL_136:
    if ( a3 != 2 )
      return;
  }
  v48 = *(_DWORD *)(this + 1024);
  v49 = *(_DWORD *)(this + 1028);
  v50 = 0;
  v62 = 1.797693134862316e308;
  v55 = 0;
  if ( v48 > 0 )
  {
    do
    {
      v51 = v50;
      v52 = fabs(
              (double)v55 * *(double *)(this + 1016)
            + *(double *)(this + 1008)
            - ((double)*(int *)(this + 324) * *(double *)(this + 312)
             + *(double *)(this + 304)
             - ((double)*(int *)(this + 1732) * *(double *)(this + 1720)
              + *(double *)(this + 1712))
             + (double)*(int *)(this + 2436) * *(double *)(this + 2424)
             + *(double *)(this + 2416)));
      if ( v52 < v62 )
      {
        v62 = v52;
        v49 = v50;
      }
      v55 = ++v50;
    }
    while ( v50 < v48 );
    *(_DWORD *)(this + 1028) = v51;
  }
  *(_DWORD *)(this + 1028) = v49;
}
