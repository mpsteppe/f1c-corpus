int __cdecl sub_564EA2(int *a1, int *a2, int a3)
{
  unsigned int v4; // ecx
  int *v5; // esi
  char *v6; // eax
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  char *v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // edx
  int v27; // eax
  unsigned int v28; // ecx
  char *v29; // edx
  unsigned int v30; // eax
  const void *v31; // esi
  void *v32; // edi
  unsigned int v33; // ecx
  int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // eax
  int v38; // eax
  unsigned int i; // ecx
  int v40; // eax
  char v41; // al
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  int v46; // eax
  unsigned int v47; // ecx
  unsigned int v48; // edx
  int v49; // eax
  int v50; // edx
  int v51; // ecx
  int v52; // eax
  unsigned int v53; // eax
  unsigned int v54; // eax
  int v55; // eax
  char *v56; // eax
  int v57; // eax
  char *v58; // ecx
  unsigned int v59; // eax
  int v60; // eax
  bool v61; // zf
  int v62; // eax
  char *v63; // eax
  unsigned __int8 *v64; // ecx
  int v65; // [esp-28h] [ebp-68h]
  int v66; // [esp-1Ch] [ebp-5Ch]
  int v67; // [esp-14h] [ebp-54h]
  int v68; // [esp-8h] [ebp-48h]
  int v69; // [esp-8h] [ebp-48h]
  int v70; // [esp-4h] [ebp-44h]
  int v71; // [esp+Ch] [ebp-34h] BYREF
  int v72; // [esp+10h] [ebp-30h] BYREF
  unsigned int v73; // [esp+14h] [ebp-2Ch]
  int v74; // [esp+18h] [ebp-28h] BYREF
  int v75; // [esp+1Ch] [ebp-24h] BYREF
  int v76; // [esp+20h] [ebp-20h] BYREF
  int v77; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int v78; // [esp+28h] [ebp-18h] BYREF
  int v79; // [esp+2Ch] [ebp-14h] BYREF
  unsigned int v80; // [esp+30h] [ebp-10h]
  char *v81; // [esp+34h] [ebp-Ch]
  unsigned int v82; // [esp+38h] [ebp-8h]
  unsigned int v83; // [esp+3Ch] [ebp-4h]
  unsigned int v84; // [esp+48h] [ebp+8h]
  unsigned int v85; // [esp+48h] [ebp+8h]
  int v86; // [esp+50h] [ebp+10h]

  v4 = a1[12];
  v5 = a2;
  v82 = a2[1];
  v83 = a1[8];
  v84 = a1[7];
  v6 = (char *)a1[13];
  v7 = (unsigned __int8 *)*a2;
  v79 = *a2;
  v81 = v6;
  if ( (unsigned int)v6 >= v4 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v4 - (_DWORD)v6 - 1;
  v9 = *a1;
  v80 = v8;
  while ( 2 )
  {
    switch ( v9 )
    {
      case 0:
        while ( v84 < 3 )
        {
          if ( !v82 )
            goto LABEL_114;
          v13 = *v7;
          a3 = 0;
          --v82;
          v83 |= v13 << v84;
          ++v7;
          v84 += 8;
          v79 = (int)v7;
        }
        v14 = (unsigned __int8)(v83 & 7) >> 1;
        a1[6] = v83 & 1;
        if ( !v14 )
        {
          v85 = v84 - 3;
          v20 = v85 & 7;
          v21 = v83 >> 3 >> v20;
          v84 = v85 - v20;
          *a1 = 1;
          v83 = v21;
          goto LABEL_107;
        }
        v15 = v14 - 1;
        if ( v15 )
        {
          v16 = v15 - 1;
          if ( !v16 )
          {
            v83 >>= 3;
            v18 = 3;
            v84 -= 3;
            goto LABEL_22;
          }
          if ( v16 != 1 )
            goto LABEL_107;
          v17 = v83 >> 3;
          *a1 = 9;
          v5[6] = (int)"invalid block type";
          a1[8] = v17;
          v10 = v84 - 3;
          v70 = -3;
          goto LABEL_7;
        }
        sub_567C88(&v74, &v75, &v76, &v77);
        v19 = sub_5671D8(v74, v75, v76, v77, v5);
        a1[1] = v19;
        if ( !v19 )
          goto LABEL_120;
        v83 >>= 3;
        v84 -= 3;
        *a1 = 6;
        goto LABEL_107;
      case 1:
        v22 = v84;
        while ( 2 )
        {
          if ( v22 < 0x20 )
          {
            if ( v82 )
            {
              v23 = *v7;
              a3 = 0;
              --v82;
              v83 |= v23 << v22;
              ++v7;
              v22 += 8;
              v79 = (int)v7;
              v84 = v22;
              continue;
            }
LABEL_114:
            v70 = a3;
            a1[8] = v83;
            a1[7] = v84;
            v5[1] = 0;
LABEL_8:
            v5[2] += (int)&v7[-*v5];
            v11 = (unsigned int)v81;
LABEL_9:
            *v5 = (int)v7;
            a1[13] = v11;
            return sub_567CB7(a1, v5, v70);
          }
          break;
        }
        if ( ~v83 >> 16 != (unsigned __int16)v83 )
        {
          *a1 = 9;
          v5[6] = (int)"invalid stored block lengths";
          goto LABEL_110;
        }
        a1[1] = (unsigned __int16)v83;
        v61 = a1[1] == 0;
        v84 = 0;
        v83 = 0;
        if ( v61 )
LABEL_57:
          v18 = a1[6] != 0 ? 7 : 0;
        else
          v18 = 2;
LABEL_22:
        *a1 = v18;
LABEL_107:
        v9 = *a1;
        v5 = a2;
        v7 = (unsigned __int8 *)v79;
        if ( (unsigned int)*a1 > 9 )
        {
LABEL_5:
          v70 = -2;
          goto LABEL_6;
        }
        v8 = v80;
        continue;
      case 2:
        if ( !v82 )
          goto LABEL_114;
        if ( !v8 )
        {
          if ( (v24 = (char *)a1[11], v81 != v24)
            || (v25 = a1[12], v26 = a1[10], v26 == v25)
            || ((v81 = (char *)a1[10], v26 >= v25) ? (v8 = (unsigned int)&v24[-v26]) : (v8 = v25 - v26 - 1),
                (v80 = v8) == 0) )
          {
            a1[13] = (int)v81;
            v27 = sub_567CB7(a1, v5, a3);
            v28 = a1[12];
            v86 = v27;
            v81 = (char *)a1[13];
            v11 = (unsigned int)v81;
            v78 = v28;
            if ( (unsigned int)v81 >= v28 )
              v8 = a1[11] - (_DWORD)v81;
            else
              v8 = v28 - (_DWORD)v81 - 1;
            v29 = (char *)a1[11];
            v80 = v8;
            v73 = (unsigned int)v29;
            if ( v81 == v29 )
            {
              v11 = a1[10];
              if ( v11 == v78 )
              {
                v11 = (unsigned int)v81;
              }
              else
              {
                v81 = (char *)a1[10];
                if ( v11 >= v78 )
                  v8 = v73 - v11;
                else
                  v8 = v78 - v11 - 1;
                v80 = v8;
              }
            }
            if ( !v8 )
            {
              v70 = v86;
              a1[8] = v83;
              a1[7] = v84;
              v5[1] = v82;
              v5[2] += (int)&v7[-*v5];
              goto LABEL_9;
            }
          }
        }
        v30 = a1[1];
        a3 = 0;
        if ( v30 > v82 )
          v30 = v82;
        if ( v30 > v8 )
          v30 = v8;
        v31 = (const void *)v79;
        v32 = v81;
        v79 += v30;
        v82 -= v30;
        v81 += v30;
        v80 -= v30;
        qmemcpy(v32, v31, v30);
        v61 = a1[1] == v30;
        a1[1] -= v30;
        if ( v61 )
          goto LABEL_57;
        goto LABEL_107;
      case 3:
        v33 = v84;
        while ( 2 )
        {
          if ( v33 < 0xE )
          {
            if ( v82 )
            {
              v34 = *v7;
              a3 = 0;
              --v82;
              v83 |= v34 << v33;
              ++v7;
              v33 += 8;
              v84 = v33;
              continue;
            }
            goto LABEL_114;
          }
          break;
        }
        v35 = v83 & 0x3FFF;
        v36 = v83 & 0x1F;
        a1[1] = v35;
        if ( v36 > 0x1D || (v37 = (v35 >> 5) & 0x1F, v37 > 0x1D) )
        {
          *a1 = 9;
          v5[6] = (int)"too many length or distance symbols";
LABEL_110:
          v70 = -3;
LABEL_6:
          a1[8] = v83;
          v10 = v84;
LABEL_7:
          a1[7] = v10;
          v5[1] = v82;
          goto LABEL_8;
        }
        v38 = ((int (__cdecl *)(int, unsigned int, int))v5[8])(v5[10], v37 + v36 + 258, 4);
        a1[3] = v38;
        if ( !v38 )
          goto LABEL_120;
        v83 >>= 14;
        v84 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_71:
        while ( a1[2] < ((unsigned int)a1[1] >> 10) + 4 )
        {
          for ( i = v84; i < 3; v84 = i )
          {
            if ( !v82 )
              goto LABEL_114;
            v40 = *v7;
            a3 = 0;
            --v82;
            v83 |= v40 << i;
            ++v7;
            i += 8;
          }
          v41 = v83;
          v42 = dword_5F5C88[a1[2]];
          v43 = a1[3];
          v83 >>= 3;
          *(_DWORD *)(v43 + 4 * v42) = v41 & 7;
          ++a1[2];
          v84 -= 3;
        }
        while ( (unsigned int)a1[2] < 0x13 )
          *(_DWORD *)(a1[3] + 4 * dword_5F5C88[a1[2]++]) = 0;
        v68 = a1[9];
        v67 = a1[3];
        a1[4] = 7;
        v80 = sub_567B06(v67, a1 + 4, a1 + 5, v68, v5);
        if ( v80 )
        {
          ((void (__cdecl *)(int, int))v5[9])(v5[10], a1[3]);
          v61 = v80 == -3;
LABEL_117:
          if ( v61 )
            *a1 = 9;
          v70 = v80;
          goto LABEL_6;
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_97:
        while ( a1[2] < (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
        {
          v44 = a1[4];
          while ( v84 < v44 )
          {
            if ( !v82 )
              goto LABEL_114;
            v45 = *v7;
            a3 = 0;
            --v82;
            v83 |= v45 << v84;
            ++v7;
            v84 += 8;
          }
          v46 = a1[5] + 8 * (v83 & dword_61A1A0[v44]);
          v47 = *(unsigned __int8 *)(v46 + 1);
          v48 = *(_DWORD *)(v46 + 4);
          v80 = v47;
          v73 = v48;
          if ( v48 >= 0x10 )
          {
            if ( v48 == 18 )
              v49 = 7;
            else
              v49 = v48 - 14;
            v79 = 8 * (v48 == 18) + 3;
            while ( v84 < v49 + v80 )
            {
              if ( !v82 )
                goto LABEL_114;
              v50 = *v7;
              a3 = 0;
              --v82;
              v83 |= v50 << v84;
              ++v7;
              v84 += 8;
            }
            v83 >>= v80;
            v79 += v83 & dword_61A1A0[v49];
            v83 >>= v49;
            v84 -= v80 + v49;
            v51 = a1[2];
            if ( v51 + v79 > (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
            {
LABEL_115:
              ((void (__cdecl *)(int, int))v5[9])(v5[10], a1[3]);
              v62 = v83;
              *a1 = 9;
              v5[6] = (int)"invalid bit length repeat";
              a1[8] = v62;
              a1[7] = v84;
              v5[1] = v82;
              v5[2] += (int)&v7[-*v5];
              v63 = v81;
              *v5 = (int)v7;
              a1[13] = (int)v63;
              return sub_567CB7(a1, v5, -3);
            }
            if ( v73 == 16 )
            {
              if ( !v51 )
                goto LABEL_115;
              v52 = *(_DWORD *)(a1[3] + 4 * v51 - 4);
            }
            else
            {
              v52 = 0;
            }
            do
            {
              *(_DWORD *)(a1[3] + 4 * v51++) = v52;
              --v79;
            }
            while ( v79 );
            a1[2] = v51;
          }
          else
          {
            v83 >>= v47;
            v84 -= v47;
            *(_DWORD *)(a1[3] + 4 * a1[2]++) = v48;
          }
        }
        v53 = a1[1];
        a1[5] = 0;
        v69 = a1[9];
        v66 = a1[3];
        v78 = 9;
        v79 = 6;
        v54 = sub_567B85((v53 & 0x1F) + 257, ((v53 >> 5) & 0x1F) + 1, v66, &v78, &v79, &v71, &v72, v69, v5);
        v65 = a1[3];
        v80 = v54;
        ((void (__cdecl *)(int, int))v5[9])(v5[10], v65);
        if ( v80 )
        {
          v61 = v80 == -3;
          goto LABEL_117;
        }
        v55 = sub_5671D8(v78, v79, v71, v72, v5);
        if ( !v55 )
        {
LABEL_120:
          v70 = -4;
          goto LABEL_6;
        }
        a1[1] = v55;
        *a1 = 6;
LABEL_101:
        a1[8] = v83;
        a1[7] = v84;
        v5[1] = v82;
        v5[2] += (int)&v7[-*v5];
        v56 = v81;
        *v5 = (int)v7;
        a1[13] = (int)v56;
        v57 = sub_56720C(a1, v5, a3);
        if ( v57 != 1 )
          return sub_567CB7(a1, v5, v57);
        a3 = 0;
        sub_567770(a1[1], v5);
        v7 = (unsigned __int8 *)*v5;
        v82 = v5[1];
        v83 = a1[8];
        v58 = (char *)a1[13];
        v84 = a1[7];
        v59 = a1[12];
        v79 = (int)v7;
        v81 = v58;
        if ( (unsigned int)v58 >= v59 )
          v60 = a1[11] - (_DWORD)v81;
        else
          v60 = v59 - (_DWORD)v58 - 1;
        v61 = a1[6] == 0;
        v80 = v60;
        if ( v61 )
        {
          *a1 = 0;
          goto LABEL_107;
        }
        *a1 = 7;
LABEL_122:
        a1[13] = (int)v81;
        v57 = sub_567CB7(a1, v5, a3);
        v61 = a1[12] == a1[13];
        v81 = (char *)a1[13];
        if ( v61 )
        {
          *a1 = 8;
LABEL_126:
          v70 = 1;
          goto LABEL_6;
        }
        a1[8] = v83;
        a1[7] = v84;
        v5[1] = v82;
        v64 = &v7[-*v5];
        *v5 = (int)v7;
        v5[2] += (int)v64;
        a1[13] = (int)v81;
        return sub_567CB7(a1, v5, v57);
      case 4:
        goto LABEL_71;
      case 5:
        goto LABEL_97;
      case 6:
        goto LABEL_101;
      case 7:
        goto LABEL_122;
      case 8:
        goto LABEL_126;
      case 9:
        goto LABEL_110;
      default:
        goto LABEL_5;
    }
  }
}
