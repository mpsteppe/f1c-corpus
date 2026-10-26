void __thiscall sub_4ED960(float *this, float a2)
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
  int k; // eax
  _DWORD *v26; // ecx
  double v27; // st6
  float *v28; // ecx
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  int v35; // ecx
  double v36; // st7
  double v37; // st7
  double v38; // st7
  int j; // eax
  unsigned __int8 v41; // c0
  unsigned __int8 v42; // c2
  double v43; // st7
  bool v44; // zf
  int v45; // ecx
  unsigned __int8 v47; // c0
  unsigned __int8 v48; // c2
  int v49; // eax
  _DWORD *v50; // [esp-10h] [ebp-18h]
  int v51; // [esp-Ch] [ebp-14h]

  if ( this[3678] > 0.0 )
  {
    v3 = this[3678] - this[3685] * this[3681] * this[3420] * a2;
    this[3678] = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)this + 16436;
      this[3678] = 0.0;
      if ( !*(_DWORD *)(v4 + 52) )
        *(_DWORD *)(v4 + 52) = 9;
    }
  }
  v5 = this[3678] * 0.75 + this[3396];
  this[3397] = v5;
  this[3398] = 1.0 / v5;
  if ( !(v7 | v8) )
  {
    v9 = 0.0;
    v10 = this + 3444;
    v11 = 4;
    do
    {
      v9 = v9 + *v10;
      v10 += 62;
      --v11;
    }
    while ( v11 );
    v12 = this + 3468;
    v13 = 4;
    v14 = 1.0 - v9 * 0.2325;
    do
    {
      if ( *(v12 - 27) > 0.0 )
      {
        v15 = *v12 - v14 * *(v12 - 27) * v12[1] * (double)dword_7D0C60 * a2;
        *v12 = v15;
        if ( v15 < 0.75 )
          *v12 = 0.75;
      }
      v12 += 62;
      --v13;
    }
    while ( v13 );
  }
  v16 = flt_8AFEE8;
  v17 = this + 3464;
  v18 = 4;
  v19 = (flt_8ACED4 - flt_8ACED0) * flt_8AFEE8 + flt_8ACED0;
  do
  {
    v20 = v17[1];
    v17 += 62;
    --v18;
    *(v17 - 63) = ((v20 - *(v17 - 62)) * v16 + *(v17 - 62)) * *(v17 - 58) * this[3837] * v19;
  }
  while ( v18 );
  if ( fabs(dbl_8AFEA0 - this[3838]) > 5.5 )
  {
    v21 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
    this[3838] = v21 + v21 + dbl_8AFEA0;
    TireBrushModelForceSolver((int)this, 0);
  }
  if ( sub_4D21D0() )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( this[i + 3929] >= 0.0 )
      {
        v23 = this[i + 3929] - a2;
        this[i + 3929] = v23;
        if ( v23 < 0.0 )
        {
          switch ( i )
          {
            case 0:
              if ( !*(_DWORD *)(*(_DWORD *)this + 16488) )
                *(_DWORD *)(*(_DWORD *)this + 16488) = 1;
              if ( this[3686] * 0.5 <= this[3685] )
              {
                if ( this[3922] != 0.0
                  || this[3923] != 0.0
                  || (v24 = flt_8AAE74[(unsigned __int8)dword_8AAE70], ++dword_8AAE70, v24 >= 0.5) )
                {
                  if ( this[3922] != -789.0 && this[3923] != -789.0 && this[3924] != -789.0 )
                  {
                    v30 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
                    if ( v30 >= 0.40000001 )
                    {
                      if ( v30 >= 0.64999998 )
                      {
                        if ( v30 < 0.89999998 )
                          this[3924] = -789.0;
                      }
                      else
                      {
                        this[3923] = -789.0;
                      }
                    }
                    else
                    {
                      this[3922] = -789.0;
                    }
                  }
                  if ( this[3922] == -789.0 )
                  {
                    v31 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.30000001;
                    this[3922] = 1.0 - v31;
                    v32 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
                    if ( v32 < 0.2 )
                      this[3923] = v32 + 0.1;
                  }
                  else if ( this[3923] == -789.0 )
                  {
                    v33 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.30000001;
                    this[3923] = 1.0 - v33;
                    v34 = flt_8AAE74[(unsigned __int8)dword_8AAE70];
                    v35 = ++dword_8AAE70;
                    if ( v34 >= 0.2 )
                    {
                      if ( v34 < 0.80000001 )
                      {
                        v36 = flt_8AAE74[(unsigned __int8)v35];
                        dword_8AAE70 = v35 + 1;
                        this[3924] = 1.0 - v36 * 0.30000001;
                      }
                    }
                    else
                    {
                      this[3922] = v34 + 0.1;
                    }
                  }
                  else if ( this[3924] == -789.0 )
                  {
                    v37 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.30000001;
                    this[3924] = 1.0 - v37;
                    v38 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.30000001;
                    this[3923] = 1.0 - v38;
                  }
                  for ( j = 0; j < *((_DWORD *)this + 3692); ++j )
                    *(_DWORD *)(*((_DWORD *)this + 3689) + 8 * j + 4) = 0;
                  v51 = 0;
                  v50 = *(_DWORD **)this;
                  goto LABEL_80;
                }
                for ( k = 0; k < *((_DWORD *)this + 3692); *v28 = v27 * 0.89999998 )
                {
                  v26 = (_DWORD *)*((_DWORD *)this + 3689);
                  v27 = *(float *)&v26[2 * k + 1];
                  v28 = (float *)&v26[2 * k++ + 1];
                }
                if ( v24 >= 0.30000001 )
                {
                  if ( v24 >= 0.40000001 )
                  {
                    this[3924] = -789.0;
                    v29 = (v24 - 0.40000001) * 50.0;
                  }
                  else
                  {
                    this[3923] = -789.0;
                    v29 = (v24 - 0.30000001) * 450.0;
                  }
                }
                else
                {
                  v29 = v24 * 1000.0;
                  this[3922] = -789.0;
                }
                this[i + 3929] = v29;
                if ( dword_7CEA5C == 3 && this[i + 3929] > 60.0 )
                  this[i + 3929] = 60.0;
              }
              else
              {
                this[i + 3929] = 0.0;
              }
              break;
            case 1:
              if ( !*(_DWORD *)(*(_DWORD *)this + 16488) )
                *(_DWORD *)(*(_DWORD *)this + 16488) = 5;
              if ( this[3422] == 0.0 || v41 | v42 )
                goto LABEL_78;
              v43 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              v51 = 1;
              v50 = *(_DWORD **)this;
              if ( v43 <= 0.60000002 )
                this[3724] = this[3724] * 0.03125;
              else
                this[3729] = this[3729] * 0.03125;
              goto LABEL_80;
            case 2:
              if ( !*(_DWORD *)(*(_DWORD *)this + 16488) )
                *(_DWORD *)(*(_DWORD *)this + 16488) = 2;
              if ( this[3686] * 0.5 <= this[3685] )
              {
                v44 = *((_DWORD *)this + 3928) == 0;
                *((_BYTE *)this + 14830) = 1;
                if ( v44 )
                  *((_DWORD *)this + 3928) = 1;
                sub_41AC50(*(_DWORD **)this, 2);
              }
              else
              {
                this[i + 3929] = 0.0;
              }
              break;
            case 3:
              v45 = *(_DWORD *)(*(_DWORD *)this + 16488);
              if ( !v45 )
                *(_DWORD *)(*(_DWORD *)this + 16488) = 4;
              if ( v47 | v48 )
              {
LABEL_78:
                this[i + 3929] = 0.0;
              }
              else
              {
                v49 = RandLCGRandomNumberGenerator(v45) % 4;
                this[62 * v49 + 3448] = this[62 * v49 + 3448] + 0.050000001;
                v51 = 3;
                v50 = *(_DWORD **)this;
LABEL_80:
                *((_DWORD *)this + 3928) = 2;
                sub_41AC50(v50, v51);
              }
              break;
            default:
              continue;
          }
        }
      }
    }
  }
}

