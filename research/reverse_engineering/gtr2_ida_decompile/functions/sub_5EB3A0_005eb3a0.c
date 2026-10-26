int __userpurge sub_5EB3A0@<eax>(char *a1@<ecx>, int a2@<ebx>, _DWORD *a3, int a4)
{
  int v5; // edi
  int v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char v11; // dl
  int v12; // eax
  int v13; // eax
  int v14; // eax
  char v15; // dl
  int v16; // eax
  int v17; // eax
  int v18; // eax
  _DWORD *v19; // esi
  int v20; // eax
  int v21; // ecx
  int *v22; // eax
  int v23; // ecx
  size_t v24; // esi
  char *v25; // eax
  int v26; // ecx
  int v27; // edx
  char *v28; // edx
  int v29; // eax
  _DWORD *v30; // ecx
  char *v31; // esi
  _DWORD *v32; // eax
  int v33; // edx
  int v34; // edi
  int v35; // ecx
  int v36; // eax
  int v37; // esi
  _DWORD *v38; // eax
  int v39; // ecx
  int v40; // esi
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  unsigned int v44; // ecx
  int v45; // edx
  int v46; // eax
  int v47; // ecx
  int v48; // edx
  int v49; // eax
  char v51; // al
  int v52; // eax
  int **v53; // eax
  int v54; // edx
  int v55; // eax
  _DWORD *v56; // eax
  int *v57; // eax
  int v58; // ecx
  _DWORD *v59; // eax
  char v60; // [esp+0h] [ebp-30h]
  int v61; // [esp+10h] [ebp-20h]
  int v62; // [esp+10h] [ebp-20h]
  int v63; // [esp+14h] [ebp-1Ch]
  int v64; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  _DWORD *v66; // [esp+1Ch] [ebp-14h]
  char *v67; // [esp+20h] [ebp-10h]
  char *Block; // [esp+24h] [ebp-Ch]
  void *Blocka; // [esp+24h] [ebp-Ch]
  void *Blockb; // [esp+24h] [ebp-Ch]
  _DWORD *v71; // [esp+28h] [ebp-8h]
  int v72; // [esp+2Ch] [ebp-4h] BYREF
  _DWORD *v73; // [esp+38h] [ebp+8h]
  unsigned int v74; // [esp+38h] [ebp+8h]
  int v75; // [esp+38h] [ebp+8h]

  v5 = (int)&a1[a4 + *((_DWORD *)a1 + 91)];
  v6 = (int)&a1[a4 + *((_DWORD *)a1 + 93)];
  v7 = (int)&a1[a4 + *((_DWORD *)a1 + 95)];
  *((_DWORD *)a1 + 97) += &a1[a4];
  v67 = &a1[a4];
  *((_DWORD *)a1 + 91) = v5;
  *((_DWORD *)a1 + 93) = v6;
  *((_DWORD *)a1 + 95) = v7;
  v66 = sub_5EA670(a1);
  for ( i = 0; i < *((_DWORD *)a1 + 90); ++i )
  {
    a2 = 108 * i;
    v8 = 108 * i + *((_DWORD *)a1 + 91);
    if ( (*(_BYTE *)v8 & 1) != 0 )
      *(_DWORD *)(v8 + 12) += v67;
    v9 = a2 + *((_DWORD *)a1 + 91);
    if ( (*(_BYTE *)v9 & 2) != 0 )
      *(_DWORD *)(v9 + 16) += v67;
    v10 = *((_DWORD *)a1 + 91);
    v11 = *(_BYTE *)(v10 + 108 * i);
    v12 = a2 + v10;
    if ( (v11 & 4) != 0 )
      *(_DWORD *)(v12 + 28) += v67;
    v13 = a2 + *((_DWORD *)a1 + 91);
    if ( (*(_BYTE *)v13 & 0x10) != 0 )
      *(_DWORD *)(v13 + 20) += v67;
    v14 = *((_DWORD *)a1 + 91);
    v15 = *(_BYTE *)(v14 + 108 * i);
    v16 = a2 + v14;
    if ( (v15 & 0x20) != 0 )
      *(_DWORD *)(v16 + 24) += v67;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 40) += v67;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 104) = a1;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 96) = 0;
    v17 = sub_5E9300(a3, *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4));
    if ( (**(_DWORD **)(*((_DWORD *)a1 + 98) + 620) & 0x10000000) != 0 )
    {
      v18 = sub_5E9070((int)&unk_FB27F8, v17, dword_FB27B0, 0);
      v19 = (_DWORD *)v18;
      v73 = (_DWORD *)v18;
      if ( !v18 )
      {
        sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Ghost material global/local mismatch.", v60);
LABEL_127:
        sub_5D8CE0();
        return -1;
      }
      *(_DWORD *)a1 |= 0x40000000u;
      if ( !strstr((const char *)(v18 + 4), "SCREEN_DIRT") )
      {
        *v19 |= 0x40000u;
        sub_5E9620(5, 6);
      }
      if ( !strcmp((const char *)sub_5E8320(v73, 99), "L0NOLIGHTINGT0") )
        sub_5E8D90(v73, 99, "L0DIFFUSET0");
    }
    else
    {
      v73 = (_DWORD *)sub_5E9070((int)&unk_FB27F8, v17, 0, 0x40000);
      if ( !v73 )
      {
        sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Material global/local mismatch.", v60);
        goto LABEL_127;
      }
    }
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) = v73;
    *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x80000;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 612))(dword_FB27A4, a2 + *((_DWORD *)a1 + 91));
    v20 = *((_DWORD *)a1 + 91);
    v21 = *(_DWORD *)(v20 + a2 + 88);
    v22 = (int *)(a2 + v20);
    if ( !v21 )
    {
      v51 = (unsigned __int8)sub_5E8320(*(_DWORD **)(108 * i + *((_DWORD *)a1 + 91) + 4), 99);
      sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Could not find shader %s for mesh %s", v51);
      sub_5D8CE0();
      return -1;
    }
    v23 = *v22;
    v24 = 0;
    v74 = 0;
    if ( (*v22 & 1) != 0 )
    {
      v24 = 32 * v22[2];
      v74 = v24;
    }
    if ( (v23 & 2) != 0 )
    {
      v24 += 16 * v22[2];
      v74 = v24;
    }
    if ( (v23 & 4) != 0 )
    {
      v24 += 24 * v22[2];
      v74 = v24;
    }
    if ( (v23 & 0x10) != 0 )
    {
      v24 += 32 * v22[2];
      v74 = v24;
    }
    if ( (v23 & 0x20) != 0 )
    {
      v24 += 32 * v22[2];
      v74 = v24;
    }
    v25 = (char *)operator new(v24);
    v26 = *((_DWORD *)a1 + 91);
    v27 = *(_DWORD *)(a2 + v26 + 8);
    Block = v25;
    v61 = 0;
    if ( (*(_BYTE *)(v26 + 108 * i) & 4) != 0 )
    {
      if ( v27 > 0 )
      {
        v28 = v25 + 56;
        v29 = 0;
        v63 = 0;
        do
        {
          qmemcpy(v28 - 56, (const void *)(v29 + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 12)), 0x20u);
          v30 = (_DWORD *)(v63 + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 28));
          v31 = v28 - 24;
          *(_DWORD *)v31 = *v30;
          *((_DWORD *)v31 + 1) = v30[1];
          *((_DWORD *)v31 + 2) = v30[2];
          *((_DWORD *)v31 + 3) = v30[3];
          *((_DWORD *)v31 + 4) = v30[4];
          *((_DWORD *)v31 + 5) = v30[5];
          qmemcpy(v28, (const void *)(v29 + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 20)), 0x20u);
          v28 += 88;
          v63 += 24;
          v29 += 32;
          ++v61;
        }
        while ( v61 < *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8) );
      }
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 32) = *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 12);
      qmemcpy(*(void **)(a2 + *((_DWORD *)a1 + 91) + 32), Block, v74);
      j__free(Block);
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 8;
      if ( v66 )
      {
        v32 = v66;
        v66[15] += *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8);
        goto LABEL_44;
      }
      *(_DWORD *)(*((_DWORD *)a1 + 98) + 60) += *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8);
    }
    else
    {
      if ( v27 > 0 )
      {
        v33 = 0;
        do
        {
          qmemcpy(v25, (const void *)(v33 + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 12)), 0x20u);
          qmemcpy(v25 + 32, (const void *)(v33 + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 20)), 0x20u);
          v25 += 64;
          v33 += 32;
          ++v61;
        }
        while ( v61 < *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8) );
      }
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 32) = *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 12);
      qmemcpy(*(void **)(a2 + *((_DWORD *)a1 + 91) + 32), Block, v74);
      j__free(Block);
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x40;
      if ( v66 )
      {
        v32 = v66;
        v66[14] += *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8);
        goto LABEL_44;
      }
      *(_DWORD *)(*((_DWORD *)a1 + 98) + 56) += *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 8);
    }
    v32 = (_DWORD *)*((_DWORD *)a1 + 98);
