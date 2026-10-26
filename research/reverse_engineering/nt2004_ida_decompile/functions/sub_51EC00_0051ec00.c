void __thiscall sub_51EC00(_DWORD **this, float a2)
{
  float v3; // edx
  int v4; // eax
  float *v5; // ebp
  _DWORD *v6; // ecx
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  _DWORD *v10; // eax
  _DWORD *v11; // edx
  int v12; // eax
  _BYTE *v13; // ecx
  double v14; // st7
  int v15; // edi
  double v16; // st7
  double v17; // st6
  float v18; // edx
  float v19; // ecx
  double v20; // st7
  double v21; // st6
  double v22; // st5
  double v23; // st7
  long double v24; // st7
  double v25; // st6
  float *v26; // ecx
  double v27; // st7
  double v28; // st7
  double v29; // st6
  _DWORD *v30; // edx
  _DWORD *v31; // ecx
  unsigned __int8 v33; // c0
  unsigned __int8 v34; // c3
  _DWORD *v35; // edx
  double v36; // st7
  int v37; // [esp-8h] [ebp-68h]
  float v38; // [esp+10h] [ebp-50h]
  float v39; // [esp+14h] [ebp-4Ch] BYREF
  float v40; // [esp+18h] [ebp-48h]
  float v41; // [esp+1Ch] [ebp-44h]
  int v42; // [esp+20h] [ebp-40h] BYREF
  float v43; // [esp+24h] [ebp-3Ch]
  float v44; // [esp+28h] [ebp-38h]
  double v45[3]; // [esp+2Ch] [ebp-34h] BYREF
  int v46; // [esp+44h] [ebp-1Ch]
  int v47; // [esp+48h] [ebp-18h]
  int v48; // [esp+4Ch] [ebp-14h]
  int v49; // [esp+50h] [ebp-10h]
  double v50; // [esp+54h] [ebp-Ch]
  int v51; // [esp+5Ch] [ebp-4h]
  float v52; // [esp+64h] [ebp+4h]

  v3 = *(float *)this;
  v38 = *((float *)this + 5177);
  this[5177] = 0;
  v4 = *(_DWORD *)(LODWORD(v3) + 20892);
  if ( v4 )
  {
    if ( v4 != 2 )
    {
      v30 = this + 4380;
      v31 = this + 5174;
      if ( v33 | v34 )
      {
        v36 = v38 + a2;
        *((float *)this + 5177) = v36;
        if ( v36 > 15.0 )
        {
          this[5177] = 0;
          this[4924] = 0;
          this[4925] = 0;
          this[4926] = 0;
          if ( dword_75CBB0 == 7 )
          {
            if ( *((_BYTE *)this + 4685) )
            {
              v37 = (int)this[1169];
              *((_BYTE *)this + 4685) = 0;
              sub_50B4E0(this + 452, v37, 1);
            }
          }
        }
      }
      else
      {
        *v31 = *v30;
        v35 = this[4382];
        this[5175] = this[4381];
        this[5176] = v35;
      }
    }
  }
  else
  {
    v5 = (float *)(this + 4380);
    v6 = this + 5174;
    if ( v8 | v9 )
    {
      if ( this[4125] )
        goto LABEL_50;
      if ( !*(_DWORD *)dword_76693C )
      {
        v12 = 0;
        v13 = this + 553;
        do
        {
          if ( !*v13 )
            break;
          ++v12;
          v13 += 304;
        }
        while ( v12 < 4 );
        if ( v12 != 4 || fabs(*((float *)this + 4684)) <= 0.1 )
        {
LABEL_50:
          if ( (dword_75CBB4 >= 5 && dword_75CBB4 <= 8 || this[4930] == (_DWORD *)2)
            && *(_DWORD *)(LODWORD(v3) + 17416) != 3
            && !sub_51C6B0((float *)this) )
          {
            v14 = v38 + a2;
            *((float *)this + 5177) = v14;
            if ( v14 > flt_7691E8 )
            {
              if ( sub_4EED40(*this)
                && (*this)[4146] == 1
                && sub_42DBA0()
                && *((_BYTE *)this + 2212)
                && *((_BYTE *)this + 2516)
                && *((_BYTE *)this + 2820)
                && *((_BYTE *)this + 3124)
                && fabs(*((float *)this + 4684)) > 0.1
                && (this[5177] = 0, (v15 = sub_514EE0(this)) != 0) )
              {
                sub_51F0F0(this);
                v16 = *(float *)(v15 + 68);
                v17 = *(float *)(v15 + 72);
                v18 = *(float *)v15;
                v19 = *(float *)(v15 + 8);
                v40 = *(float *)(v15 + 4);
                v39 = v18;
                v41 = v19;
                if ( v17 >= v16 )
                  v20 = *(float *)(v15 + 72) - 1.0;
                else
                  v20 = 1.0 - *(float *)(v15 + 68);
                v21 = v20 * *(float *)(v15 + 44);
                v22 = v20 * *(float *)(v15 + 48);
                v46 = 0;
                v47 = 1074266112;
                v48 = 0x40000000;
                v43 = v22;
                v49 = 1201543096;
                v51 = 0;
                v44 = v20 * *(float *)(v15 + 52);
                v39 = v21 + v39;
                v40 = v43 + v40;
                v41 = v44 + v41;
                v45[0] = v39;
                v45[1] = v40;
                v45[2] = v41;
                if ( sub_44E900(dbl_760B48, (int)v45) )
                  v23 = v50;
                else
                  v23 = v40;
                v40 = v23 + 0.1;
                v24 = -*(float *)(v15 + 212);
                v42 = 0;
                v25 = *(float *)(v15 + 220);
                v44 = 0.0;
                v43 = atan2(v24, -v25);
                sub_51BE20((int)this, &v39, &v42);
              }
              else
              {
                this[4924] = 0;
                this[4925] = 0;
                this[4926] = 0;
                v26 = sub_403D10(&flt_628F60, (float *)this + 4380, 0);
                this[4750] = v26;
                v27 = (*((float *)this + 4382) - v26[2]) * v26[13]
                    + (*((float *)this + 4381) - v26[1]) * v26[12]
                    + (*v5 - *v26) * v26[11];
                if ( v27 >= 0.0 )
                {
                  v52 = v27 - v26[18];
                  v28 = v26[18];
                  v29 = v26[34];
                }
                else
                {
                  v52 = -v27 - v26[17];
                  v28 = v26[17];
                  v29 = v26[33];
                }
                sub_4DCC00(*this + 5209, 1, 0);
                if ( sub_4EED40(*this) )
                {
                  sub_4BA1A0(0, -1.0);
                }
                else if ( v52 < 7.0 || v29 <= v28 )
                {
                  sub_4F8F50(*this, &v39, &v42);
                  sub_51BE20((int)this, &v39, &v42);
                  sub_4EEC20(*this, 0);
                  sub_4EEC50(*this, 0);
                  sub_4EECE0(*this, 0);
                  sub_428150(*this);
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v10 = this[4381];
      *v6 = *(_DWORD *)v5;
      v11 = this[4382];
      this[5175] = v10;
      this[5176] = v11;
    }
  }
}
