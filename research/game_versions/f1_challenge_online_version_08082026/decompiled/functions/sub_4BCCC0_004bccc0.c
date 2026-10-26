void __thiscall sub_4BCCC0(float *this, float a2)
{
  int v3; // ebx
  double v4; // st7
  int v5; // edi
  bool v6; // zf
  float v7; // eax
  char v8; // cl
  char v9; // al
  long double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  double v17; // st7
  double v18; // st6
  double v19; // st6
  float v20; // ecx
  float v21; // edx
  double v22; // st7
  long double v23; // st6
  long double v24; // st5
  long double v26; // st4
  unsigned __int8 v27; // c2
  unsigned __int8 v28; // c3
  long double v29; // st2
  int v30; // eax
  int v31; // eax
  char v32; // cl
  int v33; // eax
  float *v34; // eax
  double v35; // st7
  double v36; // st6
  double v37; // st5
  double v38; // st4
  long double v39; // st5
  int v40; // eax
  char v41; // cl
  char v42; // cl
  int v43; // edx
  unsigned __int8 v45; // c0
  unsigned __int8 v46; // c3
  int v47; // eax
  double v48; // st7
  double v49; // st6
  double v50; // st7
  double v51; // st6
  float v52; // ecx
  int v53; // ebp
  int v54; // edi
  unsigned __int8 v56; // c0
  unsigned __int8 v57; // c3
  double v58; // st7
  long double v59; // st4
  unsigned __int8 v61; // c0
  unsigned __int8 v62; // c2
  double v63; // st7
  float v64; // [esp+0h] [ebp-40h]
  float v65; // [esp+14h] [ebp-2Ch]
  float v66; // [esp+14h] [ebp-2Ch]
  float v67; // [esp+14h] [ebp-2Ch]
  float v68; // [esp+18h] [ebp-28h]
  float v69; // [esp+18h] [ebp-28h]
  float v70; // [esp+1Ch] [ebp-24h]
  float v71; // [esp+20h] [ebp-20h]
  float v72; // [esp+20h] [ebp-20h]
  int v73; // [esp+24h] [ebp-1Ch] BYREF
  float v74; // [esp+28h] [ebp-18h]
  int v75; // [esp+2Ch] [ebp-14h]
  int v76; // [esp+30h] [ebp-10h]
  float v77; // [esp+34h] [ebp-Ch]
  float v78; // [esp+38h] [ebp-8h]
  float v79; // [esp+3Ch] [ebp-4h]

  v3 = *(_DWORD *)this + 12;
  v4 = sub_4F0050(v3);
  v70 = v4;
  v5 = *(_DWORD *)(v3 + 15004);
  v6 = *((_DWORD *)this + 5) == -1082130432;
  v75 = v5;
  v73 = -1;
  if ( !v6 )
  {
    sub_4D7CF0(v70, (int)&v73);
    if ( v4 >= 0.666 )
      sub_4D7CF0(this[5], 0);
  }
  v7 = *this;
  this[5] = v70;
  v8 = *(_BYTE *)(LODWORD(v7) + 13388);
  v9 = *((_BYTE *)this + 168);
  if ( v8 )
  {
    if ( !v9 )
      this[43] = 0.0;
    *((_BYTE *)this + 168) = 1;
    v10 = sqrt(
            *(float *)(v3 + 13556) * *(float *)(v3 + 13556)
          + *(float *)(v3 + 13548) * *(float *)(v3 + 13548)
          + *(float *)(v3 + 13552) * *(float *)(v3 + 13552))
        - flt_8ACFB4;
    if ( v10 > 0.0 )
      this[43] = v10 * a2 + this[43];
  }
  else if ( v9 )
  {
    v11 = this[43];
    *((_BYTE *)this + 168) = 0;
    if ( v11 > 7.5 )
    {
      if ( dword_7CEF84 )
      {
        if ( dword_7C56A4 == 7 )
        {
          sub_4BBD60((int *)this, aSpeedingInPitl, 10);
        }
        else
        {
          v64 = (double)sub_587BDC((this[43] - 7.5) * 0.025) * 500.0 + 1500.0;
          sub_4BBA90(this, aSpeedingInPitl, v64);
        }
      }
    }
  }
  v12 = (*(float *)(v3 + 13532) - *(float *)(v5 + 8)) * *(float *)(v5 + 40)
      + (*(float *)(v3 + 13528) - *(float *)(v5 + 4)) * *(float *)(v5 + 36)
      + (*(float *)(v3 + 13524) - *(float *)v5) * *(float *)(v5 + 32);
  if ( v12 >= 0.0 )
    v13 = v12 - *(float *)(v5 + 108);
  else
    v13 = -(*(float *)(v5 + 104) + v12);
  v68 = v13;
  if ( sub_4BC340(this) )
  {
    if ( *((_BYTE *)this + 180) )
    {
      v14 = sub_4EFF00(v3);
      if ( v14 < this[51] )
        this[51] = v14;
      this[50] = a2 + this[50];
      if ( v68 < 1.0 )
      {
        *((_BYTE *)this + 180) = 0;
        v65 = 0.0;
        if ( dword_7C56A4 == 7 )
        {
          v15 = *((_DWORD *)this + 11);
          v16 = *((_DWORD *)this + 47);
          if ( v15 < v16 )
            v65 = (double)(v16 - v15) * 0.72500002;
        }
        if ( !*((_DWORD *)this + 48) && !*(_DWORD *)(v5 + 300) )
        {
          v17 = sub_4F01B0(v3) - this[49] + (double)(*((_DWORD *)this + 2) - *((_DWORD *)this + 46)) * flt_5EA408;
          v18 = v17 / this[50] - 0.89999998;
          if ( v18 <= 0.0 )
            v19 = v65;
          else
            v19 = v18 * 0.375 + v65;
          v65 = (v17 - this[50]) * 0.67500001 + v19;
        }
        v20 = *(float *)(v3 + 13552);
        v21 = *(float *)(v3 + 13556);
        v22 = this[51] + v65;
        v77 = *(float *)(v3 + 13548);
        v23 = v77;
        v78 = v20;
        v24 = v20;
        v79 = v21;
        v26 = v21;
        if ( !(v28 | v27) || v24 != 0.0 || v26 != 0.0 )
        {
          v29 = 1.0 / sqrt(v23 * v23 + v26 * v26 + v24 * v24);
          v23 = v23 * v29;
          v24 = v24 * v29;
          v26 = v26 * v29;
        }
        v66 = v26 * *(float *)(v5 + 172) + v24 * *(float *)(v5 + 168) + v23 * *(float *)(v5 + 164) - 1.0 + v22;
        if ( v66 > 1.75 && dword_7CEF84 )
        {
          if ( (*((int *)this + 52) > 1 || v66 > 2.75) && dword_7C56A4 == 7 )
            sub_4BBD60((int *)this, aCutTrack, 10);
          else
            sub_4BBC60(this, aCutTrack);
          v30 = *((_DWORD *)this + 24);
          ++*((_DWORD *)this + 52);
          if ( v30 )
          {
            *((_DWORD *)this + 24) = 1;
            if ( dword_7C56A4 != 7 )
            {
              if ( sub_423A00(byte_5EC4C0, aLapWillNotCoun, byte_5EC4CC) )
              {
                v31 = 0;
                do
                {
                  v32 = aLapWillNotCoun[v31];
                  byte_5EC4CC[v31++] = v32;
                }
                while ( v32 );
              }
              sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
            }
          }
        }
      }
    }
    else if ( v68 > 2.5 )
    {
      v33 = *((_DWORD *)this + 2);
      this[47] = this[11];
      *((_BYTE *)this + 180) = 1;
      *((_DWORD *)this + 46) = v33;
      this[48] = *(float *)(v5 + 300);
      this[49] = sub_4F01B0(v3);
      this[50] = 0.0;
      this[51] = sub_4EFF00(v3);
    }
  }
  else
  {
    *((_BYTE *)this + 180) = 0;
  }
  v34 = *(float **)(v5 + 272);
  v35 = *v34 - *(float *)v5;
  v36 = v34[1] - *(float *)(v5 + 4);
  v37 = v34[2] - *(float *)(v5 + 8);
  v38 = v37 * *(float *)(v3 + 13556) + v36 * *(float *)(v3 + 13552) + v35 * *(float *)(v3 + 13548);
  if ( v38 >= 0.0 )
  {
    this[44] = 0.0;
  }
  else
  {
    v71 = this[44];
    v39 = v71 - v38 * a2 / sqrt(v37 * v37 + v36 * v36 + v35 * v35);
    this[44] = v39;
    if ( v71 <= 10.0 && v39 > 10.0 )
    {
      if ( sub_423A00(byte_5EC4C0, aWrongWay, byte_5EC4CC) )
      {
        v40 = 0;
        do
        {
          v41 = aWrongWay[v40];
          byte_5EC4CC[v40++] = v41;
        }
        while ( v41 );
      }
      sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
      if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580)
        && sub_4EFF00(v3) > 0.0 )
      {
        sub_41A4A0();
      }
    }
    if ( dword_7CEF84 && v71 <= 125.0 && this[44] > 125.0 )
      sub_4BC0E0((int *)this, aWrongWay);
  }
  v42 = *((_BYTE *)this + 212);
  v43 = *(_DWORD *)this;
  *((_BYTE *)this + 212) = 0;
  if ( *(_BYTE *)(v43 + 13388) || dword_7C56A8 != 5 || v68 >= 8.0 || v45 | v46 )
  {
LABEL_120:
    this[55] = 0.0;
    return;
  }
  v47 = dword_7C56A4;
  if ( dword_7C56A4 == 5 )
    v48 = 87.0;
  else
    v48 = 37.0;
  if ( v42 )
    v49 = 3.0;
  else
    v49 = 0.0;
  v69 = v49 + v48;
  if ( dword_7C56A4 == 5 )
    v50 = 1.9;
  else
    v50 = 0.80000001;
  if ( v42 )
    v51 = 0.2;
  else
    v51 = 0.0;
  v76 = *((_DWORD *)this + 54);
  v52 = *(float *)(v3 + 13524);
  v74 = v51 + v50;
  v77 = v52;
  v79 = *(float *)(v3 + 13532);
  v72 = v69;
  v53 = 0;
  v78 = *(float *)(v3 + 13528);
  if ( dword_5C329C > 0 )
  {
    do
    {
      if ( v53 != *((_DWORD *)this + 1) )
      {
        v54 = dword_7C54F0[v53] + 12;
        if ( !(v56 | v57) )
        {
          v58 = sub_4F0050(v54);
          if ( v58 > v70 )
            v58 = v58 - flt_5EA3FC;
          v67 = v70 - v58;
          if ( v67 < (double)v69 && !*(_BYTE *)(v54 + 13376) )
          {
            v59 = sqrt(
                    *(float *)(v54 + 13548) * *(float *)(v54 + 13548)
                  + *(float *)(v54 + 13552) * *(float *)(v54 + 13552)
                  + *(float *)(v54 + 13556) * *(float *)(v54 + 13556));
            if ( v59 >= 5.0 && v67 / v59 < v74 )
            {
              if ( dword_7C56A4 == 7 )
              {
                if ( *(_DWORD *)(dword_7C54F0[v53] + 16480) < *((_DWORD *)this + 11)
                  && (*(_DWORD *)(dword_7C54F0[v53] + 16444) > *((_DWORD *)this + 2)
                   || *(_DWORD *)(dword_7C54F0[v53] + 16448) != *((_DWORD *)this + 3)) )
                {
                  *((_BYTE *)this + 212) = 1;
                  if ( v67 < (double)v72 )
                  {
                    *((_DWORD *)this + 54) = v53;
                    v72 = v70 - v58;
                  }
                }
              }
              else if ( *((_DWORD *)this + 24) != 2 && *(_DWORD *)(dword_7C54F0[v53] + 16532) == 2 )
              {
                if ( v61 | v62 )
                {
                  *((_BYTE *)this + 212) = 1;
                  if ( v67 < (double)v72 )
                  {
                    *((_DWORD *)this + 54) = v53;
                    v72 = v70 - v58;
                  }
                }
              }
            }
          }
        }
      }
      ++v53;
    }
    while ( v53 < dword_5C329C );
    v47 = dword_7C56A4;
  }
  if ( !*((_BYTE *)this + 212) || *((_DWORD *)this + 54) != v76 || v47 != 7 )
  {
    if ( this[55] == 0.0 )
      return;
    sub_41B910(5, *(_DWORD *)this);
    goto LABEL_120;
  }
  if ( this[55] == 0.0 )
  {
    sub_41B3C0(dword_5EB978, 5, -1, this[5], *(_DWORD *)this, 1);
  }
  else if ( this[55] >= 10.0 || a2 + this[55] < 10.0 )
  {
    if ( this[55] < 20.0 && a2 + this[55] >= 20.0 )
      sub_41B3C0(dword_5EB978, 5, -1, this[5], *(_DWORD *)this, 3);
  }
  else
  {
    sub_41B3C0(dword_5EB978, 5, -1, this[5], *(_DWORD *)this, 2);
  }
  v63 = a2 + this[55];
  this[55] = v63;
  if ( v63 > 30.0 )
  {
    if ( dword_7CEF84 )
    {
      sub_4BBD60((int *)this, aIgnoredBlueFla, 10);
      sub_41A720(*(_DWORD *)this, aIgnoredBlueFla);
      this[55] = 0.0;
    }
  }
}
