int __thiscall sub_647CB3(int *this, unsigned __int8 *a2, unsigned int a3)
{
  int *v3; // esi
  unsigned __int8 v6; // cl
  int v7; // edx
  int v8; // eax
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // eax
  void *v18; // edx
  _BYTE *v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edi
  unsigned int v25; // edx
  unsigned int v26; // edx
  unsigned int i; // eax
  unsigned int v28; // ecx
  size_t v29; // eax
  char *v30; // eax
  char *v31; // edx
  unsigned int v32; // eax
  int v33; // ecx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  bool v36; // zf
  int v37; // edx
  unsigned int v38; // edi
  unsigned int v39; // ebx
  unsigned int v41; // [esp+Ch] [ebp-38h]
  unsigned int v42; // [esp+Ch] [ebp-38h]
  int v43; // [esp+10h] [ebp-34h]
  BOOL v44; // [esp+14h] [ebp-30h]
  BOOL v45; // [esp+18h] [ebp-2Ch]
  unsigned int v46; // [esp+1Ch] [ebp-28h]
  int v47; // [esp+1Ch] [ebp-28h]
  int v48; // [esp+20h] [ebp-24h]
  unsigned int v49; // [esp+20h] [ebp-24h]
  _BYTE *v50; // [esp+24h] [ebp-20h]
  int v51; // [esp+24h] [ebp-20h]
  int v52; // [esp+28h] [ebp-1Ch]
  char v53; // [esp+2Ch] [ebp-18h]
  int v54; // [esp+30h] [ebp-14h]
  _BYTE *v55; // [esp+34h] [ebp-10h]
  char *v56; // [esp+34h] [ebp-10h]
  int v57; // [esp+38h] [ebp-Ch]
  int v58; // [esp+3Ch] [ebp-8h]
  unsigned int v59; // [esp+40h] [ebp-4h]
  int v60; // [esp+4Ch] [ebp+8h]
  _BYTE *v61; // [esp+4Ch] [ebp+8h]
  unsigned int v62; // [esp+50h] [ebp+Ch]
  unsigned int v63; // [esp+50h] [ebp+Ch]
  unsigned int v64; // [esp+50h] [ebp+Ch]

  v3 = this;
  if ( a3 < 0x12 )
    return -2147467259;
  v6 = a2[1];
  if ( (v6 & 0xFE) != 0 )
    return -2147467259;
  v7 = a2[2];
  if ( (v7 & 0xFFFFFFF4) != 0 || !*((_WORD *)a2 + 6) || !*((_WORD *)a2 + 7) )
    return -2147467259;
  v8 = a2[7];
  v54 = 0;
  v9 = (unsigned int)(v8 + 7) >> 3;
  if ( v6 )
  {
    v10 = v8 - 15;
    if ( v10 )
    {
      v11 = v10 - 1;
      if ( v11 )
      {
        v12 = v11 - 8;
        if ( v12 )
        {
          if ( v12 != 8 )
            return -2147467259;
          v54 = 21;
        }
        else
        {
          v54 = 20;
        }
      }
      else
      {
        v54 = 25;
      }
    }
    else
    {
      v54 = 24;
    }
  }
  v13 = a2[16];
  v59 = (unsigned int)(v13 + 7) >> 3;
  if ( (v7 & 3) == 1 )
  {
    if ( !a2[1] || a2[16] != 8 )
      return -2147467259;
    v57 = 41;
  }
  else if ( (v7 & 3) == 2 )
  {
    v14 = v13 - 15;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        v16 = v15 - 8;
        if ( v16 )
        {
          if ( v16 != 8 )
            return -2147467259;
          v57 = 21;
        }
        else
        {
          v57 = 20;
        }
      }
      else
      {
        v57 = 25;
      }
    }
    else
    {
      v57 = 24;
    }
  }
  else
  {
    if ( (v7 & 3) != 3 || a2[16] != 8 )
      return -2147467259;
    v57 = 50;
  }
  v43 = v7 & 8;
  v44 = (a2[17] & 0x20) == 32;
  v17 = *a2;
  v62 = a3 - 18;
  v45 = (a2[17] & 0x10) != 16;
  if ( v62 < v17 )
    return -2147467259;
  v63 = v62 - v17;
  v60 = (int)&a2[v17 + 18];
  v41 = v9 * *(unsigned __int16 *)(a2 + 5);
  if ( v63 < v41 )
    return -2147467259;
  if ( !v3[16] || v57 != 41 )
    goto LABEL_56;
  if ( *(unsigned __int16 *)(a2 + 5) + *(unsigned __int16 *)(a2 + 3) > 256 )
    return -2147467259;
  v18 = operator new(0x400u);
  v3[2] = (int)v18;
  if ( !v18 )
    return -2147024882;
  v48 = 0;
  v3[15] = 1;
  memset(v18, 0xFFu, 0x400u);
  v19 = (_BYTE *)v60;
  v20 = v3[2] + 4 * *(unsigned __int16 *)(a2 + 3);
  v55 = (_BYTE *)v60;
  v50 = (_BYTE *)v20;
  v46 = v20 + 4 * *(unsigned __int16 *)(a2 + 5);
  if ( v20 >= v46 )
  {
LABEL_53:
    for ( i = v3[2] + 4 * *(unsigned __int16 *)(a2 + 3); i < v46; i += 4 )
      *(_BYTE *)(i + 3) = -1;
    goto LABEL_56;
  }
  LOBYTE(v21) = v63;
  do
  {
    LOBYTE(v22) = v53;
    switch ( v54 )
    {
      case 20:
        LOBYTE(v21) = v19[2];
        LOBYTE(v22) = v19[1];
        LOBYTE(v58) = *v19;
        v19 += 3;
        goto LABEL_49;
      case 21:
        LOBYTE(v22) = BYTE1(*(_DWORD *)v19);
        v52 = HIBYTE(*(_DWORD *)v19);
        LOBYTE(v21) = BYTE2(*(_DWORD *)v19);
        LOBYTE(v58) = *(_DWORD *)v19;
        v19 += 4;
        goto LABEL_50;
      case 24:
        v26 = *(unsigned __int16 *)v19;
        v21 = (8 * ((v26 >> 10) & 0x1F)) | (((v26 >> 10) & 0x1F) >> 2);
        v22 = (8 * ((v26 >> 5) & 0x1F)) | (((v26 >> 5) & 0x1F) >> 2);
        v58 = (8 * (v26 & 0x1F)) | ((unsigned __int8)(v26 & 0x1F) >> 2);
        v19 = v55 + 2;
LABEL_49:
        v52 = 255;
        goto LABEL_50;
    }
    if ( v54 != 25 )
      goto LABEL_51;
    v23 = *(unsigned __int16 *)v19;
    v52 = 255 * (v23 >> 15);
    v24 = v23 & 0x1F;
    v25 = v23 >> 5;
    v21 = (8 * ((v23 >> 10) & 0x1F)) | (((v23 >> 10) & 0x1F) >> 2);
    v22 = (8 * (v25 & 0x1F)) | ((unsigned __int8)(v25 & 0x1F) >> 2);
    v58 = (8 * v24) | (v24 >> 2);
    v19 = v55 + 2;
LABEL_50:
    v53 = v22;
    v55 = v19;
LABEL_51:
    v50[1] = v22;
    v50[2] = v58;
    v50[3] = v52;
    *v50 = v21;
    v50 += 4;
    v48 |= v52 != 0;
  }
  while ( (unsigned int)v50 < v46 );
  if ( !v48 )
    goto LABEL_53;
