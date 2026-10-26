int *__thiscall sub_5365F0(int *this, int a2, int a3, const char *a4)
{
  int v4; // eax
  const char *v5; // esi
  int v6; // edi
  bool v7; // bl
  _DWORD *v8; // eax
  char *v9; // eax
  const char *v10; // esi
  int v12; // ebx
  int v13; // eax
  int *v14; // eax
  float v15; // esi
  int v16; // edi
  int *v17; // esi
  _DWORD *v18; // ebp
  char *v19; // eax
  _DWORD *v20; // edi
  int i; // esi
  const char *v22; // eax
  int v23; // eax
  int v24; // ebp
  _DWORD *v25; // edi
  const char *v26; // esi
  int v27; // eax
  char v28; // al
  int *v29; // ebx
  int v30; // ebp
  const char *v31; // edi
  int v32; // eax
  char v33; // al
  int v34; // eax
  bool v35; // zf
  int v36; // ecx
  int j; // edi
  int v38; // ebx
  int k; // eax
  _DWORD *v40; // eax
  char *v41; // eax
  int v42; // eax
  int m; // ebx
  int v44; // edx
  int v45; // edi
  int v46; // ebp
  _DWORD *v47; // edi
  const char *v48; // esi
  int v49; // eax
  char v50; // al
  float *v51; // eax
  float *v52; // esi
  float **v53; // eax
  int v54; // ecx
  int v55; // eax
  int v56; // edx
  _DWORD *v57; // eax
  int v58; // eax
  int v59; // edx
  int v60; // edi
  _DWORD *v61; // ebx
  _DWORD *v62; // eax
  _DWORD *v63; // edx
  _DWORD *n; // ecx
  int v65; // [esp-18h] [ebp-264h]
  char v66; // [esp-Ch] [ebp-258h]
  char v67; // [esp-4h] [ebp-250h]
  int v68; // [esp+0h] [ebp-24Ch]
  char *Block; // [esp+4h] [ebp-248h]
  float v70; // [esp+8h] [ebp-244h]
  int v71; // [esp+8h] [ebp-244h]
  int v72; // [esp+Ch] [ebp-240h]
  _DWORD *v73; // [esp+10h] [ebp-23Ch]
  float v74; // [esp+14h] [ebp-238h]
  char *v75; // [esp+18h] [ebp-234h]
  int v76; // [esp+1Ch] [ebp-230h]
  int v77; // [esp+20h] [ebp-22Ch]
  int *v78; // [esp+24h] [ebp-228h]
  char ArgList[4]; // [esp+3Ch] [ebp-210h] BYREF
  char Buffer[504]; // [esp+40h] [ebp-20Ch] BYREF
  int v81; // [esp+240h] [ebp-Ch]
  int v82; // [esp+244h] [ebp-8h]
  char *String2; // [esp+248h] [ebp-4h]

  sub_525140(this);
  v4 = sub_53A250(0);
  v5 = dword_B7235C;
  v6 = v4;
  if ( !dword_B7235C )
    v5 = WindowName;
  v7 = strstr(v5, "_SC_") != 0;
  HIBYTE(v73) = strstr(v5, "_SM_") != 0;
  if ( sub_616840("IgnoreTrackFilter") )
    v7 = 1;
  if ( !v6
    || *(_DWORD *)dword_B72314 == 4
    || v7
    || HIBYTE(v73)
    || (v8 = (_DWORD *)sub_616630("AI Vehicle Filter")) == 0
    || (v9 = sub_48D380(v8)) == 0 )
  {
    v10 = a4;
    sprintf(Buffer, "%s NOT: NotAI", a4);
  }
  else
  {
    v10 = a4;
    sprintf(Buffer, "%s NOT: NotAI AND: %s", a4, v9);
  }
  sub_53BDE0(&unk_BE1CE0, Buffer);
  if ( !sub_5A6E90(&unk_BE1CE0) )
  {
    sprintf(ArgList, "%s NOT: NotAI", v10);
    sub_53BDE0(&unk_BE1CE0, ArgList);
  }
  v77 = sub_5A6E90(&unk_BE1CE0);
  if ( v77 )
  {
    v12 = 0;
    v76 = 0;
    v74 = 0.0;
    if ( sub_53A250(0) )
    {
      v13 = sub_616630("Max Vehicles Per Class");
      v72 = v13;
      if ( v13 )
      {
        v12 = sub_6165F0(v13);
        v76 = v12;
        if ( v12 > 0 )
        {
          v14 = (int *)operator new(12 * v12);
          v15 = *(float *)&v14;
          v78 = v14;
          v16 = 0;
          v81 = 0;
          if ( v14 )
            sub_41D1B0((int)v14, 12, v12, (int)unknown_libname_25);
          else
            v15 = 0.0;
          v81 = -1;
          v74 = v15;
          v17 = (int *)(LODWORD(v15) + 8);
          do
          {
            v18 = (_DWORD *)sub_616610(v16);
            *(v17 - 2) = sub_6165E0(v18);
            *(v17 - 1) = 0;
            v19 = sub_48D380(v18);
            *v17 = atol(v19);
            ++v16;
            v17 += 3;
          }
          while ( v16 < v12 );
        }
      }
    }
    v20 = operator new(4 * v77);
    for ( i = 0; i < v77; ++i )
    {
      v66 = i;
      v20[i] = 0;
      v22 = *(const char **)((int (__thiscall *)(void *))byte_53A070)(&unk_BE1CE0);
      if ( !v22 )
        v22 = WindowName;
      if ( !_stricmp(v22, String2) )
        v20[i] += 3;
    }
    v23 = sub_539670(String2);
    if ( v23 )
    {
      if ( v12 > 0 )
      {
        v24 = v23 + 2172;
        v25 = v73 + 1;
        do
        {
          v26 = (const char *)*(v25 - 1);
          v27 = sub_616480(v24, v26);
          if ( v27 && (v27 == v24 || *(_BYTE *)(v27 - 1) == 32) )
          {
            v28 = *(_BYTE *)(strlen(v26) + v27);
            if ( !v28 || v28 == 32 )
              ++*v25;
          }
          v25 += 3;
          --v12;
        }
        while ( v12 );
      }
    }
    else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\season.cpp", 1036) )
    {
      sub_561210((int)byte_FAE910, "Could not find vehicle data for player", v66);
    }
    if ( v82 > 0 )
    {
      do
      {
        v70 = 0.0;
        if ( v76 > 0 )
        {
          v29 = v78;
          do
          {
            v76 = ((int (__thiscall *)(void *, _DWORD))byte_53A070)(&unk_BE1CE0, LODWORD(v70));
            if ( SLODWORD(v74) > 0 )
            {
              v73 = (_DWORD *)(v72 + 4);
              v70 = v74;
              do
              {
                v30 = (*v73 - v73[1]) << 10;
                if ( v30 > 0 )
                {
                  v31 = (const char *)*(v73 - 1);
                  v32 = sub_616480(v76 + 2172, v31);
                  if ( v32 )
                  {
                    if ( v32 == v76 + 2172 || *(_BYTE *)(v32 - 1) == 32 )
                    {
                      v33 = *(_BYTE *)(strlen(v31) + v32);
                      if ( !v33 || v33 == 32 )
                      {
                        v34 = *v29;
                        if ( *v29 < v30 )
                        {
                          do
                            v34 += 1024;
                          while ( v34 < v30 );
                          *v29 = v34;
                        }
                      }
                    }
                  }
                }
                v35 = LODWORD(v70) == 1;
                v73 += 3;
                --LODWORD(v70);
              }
              while ( !v35 );
            }
            ++v29;
            ++Block;
          }
          while ( (int)Block < (int)v75 );
        }
        v36 = 0;
        for ( j = 0x7FFFFFFF; v36 < (int)v75; ++v36 )
        {
          if ( *(_DWORD *)(v77 + 4 * v36) < j )
            j = *(_DWORD *)(v77 + 4 * v36);
        }
        v38 = 0;
        for ( k = 0; k < (int)v75; ++k )
        {
          if ( *(_DWORD *)(v77 + 4 * k) == j )
            ++v38;
        }
        v71 = 0;
        v40 = (_DWORD *)sub_616840("FieldSelection");
        if ( !v40 || (v41 = sub_48D380(v40), _stricmp(v41, "FASTEST")) )
          v71 = rand() % v38;
        v42 = 0;
        for ( m = 0; m < (int)v75; ++m )
        {
          if ( *(_DWORD *)(v77 + 4 * m) == j )
          {
            v44 = v42++;
            if ( v44 == v71 )
              break;
          }
        }
        *(_DWORD *)(v77 + 4 * m) += 2;
        v45 = ((int (__thiscall *)(void *, int))byte_53A070)(&unk_BE1CE0, m);
        v68 = v45;
        if ( (int)v73 > 0 )
        {
          v46 = v45 + 2172;
          v47 = (_DWORD *)(v71 + 4);
          Block = (char *)v73;
          do
          {
            v48 = (const char *)*(v47 - 1);
            v49 = sub_616480(v46, v48);
            if ( v49 && (v49 == v46 || *(_BYTE *)(v49 - 1) == 32) )
            {
              v50 = *(_BYTE *)(strlen(v48) + v49);
              if ( !v50 || v50 == 32 )
                ++*v47;
            }
            v47 += 3;
            --Block;
          }
          while ( Block );
          v45 = v68;
        }
        v51 = (float *)operator new(8u);
        if ( v51 )
        {
          *v51 = NAN;
          v51[1] = 0.0;
          v52 = v51;
        }
        else
        {
          v52 = 0;
        }
        *(_DWORD *)v52 = sub_53A0C0(&unk_BE1CE0, m);
        v74 = *(float *)(v45 + 2700) * 1000.0;
        v52[1] = sub_530F70((char *)(v45 + 1852)) + v74;
        v53 = (float **)operator new(0xCu);
        if ( v53 )
        {
          *v53 = v52;
          v53[1] = 0;
          *((_BYTE *)v53 + 8) = 1;
        }
        else
        {
          v53 = 0;
        }
        if ( *(_DWORD *)v77 )
        {
          *(_DWORD *)(*(_DWORD *)(v77 + 4) + 4) = v53;
        }
        else
        {
          *(_DWORD *)v77 = v53;
          *(_DWORD *)(v77 + 8) = v53;
        }
        v54 = *(_DWORD *)(v77 + 12);
        *(_DWORD *)(v77 + 4) = v53;
        v35 = v76 == 1;
        *(_DWORD *)(v77 + 12) = v54 + 1;
        --v76;
      }
      while ( !v35 );
    }
    v55 = 0;
    v56 = *(_DWORD *)v77;
    if ( !*(_DWORD *)v77 )
      goto LABEL_100;
    do
    {
      v56 = *(_DWORD *)(v56 + 4);
      ++v55;
    }
    while ( v56 );
    if ( v55 >= 2 )
    {
      v58 = v55 / 2 - 1;
      v59 = *(_DWORD *)v77;
      if ( v58 > 0 )
      {
        do
        {
          --v58;
          v59 = *(_DWORD *)(v59 + 4);
        }
        while ( v58 );
      }
      v60 = *(_DWORD *)(v59 + 4);
      v65 = *(_DWORD *)v77;
      *(_DWORD *)(v59 + 4) = 0;
      v61 = sub_535530(v65);
      v62 = sub_535530(v60);
      v57 = sub_5339E0(v61, v62);
    }
    else
    {
LABEL_100:
      v57 = *(_DWORD **)v77;
    }
    *(_DWORD *)v77 = v57;
    v63 = v57;
    if ( v57 )
    {
      for ( n = (_DWORD *)v57[1]; n; n = (_DWORD *)n[1] )
        v63 = n;
    }
    *(_DWORD *)(v77 + 8) = v57;
    *(_DWORD *)(v77 + 4) = v63;
    if ( Block )
      j__free(Block);
    if ( v75 )
      j__free(v75);
    return v78;
  }
  else
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\season.cpp", 963) )
      sub_561210((int)byte_FAE910, "No vehicles exist that satisfy filter passed to GenerateOpponents", v67);
    return 0;
  }
}
