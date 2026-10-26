void __thiscall sub_42E530(int this, int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  _BYTE *v12; // ecx
  int v13; // edi
  int v14; // ebx
  char v15; // al
  char v16; // al
  char v17; // al
  char v18; // al
  int v19; // ebx
  int v20; // edi
  char v21; // al
  char v22; // al
  double v23; // st7
  int v24; // edx
  int v25; // edi
  int v26; // ecx
  int v27; // ebx
  long double v28; // st4
  int v29; // eax
  bool v30; // bl
  char v31; // al
  int v32; // edi
  int v33; // ecx
  double v34; // st7
  double v35; // st6
  int v36; // edi
  int v37; // edx
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // edi
  int v42; // ecx
  int v43; // ebx
  long double v44; // st4
  char v45; // [esp+13h] [ebp-6Dh]
  int v46; // [esp+14h] [ebp-6Ch]
  int v47; // [esp+14h] [ebp-6Ch]
  double v48; // [esp+18h] [ebp-68h]
  double v49; // [esp+18h] [ebp-68h]
  _BYTE v50[32]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v51[64]; // [esp+40h] [ebp-40h] BYREF

  v3 = a3;
  if ( a2 == -1 || a3 == -1 )
  {
    v45 = 1;
    v5 = 44;
    v6 = 50;
LABEL_8:
    v7 = v5;
    if ( v5 <= v6 )
    {
      v8 = (v5 << 6) + this + 3012;
      do
      {
        if ( v7 < 50 )
        {
          if ( *(_BYTE *)(v8 + 72) )
          {
            v9 = *(_DWORD *)(v8 + 64);
            if ( *(_DWORD *)v8 >= v9 )
            {
              v3 = a3;
              *(_DWORD *)v8 = v9 - 1 < 0 ? 0 : v9 - 1;
            }
          }
        }
        if ( v7 > 44 )
        {
          v10 = *(_DWORD *)(v8 - 64);
          if ( *(_DWORD *)v8 <= v10 )
          {
            v11 = v10 + 1;
            if ( *(_DWORD *)(v8 - 4) - 1 < v11 )
              v11 = *(_DWORD *)(v8 - 4) - 1;
            v3 = a3;
            *(_DWORD *)v8 = v11;
          }
        }
        ++v7;
        v8 += 64;
      }
      while ( v7 <= v6 );
    }
    goto LABEL_20;
  }
  v45 = 0;
  if ( a2 == 4 && a3 >= 44 && a3 <= 50 )
  {
    v5 = a3;
    v6 = a3;
    goto LABEL_8;
  }
LABEL_20:
  if ( *(_BYTE *)(this + 6536) )
  {
    EventTriggerOnStateChange((_BYTE *)this, this + 4080, this + 4144);
    EventTriggerOnStateChange(v12, this + 4208, this + 4272);
    EventTriggerOnStateChange((_BYTE *)this, this + 4464, this + 4528);
    EventTriggerOnStateChange((_BYTE *)this, this + 4592, this + 4656);
    v13 = this + 496;
    v14 = 4;
    do
    {
      EventTriggerOnStateChange((_BYTE *)this, v13, v13 + 64);
      EventTriggerOnStateChange((_BYTE *)this, v13 + 128, v13 + 192);
      v13 += 704;
      --v14;
    }
    while ( v14 );
  }
  else
  {
    v15 = a2 == -1 && v3 == 17;
    WeightedSumComparatorWithBinaryAdjustment(this + 4080, this + 4144, v15);
    v16 = a2 == -1 && a3 == 19;
    WeightedSumComparatorWithBinaryAdjustment(this + 4208, this + 4272, v16);
    v17 = a2 == -1 && a3 == 23;
    WeightedSumComparatorWithBinaryAdjustment(this + 4464, this + 4528, v17);
    v18 = a2 == -1 && a3 == 25;
    WeightedSumComparatorWithBinaryAdjustment(this + 4592, this + 4656, v18);
    v19 = 0;
    v20 = this + 496;
    do
    {
      v21 = a2 == v19 && a3 == 5;
      WeightedSumComparatorWithBinaryAdjustment(v20, v20 + 64, v21);
      v22 = a2 == v19 && a3 == 7;
      WeightedSumComparatorWithBinaryAdjustment(v20 + 128, v20 + 192, v22);
      ++v19;
      v20 += 704;
    }
    while ( v19 < 4 );
  }
  if ( *(_DWORD *)(this + 6544) != 1 )
    return;
  if ( !v45 )
  {
    if ( a2 != 4 )
      goto LABEL_67;
    if ( a3 != 28 )
      goto LABEL_63;
  }
  if ( !StringCopyWithValidation(v50, 32, aRearspoilerang, 0) )
  {
    v23 = sub_58850F(v50);
    v24 = *(_DWORD *)(this + 4800);
    v25 = *(_DWORD *)(this + 4804);
    v26 = 0;
    v48 = 1.797693134862316e308;
    v46 = 0;
    if ( v24 > 0 )
    {
      do
      {
        v27 = v26;
        v28 = fabs((double)v46 * *(double *)(this + 4792) + *(double *)(this + 4784) - v23);
        if ( v28 < v48 )
        {
          v48 = v28;
          v25 = v26;
        }
        v46 = ++v26;
      }
      while ( v26 < v24 );
      *(_DWORD *)(this + 4804) = v27;
    }
    *(_DWORD *)(this + 4804) = v25;
  }
  if ( !v45 )
  {
    if ( a2 != 4 )
      goto LABEL_67;
LABEL_63:
    if ( a3 != 4 )
      goto LABEL_67;
  }
  if ( dword_7C56A4 )
  {
    v29 = *(_DWORD *)(this + 3264);
    if ( v29 >= 1 )
      *(_DWORD *)(this + 3268) = v29 - 1;
  }
LABEL_67:
  v30 = 0;
  if ( !StringCopyWithValidation(v51, 64, aTrackType, 0) )
    v30 = sub_588410(v51, aRoadCourse) == 0;
  v31 = v45;
  v32 = a2;
  if ( v45 )
    goto LABEL_72;
  if ( a2 != 4 )
  {
    if ( a3 != 2 )
    {
LABEL_87:
      if ( v32 != 4 )
        goto LABEL_93;
      goto LABEL_88;
    }
LABEL_72:
    if ( v30 )
    {
      v33 = this + 1712;
      v34 = (double)*(int *)(this + 1732) * *(double *)(this + 1720) + *(double *)(this + 1712);
      if ( v34 < 0.1523746 )
      {
        v35 = (double)*(int *)(this + 2436) * *(double *)(this + 2424) + *(double *)(this + 2416);
        if ( v35 < 0.1523746 )
        {
          if ( a2 != 2 && (a2 == 3 || v34 <= v35) )
            v33 = this + 2416;
          v36 = *(_DWORD *)(v33 + 16);
          if ( *(_DWORD *)(v33 + 20) < v36 )
          {
            do
            {
              v37 = *(_DWORD *)(v33 + 20);
              if ( (double)v37 * *(double *)(v33 + 8) + *(double *)v33 >= 0.1523746 )
                break;
              *(_DWORD *)(v33 + 20) = v37 + 1;
            }
            while ( v37 + 1 < v36 );
          }
        }
      }
    }
    else
    {
      v38 = *(_DWORD *)(this + 2432);
      if ( *(_DWORD *)(this + 2436) < v38 )
      {
        do
        {
          v39 = *(_DWORD *)(this + 2436);
          if ( (double)v39 * *(double *)(this + 2424) + *(double *)(this + 2416) >= 0.1523746 )
            break;
          *(_DWORD *)(this + 2436) = v39 + 1;
        }
        while ( v39 + 1 < v38 );
      }
    }
    v31 = v45;
    v32 = a2;
    if ( v45 )
      goto LABEL_89;
    goto LABEL_87;
  }
LABEL_88:
  if ( a3 )
    return;
LABEL_89:
  if ( !v30 )
    *(_DWORD *)(this + 3012) = 0;
  if ( !v31 )
  {
    if ( v32 == 4 )
      return;
LABEL_93:
    if ( a3 != 2 )
      return;
  }
  v40 = *(_DWORD *)(this + 1024);
  v41 = *(_DWORD *)(this + 1028);
  v42 = 0;
  v49 = 1.797693134862316e308;
  v47 = 0;
  if ( v40 > 0 )
  {
    do
    {
      v43 = v42;
      v44 = fabs(
              (double)v47 * *(double *)(this + 1016)
            + *(double *)(this + 1008)
            - ((double)*(int *)(this + 324) * *(double *)(this + 312)
             + *(double *)(this + 304)
             - ((double)*(int *)(this + 1732) * *(double *)(this + 1720)
              + *(double *)(this + 1712))
             + (double)*(int *)(this + 2436) * *(double *)(this + 2424)
             + *(double *)(this + 2416)));
      if ( v44 < v49 )
      {
        v49 = v44;
        v41 = v42;
      }
      v47 = ++v42;
    }
    while ( v42 < v40 );
    *(_DWORD *)(this + 1028) = v43;
  }
  *(_DWORD *)(this + 1028) = v41;
}