LABEL_56:
  v64 = v63 - v41;
  v28 = v41 + v60;
  v29 = v59 * *((unsigned __int16 *)a2 + 6) * *((unsigned __int16 *)a2 + 7);
  *v3 = v57;
  v3[1] = v41 + v60;
  v3[12] = v59 * *((unsigned __int16 *)a2 + 6);
  v36 = v3[16] == 0;
  v3[13] = 0;
  v3[3] = *((unsigned __int16 *)a2 + 6);
  v61 = (_BYTE *)(v41 + v60);
  v3[4] = *((unsigned __int16 *)a2 + 7);
  v3[5] = 1;
  if ( v36 )
    return 0;
  if ( v43 || !v44 || !v45 )
  {
    v30 = (char *)operator new(v29);
    v3[1] = (int)v30;
    if ( !v30 )
      return -2147024882;
    v3[14] = 1;
    if ( v44 )
      v31 = v30;
    else
      v31 = &v30[v3[12] * (*((unsigned __int16 *)a2 + 7) - 1)];
    v51 = 0;
    if ( !*((_WORD *)a2 + 7) )
      goto LABEL_91;
    while ( 1 )
    {
      v56 = v45 ? v31 : &v31[v3[12] - v59];
      v32 = *((unsigned __int16 *)a2 + 6);
      v49 = 0;
      if ( *((_WORD *)a2 + 6) )
        break;
LABEL_87:
      if ( v44 )
        v31 += v3[12];
      else
        v31 -= v3[12];
      if ( ++v51 >= (unsigned int)*((unsigned __int16 *)a2 + 7) )
        goto LABEL_91;
    }
    while ( 1 )
    {
      if ( v43 )
      {
        if ( !v64 )
          return -2147467259;
        v33 = *v61 & 0x80;
        v32 = (*v61++ & 0x7F) + 1;
        --v64;
        v47 = v33;
      }
      else
      {
        v47 = 0;
      }
      v49 += v32;
      if ( v32 )
        break;
LABEL_84:
      if ( v47 )
      {
        v61 += v59;
        v64 -= v59;
      }
      v32 = *((unsigned __int16 *)a2 + 6);
      if ( v49 >= v32 )
        goto LABEL_87;
    }
    while ( 1 )
    {
      v42 = v32 - 1;
      if ( v64 < v59 )
        return -2147467259;
      qmemcpy(v56, v61, v59);
      if ( !v47 )
      {
        v61 += v59;
        v64 -= v59;
      }
      if ( v45 )
        v56 += v59;
      else
        v56 -= v59;
      --v32;
      if ( !v42 )
      {
        v3 = this;
        goto LABEL_84;
      }
    }
  }
  if ( v64 < v29 )
    return -2147467259;
  v3[1] = v28;
  v3[14] = 0;
LABEL_91:
  if ( *v3 == 25 )
  {
    v34 = v3[1];
    v35 = v34 + v3[12] * v3[4];
    v36 = v34 == v35;
    if ( v34 < v35 )
    {
      v37 = 2 * v3[3];
      do
      {
        v38 = v37 + v34;
        v39 = v34;
        if ( v34 < v37 + v34 )
        {
          do
          {
            if ( *(char *)(v39 + 1) < 0 )
              break;
            v39 += 2;
          }
          while ( v39 < v38 );
          if ( v39 < v38 )
            break;
        }
        v34 += v3[12];
      }
      while ( v34 < v35 );
      v36 = v34 == v35;
    }
    if ( v36 )
      *v3 = 24;
  }
  return 0;
}
