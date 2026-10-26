int __thiscall sub_6A333F(_DWORD *this)
{
  unsigned int v2; // eax
  bool i; // cf
  _DWORD *v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  _DWORD *v7; // edi
  unsigned int v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // edx
  _DWORD *v13; // ecx
  unsigned int j; // eax
  int v15; // edi
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // edi
  int v19; // edi
  int v20; // eax
  int v21; // ecx
  double v22; // st7
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  char *v26; // eax
  _DWORD *v27; // edi
  unsigned int v28; // ecx
  _DWORD *v29; // edi
  int v30; // eax
  unsigned int v31; // eax
  char *v32; // ecx
  _DWORD *v33; // eax
  unsigned int v34; // eax
  int v35; // ecx
  _DWORD *v36; // edx
  int v38; // [esp-Ch] [ebp-108h]
  _DWORD v39[20]; // [esp+14h] [ebp-E8h] BYREF
  _DWORD v40[12]; // [esp+64h] [ebp-98h] BYREF
  _DWORD v41[4]; // [esp+94h] [ebp-68h]
  _DWORD v42[4]; // [esp+A4h] [ebp-58h]
  _DWORD v43[4]; // [esp+B4h] [ebp-48h]
  unsigned int v44; // [esp+C4h] [ebp-38h]
  unsigned int v45; // [esp+C8h] [ebp-34h]
  unsigned int v46; // [esp+CCh] [ebp-30h]
  unsigned int v47; // [esp+D0h] [ebp-2Ch]
  _DWORD *v48; // [esp+D4h] [ebp-28h]
  int v49; // [esp+D8h] [ebp-24h]
  unsigned int v50; // [esp+DCh] [ebp-20h]
  _DWORD *v51; // [esp+E0h] [ebp-1Ch]
  double *v52; // [esp+E4h] [ebp-18h]
  int v53; // [esp+E8h] [ebp-14h]
  unsigned int v54; // [esp+ECh] [ebp-10h]
  int k; // [esp+F0h] [ebp-Ch]
  _DWORD *v56; // [esp+F4h] [ebp-8h]
  char *v57; // [esp+F8h] [ebp-4h]

  v57 = 0;
  v56 = 0;
  v2 = this[19];
  v44 = this[137];
  for ( i = v2 < v44; ; i = v46 + 1 < v44 )
  {
    v46 = v2;
    if ( !i )
    {
      v18 = 0;
      goto LABEL_65;
    }
    v48 = *(_DWORD **)(this[140] + 4 * v2);
    v4 = v48;
    if ( !v48 )
      goto LABEL_62;
    v5 = *v48;
    if ( !*v48 )
      goto LABEL_62;
    v54 = v5 & 0xFFFFF;
    v6 = v48[1] / (v5 & 0xFFFFFu);
    v50 = 0;
    v45 = v6;
    if ( v6 )
      break;
LABEL_54:
    v33 = (_DWORD *)sub_681186(116);
    if ( v33 )
      v56 = sub_680CEC(v33);
    else
      v56 = 0;
    if ( !v56 || sub_681997((int)this, v56) < 0 )
      goto LABEL_70;
    v18 = sub_681430((char *)v56, v4);
    if ( v18 < 0 )
      goto LABEL_67;
    v34 = this[137];
    if ( v34 >= 0x200 )
      goto LABEL_70;
    v35 = this[140];
    v36 = v56;
    v56 = 0;
    *(_DWORD *)(v35 + 4 * v34) = v36;
    ++this[137];
    *v4 = 0;
LABEL_62:
    v2 = v46 + 1;
  }
  v53 = 0;
  v51 = v40;
  while ( 1 )
  {
    v7 = v51;
    *v51 = -1;
    *++v7 = -1;
    *++v7 = -1;
    v7[1] = -1;
    memset(v39, 255, 16);
    v8 = 0;
    v49 = 0;
    v47 = 0;
    if ( !v54 )
      goto LABEL_73;
    v52 = (double *)(*v4 & 0xFFF00000);
    v9 = (_DWORD *)(v53 + v4[2]);
    do
    {
      v10 = this[5];
      k = *(_DWORD *)(v10 + 4 * *v9);
      if ( v52 != (double *)1342177280 && v54 == v4[3] )
        v8 = *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(v4[4] + 4 * v8)) + 16);
      v11 = v8 + 4 * v50;
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(k + 4)) + 5) & 1) != 0 )
        v40[v11] = v8;
      else
        v40[v11] = *(_DWORD *)(k + 16);
      if ( v8 == 3 )
        v49 = 1;
      v39[v8] = 0;
      v8 = v47 + 1;
      ++v9;
      ++v47;
    }
    while ( v47 < v54 );
    if ( !v49 )
      goto LABEL_73;
    v12 = 1;
    if ( v54 != 1 || v52 == (double *)1342177280 && v4[3] == 1 )
      goto LABEL_73;
    v13 = v51;
    for ( j = 0; j < 4; ++j )
    {
      if ( *v13 != dword_91A4A0[j] && v39[j] != -1 )
        v12 = 0;
      ++v13;
    }
    if ( !v12 )
    {
LABEL_73:
      if ( !sub_6A326C((int)v51, v39, 2u) )
        break;
    }
