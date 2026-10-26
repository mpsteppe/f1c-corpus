void __userpurge sub_582400(int a1@<ecx>, float a2@<ebp>, float *a3, float *a4, int a5)
{
  int v5; // eax
  unsigned int v6; // kr00_4
  int v7; // eax
  float v9; // ecx
  long double v10; // st7
  float v11; // edx
  long double v12; // st7
  int v13; // edi
  double v14; // st6
  double v15; // st4
  double v16; // st5
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  int v20; // edx
  double v21; // st7
  int v22; // ecx
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  float v27; // ecx
  float v28; // edx
  int v29; // ecx
  double v30; // st6
  double v31; // st4
  double v32; // st5
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  float v40; // ecx
  float v41; // edx
  int v42; // ecx
  float *v43; // ecx
  int v44; // edx
  int v45; // edi
  float *v46; // ebp
  float *v47; // ebx
  double v48; // st7
  double v49; // st7
  _BYTE *v50; // eax
  double v51; // st7
  int v52; // ecx
  int v53; // edx
  double v54; // st7
  int v55; // ecx
  double v56; // st7
  double v57; // st7
  double v58; // st6
  double v59; // st5
  double v60; // st5
  double v61; // st7
  float v62; // ecx
  float v63; // edx
  unsigned int v64; // edi
  char *v65; // ebx
  float *v66; // ebp
  double v67; // st7
  double v68; // st7
  double v69; // st7
  double v70; // st7
  double v71; // st7
  double v72; // st7
  double v73; // st7
  double v74; // st7
  double v75; // st7
  float v76; // ecx
  float v77; // edx
  int v78; // ecx
  int v79; // eax
  int v80; // eax
  double v81; // st7
  double v82; // st7
  double v83; // st7
  int v84; // eax
  double v85; // st7
  int v86; // [esp-4h] [ebp-A0h]
  float v87; // [esp+18h] [ebp-84h]
  float v88; // [esp+1Ch] [ebp-80h]
  int v89; // [esp+20h] [ebp-7Ch]
  float *v90; // [esp+20h] [ebp-7Ch]
  float v91; // [esp+24h] [ebp-78h]
  int v92; // [esp+24h] [ebp-78h]
  int v93; // [esp+24h] [ebp-78h]
  float v94; // [esp+28h] [ebp-74h]
  float v95; // [esp+2Ch] [ebp-70h]
  float v96; // [esp+30h] [ebp-6Ch]
  float v97; // [esp+34h] [ebp-68h]
  float v98; // [esp+3Ch] [ebp-60h]
  float v99; // [esp+3Ch] [ebp-60h]
  float v100; // [esp+3Ch] [ebp-60h]
  float v101; // [esp+40h] [ebp-5Ch]
  float v102; // [esp+40h] [ebp-5Ch]
  float v103; // [esp+40h] [ebp-5Ch]
  float v104; // [esp+44h] [ebp-58h]
  float v105; // [esp+44h] [ebp-58h]
  float v106; // [esp+44h] [ebp-58h]
  int v107; // [esp+48h] [ebp-54h] BYREF
  float v108; // [esp+4Ch] [ebp-50h] BYREF
  float v109; // [esp+50h] [ebp-4Ch] BYREF
  float v110; // [esp+54h] [ebp-48h] BYREF
  float v111; // [esp+58h] [ebp-44h] BYREF
  float v112; // [esp+5Ch] [ebp-40h] BYREF
  float v113; // [esp+60h] [ebp-3Ch]
  float v114; // [esp+64h] [ebp-38h]
  float v115; // [esp+68h] [ebp-34h]
  float v116; // [esp+6Ch] [ebp-30h]
  float v117; // [esp+70h] [ebp-2Ch]
  float v118; // [esp+74h] [ebp-28h]
  float v119; // [esp+78h] [ebp-24h]
  int v120; // [esp+7Ch] [ebp-20h]
  float *v121; // [esp+80h] [ebp-1Ch]
  float v122; // [esp+84h] [ebp-18h]
  int v123; // [esp+88h] [ebp-14h]

  if ( *(_DWORD *)a1 == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
  {
    if ( !byte_B660D7 && (!*(_BYTE *)(a1 + 15556) || !byte_B660DC) )
    {
LABEL_9:
      v104 = fabs(*(float *)(a5 + 4));
      v98 = (double)dword_B71DEC * v104 * 0.0099999998;
      if ( v98 > (double)*(float *)(a1 + 18448) )
        sub_577700((float *)a1);
      v101 = v98 * *(float *)(a1 + 18452);
      if ( v104 > (double)*(float *)(a1 + 18456) )
      {
        if ( v101 > 1.0 )
          v101 = 1.0;
        if ( a3[2] >= -1.0 )
        {
          if ( a3[2] >= 1.0 )
            sub_57C0C0((void *)a1, v101);
          else
            sub_57C060((void *)a1, v101);
        }
        else
        {
          sub_57C000((void *)a1, v101);
        }
        if ( byte_B71E10 )
        {
          v9 = *a4;
          v10 = v101 * *(float *)(a1 + 18460);
          v11 = a4[1];
          v111 = a4[2];
          v109 = v9;
          v110 = v11;
          if ( v10 > 1.0 )
            v10 = 1.0;
          v12 = sqrt(v10) / v104;
          v109 = v109 * v12;
          v110 = v110 * v12;
          v111 = v111 * v12;
          v13 = off_9034A4;
          if ( dword_82F4A0 < 1023 )
          {
            ++dword_82F4A0;
            off_9034A4 += 848;
          }
          *(float *)&v89 = dbl_FB1D18;
          sub_51B2A0((_DWORD *)v13, 2, 7, 14, *(_DWORD *)(a1 + 4), v89, 0);
          v112 = *a3 * 0.5;
          v113 = a3[1] * 0.66666669;
          v114 = a3[2] * 0.2857143;
          sub_573990((char *)(v13 + 8), &v112);
          sub_573990((char *)(v13 + 11), &v109);
          *(_DWORD *)(v13 + 14) = *(_DWORD *)(a1 + 15932);
          sub_573990((char *)(v13 + 18), (float *)(a5 + 60));
          *(_BYTE *)(v13 + 21) = *(_BYTE *)(a5 + 12);
        }
        sub_4FB7E0((void *)(a1 + 14808), 1, 5);
      }
      if ( *(_DWORD *)(a1 + 4336) )
      {
        if ( *(_BYTE *)(a1 + 4400) )
        {
          v14 = a3[2] - *(float *)(a1 + 18480);
          v15 = a3[1] - *(float *)(a1 + 18476);
          v16 = v14 * v14 + v15 * v15;
          if ( v16 < v96 && (1.0 - v16 / v96) * v97 > *(float *)(a1 + 18464) )
          {
            v17 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
            if ( v17 < *(float *)(a1 + 18468) )
            {
              LODWORD(v88) = a1 + 4336;
              sub_56DFC0();
              sub_4FB7E0((void *)(a1 + 14808), 1, 6);
              if ( !*(_DWORD *)(a1 + 18412) )
                *(_DWORD *)(a1 + 18412) = 1;
              *(_DWORD *)(a1 + 17432) = *(_DWORD *)(a1 + 17448);
              sub_579710(a1, 0);
              if ( !*(_DWORD *)(a1 + 14804) )
                sub_4EE910(dword_B6F1C8, 4);
              v110 = *(float *)(a1 + 15932);
              sub_416420((float *)(a1 + 15936), (float *)(a1 + 15972), (float *)(a1 + 18472), &v111);
              v6 = __readeflags();
              v7 = *(_DWORD *)__ROL4__(dword_16C6EA0, dword_16F9924);
              __writeeflags(v6);
              v18 = flt_BE0CA4[(unsigned __int8)v7];
              dword_BE08A0 = v7 + 1;
              v19 = (unsigned __int8)(v7 + 1);
              v7 += 2;
              v111 = v18 * 0.2 + v111;
              v20 = (unsigned __int8)v7;
              v21 = flt_BE0CA4[v19];
              dword_BE08A0 = v7++;
              v22 = (unsigned __int8)v7;
              v120 = 0;
              v121 = 0;
              v112 = v21 * 0.2 + v112;
              v122 = 0.0;
              v23 = flt_BE0CA4[v20];
              dword_BE08A0 = v7++;
              v113 = v23 * 0.2 + v113;
              v24 = flt_BE0CA4[v22];
              dword_BE08A0 = v7;
              v117 = v24 + v24;
              v25 = flt_BE0CA4[(unsigned __int8)v7];
              dword_BE08A0 = v7 + 1;
              v118 = v25 + v25 + 5.0;
              v26 = flt_BE0CA4[(unsigned __int8)(v7 + 1)];
              dword_BE08A0 = v7 + 2;
              v27 = *(float *)(a1 + 15988);
              v28 = *(float *)(a1 + 15992);
              v114 = *(float *)(a1 + 15984);
              v115 = v27;
              v29 = *(_DWORD *)(a1 + 4);
              v116 = v28;
              v119 = v26 + v26;
              sub_41A1F0(&dword_91BF88, 4, (float *)(a1 + 18484), v29, 0, &v110);
            }
          }
        }
      }
      if ( *(_DWORD *)(a1 + 4404) )
      {
        if ( *(_BYTE *)(a1 + 4468) )
        {
          v30 = a3[2] - *(float *)(a1 + 18528);
          v31 = a3[1] - *(float *)(a1 + 18524);
          v32 = v30 * v30 + v31 * v31;
          if ( v32 < v91 && (1.0 - v32 / v91) * a2 > *(float *)(a1 + 18512) )
          {
            v33 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
            if ( v33 < *(float *)(a1 + 18516) )
            {
              sub_56DFC0();
              sub_4FB7E0((void *)(a1 + 14808), 1, 7);
              if ( !*(_DWORD *)(a1 + 18412) )
                *(_DWORD *)(a1 + 18412) = 1;
              *(_DWORD *)(a1 + 17432) = *(_DWORD *)(a1 + 17448);
              sub_579710(a1, 0);
              if ( !*(_DWORD *)(a1 + 14804) )
                sub_4EE910(dword_B6F1C8, 5);
              v107 = *(_DWORD *)(a1 + 15932);
              sub_416420((float *)(a1 + 15936), (float *)(a1 + 15972), (float *)(a1 + 18520), &v108);
              v34 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.2;
              v108 = v34 + v108;
              v35 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              v117 = 0.0;
              v118 = 0.0;
              v109 = v35 * 0.2 + v109;
              v119 = 0.0;
              v36 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              v110 = v36 * 0.2 + v110;
              v37 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              v114 = v37 + v37;
              v38 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              v115 = v38 + v38 + 5.0;
              v39 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              v40 = *(float *)(a1 + 15988);
              v41 = *(float *)(a1 + 15992);
              v111 = *(float *)(a1 + 15984);
              v112 = v40;
              v42 = *(_DWORD *)(a1 + 4);
              v113 = v41;
              v116 = v39 + v39;
              sub_41A1F0(&dword_91BF88, 4, (float *)(a1 + 18532), v42, 1, (float *)&v107);
            }
          }
        }
      }
      v43 = (float *)(a1 + 18732);
      v44 = a1 + 4472;
      v45 = 0;
      v46 = (float *)(a1 + 18860);
      v47 = (float *)(a1 + 18764);
      LODWORD(v122) = a1 + 18732;
      v92 = a1 + 4472;
      do
      {
        if ( *(_DWORD *)v44 )
        {
          if ( *(_BYTE *)(v44 + 64) )
          {
            v99 = *v121 - *v47;
            v102 = v121[1] - v47[1];
            v105 = v121[2] - v47[2];
            v48 = v99 * v99 + v105 * v105 + v102 * v102;
            if ( v48 < v87 && (1.0 - v48 / v87) * v88 > *(v43 - 8) )
            {
              v49 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
              if ( v49 < *v43 )
              {
                sub_57C120((_DWORD *)a1, v45 + 6);
                v50 = *(_BYTE **)(a1 + 5116);
                if ( v50
                  && !*v50
                  && *(_DWORD *)(*(_DWORD *)a1 + 22468) == *(_DWORD *)(dword_91E084 + 22468)
                  && (!(unsigned __int8)sub_4735E0(&dword_B6CBA8) || !sub_473630(&dword_B6CBA8)) )
                {
                  sub_44E880(&dbl_B66040, 30, dbl_B67D08);
                }
                v107 = *(_DWORD *)(a1 + 15932);
                sub_416420((float *)(a1 + 15936), (float *)(a1 + 15972), v47, &v108);
                v5 = *off_16C9994;
                v51 = flt_BE0CA4[(unsigned __int8)*off_16C9994];
                dword_BE08A0 = *off_16C9994 + 1;
                v52 = (unsigned __int8)(v5 + 1);
                v5 += 2;
                v108 = v51 * 0.2 + v108;
                v53 = (unsigned __int8)v5;
                v54 = flt_BE0CA4[v52];
                dword_BE08A0 = v5++;
                v55 = (unsigned __int8)v5;
                v109 = v54 * 0.2 + v109;
                v56 = flt_BE0CA4[v53];
                dword_BE08A0 = v5++;
                v110 = v56 * 0.2 + v110;
                v57 = *(float *)(a1 + 15996) * 0.30000001;
                v58 = *(float *)(a1 + 16000) * 0.30000001 + 5.0;
                v116 = *(float *)(a1 + 16004) * 0.30000001;
                v59 = flt_BE0CA4[v55];
                dword_BE08A0 = v5;
                v114 = v59 + v59 + v57;
                v60 = flt_BE0CA4[(unsigned __int8)v5];
                dword_BE08A0 = v5 + 1;
                v115 = v60 + v60 + v58;
                v61 = flt_BE0CA4[(unsigned __int8)(v5 + 1)];
                dword_BE08A0 = v5 + 2;
                v62 = *(float *)(a1 + 15988);
                v63 = *(float *)(a1 + 15992);
                v111 = *(float *)(a1 + 15984);
                v112 = v62;
                v116 = v61 + v61 + v116;
                v86 = *(_DWORD *)(a1 + 4);
                v113 = v63;
                v117 = 0.0;
                v118 = 0.0;
                v119 = 0.0;
                sub_41A1F0(&dword_91BF88, 5, v46, v86, v45, (float *)&v107);
                v44 = v92;
                *(float *)&v43 = v122;
              }
            }
          }
        }
        ++v45;
        ++v43;
        v44 += 68;
        v47 += 3;
        v46 += 7;
        v122 = *(float *)&v43;
        v92 = v44;
      }
      while ( v45 < 8 );
      v64 = 0;
      v65 = (char *)&unk_B66308;
      v90 = (float *)(a1 + 18588);
      v93 = a1 + 3152;
      v66 = (float *)(a1 + 16160);
      while ( 1 )
      {
        if ( *(_DWORD *)v93 )
        {
          if ( *(_BYTE *)(v93 + 64) )
          {
            v100 = *v121 - *v66;
            v103 = v121[1] - v66[1];
            v106 = v121[2] - v66[2];
            v67 = v100 * v100 + v106 * v106 + v103 * v103;
            if ( v67 < v87 )
              break;
          }
        }
LABEL_88:
        v65 += 1280;
        ++v64;
        v66 += 63;
        v93 += 296;
        v90 += 7;
        if ( (int)v65 >= (int)byte_B67708 )
          return;
      }
      v68 = (1.0 - v67 / v87) * v88;
      v122 = v68;
      if ( v68 > *(float *)(a1 + 18576) )
      {
        if ( v122 <= (double)*(float *)(a1 + 18580)
          || (v69 = flt_BE08A4[(unsigned __int8)dword_BE08A0], ++dword_BE08A0, v69 >= *(float *)(a1 + 18584)) )
        {
          if ( !*(_DWORD *)(a1 + 14804) )
          {
            v81 = *(float *)(a1 + 18580) - *(float *)(a1 + 18576);
            if ( v81 > 0.0 )
            {
              v82 = (v122 - *(float *)(a1 + 18576)) / v81;
              v94 = v82;
              if ( v82 > 1.0 )
                v94 = 1.0;
              sub_447150(&dbl_B66040, v64, v94);
            }
          }
          goto LABEL_81;
        }
        sub_57C120((_DWORD *)a1, v64);
        v107 = *(_DWORD *)(a1 + 15932);
        sub_416420((float *)(a1 + 15936), (float *)(a1 + 15972), v66, &v108);
        v70 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.2;
        v108 = v70 + v108;
        v71 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v117 = 0.0;
        v118 = 0.0;
        v109 = v71 * 0.2 + v109;
        v119 = 0.0;
        v72 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v110 = v72 * 0.2 + v110;
        v73 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v114 = v73 + v73;
        v74 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v115 = v74 + v74 + 5.0;
        v75 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
        v76 = *(float *)(a1 + 15988);
        v77 = *(float *)(a1 + 15992);
        v111 = *(float *)(a1 + 15984);
        v112 = v76;
        v78 = *(_DWORD *)(a1 + 4);
        v116 = v75 + v75;
        v113 = v77;
        sub_41A1F0(&dword_91BF88, 3, v90, v78, v64, (float *)&v107);
        v79 = *(_DWORD *)(a1 + 17244);
        if ( v79 )
        {
          v80 = v79 - 1;
          if ( v80 && (v80 != 1 || v65 != (char *)&unk_B66308 && v65 != (char *)&unk_B66808) )
            goto LABEL_81;
        }
        else if ( v65 != (char *)&unk_B66D08 && v65 != (char *)&unk_B67208 )
        {
          goto LABEL_81;
        }
        sub_577700((float *)a1);
      }
LABEL_81:
      v83 = *(float *)(a1 + 18560);
      v84 = *(_DWORD *)(v123 + 12);
      v95 = *(float *)(a1 + 18564);
      if ( v84 == 5 || v84 == 4 )
      {
        v83 = *(float *)(a1 + 18568);
        v95 = *(float *)(a1 + 18572);
      }
      if ( v122 > v83 )
      {
        v85 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
        if ( v85 < v95 && !*(_DWORD *)(a1 + 14804) )
          sub_4397B0();
      }
      goto LABEL_88;
    }
  }
  else if ( *(_DWORD *)(a1 + 14804) != 1 || dword_B64134 != 1 && dword_B64134 != 3 )
  {
    goto LABEL_9;
  }
}
