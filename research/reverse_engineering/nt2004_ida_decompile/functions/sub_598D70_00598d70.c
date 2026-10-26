int __thiscall sub_598D70(int this, char a2, const char *a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // edi
  char *v10; // ebp
  _DWORD *v11; // eax
  int v13; // eax
  int v14; // edi
  int v15; // ebp
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  char *v19; // edi
  char *v20; // eax
  int v21; // edx
  char v22; // cl
  int v23; // eax
  int v24; // edi
  char *v25; // ebp
  int v26; // eax
  int v27; // edi
  _DWORD *v28; // eax
  char *v29; // ebx
  _DWORD *v30; // ebp
  char *v31; // edi
  int v32; // ebx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  char *v36; // eax
  char v37; // cl
  int v38; // edx
  char *v39; // eax
  char v40; // cl
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v45; // ecx
  int v46; // eax
  char *v47; // edi
  int v48; // eax
  int v49; // ebx
  int v50; // [esp-4h] [ebp-370h]
  int v51; // [esp+10h] [ebp-35Ch]
  char *v53; // [esp+18h] [ebp-354h]
  int v54; // [esp+1Ch] [ebp-350h]
  int v55; // [esp+20h] [ebp-34Ch]
  char v56[8]; // [esp+24h] [ebp-348h] BYREF
  char v57[64]; // [esp+2Ch] [ebp-340h] BYREF
  char Buffer[256]; // [esp+6Ch] [ebp-300h] BYREF
  char v59[256]; // [esp+16Ch] [ebp-200h] BYREF
  char v60[256]; // [esp+26Ch] [ebp-100h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  v3 = 0;
  v4 = 0;
  v51 = 0;
  if ( (a2 & 1) == 0 )
  {
    if ( (a2 & 2) != 0 )
    {
      v4 = 1;
    }
    else if ( (a2 & 4) != 0 )
    {
      v4 = 2;
    }
    else if ( (a2 & 8) != 0 )
    {
      v4 = 3;
    }
    else if ( (a2 & 0x10) != 0 )
    {
      v4 = 4;
    }
    else if ( (a2 & 0x20) != 0 )
    {
      v4 = 5;
    }
    else if ( (a2 & 0x40) != 0 )
    {
      v4 = 6;
    }
    else if ( a2 < 0 )
    {
      v4 = 7;
    }
  }
  v5 = *(_DWORD *)(this + 176);
  v6 = 148 * v4;
  v7 = *(_DWORD *)(v6 + v5 + 140);
  v8 = v5 + v6;
  if ( v7 )
  {
    if ( *(int *)(v8 + 72) > 0 )
    {
      v9 = 0;
      v10 = Buffer;
      do
      {
        strcpy(v10, (const char *)(v9 + *(_DWORD *)(v8 + 140) + 20));
        ++v3;
        v9 += 96;
        v10 += 32;
      }
      while ( v3 < *(_DWORD *)(v8 + 72) );
    }
    v11 = *(_DWORD **)(v8 + 140);
    if ( (*v11)-- == 1 )
    {
      v13 = *(_DWORD *)(v8 + 140);
      v14 = 0;
      if ( *(int *)(v13 + 88) > 0 )
      {
        v15 = 0;
        do
        {
          sub_5A2660(v13 + v15);
          v13 = *(_DWORD *)(v8 + 140);
          ++v14;
          v15 += 96;
        }
        while ( v14 < *(_DWORD *)(v13 + 88) );
      }
      sub_599CB0(*(_DWORD *)(v8 + 140));
    }
    *(_DWORD *)(v8 + 140) = 0;
  }
  if ( a3 )
  {
    strcpy(v57, a3);
    v16 = 0;
    v17 = strlen(v57);
    do
    {
      v18 = aBmp[v16];
      v56[v16++] = v18;
    }
    while ( v18 );
    if ( v17 > 0 )
    {
      while ( v57[v17] != 46 )
      {
        if ( --v17 <= 0 )
          goto LABEL_36;
      }
      v19 = &v57[v17];
      v20 = &v57[v17];
      v21 = v56 - &v57[v17];
      do
      {
        v22 = *v20;
        v20[v21] = *v20;
        ++v20;
      }
      while ( v22 );
      *v19 = 0;
    }
LABEL_36:
    v23 = *(_DWORD *)(v8 + 72);
    v24 = 0;
    if ( v23 > 0 )
    {
      v25 = Buffer;
      do
      {
        if ( v23 <= 1 )
          sprintf(v25, "%s%s", v57, v56);
        else
          sprintf(v25, "%s%.2d%s", v57, v24, v56);
        v23 = *(_DWORD *)(v8 + 72);
        ++v24;
        v25 += 32;
      }
      while ( v24 < v23 );
    }
  }
  sub_5A1B80((char *)v8, (int)v57);
  if ( !v57[0] )
    goto LABEL_85;
  v26 = sub_599D20(a3);
  if ( v26 && (*(_DWORD *)(v8 + 64) & 0x100) == 0 )
  {
    *(_DWORD *)(v8 + 140) = v26;
LABEL_84:
    ++**(_DWORD **)(v8 + 140);
LABEL_85:
    if ( (*(_BYTE *)(this + 156) & 0x40) != 0 )
    {
      v43 = sub_59A7D0(*(float *)(this + 184));
      *(_DWORD *)(this + 188) = v43;
      if ( !v43 )
      {
        sub_59A770(*(_DWORD *)(this + 184));
        *(_DWORD *)(this + 188) = sub_59A7D0(*(float *)(this + 184));
      }
    }
    *(_DWORD *)(this + 156) &= ~2u;
    return 0;
  }
  v27 = *(_DWORD *)(v8 + 72);
  v28 = operator new(96 * v27 + 4);
  if ( v28 )
  {
    v29 = (char *)(v28 + 1);
    *v28 = v27;
    v30 = v28 + 1;
    if ( v27 - 1 >= 0 )
    {
      do
      {
        sub_5A1D10(v30);
        v30 += 24;
        --v27;
      }
      while ( v27 );
    }
    v31 = v29;
  }
  else
  {
    v31 = 0;
  }
  v50 = *(_DWORD *)(v8 + 72);
  *(_DWORD *)(v8 + 140) = v31;
  sub_5A26A0(v50);
  if ( *(int *)(v8 + 72) > 1 )
    *(_DWORD *)(this + 156) |= 0x400u;
  v32 = 0;
  if ( *(int *)(v8 + 72) <= 0 )
  {
LABEL_83:
    sub_599C60(*(_DWORD *)(v8 + 140));
    goto LABEL_84;
  }
  v55 = v31 - v60 + 20;
  v54 = v31 - v59 + 20;
  v53 = Buffer;
  while ( 1 )
  {
    strcpy(v31 + 20, v53);
    v33 = *(_DWORD *)(v8 + 64);
    v34 = v51 | 4;
    v51 |= 4u;
    if ( (v33 & 0x80u) != 0 )
      v51 = v34 | 0x800;
    if ( dword_7E8D38 && (v33 & 0xC) != 0 )
    {
      *((_DWORD *)v31 + 23) = *(_DWORD *)(v8 + 68) + 1;
      v35 = *(_DWORD *)(v8 + 64);
      if ( (v35 & 8) != 0 )
      {
        v51 |= 0x2000u;
      }
      else if ( (v35 & 4) != 0 )
      {
        v51 |= 0x4000u;
      }
    }
    else
    {
      *(_DWORD *)(v8 + 64) = v33 & 0xFFFFFFF3;
      *((_DWORD *)v31 + 23) = 1;
    }
    if ( (*(_BYTE *)(v8 + 64) & 1) != 0 )
      *((_DWORD *)v31 + 1) |= 1u;
    if ( (*(_DWORD *)(v8 + 64) & 0x8000) != 0 )
      *((_DWORD *)v31 + 1) |= 0x8000u;
    if ( (*(_DWORD *)(v8 + 96) & 0x400000) != 0 )
      v51 |= (unsigned int)&unk_800000;
    if ( *(int *)(v8 + 72) <= 1 )
    {
      sprintf(v59, "%s%s", (const char *)v8, dword_608FD8);
      sprintf(v60, "%s%s", (const char *)v8, v56);
    }
    else
    {
      sprintf(v59, "%s%.2d%s", (const char *)v8, v32, dword_608FD8);
      sprintf(v60, "%s%.2d%s", (const char *)v8, v32, v56);
    }
    v36 = v59;
    do
    {
      v37 = *v36;
      v36[v54] = *v36;
      ++v36;
    }
    while ( v37 );
    if ( sub_5A2210(v31 + 20, *(_DWORD *)(v8 + 128), v51) )
    {
      v38 = v55;
      v39 = v60;
      do
      {
        v40 = *v39;
        v39[v38] = *v39;
        ++v39;
      }
      while ( v40 );
      if ( sub_5A1F80(v31 + 20, *(_DWORD *)(v8 + 128), v51) )
        break;
    }
    if ( *(int *)(*(_DWORD *)(v8 + 140) + 92) > 1 )
    {
      v41 = *(_DWORD *)(v8 + 64);
      if ( (v41 & 0xC) == 0 )
        *(_DWORD *)(v8 + 64) = v41 | 8;
    }
    v31 += 96;
    v42 = *(_DWORD *)(v8 + 72);
    v54 += 96;
    ++v32;
    v55 += 96;
    v53 += 32;
    if ( v32 >= v42 )
      goto LABEL_83;
  }
  for ( ; v32 > 0; ++v32 )
    sub_5A2660(*(_DWORD *)(v8 + 140));
  v45 = *(_DWORD *)(v8 + 140);
  if ( v45 )
  {
    v46 = *(_DWORD *)(v45 - 4);
    v47 = (char *)(v45 + 96 * v46);
    v48 = v46 - 1;
    if ( v48 >= 0 )
    {
      v49 = v48 + 1;
      do
      {
        v47 -= 96;
        j_nullsub_6(v47);
        --v49;
      }
      while ( v49 );
    }
    sub_5BE8AE();
  }
  *(_DWORD *)(v8 + 140) = 0;
  return -1;
}