LABEL_44:
    v32[17] += *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 36);
    *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) & 0xFFFFFFC8;
    v34 = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 12) = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 16) = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 28) = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 20) = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 24) = 0;
    if ( (*a1 & 0x20) != 0 )
    {
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x20000000;
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 80) = 4;
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 84) = *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 36) / 3;
    }
    else
    {
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 80) = 5;
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 84) = *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 36) - 2;
    }
    v75 = 256;
    if ( (**((_BYTE **)a1 + 98) & 0x10) != 0 )
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x8000;
    v35 = **(_DWORD **)(*((_DWORD *)a1 + 91) + a2 + 4);
    if ( (v35 & 0x20) != 0 )
      v75 = 2304;
    if ( (v35 & 0x800) != 0 )
      v75 |= 4u;
    if ( (v35 & 0x40) != 0 )
      v75 |= 0x400u;
    v64 = sub_5F7BF0(0);
    v71 = *(_DWORD **)(a2 + *((_DWORD *)a1 + 91) + 4);
    v62 = sub_5E8220(v71, 99);
    Blocka = (void *)sub_5E82A0(v71, 99);
    if ( v62 < (int)Blocka + sub_5E8220(v71, 99) )
    {
      do
      {
        v36 = sub_5E80D0(*(_DWORD **)(a2 + *((_DWORD *)a1 + 91) + 4), v62);
        v37 = v36;
        if ( *(int *)(v36 + 4) <= 1 || *(_DWORD *)(v36 + 84) == 6 )
          *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 92) = 0;
        else
          *(_DWORD *)a1 |= 0x80u;
        if ( *(char *)v36 < 0 )
          v75 |= 1u;
        if ( (*(_BYTE *)(v36 + 96) & 2) != 0 )
          v75 &= ~0x400u;
        if ( v64 && v34 < *(_DWORD *)(v64 + 340) )
        {
          if ( *(_DWORD *)(sub_5F6520(v34) + 216) == 1 )
            *(_DWORD *)(v37 + 140) = 1;
          else
            *(_DWORD *)(v37 + 140) = *(_DWORD *)(sub_5F6520(v34) + 216) != 2 ? 0 : 2;
          if ( *(_DWORD *)(sub_5F6520(v34) + 220) == 1 )
            *(_DWORD *)(v37 + 144) = 1;
          else
            *(_DWORD *)(v37 + 144) = *(_DWORD *)(sub_5F6520(v34) + 220) != 2 ? 0 : 2;
          if ( *(_DWORD *)(sub_5F6520(v34) + 224) == 1 )
            *(_DWORD *)(v37 + 148) = 1;
          else
            *(_DWORD *)(v37 + 148) = *(_DWORD *)(sub_5F6520(v34) + 224) != 2 ? 0 : 2;
          *(_BYTE *)(v37 + 129) = *(_BYTE *)(sub_5F6520(v34) + 238) != 0;
          *(_BYTE *)(v37 + 128) = *(_BYTE *)(sub_5F6520(v34++) + 236) != 0;
        }
        ++v62;
        Blockb = (void *)sub_5E82A0(v71, 99);
      }
      while ( v62 < (int)Blockb + sub_5E8220(v71, 99) );
    }
    if ( sub_5E9420(*(char **)(a2 + *((_DWORD *)a1 + 91) + 4)) )
    {
      sub_5D8C80(
        (int)a1,
        (char *)0xFFFFFFFF,
        "Error loading global material %s",
        *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91) + 4) + 4);
      sub_5D8CE0();
      return -1;
    }
    if ( (**(_DWORD **)(*((_DWORD *)a1 + 98) + 620) & 0x10000000) != 0 )
    {
      v75 |= 0x801u;
      v38 = (_DWORD *)sub_5E80D0(*(_DWORD **)(a2 + *((_DWORD *)a1 + 91) + 4), 0);
      sub_5E2A20(v38, 3);
    }
    sub_5E8870(*(_DWORD **)(a2 + *((_DWORD *)a1 + 91) + 4), v75, 0);
    v39 = *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4);
    v40 = *(_DWORD *)v39 & 0x10120;
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 3) & 0x10) != 0
      && (*(_DWORD *)v39 & 0x20000) == 0
      && !strstr((const char *)(v39 + 4), "BACKFIRE")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "HEADLIGHT")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "BRAKELIGHT")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "RAINLIGHT")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "SCREEN_DIRT")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "RAIN_ANIM")
      && !strstr((const char *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 4), "INTERIOR_BANNER") )
    {
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 5;
      *(_DWORD *)a1 |= 0x100u;
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x80000000;
      if ( !*(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 88) + 704) )
      {
        ++dword_FB2814;
        *(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 88) + 704) = 1;
      }
      *(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 201) = 0;
      sub_5F7C20(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4), 4);
      *(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4) + 201) = 0;
      goto LABEL_107;
    }
    if ( !v40 )
    {
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 2;
      goto LABEL_96;
    }
    if ( v40 > 288 )
    {
      if ( v40 != 65568 )
        goto LABEL_107;
      *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 4;
      v43 = a2 + *((_DWORD *)a1 + 91);
      *(_DWORD *)a1 |= 0x10000100u;
      if ( (**(_DWORD **)(v43 + 4) & 0x20000) == 0 )
        goto LABEL_107;
      v44 = *(_DWORD *)v43 | 0x80000000;
      goto LABEL_106;
    }
    switch ( v40 )
    {
      case 288:
        *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 1;
        *(_DWORD *)a1 |= 0x110u;
        break;
      case 32:
        *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 3;
        *(_DWORD *)a1 |= 0x100u;
        break;
      case 256:
        *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) = 0;
        *(_DWORD *)a1 |= 0x10u;
