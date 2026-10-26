void __thiscall sub_4DF490(_DWORD *this, float a2, int a3)
{
  float v4; // ecx
  int v5; // edi
  bool v6; // al
  char v7; // bl
  char v8; // al
  double v9; // st7
  int v10; // eax
  int v11; // ebp
  float *v12; // edi
  char v13; // bl
  int v14; // ecx
  float *v15; // edi
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  double v20; // st7
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c2
  double v23; // st7
  double v24; // st7
  double v25; // st7
  int v26; // eax
  double v27; // st6
  float *v28; // ecx
  double v29; // st7
  unsigned int v30; // eax
  double v31; // st7
  double v32; // st7
  unsigned __int8 v34; // c0
  unsigned __int8 v35; // c3
  bool v36; // [esp+12h] [ebp-2Eh]
  char v37; // [esp+12h] [ebp-2Eh]
  char v38; // [esp+13h] [ebp-2Dh]
  float v39; // [esp+14h] [ebp-2Ch]
  float v40; // [esp+18h] [ebp-28h]
  float v41; // [esp+18h] [ebp-28h]
  float v42; // [esp+1Ch] [ebp-24h]
  float v43; // [esp+1Ch] [ebp-24h]
  float v44; // [esp+20h] [ebp-20h]
  float v45; // [esp+24h] [ebp-1Ch]
  float v46; // [esp+24h] [ebp-1Ch]
  float v47; // [esp+28h] [ebp-18h]
  float v48; // [esp+2Ch] [ebp-14h]
  float v49; // [esp+30h] [ebp-10h]
  float v50; // [esp+34h] [ebp-Ch] BYREF
  float v51; // [esp+38h] [ebp-8h]
  float v52; // [esp+3Ch] [ebp-4h]
  float v53; // [esp+44h] [ebp+4h]
  float v54; // [esp+48h] [ebp+8h]
  float v55; // [esp+48h] [ebp+8h]

  v38 = *((_BYTE *)this + 285);
  *((_BYTE *)this + 285) = 1;
  sub_45D270(&byte_764D68, aWarningDriving, 0);
  sub_45D270(&byte_764D68, aWarningDriving_0, 0);
  sub_45D270(&byte_764D68, aWarningAcceler, 0);
  sub_45D270(&byte_764D68, aWarningYouAreA, 0);
  v4 = *((float *)this + 73);
  v5 = *this;
  this[73] = 0;
  v44 = v4;
  v6 = *(_BYTE *)(v5 + 17412) && dword_75CBB4 >= 5 || dword_75CBB0 != 7 || this[14];
  if ( *(_DWORD *)(v5 + 16584) )
  {
    if ( !v6 )
    {
LABEL_132:
      this[72] = 0;
      return;
    }
LABEL_130:
    if ( (unsigned __int8)sub_4F8410(v5) )
      sub_4F81A0(*this);
    goto LABEL_132;
  }
  if ( v6 )
    goto LABEL_130;
  v36 = dword_7D7540 == 7;
  if ( dword_75CBB4 == 5 && this[2] == 9 )
  {
    v7 = 1;
  }
  else
  {
    v7 = 0;
    if ( dword_75CBB4 != 5 )
    {
LABEL_15:
      v8 = 0;
      goto LABEL_16;
    }
  }
  if ( !sub_4DEB10(this) )
    goto LABEL_15;
  v8 = 1;
LABEL_16:
  if ( v36 || v7 || (v37 = 0, v8) )
    v37 = 1;
  v45 = dbl_7DA9D0 - 0.80000001;
  v9 = flt_6290D0;
  v39 = flt_6290D0;
  v10 = sub_4F82E0(v5);
  v11 = v10;
  if ( v10 != this[77] )
  {
    this[77] = v10;
    v9 = dbl_7DA9D0;
    *((float *)this + 78) = dbl_7DA9D0;
  }
  if ( v10 >= 0 )
  {
    v12 = (float *)((char *)&unk_62BF68 + 25304 * v10);
    if ( *((_DWORD *)v12 + 4146) == 2 )
    {
      v40 = v12[6322];
    }
    else
    {
      v9 = dbl_7DA9D0;
      v40 = dbl_7DA9D0;
    }
    sub_51C900(v12 + 21);
    v13 = 0;
LABEL_29:
    v14 = *((_DWORD *)v12 + 5279);
    v42 = v9;
    v50 = v12[4401];
    v51 = v12[4402];
    v52 = v12[4403];
    v15 = v12 + 4407;
    v48 = v15[1];
    v47 = *v15;
    v49 = v15[2];
    if ( v40 <= (double)v45 )
      return;
    v16 = this[70] - v14;
    v17 = sub_51C900(*this + 84);
    v41 = v17;
    if ( fabs(v17 - v42) < 20.0 )
    {
      v18 = *(float **)(*this + 19084);
      if ( v18 )
        v42 = (v52 - *(float *)(*this + 17612)) * v18[55]
            + (v51 - *(float *)(*this + 17608)) * v18[54]
            + (v50 - *(float *)(*this + 17604)) * v18[53]
            + v41;
    }
    if ( v16 )
    {
      if ( v16 > 2 || v16 > 1 && v41 > (double)v42 )
      {
        sub_4DCCC0(this, aLappedFieldMul);
        return;
      }
      if ( v16 > 0 )
        goto LABEL_35;
    }
    else if ( v41 > (double)v42 )
    {
LABEL_35:
      if ( v37 )
      {
        if ( !byte_7D74CB && !*((_BYTE *)this + 284) )
        {
          *((_BYTE *)this + 284) = 1;
          if ( (unsigned __int8)sub_4DFF10(&v50) )
          {
            if ( (int)this[3] > 0 )
              sub_4DC690(this, aPassedOnLeftDu, 1, 0);
            else
              sub_4DC690(this, aIllegallyPasse, 1, 0);
          }
        }
      }
      else
      {
        *((_BYTE *)this + 285) = v38;
        if ( v16 > 0 )
          goto LABEL_93;
        v25 = v42 + 15.0;
        if ( v11 >= 0 )
        {
          v26 = sub_4F82E0((char *)&unk_62BF68 + 25304 * v11);
          if ( v26 < 0 )
          {
            if ( (unsigned __int8)sub_4BBF20() )
            {
              v25 = sub_4BBF40() + 5.0;
            }
            else
            {
              v53 = v25;
              v25 = v53;
            }
          }
          else
          {
            v25 = sub_51C7A0((char *)&unk_62BFBC + 25304 * v26) + 5.0;
          }
        }
        v27 = v39 * 0.5;
        if ( v25 <= v41 + v27 )
        {
          if ( v25 < v41 - v27 )
            v25 = v25 + v39;
        }
        else
        {
          v25 = v25 - v39;
        }
        if ( v41 > v25 )
LABEL_93:
          *((_BYTE *)this + 285) = 0;
        if ( !a3 || *((_BYTE *)this + 284) )
        {
          sub_4DF3E0((int)this, v11);
          sub_45D100(&byte_764D68, (int)aWarningYouAreA, 3, 16909060, 0);
        }
        else
        {
          *((_BYTE *)this + 284) = 1;
          if ( v16 <= 0 )
          {
            if ( a3 == 1 )
            {
              sub_4DC690(this, aIllegallyPasse_0, 1, 0);
            }
            else if ( a3 == 2 )
            {
              sub_4DC690(this, aIllegallyPasse_1, 1, 0);
            }
            else if ( v42 + 10.0 < v41 )
            {
              sub_4DC690(this, aIllegallyPasse_2, 1, 0);
            }
          }
          else
          {
            sub_4DF420(this, v16);
          }
        }
      }
      return;
    }
    if ( a3 || v37 )
      return;
    v54 = v42 - v41;
    v20 = v54;
    if ( v21 | v22 )
    {
      v23 = v20 + v39;
    }
    else
    {
      if ( v20 <= v39 )
      {
LABEL_52:
        if ( v54 <= 50.0
          || (sub_4DF3E0((int)this, v11), v54 <= 75.0)
          || flt_7D74E0 + 15.0 <= sqrt(v48 * v48 + v49 * v49 + v47 * v47)
          || (v43 = dbl_7DA9D0, fabs(*(float *)(*this + 17528) - v43) <= 5.0)
          || fabs(*((float *)this + 78) - v43) <= 3.0
          || v13 && flt_766230 + 10.0 >= v43 )
        {
LABEL_79:
          *((float *)this + 75) = v54;
          return;
        }
        if ( v44 == 0.0 )
          *((float *)this + 74) = v54;
        v24 = v44 + a2;
        *((float *)this + 73) = v24;
        if ( v24 > 0.5 && v54 > (double)*((float *)this + 74) )
          sub_45D100(&byte_764D68, (int)aWarningDriving, 3, 16909060, 0);
        if ( *((float *)this + 73) > 9.5 )
        {
          if ( v54 >= (double)*((float *)this + 74) )
          {
            if ( (unsigned __int8)sub_4F8460(*this) )
            {
              if ( dword_75CBB4 <= 3 && !this[16] && v39 * 0.5 < v54 )
              {
                sub_4DC690(this, aDrivingTooSlow, 1, 0);
                this[73] = -1063256064;
              }
              goto LABEL_74;
            }
            sub_45D100(&byte_764D68, (int)aDrivingTooSlow_0, 3, 16909060, 0);
            sub_4F8240(*this);
          }
          else
          {
            *((float *)this + 74) = v54;
          }
          this[73] = 0;
        }
LABEL_74:
        *((_BYTE *)this + 285) = v38;
        if ( v54 > 100.0
          && v54 > (double)*((float *)this + 74)
          && v54 > (double)*((float *)this + 75)
          && *((float *)this + 73) > 4.5 )
        {
          *((_BYTE *)this + 285) = 0;
        }
        goto LABEL_79;
      }
      v23 = v54 - v39;
    }
    v54 = v23;
    goto LABEL_52;
  }
  if ( (unsigned __int8)sub_4BBF20() )
  {
    v12 = (float *)off_5FD348;
    v40 = sub_4BC030();
    v9 = sub_4BBF40();
    v13 = 1;
    goto LABEL_29;
  }
  if ( a3 )
  {
    if ( (int)this[70] > 0 )
      sub_4DF420(this, this[70]);
    goto LABEL_109;
  }
  v28 = (float *)*this;
  v55 = flt_7D74E0;
  if ( flt_7D74E0 * 0.30000001 <= sqrt(
                                    *(float *)(*this + 17628) * *(float *)(*this + 17628)
                                  + v28[4408] * v28[4408]
                                  + v28[4409] * v28[4409])
    || dword_75CBB4 < 3 )
  {
    if ( flt_7D74E0 * 1.5 >= sqrt(v28[4407] * v28[4407] + v28[4408] * v28[4408] + v28[4409] * v28[4409]) )
    {
LABEL_109:
      this[72] = 0;
      return;
    }
    if ( !v37 && dword_7D7540 != 1 && dword_7D7540 != 2 )
    {
      v30 = sub_4F83E0(0);
      if ( v30 == this[1] )
        goto LABEL_125;
      if ( v30 < 0x30 )
      {
        v46 = sub_51C7A0((char *)&unk_62BFBC + 25304 * v30);
        v31 = v46 - sub_51C7A0(*this + 84);
        if ( v31 >= v39 * -0.5 )
        {
          if ( v31 > v39 * 0.5 )
            v31 = v31 - v39;
        }
        else
        {
          v31 = v31 + v39;
        }
        if ( v31 < 1.0 )
        {
LABEL_125:
          sub_45D100(&byte_764D68, (int)aWarningAcceler, 3, 16909060, 0);
          v32 = a2 + *((float *)this + 72);
          *((float *)this + 72) = v32;
          if ( !(v34 | v35)
            || v32 > 1.5
            && v55 + v55 < sqrt(
                             *(float *)(*this + 17628) * *(float *)(*this + 17628)
                           + *(float *)(*this + 17632) * *(float *)(*this + 17632)
                           + *(float *)(*this + 17636) * *(float *)(*this + 17636)) )
          {
            this[72] = 0;
            sub_4DC690(this, aAcceleratedToo, 1, 0);
          }
        }
      }
    }
  }
  else
  {
    sub_45D100(&byte_764D68, (int)aWarningDriving_0, 3, 16909060, 0);
    v29 = a2 + *((float *)this + 72);
    *((float *)this + 72) = v29;
    if ( v29 > 5.0 )
    {
      this[72] = 0;
      sub_45D100(&byte_764D68, (int)aDrivingTooSlow_0, 3, 16909060, 0);
      sub_4F8240(*this);
    }
  }
}
