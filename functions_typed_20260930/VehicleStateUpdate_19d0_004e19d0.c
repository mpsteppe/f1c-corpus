void __thiscall sub_4E19D0(char *this)
{
  char *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // ebp
  int v7; // edi
  int v8; // eax
  float *v9; // edi
  float v10; // ecx
  float v11; // edx
  int v12; // ebx
  double v13; // st7
  float v14; // eax
  int *v15; // ebx
  bool v16; // cl
  bool v17; // al
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c2
  int v21; // eax
  int v22; // eax
  char *v23; // edi
  int v24; // ebx
  char *v25; // edi
  int v26; // ebx
  double v27; // st7
  float v28; // eax
  float v29; // ecx
  int v30; // eax
  int v31; // edi
  int *v32; // ebx
  int *v33; // ebp
  char v34; // bl
  double v35; // st7
  int v36; // ecx
  char v37; // al
  char v38; // al
  int v39; // edi
  int v40; // [esp+Ch] [ebp-48h]
  float v41; // [esp+Ch] [ebp-48h]
  int v42; // [esp+10h] [ebp-44h] BYREF
  float v43; // [esp+14h] [ebp-40h] BYREF
  int v44; // [esp+18h] [ebp-3Ch] BYREF
  int v45; // [esp+1Ch] [ebp-38h]
  int v46; // [esp+20h] [ebp-34h]
  float v47[12]; // [esp+24h] [ebp-30h] BYREF

  sub_54B4D0(
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *((_DWORD *)this + 4),
    *((float *)this + 5),
    *((float *)this + 6),
    *((float *)this + 7));
  v2 = this + 456;
  v3 = 4;
  do
  {
    if ( *((_DWORD *)v2 - 33) && *(v2 - 68) )
      sub_54B4D0(
        *((_DWORD *)v2 - 32),
        *((_DWORD *)v2 - 31),
        *((_DWORD *)v2 - 30),
        *((float *)v2 - 29),
        *((float *)v2 - 28),
        *((float *)v2 - 27));
    if ( *((_DWORD *)v2 - 16) && *v2 )
      sub_54B4D0(
        *((_DWORD *)v2 - 15),
        *((_DWORD *)v2 - 14),
        *((_DWORD *)v2 - 13),
        *((float *)v2 - 12),
        *((float *)v2 - 11),
        *((float *)v2 - 10));
    v4 = *((_DWORD *)v2 + 6);
    if ( v4 )
    {
      ColorAlphaUpdateFlagSet(v4, *((float *)v2 + 8));
      v5 = *((_DWORD *)v2 + 7);
      if ( v5 )
        ColorAlphaUpdateFlagSet(v5, *((float *)v2 + 8));
    }
    v2 += 296;
    --v3;
  }
  while ( v3 );
  v40 = 0;
  if ( *((int *)this + 2804) > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *((_DWORD *)this + 2805);
      v8 = *(_DWORD *)(v7 + v6);
      v9 = (float *)(v6 + v7);
      v8 *= 296;
      *(float *)&v44 = *(float *)&this[v8 + 328] + v9[1];
      v10 = *(float *)&this[v8 + 348];
      v11 = *(float *)&this[v8 + 344];
      *(float *)&v45 = *(float *)&this[v8 + 332] + v9[2];
      v12 = (int)&this[v8 + 212];
      v13 = *(float *)&this[v8 + 336] + v9[3];
      v14 = *(float *)&this[v8 + 340];
      *(float *)&v46 = v13;
      sub_54B4D0(v44, v45, v46, v14, v11, v10);
      BitFlagReader(&v43, &v42);
      FlagFieldBitManipulation(LODWORD(v43), v42, 1, 0);
      sub_5506A0(*(_DWORD *)(v12 + 280), 0, 0);
      v15 = &dword_8AD3EC;
      do
      {
        if ( *v15 )
          sub_5506A0(*((_DWORD *)this + 731), *v15, 0);
        ++v15;
      }
      while ( (int)v15 < (int)&unk_8AD3F8 );
      v6 += 20;
      ++v40;
    }
    while ( v40 < *((_DWORD *)this + 2804) );
  }
  v16 = !dword_7CFCEC && dword_5EA518 == dword_5EA528 && *(_DWORD *)(dword_5EA528 + 52) == 1;
  v17 = *(_DWORD *)(*(_DWORD *)this + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) && dword_7CF7F4 > 0;
  if ( !v16 && (v17 || dword_8AB6E4 == 2) && VirtualDispatchHelper(&dword_5EA510) && v19 | v20 )
  {
    v21 = *((_DWORD *)this + 601);
    if ( v21 )
    {
      v22 = v21 - 1;
      if ( !v22 )
        goto LABEL_40;
      if ( v22 != 1 )
        goto LABEL_44;
      if ( dword_7CFCC8 )
      {
        v23 = this + 212;
        v24 = 4;
        do
        {
          sub_4E3090(v23);
          v23 += 296;
          --v24;
        }
        while ( v24 );
      }
      else
      {
LABEL_40:
        sub_4E3090(this + 212);
        sub_4E3090(this + 508);
      }
    }
    else
    {
      v25 = this + 212;
      v26 = 4;
      do
      {
        sub_4E3090(v25);
        v25 += 296;
        --v26;
      }
      while ( v26 );
    }
  }
