void __thiscall sub_50BFD0(char *this)
{
  char *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  CHAR ***v6; // eax
  CHAR *v7; // eax
  bool v8; // al
  bool v9; // cl
  bool v10; // al
  _DWORD *v11; // eax
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c2
  int v15; // eax
  int v16; // eax
  char *v17; // edi
  int v18; // ebx
  char *v19; // edi
  int v20; // ebx
  _DWORD *v21; // ecx
  double v22; // st7
  float v23; // ecx
  float v24; // edx
  int v25; // edi
  int *v26; // ebx
  int *v27; // ebp
  int v28; // ebp
  int *v29; // edi
  int *v30; // ebx
  int v31; // edi
  int *v32; // ebx
  int *v33; // ebp
  int v34; // ebp
  int *v35; // edi
  int *v36; // ebx
  char v37; // bl
  int v38; // ecx
  char v39; // al
  double v40; // st7
  int v41; // edi
  float v42; // [esp+Ch] [ebp-44h]
  float v43; // [esp+Ch] [ebp-44h]
  float v44; // [esp+Ch] [ebp-44h]
  float v45; // [esp+Ch] [ebp-44h]
  float v46[3]; // [esp+14h] [ebp-3Ch] BYREF
  float v47[12]; // [esp+20h] [ebp-30h] BYREF

  sub_59E170(
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *((_DWORD *)this + 4),
    *((float *)this + 5),
    *((float *)this + 6),
    *((float *)this + 7));
  v2 = this + 472;
  v3 = 4;
  do
  {
    if ( *((_DWORD *)v2 - 33) && *(v2 - 68) )
      sub_59E170(
        *((_DWORD *)v2 - 32),
        *((_DWORD *)v2 - 31),
        *((_DWORD *)v2 - 30),
        *((float *)v2 - 29),
        *((float *)v2 - 28),
        *((float *)v2 - 27));
    if ( *((_DWORD *)v2 - 16) && *v2 )
      sub_59E170(
        *((_DWORD *)v2 - 15),
        *((_DWORD *)v2 - 14),
        *((_DWORD *)v2 - 13),
        *((float *)v2 - 12),
        *((float *)v2 - 11),
        *((float *)v2 - 10));
    v4 = *((_DWORD *)v2 + 6);
    if ( v4 )
    {
      sub_50C800(v4, *((float *)v2 + 8));
      v5 = *((_DWORD *)v2 + 7);
      if ( v5 )
        sub_50C800(v5, *((float *)v2 + 8));
    }
    v2 += 304;
    --v3;
  }
  while ( v3 );
  if ( sub_40C460(&dword_6291CC) )
  {
    v6 = (CHAR ***)sub_40C460(&dword_6291CC);
    v7 = sub_459B80(v6);
    v8 = _strcmpi(v7, aCockpit) == 0;
  }
  else
  {
    v8 = 0;
  }
  v9 = !dword_768108 && v8;
  v10 = *(_DWORD *)(*(_DWORD *)this + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) && dword_767BEC > 0;
  if ( !v9 && (v10 || dword_7D5DA4 == 2) )
  {
    v11 = (_DWORD *)sub_40C460(&dword_6291CC);
    if ( v11 )
    {
      sub_459BC0(v11, v46, 0);
      if ( v13 | v14 )
      {
        v15 = *((_DWORD *)this + 717);
        if ( !v15 )
        {
          v19 = this + 220;
          v20 = 4;
          do
          {
            sub_50E400(v19);
            v19 += 304;
            --v20;
          }
          while ( v20 );
          goto LABEL_39;
        }
        v16 = v15 - 1;
        if ( v16 )
        {
          if ( v16 != 1 )
            goto LABEL_39;
          if ( dword_7680E4 )
          {
            v17 = this + 220;
            v18 = 4;
            do
            {
              sub_50E400(v17);
              v17 += 304;
              --v18;
            }
            while ( v18 );
            goto LABEL_39;
          }
        }
        sub_50E400(this + 220);
        sub_50E400(this + 524);
      }
    }
  }
LABEL_39:
  v21 = *(_DWORD **)this;
  *((float *)this + 706) = *((float *)this + 705) * 0.050000012 + *((float *)this + 706) * 0.94999999;
  if ( sub_4EED40(v21) )
    v42 = *((float *)this + 705);
  else
    v42 = *((float *)this + 706);
  if ( *((_DWORD *)this + 639) )
  {
    v22 = v42 * 2.0943952;
    v23 = *((float *)this + 709);
    v24 = *((float *)this + 710);
    v46[0] = *((float *)this + 708);
    v46[0] = v46[0] * v22;
    v47[3] = 1.0;
    v46[1] = v23 * v22;
    memset(&v47[4], 0, 12);
    v47[7] = 1.0;
    memset(&v47[8], 0, 12);
    v46[2] = v24 * v22;
    v47[11] = 1.0;
    sub_579930(v46, v47);
    sub_59E0F0(v47[0], v47[1], v47[2]);
  }
  if ( *((_DWORD *)this + 636) && *((_DWORD *)this + 637) && this[2877] )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) )
    {
      v25 = 0;
      v43 = v42 + 1.0 - 0.025;
      if ( *((int *)this + 650) > 0 )
      {
        v26 = (int *)(this + 2604);
        v27 = (int *)(this + 2616);
        do
        {
          sub_5ADBF0(*v26, *v27, v43);
          ++v25;
          ++v26;
          v27 += 5;
        }
        while ( v25 < *((_DWORD *)this + 650) );
      }
      v28 = 0;
      if ( *((int *)this + 664) > 0 )
      {
        v29 = (int *)(this + 2660);
        v30 = (int *)(this + 2672);
        do
        {
          sub_5ADBF0(*v29, *v30, v43);
          ++v28;
          ++v29;
          v30 += 5;
        }
        while ( v28 < *((_DWORD *)this + 664) );
      }
      this[2712] = 0;
    }
    else if ( !this[2712] )
    {
      v31 = 0;
      if ( *((int *)this + 650) > 0 )
      {
        v32 = (int *)(this + 2604);
        v33 = (int *)(this + 2616);
        do
        {
          sub_5ADBF0(*v32, *v33, 1.0);
          ++v31;
          ++v32;
          v33 += 5;
        }
        while ( v31 < *((_DWORD *)this + 650) );
      }
      v34 = 0;
      if ( *((int *)this + 664) > 0 )
      {
        v35 = (int *)(this + 2660);
        v36 = (int *)(this + 2672);
        do
        {
          sub_5ADBF0(*v35, *v36, 1.0);
          ++v34;
          ++v35;
          v36 += 5;
        }
        while ( v34 < *((_DWORD *)this + 664) );
      }
      this[2712] = 1;
    }
  }
  v37 = 0;
  if ( this[2888] )
  {
    if ( fmod(dbl_7DA9D0, *((float *)this + 723)) < 0.33500001 )
LABEL_68:
      v37 = 1;
  }
  else if ( (flt_7DAB04 + flt_7DAB08) * 0.5 > *((float *)this + 704) && this[2886] )
  {
    goto LABEL_68;
  }
  if ( v37 != this[2884] )
  {
    if ( this[2886] )
    {
      v38 = *((_DWORD *)this + 640);
      this[2884] = v37;
      if ( v38 )
        sub_5A2930(v37 != 0, 0, 0);
    }
  }
  if ( *((_DWORD *)this + 641) )
  {
    v39 = this[2885];
    if ( v39 != this[2887] )
    {
      this[2887] = v39;
      sub_5A2930(v39 != 0, 0, 0);
    }
  }
  if ( *((_DWORD *)this + 642) )
  {
    if ( dword_7D5DA4 == 2 )
      v40 = sub_4D9E20(&dword_7D5DAC);
    else
      v40 = dbl_7DA9D0;
    v41 = 0;
    v44 = v40 - *((float *)this + 726);
    if ( v44 > 0.0 && v44 < (double)*((float *)this + 727) )
    {
      v45 = flt_767B5C * v44 + 0.5;
      v41 = (int)v45;
    }
    if ( v41 != *((_DWORD *)this + 725) )
    {
      *((_DWORD *)this + 725) = v41;
      sub_5A2930(0, 0, 0);
      sub_5A2930(v41, 0, 0);
    }
  }
}
