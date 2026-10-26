int __thiscall sub_531250(int this, int a2)
{
  char *v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  char *v7; // ebx
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  _BYTE *v11; // ebx
  int v12; // ecx
  char *v13; // eax
  unsigned int v14; // ecx
  char v15; // cl
  unsigned __int32 v16; // eax
  int v17; // edi
  __int16 *v18; // ecx
  int v19; // ecx
  char v20; // di
  unsigned int v21; // eax
  char *v22; // ecx
  char v23; // al
  unsigned __int32 v24; // eax
  int v25; // edi
  __int16 *v26; // ecx
  char *v27; // eax
  char v28; // cl
  int v29; // eax
  int v30; // eax
  bool v31; // zf
  unsigned __int32 v32; // eax
  int v33; // ebx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  _BYTE *v36; // edx
  _BYTE *v37; // edx
  int v38; // ecx
  unsigned __int32 v39; // eax
  int v40; // ebx
  int v41; // ecx
  _BYTE *v42; // edx
  unsigned __int32 v43; // eax
  int v44; // ebx
  int v45; // edi
  int v46; // ebx
  int v47; // edi
  int v48; // edi
  _WORD *v49; // ebx
  char *v50; // ebx
  int v51; // edi
  int v52; // edi
  _BYTE v54[64]; // [esp+4h] [ebp-158h] BYREF
  char v55[192]; // [esp+44h] [ebp-118h] BYREF
  char v56[64]; // [esp+104h] [ebp-58h] BYREF
  __int16 *v57; // [esp+144h] [ebp-18h]
  int v58; // [esp+148h] [ebp-14h]
  unsigned int v59; // [esp+14Ch] [ebp-10h]
  unsigned int v60; // [esp+150h] [ebp-Ch]
  unsigned int v61; // [esp+154h] [ebp-8h]
  __int16 *v62; // [esp+158h] [ebp-4h]
  int v63; // [esp+164h] [ebp+8h]
  int v64; // [esp+164h] [ebp+8h]
  int v65; // [esp+164h] [ebp+8h]

  v3 = v55;
  if ( !*(_DWORD *)(this + 9380) )
    return 0;
  if ( *(_BYTE *)(this + 9406) )
    v4 = 4;
  else
    v4 = byte_5B65E0[16 * (2 * *(unsigned __int8 *)(this + 9412) - *(_DWORD *)(this + 9420))
                   + *(unsigned __int8 *)(this + 9411)];
  v5 = word_5B6620[v4];
  *(_DWORD *)(this + 9400) = v5;
  v57 = (__int16 *)*(&off_5DA760 + v4);
  v62 = v57;
  v6 = *(_DWORD *)(this + 9420);
  v58 = v6 * v5;
  v7 = v56;
  if ( v6 == 2 )
  {
    if ( v5 )
    {
      v59 = v5;
      do
      {
        v8 = *v62;
        v61 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
        v9 = v8 + *(_DWORD *)(this + 9384);
        *v7 = dword_5B4788[v8] & (_byteswap_ulong(v61) >> -(char)(v8 + (*(_BYTE *)(this + 9384) & 7)));
        v10 = *(_DWORD *)(this + 9380);
        *(_DWORD *)(this + 9384) = v9;
        v11 = v7 + 1;
        v61 = *(_DWORD *)((v9 >> 3) + v10);
        v12 = v8 + *(_DWORD *)(this + 9384);
        *v11 = dword_5B4788[v8] & (_byteswap_ulong(v61) >> -(char)(v8 + (*(_BYTE *)(this + 9384) & 7)));
        *(_DWORD *)(this + 9384) = v12;
        v7 = v11 + 1;
        v62 += 2 * (1 << v8);
        --v59;
      }
      while ( v59 );
    }
    v13 = v56;
    v62 = (__int16 *)v54;
    v14 = v58;
    if ( !v58 )
      goto LABEL_24;
    v61 = v58;
    do
    {
      v15 = *v13++;
      v59 = (unsigned int)v13;
      if ( v15 )
      {
        v60 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
        v16 = _byteswap_ulong(v60);
        v17 = *(_DWORD *)(this + 9384) & 7;
        *(_DWORD *)(this + 9384) += 2;
        v18 = v62;
        *(_BYTE *)v62 = (v16 >> (-2 - v17)) & 3;
        v13 = (char *)v59;
        v62 = (__int16 *)((char *)v18 + 1);
      }
      --v61;
    }
    while ( v61 );
  }
  else
  {
    if ( v5 )
    {
      v61 = v5;
      do
      {
        v19 = *(_DWORD *)(this + 9384);
        v59 = *v62;
        v60 = *(_DWORD *)((v19 >> 3) + *(_DWORD *)(this + 9380));
        v20 = v59;
        v21 = v59 + *(_DWORD *)(this + 9384);
        *v7 = LOBYTE(dword_5B4788[v59]) & (_byteswap_ulong(v60) >> -(char)(v59 + (*(_BYTE *)(this + 9384) & 7)));
        *(_DWORD *)(this + 9384) = v21;
        ++v7;
        v62 += 2 * (1 << v20);
        --v61;
      }
      while ( v61 );
    }
    v22 = v56;
    v62 = (__int16 *)v54;
    if ( *(_DWORD *)(this + 9400) )
    {
      v61 = *(_DWORD *)(this + 9400);
      do
      {
        v23 = *v22++;
        v59 = (unsigned int)v22;
        if ( v23 )
        {
          v60 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
          v24 = _byteswap_ulong(v60);
          v25 = *(_DWORD *)(this + 9384) & 7;
          *(_DWORD *)(this + 9384) += 2;
          v26 = v62;
          *(_BYTE *)v62 = (v24 >> (-2 - v25)) & 3;
          v62 = (__int16 *)((char *)v26 + 1);
          v22 = (char *)v59;
        }
        --v61;
      }
      while ( v61 );
    }
  }
  v14 = v58;
LABEL_24:
  v27 = v56;
  v62 = (__int16 *)v54;
  if ( v14 )
  {
    v61 = v14;
    while ( 1 )
    {
      v28 = *v27;
      v59 = (unsigned int)(v27 + 1);
      if ( !v28 )
        goto LABEL_38;
      v29 = *(char *)v62;
      v62 = (__int16 *)((char *)v62 + 1);
      if ( v29 )
      {
        v30 = v29 - 1;
        if ( v30 )
        {
          v31 = v30 == 1;
          v60 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
          v32 = _byteswap_ulong(v60);
          if ( v31 )
          {
            v38 = -6 - (*(_DWORD *)(this + 9384) & 7);
            *(_DWORD *)(this + 9384) += 6;
            v35 = (v32 >> v38) & 0x3F;
            *v3 = v35;
          }
          else
          {
            v33 = *(_DWORD *)(this + 9384) & 7;
            *(_DWORD *)(this + 9384) += 12;
            v34 = (v32 >> (-12 - v33)) & 0xFFF;
            v35 = (v32 >> (-12 - v33)) & 0x3F;
            *v3 = (v34 >> 6) & 0x3F;
          }
          v36 = v3 + 1;
          *v36 = v35;
          v37 = v36 + 1;
          goto LABEL_37;
        }
        v60 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
        v39 = _byteswap_ulong(v60);
        v40 = *(_DWORD *)(this + 9384) & 7;
        *(_DWORD *)(this + 9384) += 12;
        v35 = (v39 >> (-12 - v40)) & 0xFFF;
        v41 = (v35 >> 6) & 0x3F;
        *v3 = v41;
        v42 = v3 + 1;
      }
      else
      {
        v60 = *(_DWORD *)((*(int *)(this + 9384) >> 3) + *(_DWORD *)(this + 9380));
        v43 = _byteswap_ulong(v60);
        v44 = *(_DWORD *)(this + 9384) & 7;
        *(_DWORD *)(this + 9384) += 18;
        v35 = (v43 >> (-18 - v44)) & 0x3FFFF;
        *v3 = (v35 >> 12) & 0x3F;
        v42 = v3 + 1;
        LOBYTE(v41) = (v35 >> 6) & 0x3F;
      }
      *v42 = v41;
      v37 = v42 + 1;
      LOBYTE(v35) = v35 & 0x3F;
LABEL_37:
      *v37 = v35;
      v3 = v37 + 1;
LABEL_38:
      if ( !--v61 )
        break;
      v27 = (char *)v59;
    }
  }
  v45 = a2;
  v46 = 0;
  if ( a2 )
    v58 = *(_DWORD *)(this + 9424);
  else
    v58 = 0;
  if ( dword_8B0108 )
  {
    v64 = 0;
    v49 = &unk_8B0424;
    do
    {
      sub_530840((_DWORD *)this, (int)&unk_5B2BA4, v56, v49, &v55[v64 >> 2], v57);
      v49 += 192;
      ++v64;
    }
    while ( (int)v49 < (int)dword_8B1624 );
    v50 = (char *)&unk_8B04A4;
    v65 = 2 * v58;
    do
    {
      sub_532AA0(v45, v50 - 128);
      v51 = v65 + v45;
      sub_532AA0(v51, v50);
      v52 = v65 + v51;
      sub_532AA0(v52, v50 + 128);
      v50 += 384;
      v45 = v65 + v52;
    }
    while ( (int)v50 < (int)byte_8B16A4 );
  }
  else
  {
    v63 = 2 * v58;
    do
    {
      sub_530050((_DWORD *)this, v56, dword_8B1624, (int)v55, v46 >> 2, v57);
      sub_531830(v45, dword_8B1624);
      v47 = v63 + v45;
      sub_531830(v47, &unk_8B1724);
      v48 = v63 + v47;
      sub_531830(v48, &unk_8B1824);
      v45 = v63 + v48;
      ++v46;
    }
    while ( v46 < 12 );
  }
  if ( dword_8B0108 )
    _m_empty();
  return 0;
}
