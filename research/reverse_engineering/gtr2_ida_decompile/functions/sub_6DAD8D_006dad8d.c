int __stdcall sub_6DAD8D(int *a1, int *a2, int a3)
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
  int v54; // eax
  char *v55; // eax
  int v56; // eax
  char *v57; // ecx
  unsigned int v58; // eax
  int v59; // eax
  bool v60; // zf
  unsigned __int8 *v61; // ecx
  int v62; // [esp-1Ch] [ebp-5Ch]
  int v63; // [esp-14h] [ebp-54h]
  int v64; // [esp-8h] [ebp-48h]
  int v65; // [esp-8h] [ebp-48h]
  int v66; // [esp-4h] [ebp-44h]
  int v67; // [esp-4h] [ebp-44h]
  int v68; // [esp+Ch] [ebp-34h] BYREF
  int v69; // [esp+10h] [ebp-30h] BYREF
  unsigned int v70; // [esp+14h] [ebp-2Ch]
  int v71; // [esp+18h] [ebp-28h] BYREF
  int v72; // [esp+1Ch] [ebp-24h] BYREF
  int v73; // [esp+20h] [ebp-20h] BYREF
  int v74; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int v75; // [esp+28h] [ebp-18h] BYREF
  int v76; // [esp+2Ch] [ebp-14h] BYREF
  unsigned int v77; // [esp+30h] [ebp-10h]
  char *v78; // [esp+34h] [ebp-Ch]
  unsigned int v79; // [esp+38h] [ebp-8h]
  unsigned int v80; // [esp+3Ch] [ebp-4h]
  unsigned int v81; // [esp+48h] [ebp+8h]
  unsigned int v82; // [esp+48h] [ebp+8h]
  int v83; // [esp+50h] [ebp+10h]

  v4 = a1[12];
  v5 = a2;
  v79 = a2[1];
  v80 = a1[8];
  v81 = a1[7];
  v6 = (char *)a1[13];
  v7 = (unsigned __int8 *)*a2;
  v76 = *a2;
  v78 = v6;
  if ( (unsigned int)v6 >= v4 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v4 - (_DWORD)v6 - 1;
  v9 = *a1;
  v77 = v8;
LABEL_12:
  switch ( v9 )
  {
    case 0:
      while ( v81 < 3 )
      {
        if ( !v79 )
          goto LABEL_114;
        v13 = *v7;
        a3 = 0;
        --v79;
        v80 |= v13 << v81;
        ++v7;
        v81 += 8;
        v76 = (int)v7;
      }
      v14 = (unsigned __int8)(v80 & 7) >> 1;
      a1[6] = v80 & 1;
      if ( !v14 )
      {
        v82 = v81 - 3;
        v20 = v82 & 7;
        v21 = v80 >> 3 >> v20;
        v81 = v82 - v20;
        *a1 = 1;
        v80 = v21;
        goto LABEL_107;
      }
      v15 = v14 - 1;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( !v16 )
        {
          v80 >>= 3;
          v18 = 3;
          v81 -= 3;
          goto LABEL_22;
        }
        if ( v16 != 1 )
          goto LABEL_107;
        v17 = v80 >> 3;
        *a1 = 9;
        v5[6] = (int)"invalid block type";
        a1[8] = v17;
        v10 = v81 - 3;
        v66 = -3;
        goto LABEL_7;
      }
      sub_6DF7F8(&v71, &v72, &v73, &v74, v5);
      v19 = sub_6DED6B(v71, v72, v73, v74, v5);
      a1[1] = v19;
      if ( !v19 )
        goto LABEL_120;
      v80 >>= 3;
      v81 -= 3;
      *a1 = 6;
      goto LABEL_107;
    case 1:
      v22 = v81;
      while ( 2 )
      {
        if ( v22 >= 0x20 )
        {
          if ( ~v80 >> 16 != (unsigned __int16)v80 )
          {
            *a1 = 9;
            v5[6] = (int)"invalid stored block lengths";
            goto LABEL_110;
          }
          a1[1] = (unsigned __int16)v80;
          v60 = a1[1] == 0;
          v81 = 0;
          v80 = 0;
          if ( v60 )
LABEL_57:
            v18 = a1[6] != 0 ? 7 : 0;
          else
            v18 = 2;
LABEL_22:
          *a1 = v18;
          goto LABEL_107;
        }
        if ( v79 )
        {
          v23 = *v7;
          a3 = 0;
          --v79;
          v80 |= v23 << v22;
          ++v7;
          v22 += 8;
          v76 = (int)v7;
          v81 = v22;
          continue;
        }
        goto LABEL_114;
      }
    case 2:
      if ( !v79 )
        goto LABEL_114;
      if ( !v8 )
      {
        if ( (v24 = (char *)a1[11], v78 != v24)
          || (v25 = a1[12], v26 = a1[10], v26 == v25)
          || ((v78 = (char *)a1[10], v26 >= v25) ? (v8 = (unsigned int)&v24[-v26]) : (v8 = v25 - v26 - 1),
              (v77 = v8) == 0) )
        {
          a1[13] = (int)v78;
          v27 = sub_6DF829(a1, v5, a3);
          v28 = a1[12];
          v83 = v27;
          v78 = (char *)a1[13];
          v11 = (unsigned int)v78;
          v75 = v28;
          if ( (unsigned int)v78 >= v28 )
            v8 = a1[11] - (_DWORD)v78;
          else
            v8 = v28 - (_DWORD)v78 - 1;
          v29 = (char *)a1[11];
          v77 = v8;
          v70 = (unsigned int)v29;
          if ( v78 == v29 )
          {
            v11 = a1[10];
            if ( v11 == v75 )
            {
              v11 = (unsigned int)v78;
            }
            else
            {
              v78 = (char *)a1[10];
              if ( v11 >= v75 )
                v8 = v70 - v11;
              else
                v8 = v75 - v11 - 1;
              v77 = v8;
            }
          }
          if ( !v8 )
          {
            v66 = v83;
            a1[8] = v80;
            a1[7] = v81;
            v5[1] = v79;
            v5[2] += (int)&v7[-*v5];
            goto LABEL_9;
          }
        }
      }
      v30 = a1[1];
      a3 = 0;
      if ( v30 > v79 )
        v30 = v79;
      if ( v30 > v8 )
        v30 = v8;
      v31 = (const void *)v76;
      v32 = v78;
      v76 += v30;
      v79 -= v30;
      v78 += v30;
      v77 -= v30;
      qmemcpy(v32, v31, v30);
      v60 = a1[1] == v30;
      a1[1] -= v30;
      if ( v60 )
        goto LABEL_57;
      goto LABEL_107;
    case 3:
      v33 = v81;
      while ( 2 )
      {
        if ( v33 < 0xE )
        {
          if ( v79 )
          {
            v34 = *v7;
            a3 = 0;
            --v79;
            v80 |= v34 << v33;
            ++v7;
            v33 += 8;
            v81 = v33;
            continue;
          }
LABEL_114:
          v66 = a3;
          a1[8] = v80;
          a1[7] = v81;
          v5[1] = 0;
          goto LABEL_8;
        }
        break;
      }
      v35 = v80 & 0x3FFF;
      v36 = v80 & 0x1F;
      a1[1] = v35;
      if ( v36 > 0x1D || (v37 = (v35 >> 5) & 0x1F, v37 > 0x1D) )
      {
        *a1 = 9;
        v5[6] = (int)"too many length or distance symbols";
        goto LABEL_110;
      }
      v38 = ((int (__stdcall *)(int, unsigned int, int))v5[8])(v5[10], v37 + v36 + 258, 4);
      a1[3] = v38;
      if ( !v38 )
      {
LABEL_120:
        v66 = -4;
        goto LABEL_6;
      }
      v80 >>= 14;
      v81 -= 14;
      a1[2] = 0;
      *a1 = 4;
LABEL_71:
      while ( a1[2] < ((unsigned int)a1[1] >> 10) + 4 )
      {
        for ( i = v81; i < 3; v81 = i )
        {
          if ( !v79 )
            goto LABEL_114;
          v40 = *v7;
          a3 = 0;
          --v79;
          v80 |= v40 << i;
          ++v7;
          i += 8;
        }
        v41 = v80;
        v42 = dword_748A00[a1[2]];
        v43 = a1[3];
        v80 >>= 3;
        *(_DWORD *)(v43 + 4 * v42) = v41 & 7;
        ++a1[2];
        v81 -= 3;
      }
      while ( (unsigned int)a1[2] < 0x13 )
        *(_DWORD *)(a1[3] + 4 * dword_748A00[a1[2]++]) = 0;
      v64 = a1[9];
      v63 = a1[3];
      a1[4] = 7;
      v77 = sub_6DF685(v63, a1 + 4, a1 + 5, v64, v5);
      if ( v77 )
      {
        v60 = v77 == -3;
LABEL_117:
        if ( v60 )
        {
          ((void (__stdcall *)(int, int))v5[9])(v5[10], a1[3]);
          *a1 = 9;
        }
        v66 = v77;
        goto LABEL_6;
      }
      a1[2] = 0;
      *a1 = 5;
      break;
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
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_97:
      if ( a1[2] >= (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
      {
        v53 = a1[1];
        a1[5] = 0;
        v65 = a1[9];
        v62 = a1[3];
        v75 = 9;
        v76 = 6;
        v77 = sub_6DF6FE((v53 & 0x1F) + 257, ((v53 >> 5) & 0x1F) + 1, v62, &v75, &v76, &v68, &v69, v65, v5);
        if ( v77 )
        {
          v60 = v77 == -3;
          goto LABEL_117;
        }
        v54 = sub_6DED6B(v75, v76, v68, v69, v5);
        if ( !v54 )
          goto LABEL_120;
        v67 = a1[3];
        a1[1] = v54;
        ((void (__stdcall *)(int, int))v5[9])(v5[10], v67);
        *a1 = 6;
LABEL_101:
        a1[8] = v80;
        a1[7] = v81;
        v5[1] = v79;
        v5[2] += (int)&v7[-*v5];
        v55 = v78;
        *v5 = (int)v7;
        a1[13] = (int)v55;
        v56 = sub_6DED9E(a1, v5, a3);
        if ( v56 != 1 )
          return sub_6DF829(a1, v5, v56);
        a3 = 0;
        sub_6DF2F5(a1[1], v5);
        v57 = (char *)a1[13];
        v7 = (unsigned __int8 *)*v5;
        v79 = v5[1];
        v80 = a1[8];
        v81 = a1[7];
        v58 = a1[12];
        v76 = (int)v7;
        v78 = v57;
        if ( (unsigned int)v57 >= v58 )
          v59 = a1[11] - (_DWORD)v78;
        else
          v59 = v58 - (_DWORD)v57 - 1;
        v60 = a1[6] == 0;
        v77 = v59;
        if ( !v60 )
        {
          *a1 = 7;
LABEL_122:
          a1[13] = (int)v78;
          v56 = sub_6DF829(a1, v5, a3);
          v60 = a1[12] == a1[13];
          v78 = (char *)a1[13];
          if ( v60 )
          {
            *a1 = 8;
LABEL_126:
            v66 = 1;
            goto LABEL_6;
          }
          a1[8] = v80;
          a1[7] = v81;
          v5[1] = v79;
          v61 = &v7[-*v5];
          *v5 = (int)v7;
          v5[2] += (int)v61;
          a1[13] = (int)v78;
          return sub_6DF829(a1, v5, v56);
        }
        *a1 = 0;
LABEL_107:
        v9 = *a1;
        v7 = (unsigned __int8 *)v76;
        v5 = a2;
        if ( (unsigned int)*a1 > 9 )
        {
LABEL_5:
          v66 = -2;
          goto LABEL_6;
        }
        v8 = v77;
        goto LABEL_12;
      }
      v44 = a1[4];
      while ( v81 < v44 )
      {
        if ( !v79 )
          goto LABEL_114;
        v45 = *v7;
        a3 = 0;
        --v79;
        v80 |= v45 << v81;
        ++v7;
        v81 += 8;
      }
      v46 = a1[5] + 8 * (v80 & dword_91BBC0[v44]);
      v47 = *(unsigned __int8 *)(v46 + 1);
      v48 = *(_DWORD *)(v46 + 4);
      v77 = v47;
      v70 = v48;
      if ( v48 >= 0x10 )
        break;
      v80 >>= v47;
      v81 -= v47;
      *(_DWORD *)(a1[3] + 4 * a1[2]++) = v48;
    }
    v49 = v48 == 18 ? 7 : v48 - 14;
    v76 = 8 * (v48 == 18) + 3;
    while ( v81 < v49 + v77 )
    {
      if ( !v79 )
        goto LABEL_114;
      v50 = *v7;
      a3 = 0;
      --v79;
      v80 |= v50 << v81;
      ++v7;
      v81 += 8;
    }
    v80 >>= v77;
    v76 += v80 & dword_91BBC0[v49];
    v80 >>= v49;
    v81 -= v77 + v49;
    v51 = a1[2];
    if ( v51 + v76 > (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
      break;
    if ( v70 == 16 )
    {
      if ( !v51 )
        break;
      v52 = *(_DWORD *)(a1[3] + 4 * v51 - 4);
    }
    else
    {
      v52 = 0;
    }
    do
    {
      *(_DWORD *)(a1[3] + 4 * v51++) = v52;
      --v76;
    }
    while ( v76 );
    a1[2] = v51;
  }
  ((void (__stdcall *)(int, int))v5[9])(v5[10], a1[3]);
  *a1 = 9;
  v5[6] = (int)"invalid bit length repeat";
LABEL_110:
  v66 = -3;
LABEL_6:
  a1[8] = v80;
  v10 = v81;
LABEL_7:
  a1[7] = v10;
  v5[1] = v79;
LABEL_8:
  v5[2] += (int)&v7[-*v5];
  v11 = (unsigned int)v78;
LABEL_9:
  *v5 = (int)v7;
  a1[13] = v11;
  return sub_6DF829(a1, v5, v66);
}