LABEL_53:
    ++v50;
    v51 += 4;
    v53 += 4 * v54;
    if ( v50 >= v45 )
      goto LABEL_54;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = sub_681AAA(this, this[34], 0, 3, 0.0);
    v43[v15] = v16;
    if ( v16 == -1 )
      break;
    if ( ++v15 )
    {
      v17 = (_DWORD *)sub_681186(116);
      if ( v17 )
        v57 = (char *)sub_680CEC(v17);
      else
        v57 = 0;
      if ( v57 )
      {
        v18 = sub_6811D1(v57, 1342177283, 6, 1, 0);
        if ( v18 < 0 )
          goto LABEL_65;
        v18 = sub_680D22(v57, (int)v4);
        if ( v18 < 0 )
          goto LABEL_65;
        v19 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v53 + v4[2]));
        v49 = *(_DWORD *)(v19 + 16);
        v20 = 0;
        for ( k = 0; ; v20 = k )
        {
          v21 = v20 == v49 ? this[273] : this[272];
          v22 = *(double *)(v19 + 32);
          v38 = *(_DWORD *)(v19 + 4);
          v42[v20] = v21;
          v23 = sub_681AAA(this, v38, 0, v20, v22);
          v41[k] = v23;
          if ( v23 == -1 )
            break;
          v52 = *(double **)(this[5] + 4 * v23);
          sub_6815D6(v52, v19);
          v24 = *(_DWORD *)(v53 + v4[2]);
          v25 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v24) + 56);
          if ( v25 == -1 )
            *((_DWORD *)v52 + 14) = v24;
          else
            *((_DWORD *)v52 + 14) = v25;
          if ( (unsigned int)++k >= 3 )
          {
            v26 = v57;
            v27 = (_DWORD *)*((_DWORD *)v57 + 2);
            v28 = v54;
            *v27++ = v42[0];
            *v27 = v42[1];
            v27[1] = v42[2];
            v29 = (_DWORD *)(*((_DWORD *)v26 + 2) + 12);
            *v29++ = v41[0];
            *v29 = v41[1];
            v29[1] = v41[2];
            **((_DWORD **)v26 + 4) = v43[0];
            if ( v28 )
            {
              v30 = v53;
              do
              {
                *(_DWORD *)(v30 + v48[2]) = v43[0];
                v30 += 4;
                --v28;
              }
              while ( v28 );
            }
            v31 = this[137];
            if ( v31 < 0x200 )
            {
              v32 = v57;
              *(_DWORD *)(this[140] + 4 * v31) = v57;
              ++this[137];
              if ( sub_681997((int)this, v32) >= 0 )
              {
                v57 = 0;
                v4 = v48;
                goto LABEL_53;
              }
            }
            goto LABEL_70;
          }
        }
      }
      break;
    }
  }
LABEL_70:
  v18 = -2147024882;
LABEL_65:
  if ( v57 )
    sub_66238F(v57, 1);
LABEL_67:
  if ( v56 )
    sub_66238F(v56, 1);
  return v18;
}
