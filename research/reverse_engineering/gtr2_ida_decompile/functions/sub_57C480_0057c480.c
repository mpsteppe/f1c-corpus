void __thiscall sub_57C480(float *this, float a2)
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
  int i; // edi
  double v23; // st7
  double v24; // st7
  int v25; // ecx
  int k; // eax
  int v27; // ecx
  double v28; // st6
  float *v29; // ecx
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  int v37; // ecx
  double v38; // st7
  double v39; // st7
  double v40; // st7
  int j; // eax
  unsigned __int8 v43; // c0
  unsigned __int8 v44; // c2
  double v45; // st7
  double v46; // st7
  double v47; // st7
  bool v48; // zf
  unsigned __int8 v50; // c0
  unsigned __int8 v51; // c2
  int v52; // eax
  double v53; // [esp+8h] [ebp-8h]

  if ( this[4295] > 0.0 )
  {
    v3 = this[4295] - this[4303] * this[4298] * this[4033] * a2;
    this[4295] = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)this + 19272;
      this[4295] = 0.0;
      if ( !*(_DWORD *)(v4 + 112) )
        *(_DWORD *)(v4 + 112) = 9;
    }
  }
  v5 = this[4295] * 0.74000001 + this[4017] + this[4008];
  this[4009] = v5;
  this[4010] = 1.0 / v5;
  if ( !(v7 | v8) )
  {
    v9 = 0.0;
    v10 = this + 4057;
    v11 = 4;
    do
    {
      v9 = v9 + *v10;
      v10 += 63;
      --v11;
    }
    while ( v11 );
    v12 = this + 4081;
    v13 = 4;
    v14 = 1.0 - v9 * 0.2325;
    do
    {
      if ( *(v12 - 27) > 0.0 )
      {
        v15 = *v12 - v14 * *(v12 - 27) * v12[1] * (double)dword_B72F4C * a2;
        *v12 = v15;
        if ( v15 < 0.6875 )
          *v12 = 0.6875;
      }
      v12 += 63;
      --v13;
    }
    while ( v13 );
  }
  v16 = sub_592970(&dword_FB1EF8);
  v17 = this + 4077;
  v18 = 4;
  v19 = (flt_BE2798 - flt_BE2794) * v16 + flt_BE2794;
  do
  {
    v20 = v17[1];
    v17 += 63;
    --v18;
    *(v17 - 64) = ((v20 - *(v17 - 63)) * v16 + *(v17 - 63)) * *(v17 - 59) * this[4511] * v19;
  }
  while ( v18 );
  if ( fabs(dbl_FB1D18 - this[4512]) > 5.5 )
  {
    v21 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
    this[4512] = v21 + v21 + dbl_FB1D18;
    sub_579710((int)this, 0);
  }
  if ( sub_551A90() && *(_DWORD *)(*(_DWORD *)this + 19280) != 10 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v53 = this[i + 4604];
      if ( v53 >= 0.0 )
      {
        v23 = this[i + 4604] - a2;
        this[i + 4604] = v23;
        if ( v23 < 0.0 )
        {
          switch ( i )
          {
            case 0:
              if ( !*(_DWORD *)(*(_DWORD *)this + 19384) )
                *(_DWORD *)(*(_DWORD *)this + 19384) = 1;
              if ( this[4304] * 0.5 > this[4303] )
              {
                if ( v53 != 1.175494350822288e-38 )
                  goto LABEL_84;
                LODWORD(this[i + 4604]) = &byte_800000;
                break;
              }
              if ( this[4597] != 0.0 || this[4598] != 0.0 || this[4599] != 0.0 )
              {
                v25 = dword_BE08A0;
LABEL_43:
                if ( -789.0 != this[4597] && -789.0 != this[4598] && -789.0 != this[4599] )
                {
                  if ( v53 != 1.175494350822288e-38
                    || (v31 = flt_BE0CA4[(unsigned __int8)v25], ++v25, dword_BE08A0 = v25, v31 > 0.30000001) )
                  {
                    v32 = flt_BE08A4[(unsigned __int8)v25++];
                    dword_BE08A0 = v25;
                    if ( v32 < 0.40000001 )
                    {
                      this[4597] = -789.0;
                      goto LABEL_54;
                    }
                    if ( v32 < 0.64999998 )
                    {
                      this[4598] = -789.0;
                      goto LABEL_54;
                    }
                    if ( v32 < 0.89999998 )
                    {
                      this[4599] = -789.0;
LABEL_54:
                      v25 = dword_BE08A0;
                    }
                  }
                }
                if ( -789.0 == this[4597] )
                {
                  v33 = flt_BE08A4[(unsigned __int8)v25];
                  dword_BE08A0 = v25 + 1;
                  this[4597] = 1.0 - v33 * 0.30000001;
                  v34 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
                  if ( v34 < 0.2 )
                    this[4598] = v34 + 0.1;
                }
                else if ( -789.0 == this[4598] )
                {
                  v35 = flt_BE08A4[(unsigned __int8)v25];
                  dword_BE08A0 = v25 + 1;
                  this[4598] = 1.0 - v35 * 0.30000001;
                  v36 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
                  v37 = ++dword_BE08A0;
                  if ( v36 >= 0.2 )
                  {
                    if ( v36 < 0.80000001 )
                    {
                      v38 = flt_BE08A4[(unsigned __int8)v37];
                      dword_BE08A0 = v37 + 1;
                      this[4599] = 1.0 - v38 * 0.30000001;
                    }
                  }
                  else
                  {
                    this[4597] = v36 + 0.1;
                  }
                }
                else if ( -789.0 == this[4599] )
                {
                  v39 = flt_BE08A4[(unsigned __int8)v25];
                  dword_BE08A0 = v25 + 1;
                  this[4599] = 1.0 - v39 * 0.30000001;
                  v40 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.30000001;
                  this[4598] = 1.0 - v40;
                }
                for ( j = 0; j < *((_DWORD *)this + 4310); ++j )
                  *(_DWORD *)(*((_DWORD *)this + 4307) + 8 * j + 4) = 0;
                *((_DWORD *)this + 4603) = 2;
                break;
              }
              v24 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
              v25 = ++dword_BE08A0;
              if ( v24 >= 0.5 )
                goto LABEL_43;
              for ( k = 0; k < *((_DWORD *)this + 4310); *v29 = v28 * 0.89999998 )
              {
                v27 = *((_DWORD *)this + 4307);
                v28 = *(float *)(v27 + 8 * k + 4);
                v29 = (float *)(v27 + 8 * k++ + 4);
              }
              if ( v24 >= 0.30000001 )
              {
                if ( v24 >= 0.40000001 )
                {
                  this[4599] = -789.0;
                  v30 = (v24 - 0.40000001) * 50.0;
                }
                else
                {
                  this[4598] = -789.0;
                  v30 = (v24 - 0.30000001) * 450.0;
                }
              }
              else
              {
                v30 = v24 * 1000.0;
                this[4597] = -789.0;
              }
              this[i + 4604] = v30;
              if ( dword_B6FD6C == 3 && this[i + 4604] > 60.0 )
                this[i + 4604] = 60.0;
              break;
            case 1:
              if ( !*(_DWORD *)(*(_DWORD *)this + 19384) )
                *(_DWORD *)(*(_DWORD *)this + 19384) = 5;
              if ( this[4035] == 0.0 || v43 | v44 )
                goto LABEL_84;
              v45 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              if ( v45 <= 0.60000002 )
              {
                v47 = this[4342];
                *((_DWORD *)this + 4603) = 2;
                this[4342] = v47 * 0.03125;
              }
              else
              {
                v46 = this[4347];
                *((_DWORD *)this + 4603) = 2;
                this[4347] = v46 * 0.03125;
              }
              break;
            case 2:
              if ( !*(_DWORD *)(*(_DWORD *)this + 19384) )
                *(_DWORD *)(*(_DWORD *)this + 19384) = 2;
              if ( this[4304] * 0.5 <= this[4303] )
              {
                v48 = *((_DWORD *)this + 4603) == 0;
                *((_BYTE *)this + 17303) = 1;
                if ( v48 )
                  *((_DWORD *)this + 4603) = 1;
              }
              else
              {
                this[i + 4604] = 0.0;
              }
              break;
            case 3:
              if ( !*(_DWORD *)(*(_DWORD *)this + 19384) )
                *(_DWORD *)(*(_DWORD *)this + 19384) = 4;
              if ( v50 | v51 )
              {
LABEL_84:
                this[i + 4604] = 0.0;
              }
              else
              {
                v52 = rand() % 4;
                this[63 * v52 + 4061] = this[63 * v52 + 4061] + 0.050000001;
                *((_DWORD *)this + 4603) = 2;
              }
              break;
            default:
              break;
          }
        }
      }
    }
  }
}