LABEL_44:
  if ( *((_DWORD *)this + 552) )
  {
    v27 = *((float *)this + 596) * 2.0943952;
    v28 = *((float *)this + 599);
    v29 = *((float *)this + 600);
    v44 = *((int *)this + 598);
    *(float *)&v44 = *(float *)&v44 * v27;
    *(float *)&v45 = v28 * v27;
    v47[3] = 1.0;
    memset(&v47[4], 0, 12);
    v47[7] = 1.0;
    *(float *)&v46 = v29 * v27;
    memset(&v47[8], 0, 12);
    v47[11] = 1.0;
    sub_567120(&v44, v47);
    sub_54B450(v47[0], v47[1], v47[2]);
  }
  if ( *((_DWORD *)this + 550) && this[2413] )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) )
    {
      FlagFieldBitManipulation(1, 1, 0, 0);
      v30 = *((_DWORD *)this + 557);
      v31 = 0;
      v43 = *((float *)this + 596) + 1.0 - 0.025;
      if ( v30 > 0 )
      {
        v32 = (int *)(this + 2232);
        v33 = (int *)(this + 2244);
        do
        {
          ConditionalDispatchByFlag(*v32, *v33, v43);
          ++v31;
          ++v32;
          v33 += 4;
        }
        while ( v31 < *((_DWORD *)this + 557) );
      }
    }
    else
    {
      FlagFieldBitManipulation(0, 0, 0, 0);
    }
  }
  v34 = 0;
  if ( this[2425] || (v35 = (flt_8AFEE8 + flt_8AFEEC) * 0.5, v35 > *((float *)this + 595)) )
  {
    v35 = dbl_8AFEA0;
    v43 = dbl_8AFEA0;
    InterruptDispatch(dbl_8AFEA0);
    if ( v35 < 0.33500001 )
      v34 = 1;
  }
  if ( v34 != this[2420] )
  {
    v36 = *((_DWORD *)this + 553);
    this[2420] = v34;
    if ( v36 )
      sub_5506A0(v34 != 0, 0, 0);
  }
  if ( *((_DWORD *)this + 554) )
  {
    v37 = this[2421];
    if ( v37 != this[2422] )
    {
      this[2422] = v37;
      sub_5506A0(v37 != 0, 0, 0);
    }
  }
  if ( *((_DWORD *)this + 555) )
  {
    v38 = this[2423];
    if ( v38 != this[2424] )
    {
      this[2424] = v38;
      sub_5506A0(v38 != 0, 0, 0);
    }
  }
  if ( *((_DWORD *)this + 556) )
  {
    if ( dword_8AB6E4 == 2 )
      Delegation(&dword_8AB6EC);
    else
      v35 = dbl_8AFEA0;
    v39 = 0;
    v41 = v35 - *((float *)this + 609);
    if ( v41 > 0.0 && v41 < (double)*((float *)this + 610) )
    {
      v43 = flt_7CF740 * v41 + 0.5;
      v42 = (int)v43;
      v39 = v42;
    }
    if ( v39 != *((_DWORD *)this + 608) )
    {
      *((_DWORD *)this + 608) = v39;
      sub_5506A0(0, 0, 0);
      sub_5506A0(v39, 0, 0);
    }
  }
}

