int __usercall sub_4188D0@<eax>(
        char a1@<cl>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  _DWORD *v13; // ecx
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  int v17; // eax
  int v18; // edi
  char *v19; // ecx
  int v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // edx
  char *v24; // ebp
  int v25; // edi
  int v26; // edx
  char *v27; // ebp
  int v28; // ecx
  int v29; // ebx
  unsigned int v30; // edi
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int v44; // edx
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int *v50; // eax
  int v51; // edx
  int v52; // ecx
  int v53; // ecx
  int v54; // edx
  int v55; // ecx
  int v56; // edx
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // edx
  int v61; // ecx
  int v62; // edi
  _DWORD *v63; // eax
  _DWORD *v64; // ebp
  int v65; // eax
  int v66; // edi
  int v67; // ebp
  int v68; // ecx
  const char *v70; // [esp+301Ch] [ebp-2Ch]
  int v71; // [esp+3020h] [ebp-28h]
  _DWORD *v74; // [esp+3038h] [ebp-10h]
  _DWORD *v75; // [esp+3038h] [ebp-10h]
  int i; // [esp+303Ch] [ebp-Ch]
  int savedregs; // [esp+3048h] [ebp+0h] BYREF

  sub_631BD0(a1);
  v14 = v13;
  v13[3] = 105;
  v15 = operator new(0x106Cu);
  v74 = v15;
  STACK[0x607C] = 0;
  if ( v15 )
  {
    v16 = v15 + 1;
    *v15 = 105;
    sub_630A11(v15 + 1, 40, 105, sub_416860, nullsub_7);
  }
  else
  {
    v16 = 0;
  }
  v14[4] = v16;
  v17 = 0;
  STACK[0x607C] = -1;
  v18 = 0;
  v19 = (char *)&unk_925D08;
  do
  {
    v20 = v18 + v14[4];
    *(_DWORD *)(v20 + 32) = 7;
    *(_WORD *)(v20 + 8) = v17;
    *(_DWORD *)(v20 + 36) = v19 - 22616;
    v21 = v18 + v14[4] + 40;
    *(_DWORD *)(v21 + 32) = 7;
    *(_DWORD *)(v21 + 36) = v19;
    *(_WORD *)(v21 + 8) = v17 + 1;
    v22 = v18 + 80 + v14[4];
    *(_WORD *)(v22 + 8) = v17 + 2;
    *(_DWORD *)(v22 + 36) = v19 + 22616;
    *(_DWORD *)(v22 + 32) = 7;
    v23 = v18 + 120 + v14[4];
    v24 = v19 + 45232;
    *(_WORD *)(v23 + 8) = v17 + 3;
    v19 += 90464;
    v17 += 4;
    v18 += 160;
    *(_DWORD *)(v23 + 32) = 7;
    *(_DWORD *)(v23 + 36) = v24;
  }
  while ( (int)v19 < (int)dword_B640C8 );
  if ( v17 < v14[3] )
  {
    v25 = 40 * v17;
    v26 = 22616 * v17;
    do
    {
      v27 = (char *)off_757C18 + v26 - 2352048;
      v28 = v25 + v14[4];
      *(_WORD *)(v28 + 8) = v17;
      *(_DWORD *)(v28 + 32) = 7;
      *(_DWORD *)(v28 + 36) = v27;
      ++v17;
      v26 += 22616;
      v25 += 40;
    }
    while ( v17 < v14[3] );
  }
  v29 = sub_5DAB20(dword_FB1D04, a3, a4, &savedregs, a2, v74);
  v14[27] = 0;
  v14[24] = 0;
  v14[21] = 0;
  v14[18] = 0;
  v14[15] = 0;
  v14[12] = 0;
  v14[9] = 0;
  v14[5] = 0;
  v14[7] = 0;
  v75 = operator new(4 * v29 + 4);
  for ( i = 0; i < v29; ++i )
  {
    v30 = sub_5DAB30(i);
    v70 = (const char *)(v30 + 468);
    if ( (*(_DWORD *)v30 & 0x10) != 0 )
    {
      if ( !strncmp(v70, "DSPOLY", 6u) )
      {
        v31 = v14[5];
        *(&a13 + v31) = v30;
        v14[5] = v31 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "DSINDICATOR", 0xBu) )
      {
        v32 = v14[5];
        *(&a13 + v32) = v30;
        v14[5] = v32 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "DSCONE", 6u) )
      {
        v33 = v14[9];
        *(&STACK[0x3670] + v33) = v30;
        v14[9] = v33 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "CONE", 4u) )
      {
        v34 = v14[9];
        *(&STACK[0x3670] + v34) = v30;
        v14[9] = v34 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "POST", 4u) )
      {
        v35 = v14[12];
        *(&STACK[0x5470] + v35) = v30;
        v14[12] = v35 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "SIGN", 4u) )
      {
        v36 = v14[15];
        *(&STACK[0x4870] + v36) = v30;
        v14[15] = v36 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "WHEEL", 5u) )
      {
        v37 = v14[18];
        *(&STACK[0x3C70] + v37) = v30;
        v14[18] = v37 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "WING", 4u) )
      {
        v38 = v14[21];
        *(&STACK[0x4270] + v38) = v30;
        v14[21] = v38 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "PART", 4u) )
      {
        v39 = v14[24];
        *(&STACK[0x4E70] + v39) = v30;
        v14[24] = v39 + 1;
      }
      if ( !strncmp((const char *)(v30 + 468), "SHARD", 4u) )
      {
        v40 = v14[27];
        *(&STACK[0x5A70] + v40) = v30;
        v14[27] = v40 + 1;
      }
      sub_5EDA00(0, 0);
    }
    else if ( !strncmp(v70, "DSPOLY", 6u) )
    {
      v41 = v14[5];
      *(&a13 + v41) = v30;
      v14[5] = v41 + 1;
    }
    else if ( !strncmp((const char *)(v30 + 468), "DSINDICATOR", 0xBu) )
    {
      v42 = v14[5];
      *(&a13 + v42) = v30;
      v14[5] = v42 + 1;
    }
    else if ( (unsigned __int8)sub_5ED600(0)
           && v30 != dword_FAE624
           && v30 != dword_FAE628
           && v30 != dword_FAE62C
           && v30 != dword_FAE630
           && v30 != dword_FAE634 )
    {
      v75[v14[7]++] = v30;
    }
  }
  v43 = v14[24] + 840;
  v44 = v14[21] + 210;
  v14[18] += 420;
  v14[21] = v44;
  v14[24] = v43;
  if ( dword_FAE624 )
  {
    v45 = v14[5];
    *(&a13 + v45) = dword_FAE624;
    v14[5] = v45 + 1;
  }
  if ( dword_FAE628 )
  {
    v46 = v14[5];
    *(&a13 + v46) = dword_FAE628;
    v14[5] = v46 + 1;
  }
  if ( dword_FAE62C )
  {
    v47 = v14[5];
    *(&a13 + v47) = dword_FAE62C;
    v14[5] = v47 + 1;
  }
  if ( dword_FAE630 )
  {
    v48 = v14[5];
    *(&a13 + v48) = dword_FAE630;
    v14[5] = v48 + 1;
  }
  if ( dword_FAE634 )
  {
    v49 = v14[5];
    *(&a13 + v49) = dword_FAE634;
    v14[5] = v49 + 1;
  }
  if ( byte_B6FAB4 )
  {
    v50 = (int *)&unk_FAE63C;
    do
    {
      v51 = *(v50 - 1);
      if ( v51 )
      {
        v52 = v14[5];
        *(&a13 + v52) = v51;
        v14[5] = v52 + 1;
      }
      if ( *v50 )
      {
        v53 = v14[5];
        *(&a13 + v53) = *v50;
        v14[5] = v53 + 1;
      }
      v54 = v50[1];
      if ( v54 )
      {
        v55 = v14[5];
        *(&a13 + v55) = v54;
        v14[5] = v55 + 1;
      }
      v56 = v50[2];
      if ( v56 )
      {
        v57 = v14[5];
        *(&a13 + v57) = v56;
        v14[5] = v57 + 1;
      }
      v58 = v50[3];
      if ( v58 )
      {
        v59 = v14[5];
        *(&a13 + v59) = v58;
        v14[5] = v59 + 1;
      }
      v60 = v50[4];
      if ( v60 )
      {
        v61 = v14[5];
        *(&a13 + v61) = v60;
        v14[5] = v61 + 1;
      }
      v50 += 6;
    }
    while ( (int)v50 < (int)dword_FAE684 );
  }
  v62 = v14[5];
  v63 = operator new(40 * v62 + 4);
  STACK[0x607C] = 1;
  if ( v63 )
  {
    v64 = v63 + 1;
    *v63 = v62;
    sub_630A11(v63 + 1, 40, v62, sub_416860, nullsub_7);
  }
  else
  {
    v64 = 0;
  }
  v65 = v14[5];
  v66 = 0;
  STACK[0x607C] = -1;
  v14[6] = v64;
  if ( v65 > 0 )
  {
    v67 = 0;
    do
    {
      v68 = v67 + v14[6];
      v71 = *(&a13 + v66);
      *(_WORD *)(v68 + 8) = v66;
      *(_DWORD *)(v68 + 32) = 8;
      *(_DWORD *)(v68 + 36) = v71;
      sub_417E90((_DWORD *)v68, v71, 0);
      ++v66;
      v67 += 40;
    }
    while ( v66 < v14[5] );
  }
  return off_16C95A4();
}
