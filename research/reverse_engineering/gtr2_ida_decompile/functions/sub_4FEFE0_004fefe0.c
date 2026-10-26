void __thiscall sub_4FEFE0(int this, int a2)
{
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // esi
  int v8; // esi
  int v9; // edi
  int *v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // edi
  bool v14; // cc
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ebp
  unsigned __int64 v23; // rax
  int v24; // esi
  int v25; // edi
  int v26; // esi
  int v27; // esi
  int v28; // edi
  int v29; // edi
  int v30; // esi
  int v31; // esi
  int v32; // edi
  int v33; // edi
  int v34; // esi
  int v35; // edi
  int v36; // edi
  _DWORD *v37; // ecx
  _DWORD *v38; // ecx
  _DWORD *v39; // edi
  int v40; // ecx
  char v41; // al
  int v42; // eax
  int v43; // ebx
  _DWORD *v44; // [esp-4h] [ebp-1Ch]
  int v45; // [esp+10h] [ebp-8h]
  _DWORD *v46; // [esp+14h] [ebp-4h]
  int *v47; // [esp+1Ch] [ebp+4h]
  char v48; // [esp+1Ch] [ebp+4h]

  qmemcpy((void *)(this + 152), (const void *)(a2 + 3312), 0x40u);
  *(_BYTE *)(this + 181) = 0;
  *(_DWORD *)(this + 172) = *(_DWORD *)(a2 + 6404);
  qmemcpy((void *)(this + 408), (const void *)(a2 + 4784), 0x40u);
  *(_DWORD *)(this + 432) = *(_DWORD *)(this + 428);
  *(_BYTE *)(this + 437) = 1;
  v4 = sub_560950(&dword_FAE908, a2 + 112);
  v5 = *(_DWORD *)(this + 668);
  *(_DWORD *)(this + 664) = v4;
  if ( v5 >= 0 )
  {
LABEL_6:
    v6 = *(_DWORD *)dword_B640C8;
    goto LABEL_7;
  }
  v6 = *(_DWORD *)dword_B640C8;
  if ( *(int *)dword_B640C8 >= 3 && *(int *)dword_B640C8 <= 6 )
  {
    v7 = *(_DWORD *)(a2 + 3012);
    if ( !*(_BYTE *)(sub_560800(v7) + 20) )
      *(_DWORD *)(this + 668) = v7;
    goto LABEL_6;
  }
LABEL_7:
  if ( *(int *)(this + 672) < 0 && v6 >= 3 && v6 <= 6 )
  {
    v8 = *(_DWORD *)(a2 + 3076);
    if ( !*(_BYTE *)(sub_560800(v8) + 20) )
      *(_DWORD *)(this + 672) = v8;
  }
  sub_4FD540();
  v9 = 3;
  v10 = (int *)(this + 236);
  v45 = 3;
  v47 = (int *)(this + 236);
  do
  {
    v11 = *(v10 - 1);
    v12 = 0;
    *v10 = 0;
    if ( v11 > 0 )
    {
      v46 = (_DWORD *)(((v9 != 3) << 6) + a2 + 3012);
      do
      {
        if ( v12 <= 0 || v12 - 1 >= *(_DWORD *)(*(_DWORD *)(this + 664) + 16) )
          v13 = 0;
        else
          v13 = sub_560800(v12 - 1);
        if ( v13 == sub_560800(*v46) )
          break;
        ++v12;
      }
      while ( v12 < *(v47 - 1) );
      v10 = v47;
      v9 = v45;
    }
    v14 = v12 < *(v10 - 1);
    *v10 = v12;
    if ( !v14 )
      *v10 = 1;
    ++v9;
    v10 += 16;
    v45 = v9;
    v47 = v10;
  }
  while ( v9 <= 4 );
  if ( *(_BYTE *)(*(_DWORD *)this + 21676) )
    *(_DWORD *)(this + 40) = 2;
  else
    *(_DWORD *)(this + 40) = 1;
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 48) = 0;
  v44 = *(_DWORD **)(this + 12);
  *(_DWORD *)(this + 104) = 1;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 112) = 0;
  sub_4FBE60((_DWORD *)this, v44);
  *(_DWORD *)(this + 360) = 1;
  *(_DWORD *)(this + 364) = 0;
  *(_DWORD *)(this + 368) = 0;
  *(_DWORD *)(this + 424) = 1;
  *(_DWORD *)(this + 428) = 0;
  *(_DWORD *)(this + 432) = 0;
  *(_DWORD *)(this + 488) = 1;
  *(_DWORD *)(this + 492) = 0;
  *(_DWORD *)(this + 496) = 0;
  *(_DWORD *)(this + 552) = 1;
  *(_DWORD *)(this + 556) = 0;
  *(_DWORD *)(this + 560) = 0;
  *(_DWORD *)(this + 616) = 1;
  *(_DWORD *)(this + 620) = 0;
  *(_DWORD *)(this + 624) = 0;
  *(_DWORD *)(this + 676) = *(_DWORD *)(a2 + 6340);
  *(float *)(this + 744) = *(double *)(a2 + 6936);
  if ( *(double *)(a2 + 6936) == 0.0 )
  {
    v15 = *(_DWORD *)(a2 + 6404);
    *(_DWORD *)(this + 680) = 1024;
    *(_DWORD *)(this + 684) = v15;
    v16 = *(_DWORD *)(a2 + 6468);
    *(_DWORD *)(this + 688) = 2048;
    *(_DWORD *)(this + 692) = v16;
    v17 = *(_DWORD *)(a2 + 6532);
    *(_DWORD *)(this + 696) = 3072;
    *(_DWORD *)(this + 700) = v17;
    v18 = *(_DWORD *)(a2 + 6596);
    *(_DWORD *)(this + 704) = 4096;
    *(_DWORD *)(this + 708) = v18;
    v19 = *(_DWORD *)(a2 + 6660);
    *(_DWORD *)(this + 712) = 5120;
    *(_DWORD *)(this + 716) = v19;
    v20 = *(_DWORD *)(a2 + 6724);
    *(_DWORD *)(this + 720) = 6144;
    *(_DWORD *)(this + 724) = v20;
    v21 = *(_DWORD *)(a2 + 6788);
    *(_DWORD *)(this + 728) = 7169;
    *(_DWORD *)(this + 732) = v21;
    v22 = *(_DWORD *)(a2 + 6852);
    *(_DWORD *)(this + 736) = 0x2000;
    *(_DWORD *)(this + 740) = v22;
  }
  else
  {
    v23 = (unsigned __int64)(((double)*(int *)(a2 + 3332) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312))
                           * *(double *)(a2 + 6936));
    v24 = dword_B72230;
    *(_DWORD *)(this + 684) = *(_DWORD *)(a2 + 6404);
    v25 = v23 - v24;
    *(_DWORD *)(this + 680) = v23 - v24;
    v26 = (unsigned __int64)(((double)*(int *)(a2 + 6404) * *(double *)(a2 + 6392) + *(double *)(a2 + 6384))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 692) = *(_DWORD *)(a2 + 6468);
    v27 = v25 + v26;
    *(_DWORD *)(this + 688) = v27;
    v28 = (unsigned __int64)(((double)*(int *)(a2 + 6468) * *(double *)(a2 + 6456) + *(double *)(a2 + 6448))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 700) = *(_DWORD *)(a2 + 6532);
    v29 = v27 + v28;
    *(_DWORD *)(this + 696) = v29;
    v30 = (unsigned __int64)(((double)*(int *)(a2 + 6532) * *(double *)(a2 + 6520) + *(double *)(a2 + 6512))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 708) = *(_DWORD *)(a2 + 6596);
    v31 = v29 + v30;
    *(_DWORD *)(this + 704) = v31;
    v32 = (unsigned __int64)(((double)*(int *)(a2 + 6596) * *(double *)(a2 + 6584) + *(double *)(a2 + 6576))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 716) = *(_DWORD *)(a2 + 6660);
    v33 = v31 + v32;
    *(_DWORD *)(this + 712) = v33;
    v34 = v33
        + (unsigned __int64)(((double)*(int *)(a2 + 6660) * *(double *)(a2 + 6648) + *(double *)(a2 + 6640))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 724) = *(_DWORD *)(a2 + 6724);
    *(_DWORD *)(this + 720) = v34;
    v35 = (unsigned __int64)(((double)*(int *)(a2 + 6724) * *(double *)(a2 + 6712) + *(double *)(a2 + 6704))
                           * *(double *)(a2 + 6936))
        - dword_B72230;
    *(_DWORD *)(this + 732) = *(_DWORD *)(a2 + 6788);
    v36 = v34 + v35;
    *(_DWORD *)(this + 728) = v36;
    LODWORD(v23) = v36
                 + (unsigned __int64)(((double)*(int *)(a2 + 6788) * *(double *)(a2 + 6776) + *(double *)(a2 + 6768))
                                    * *(double *)(a2 + 6936))
                 - dword_B72230;
    *(_DWORD *)(this + 740) = *(_DWORD *)(a2 + 6852);
    *(_DWORD *)(this + 736) = v23;
  }
  v37 = *(_DWORD **)(this + 12);
  *(_DWORD *)(this + 752) = 0;
  *(_DWORD *)(this + 756) = 0;
  *(_DWORD *)(this + 760) = 0;
  if ( v37 )
    sub_4F7EC0(v37, *(_DWORD *)dword_B640C8 == 0, 0);
  v38 = *(_DWORD **)(this + 16);
  if ( v38 )
    sub_4F7EC0(v38, 0, 0);
  v39 = *(_DWORD **)(this + 12);
  if ( v39 )
  {
    v40 = *(_DWORD *)(this + 8);
    if ( v39 != (_DWORD *)v40 )
    {
      v41 = 0;
      if ( !v40 )
        goto LABEL_42;
      v42 = *(_DWORD *)(this + 752);
      if ( (v42 != 3 || !*(_BYTE *)(this + 765)) && v42 != 4 )
      {
        v48 = *(_BYTE *)(v40 + 12) & 1;
        sub_4F7EC0((_DWORD *)v40, 0, 0);
        v41 = v48;
LABEL_42:
        *(_DWORD *)(this + 8) = v39;
        if ( v41 )
          sub_4FA870((int)v39, 0, 0);
        else
          sub_4F7EC0(v39, 0, 0);
      }
    }
  }
  if ( *(_DWORD *)this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0)
    && *(_DWORD *)dword_B640C8 == 6
    && (!(unsigned __int8)sub_4735A0() || !byte_B6F118) )
  {
    v43 = *(_DWORD *)(this + 8);
    if ( v43 )
      sub_4F7F70(v43);
  }
  dword_B6F52C = 0;
}
