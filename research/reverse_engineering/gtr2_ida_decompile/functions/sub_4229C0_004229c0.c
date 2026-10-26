void __thiscall sub_4229C0(float *this)
{
  double v2; // st7
  double v3; // st7
  int v4; // ecx
  double v5; // st7
  int v6; // eax
  double v7; // st6
  double v8; // st7
  double v9; // st7
  int v10; // eax
  int v11; // edi
  float *v12; // ebp
  double v13; // st7
  double v14; // st7
  double v15; // st7
  float v16; // eax
  char v17; // al
  double v18; // st7
  double v19; // st7
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c3
  double v23; // st7
  double v25; // st7
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c3
  void *v28; // eax
  char v29; // al
  double v30; // st7
  double v31; // st7
  int v32; // eax
  double v33; // st7
  int v34; // eax
  double v35; // st7
  long double v36; // st7
  long double v37; // st7
  int v38; // ebx
  int v39; // edi
  double v40; // st7
  long double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  float v46; // [esp+0h] [ebp-C4h]
  float v47; // [esp+0h] [ebp-C4h]
  int v48; // [esp+14h] [ebp-B0h]
  int v49; // [esp+14h] [ebp-B0h]
  float v50; // [esp+14h] [ebp-B0h]
  float v51; // [esp+14h] [ebp-B0h]
  float v52; // [esp+14h] [ebp-B0h]
  float v53; // [esp+14h] [ebp-B0h]
  float v54; // [esp+18h] [ebp-ACh]
  float v55; // [esp+18h] [ebp-ACh]
  float v56; // [esp+1Ch] [ebp-A8h]
  float v57; // [esp+1Ch] [ebp-A8h]
  float v58; // [esp+1Ch] [ebp-A8h]
  float v59; // [esp+1Ch] [ebp-A8h]
  float v60; // [esp+20h] [ebp-A4h]
  float v61; // [esp+20h] [ebp-A4h]
  float v62; // [esp+20h] [ebp-A4h]
  float v63; // [esp+24h] [ebp-A0h]
  float v64; // [esp+24h] [ebp-A0h]
  float v65; // [esp+24h] [ebp-A0h]
  float v66; // [esp+28h] [ebp-9Ch]
  float v67; // [esp+28h] [ebp-9Ch]
  float v68; // [esp+2Ch] [ebp-98h]
  float v69; // [esp+2Ch] [ebp-98h]
  float v70; // [esp+30h] [ebp-94h]
  float v71; // [esp+30h] [ebp-94h]
  float v72; // [esp+34h] [ebp-90h]
  float v73; // [esp+38h] [ebp-8Ch]
  float v74; // [esp+3Ch] [ebp-88h]
  float v75; // [esp+40h] [ebp-84h] BYREF
  float v76; // [esp+44h] [ebp-80h]
  float v77; // [esp+48h] [ebp-7Ch]
  float v78; // [esp+4Ch] [ebp-78h]
  float v79; // [esp+50h] [ebp-74h]
  float v80; // [esp+54h] [ebp-70h]
  float v81; // [esp+58h] [ebp-6Ch]
  float v82; // [esp+5Ch] [ebp-68h] BYREF
  float v83; // [esp+60h] [ebp-64h]
  float v84; // [esp+64h] [ebp-60h]
  float v85[3]; // [esp+68h] [ebp-5Ch] BYREF
  float v86; // [esp+74h] [ebp-50h]
  float v87; // [esp+78h] [ebp-4Ch]
  float v88[3]; // [esp+7Ch] [ebp-48h] BYREF
  float v89[9]; // [esp+88h] [ebp-3Ch] BYREF
  char v90[24]; // [esp+ACh] [ebp-18h] BYREF

  v2 = this[5224];
  if ( *((_DWORD *)this + 5129) == 2139095039 )
    v3 = v2 * this[5208];
  else
    v3 = v2 * this[5176];
  v4 = *((_DWORD *)this + 5129);
  this[5134] = v3;
  *((_DWORD *)this + 5130) = v4;
  this[5129] = 3.4028235e38;
  if ( dword_B64134 == 3 || *((_DWORD *)this + 4820) == 10 && dword_FADE9C < 7 || *(_UNKNOWN **)this == off_757C18 )
  {
    v5 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.17;
    this[5128] = v5 + 0.17;
  }
  v6 = *((_DWORD *)this + 4888);
  v66 = flt_91BDE4;
  v86 = sub_577D40(this + 4) + (double)v6 * v66;
  if ( this[5128] >= 0.0 )
  {
    this[5134] = this[5134] * 0.60000002;
    this[5128] = this[5128] - 0.025;
    if ( dbl_FB1D18 > this[5133] )
    {
      v7 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 3.0;
      this[5133] = v7 + dbl_FB1D18 + 5.0;
      v8 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.34999999;
      this[5131] = v8;
      v9 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.55000001;
      this[5132] = v9;
    }
    v10 = sub_54F1F0(*(_DWORD *)this);
    v11 = 2;
    if ( v10 < 0 )
    {
      if ( !byte_9034D0 || *(_UNKNOWN **)this == off_757C18 )
        goto LABEL_37;
      v12 = (float *)((char *)off_757C18 + 16);
      v14 = sub_52B3A0(&byte_9034D0) - 20.0;
    }
    else
    {
      v12 = (float *)((char *)&unk_9204B0 + 22616 * v10);
      v48 = *(_DWORD *)(*(_DWORD *)v12 + 19552);
      v13 = sub_577D40(v12);
      v11 = *(_DWORD *)(*(_DWORD *)this + 19324) - *(_DWORD *)(*(_DWORD *)v12 + 19324);
      v14 = v13 + (double)v48 * v66;
    }
    if ( v12 )
    {
      v49 = *((_DWORD *)this + 4888);
      v68 = v14;
      v54 = v68 - (sub_577D40(this + 4) + (double)v49 * v66);
      if ( v66 * 0.5 <= v54 )
      {
        *((_DWORD *)this + 5210) = 1;
      }
      else
      {
        v15 = (double)((v11 + 1) / 2);
        v16 = this[*((_DWORD *)this + 5136) + 5046];
        v67 = 10.0 * v15;
        v78 = v15 * 20.0;
        v50 = flt_FADE54 * 0.30000001;
        v69 = flt_FADE54 * 0.60000002;
        v87 = flt_FADE54 * 0.75;
        v70 = flt_FADE54 * 1.4;
        this[5129] = this[5131] - *(float *)(LODWORD(v16) + 164);
        if ( byte_FADF20 )
        {
          v17 = sub_54F230(*(_DWORD *)this);
          v18 = this[5129];
          if ( v17 )
            v19 = v18 + 2.0;
          else
            v19 = v18 - 2.0;
          this[5129] = v19;
        }
        this[5097] = this[5129];
        if ( v21 | v22 )
        {
          v25 = v54;
          if ( v26 | v27 )
          {
            if ( v25 <= -10.0 )
              v47 = v87;
            else
              v47 = (v54 - -10.0) / (v67 - -10.0) * (v69 - v50) + v50;
          }
          else
          {
            v47 = (v25 + this[5132] - v67) / (v78 - v67) * (v70 - v69) + v69;
          }
          this[5210] = 0.0;
          sub_41FB40(this, v47);
        }
        else
        {
          v23 = v54 - v78;
          *((_DWORD *)this + 5210) = 1;
          v46 = v23 * 0.69999999 + v70;
          sub_41FB40(this, v46);
        }
        if ( this[5119] < 1.0
          && sub_41FE50(v12) < 0.2
          && ((double)*((int *)this + 4831) + 4.0) * 0.40000001 + flt_FADE1C > dbl_FB1D18 )
        {
          this[5115] = 0.0;
        }
      }
LABEL_44:
      if ( this[5115] > 0.89999998 )
        this[5115] = 0.89999998;
      goto LABEL_46;
    }
LABEL_37:
    v28 = *(void **)this;
    this[5129] = this[5131] - *(float *)(LODWORD(this[*((_DWORD *)this + 5136) + 5046]) + 164);
    if ( v28 != off_757C18 && byte_FADF20 )
    {
      v29 = sub_54F230(v28);
      v30 = this[5129];
      if ( v29 )
        v31 = v30 + 2.0;
      else
        v31 = v30 - 2.0;
      this[5129] = v31;
    }
    this[5097] = this[5129];
    *((_DWORD *)this + 5210) = 1;
    sub_41FB40(this, flt_FADE54);
    goto LABEL_44;
  }
LABEL_46:
  if ( dword_B64134 == 1 )
  {
    v32 = *((_DWORD *)this + 4373);
    if ( v32 && *(_DWORD *)(v32 + 304) )
    {
      if ( (unsigned __int8)sub_577A80(this + 4)
        && this[4307] < (double)this[4309]
        && fabs(dbl_FB1D18 - this[5127]) > 10.0 )
      {
        v33 = (double)dword_B6FFAC - 30.0;
        if ( v33 >= 20.0 )
          v51 = v33;
        else
          v51 = 20.0;
        v71 = dbl_FB1D18;
        if ( fmod((double)*((int *)this + 1) * 8.5, v51) + 1.0 + this[5121] * 20.0 + flt_FADE1C >= v71 )
        {
          this[5113] = 0.0;
        }
        else
        {
          v34 = sub_421930(this);
          sub_57F2F0(v34, v34, 1);
          v35 = this[5376] * 1.5 + this[4299];
          if ( v35 >= this[4300] )
            v56 = this[4300];
          else
            v56 = v35;
          sub_578550(LODWORD(v56));
          sub_577660(this + 4, 0);
          this[5127] = dbl_FB1D18;
          *((_DWORD *)this + 5192) = 5;
          *((_DWORD *)this + 5213) = 1;
          this[5046] = 0.0;
          this[5047] = 0.0;
          *((_DWORD *)this + 5207) = dword_FADE50;
        }
      }
    }
    else
    {
      sub_54FD90(*(_DWORD *)this);
      sub_577780(&v82, v90);
      v57 = v88[0] - v82;
      v75 = v57;
      v60 = v88[1] - v83;
      v76 = v60;
      v63 = v88[2] - v84;
      v77 = v63;
      v36 = sqrt(v57 * v57 + v63 * v63 + v60 * v60);
      v52 = v36;
      v37 = v36 * 0.40000001 + 3.0;
      if ( v37 < this[5144] )
        this[5144] = v37;
      if ( this[5144] < 5.0 )
        this[5144] = 5.0;
      if ( byte_B6FF94 )
      {
        v55 = 3.4028235e38;
        v38 = 104;
        if ( dword_757C10 + 3 <= 104 )
          v38 = dword_757C10 + 3;
        v39 = 0;
        if ( v38 > 0 )
        {
          do
          {
            sub_4035C0();
            v57 = v57 - v82;
            v60 = v60 - v83;
            v40 = v63 - v84;
            v63 = v40;
            v41 = sqrt(v40 * v63 + v60 * v60 + v57 * v57);
            if ( v41 < v55 )
              v55 = v41;
            ++v39;
          }
          while ( v39 < v38 );
          if ( v55 < 80.0 )
          {
            v42 = v55 - 20.0;
            if ( v42 < 35.0 )
              v42 = 35.0;
            if ( v42 < this[5144] )
              this[5144] = v42;
            if ( this[5144] < 5.0 )
              this[5144] = 5.0;
            if ( v55 < 30.0 )
            {
              sub_4035C0();
              sub_4035C0();
              v58 = v79 + v72;
              v61 = v80 + v73;
              v64 = v81 + v74;
              v59 = v58 * 0.5;
              v62 = v61 * 0.5;
              v65 = v64 * 0.5;
              v79 = v59 - v82;
              v80 = v62 - v83;
              v81 = v65 - v84;
              this[5113] = atan2(
                             -(v81 * this[3994] + v80 * this[3991] + v79 * this[3988]),
                             -(v81 * this[3996] + v80 * this[3993] + v79 * this[3990]))
                         / this[5160];
              if ( this[5113] >= -1.0 )
              {
                if ( this[5113] > 1.0 )
                  this[5113] = 1.0;
              }
              else
              {
                this[5113] = -1.0;
              }
            }
          }
        }
      }
      if ( v52 < 30.0 )
      {
        sub_614A90(v85, v89);
        v43 = (v89[8] * -1.0 + v89[7] * 0.0 + v89[6] * 0.0) * v77
            + (v89[5] * -1.0 + v89[4] * 0.0 + v89[3] * 0.0) * v76
            + (v89[2] * -1.0 + v89[1] * 0.0 + v89[0] * 0.0) * v75;
        if ( v43 >= 0.0 )
        {
          if ( v43 < 15.0 )
          {
            sub_41FAB0(this + 3988, &v75, v85);
            this[5113] = atan2(-v85[0], -v85[2]) / this[5160];
            if ( this[5113] >= -1.0 )
            {
              if ( this[5113] > 1.0 )
                this[5113] = 1.0;
            }
            else
            {
              this[5113] = -1.0;
            }
          }
        }
        else
        {
          sub_573810(this + 4);
          sub_57DCC0(v88, v85);
          *((_BYTE *)this + 21516) = 0;
          if ( dword_B64134 == 1 )
            sub_573540(this + 4);
        }
      }
    }
  }
  if ( *((_DWORD *)this + 5129) != 2139095039 && v86 < 150.0 )
  {
    v44 = 0.1 - (this[5119] - 22.0) * 0.020833334 * 0.075000003;
    if ( v44 < 0.025 || v44 <= 0.1 )
    {
      if ( v44 < 0.025 )
        v44 = 0.025;
    }
    else
    {
      v44 = 0.1;
    }
    v53 = v44;
    if ( *((_DWORD *)this + 5130) == 2139095039 )
    {
      this[5129] = this[5092];
    }
    else
    {
      v45 = v53 + this[5130];
      if ( v45 < this[5129] || (v45 = this[5130] - v53, v45 > this[5129]) )
        this[5129] = v45;
    }
  }
}
