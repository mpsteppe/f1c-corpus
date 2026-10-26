char __thiscall sub_4F5FB0(char *this, int a2)
{
  int v4; // eax
  _DWORD *v5; // eax
  bool v6; // al
  _DWORD *v7; // edx
  _DWORD *v8; // eax
  float *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // edx
  int v34; // ecx
  int v35; // esi
  _DWORD *v36; // eax
  _DWORD *v37; // ecx
  int *v38; // ecx
  int v39; // edi
  int v40; // esi
  int v41; // eax
  int v42; // edx
  _DWORD *v43; // ecx
  bool v44; // sf
  bool v45; // cc
  int v47; // [esp+8h] [ebp-20h]
  int v48; // [esp+10h] [ebp-18h]
  int *v49; // [esp+14h] [ebp-14h]
  int v50; // [esp+18h] [ebp-10h] BYREF
  int v51; // [esp+1Ch] [ebp-Ch]
  int v52; // [esp+20h] [ebp-8h]
  int v53; // [esp+24h] [ebp-4h]
  int v54; // [esp+2Ch] [ebp+4h]

  *(_BYTE *)a2 = this[8];
  LOBYTE(v4) = this[8];
  if ( !(_BYTE)v4 )
    return v4;
  v5 = (_DWORD *)*((_DWORD *)this + 34);
  if ( v5 )
    v6 = (*v5 & 4) == 0;
  else
    v6 = 0;
  *(_BYTE *)(a2 + 1) = v6;
  *(_BYTE *)(a2 + 2) = this[12];
  *(_BYTE *)(a2 + 3) = this[13];
  *(_BYTE *)(a2 + 4) = this[14];
  *(_DWORD *)(a2 + 8) = *((_DWORD *)this + 21);
  *(_DWORD *)(a2 + 12) = *((_DWORD *)this + 22);
  *(_DWORD *)(a2 + 16) = *((_DWORD *)this + 23);
  *(_DWORD *)(a2 + 20) = *((_DWORD *)this + 24);
  *(_DWORD *)(a2 + 24) = *((_DWORD *)this + 25);
  *(_DWORD *)(a2 + 28) = *((_DWORD *)this + 26);
  *(_DWORD *)(a2 + 32) = *((_DWORD *)this + 30);
  *(_DWORD *)(a2 + 36) = *((_DWORD *)this + 31);
  *(_DWORD *)(a2 + 40) = *((_DWORD *)this + 32);
  *(_DWORD *)(a2 + 44) = *((_DWORD *)this + 33);
  if ( (*(_DWORD *)this == 7 || *(_DWORD *)this == 8) && (v7 = (_DWORD *)*((_DWORD *)this + 58), *v7) )
  {
    v8 = (_DWORD *)(*v7 + 52);
    *(_DWORD *)(a2 + 48) = *v8;
    *(_DWORD *)(a2 + 52) = v8[1];
    *(_DWORD *)(a2 + 56) = v8[2];
    v9 = (float *)(**((_DWORD **)this + 58) + 4);
  }
  else
  {
    v13 = *((_DWORD *)this + 35);
    if ( !v13 )
    {
      v15 = *((_DWORD *)this + 34);
      if ( v15 )
      {
        v16 = (_DWORD *)(v15 + 124);
        *(_DWORD *)(a2 + 48) = *v16;
        *(_DWORD *)(a2 + 52) = v16[1];
        *(_DWORD *)(a2 + 56) = v16[2];
        sub_4F1560((float *)&v50, (float *)(*((_DWORD *)this + 34) + 76));
        v17 = v51;
        v18 = v52;
        *(_DWORD *)(a2 + 64) = v50;
        v19 = v53;
        *(_DWORD *)(a2 + 68) = v17;
        *(_DWORD *)(a2 + 72) = v18;
        *(_DWORD *)(a2 + 60) = v19;
      }
      else
      {
        *(_DWORD *)(a2 + 48) = 0;
        *(_DWORD *)(a2 + 52) = 0;
        *(_DWORD *)(a2 + 56) = 0;
        *(_DWORD *)(a2 + 72) = 0;
        *(_DWORD *)(a2 + 68) = 0;
        *(_DWORD *)(a2 + 64) = 0;
        *(_DWORD *)(a2 + 60) = 1065353216;
      }
      goto LABEL_15;
    }
    v14 = (_DWORD *)(*(_DWORD *)(v13 + 8) + 116);
    *(_DWORD *)(a2 + 48) = *v14;
    *(_DWORD *)(a2 + 52) = v14[1];
    *(_DWORD *)(a2 + 56) = v14[2];
    v9 = (float *)(*(_DWORD *)(*((_DWORD *)this + 35) + 8) + 68);
  }
  sub_4F1560((float *)&v50, v9);
  v10 = v51;
  v11 = v52;
  *(_DWORD *)(a2 + 64) = v50;
  v12 = v53;
  *(_DWORD *)(a2 + 68) = v10;
  *(_DWORD *)(a2 + 72) = v11;
  *(_DWORD *)(a2 + 60) = v12;
LABEL_15:
  v20 = *((_DWORD *)this + 1);
  v21 = *(_DWORD *)(v20 + 288);
  v22 = 0;
  if ( v21 <= 0 )
  {
LABEL_19:
    v22 = -1;
  }
  else
  {
    v23 = *(_DWORD *)(v20 + 292);
    while ( v23 != *((_DWORD *)this + 48) )
    {
      ++v22;
      v23 += 768;
      if ( v22 >= v21 )
        goto LABEL_19;
    }
  }
  *(_DWORD *)(a2 + 76) = v22;
  v24 = *((_DWORD *)this + 1);
  v25 = *(_DWORD *)(v24 + 288);
  v26 = 0;
  if ( v25 <= 0 )
  {
LABEL_24:
    v26 = -1;
  }
  else
  {
    v27 = *(_DWORD *)(v24 + 292);
    while ( v27 != *((_DWORD *)this + 49) )
    {
      ++v26;
      v27 += 768;
      if ( v26 >= v25 )
        goto LABEL_24;
    }
  }
  *(_DWORD *)(a2 + 80) = v26;
  v28 = *((_DWORD *)this + 1);
  v29 = *(_DWORD *)(v28 + 288);
  v30 = 0;
  if ( v29 <= 0 )
  {
LABEL_29:
    v30 = -1;
  }
  else
  {
    v31 = *(_DWORD *)(v28 + 292);
    while ( v31 != *((_DWORD *)this + 50) )
    {
      ++v30;
      v31 += 768;
      if ( v30 >= v29 )
        goto LABEL_29;
    }
  }
  *(_DWORD *)(a2 + 84) = v30;
  *(_BYTE *)(a2 + 88) = this[240];
  *(_DWORD *)(a2 + 92) = *((_DWORD *)this + 61);
  *(_DWORD *)(a2 + 96) = *((_DWORD *)this + 62);
  *(_DWORD *)(a2 + 100) = *((_DWORD *)this + 63);
  *(_DWORD *)(a2 + 104) = *((_DWORD *)this + 64);
  *(_DWORD *)(a2 + 108) = *((_DWORD *)this + 65);
  v4 = *((_DWORD *)this + 66);
  *(_DWORD *)(a2 + 112) = v4;
  *(_DWORD *)(a2 + 116) = *((_DWORD *)this + 67);
  qmemcpy((void *)(a2 + 120), this + 272, 0x3Cu);
  qmemcpy((void *)(a2 + 180), this + 332, 0x3Cu);
  qmemcpy((void *)(a2 + 240), this + 392, 0x3Cu);
  qmemcpy((void *)(a2 + 300), this + 452, 0x3Cu);
  qmemcpy((void *)(a2 + 360), this + 512, 0x3Cu);
  qmemcpy((void *)(a2 + 420), this + 572, 0x3Cu);
  qmemcpy((void *)(a2 + 480), this + 632, 0x3Cu);
  qmemcpy((void *)(a2 + 540), this + 692, 0x40u);
  if ( *(_DWORD *)this == 9 )
  {
    v4 = *((_DWORD *)this + 191);
    *(_DWORD *)(a2 + 604) = v4;
  }
  if ( *((_DWORD *)this + 43) && (LOBYTE(v4) = sub_5BFC80(), (_BYTE)v4) )
  {
    *(_DWORD *)(a2 + 608) = *(_DWORD *)(*((_DWORD *)this + 43) + 28);
    *(_DWORD *)(a2 + 612) = -1;
    v32 = *(_DWORD *)(*((_DWORD *)this + 43) + 32);
    if ( v32 )
    {
      v33 = *((_DWORD *)this + 38);
      v34 = 0;
      if ( v33 > 0 )
      {
        v35 = *(_DWORD *)(v32 + 60);
        v36 = (_DWORD *)(*((_DWORD *)this + 39) + 112);
        do
        {
          if ( *v36 == v35 )
            break;
          ++v34;
          v36 += 30;
        }
        while ( v34 < v33 );
      }
      if ( v34 != v33 )
        *(_DWORD *)(a2 + 612) = v34;
    }
    v37 = (_DWORD *)(*((_DWORD *)this + 43) + 44);
    *(_DWORD *)(a2 + 616) = *v37;
    *(_DWORD *)(a2 + 620) = v37[1];
    *(_DWORD *)(a2 + 624) = v37[2];
    v4 = *(_DWORD *)(*((_DWORD *)this + 43) + 56);
    *(_DWORD *)(a2 + 628) = v4;
  }
  else
  {
    *(_DWORD *)(a2 + 608) = -1;
  }
  *(_BYTE *)(a2 + 632) = *((_DWORD *)this + 44) && (LOBYTE(v4) = sub_5BFC80(), (_BYTE)v4);
  *(_BYTE *)(a2 + 633) = *((_DWORD *)this + 45) && (LOBYTE(v4) = sub_5BFC80(), (_BYTE)v4);
  *(_DWORD *)(a2 + 636) = 99;
  *(_DWORD *)(a2 + 676) = 0;
  if ( *((_DWORD *)this + 35) )
  {
    sub_4F56F0((int)this);
    if ( *((_DWORD *)this + 40) && *((_DWORD *)this + 42) && (unsigned __int8)sub_405250() )
    {
      *(_DWORD *)(a2 + 636) = *((_DWORD *)this + 41);
      *(float *)(a2 + 640) = -*(double *)(*((_DWORD *)this + 42) + 8);
      *(float *)(a2 + 644) = *(double *)*((_DWORD *)this + 42);
      *(_DWORD *)(a2 + 648) = *(_DWORD *)(*((_DWORD *)this + 42) + 40);
      *(_DWORD *)(a2 + 652) = *(_DWORD *)(*((_DWORD *)this + 42) + 24);
      *(_DWORD *)(a2 + 656) = 0;
      *(float *)(a2 + 660) = *(double *)(*((_DWORD *)this + 42) + 16);
      *(_DWORD *)(a2 + 672) = *(_DWORD *)(*((_DWORD *)this + 42) + 48);
      *(_BYTE *)(a2 + 664) = *(_BYTE *)(*((_DWORD *)this + 42) + 84);
      *(_DWORD *)(a2 + 668) = *(_DWORD *)(*((_DWORD *)this + 42) + 44);
    }
    v38 = *(int **)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 35) + 8) + 532) + 8);
    v39 = *v38;
    LOBYTE(v4) = 0;
    v49 = v38;
    v48 = *v38;
    v40 = a2 + 680;
    v47 = 0;
    if ( *v38 > 0 )
    {
      v54 = 0;
      do
      {
        v41 = v54 + v38[2];
        v42 = 0;
        if ( *((int *)this + 38) > 0 )
        {
          v43 = (_DWORD *)(*((_DWORD *)this + 39) + 112);
          do
          {
            if ( *v43 == *(_DWORD *)(*(_DWORD *)v41 + 60) )
              break;
            ++v42;
            v43 += 30;
          }
          while ( v42 < *((_DWORD *)this + 38) );
          v39 = v48;
          v38 = v49;
        }
        if ( v42 != *((_DWORD *)this + 38) )
        {
          *(_DWORD *)v40 = v42;
          *(_DWORD *)(v40 + 16) = *(_DWORD *)(v41 + 12);
          *(_DWORD *)(v40 + 20) = *(_DWORD *)(v41 + 4);
          *(_DWORD *)(v40 + 24) = *(_DWORD *)(v41 + 8);
          *(_DWORD *)(v40 + 36) = *(_DWORD *)(v41 + 20);
          *(_BYTE *)(v40 + 28) = *(_BYTE *)(v41 + 38);
          v4 = *(_DWORD *)(a2 + 676) + 1;
          v44 = *(_DWORD *)(a2 + 676) - 15 < 0;
          *(_DWORD *)(a2 + 676) = v4;
          if ( v44 == __OFSUB__(v4, 16) )
            return v4;
          v40 += 40;
        }
        LOBYTE(v4) = v47 + 1;
        v45 = ++v47 < v39;
        v54 += 40;
      }
      while ( v45 );
    }
  }
  return v4;
}
