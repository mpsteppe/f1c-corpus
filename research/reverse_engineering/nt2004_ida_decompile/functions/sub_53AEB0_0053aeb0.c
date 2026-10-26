int __fastcall sub_53AEB0(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  _BYTE *v9; // edx
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  bool v16; // zf
  int v17; // ecx
  unsigned int v18; // eax
  char v19; // cl
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  char v25; // cl
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // cl
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // eax
  char v34; // cl
  int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // ebx
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v57; // ebx
  int v58; // eax
  unsigned __int8 *v59; // ebx
  unsigned __int8 *v60; // ecx
  unsigned __int8 *v61; // ebx
  int v62; // [esp-4h] [ebp-2Ch]
  unsigned int v63; // [esp+10h] [ebp-18h]
  int v64; // [esp+14h] [ebp-14h]
  unsigned int v65; // [esp+18h] [ebp-10h]
  unsigned int v66; // [esp+1Ch] [ebp-Ch]
  unsigned int v67; // [esp+20h] [ebp-8h]
  unsigned __int8 *v68; // [esp+20h] [ebp-8h]
  unsigned int v69; // [esp+20h] [ebp-8h]
  unsigned int v70; // [esp+20h] [ebp-8h]
  unsigned int v71; // [esp+20h] [ebp-8h]
  _BYTE *v72; // [esp+24h] [ebp-4h]
  int v73; // [esp+2Ch] [ebp+4h]

  v5 = (_DWORD *)a1[1];
  v6 = *a2;
  v7 = a1[7];
  v65 = (unsigned int)a2[1];
  v8 = a1[12];
  v63 = a1[8];
  v9 = (_BYTE *)a1[13];
  v64 = a1[1];
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
LABEL_4:
  v66 = v10;
  while ( 2 )
  {
    switch ( *v5 )
    {
      case 0:
        if ( v66 >= 0x102 && v65 >= 0xA )
        {
          a1[8] = v63;
          a1[7] = v7;
          v11 = *a2;
          a2[1] = (unsigned __int8 *)v65;
          v12 = a2[2];
          *a2 = v6;
          a2[2] = &v12[v6 - v11];
          a1[13] = v9;
          v13 = sub_53BDF0(*(_DWORD *)(v64 + 18), *(_DWORD *)(v64 + 22), a1, a2);
          v6 = *a2;
          v7 = a1[7];
          v65 = (unsigned int)a2[1];
          v14 = a1[12];
          v63 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v66 = v15;
          if ( v13 )
          {
            v16 = v13 == 1;
            v5 = (_DWORD *)v64;
            *(_DWORD *)v64 = 2 * !v16 + 7;
            continue;
          }
        }
        v5 = (_DWORD *)v64;
        v17 = *(unsigned __int8 *)(v64 + 16);
        *(_DWORD *)v64 = 1;
        *(_DWORD *)(v64 + 12) = v17;
        *(_DWORD *)(v64 + 8) = *(_DWORD *)(v64 + 18);
        goto LABEL_14;
      case 1:
LABEL_14:
        v18 = v5[3];
        v67 = v18;
        if ( v7 >= v18 )
          goto LABEL_17;
        do
        {
          if ( !v65 )
            goto LABEL_86;
          v19 = v7;
          --v65;
          v7 += 8;
          a3 = 0;
          v20 = (*v6 << v19) | v63;
          v18 = v67;
          ++v6;
          v63 = v20;
        }
        while ( v7 < v67 );
LABEL_17:
        v68 = (unsigned __int8 *)(*(_DWORD *)(v64 + 8) + 8 * (v63 & dword_616D90[v18]));
        v21 = v68[1];
        v63 >>= v21;
        v7 -= v21;
        v22 = *v68;
        if ( *v68 )
        {
          if ( (v22 & 0x10) != 0 )
          {
            v5 = (_DWORD *)v64;
            *(_DWORD *)(v64 + 8) = v22 & 0xF;
            v23 = *((_DWORD *)v68 + 1);
            *(_DWORD *)v64 = 2;
            *(_DWORD *)(v64 + 4) = v23;
          }
          else
          {
            if ( (v22 & 0x40) == 0 )
              goto LABEL_22;
            v5 = (_DWORD *)v64;
            if ( (v22 & 0x20) == 0 )
            {
              *(_DWORD *)v64 = 9;
              a2[6] = (unsigned __int8 *)aInvalidLiteral;
              v62 = -3;
              goto LABEL_96;
            }
            *(_DWORD *)v64 = 7;
          }
        }
        else
        {
          v5 = (_DWORD *)v64;
          *(_DWORD *)(v64 + 8) = *((_DWORD *)v68 + 1);
          *(_DWORD *)v64 = 6;
        }
        continue;
      case 2:
        v24 = v5[2];
        v69 = v24;
        if ( v7 >= v24 )
          goto LABEL_28;
        do
        {
          if ( !v65 )
            goto LABEL_86;
          v25 = v7;
          --v65;
          v7 += 8;
          a3 = 0;
          v26 = (*v6 << v25) | v63;
          v24 = v69;
          ++v6;
          v63 = v26;
        }
        while ( v7 < v69 );
LABEL_28:
        *(_DWORD *)(v64 + 4) += v63 & dword_616D90[v24];
        v63 >>= v69;
        v7 -= v69;
        v5 = (_DWORD *)v64;
        v27 = *(unsigned __int8 *)(v64 + 17);
        *(_DWORD *)v64 = 3;
        *(_DWORD *)(v64 + 12) = v27;
        *(_DWORD *)(v64 + 8) = *(_DWORD *)(v64 + 22);
LABEL_29:
        v28 = v5[3];
        v70 = v28;
        if ( v7 >= v28 )
        {
LABEL_32:
          v68 = (unsigned __int8 *)(*(_DWORD *)(v64 + 8) + 8 * (v63 & dword_616D90[v28]));
          v31 = v68[1];
          v7 -= v31;
          v63 >>= v31;
          v22 = *v68;
          if ( (v22 & 0x10) != 0 )
          {
            v5 = (_DWORD *)v64;
            *(_DWORD *)(v64 + 8) = v22 & 0xF;
            v32 = *((_DWORD *)v68 + 1);
            *(_DWORD *)v64 = 4;
            *(_DWORD *)(v64 + 12) = v32;
          }
          else
          {
            if ( (v22 & 0x40) != 0 )
            {
              v62 = -3;
              *(_DWORD *)v64 = 9;
              a2[6] = (unsigned __int8 *)aInvalidDistanc;
LABEL_96:
              a1[7] = v7;
              a1[8] = v63;
              a2[1] = (unsigned __int8 *)v65;
              v60 = (unsigned __int8 *)(v6 - *a2);
LABEL_97:
              a2[2] = &a2[2][(_DWORD)v60];
LABEL_98:
              *a2 = v6;
              a1[13] = v9;
              return sub_53BCA0(v62);
            }
LABEL_22:
            *(_DWORD *)(v64 + 12) = v22;
            v5 = (_DWORD *)v64;
            *(_DWORD *)(v64 + 8) = &v68[8 * *((_DWORD *)v68 + 1)];
          }
          continue;
        }
        while ( v65 )
        {
          v29 = v7;
          --v65;
          v7 += 8;
          a3 = 0;
          v30 = (*v6 << v29) | v63;
          v28 = v70;
          ++v6;
          v63 = v30;
          if ( v7 >= v70 )
            goto LABEL_32;
        }
LABEL_86:
        a1[7] = v7;
        a1[8] = v63;
        v54 = a2[2];
        v55 = (unsigned __int8 *)(v6 - *a2);
        a2[1] = 0;
        *a2 = v6;
        a2[2] = &v54[(_DWORD)v55];
        a1[13] = v9;
        return sub_53BCA0(a3);
      case 3:
        goto LABEL_29;
      case 4:
        v33 = v5[2];
        v71 = v33;
        if ( v7 >= v33 )
          goto LABEL_39;
        do
        {
          if ( !v65 )
            goto LABEL_86;
          v34 = v7;
          --v65;
          v7 += 8;
          a3 = 0;
          v35 = (*v6 << v34) | v63;
          v33 = v71;
          ++v6;
          v63 = v35;
        }
        while ( v7 < v71 );
LABEL_39:
        *(_DWORD *)(v64 + 12) += v63 & dword_616D90[v33];
        v63 >>= v71;
        v7 -= v71;
        *(_DWORD *)v64 = 5;
LABEL_40:
        v36 = *(_DWORD *)(v64 + 12);
        if ( (unsigned int)&v9[-a1[10]] >= v36 )
          v72 = &v9[-v36];
        else
          v72 = &v9[a1[11] - a1[10] - *(_DWORD *)(v64 + 12)];
        v5 = (_DWORD *)v64;
        if ( *(_DWORD *)(v64 + 4) )
        {
          do
          {
            if ( !v66 )
            {
              if ( v9 != (_BYTE *)a1[11]
                || (v37 = a1[12], v38 = a1[10], v37 == v38)
                || ((v9 = (_BYTE *)a1[10], v38 >= v37) ? (v39 = a1[11] - v38) : (v39 = v37 - v38 - 1), (v66 = v39) == 0) )
              {
                a1[13] = v9;
                v40 = sub_53BCA0(a3);
                v9 = (_BYTE *)a1[13];
                v73 = v40;
                v41 = a1[12];
                if ( (unsigned int)v9 >= v41 )
                  v42 = a1[11] - (_DWORD)v9;
                else
                  v42 = v41 - (_DWORD)v9 - 1;
                v66 = v42;
                if ( v9 == (_BYTE *)a1[11] )
                {
                  v43 = a1[10];
                  if ( v41 != v43 )
                  {
                    v9 = (_BYTE *)a1[10];
                    if ( v43 >= v41 )
                      v44 = a1[11] - v43;
                    else
                      v44 = v41 - v43 - 1;
                    v66 = v44;
                  }
                }
                if ( !v66 )
                {
LABEL_87:
                  a1[8] = v63;
                  a1[7] = v7;
                  v57 = *a2;
                  a2[1] = (unsigned __int8 *)v65;
                  a2[2] += v6 - v57;
                  v62 = v73;
                  goto LABEL_98;
                }
              }
              v5 = (_DWORD *)v64;
            }
            ++v9;
            a3 = 0;
            *(v9 - 1) = *v72++;
            --v66;
            if ( v72 == (_BYTE *)a1[11] )
              v72 = (_BYTE *)a1[10];
            v45 = v5[1] - 1;
            v5[1] = v45;
          }
          while ( v45 );
        }
        *v5 = 0;
        continue;
      case 5:
        goto LABEL_40;
      case 6:
        if ( v66 )
          goto LABEL_84;
        if ( v9 != (_BYTE *)a1[11]
          || (v46 = a1[12], v47 = a1[10], v46 == v47)
          || ((v9 = (_BYTE *)a1[10], v47 >= v46) ? (v48 = a1[11] - v47) : (v48 = v46 - v47 - 1), (v66 = v48) == 0) )
        {
          a1[13] = v9;
          v49 = sub_53BCA0(a3);
          v9 = (_BYTE *)a1[13];
          v73 = v49;
          v50 = a1[12];
          if ( (unsigned int)v9 >= v50 )
            v51 = a1[11] - (_DWORD)v9;
          else
            v51 = v50 - (_DWORD)v9 - 1;
          v66 = v51;
          if ( v9 == (_BYTE *)a1[11] )
          {
            v52 = a1[10];
            if ( v50 != v52 )
            {
              v9 = (_BYTE *)a1[10];
              if ( v52 >= v50 )
                v53 = a1[11] - v52;
              else
                v53 = v50 - v52 - 1;
              v66 = v53;
            }
          }
          if ( !v66 )
            goto LABEL_87;
        }
        v5 = (_DWORD *)v64;
LABEL_84:
        a3 = 0;
        *v9++ = *((_BYTE *)v5 + 8);
        v10 = v66 - 1;
        *v5 = 0;
        goto LABEL_4;
      case 7:
        if ( v7 > 7 )
        {
          v7 -= 8;
          --v6;
          ++v65;
        }
        a1[13] = v9;
        v58 = sub_53BCA0(a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[7] = v7;
          a1[8] = v63;
          v59 = *a2;
          a2[1] = (unsigned __int8 *)v65;
          v62 = v58;
          v60 = (unsigned __int8 *)(v6 - v59);
          goto LABEL_97;
        }
        *(_DWORD *)v64 = 8;
LABEL_93:
        v62 = 1;
        goto LABEL_96;
      case 8:
        goto LABEL_93;
      case 9:
        a1[8] = v63;
        a1[7] = v7;
        v61 = *a2;
        a2[1] = (unsigned __int8 *)v65;
        v62 = -3;
        a2[2] += v6 - v61;
        goto LABEL_98;
      default:
        v62 = -2;
        goto LABEL_96;
    }
  }
}