LABEL_96:
        v41 = *((_DWORD *)a1 + 91);
        v42 = *(_DWORD *)(v41 + 108 * i);
        v43 = a2 + v41;
        v44 = v42 | 0x100;
LABEL_106:
        *(_DWORD *)v43 = v44;
        break;
    }
LABEL_107:
    v45 = *((_DWORD *)a1 + 91);
    v46 = *(_DWORD *)(a2 + v45 + 76);
    if ( !*(_BYTE *)(*(_DWORD *)(a2 + v45 + 88) + v46 + 700) )
    {
      ++dword_FB2804[v46];
      *(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 88) + *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76) + 700) = 1;
    }
    _strupr(a1 + 400);
    sub_5F7C20(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 4), *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 76));
    sub_5E8E90(*(_DWORD **)(a2 + *((_DWORD *)a1 + 91) + 4));
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 44) = 0;
    *(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 48) = 0;
    if ( (**(_DWORD **)(*((_DWORD *)a1 + 98) + 620) & 0x10000000) != 0
      && !*(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 88) + 809) )
    {
      *((_BYTE *)dword_FB27AC + 201) = 0;
      sub_5F7C20(dword_FB27AC, 4);
      *(_BYTE *)(*(_DWORD *)(a2 + *((_DWORD *)a1 + 91) + 88) + 809) = 1;
    }
    if ( (*(_DWORD *)a1 & 0x8000000) != 0 )
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x400000;
    if ( (*(_DWORD *)a1 & 0x20000000) != 0 )
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x10000000;
    sub_5E8580(*(float **)(a2 + *((_DWORD *)a1 + 91) + 4), 4, &v72);
    if ( ((unsigned int)byte_FFFFFF & v72) != 0 )
      *(_DWORD *)(108 * i + *((_DWORD *)a1 + 91)) = *(_DWORD *)(*((_DWORD *)a1 + 91) + 108 * i) | 0x40000;
  }
  v47 = 0;
  if ( *((int *)a1 + 92) > 0 )
  {
    v48 = 0;
    do
    {
      a2 = *((_DWORD *)a1 + 91);
      *(_DWORD *)(v48 + *((_DWORD *)a1 + 93) + 8) = a2 + 108 * *(_DWORD *)(v48 + *((_DWORD *)a1 + 93) + 8);
      ++v47;
      v48 += 36;
    }
    while ( v47 < *((_DWORD *)a1 + 92) );
  }
  v49 = *(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 0x100) == 0 )
  {
    if ( (v49 & 0x10) != 0 )
    {
      *((_DWORD *)a1 + 119) = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 152;
      goto LABEL_139;
    }
    v52 = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 92;
    goto LABEL_138;
  }
  if ( (v49 & 0x40000000) == 0 )
  {
    if ( (v49 & 0x10000000) != 0 )
    {
      *((_DWORD *)a1 + 119) = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 172;
      goto LABEL_139;
    }
    if ( (v49 & 0x10) == 0 )
    {
      *((_DWORD *)a1 + 119) = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 132;
      goto LABEL_139;
    }
    v52 = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 112;
LABEL_138:
    *((_DWORD *)a1 + 119) = v52;
    goto LABEL_139;
  }
  *((_DWORD *)a1 + 119) = *(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 192;
LABEL_139:
  ++*(_DWORD *)(*((_DWORD *)a1 + 119) + 8);
  if ( *a1 < 0 )
  {
    v53 = *(int ***)(*(_DWORD *)(*((_DWORD *)a1 + 98) + 620) + 516);
    if ( !v53 )
      goto LABEL_146;
    while ( !*v53 || *v53 != (int *)a1 )
    {
      v53 = (int **)v53[1];
      if ( !v53 )
        goto LABEL_146;
    }
    if ( !*v53 )
LABEL_146:
      sub_5FDFB0(a1, 0);
  }
  if ( (*(_DWORD *)a1 & 0x4000000) == 0 )
    goto LABEL_165;
  v54 = *((_DWORD *)a1 + 98);
  if ( *(_DWORD *)(v54 + 624) )
    goto LABEL_165;
  v55 = *(_DWORD *)(v54 + 620);
  if ( (*(_BYTE *)v54 & 0x10) != 0 )
  {
    v56 = *(_DWORD **)(v55 + 468);
    if ( v56 )
    {
      while ( !*v56 || *v56 != v54 )
      {
        v56 = (_DWORD *)v56[1];
        if ( !v56 )
          goto LABEL_156;
      }
      if ( *v56 )
        goto LABEL_165;
    }
LABEL_156:
    sub_5FDFB0(v54, 0);
    v57 = (int *)*((_DWORD *)a1 + 98);
    v58 = *v57 | 0x8000000;
  }
  else
  {
    v59 = *(_DWORD **)(v55 + 484);
    if ( v59 )
    {
      while ( !*v59 || *v59 != v54 )
      {
        v59 = (_DWORD *)v59[1];
        if ( !v59 )
          goto LABEL_163;
      }
      if ( *v59 )
        goto LABEL_165;
    }
LABEL_163:
    sub_5FDFB0(v54, 0);
    v57 = (int *)*((_DWORD *)a1 + 98);
    v58 = *v57 | 0x4000000;
  }
  *v57 = v58;
LABEL_165:
  qmemcpy(a1 + 120, a1 + 24, 0x60u);
  *((_DWORD *)a1 + 117) = 0;
  sub_5D8DD0((int)a1, a2, 0);
  *((_DWORD *)a1 + 62) = 6;
  return 0;
}
