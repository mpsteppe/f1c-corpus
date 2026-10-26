int __thiscall sub_649CC7(void *this, _BYTE *a2, int a3)
{
  _WORD *v4; // esi
  int v7; // ecx
  const char *v8; // edi
  bool v9; // zf
  unsigned int v10; // eax
  _BYTE *v11; // edi
  int v12; // eax
  int v13; // esi
  _BYTE *v14; // esi
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  int *v18; // eax
  char v19; // cl
  char *v20; // eax
  char v21; // cl
  int *v22; // edi
  char *v23; // eax
  char v24; // cl
  int v25; // eax
  _BYTE *v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  void *v31; // eax
  int v32; // edx
  int v33; // edi
  unsigned int v34; // eax
  int v35; // esi
  int v36; // eax
  int v37; // ecx
  unsigned int v38; // esi
  int v39; // ecx
  float *v40; // eax
  int v41; // edi
  double v42; // st7
  double v43; // st6
  double v44; // st5
  double v45; // st4
  int v46; // edx
  int v47; // edx
  int v48; // esi
  unsigned int v49; // ebx
  float *v50; // esi
  int v51; // edi
  int v52; // ecx
  unsigned __int8 v53; // dl
  unsigned __int8 v54; // dl
  int v55; // eax
  double v56; // st7
  float *v57; // edi
  int v58; // eax
  unsigned __int8 *v59; // edx
  float *v60; // edi
  char v61; // [esp+18h] [ebp-260h] BYREF
  char Buffer; // [esp+118h] [ebp-160h] BYREF
  char v63; // [esp+119h] [ebp-15Fh]
  char v64[254]; // [esp+11Ah] [ebp-15Eh] BYREF
  char v65[16]; // [esp+218h] [ebp-60h] BYREF
  char v66[16]; // [esp+228h] [ebp-50h] BYREF
  int v67; // [esp+238h] [ebp-40h]
  int v68; // [esp+23Ch] [ebp-3Ch]
  float v69; // [esp+240h] [ebp-38h] BYREF
  int v70; // [esp+244h] [ebp-34h]
  int v71; // [esp+248h] [ebp-30h]
  int v72; // [esp+24Ch] [ebp-2Ch]
  float v73; // [esp+250h] [ebp-28h]
  int v74; // [esp+254h] [ebp-24h]
  _BYTE *v75; // [esp+258h] [ebp-20h]
  int v76; // [esp+25Ch] [ebp-1Ch] BYREF
  int v77; // [esp+260h] [ebp-18h] BYREF
  int v78; // [esp+264h] [ebp-14h]
  int v79; // [esp+268h] [ebp-10h]
  bool v80; // [esp+26Fh] [ebp-9h]
  _BYTE *v81; // [esp+270h] [ebp-8h]
  signed int v82; // [esp+274h] [ebp-4h]
  float *v83; // [esp+280h] [ebp+8h]
  char v84; // [esp+283h] [ebp+Bh]
  int v85; // [esp+284h] [ebp+Ch]
  unsigned __int8 *v86; // [esp+284h] [ebp+Ch]
  float v87; // [esp+284h] [ebp+Ch]

  v4 = a2;
  v82 = a3;
  v81 = a2;
  if ( (unsigned int)a3 <= 0xA )
    return -2147467259;
  v7 = 5;
  v8 = "#?RADIANCE";
  v9 = 1;
  do
  {
    if ( !v7 )
      break;
    v9 = *v4++ == *(_WORD *)v8;
    v8 += 2;
    --v7;
  }
  while ( v9 );
  if ( !v9 )
    return -2147467259;
  v85 = 0;
  v73 = 1.0;
  if ( a3 <= 0 )
    return -2147467259;
  while ( *v81 != 10 )
  {
    if ( v82 > (int)strlen("FORMAT=") && !memcmp(v81, "FORMAT=", strlen("FORMAT=")) )
    {
      v81 += strlen("FORMAT=");
      v82 -= strlen("FORMAT=");
      while ( *v81 == 32 || *v81 == 9 )
      {
        if ( !--v82 )
          return -2147467259;
        ++v81;
      }
      strcpy(v66, "32-bit_rle_rgbe");
      strcpy(v65, "32-bit_rle_xyze");
      if ( v82 < 16 || memcmp(v81, v66, 0xFu) && memcmp(v81, v65, 0xFu) )
        return -2147467259;
      v81 += 16;
      v82 -= 16;
      v85 = 1;
    }
    else if ( v82 > (int)strlen("EXPOSURE=") && !memcmp(v81, "EXPOSURE=", strlen("EXPOSURE=")) )
    {
      v81 += strlen("EXPOSURE=");
      v82 -= strlen("EXPOSURE=");
      while ( *v81 == 32 || *v81 == 9 )
      {
        if ( !--v82 )
          return -2147467259;
        ++v81;
      }
      v10 = 256;
      if ( v82 < 256 )
        v10 = v82;
      v11 = v81;
      v12 = sub_646616((int)v81, v10);
      v13 = v12;
      if ( !v12 )
        return -2147467259;
      sub_649423(&Buffer, v12 + 1, v11);
      if ( sscanf(&Buffer, "%f%s", &v69, &v61) != 1 )
        return -2147467259;
      v81 = &v11[v13 + 1];
      v82 += -1 - v13;
      v73 = v69 * v73;
    }
    else
    {
      v14 = v81;
      v15 = sub_646616((int)v81, v82);
      v81 = &v14[v15 + 1];
      v82 += -1 - v15;
    }
    if ( v82 <= 0 )
      goto LABEL_36;
  }
  ++v81;
  --v82;
LABEL_36:
  if ( !v85 )
    return -2147467259;
  v16 = 256;
  if ( v82 <= 256 )
    v16 = v82;
  v17 = sub_646616((int)v81, v16);
  v79 = v17;
  if ( v17 <= 2 )
    return -2147467259;
  sub_649423(&Buffer, v17 + 1, v81);
  if ( v63 == 89 )
  {
    v84 = 1;
    v18 = &v76;
    if ( Buffer == 45 )
    {
      HIBYTE(v85) = 0;
      goto LABEL_50;
    }
    if ( Buffer == 43 )
    {
      HIBYTE(v85) = 1;
      goto LABEL_50;
    }
    return -2147467259;
  }
  if ( v63 != 88 )
    return -2147467259;
  v84 = 0;
  v18 = &v77;
  if ( Buffer == 45 )
  {
    v80 = 0;
  }
  else
  {
    if ( Buffer != 43 )
      return -2147467259;
    v80 = 1;
  }
LABEL_50:
  if ( sscanf(v64, "%u", v18) != 1 )
    return -2147467259;
  v19 = v64[0];
  v20 = v64;
  if ( !v64[0] )
    return -2147467259;
  do
  {
    if ( v19 == 45 )
      break;
    if ( v19 == 43 )
      break;
    v19 = *++v20;
  }
  while ( *v20 );
  v21 = *v20;
  if ( !*v20 )
    return -2147467259;
  if ( v84 )
  {
    v80 = v21 == 43;
    v22 = &v77;
  }
  else
  {
    HIBYTE(v85) = v21 == 43;
    v22 = &v76;
  }
  v23 = v20 + 1;
  v24 = *v23;
  if ( !*v23 || v24 != 89 && v24 != 88 )
    return -2147467259;
  if ( sscanf(v23 + 1, "%u", v22) != 1 )
    return -2147467259;
  v25 = v79;
  v26 = v81;
  v27 = v76;
  *((_DWORD *)this + 13) = 0;
  v81 = &v26[v25 + 1];
  v82 += -1 - v25;
  v28 = v77;
  *((_DWORD *)this + 3) = v77;
  v29 = v27 * v28;
  v30 = 16 * v28;
  *(_DWORD *)this = 116;
  *((_DWORD *)this + 12) = v30;
  *((_DWORD *)this + 4) = v27;
  *((_DWORD *)this + 5) = 1;
  if ( !v29 )
    return -2147467259;
  *((_DWORD *)this + 14) = 1;
  v31 = operator new(v27 * v30);
  v32 = (int)v31;
  *((_DWORD *)this + 1) = v31;
  if ( !v31 )
    return -2147024882;
  v33 = v76;
  v74 = v76;
  if ( v84 )
  {
    v78 = v77;
  }
  else
  {
    v74 = v77;
    v78 = v76;
  }
  if ( !v84 )
  {
    v38 = *((_DWORD *)this + 12);
    if ( v80 )
    {
      v36 = 4;
      if ( !HIBYTE(v85) )
      {
        v35 = v38 >> 2;
        goto LABEL_88;
      }
      v37 = v32 + v38 * (v76 - 1);
    }
    else
    {
      if ( !HIBYTE(v85) )
      {
        v37 = (int)v31 + v38 - 16;
        v36 = -4;
        goto LABEL_83;
      }
      v37 = (int)v31 + v76 * v38 - 16;
      v36 = -4;
    }
    v38 = -v38;
LABEL_83:
    v35 = v38 >> 2;
    goto LABEL_89;
  }
  v34 = *((_DWORD *)this + 12);
  if ( !v80 )
  {
    v35 = -4;
    if ( !HIBYTE(v85) )
    {
      v37 = v34 + v32 - 16;
LABEL_77:
      v36 = v34 >> 2;
      goto LABEL_89;
    }
    v37 = v76 * v34 + v32 - 16;
LABEL_76:
    v34 = -v34;
    goto LABEL_77;
  }
  v35 = 4;
  if ( HIBYTE(v85) )
  {
    v37 = v32 + v34 * (v76 - 1);
    goto LABEL_76;
  }
  v36 = v34 >> 2;
LABEL_88:
  v37 = v32;
LABEL_89:
  v71 = 0;
  v86 = v81;
  if ( v74 > 0 )
  {
    v67 = 4 * v36;
    v75 = (_BYTE *)v37;
    while ( v82 >= 4 )
    {
      v39 = *(_DWORD *)v86;
      v86 += 4;
      v82 -= 4;
      if ( (_BYTE)v39 == 2 || BYTE1(v39) == 2 && BYTE2(v39) < 0x80u )
      {
        if ( HIBYTE(v39) + (BYTE2(v39) << 8) == v78 )
        {
          v72 = 0;
          v81 = v75;
          while ( 1 )
          {
            v52 = 0;
            v83 = (float *)v81;
            if ( v78 > 0 )
              break;
LABEL_128:
            ++v72;
            v81 += 4;
            if ( v72 >= 4 )
              goto LABEL_105;
          }
          while ( v82 >= 2 )
          {
            v53 = *v86;
            if ( *v86 <= 0x80u )
            {
              v58 = v53;
              if ( v82 < v53 + 1 )
                goto LABEL_130;
              v52 += v53;
              v70 = v52;
              if ( v52 > v78 )
                goto LABEL_130;
              if ( v53 )
              {
                v59 = v86 + 1;
                v79 = v58;
                do
                {
                  v68 = *v59;
                  v60 = v83;
                  v83 += v35;
                  ++v59;
                  v9 = v79-- == 1;
                  *v60 = (float)v68;
                }
                while ( !v9 );
                v52 = v70;
              }
              v82 += -1 - v58;
              v86 += v58 + 1;
            }
            else
            {
              v54 = v53 & 0x7F;
              v55 = v54;
              v52 += v54;
              if ( v52 > v78 )
                goto LABEL_130;
              v79 = v86[1];
              v56 = (double)v79;
              if ( v54 )
              {
                do
                {
                  v57 = v83;
                  v83 += v35;
                  *v57 = v56;
                  --v55;
                }
                while ( v55 );
              }
              v86 += 2;
              v82 -= 2;
            }
            if ( v52 >= v78 )
              goto LABEL_128;
          }
        }
        break;
      }
      v81 = 0;
      v40 = (float *)v75;
      v41 = 1;
      v42 = (double)(unsigned __int8)v39;
      v43 = (double)BYTE1(v39);
      v79 = BYTE2(v39);
      v44 = (double)BYTE2(v39);
      v45 = (double)HIBYTE(v39);
      if ( v78 > 1 )
      {
        while ( v82 >= 4 )
        {
          v46 = *(_DWORD *)v86;
          v86 += 4;
          v82 -= 4;
          if ( (_WORD)v46 == 257 && BYTE2(v46) == 1 )
          {
            v47 = HIBYTE(v46) << (char)v81;
            v41 += v47;
            if ( v41 > v78 )
              goto LABEL_130;
            if ( v47 > 0 )
            {
              do
              {
                *v40 = v42;
                v40[1] = v43;
                v40[2] = v44;
                v40[3] = v45;
                v40 += v35;
                --v47;
              }
              while ( v47 );
            }
            v81 += 8;
          }
          else
          {
            v81 = 0;
            v42 = (double)(unsigned __int8)v46;
            v79 = BYTE1(v46);
            *v40 = v42;
            v43 = (double)v79;
            v79 = BYTE2(v46);
            v40[1] = v43;
            v44 = (double)v79;
            ++v41;
            v40[2] = v44;
            v45 = (double)HIBYTE(v46);
            v40[3] = v45;
            v40 += v35;
          }
          if ( v41 >= v78 )
            goto LABEL_105;
        }
        break;
      }
LABEL_105:
      ++v71;
      v75 += v67;
      if ( v71 >= v74 )
      {
        v33 = v76;
        goto LABEL_107;
      }
    }
LABEL_130:
    j__free(*((void **)this + 1));
    *((_DWORD *)this + 1) = 0;
    return -2147467259;
  }
LABEL_107:
  v48 = *((_DWORD *)this + 1);
  v49 = 0;
  if ( v33 * v77 )
  {
    v50 = (float *)(v48 + 8);
    v87 = 1.0 / v73;
    do
    {
      v51 = (__int64)v50[1] - 136;
      *(v50 - 2) = sub_63E473(*(v50 - 2) + 0.5, v51) * v87;
      *(v50 - 1) = sub_63E473(*(v50 - 1) + 0.5, v51) * v87;
      ++v49;
      *v50 = sub_63E473(*v50 + 0.5, v51) * v87;
      v50 += 4;
      *(v50 - 3) = 1.0;
    }
    while ( v49 < v76 * v77 );
  }
  return 0;
}
