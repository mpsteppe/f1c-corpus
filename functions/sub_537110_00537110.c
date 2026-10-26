int __fastcall sub_537110(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  char *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ebp
  int v7; // eax
  unsigned __int8 *v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  int v11; // edx
  unsigned int v12; // ebp
  int v13; // ecx
  int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned int v16; // edi
  int v17; // esi
  int v18; // edx
  unsigned int v19; // edi
  unsigned int v20; // ecx
  char *v21; // ecx
  char *v22; // edx
  unsigned int v23; // eax
  unsigned int v24; // esi
  unsigned __int8 **v25; // edi
  int v26; // eax
  char *v27; // edx
  unsigned int v28; // esi
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  int *v40; // esi
  int v41; // eax
  unsigned int v42; // edi
  unsigned __int8 *v43; // eax
  char v44; // cl
  int v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // ecx
  char v50; // cl
  int v51; // edx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  char v55; // cl
  unsigned int v56; // edi
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  int v61; // edx
  int v62; // ecx
  int v63; // eax
  unsigned __int8 *v64; // ebp
  int v65; // edi
  int v66; // eax
  unsigned int v67; // eax
  unsigned __int8 *v68; // edi
  char *v69; // ecx
  int v70; // eax
  int *v71; // edx
  int v72; // ebp
  int v73; // esi
  int result; // eax
  int *v75; // edx
  int v76; // esi
  int v77; // ecx
  int *v78; // edx
  int v79; // ebp
  unsigned __int8 *v80; // ecx
  int v81; // esi
  unsigned __int8 *v82; // ecx
  unsigned __int8 *v83; // esi
  unsigned __int8 *v84; // ebp
  unsigned __int8 *v85; // esi
  int v86; // edi
  int v87; // esi
  unsigned __int8 *v88; // edi
  int v89; // edx
  int v90; // edx
  unsigned __int8 *v91; // ecx
  unsigned __int8 *v92; // edi
  int v93; // ecx
  int v94; // ecx
  unsigned __int8 *v95; // edx
  unsigned __int8 *v96; // edi
  int v97; // edx
  unsigned __int8 *v98; // edi
  int v99; // edx
  unsigned __int8 *v100; // edi
  int v101; // ecx
  int v102; // eax
  char *v103; // ecx
  int v104; // edx
  unsigned __int8 *v105; // ebp
  unsigned __int8 *v106; // ebp
  int v107; // edx
  int v108; // [esp-1Ch] [ebp-68h]
  int v109; // [esp-8h] [ebp-54h]
  int v110; // [esp-8h] [ebp-54h]
  int v111; // [esp-4h] [ebp-50h]
  unsigned int v112; // [esp-4h] [ebp-50h]
  unsigned __int8 *v113; // [esp+10h] [ebp-3Ch]
  unsigned int v114; // [esp+14h] [ebp-38h]
  char *v115; // [esp+18h] [ebp-34h]
  int v116; // [esp+1Ch] [ebp-30h] BYREF
  int *v117; // [esp+20h] [ebp-2Ch]
  unsigned int v118; // [esp+24h] [ebp-28h]
  int v119; // [esp+28h] [ebp-24h] BYREF
  int v120; // [esp+2Ch] [ebp-20h] BYREF
  int v121; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int v122; // [esp+3Ch] [ebp-10h]
  unsigned int v123; // [esp+40h] [ebp-Ch]
  int v124; // [esp+44h] [ebp-8h] BYREF
  int v125; // [esp+48h] [ebp-4h] BYREF
  int v126; // [esp+50h] [ebp+4h]

  v113 = *a2;
  v114 = (unsigned int)a2[1];
  v4 = (char *)a1[13];
  v5 = a1[12];
  v117 = (int *)a2;
  v6 = a1[7];
  v116 = a1[8];
  v115 = v4;
  if ( (unsigned int)v4 >= v5 )
    v7 = a1[11] - (_DWORD)v4;
  else
    v7 = v5 - (_DWORD)v4 - 1;
  v118 = v7;
LABEL_5:
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 0:
        v8 = v113;
        v9 = v116;
        if ( v6 >= 3 )
          goto LABEL_10;
        v10 = v114;
        do
        {
          if ( !v10 )
          {
            v71 = v117;
            a1[8] = v9;
            a1[7] = v6;
            v72 = *v71;
            v73 = v71[2];
            v71[1] = 0;
            *v71 = (int)v8;
            v66 = a3;
            v71[2] = (int)&v8[v73 - v72];
            a1[13] = v115;
            return AudioRingBufferCopy(v66);
          }
          --v10;
          a3 = 0;
          v11 = *v8 << v6;
          v6 += 8;
          v114 = v10;
          v9 |= v11;
          ++v8;
          v116 = v9;
          v113 = v8;
        }
        while ( v6 < 3 );
LABEL_10:
        a1[6] = v9 & 1;
        switch ( (unsigned __int8)(v9 & 7) >> 1 )
        {
          case 0:
            v12 = v6 - 3;
            *a1 = 1;
            v13 = v12 & 7;
            v6 = v12 - v13;
            v116 = v9 >> 3 >> v13;
            continue;
          case 1:
            ArithmeticComparison_a630(&v121, &v120, v117);
            v14 = ObjectAllocFieldInit(v121, v120, v117);
            a1[1] = v14;
            if ( v14 )
            {
              v116 = v9 >> 3;
              v6 -= 3;
              *a1 = 6;
              continue;
            }
            v75 = v117;
            a1[8] = v9;
            a1[7] = v6;
            v76 = *v75;
            v75[1] = v114;
            v77 = v75[2];
            *v75 = (int)v8;
            v75[2] = (int)&v8[v77 - v76];
            a1[13] = v115;
            result = AudioRingBufferCopy(-4);
            break;
          case 2:
            v116 = v9 >> 3;
            v6 -= 3;
            *a1 = 3;
            continue;
          case 3:
            v78 = v117;
            *a1 = 9;
            v78[6] = (int)aInvalidBlockTy_0;
            a1[8] = v9 >> 3;
            a1[7] = v6 - 3;
            v79 = *v78;
            v78[1] = v114;
            v80 = &v8[-v79];
            *v78 = (int)v8;
            v111 = -3;
            goto LABEL_132;
          default:
            continue;
        }
        return result;
      case 1:
        v15 = v113;
        v16 = v114;
        v17 = v116;
        if ( v6 >= 0x20 )
          goto LABEL_18;
        break;
      case 2:
        v19 = v114;
        if ( !v114 )
        {
          v78 = v117;
          a1[8] = v116;
          a1[7] = v6;
          v81 = v78[2];
          v82 = &v113[-*v78];
          v78[1] = 0;
          v83 = &v82[v81];
          *v78 = (int)v113;
          v111 = a3;
          goto LABEL_133;
        }
        v20 = v118;
        if ( !v118 )
        {
          v21 = (char *)a1[11];
          v22 = v115;
          if ( v115 != v21 )
            goto LABEL_29;
          v23 = a1[12];
          v24 = a1[10];
          if ( v23 == v24 )
            goto LABEL_29;
          v22 = (char *)a1[10];
          v115 = v22;
          v20 = v24 >= v23 ? (unsigned int)&v21[-v24] : v23 - v24 - 1;
          v118 = v20;
          if ( !v20 )
          {
LABEL_29:
            v25 = (unsigned __int8 **)v117;
            a1[13] = v22;
            v26 = AudioRingBufferCopy(a3);
            v27 = (char *)a1[13];
            v28 = a1[12];
            v126 = v26;
            v115 = v27;
            if ( (unsigned int)v27 >= v28 )
              v20 = a1[11] - (_DWORD)v27;
            else
              v20 = v28 - (_DWORD)v27 - 1;
            v29 = a1[11];
            v118 = v20;
            v119 = v29;
            if ( v27 == (char *)v29 )
            {
              v30 = a1[10];
              if ( v28 != v30 )
              {
                v27 = (char *)a1[10];
                v115 = v27;
                if ( v30 >= v28 )
                  v20 = v119 - v30;
                else
                  v20 = v28 - v30 - 1;
                v118 = v20;
              }
            }
            if ( !v20 )
            {
              a1[8] = v116;
              a1[7] = v6;
              v84 = *v25;
              v85 = v25[2];
              v25[1] = (unsigned __int8 *)v114;
              *v25 = v113;
              v25[2] = &v85[v113 - v84];
              a1[13] = v27;
              return AudioRingBufferCopy(v126);
            }
            v19 = v114;
          }
        }
        v31 = a1[1];
        a3 = 0;
        if ( v31 > v19 )
          v31 = v19;
        if ( v31 > v20 )
          v31 = v20;
        qmemcpy(v115, v113, v31);
        v113 += v31;
        v32 = a1[1] - v31;
        v114 -= v31;
        v115 += v31;
        v118 -= v31;
        a1[1] = v32;
        if ( !v32 )
          goto LABEL_45;
        continue;
      case 3:
        v33 = v116;
        if ( v6 >= 0xE )
          goto LABEL_50;
        v34 = v114;
        v35 = v113;
        do
        {
          if ( !v34 )
          {
            v78 = v117;
            v15 = v113;
            a1[8] = v33;
            a1[7] = v6;
            v78[1] = 0;
            goto LABEL_107;
          }
          --v34;
          a3 = 0;
          v36 = *v35 << v6;
          v6 += 8;
          v114 = v34;
          v33 |= v36;
          v113 = ++v35;
        }
        while ( v6 < 0xE );
LABEL_50:
        v37 = v33 & 0x3FFF;
        a1[1] = v37;
        v38 = v33 & 0x1F;
        if ( v38 > 0x1D || (v39 = (v37 >> 5) & 0x1F, v39 > 0x1D) )
        {
          v78 = v117;
          *a1 = 9;
          v111 = -3;
          v78[6] = (int)aTooManyLengthO_0;
          a1[8] = v33;
LABEL_130:
          a1[7] = v6;
          v78[1] = v114;
          v15 = v113;
          goto LABEL_131;
        }
        v40 = v117;
        v41 = ((int (__fastcall *)(int, unsigned int, int))v117[8])(v117[10], v39 + v38 + 258, 4);
        a1[3] = v41;
        if ( !v41 )
        {
          a1[8] = v33;
          a1[7] = v6;
          v88 = (unsigned __int8 *)*v40;
          v40[1] = v114;
          v89 = v40[2];
          *v40 = (int)v113;
          v40[2] = v113 - v88 + v89;
          a1[13] = v115;
          return AudioRingBufferCopy(-4);
        }
        v42 = v33 >> 14;
        v6 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_55:
        if ( a1[2] < (unsigned int)((a1[1] >> 10) + 4) )
        {
          do
          {
            if ( v6 < 3 )
            {
              v43 = v113;
              do
              {
                if ( !v114 )
                {
                  a1[8] = v42;
                  a1[7] = v6;
                  v90 = v40[2];
                  v91 = &v113[-*v40];
                  *v40 = (int)v113;
                  v40[2] = (int)&v91[v90];
                  v40[1] = 0;
                  a1[13] = v115;
                  return AudioRingBufferCopy(a3);
                }
                --v114;
                v44 = v6;
                v6 += 8;
                a3 = 0;
                v42 |= *v43++ << v44;
                v113 = v43;
              }
              while ( v6 < 3 );
            }
            v45 = v42 & 7;
            v6 -= 3;
            v42 >>= 3;
            *(_DWORD *)(a1[3] + 4 * dword_5B7C60[a1[2]]) = v45;
            v46 = a1[2] + 1;
            a1[2] = v46;
          }
          while ( v46 < (a1[1] >> 10) + 4 );
        }
        if ( a1[2] < 0x13u )
        {
          do
          {
            *(_DWORD *)(a1[3] + 4 * dword_5B7C60[a1[2]]) = 0;
            v47 = a1[2] + 1;
            a1[2] = v47;
          }
          while ( v47 < 0x13 );
        }
        v109 = a1[9];
        a1[4] = 7;
        v118 = sub_539F70(a1 + 5, v109, v40);
        if ( v118 )
        {
          ((void (__fastcall *)(int, _DWORD))v40[9])(v40[10], a1[3]);
          if ( v118 == -3 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v6;
          v92 = (unsigned __int8 *)*v40;
          v40[1] = v114;
          v93 = v40[2];
          *v40 = (int)v113;
          v40[2] = v113 - v92 + v93;
          v111 = v118;
          goto LABEL_134;
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_66:
        v48 = v113;
        if ( a1[2] < ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
        {
          while ( 1 )
          {
            v49 = a1[4];
            if ( v6 < v49 )
            {
              while ( v114 )
              {
                v50 = v6;
                v6 += 8;
                --v114;
                a3 = 0;
                v51 = *v48 << v50;
                v49 = a1[4];
                v42 |= v51;
                v113 = ++v48;
                if ( v6 >= v49 )
                  goto LABEL_72;
              }
              goto LABEL_114;
            }
LABEL_72:
            v52 = a1[5] + 8 * (v42 & dword_5DBB90[v49]);
            v53 = *(unsigned __int8 *)(v52 + 1);
            v54 = *(_DWORD *)(v52 + 4);
            v118 = v53;
            v123 = v54;
            if ( v54 >= 0x10 )
            {
              if ( v54 == 18 )
                v119 = 7;
              else
                v119 = v54 - 14;
              v116 = 8 * (v54 == 18) + 3;
              v122 = v119 + v118;
              if ( v6 < v119 + v118 )
              {
                while ( v114 )
                {
                  v55 = v6;
                  v6 += 8;
                  --v114;
                  a3 = 0;
                  v42 |= *v48++ << v55;
                  v113 = v48;
                  if ( v6 >= v122 )
                    goto LABEL_80;
                }
LABEL_114:
                a1[8] = v42;
                a1[7] = v6;
                v94 = v40[2];
                v95 = &v113[-*v40];
                v40[1] = 0;
                *v40 = (int)v113;
                v40[2] = (int)&v95[v94];
                v111 = a3;
                goto LABEL_134;
              }
LABEL_80:
              v56 = v42 >> v118;
              v57 = a1[1];
              v116 += v56 & dword_5DBB90[v119];
              v42 = v56 >> v119;
              v6 -= v118 + v119;
              v58 = a1[2];
              if ( v58 + v116 > ((v57 >> 5) & 0x1F) + (v57 & 0x1F) + 258 )
                goto LABEL_115;
              if ( v123 == 16 )
              {
                if ( !v58 )
                {
LABEL_115:
                  ((void (__fastcall *)(int, _DWORD))v40[9])(v40[10], a1[3]);
                  *a1 = 9;
                  v40[6] = (int)aInvalidBitLeng_0;
                  a1[8] = v42;
                  a1[7] = v6;
                  v96 = (unsigned __int8 *)*v40;
                  v40[1] = v114;
                  v97 = v40[2];
                  *v40 = (int)v113;
                  v40[2] = v113 - v96 + v97;
                  a1[13] = v115;
                  return AudioRingBufferCopy(-3);
                }
                v59 = *(_DWORD *)(a1[3] + 4 * v58 - 4);
              }
              else
              {
                v59 = 0;
              }
              do
              {
                ++v58;
                *(_DWORD *)(a1[3] + 4 * v58 - 4) = v59;
                --v116;
              }
              while ( v116 );
              a1[2] = v58;
            }
            else
            {
              v6 -= v53;
              v42 >>= v53;
              *(_DWORD *)(a1[3] + 4 * a1[2]++) = v54;
            }
            if ( a1[2] >= ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
              break;
            v48 = v113;
          }
        }
        v110 = a1[9];
        v108 = a1[3];
        a1[5] = 0;
        v116 = 9;
        v119 = 6;
        v60 = sub_53A4D0(v108, &v116, &v119, &v125, &v124, v110, v40);
        v61 = a1[3];
        v62 = v40[10];
        v118 = v60;
        ((void (__fastcall *)(int, int))v40[9])(v62, v61);
        if ( v118 )
        {
          if ( v118 == -3 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v6;
          v98 = (unsigned __int8 *)*v40;
          v99 = v40[2];
          v40[1] = v114;
          *v40 = (int)v113;
          v112 = v118;
          v40[2] = v113 - v98 + v99;
          a1[13] = v115;
          return AudioRingBufferCopy(v112);
        }
        else
        {
          v63 = ObjectAllocFieldInit(v125, v124, v40);
          if ( !v63 )
          {
            a1[8] = v42;
            a1[7] = v6;
            v100 = (unsigned __int8 *)*v40;
            v40[1] = v114;
            v101 = v40[2];
            *v40 = (int)v113;
            v111 = -4;
            v40[2] = v113 - v100 + v101;
            goto LABEL_134;
          }
          a1[1] = v63;
          *a1 = 6;
LABEL_92:
          a1[8] = v42;
          a1[7] = v6;
          v64 = (unsigned __int8 *)*v40;
          v65 = v40[2];
          v40[1] = v114;
          *v40 = (int)v113;
          v40[2] = v113 - v64 + v65;
          a1[13] = v115;
          v66 = sub_539870(a3);
          if ( v66 == 1 )
          {
            a3 = 0;
            IndirectCallViaVTable0x24(a1[1], v40);
            v67 = a1[12];
            v68 = (unsigned __int8 *)*v40;
            v6 = a1[7];
            v114 = v40[1];
            v69 = (char *)a1[13];
            v113 = (unsigned __int8 *)*v40;
            v116 = a1[8];
            v115 = v69;
            if ( (unsigned int)v69 >= v67 )
              v70 = a1[11] - (_DWORD)v69;
            else
              v70 = v67 - (_DWORD)v69 - 1;
            v118 = v70;
            if ( !a1[6] )
            {
              *a1 = 0;
              continue;
            }
            *a1 = 7;
LABEL_122:
            a1[13] = v69;
            v102 = AudioRingBufferCopy(a3);
            v103 = (char *)a1[13];
            if ( (char *)a1[12] == v103 )
            {
              *a1 = 8;
LABEL_126:
              a1[8] = v116;
              a1[7] = v6;
              v106 = (unsigned __int8 *)*v40;
              v40[1] = v114;
              v107 = v40[2];
              *v40 = (int)v68;
              v40[2] = v68 - v106 + v107;
              a1[13] = v103;
              return AudioRingBufferCopy(1);
            }
            else
            {
              v104 = v116;
              a1[7] = v6;
              a1[8] = v104;
              v105 = (unsigned __int8 *)*v40;
              v40[1] = v114;
              *v40 = (int)v68;
              v40[2] += v68 - v105;
              a1[13] = v103;
              return AudioRingBufferCopy(v102);
            }
          }
          else
          {
            return AudioRingBufferCopy(v66);
          }
        }
      case 4:
        v42 = v116;
        v40 = v117;
        goto LABEL_55;
      case 5:
        v42 = v116;
        v40 = v117;
        goto LABEL_66;
      case 6:
        v42 = v116;
        v40 = v117;
        goto LABEL_92;
      case 7:
        v69 = v115;
        v68 = v113;
        v40 = v117;
        goto LABEL_122;
      case 8:
        v103 = v115;
        v68 = v113;
        v40 = v117;
        goto LABEL_126;
      case 9:
        v111 = -3;
        goto LABEL_129;
      default:
        v111 = -2;
LABEL_129:
        v78 = v117;
        a1[8] = v116;
        goto LABEL_130;
    }
    break;
  }
  while ( v16 )
  {
    a3 = 0;
    v18 = *v15 << v6;
    --v16;
    v6 += 8;
    v114 = v16;
    v17 |= v18;
    v113 = ++v15;
    if ( v6 >= 0x20 )
    {
LABEL_18:
      if ( (unsigned int)~v17 >> 16 != (unsigned __int16)v17 )
      {
        v78 = v117;
        *a1 = 9;
        v111 = -3;
        v78[6] = (int)aInvalidStoredB_0;
        a1[8] = v17;
        a1[7] = v6;
        v78[1] = v16;
LABEL_131:
        v80 = &v15[-*v78];
        *v78 = (int)v15;
LABEL_132:
        v83 = &v80[v78[2]];
        goto LABEL_133;
      }
      v6 = 0;
      a1[1] = (unsigned __int16)v17;
      v116 = 0;
      if ( (_WORD)v17 )
      {
        *a1 = 2;
        goto LABEL_5;
      }
LABEL_45:
      *a1 = a1[6] != 0 ? 7 : 0;
      goto LABEL_5;
    }
  }
  v78 = v117;
  a1[8] = v17;
  a1[7] = v6;
  v78[1] = 0;
LABEL_107:
  v86 = *v78;
  v87 = v78[2];
  *v78 = (int)v15;
  v83 = &v15[v87 - v86];
  v111 = a3;
LABEL_133:
  v78[2] = (int)v83;
LABEL_134:
  a1[13] = v115;
  return AudioRingBufferCopy(v111);
}
