void __thiscall sub_519DE0(float *this, float a2)
{
  double v3; // st7
  int v4; // eax
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  double v9; // st7
  float *v10; // eax
  int v11; // ecx
  float *v12; // ecx
  int v13; // edx
  double v14; // st7
  double v15; // st6
  double v16; // st7
  float *v17; // eax
  int v18; // ecx
  double v19; // st6
  double v20; // st5
  double v21; // st6
  unsigned __int8 v23; // c0
  unsigned __int8 v24; // c2
  int i; // edi
  double v26; // st7
  double v27; // st7
  int v28; // ecx
  int k; // eax
  _DWORD *v30; // ecx
  double v31; // st6
  float *v32; // ecx
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  int v40; // ecx
  double v41; // st7
  double v42; // st7
  double v43; // st7
  int j; // eax
  unsigned __int8 v46; // c0
  unsigned __int8 v47; // c2
  double v48; // st7
  bool v49; // zf
  int v50; // eax
  unsigned __int8 v52; // c0
  unsigned __int8 v53; // c2
  int v54; // eax
  int v55; // [esp-Ch] [ebp-20h]
  int v56; // [esp-8h] [ebp-1Ch]
  double v57; // [esp+Ch] [ebp-8h]

  if ( this[4677] > 0.0 )
  {
    v3 = this[4677] - this[4684] * this[4680] * this[4419] * a2;
    this[4677] = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)this + 20836;
      this[4677] = 0.0;
      if ( !*(_DWORD *)(v4 + 60) )
        *(_DWORD *)(v4 + 60) = 8;
    }
  }
  v5 = this[4677] * 0.72600001 + this[4395];
  this[4396] = v5;
  this[4397] = 1.0 / v5;
  if ( !(v7 | v8) )
  {
    v9 = 0.0;
    v10 = this + 4443;
    v11 = 4;
    do
    {
      v9 = v9 + *v10;
      v10 += 62;
      --v11;
    }
    while ( v11 );
    v12 = this + 4467;
    v13 = 4;
    v14 = 1.0 - v9 * 0.2325;
    do
    {
      if ( *(v12 - 27) > 0.0 )
      {
        v15 = *v12 - v14 * *(v12 - 27) * v12[1] * (double)*(int *)dword_7693B0 * a2;
        *v12 = v15;
        if ( v15 < 0.6875 )
          *v12 = 0.6875;
      }
      v12 += 62;
      --v13;
    }
    while ( v13 );
  }
  v16 = flt_7DAB04;
  v17 = this + 4463;
  v18 = 4;
  v19 = (flt_7D7408 - flt_7D7404) * flt_7DAB04 + flt_7D7404;
  do
  {
    v20 = v17[1];
    v17 += 62;
    --v18;
    *(v17 - 63) = ((v20 - *(v17 - 62)) * v16 + *(v17 - 62)) * *(v17 - 58) * this[4839] * v19;
  }
  while ( v18 );
  if ( fabs(dbl_7DA9D0 - this[4840]) > 5.5 )
  {
    v21 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
    this[4840] = v21 + v21 + dbl_7DA9D0;
    sub_513830((int)this, 0);
  }
  if ( dword_75CBB4 >= 5
    && (!sub_4DEB10((_DWORD *)(*(_DWORD *)this + 20836)) || !(v23 | v24))
    && dword_75CBB0 != 5
    && (!sub_4EED40(*(_DWORD **)this) || !sub_42DBA0()) )
  {
    for ( i = 0; i < 5; ++i )
    {
      v57 = this[i + 4931];
      if ( v57 >= 0.0 )
      {
        v26 = this[i + 4931] - a2;
        this[i + 4931] = v26;
        if ( v26 < 0.0 )
        {
          switch ( i )
          {
            case 0:
              if ( !*(_DWORD *)(*(_DWORD *)this + 20896) )
                *(_DWORD *)(*(_DWORD *)this + 20896) = 1;
              if ( this[4685] * 0.5 <= this[4684] )
              {
                if ( this[4924] != 0.0 || this[4925] != 0.0 || this[4926] != 0.0 )
                {
                  v28 = dword_7D3C50;
LABEL_49:
                  if ( this[4924] != -789.0 && this[4925] != -789.0 && this[4926] != -789.0 )
                  {
                    if ( v57 != 1.175494350822288e-38
                      || (v34 = flt_7D4054[(unsigned __int8)v28], ++v28, dword_7D3C50 = v28, v34 > 0.30000001) )
                    {
                      v35 = flt_7D3C54[(unsigned __int8)v28++];
                      dword_7D3C50 = v28;
                      if ( v35 < 0.40000001 )
                      {
                        this[4924] = -789.0;
                        goto LABEL_60;
                      }
                      if ( v35 < 0.64999998 )
                      {
                        this[4925] = -789.0;
                        goto LABEL_60;
                      }
                      if ( v35 < 0.89999998 )
                      {
                        this[4926] = -789.0;
LABEL_60:
                        v28 = dword_7D3C50;
                      }
                    }
                  }
                  if ( this[4924] == -789.0 )
                  {
                    v36 = flt_7D3C54[(unsigned __int8)v28];
                    dword_7D3C50 = v28 + 1;
                    this[4924] = 1.0 - v36 * 0.30000001;
                    v37 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
                    if ( v37 < 0.2 )
                      this[4925] = v37 + 0.1;
                  }
                  else if ( this[4925] == -789.0 )
                  {
                    v38 = flt_7D3C54[(unsigned __int8)v28];
                    dword_7D3C50 = v28 + 1;
                    this[4925] = 1.0 - v38 * 0.30000001;
                    v39 = flt_7D3C54[(unsigned __int8)dword_7D3C50];
                    v40 = ++dword_7D3C50;
                    if ( v39 >= 0.2 )
                    {
                      if ( v39 < 0.80000001 )
                      {
                        v41 = flt_7D3C54[(unsigned __int8)v40];
                        dword_7D3C50 = v40 + 1;
                        this[4926] = 1.0 - v41 * 0.30000001;
                      }
                    }
                    else
                    {
                      this[4924] = v39 + 0.1;
                    }
                  }
                  else if ( this[4926] == -789.0 )
                  {
                    v42 = flt_7D3C54[(unsigned __int8)v28];
                    dword_7D3C50 = v28 + 1;
                    this[4926] = 1.0 - v42 * 0.30000001;
                    v43 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 0.30000001;
                    this[4925] = 1.0 - v43;
                  }
                  for ( j = 0; j < *((_DWORD *)this + 4691); ++j )
                    *(_DWORD *)(*((_DWORD *)this + 4688) + 8 * j + 4) = 0;
                  v56 = 0;
                  goto LABEL_96;
                }
                v27 = flt_7D3C54[(unsigned __int8)dword_7D3C50];
                v28 = ++dword_7D3C50;
                if ( v27 >= 0.5 )
                  goto LABEL_49;
                for ( k = 0; k < *((_DWORD *)this + 4691); *v32 = v31 * 0.89999998 )
                {
                  v30 = (_DWORD *)*((_DWORD *)this + 4688);
                  v31 = *(float *)&v30[2 * k + 1];
                  v32 = (float *)&v30[2 * k++ + 1];
                }
                if ( v27 >= 0.30000001 )
                {
                  if ( v27 >= 0.40000001 )
                  {
                    this[4926] = -789.0;
                    v33 = (v27 - 0.40000001) * 50.0;
                  }
                  else
                  {
                    this[4925] = -789.0;
                    v33 = (v27 - 0.30000001) * 450.0;
                  }
                }
                else
                {
                  v33 = v27 * 1000.0;
                  this[4924] = -789.0;
                }
                this[i + 4931] = v33;
                if ( *(_DWORD *)dword_766B6C == 3 && this[i + 4931] > 60.0 )
                  this[i + 4931] = 60.0;
                if ( !*((_DWORD *)this + 4930) )
                  *((_DWORD *)this + 4930) = 1;
              }
              else
              {
                if ( v57 != 1.175494350822288e-38 )
                  goto LABEL_94;
                LODWORD(this[i + 4931]) = &unk_800000;
              }
              break;
            case 1:
              if ( !*(_DWORD *)(*(_DWORD *)this + 20896) )
                *(_DWORD *)(*(_DWORD *)this + 20896) = 5;
              if ( this[4421] == 0.0 || v46 | v47 )
                goto LABEL_94;
              v48 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
              v56 = 1;
              v55 = *(_DWORD *)this;
              if ( v48 <= 0.60000002 )
                this[4723] = this[4723] * 0.03125;
              else
                this[4728] = this[4728] * 0.03125;
              goto LABEL_97;
            case 2:
              if ( !*(_DWORD *)(*(_DWORD *)this + 20896) )
                *(_DWORD *)(*(_DWORD *)this + 20896) = 2;
              if ( this[4685] * 0.5 <= this[4684] )
              {
                v49 = *((_DWORD *)this + 4930) == 0;
                *((_BYTE *)this + 18826) = 1;
                if ( v49 )
                  *((_DWORD *)this + 4930) = 1;
                nullsub_2(*(_DWORD *)this, 2);
              }
              else
              {
                this[i + 4931] = 0.0;
              }
              break;
            case 3:
              if ( !*(_DWORD *)(*(_DWORD *)this + 20896) )
                *(_DWORD *)(*(_DWORD *)this + 20896) = 4;
              if ( v52 | v53 )
              {
LABEL_94:
                this[i + 4931] = 0.0;
              }
              else
              {
                v54 = rand() % 4;
                this[62 * v54 + 4447] = this[62 * v54 + 4447] + 0.050000001;
                v56 = 3;
LABEL_96:
                v55 = *(_DWORD *)this;
LABEL_97:
                *((_DWORD *)this + 4930) = 2;
                nullsub_2(v55, v56);
              }
              break;
            case 4:
              if ( !*(_DWORD *)(*(_DWORD *)this + 20896) )
                *(_DWORD *)(*(_DWORD *)this + 20896) = 0;
              v50 = rand() % 4;
              this[62 * v50 + 4467] = this[62 * v50 + 4467] * 0.5;
              sub_421590(*(_DWORD *)this, 17, v50);
              nullsub_2(*(_DWORD *)this, 4);
              break;
            default:
              break;
          }
        }
      }
    }
  }
}
