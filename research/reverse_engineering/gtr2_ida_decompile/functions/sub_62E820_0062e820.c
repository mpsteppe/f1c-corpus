int __fastcall sub_62E820(int *a1, unsigned __int8 **a2, int a3)
{
  unsigned int v4; // ebp
  int *v5; // esi
  char *v6; // eax
  unsigned int v7; // ecx
  unsigned __int8 *v8; // edi
  unsigned int v9; // ecx
  int v10; // edx
  unsigned int v12; // eax
  int v13; // edx
  unsigned int v14; // ebp
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  char *v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  char *v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // ecx
  int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // eax
  int v28; // eax
  int v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  int v32; // edx
  int v33; // edx
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // edx
  unsigned int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned __int8 *v41; // ebp
  int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // edx
  char *v45; // ecx
  int v46; // eax
  unsigned __int8 *v47; // ecx
  unsigned __int8 *v48; // ecx
  unsigned __int8 *v49; // ebp
  int v50; // ebp
  unsigned __int8 *v51; // ecx
  int v52; // ebp
  int v53; // eax
  int v54; // ebp
  unsigned __int8 *v55; // ecx
  int v56; // [esp-1Ch] [ebp-68h]
  int v57; // [esp-8h] [ebp-54h]
  int v58; // [esp-8h] [ebp-54h]
  int v59; // [esp-4h] [ebp-50h]
  unsigned int v60; // [esp+10h] [ebp-3Ch]
  unsigned int v61; // [esp+14h] [ebp-38h]
  char *v62; // [esp+18h] [ebp-34h]
  unsigned int v63; // [esp+1Ch] [ebp-30h]
  int v64; // [esp+1Ch] [ebp-30h]
  int v65; // [esp+1Ch] [ebp-30h]
  int v66; // [esp+20h] [ebp-2Ch] BYREF
  unsigned int v67; // [esp+24h] [ebp-28h] BYREF
  int *v68; // [esp+28h] [ebp-24h]
  int v69; // [esp+2Ch] [ebp-20h] BYREF
  int v70; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int v71; // [esp+3Ch] [ebp-10h]
  unsigned int v72; // [esp+40h] [ebp-Ch]
  int v73; // [esp+44h] [ebp-8h] BYREF
  int v74; // [esp+48h] [ebp-4h] BYREF
  int v75; // [esp+50h] [ebp+4h]

  v4 = a1[7];
  v5 = (int *)a2;
  v61 = (unsigned int)a2[1];
  v6 = (char *)a1[13];
  v60 = a1[8];
  v7 = a1[12];
  v8 = *a2;
  v68 = (int *)a2;
  v66 = (int)v8;
  v62 = v6;
  if ( (unsigned int)v6 >= v7 )
    v9 = a1[11] - (_DWORD)v6;
  else
    v9 = v7 - (_DWORD)v6 - 1;
  v10 = *a1;
  v63 = v9;
  while ( 2 )
  {
    v12 = v60;
    switch ( v10 )
    {
      case 0:
        if ( v4 >= 3 )
          goto LABEL_13;
        do
        {
          if ( !v61 )
          {
            a1[8] = v60;
            a1[7] = v4;
            v5[1] = 0;
            v59 = a3;
            goto LABEL_7;
          }
          --v61;
          v13 = *v8 << v4;
          v4 += 8;
          a3 = 0;
          v12 |= v13;
          ++v8;
          v60 = v12;
          v66 = (int)v8;
        }
        while ( v4 < 3 );
LABEL_13:
        a1[6] = v12 & 1;
        switch ( (unsigned __int8)(v12 & 7) >> 1 )
        {
          case 0:
            v14 = v4 - 3;
            v15 = v14 & 7;
            v4 = v14 - v15;
            *a1 = 1;
            v60 = v12 >> 3 >> v15;
            break;
          case 1:
            sub_630200(&v70, &v69, v5);
            v16 = sub_62F3D0(v70, v69, v5);
            a1[1] = v16;
            if ( !v16 )
            {
              a1[8] = v60;
              a1[7] = v4;
              v47 = (unsigned __int8 *)v5[2];
              v5[1] = v61;
              v5[2] = (int)&v8[(_DWORD)v47 - *v5];
              *v5 = (int)v8;
              a1[13] = (int)v62;
              return sub_630230(-4);
            }
            v60 >>= 3;
            v4 -= 3;
            *a1 = 6;
            break;
          case 2:
            v60 = v12 >> 3;
            v4 -= 3;
            *a1 = 3;
            break;
          case 3:
            *a1 = 9;
            v5[6] = (int)"invalid block type";
            a1[8] = v60 >> 3;
            a1[7] = v4 - 3;
            v48 = (unsigned __int8 *)v5[2];
            v5[1] = v61;
            v5[2] = (int)&v8[(_DWORD)v48 - *v5];
            *v5 = (int)v8;
            a1[13] = (int)v62;
            return sub_630230(-3);
          default:
            break;
        }
LABEL_95:
        v10 = *a1;
        v5 = v68;
        v8 = (unsigned __int8 *)v66;
        if ( (unsigned int)*a1 > 9 )
        {
LABEL_5:
          v59 = -2;
          goto LABEL_6;
        }
        v9 = v63;
        continue;
      case 1:
        if ( v4 >= 0x20 )
          goto LABEL_21;
        do
        {
          if ( !v61 )
            goto LABEL_107;
          --v61;
          v17 = *v8 << v4;
          v4 += 8;
          a3 = 0;
          v12 |= v17;
          ++v8;
          v60 = v12;
          v66 = (int)v8;
        }
        while ( v4 < 0x20 );
LABEL_21:
        if ( ~v12 >> 16 != (unsigned __int16)v12 )
        {
          *a1 = 9;
          v5[6] = (int)"invalid stored block lengths";
          goto LABEL_109;
        }
        v4 = 0;
        a1[1] = (unsigned __int16)v12;
        v60 = 0;
        if ( !(_WORD)v12 )
          goto LABEL_47;
        *a1 = 2;
        goto LABEL_95;
      case 2:
        if ( !v61 )
          goto LABEL_107;
        if ( v9 )
          goto LABEL_42;
        v18 = (char *)a1[11];
        if ( v62 == v18 )
        {
          v19 = a1[12];
          v20 = a1[10];
          if ( v20 != v19 )
          {
            v62 = (char *)a1[10];
            v9 = v20 >= v19 ? (unsigned int)&v18[-v20] : v19 - v20 - 1;
            v63 = v9;
            if ( v9 )
              goto LABEL_42;
          }
        }
        a1[13] = (int)v62;
        v75 = sub_630230(a3);
        v21 = (char *)a1[13];
        v62 = v21;
        v67 = a1[12];
        if ( (unsigned int)v21 >= v67 )
          v9 = a1[11] - (_DWORD)v21;
        else
          v9 = v67 - (_DWORD)v21 - 1;
        v63 = v9;
        v71 = a1[11];
        if ( v21 == (char *)v71 )
        {
          v21 = (char *)a1[10];
          if ( v21 == (char *)v67 )
          {
            v21 = v62;
          }
          else
          {
            v62 = (char *)a1[10];
            if ( (unsigned int)v21 >= v67 )
            {
              v9 = v71 - (_DWORD)v21;
              v63 = v71 - (_DWORD)v21;
            }
            else
            {
              v9 = v67 - (_DWORD)v21 - 1;
              v63 = v9;
            }
          }
        }
        if ( v9 )
        {
LABEL_42:
          v22 = a1[1];
          a3 = 0;
          if ( v22 > v61 )
            v22 = v61;
          if ( v22 > v9 )
            v22 = v9;
          qmemcpy(v62, (const void *)v66, v22);
          v66 += v22;
          v23 = a1[1] - v22;
          v61 -= v22;
          v62 += v22;
          v63 -= v22;
          a1[1] = v23;
          if ( !v23 )
LABEL_47:
            *a1 = a1[6] != 0 ? 7 : 0;
          goto LABEL_95;
        }
        a1[8] = v60;
        a1[7] = v4;
        v49 = (unsigned __int8 *)v5[2];
        v5[1] = v61;
        v5[2] = (int)&v8[(_DWORD)v49 - *v5];
        *v5 = (int)v8;
        a1[13] = (int)v21;
        return sub_630230(v75);
      case 3:
        if ( v4 >= 0xE )
          goto LABEL_51;
        do
        {
          if ( !v61 )
            goto LABEL_107;
          --v61;
          v24 = *v8 << v4;
          v4 += 8;
          a3 = 0;
          v12 |= v24;
          ++v8;
          v60 = v12;
        }
        while ( v4 < 0xE );
LABEL_51:
        v25 = v12 & 0x3FFF;
        v26 = v25 & 0x1F;
        a1[1] = v25;
        if ( v26 > 0x1D || (v27 = (v25 >> 5) & 0x1F, v27 > 0x1D) )
        {
          *a1 = 9;
          v5[6] = (int)"too many length or distance symbols";
LABEL_109:
          a1[8] = v60;
          a1[7] = v4;
          v50 = *v5;
          v5[1] = v61;
          v5[2] += (int)&v8[-v50];
          *v5 = (int)v8;
          a1[13] = (int)v62;
          return sub_630230(-3);
        }
        else
        {
          v28 = ((int (__fastcall *)(int, unsigned int, int))v5[8])(v5[10], v27 + v26 + 258, 4);
          a1[3] = v28;
          if ( !v28 )
          {
            v59 = -4;
LABEL_6:
            a1[7] = v4;
            a1[8] = v60;
            v5[1] = v61;
LABEL_7:
            v5[2] += (int)&v8[-*v5];
            *v5 = (int)v8;
            a1[13] = (int)v62;
            return sub_630230(v59);
          }
          v60 >>= 14;
          v4 -= 14;
          a1[2] = 0;
          *a1 = 4;
          v12 = v60;
LABEL_55:
          if ( a1[2] < ((unsigned int)a1[1] >> 10) + 4 )
          {
            while ( v4 >= 3 )
            {
LABEL_59:
              *(_DWORD *)(a1[3] + 4 * dword_72FD40[a1[2]++]) = v12 & 7;
              v12 = v60 >> 3;
              v4 -= 3;
              v60 >>= 3;
              if ( a1[2] >= ((unsigned int)a1[1] >> 10) + 4 )
                goto LABEL_60;
            }
            while ( v61 )
            {
              --v61;
              v29 = *v8 << v4;
              v4 += 8;
              a3 = 0;
              v12 |= v29;
              ++v8;
              v60 = v12;
              if ( v4 >= 3 )
                goto LABEL_59;
            }
            goto LABEL_107;
          }
LABEL_60:
          if ( (unsigned int)a1[2] < 0x13 )
          {
            do
            {
              *(_DWORD *)(a1[3] + 4 * dword_72FD40[a1[2]]) = 0;
              v30 = a1[2] + 1;
              a1[2] = v30;
            }
            while ( v30 < 0x13 );
          }
          v57 = a1[9];
          a1[4] = 7;
          v64 = sub_630000(a1 + 5, v57, v5);
          if ( v64 )
          {
            ((void (__fastcall *)(int, int))v5[9])(v5[10], a1[3]);
            if ( v64 == -3 )
              *a1 = 9;
            a1[8] = v60;
            a1[7] = v4;
            v5[1] = v61;
            v59 = v64;
            goto LABEL_7;
          }
          a1[2] = 0;
          v12 = v60;
          *a1 = 5;
LABEL_64:
          if ( a1[2] < (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
          {
            while ( 1 )
            {
              v31 = a1[4];
              if ( v4 < v31 )
                break;
LABEL_70:
              v33 = a1[5] + 8 * (v12 & dword_9127F0[v31]);
              v34 = *(unsigned __int8 *)(v33 + 1);
              v35 = *(_DWORD *)(v33 + 4);
              v72 = v35;
              if ( v35 >= 0x10 )
              {
                if ( v35 == 18 )
                  v67 = 7;
                else
                  v67 = v35 - 14;
                v66 = 8 * (v35 == 18) + 3;
                v71 = v67 + v34;
                if ( v4 < v67 + v34 )
                {
                  while ( v61 )
                  {
                    --v61;
                    v36 = *v8 << v4;
                    v4 += 8;
                    a3 = 0;
                    v12 |= v36;
                    ++v8;
                    v60 = v12;
                    if ( v4 >= v71 )
                      goto LABEL_78;
                  }
                  goto LABEL_107;
                }
LABEL_78:
                v37 = v12 >> v34;
                v66 += v37 & dword_9127F0[v67];
                v60 = v37 >> v67;
                v4 -= v34 + v67;
                v38 = a1[2];
                if ( v38 + v66 > (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
                  goto LABEL_108;
                if ( v72 == 16 )
                {
                  if ( !v38 )
                  {
LABEL_108:
                    ((void (__fastcall *)(int, int))v5[9])(v5[10], a1[3]);
                    *a1 = 9;
                    v5[6] = (int)"invalid bit length repeat";
                    goto LABEL_109;
                  }
                  v39 = *(_DWORD *)(a1[3] + 4 * v38 - 4);
                }
                else
                {
                  v39 = 0;
                }
                do
                {
                  *(_DWORD *)(a1[3] + 4 * v38++) = v39;
                  --v66;
                }
                while ( v66 );
                a1[2] = v38;
              }
              else
              {
                v4 -= v34;
                v60 = v12 >> v34;
                *(_DWORD *)(a1[3] + 4 * a1[2]++) = v35;
              }
              if ( a1[2] >= (((unsigned int)a1[1] >> 5) & 0x1F) + (a1[1] & 0x1F) + 258 )
                goto LABEL_86;
              v12 = v60;
            }
            while ( v61 )
            {
              --v61;
              v32 = *v8 << v4;
              v31 = a1[4];
              v4 += 8;
              a3 = 0;
              v12 |= v32;
              ++v8;
              v60 = v12;
              if ( v4 >= v31 )
                goto LABEL_70;
            }
LABEL_107:
            a1[8] = v60;
            a1[7] = v4;
            v5[2] += (int)&v8[-*v5];
            v5[1] = 0;
            *v5 = (int)v8;
            a1[13] = (int)v62;
            return sub_630230(a3);
          }
LABEL_86:
          v58 = a1[9];
          v56 = a1[3];
          a1[5] = 0;
          v66 = 9;
          v67 = 6;
          v65 = sub_6300A0(v56, &v66, &v67, &v74, &v73, v58, v5);
          ((void (__fastcall *)(int, int))v5[9])(v5[10], a1[3]);
          if ( v65 )
          {
            if ( v65 == -3 )
              *a1 = 9;
            a1[8] = v60;
            a1[7] = v4;
            v51 = (unsigned __int8 *)v5[2];
            v5[1] = v61;
            v5[2] = (int)&v8[(_DWORD)v51 - *v5];
            *v5 = (int)v8;
            a1[13] = (int)v62;
            return sub_630230(v65);
          }
          else
          {
            v40 = sub_62F3D0(v74, v73, v5);
            if ( v40 )
            {
              a1[1] = v40;
              *a1 = 6;
LABEL_89:
              a1[8] = v60;
              a1[7] = v4;
              v41 = (unsigned __int8 *)v5[2];
              v5[1] = v61;
              v5[2] = (int)&v8[(_DWORD)v41 - *v5];
              *v5 = (int)v8;
              a1[13] = (int)v62;
              v42 = sub_62F410(a3);
              if ( v42 == 1 )
              {
                a3 = 0;
                sub_62FB00(a1[1], v5);
                v43 = a1[12];
                v8 = (unsigned __int8 *)*v5;
                v44 = a1[8];
                v4 = a1[7];
                v61 = v5[1];
                v45 = (char *)a1[13];
                v66 = *v5;
                v60 = v44;
                v62 = v45;
                if ( (unsigned int)v45 >= v43 )
                  v46 = a1[11] - (_DWORD)v45;
                else
                  v46 = v43 - (_DWORD)v45 - 1;
                v63 = v46;
                if ( !a1[6] )
                {
                  *a1 = 0;
                  goto LABEL_95;
                }
                *a1 = 7;
LABEL_116:
                a1[13] = (int)v62;
                v53 = sub_630230(a3);
                v62 = (char *)a1[13];
                if ( (char *)a1[12] != v62 )
                {
                  a1[8] = v60;
                  a1[7] = v4;
                  v5[1] = v61;
                  v59 = v53;
                  goto LABEL_7;
                }
                *a1 = 8;
LABEL_119:
                a1[8] = v60;
                a1[7] = v4;
                v54 = *v5;
                v5[1] = v61;
                v5[2] += (int)&v8[-v54];
                *v5 = (int)v8;
                a1[13] = (int)v62;
                return sub_630230(1);
              }
              else
              {
                return sub_630230(v42);
              }
            }
            else
            {
              a1[8] = v60;
              a1[7] = v4;
              v52 = *v5;
              v5[1] = v61;
              v5[2] += (int)&v8[-v52];
              *v5 = (int)v8;
              a1[13] = (int)v62;
              return sub_630230(-4);
            }
          }
        }
      case 4:
        goto LABEL_55;
      case 5:
        goto LABEL_64;
      case 6:
        goto LABEL_89;
      case 7:
        goto LABEL_116;
      case 8:
        goto LABEL_119;
      case 9:
        a1[8] = v60;
        a1[7] = v4;
        v55 = (unsigned __int8 *)v5[2];
        v5[1] = v61;
        v5[2] = (int)&v8[(_DWORD)v55 - *v5];
        *v5 = (int)v8;
        a1[13] = (int)v62;
        return sub_630230(-3);
      default:
        goto LABEL_5;
    }
  }
}
