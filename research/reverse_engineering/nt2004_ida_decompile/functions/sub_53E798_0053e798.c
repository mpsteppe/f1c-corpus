int __thiscall sub_53E798(int *this, unsigned __int8 *a2, unsigned int a3)
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
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  int v22; // edx
  unsigned int v23; // eax
  unsigned int v24; // edi
  unsigned int v25; // edx
  unsigned int v26; // edx
  _BYTE *v27; // edi
  unsigned int v28; // ecx
  unsigned int v29; // eax
  bool v30; // zf
  char *v31; // eax
  char *v32; // edx
  unsigned int v33; // eax
  int v34; // ecx
  unsigned int v36; // [esp+Ch] [ebp-30h]
  unsigned int v37; // [esp+Ch] [ebp-30h]
  unsigned int v38; // [esp+10h] [ebp-2Ch]
  int v39; // [esp+14h] [ebp-28h]
  BOOL v40; // [esp+18h] [ebp-24h]
  BOOL v41; // [esp+1Ch] [ebp-20h]
  int v42; // [esp+20h] [ebp-1Ch]
  int v43; // [esp+20h] [ebp-1Ch]
  char v44; // [esp+24h] [ebp-18h]
  unsigned int v45; // [esp+24h] [ebp-18h]
  int v46; // [esp+28h] [ebp-14h]
  int v47; // [esp+28h] [ebp-14h]
  _BYTE *v48; // [esp+2Ch] [ebp-10h]
  int v49; // [esp+30h] [ebp-Ch]
  unsigned int v50; // [esp+34h] [ebp-8h]
  int v51; // [esp+38h] [ebp-4h]
  _BYTE *v52; // [esp+38h] [ebp-4h]
  unsigned __int16 *v53; // [esp+44h] [ebp+8h]
  char *v54; // [esp+44h] [ebp+8h]
  unsigned int v55; // [esp+48h] [ebp+Ch]
  unsigned int v56; // [esp+48h] [ebp+Ch]
  unsigned int v57; // [esp+48h] [ebp+Ch]

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
  v46 = 0;
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
          v46 = 21;
        }
        else
        {
          v46 = 20;
        }
      }
      else
      {
        v46 = 25;
      }
    }
    else
    {
      v46 = 24;
    }
  }
  v13 = a2[16];
  v50 = (unsigned int)(v13 + 7) >> 3;
  if ( (v7 & 3) == 1 )
  {
    if ( !a2[1] || a2[16] != 8 )
      return -2147467259;
    v49 = 41;
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
          v49 = 21;
        }
        else
        {
          v49 = 20;
        }
      }
      else
      {
        v49 = 25;
      }
    }
    else
    {
      v49 = 24;
    }
  }
  else
  {
    if ( (v7 & 3) != 3 || a2[16] != 8 )
      return -2147467259;
    v49 = 50;
  }
  v39 = v7 & 8;
  v40 = (a2[17] & 0x20) == 32;
  v17 = *a2;
  v55 = a3 - 18;
  v41 = (a2[17] & 0x10) != 16;
  if ( v55 < v17 )
    return -2147467259;
  v56 = v55 - v17;
  v51 = (int)&a2[v17 + 18];
  v36 = v9 * *(unsigned __int16 *)(a2 + 5);
  if ( v56 < v36 )
    return -2147467259;
  if ( v3[16] && v49 == 41 )
  {
    if ( *(unsigned __int16 *)(a2 + 5) + *(unsigned __int16 *)(a2 + 3) > 256 )
      return -2147467259;
    v18 = operator new(0x400u);
    v3[2] = (int)v18;
    if ( !v18 )
      return -2147024882;
    v3[15] = 1;
    memset(v18, 0xFFu, 0x400u);
    v53 = (unsigned __int16 *)v51;
    v19 = v3[2] + 4 * *(unsigned __int16 *)(a2 + 3);
    v48 = (_BYTE *)v19;
    v38 = v19 + 4 * *(unsigned __int16 *)(a2 + 5);
    if ( v19 < v38 )
    {
      LOBYTE(v20) = v56;
      LOBYTE(v21) = v56;
      while ( 1 )
      {
        LOBYTE(v22) = v44;
        if ( v46 == 20 )
          break;
        switch ( v46 )
        {
          case 21:
            LOBYTE(v21) = BYTE1(*(_DWORD *)v53);
            v42 = HIBYTE(*(_DWORD *)v53);
            LOBYTE(v20) = BYTE2(*(_DWORD *)v53);
            LOBYTE(v22) = *(_DWORD *)v53;
            v53 += 2;
            goto LABEL_50;
          case 24:
            v26 = *v53;
            v20 = (8 * ((v26 >> 10) & 0x1F)) | (((v26 >> 10) & 0x1F) >> 2);
            v21 = (8 * ((v26 >> 5) & 0x1F)) | (((v26 >> 5) & 0x1F) >> 2);
            v22 = (8 * (v26 & 0x1F)) | ((unsigned __int8)(v26 & 0x1F) >> 2);
            ++v53;
LABEL_49:
            LOBYTE(v42) = -1;
            goto LABEL_50;
          case 25:
            v23 = *v53;
            v42 = 255 * (v23 >> 15);
            v24 = v23 & 0x1F;
            v25 = v23 >> 5;
            v20 = (8 * ((v23 >> 10) & 0x1F)) | (((v23 >> 10) & 0x1F) >> 2);
            v21 = (8 * (v25 & 0x1F)) | ((unsigned __int8)(v25 & 0x1F) >> 2);
            v22 = (8 * v24) | (v24 >> 2);
            ++v53;
LABEL_50:
            v44 = v22;
            break;
        }
        v27 = v48;
        v48 += 4;
        v27[2] = v22;
        v27[3] = v42;
        *v27 = v20;
        v27[1] = v21;
        if ( (unsigned int)v48 >= v38 )
          goto LABEL_52;
      }
      LOBYTE(v20) = *((_BYTE *)v53 + 2);
      LOBYTE(v21) = *((_BYTE *)v53 + 1);
      LOBYTE(v22) = *(_BYTE *)v53;
      v53 = (unsigned __int16 *)((char *)v53 + 3);
      goto LABEL_49;
    }
  }
