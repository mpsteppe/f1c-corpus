void __thiscall sub_4EB430(int this)
{
  _BYTE *v2; // eax
  int v3; // ecx
  char *v4; // ecx
  int v5; // ebp
  char v6; // bl
  char v7; // dl
  char *v8; // eax
  char *v9; // eax
  int v10; // ecx
  int v11; // ecx
  double v12; // st7
  double v13; // st6
  float *v14; // edx
  int v15; // edi
  double v16; // st7
  float *v17; // eax
  int v18; // edx
  float *v19; // edi
  int *v20; // ebp
  int v21; // eax
  double v22; // st7
  int v23; // eax
  int v24; // ecx
  double v25; // st7
  int v26; // ebx
  bool v27; // zf
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  double v31; // st6
  float *v32; // eax
  double v33; // st5
  double v34; // st7
  double v35; // st6
  double v36; // st5
  int v37; // ebp
  float *v38; // edi
  float v39; // eax
  int v40; // eax
  int v41; // ebx
  double v42; // st7
  int v43; // ecx
  double v44; // st7
  int v45; // eax
  double v46; // st7
  int v47; // ecx
  float *v48; // eax
  long double v49; // st7
  int v50; // edi
  float *v51; // edx
  float v52; // [esp+0h] [ebp-5Ch]
  float v53; // [esp+18h] [ebp-44h]
  float v54; // [esp+18h] [ebp-44h]
  float v55; // [esp+1Ch] [ebp-40h]
  float v56; // [esp+1Ch] [ebp-40h]
  float v57; // [esp+1Ch] [ebp-40h]
  float v58; // [esp+1Ch] [ebp-40h]
  float v59; // [esp+20h] [ebp-3Ch]
  float v60; // [esp+20h] [ebp-3Ch]
  float v61; // [esp+2Ch] [ebp-30h]
  float v62; // [esp+2Ch] [ebp-30h]
  float v63; // [esp+30h] [ebp-2Ch]
  float v64; // [esp+30h] [ebp-2Ch]
  float v65; // [esp+34h] [ebp-28h]
  float v66; // [esp+34h] [ebp-28h]
  float v67; // [esp+38h] [ebp-24h]
  float v68; // [esp+38h] [ebp-24h]
  float v69; // [esp+3Ch] [ebp-20h]
  float v70; // [esp+3Ch] [ebp-20h]
  float v71; // [esp+40h] [ebp-1Ch]
  float v72; // [esp+40h] [ebp-1Ch]
  float v73; // [esp+48h] [ebp-14h]
  float v74; // [esp+4Ch] [ebp-10h]
  int v75[3]; // [esp+50h] [ebp-Ch] BYREF

  *(_BYTE *)(this + 15221) = 0;
  *(_DWORD *)(this + 172) = 0;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 164) = 0;
  *(_DWORD *)(this + 168) = 1065353216;
  *(_DWORD *)(this + 180) = 0;
  if ( *(_DWORD *)(this + 12988) <= 1u && (*(_BYTE *)(*(_DWORD *)this + 18620) & 1) != 0 )
  {
    if ( *(_BYTE *)(this + 4208) )
    {
      *(_BYTE *)(this + 4208) = 0;
      v2 = (_BYTE *)(this + 4212);
      v3 = 17;
      do
      {
        *v2 = 0;
        v2 += 28;
        --v3;
      }
      while ( v3 );
    }
    v4 = (char *)(this + 15224);
    v5 = 4;
    do
    {
      v6 = *v4;
      if ( *v4 )
      {
        v7 = v4[1];
        *(_BYTE *)(this + 4208) = 1;
        v8 = v4 - 10648;
        *v8 = v6;
        v8[1] = v7;
        v9 = v4 - 10632;
        *(_DWORD *)v9 = *((_DWORD *)v4 + 4);
        *((_DWORD *)v9 + 1) = *((_DWORD *)v4 + 5);
        *((_DWORD *)v9 + 2) = *((_DWORD *)v4 + 6);
        *v4 = 0;
      }
      v4 += 28;
      --v5;
    }
    while ( v5 );
    dword_8ADAF8 = 0;
    v52 = sub_4E9980((float *)this);
    sub_4BE340((int)dword_8AB710, this, (float *)(this + 13524), v52);
    if ( sub_4E96C0(this) )
    {
      v59 = sub_4E9A40((float *)this, 0);
      sub_4BE4E0((int)dword_8AB710, *(_DWORD *)(this + 1768), (float *)(this + 13524), v59);
    }
    sub_4E9BD0((float *)this);
    sub_4EA970(v10);
    v11 = dword_8ADAF8;
    if ( dword_8ADAF8 > 0 )
    {
      if ( dword_8ADAF8 > 1 )
      {
        v12 = 0.0;
        v13 = 0.0;
        v55 = 0.0;
        v54 = 0.0;
        if ( dword_8ADAF8 <= 0 )
          goto LABEL_23;
        v14 = (float *)&unk_8AD400;
        v15 = dword_8ADAF8;
        do
        {
          if ( *(v14 - 1) > (double)v54 )
            v54 = *(v14 - 1);
          v13 = v13 + *(v14 - 1);
          if ( *v14 > (double)v55 )
            v55 = *v14;
          v14 += 14;
          --v15;
          v12 = v12 + *(v14 - 14);
        }
        while ( v15 );
        if ( v13 <= 0.0 )
LABEL_23:
          v53 = 1.0;
        else
          v53 = v54 / v13;
        if ( v12 <= 0.0 )
          v16 = 1.0;
        else
          v16 = v55 / v12;
        if ( dword_8ADAF8 > 0 )
        {
          v17 = (float *)&unk_8AD400;
          v18 = dword_8ADAF8;
          do
          {
            v17 += 14;
            --v18;
            *(v17 - 15) = v53 * *(v17 - 15);
            *(v17 - 14) = v16 * *(v17 - 14);
          }
          while ( v18 );
        }
      }
      v60 = 0.0;
      if ( v11 > 0 )
      {
        v19 = (float *)&unk_8AD42C;
        while ( 2 )
        {
          v20 = (int *)(v19 - 13);
          sub_4EBC60(v19 - 13, 1);
          v21 = *((_DWORD *)v19 - 10);
          v56 = fabs(*(v19 - 12));
          *(v19 - 12) = -*(v19 - 12);
          switch ( v21 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
              sub_40F4B0(*((_DWORD **)v19 - 9), (int)(v19 - 13), *(float *)(this + 13484));
              v26 = 37;
              v53 = (v56 - 5.0) * 0.0099999998;
              goto LABEL_44;
            case 6:
              sub_40F4B0(*((_DWORD **)v19 - 9), (int)(v19 - 13), *(float *)(this + 13484));
              v22 = (v56 - 1000.0) * 0.00025000001;
              v53 = v22;
              v57 = v22 * 3.0;
              v23 = (int)v57;
              v24 = v23;
              if ( v23 >= 0 )
              {
                if ( v23 > 3 )
                  v24 = 3;
              }
              else
              {
                v24 = 0;
              }
              v25 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              if ( v25 > 0.0 )
                ++v24;
              v26 = v24 + 32;
              v27 = byte_7CF728 == 0;
              goto LABEL_40;
            case 9:
              v40 = *((_DWORD *)v19 - 9);
              if ( v40 )
              {
                v41 = *(_DWORD *)(v40 + 56);
                if ( *(float *)(v40 + 8) - *(float *)(v40 + 12) * 0.0 == 0.0 )
                  *(_BYTE *)(this + 15221) = 1;
              }
              else
              {
                v41 = 27;
              }
              v42 = (v56 - 1000.0) * 0.00025000001;
              v53 = v42;
              v58 = v42 * 3.0;
              v43 = (int)v58;
              if ( v43 >= 0 )
              {
                if ( v43 > 3 )
                  v43 = 3;
              }
              else
              {
                v43 = 0;
              }
              v44 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
              if ( v44 > 0.0 )
                ++v43;
              v45 = *((_DWORD *)v19 - 9);
              v26 = v43 + v41;
              if ( !v45 || *v20 < 0 )
                goto LABEL_43;
              v27 = *(_DWORD *)(v45 + 40) == 0;
LABEL_40:
              if ( !v27 && !(v29 | v30) )
              {
                v67 = *(float *)(this + 13548) * 0.5;
                v69 = *(float *)(this + 13552) * 0.5;
                v71 = *(float *)(this + 13556) * 0.5;
                v31 = *(v19 - 2);
                v32 = (float *)(28 * *v20 + this + 4228);
                v73 = *(v19 - 1) * 0.5;
                v33 = *v19;
                *(_BYTE *)(this + 4208) = 1;
                *((_BYTE *)v32 - 16) = 8;
                *((_BYTE *)v32 - 15) = 8;
                v74 = v33 * 0.5;
                v61 = v67 + v31 * 0.5;
                *v32 = v61;
                v63 = v73 + v69 + 2.0;
                v32[1] = v63;
                v65 = v71 + v74;
                v32[2] = v65;
              }
LABEL_43:
              if ( v26 != -1 )
              {
LABEL_44:
                if ( v53 > 0.0099999998 )
                {
                  if ( v53 > 1.0 )
                    v53 = 1.0;
                  if ( sub_4F8AB0(v26) < v53 )
                  {
                    v34 = *(v19 - 8) - *(float *)(this + 13524);
                    v35 = *(v19 - 7) - *(float *)(this + 13528);
                    v36 = *(v19 - 6) - *(float *)(this + 13532);
                    *(float *)v75 = v36 * *(float *)(this + 13512)
                                  + v35 * *(float *)(this + 13500)
                                  + v34 * *(float *)(this + 13488);
                    *(float *)&v75[1] = v36 * *(float *)(this + 13516)
                                      + v35 * *(float *)(this + 13504)
                                      + v34 * *(float *)(this + 13492);
                    *(float *)&v75[2] = v36 * *(float *)(this + 13520)
                                      + v35 * *(float *)(this + 13508)
                                      + v34 * *(float *)(this + 13496);
                    sub_4F8850(v26, 2, v53, 1.0, (int)v75);
                  }
                }
              }
LABEL_49:
              v11 = dword_8ADAF8;
              v19 += 14;
              ++LODWORD(v60);
              if ( SLODWORD(v60) >= dword_8ADAF8 )
                break;
              continue;
            default:
              goto LABEL_49;
          }
          break;
        }
      }
      v37 = 0;
      if ( v11 > 0 )
      {
        v38 = (float *)&unk_8AD404;
        do
        {
          v39 = *v38;
          if ( *(_DWORD *)v38 != 9 && LODWORD(v39) != 10 )
          {
            switch ( LODWORD(v39) )
            {
              case 0:
              case 3:
                v46 = *(double *)(*(_DWORD *)(*((_DWORD *)v38 + 1) + 32) + 384);
                goto LABEL_73;
              case 1:
              case 4:
                v46 = *(double *)(*(_DWORD *)(*((_DWORD *)v38 + 1) + 32) + 384);
                goto LABEL_73;
              case 2:
              case 5:
                v46 = *(double *)(*(_DWORD *)(*((_DWORD *)v38 + 1) + 32) + 384);
LABEL_73:
                v53 = v46;
                break;
              case 6:
                v53 = *(float *)(*(_DWORD *)(*((_DWORD *)v38 + 1) + 32) + 13588);
                break;
              default:
                break;
            }
            v60 = *(v38 - 1) * *(float *)(this + 13588) / (v53 + *(float *)(this + 13588));
            *(v38 - 1) = *(v38 - 1) - v60;
          }
          sub_4EC080(v38 - 3);
          if ( *(_DWORD *)v38 != 9 && *(_DWORD *)v38 != 10 )
          {
            v47 = *((_DWORD *)v38 + 1);
            *(v38 - 1) = -v60;
            sub_40F550(v47, (int)(v38 - 3));
          }
          v11 = dword_8ADAF8;
          ++v37;
          v38 += 14;
        }
        while ( v37 < dword_8ADAF8 );
      }
      if ( !*(_DWORD *)(this + 15004) )
      {
        sub_4E9630((_DWORD *)this);
        v11 = dword_8ADAF8;
      }
      v48 = *(float **)(this + 15004);
      v62 = *v48 - *(float *)(this + 13524);
      v68 = v62;
      v64 = v48[1] - *(float *)(this + 13528);
      v70 = v64;
      v66 = v48[2] - *(float *)(this + 13532);
      v72 = v66;
      if ( v62 != 0.0 || v64 != 0.0 || v66 != 0.0 )
      {
        v49 = 1.0 / sqrt(v66 * v66 + v64 * v64 + v62 * v62);
        v68 = v62 * v49;
        v70 = v64 * v49;
        v72 = v66 * v49;
      }
      v50 = 0;
      if ( v11 > 0 )
      {
        v51 = (float *)&unk_8AD428;
        do
        {
          if ( *((_DWORD *)v51 - 9) == 9 && v72 * v51[1] + v68 * *(v51 - 1) + v70 * *v51 < -0.70700002 )
          {
            *(_BYTE *)(this + 16368) = 1;
            v11 = dword_8ADAF8;
          }
          ++v50;
          v51 += 14;
        }
        while ( v50 < v11 );
      }
    }
  }
}
