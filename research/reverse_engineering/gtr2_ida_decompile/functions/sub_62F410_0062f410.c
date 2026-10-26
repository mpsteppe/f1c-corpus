int __fastcall sub_62F410(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v4; // ecx
  unsigned int v5; // ebx
  unsigned __int8 *v7; // ebp
  unsigned int v8; // eax
  _BYTE *v9; // edx
  unsigned int v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // ebx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  int v26; // ecx
  unsigned int v27; // eax
  int v28; // eax
  int v29; // ecx
  unsigned int v30; // eax
  _DWORD *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // ecx
  bool v37; // zf
  unsigned int v38; // eax
  unsigned int v39; // ecx
  int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  unsigned __int8 *v43; // ecx
  int v45; // ebx
  unsigned __int8 *v46; // ebx
  int v47; // eax
  unsigned __int8 *v48; // ebx
  unsigned __int8 *v49; // ebx
  int v50; // [esp-4h] [ebp-30h]
  unsigned int v51; // [esp+10h] [ebp-1Ch]
  _DWORD *v52; // [esp+14h] [ebp-18h]
  unsigned int v53; // [esp+18h] [ebp-14h]
  unsigned int v54; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *v55; // [esp+20h] [ebp-Ch]
  unsigned int v56; // [esp+20h] [ebp-Ch]
  unsigned int v57; // [esp+20h] [ebp-Ch]
  unsigned int v58; // [esp+20h] [ebp-Ch]
  _BYTE *v59; // [esp+24h] [ebp-8h]
  unsigned int v60; // [esp+28h] [ebp-4h]
  unsigned int v61; // [esp+28h] [ebp-4h]
  int v62; // [esp+30h] [ebp+4h]

  v4 = (_DWORD *)a1[1];
  v5 = a1[7];
  v7 = *a2;
  v53 = (unsigned int)a2[1];
  v8 = a1[12];
  v51 = a1[8];
  v9 = (_BYTE *)a1[13];
  v52 = v4;
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
  v11 = *v4;
  v54 = v10;
  while ( 1 )
  {
    switch ( v11 )
    {
      case 0:
        if ( v10 >= 0x102 && v53 >= 0xA )
        {
          a1[8] = v51;
          a1[7] = v5;
          v12 = *a2;
          a2[1] = (unsigned __int8 *)v53;
          a2[2] += v7 - v12;
          *a2 = v7;
          a1[13] = v9;
          v13 = sub_630370(*(_DWORD *)((char *)v52 + 18), *(_DWORD *)((char *)v52 + 22), a1, a2);
          v7 = *a2;
          v5 = a1[7];
          v53 = (unsigned int)a2[1];
          v14 = a1[12];
          v51 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v54 = v15;
          if ( v13 )
          {
            *v52 = 2 * (v13 != 1) + 7;
            v10 = v15;
            break;
          }
        }
        v52[3] = *((unsigned __int8 *)v52 + 16);
        v52[2] = *(_DWORD *)((char *)v52 + 18);
        *v52 = 1;
        goto LABEL_14;
      case 1:
LABEL_14:
        v16 = v52[3];
        if ( v5 >= v16 )
          goto LABEL_17;
        do
        {
          if ( !v53 )
            goto LABEL_89;
          --v53;
          v17 = *v7 << v5;
          v5 += 8;
          a3 = 0;
          v18 = v17 | v51;
          v16 = v52[3];
          ++v7;
          v51 = v18;
        }
        while ( v5 < v16 );
LABEL_17:
        v55 = (unsigned __int8 *)(v52[2] + 8 * (v51 & dword_9127F0[v16]));
        v51 >>= v55[1];
        v5 -= v55[1];
        v19 = *v55;
        if ( !*v55 )
        {
          v52[2] = *((_DWORD *)v55 + 1);
          *v52 = 6;
          v10 = v54;
          break;
        }
        if ( (v19 & 0x10) != 0 )
        {
          v52[2] = v19 & 0xF;
          v52[1] = *((_DWORD *)v55 + 1);
          v10 = v54;
          *v52 = 2;
          break;
        }
        if ( (v19 & 0x40) == 0 )
          goto LABEL_35;
        if ( (v19 & 0x20) == 0 )
        {
          *v52 = 9;
          a2[6] = "invalid literal/length code";
          v50 = -3;
          goto LABEL_84;
        }
        *v52 = 7;
        v10 = v54;
        break;
      case 2:
        v20 = v52[2];
        v56 = v20;
        if ( v5 >= v20 )
          goto LABEL_27;
        do
        {
          if ( !v53 )
            goto LABEL_89;
          --v53;
          v21 = *v7 << v5;
          v5 += 8;
          a3 = 0;
          v22 = v21 | v51;
          v20 = v52[2];
          ++v7;
          v51 = v22;
        }
        while ( v5 < v56 );
LABEL_27:
        v52[1] += v51 & dword_9127F0[v20];
        v51 >>= v56;
        v5 -= v56;
        v23 = v52;
        v52[3] = *((unsigned __int8 *)v52 + 17);
        v52[2] = *(_DWORD *)((char *)v52 + 22);
        *v52 = 3;
LABEL_29:
        v24 = v23[3];
        v57 = v24;
        if ( v5 < v24 )
        {
          while ( v53 )
          {
            --v53;
            v25 = *v7 << v5;
            v5 += 8;
            a3 = 0;
            v26 = v25 | v51;
            v24 = v57;
            ++v7;
            v51 = v26;
            if ( v5 >= v57 )
              goto LABEL_32;
          }
LABEL_89:
          a1[7] = v5;
          a1[8] = v51;
          v45 = (int)&a2[2][v7 - *a2];
          a2[1] = 0;
          a2[2] = (unsigned __int8 *)v45;
          *a2 = v7;
          a1[13] = v9;
          return sub_630230(a3);
        }
LABEL_32:
        v55 = (unsigned __int8 *)(v52[2] + 8 * (v51 & dword_9127F0[v24]));
        v51 >>= v55[1];
        v19 = *v55;
        v5 -= v55[1];
        if ( (v19 & 0x10) != 0 )
        {
          v52[2] = v19 & 0xF;
          v52[3] = *((_DWORD *)v55 + 1);
          v10 = v54;
          *v52 = 4;
        }
        else
        {
          if ( (v19 & 0x40) != 0 )
          {
            *v52 = 9;
            a2[6] = "invalid distance code";
            v50 = -3;
LABEL_84:
            a1[8] = v51;
            a1[7] = v5;
            a2[1] = (unsigned __int8 *)v53;
            v43 = (unsigned __int8 *)(v7 - *a2);
LABEL_85:
            a2[2] = &a2[2][(_DWORD)v43];
            goto LABEL_86;
          }
LABEL_35:
          v52[3] = v19;
          v52[2] = &v55[8 * *((_DWORD *)v55 + 1)];
          v10 = v54;
        }
        break;
      case 3:
        v23 = v52;
        goto LABEL_29;
      case 4:
        v27 = v52[2];
        v58 = v27;
        if ( v5 >= v27 )
          goto LABEL_39;
        do
        {
          if ( !v53 )
            goto LABEL_89;
          --v53;
          v28 = *v7 << v5;
          v5 += 8;
          a3 = 0;
          v29 = v28 | v51;
          v27 = v52[2];
          ++v7;
          v51 = v29;
        }
        while ( v5 < v58 );
LABEL_39:
        v52[3] += v51 & dword_9127F0[v27];
        v51 >>= v58;
        v5 -= v58;
        *v52 = 5;
LABEL_40:
        v30 = v52[3];
        if ( (unsigned int)&v9[-a1[10]] >= v30 )
          v59 = &v9[-v30];
        else
          v59 = &v9[a1[11] - a1[10] - v52[3]];
        v31 = v52;
        v10 = v54;
        if ( !v52[1] )
        {
LABEL_81:
          *v31 = 0;
          break;
        }
        while ( 1 )
        {
          if ( !v10 )
          {
            if ( v9 != (_BYTE *)a1[11]
              || (v32 = a1[12], v33 = a1[10], v32 == v33)
              || ((v9 = (_BYTE *)a1[10], v33 >= v32) ? (v10 = a1[11] - v33) : (v10 = v32 - v33 - 1), !v10) )
            {
              a1[13] = v9;
              v34 = sub_630230(a3);
              v9 = (_BYTE *)a1[13];
              v62 = v34;
              v35 = a1[12];
              v60 = v35;
              if ( (unsigned int)v9 >= v35 )
                v10 = a1[11] - (_DWORD)v9;
              else
                v10 = v35 - (_DWORD)v9 - 1;
              if ( v9 == (_BYTE *)a1[11] )
              {
                v36 = a1[10];
                if ( v60 != v36 )
                {
                  v9 = (_BYTE *)a1[10];
                  if ( v36 >= v60 )
                    v10 = a1[11] - v36;
                  else
                    v10 = v60 - v36 - 1;
                }
              }
              if ( !v10 )
                break;
            }
          }
          *v9++ = *v59;
          --v10;
          v37 = v59 + 1 == (_BYTE *)a1[11];
          a3 = 0;
          ++v59;
          v54 = v10;
          if ( v37 )
            v59 = (_BYTE *)a1[10];
          v31 = v52;
          if ( !--v52[1] )
            goto LABEL_81;
        }
LABEL_90:
        a1[8] = v51;
        a1[7] = v5;
        v46 = *a2;
        a2[1] = (unsigned __int8 *)v53;
        a2[2] += v7 - v46;
        v50 = v62;
LABEL_86:
        *a2 = v7;
        a1[13] = v9;
        return sub_630230(v50);
      case 5:
        goto LABEL_40;
      case 6:
        if ( !v10 )
        {
          if ( v9 != (_BYTE *)a1[11]
            || (v38 = a1[12], v39 = a1[10], v38 == v39)
            || ((v9 = (_BYTE *)a1[10], v39 >= v38) ? (v10 = a1[11] - v39) : (v10 = v38 - v39 - 1), !v10) )
          {
            a1[13] = v9;
            v40 = sub_630230(a3);
            v9 = (_BYTE *)a1[13];
            v62 = v40;
            v41 = a1[12];
            v61 = v41;
            if ( (unsigned int)v9 >= v41 )
              v10 = a1[11] - (_DWORD)v9;
            else
              v10 = v41 - (_DWORD)v9 - 1;
            if ( v9 == (_BYTE *)a1[11] )
            {
              v42 = a1[10];
              if ( v61 != v42 )
              {
                v9 = (_BYTE *)a1[10];
                if ( v42 >= v61 )
                  v10 = a1[11] - v42;
                else
                  v10 = v61 - v42 - 1;
              }
            }
            if ( !v10 )
              goto LABEL_90;
          }
        }
        *v9 = *((_BYTE *)v52 + 8);
        v31 = v52;
        ++v9;
        --v10;
        a3 = 0;
        v54 = v10;
        goto LABEL_81;
      case 7:
        if ( v5 > 7 )
        {
          v5 -= 8;
          ++v53;
          --v7;
        }
        a1[13] = v9;
        v47 = sub_630230(a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[8] = v51;
          a1[7] = v5;
          v48 = *a2;
          a2[1] = (unsigned __int8 *)v53;
          v43 = (unsigned __int8 *)(v7 - v48);
          v50 = v47;
          goto LABEL_85;
        }
        *v52 = 8;
LABEL_96:
        v50 = 1;
        goto LABEL_84;
      case 8:
        goto LABEL_96;
      case 9:
        a1[8] = v51;
        a1[7] = v5;
        v49 = *a2;
        a2[1] = (unsigned __int8 *)v53;
        a2[2] += v7 - v49;
        v50 = -3;
        goto LABEL_86;
      default:
        goto LABEL_83;
    }
    v11 = *v52;
    if ( *v52 > 9u )
    {
LABEL_83:
      v50 = -2;
      goto LABEL_84;
    }
  }
}