LABEL_52:
  v57 = v56 - v36;
  v28 = v36 + v51;
  v29 = v50 * *((unsigned __int16 *)a2 + 6) * *((unsigned __int16 *)a2 + 7);
  *v3 = v49;
  v3[1] = v36 + v51;
  v30 = v3[16] == 0;
  v3[12] = v50 * *((unsigned __int16 *)a2 + 6);
  v3[13] = 0;
  v3[3] = *((unsigned __int16 *)a2 + 6);
  v52 = (_BYTE *)(v36 + v51);
  v3[4] = *((unsigned __int16 *)a2 + 7);
  v3[5] = 1;
  if ( v30 )
    return 0;
  if ( !v39 && v40 && v41 )
  {
    if ( v57 >= v29 )
    {
      v3[1] = v28;
      v3[14] = 0;
      return 0;
    }
  }
  else
  {
    v31 = (char *)operator new(v29);
    v3[1] = (int)v31;
    if ( !v31 )
      return -2147024882;
    v3[14] = 1;
    if ( v40 )
      v32 = v31;
    else
      v32 = &v31[v3[12] * (*((unsigned __int16 *)a2 + 7) - 1)];
    v47 = 0;
    if ( !*((_WORD *)a2 + 7) )
      return 0;
    while ( 1 )
    {
      v54 = v41 ? v32 : &v32[v3[12] - v50];
      v33 = *((unsigned __int16 *)a2 + 6);
      v45 = 0;
      if ( *((_WORD *)a2 + 6) )
        break;
LABEL_83:
      if ( v40 )
        v32 += v3[12];
      else
        v32 -= v3[12];
      if ( ++v47 >= (unsigned int)*((unsigned __int16 *)a2 + 7) )
        return 0;
    }
    while ( 1 )
    {
      if ( v39 )
      {
        if ( !v57 )
          return -2147467259;
        v34 = *v52 & 0x80;
        v33 = (*v52++ & 0x7F) + 1;
        --v57;
        v43 = v34;
      }
      else
      {
        v43 = 0;
      }
      v45 += v33;
      if ( v33 )
        break;
LABEL_80:
      if ( v43 )
      {
        v52 += v50;
        v57 -= v50;
      }
      v33 = *((unsigned __int16 *)a2 + 6);
      if ( v45 >= v33 )
        goto LABEL_83;
    }
    while ( 1 )
    {
      v37 = v33 - 1;
      if ( v57 < v50 )
        break;
      qmemcpy(v54, v52, v50);
      if ( !v43 )
      {
        v52 += v50;
        v57 -= v50;
      }
      if ( v41 )
        v54 += v50;
      else
        v54 -= v50;
      --v33;
      if ( !v37 )
      {
        v3 = this;
        goto LABEL_80;
      }
    }
  }
  return -2147467259;
}
