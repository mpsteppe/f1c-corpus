_DWORD *__thiscall sub_48A940(int *this, int *a2, int a3)
{
  int v4; // esi
  int v5; // ebp
  int v6; // eax
  _DWORD **v7; // ecx
  _DWORD *v8; // edi
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  _DWORD **v14; // eax
  int v15; // eax
  int *v16; // esi
  _DWORD *result; // eax
  int v18; // eax
  double v19; // st7
  unsigned int i; // eax
  int v21; // ecx
  bool v22; // zf
  int v23; // edx
  float **v24; // ecx
  float *v25; // ecx
  float *v26; // edx
  float v27; // esi
  int v28; // eax
  double v29; // st7
  double v30; // st6
  double v31; // st5
  int v32; // ecx
  int v33; // eax
  float **v34; // eax
  int *v35; // esi
  int v36; // eax
  int v37; // ecx
  int j; // edx
  int *v39; // ecx
  int v40; // eax
  int v41; // edx
  int v42; // ecx
  int v43; // eax
  int *v44; // eax
  int *v45; // ecx
  int v46; // eax
  int v47; // edi
  _DWORD *v48; // eax
  _DWORD *v49; // esi
  _DWORD *v50; // eax
  int v51; // ecx
  int v52; // eax
  int *v53; // eax
  int *v54; // eax
  int *v55; // edx
  int *k; // ecx
  int v57; // eax
  int ****v58; // ecx
  int ***v59; // ebp
  int **v60; // esi
  int v61; // ecx
  int v62; // eax
  int ****v63; // eax
  int **v64; // esi
  int **v65; // eax
  char *v66; // edi
  char ***v67; // esi
  char **v68; // eax
  _DWORD *v69; // edi
  _DWORD *v70; // esi
  _DWORD *v71; // esi
  _DWORD *v72; // eax
  int v73; // ecx
  int v74; // eax
  int ****v75; // eax
  _DWORD **v76; // eax
  int v77; // edi
  _DWORD *v78; // esi
  _DWORD *v79; // eax
  int v80; // [esp+4h] [ebp-54h]
  int v81; // [esp+Ch] [ebp-4Ch]
  float v82; // [esp+10h] [ebp-48h]
  int v83; // [esp+14h] [ebp-44h] BYREF
  int *v84; // [esp+18h] [ebp-40h] BYREF
  int v85; // [esp+1Ch] [ebp-3Ch] BYREF
  float v86; // [esp+20h] [ebp-38h]
  int *v87; // [esp+24h] [ebp-34h] BYREF
  int *v88; // [esp+28h] [ebp-30h] BYREF
  float v89; // [esp+2Ch] [ebp-2Ch]
  float v90; // [esp+30h] [ebp-28h]
  float v91; // [esp+34h] [ebp-24h]
  int *v92; // [esp+38h] [ebp-20h] BYREF
  int *v93; // [esp+3Ch] [ebp-1Ch]
  int *v94; // [esp+40h] [ebp-18h]
  int v95; // [esp+44h] [ebp-14h]
  int v96; // [esp+50h] [ebp-8h]
  int *retaddr; // [esp+58h] [ebp+0h] BYREF

  sub_525140(*this + 1012);
  v4 = *this;
  v85 = sub_489E40();
  v86 = (float)v85;
  v5 = (unsigned __int64)(*(float *)(v4 + 108) * *(float *)(v4 + 104) * v86);
  v4 += 148;
  v81 = v5;
  v83 = a3;
  sub_489DD0((_DWORD *)v4, &v84, &v83);
  if ( v84 != *(int **)(v4 + 4) )
  {
    v6 = v84[4];
    v5 += *(unsigned __int16 *)(v6 + 876);
    v81 = v5;
    *(_WORD *)(v6 + 876) = 0;
  }
  v7 = *(_DWORD ***)(*this + 116);
  *(_DWORD *)(*this + 124) = v7;
  if ( v7 )
  {
    v8 = *v7;
    if ( *v7 )
    {
      do
      {
        if ( (int *)v8[211] != a2 )
        {
          v9 = (_DWORD *)(*this + 1012);
          v10 = operator new(0xCu);
          if ( v10 )
          {
            *v10 = v8;
            v10[1] = 0;
            *((_BYTE *)v10 + 8) = 0;
          }
          else
          {
            v10 = 0;
          }
          if ( *v9 )
          {
            *(_DWORD *)(v9[1] + 4) = v10;
          }
          else
          {
            *v9 = v10;
            v9[2] = v10;
          }
          v11 = v9[3] + 1;
          v9[1] = v10;
          v9[3] = v11;
          v5 += -8 - ((*v8 >> 8) & 0x3FF);
        }
        v12 = *(_DWORD *)(*this + 124);
        v13 = *this + 116;
        if ( v12 )
          *(_DWORD *)(*this + 124) = *(_DWORD *)(v12 + 4);
        v14 = *(_DWORD ***)(v13 + 8);
        if ( !v14 )
          break;
        v8 = *v14;
      }
      while ( *v14 );
      v81 = v5;
    }
  }
  if ( v85 > 1487 )
  {
    if ( v85 > 2975 )
    {
      if ( v85 > 7200 )
        v15 = (v85 > 28800) + 3;
      else
        v15 = 2;
    }
    else
    {
      v15 = 1;
    }
  }
  else
  {
    v15 = 0;
  }
  switch ( v15 )
  {
    case 1:
      v82 = 0.125;
      break;
    case 2:
      v82 = 0.083333336;
      break;
    case 3:
      v82 = 0.0625;
      break;
    case 4:
      v82 = 0.015625;
      break;
    default:
      v82 = 0.16666667;
      break;
  }
  v16 = v84;
  result = (_DWORD *)(*this + 148);
  if ( v84 != *(int **)(*this + 152) )
  {
    v18 = v84[4];
    v19 = dbl_FB1D08 + *(float *)(v18 + 12);
    *(float *)(v18 + 12) = v19;
    if ( v19 >= v82 && v5 > 0 )
    {
      sub_489AA0((float *)v16[4], v82);
      v83 = v5 / 48;
      if ( v5 / 48 > 0 )
      {
        sub_525140(*this + 996);
        for ( i = 164; i < 0x3E4; i += 4 )
          *(_DWORD *)(i + *this) = -1;
        v21 = **(_DWORD **)(*this + 152);
        v22 = v21 == *(_DWORD *)(*this + 152);
        v85 = v21;
        if ( !v22 )
        {
          do
          {
            v23 = *(_DWORD *)(v21 + 16);
            if ( *(_BYTE *)(v23 + 16) && *(int **)(v21 + 12) != a2 && *(_DWORD *)(v23 + 21) != -23693671 )
              sub_5FDFB0(*(_DWORD *)(v23 + 880), 0);
            sub_476240(&v85);
            v21 = v85;
          }
          while ( v85 != *(_DWORD *)(*this + 152) );
        }
        v24 = *(float ***)(*this + 996);
        *(_DWORD *)(*this + 1004) = v24;
        if ( v24 )
        {
          v25 = *v24;
          if ( v25 )
          {
            v26 = (float *)((char *)&unk_924314 + 22616 * (_DWORD)retaddr);
            do
            {
              v89 = *v26;
              v27 = v26[1];
              v91 = v26[2];
              v28 = *(_DWORD *)v25;
              v29 = *(float *)(*(_DWORD *)v25 + 53);
              v90 = v27;
              v30 = *(float *)(v28 + 57) - v27;
              v31 = *(float *)(v28 + 61) - v91;
              v25[1] = v31 * v31 + v30 * v30 + (v29 - v89) * (v29 - v89);
              v32 = *(_DWORD *)(*this + 1004);
              v33 = *this + 996;
              if ( v32 )
                *(_DWORD *)(*this + 1004) = *(_DWORD *)(v32 + 4);
              v34 = *(float ***)(v33 + 8);
              if ( !v34 )
                break;
              v25 = *v34;
            }
            while ( *v34 );
          }
        }
        v35 = (int *)(*this + 996);
        v36 = sub_489BC0(*v35);
        v37 = v36;
        *v35 = v36;
        if ( v36 )
        {
          for ( j = *(_DWORD *)(v36 + 4); j; j = *(_DWORD *)(j + 4) )
            v37 = j;
        }
        v35[2] = v36;
        v35[1] = v37;
        v39 = *(int **)(*this + 996);
        *(_DWORD *)(*this + 1004) = v39;
        if ( v39 )
          v40 = *v39;
        else
          v40 = 0;
        if ( v40 )
        {
          v41 = 164;
          do
          {
            *(_DWORD *)(v41 + *this) = *(_DWORD *)(*(_DWORD *)v40 + 861);
            v42 = *(_DWORD *)(*this + 1004);
            v43 = *this + 996;
            v41 += 4;
            if ( v42 )
              *(_DWORD *)(*this + 1004) = *(_DWORD *)(v42 + 4);
            v44 = *(int **)(v43 + 8);
            if ( !v44 )
              break;
            v40 = *v44;
          }
          while ( v40 );
        }
        v92 = 0;
        v93 = 0;
        v94 = 0;
        v95 = 0;
        dword_B6D678 = *this;
        v45 = *(int **)(*this + 132);
        v46 = *this + 132;
        v96 = 0;
        *(_DWORD *)(v46 + 8) = v45;
        if ( v45 )
        {
          v47 = *v45;
          if ( *v45 )
          {
            do
            {
              if ( *(int **)(v47 + 844) != a2 )
              {
                v48 = operator new(4u);
                if ( v48 )
                {
                  *v48 = 0;
                  v49 = v48;
                }
                else
                {
                  v49 = 0;
                }
                *v49 = v47;
                v50 = operator new(0xCu);
                if ( v50 )
                {
                  *v50 = v49;
                  v50[1] = 0;
                  *((_BYTE *)v50 + 8) = 1;
                }
                else
                {
                  v50 = 0;
                }
                if ( v92 )
                {
                  v93[1] = (int)v50;
                }
                else
                {
                  v92 = v50;
                  v94 = v50;
                }
                v93 = v50;
                ++v95;
              }
              v51 = *(_DWORD *)(*this + 140);
              v52 = *this + 132;
              if ( v51 )
                *(_DWORD *)(*this + 140) = *(_DWORD *)(v51 + 4);
              v53 = *(int **)(v52 + 8);
              if ( !v53 )
                break;
              v47 = *v53;
            }
            while ( *v53 );
          }
        }
        v54 = (int *)sub_489D60((int)v92);
        v92 = v54;
        v55 = v54;
        if ( v54 )
        {
          for ( k = (int *)v54[1]; k; k = (int *)k[1] )
            v55 = k;
        }
        v94 = v54;
        v57 = v83;
        v93 = v55;
        if ( v83 > 1 )
          v57 = v83 / 2;
        v85 = v57;
        v58 = *(int *****)(*this + 996);
        *(_DWORD *)(*this + 1004) = v58;
        if ( v58 )
          v59 = *v58;
        else
          v59 = 0;
        v94 = v92;
        if ( v92 )
          v83 = *v92;
        else
          v83 = 0;
        do
        {
          if ( v59 )
          {
            while ( 1 )
            {
              v60 = *v59;
              if ( *((_BYTE *)*v59 + 16) )
              {
                retaddr = a2;
                sub_489DD0(v60, &v87, &retaddr);
                if ( v87 != v60[1] )
                {
                  LOBYTE(retaddr) = (unsigned int)(v87[4] & 0x7F) >= *(_BYTE *)(v84[4] + 878);
                  if ( (unsigned int)(v87[4] & 0x7F) >= *(_BYTE *)(v84[4] + 878) )
                    break;
                }
              }
              v61 = *(_DWORD *)(*this + 1004);
              v62 = *this + 996;
              if ( v61 )
                *(_DWORD *)(*this + 1004) = *(_DWORD *)(v61 + 4);
              v63 = *(int *****)(v62 + 8);
              if ( !v63 )
                goto LABEL_125;
              v59 = *v63;
              if ( !*v63 )
                goto LABEL_126;
            }
            v64 = *v59;
            retaddr = a2;
            sub_489DD0(*v59, &v88, &retaddr);
            if ( v88 != v64[1] )
              sub_48A250();
            v65 = *v59;
            if ( *(int **)((char *)*v59 + 861) != a2 )
            {
              if ( --v83 < 0 )
              {
                v69 = operator new(0x350u);
                v70 = (int **)((char *)*v59 + 17);
                sub_51B2A0(1, 7, 14, (unsigned __int8)*v70, *(int **)((char *)*v59 + 21), 0);
                sub_51B0B0(v70 + 2);
                v71 = (_DWORD *)(*this + 1012);
                if ( v69 )
                {
                  v72 = operator new(0xCu);
                  if ( v72 )
                  {
                    *v72 = v69;
                    v72[1] = 0;
                    *((_BYTE *)v72 + 8) = 1;
                  }
                  else
                  {
                    v72 = 0;
                  }
                  if ( *v71 )
                  {
                    *(_DWORD *)(v71[1] + 4) = v72;
                  }
                  else
                  {
                    *v71 = v72;
                    v71[2] = v72;
                  }
                  v71[1] = v72;
                  ++v71[3];
                }
                v80 += -8 - ((*v69 >> 8) & 0x3FF);
              }
              else
              {
                v66 = (char *)v65 + 17;
                v67 = (char ***)(*this + 1012);
                if ( v65 != (int **)-17 )
                {
                  v68 = (char **)operator new(0xCu);
                  if ( v68 )
                  {
                    *v68 = v66;
                    v68[1] = 0;
                    *((_BYTE *)v68 + 8) = 0;
                  }
                  else
                  {
                    v68 = 0;
                  }
                  if ( *v67 )
                  {
                    v67[1][1] = (char *)v68;
                  }
                  else
                  {
                    *v67 = v68;
                    v67[2] = v68;
                  }
                  v67[1] = v68;
                  v67[3] = (char **)((char *)v67[3] + 1);
                }
                v80 -= 48;
              }
            }
            v73 = *(_DWORD *)(*this + 1004);
            v74 = *this + 996;
            if ( v73 )
              *(_DWORD *)(*this + 1004) = *(_DWORD *)(v73 + 4);
            v75 = *(int *****)(v74 + 8);
            if ( v75 )
            {
              v59 = *v75;
              goto LABEL_126;
            }
LABEL_125:
            v59 = 0;
          }
LABEL_126:
          if ( v81 <= 0 )
            break;
          v76 = (_DWORD **)v83;
          if ( v83 )
          {
            v77 = *(_DWORD *)v83;
            v78 = (_DWORD *)(*this + 1012);
            if ( *(_DWORD *)v83 )
            {
              v79 = operator new(0xCu);
              if ( v79 )
              {
                *v79 = v77;
                v79[1] = 0;
                *((_BYTE *)v79 + 8) = 0;
              }
              else
              {
                v79 = 0;
              }
              if ( *v78 )
              {
                *(_DWORD *)(v78[1] + 4) = v79;
              }
              else
              {
                *v78 = v79;
                v78[2] = v79;
              }
              v78[1] = v79;
              ++v78[3];
              v76 = (_DWORD **)v83;
            }
            v81 += -8 - ((**v76 >> 8) & 0x3FF);
            if ( v94 && (v94 = (int *)v94[1]) != 0 )
              v83 = *v94;
            else
              v83 = 0;
          }
          else if ( !v59 )
          {
            break;
          }
        }
        while ( v81 > 0 );
        sub_525140(&v92);
        v5 = v81;
        v16 = v84;
      }
    }
    result = (_DWORD *)(*this + 1012);
    *(_DWORD *)(*this + 1020) = *result;
    if ( v5 > 0 )
    {
      result = ((unsigned __int64)(v86 * v82) & 0x80000000) != 0LL ? 0 : (_DWORD *)(unsigned __int64)(v86 * v82);
      if ( (int)result >= v5 )
        result = (_DWORD *)v5;
      *(_WORD *)(v16[4] + 876) = (_WORD)result;
    }
  }
  return result;
}
