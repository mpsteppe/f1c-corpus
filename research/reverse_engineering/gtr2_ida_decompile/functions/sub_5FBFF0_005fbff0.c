void __userpurge sub_5FBFF0(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5, int a6, int a7)
{
  void (__thiscall *v8)(_DWORD); // eax
  int i; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  char **v13; // eax
  bool v14; // zf
  char *j; // eax
  int v16; // eax
  char **v17; // eax
  _DWORD *v18; // eax
  int v19; // ebx
  _DWORD *v20; // ecx
  _DWORD *v21; // eax
  _DWORD *v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // ecx
  _DWORD *v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  _DWORD *v32; // eax
  void (__thiscall *v33)(_DWORD); // eax
  _DWORD *v34; // eax
  int v35; // eax
  _DWORD *v36; // eax
  char **v37; // eax
  char *k; // eax
  int v39; // eax
  char **v40; // eax
  int v41; // [esp-10h] [ebp-20h]
  int v42; // [esp-Ch] [ebp-1Ch]
  int v43; // [esp-8h] [ebp-18h]
  int v44; // [esp-4h] [ebp-14h]

  if ( *(char *)a1 < 0 )
  {
    off_16C9808(a5, a6, a7);
    return;
  }
  if ( (*(_BYTE *)a1 & 8) != 0 )
  {
    v8 = *(void (__thiscall **)(_DWORD))(a1 + 780);
    if ( v8 )
      v8(*(_DWORD *)(a1 + 784));
    sub_5E5050((char *)a1, 6);
    for ( i = 0; i < 6; ++i )
    {
      v10 = dword_FB2804[i];
      v11 = dword_FB27A4;
      if ( v10 > *(_DWORD *)(4 * i + 9060 + dword_FB27A4) )
      {
        sub_5F7D00((_DWORD *)dword_FB27A4, i, v10);
        v11 = dword_FB27A4;
      }
      v12 = 9084 - (_DWORD)dword_FB2804 + 4 * i;
      *(int *)((char *)dword_FB2804 + v12 + v11) = 0;
    }
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 92) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 112) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 132) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 152) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 172) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 764) + 192) = 0;
    if ( a5 )
    {
      v13 = *(char ***)a5;
      v14 = *(_DWORD *)a5 == 0;
      *(_DWORD *)(a5 + 8) = *(_DWORD *)a5;
      if ( !v14 )
      {
        for ( j = *v13; j; j = *v17 )
        {
          sub_5FBCC0(j, a1);
          v16 = *(_DWORD *)(a5 + 8);
          if ( !v16 )
            break;
          v17 = *(char ***)(v16 + 4);
          *(_DWORD *)(a5 + 8) = v17;
          if ( !v17 )
            break;
        }
      }
    }
    if ( (*(_DWORD *)a1 & 0x80000) == 0 )
    {
      v18 = *(_DWORD **)(a1 + 764);
      if ( !v18[207] || (BYTE1(*v18) & 0x80u) == 0 )
      {
        v19 = a6;
        if ( a6 )
        {
          v37 = *(char ***)a6;
          v14 = *(_DWORD *)a6 == 0;
          *(_DWORD *)(a6 + 8) = *(_DWORD *)a6;
          if ( !v14 )
          {
            for ( k = *v37; k; k = *v40 )
            {
              sub_5FBCC0(k, a1);
              v39 = *(_DWORD *)(a6 + 8);
              if ( !v39 )
                break;
              v40 = *(char ***)(v39 + 4);
              *(_DWORD *)(a6 + 8) = v40;
              if ( !v40 )
                break;
            }
          }
        }
        goto LABEL_21;
      }
      sub_608270(a1);
      ++*(_DWORD *)(*(_DWORD *)(a1 + 764) + 744);
    }
    v19 = a6;
LABEL_21:
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 112), 1);
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 92), 1);
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 152), 1);
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 132), 1);
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 172), 1);
    sub_5FBDC0((_DWORD *)(*(_DWORD *)(a1 + 764) + 192), 1);
    if ( (*(_BYTE *)a1 & 0x40) != 0 )
    {
      v20 = *(_DWORD **)(a1 + 764);
      if ( (*v20 & 0xF0000) != 0 )
      {
        v20[65] = 0;
        v21 = *(_DWORD **)(a1 + 764);
        if ( (*v21 & 0x10000) != 0 )
        {
          v22 = (_DWORD *)v21[149];
          v21[151] = v22;
          if ( v22 )
          {
            if ( *v22 )
            {
              do
              {
                v44 = 0;
                v43 = a1;
                sub_5E6840();
                v23 = *(_DWORD *)(a1 + 764);
                v24 = *(_DWORD *)(v23 + 604);
                v25 = v23 + 596;
                if ( v24 )
                  *(_DWORD *)(v25 + 8) = *(_DWORD *)(v24 + 4);
                v26 = *(_DWORD **)(v25 + 8);
              }
              while ( v26 && *v26 );
            }
          }
        }
        v27 = *(_DWORD **)(a1 + 764);
        if ( (*v27 & 0x20000) != 0 )
        {
          v28 = (_DWORD *)v27[153];
          v27[155] = v28;
          if ( v28 )
          {
            if ( *v28 )
            {
              do
              {
                v42 = 0;
                v41 = a1;
                sub_5E6840();
                v29 = *(_DWORD *)(a1 + 764);
                v30 = *(_DWORD *)(v29 + 620);
                v31 = v29 + 612;
                if ( v30 )
                  *(_DWORD *)(v31 + 8) = *(_DWORD *)(v30 + 4);
                v32 = *(_DWORD **)(v31 + 8);
              }
              while ( v32 && *v32 );
            }
          }
        }
      }
    }
    sub_5E5050((char *)a1, 280);
    (*(void (__thiscall **)(int, _DWORD, int, int, int, int, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 476))(
      dword_FB27A4,
      *(_DWORD *)(a1 + 764),
      a1,
      1,
      v41,
      v42,
      v43,
      v44,
      a4,
      a3,
      a2);
    v33 = *(void (__thiscall **)(_DWORD))(a1 + 788);
    if ( v33 )
      v33(*(_DWORD *)(a1 + 792));
    if ( (*(_DWORD *)a1 & 0x100) != 0 )
    {
      v34 = *(_DWORD **)(a1 + 800);
      *(_DWORD *)(a1 + 808) = v34;
      if ( v34 )
      {
        if ( *v34 )
        {
          do
          {
            sub_5FBFF0(a5, v19, 0);
            v35 = *(_DWORD *)(a1 + 808);
            if ( !v35 )
              break;
            v36 = *(_DWORD **)(v35 + 4);
            *(_DWORD *)(a1 + 808) = v36;
            if ( !v36 )
              break;
          }
          while ( *v36 );
          sub_5E5050((char *)a1, 286);
        }
      }
    }
  }
}
