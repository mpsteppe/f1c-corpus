int __thiscall sub_598650(int this, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // eax
  int v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // ebp
  int v15; // edi
  int v16; // eax
  int v17; // edi
  _DWORD *v18; // eax
  _DWORD *v19; // ebx
  _DWORD *v20; // ebp
  _DWORD *v21; // eax
  int v22; // ebp
  int v23; // eax
  char v24; // cl
  int v25; // ecx
  _BYTE *v26; // edi
  int v27; // eax
  char *v28; // edx
  char v29; // cl
  char *v30; // eax
  int v31; // ebx
  int v32; // ebp
  int v33; // eax
  int v34; // eax
  int v35; // eax
  char *v36; // eax
  char v37; // cl
  char *v38; // eax
  char v39; // cl
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  char *v43; // eax
  char v44; // cl
  bool v45; // cc
  int v46; // eax
  unsigned int v47; // eax
  _DWORD *v48; // eax
  _DWORD *v49; // edx
  int v50; // eax
  int v51; // ecx
  int i; // eax
  int v54; // [esp-4h] [ebp-25Ch]
  int v55; // [esp-4h] [ebp-25Ch]
  _DWORD *v56; // [esp+10h] [ebp-248h]
  int v57; // [esp+10h] [ebp-248h]
  _DWORD *v59; // [esp+18h] [ebp-240h]
  int v60; // [esp+1Ch] [ebp-23Ch]
  int v61; // [esp+20h] [ebp-238h]
  char *v62; // [esp+24h] [ebp-234h]
  int v63; // [esp+28h] [ebp-230h]
  char v64[8]; // [esp+2Ch] [ebp-22Ch] BYREF
  int v65; // [esp+34h] [ebp-224h]
  char v66[32]; // [esp+38h] [ebp-220h] BYREF
  char Buffer[256]; // [esp+58h] [ebp-200h] BYREF
  char v68[256]; // [esp+158h] [ebp-100h] BYREF
  int v69; // [esp+25Ch] [ebp+4h]

  v2 = this;
  v3 = *(_DWORD *)(this + 156);
  if ( (v3 & 1) == 0 || (v3 & 2) == 0 )
    return 0;
  if ( a2 == -1 )
  {
    v4 = *(_DWORD *)(this + 172);
    v5 = 0;
  }
  else
  {
    v5 = a2;
    v4 = a2 + 1;
  }
  v6 = v5;
  v69 = v4;
  v63 = v5;
  if ( v5 >= v4 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(v2 + 176);
    v8 = 148 * v6;
    v9 = *(_DWORD *)(v8 + v7 + 96);
    v10 = v7 + v8;
    v65 = 0;
    if ( v9 != 0x8000000 )
      break;
    if ( sub_5A9070(v10 + 144, v10, 1, 0) )
      return -1;
    v11 = (_DWORD *)sub_599D20(v10);
    if ( v11 )
    {
      *(_DWORD *)(v10 + 140) = v11;
      ++*v11;
    }
    else
    {
      v12 = *(_DWORD *)(v10 + 72);
      v13 = operator new(96 * v12 + 4);
      if ( v13 )
      {
        v14 = v13 + 1;
        *v13 = v12;
        v56 = v13 + 1;
        if ( v12 - 1 >= 0 )
        {
          do
          {
            sub_5A1D10(v14);
            v14 += 24;
            --v12;
          }
          while ( v12 );
          v14 = v56;
        }
        v15 = (int)v14;
      }
      else
      {
        v15 = 0;
      }
      v54 = *(_DWORD *)(v10 + 72);
      *(_DWORD *)(v10 + 140) = v15;
      sub_5A26A0(v54);
      if ( sub_5A1DC0(
             v15,
             v10,
             *(_DWORD *)(*(_DWORD *)(v10 + 144) + 268),
             *(_DWORD *)(*(_DWORD *)(v10 + 144) + 272),
             0,
             4) )
      {
        return -1;
      }
      sub_599C60(v15);
      ++**(_DWORD **)(v10 + 140);
    }
LABEL_98:
    v47 = *(_DWORD *)(v2 + 156) & 0xFFFFFFFD;
    *(_DWORD *)(v2 + 156) = v47;
    if ( (v47 & 0x400) != 0 )
    {
      v48 = operator new(8u);
      if ( v48 )
      {
        *v48 = 0;
        v48[1] = 0;
        v49 = v48;
      }
      else
      {
        v49 = 0;
      }
      *v49 = v2;
      v50 = *(_DWORD *)(v2 + 192);
      v51 = *(_DWORD *)(v50 + 48);
      if ( v51 )
      {
        for ( i = *(_DWORD *)(v51 + 4); i; i = *(_DWORD *)(i + 4) )
          v51 = i;
        *(_DWORD *)(v51 + 4) = v49;
      }
      else
      {
        *(_DWORD *)(v50 + 48) = v49;
      }
    }
    v6 = ++v63;
    if ( v63 >= v69 )
      return 0;
  }
  if ( !*(_BYTE *)v10 )
  {
LABEL_95:
    if ( (*(_BYTE *)(v2 + 156) & 0x40) != 0 )
    {
      v46 = sub_59A7D0(*(float *)(v2 + 184));
      *(_DWORD *)(v2 + 188) = v46;
      if ( !v46 )
      {
        sub_59A770(*(_DWORD *)(v2 + 184));
        *(_DWORD *)(v2 + 188) = sub_59A7D0(*(float *)(v2 + 184));
      }
    }
    goto LABEL_98;
  }
  v16 = sub_599D20(v10);
  if ( v16 && (*(_DWORD *)(v10 + 64) & 0x100) == 0 )
  {
    *(_DWORD *)(v10 + 140) = v16;
LABEL_94:
    ++**(_DWORD **)(v10 + 140);
    goto LABEL_95;
  }
  v17 = *(_DWORD *)(v10 + 72);
  v18 = operator new(96 * v17 + 4);
  if ( v18 )
  {
    v19 = v18 + 1;
    *v18 = v17;
    v20 = v18 + 1;
    if ( v17 - 1 >= 0 )
    {
      do
      {
        sub_5A1D10(v20);
        v20 += 24;
        --v17;
      }
      while ( v17 );
    }
    v21 = v19;
  }
  else
  {
    v21 = 0;
  }
  v22 = (int)v21;
  v55 = *(_DWORD *)(v10 + 72);
  *(_DWORD *)(v10 + 140) = v21;
  v59 = v21;
  sub_5A26A0(v55);
  if ( *(int *)(v10 + 72) > 1 )
    *(_DWORD *)(this + 156) |= 0x400u;
  v23 = 0;
  do
  {
    v24 = aBmp[v23];
    v64[v23++] = v24;
  }
  while ( v24 );
  v25 = strlen((const char *)v10);
  if ( v25 > 0 )
  {
    while ( *(_BYTE *)(v25 + v10) != 46 )
    {
      if ( --v25 <= 0 )
        goto LABEL_39;
    }
    v26 = (_BYTE *)(v25 + v10);
    v27 = v25 + v10;
    v28 = &v64[-v25 - v10];
    do
    {
      v29 = *(_BYTE *)v27;
      v28[v27] = *(_BYTE *)v27;
      ++v27;
    }
    while ( v29 );
    *v26 = 0;
  }
LABEL_39:
  v57 = 0;
  if ( *(int *)(v10 + 72) <= 0 )
  {
LABEL_93:
    sub_599C60(*(_DWORD *)(v10 + 140));
    v2 = this;
    goto LABEL_94;
  }
  v61 = v22 - (_DWORD)v68 + 20;
  v60 = v22 - (_DWORD)Buffer + 20;
  v30 = &v66[-v22 - 20];
  v31 = v22 + 20;
  v32 = v65;
  v62 = v30;
  while ( 1 )
  {
    v33 = *(_DWORD *)(v10 + 96);
    if ( ((unsigned int)&unk_800000 & v33) != 0 && (v33 & 0x4000) != 0 )
    {
      v32 &= ~4u;
      *(_DWORD *)(v10 + 64) |= 2u;
    }
    v34 = *(_DWORD *)(v10 + 64);
    if ( (v34 & 2) != 0 )
    {
      if ( dword_7E8CD0 )
      {
        sub_59FA90(dword_7E8CD0);
        if ( dword_7E8CD0 )
        {
          j_nullsub_6((void *)dword_7E8CD0);
          sub_5BE8AE();
        }
        dword_7E8CD0 = 0;
      }
      else if ( dword_7E8CD4 )
      {
        sub_59FA90(dword_7E8CD4);
        if ( dword_7E8CD4 )
        {
          j_nullsub_6((void *)dword_7E8CD4);
          sub_5BE8AE();
        }
        dword_7E8CD4 = 0;
      }
      v32 |= 0x40008u;
      *(_DWORD *)(v10 + 64) |= 1u;
    }
    else
    {
      v32 |= 4u;
      if ( (v34 & 0x80u) != 0 )
        v32 |= 0x800u;
    }
    if ( dword_7E8D38 && (*(_BYTE *)(v10 + 64) & 0xC) != 0 )
    {
      *(_DWORD *)(v31 + 72) = *(_DWORD *)(v10 + 68) + 1;
      v35 = *(_DWORD *)(v10 + 64);
      if ( (v35 & 8) != 0 )
      {
        v32 |= 0x2000u;
      }
      else if ( (v35 & 4) != 0 )
      {
        v32 |= 0x4000u;
      }
    }
    else
    {
      *(_DWORD *)(v10 + 64) &= 0xFFFFFFF3;
      *(_DWORD *)(v31 + 72) = 1;
    }
    if ( (*(_BYTE *)(v10 + 64) & 1) != 0 )
      *(_DWORD *)(v31 - 16) |= 1u;
    if ( (*(_DWORD *)(v10 + 64) & 0x8000) != 0 )
      *(_DWORD *)(v31 - 16) |= 0x8000u;
    if ( (*(_DWORD *)(v10 + 96) & 0x400000) != 0 )
      v32 |= (unsigned int)&unk_800000;
    if ( *(int *)(v10 + 72) <= 1 )
    {
      sprintf(Buffer, "%s%s", (const char *)v10, dword_608FD8);
      sprintf(v68, "%s%s", (const char *)v10, v64);
    }
    else
    {
      sprintf(Buffer, "%s%.2d%s", (const char *)v10, v57, dword_608FD8);
      sprintf(v68, "%s%.2d%s", (const char *)v10, v57, v64);
    }
    v36 = Buffer;
    do
    {
      v37 = *v36;
      v36[v60] = *v36;
      ++v36;
    }
    while ( v37 );
    if ( sub_5A2210((char *)v31, *(_DWORD *)(v10 + 128), v32) )
    {
      v38 = v68;
      do
      {
        v39 = *v38;
        v38[v61] = *v38;
        ++v38;
      }
      while ( v39 );
      if ( sub_5A1F80((char *)v31, *(_DWORD *)(v10 + 128), v32) )
        return -1;
    }
    v40 = *(_DWORD *)(v10 + 96);
    if ( ((unsigned int)&unk_800000 & v40) != 0 && (v40 & 0x4000) != 0 && sub_59AB10(2, this) )
      return -1;
    if ( *(int *)(*(_DWORD *)(v10 + 140) + 92) > 1 )
    {
      v41 = *(_DWORD *)(v10 + 64);
      if ( (v41 & 0xC) == 0 )
        *(_DWORD *)(v10 + 64) = v41 | 8;
    }
    if ( (*(_DWORD *)(v10 + 64) & 0x100) != 0 )
    {
      v42 = strlen((const char *)v31);
      if ( v42 > 0 )
      {
        while ( *(_BYTE *)(v31 + v42) != 46 )
        {
          if ( --v42 <= 0 )
            goto LABEL_92;
        }
        *((_BYTE *)v59 + v42 + 20) = 0;
        v43 = (char *)v31;
        do
        {
          v44 = *v43;
          v62[(_DWORD)v43] = *v43;
          ++v43;
        }
        while ( v44 );
        sprintf((char *const)v31, "%s%4s%s%c", v66, (const char *)(this + 64), v64, 0);
      }
    }
LABEL_92:
    v59 += 24;
    v62 -= 96;
    v31 += 96;
    v60 += 96;
    v45 = v57 + 1 < *(_DWORD *)(v10 + 72);
    v61 += 96;
    ++v57;
    if ( !v45 )
      goto LABEL_93;
  }
}
