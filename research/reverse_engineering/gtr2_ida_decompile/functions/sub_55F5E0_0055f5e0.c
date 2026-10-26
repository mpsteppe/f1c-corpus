void __thiscall sub_55F5E0(void *this, _DWORD *a2)
{
  void *v2; // esi
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // eax
  const char *v7; // edi
  double *v8; // eax
  int v9; // ecx
  int v10; // ebx
  double *v11; // esi
  double *v12; // edx
  int v13; // edi
  int v14; // ecx
  double *v15; // eax
  double *v16; // eax
  int v17; // ecx
  double v18; // st7
  const CHAR *v19; // esi
  double *v20; // ebx
  const CHAR *v21; // esi
  double v22; // st7
  int v23; // eax
  int v24; // edi
  int v25; // ecx
  double v26; // st6
  double v27; // st6
  int v28; // ebx
  int v29; // edx
  double v30; // st7
  int v31; // eax
  int v32; // ecx
  int v33; // edi
  double v34; // st7
  int v35; // edx
  double *v36; // ecx
  long double v37; // st6
  int v38; // edx
  int v39; // eax
  double *v40; // ecx
  char v41; // [esp+Fh] [ebp-591h]
  double v43; // [esp+10h] [ebp-590h]
  double v44; // [esp+10h] [ebp-590h]
  double v45; // [esp+10h] [ebp-590h]
  int v46; // [esp+18h] [ebp-588h]
  int v47; // [esp+18h] [ebp-588h]
  double v48; // [esp+18h] [ebp-588h]
  int v49; // [esp+20h] [ebp-580h]
  double v50; // [esp+20h] [ebp-580h]
  double v51; // [esp+20h] [ebp-580h]
  unsigned int v52; // [esp+28h] [ebp-578h]
  double v53; // [esp+28h] [ebp-578h]
  double v54; // [esp+28h] [ebp-578h]
  double v55; // [esp+30h] [ebp-570h]
  double v56; // [esp+30h] [ebp-570h]
  double v57; // [esp+30h] [ebp-570h]
  double v58; // [esp+30h] [ebp-570h]
  double *Block; // [esp+38h] [ebp-568h]
  double Blocka; // [esp+38h] [ebp-568h]
  double v61; // [esp+40h] [ebp-560h] BYREF
  int v62[2]; // [esp+48h] [ebp-558h] BYREF
  int v63[2]; // [esp+50h] [ebp-550h] BYREF
  _DWORD v64[4]; // [esp+58h] [ebp-548h] BYREF
  double v65; // [esp+68h] [ebp-538h] BYREF
  double v66; // [esp+70h] [ebp-530h]
  double v67; // [esp+78h] [ebp-528h]
  double v68; // [esp+80h] [ebp-520h]
  double v69; // [esp+88h] [ebp-518h]
  double v70[4]; // [esp+90h] [ebp-510h] BYREF
  double v71; // [esp+B0h] [ebp-4F0h]
  double v72; // [esp+B8h] [ebp-4E8h] BYREF
  double v73; // [esp+C0h] [ebp-4E0h]
  double v74; // [esp+C8h] [ebp-4D8h]
  double v75; // [esp+D0h] [ebp-4D0h]
  double v76; // [esp+D8h] [ebp-4C8h]
  double v77[4]; // [esp+E0h] [ebp-4C0h] BYREF
  double v78; // [esp+100h] [ebp-4A0h]
  int v79[32]; // [esp+108h] [ebp-498h] BYREF
  char v80[512]; // [esp+188h] [ebp-418h] BYREF
  int v81; // [esp+388h] [ebp-218h]
  char v82; // [esp+38Ch] [ebp-214h]
  int v83; // [esp+394h] [ebp-20Ch]
  int v84; // [esp+398h] [ebp-208h]
  int v85; // [esp+39Ch] [ebp-204h]
  char Str[512]; // [esp+3A0h] [ebp-200h] BYREF

  *(double *)v63 = 0.01;
  v2 = this;
  *(double *)v62 = 1.0;
  v3 = 0;
  memset(Str, 0, sizeof(Str));
  v4 = a2;
  v5 = *a2;
  v41 = 0;
  v46 = 0;
  Block = 0;
  v81 = 0;
  v85 = 0;
  v83 = 0;
  v84 = 0;
  v82 = 1;
  if ( (*(int (__thiscall **)(_DWORD *, char *, int))(v5 + 36))(a2, Str, 512) )
  {
    do
    {
      v6 = sub_612EB0(v80);
      if ( v6 == 1 || v6 == 4 )
        break;
      if ( !v6 )
      {
        if ( v41 )
        {
          v7 = (const char *)sub_6331DF(Str, &unk_720738);
          if ( v7 )
          {
            v52 = v46 - 4;
            do
            {
              if ( sscanf(v7, off_720734, &v61) == 1 )
              {
                if ( v46 >= v3 )
                {
                  v49 = v3 + 128;
                  v8 = (double *)operator new(8 * (v3 + 128));
                  v9 = v46;
                  v10 = 0;
                  v11 = v8;
                  if ( v46 >= 4 )
                  {
                    v12 = Block + 3;
                    v13 = (char *)Block - (char *)v8;
                    v14 = (v52 >> 2) + 1;
                    v15 = v8 + 1;
                    v10 = 4 * v14;
                    do
                    {
                      v15 += 4;
                      *(v15 - 5) = *(v12 - 3);
                      v12 += 4;
                      --v14;
                      *(v15 - 4) = *(double *)((char *)v15 + v13 - 32);
                      *(v15 - 3) = *(v12 - 5);
                      *(v15 - 2) = *(v12 - 4);
                    }
                    while ( v14 );
                    v9 = v46;
                  }
                  if ( v10 < v9 )
                  {
                    v16 = &v11[v10];
                    v17 = v9 - v10;
                    do
                    {
                      v18 = *(double *)((char *)v16++ + (char *)Block - (char *)v11);
                      --v17;
                      *(v16 - 1) = v18;
                    }
                    while ( v17 );
                  }
                  if ( Block )
                    j_j__free(Block);
                  v3 = v49;
                  Block = v11;
                  v2 = this;
                }
                Block[v46++] = v61;
                ++v52;
              }
              else if ( (unsigned __int8)sub_5612D0(
                                           (int)byte_FAE910,
                                           1,
                                           "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp",
                                           290) )
              {
                sub_561210(
                  (int)byte_FAE910,
                  "Skipping unexpected data point \"%s\" in tire slip curve \"%s\"",
                  (char)v7);
              }
              v7 = (const char *)sub_6331DF(0, &unk_720738);
            }
            while ( v7 );
          }
          v4 = a2;
        }
        else
        {
          if ( sub_6131C0("Name", (int)v79) )
            sub_615860(v79);
          sub_6136D0("Step", (int)v63, 0, 0, 0);
          sub_6136D0("DropoffFunction", (int)v62, 0, 0, 0);
          if ( strstr(Str, "DATA:") )
            v41 = 1;
        }
      }
    }
    while ( (*(int (__thiscall **)(_DWORD *, char *, int))(*v4 + 36))(v4, Str, 512) );
  }
  if ( *(double *)v63 <= 0.0 )
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp", 304) )
    {
      v19 = *(const CHAR **)v2;
      if ( !v19 )
        v19 = WindowName;
      sub_561210((int)byte_FAE910, "Tire slip curve step must be positive for curve \"%s\"", (char)v19);
    }
    return;
  }
  if ( v46 < 3 )
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp", 313) )
      sub_561210((int)byte_FAE910, "Need at least %d data points found for tire slip curve \"%s\"", 3);
    return;
  }
  v20 = Block;
  if ( *Block != 0.0 )
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp", 321) )
    {
      v21 = *(const CHAR **)v2;
      if ( !v21 )
        v21 = WindowName;
      sub_561210((int)byte_FAE910, "First data point must be zero in tire slip curve \"%s\"", (char)v21);
    }
    return;
  }
  *((_DWORD *)v2 + 8) = v46;
  *((_DWORD *)v2 + 9) = operator new(32 * v46);
  if ( *((int *)v2 + 8) <= 3 )
    v22 = Block[1] - *Block;
  else
    v22 = (Block[2] - *Block + Block[2] - *Block - (Block[3] - Block[1])) * 0.5;
  v64[0] = &v65;
  v64[1] = v70;
  v23 = 0;
  v64[2] = &v72;
  v64[3] = v77;
  v24 = 0;
  while ( 1 )
  {
    v25 = *((_DWORD *)v2 + 8);
    if ( v23 >= v25 - 2 )
      break;
    v26 = (v20[v23 + 2] - v20[v23]) * 0.5;
LABEL_51:
    v55 = v26;
    v50 = (double)v23;
    v27 = v20[v23];
    v28 = v23 + 1;
    v65 = v50 * (v50 * v50);
    v66 = v50 * v50;
    v67 = v50;
    v68 = 1.0;
    v69 = v27;
    v70[0] = v66 * 3.0;
    v70[1] = v50 + v50;
    v70[2] = 1.0;
    v70[3] = 0.0;
    v71 = v22;
    v43 = (double)(v23 + 1);
    v53 = Block[v23 + 1];
    v72 = v43 * (v43 * v43);
    v73 = v43 * v43;
    v74 = v43;
    v75 = 1.0;
    v76 = v53;
    v77[0] = v73 * 3.0;
    v77[1] = v43 + v43;
    v77[2] = 1.0;
    v77[3] = 0.0;
    v78 = v55;
    if ( sub_6156E0(v64, 4) )
    {
      *(double *)(v24 + *((_DWORD *)v2 + 9)) = 0.0;
      *(double *)(v24 + *((_DWORD *)v2 + 9) + 8) = 0.0;
      *(double *)(v24 + *((_DWORD *)v2 + 9) + 16) = (v53 - v27) / (v43 - v50);
      v29 = *((_DWORD *)v2 + 9);
      v30 = v50 * *(double *)(v24 + v29 + 16);
      v31 = v24 + v29;
      v24 += 32;
      *(double *)(v31 + 24) = v27 - v30;
      v23 = v28;
      v22 = v55;
      v20 = Block;
    }
    else
    {
      *(double *)(v24 + *((_DWORD *)v2 + 9)) = v69;
      v24 += 32;
      *(double *)(v24 + *((_DWORD *)v2 + 9) - 24) = v71;
      *(double *)(v24 + *((_DWORD *)v2 + 9) - 16) = v76;
      v23 = v28;
      v20 = Block;
      *(double *)(v24 + *((_DWORD *)v2 + 9) - 8) = v78;
      v22 = v55;
    }
  }
  if ( v23 < v25 - 1 )
  {
    v26 = 0.0;
    goto LABEL_51;
  }
  v32 = 32 * v23;
  *(double *)(v32 + *((_DWORD *)v2 + 9)) = 0.0;
  *(double *)(v32 + *((_DWORD *)v2 + 9) + 8) = 0.0;
  *(double *)(v32 + *((_DWORD *)v2 + 9) + 16) = 0.0;
  *(double *)(v32 + *((_DWORD *)v2 + 9) + 24) = v20[v23];
  v33 = *((_DWORD *)v2 + 8);
  v34 = 0.0;
  v35 = 0;
  *((double *)v2 + 3) = 0.0;
  v47 = 0;
  if ( v33 > 0 )
  {
    v36 = (double *)*((_DWORD *)v2 + 9);
    do
    {
      v48 = (double)v47;
      v61 = v48 * ((v48 * *v36 + v36[1]) * v48 + v36[2]) + v36[3];
      if ( v61 > v34 )
      {
        v34 = v61;
        *((double *)v2 + 3) = v48;
      }
      v56 = *v36 * 3.0;
      if ( v56 != 0.0 )
      {
        v54 = v36[1] + v36[1];
        v37 = v54 * v54 - v56 * v36[2] * 4.0;
        if ( v37 >= 0.0 )
        {
          Blocka = sqrt(v37);
          v57 = -0.5 / v56;
          v44 = (Blocka + v54) * v57;
          if ( v44 > v48 && (double)(v35 + 1) > v44 )
          {
            v61 = ((v44 * *v36 + v36[1]) * v44 + v36[2]) * v44 + v36[3];
            if ( v61 > v34 )
            {
              v34 = v61;
              *((double *)v2 + 3) = v44;
            }
          }
          v45 = (v54 - Blocka) * v57;
          if ( v45 > v48 && (double)(v35 + 1) > v45 )
          {
            v61 = ((v45 * *v36 + v36[1]) * v45 + v36[2]) * v45 + v36[3];
            if ( v61 > v34 )
            {
              v34 = v61;
              *((double *)v2 + 3) = v45;
            }
          }
        }
      }
      v58 = (double)++v35;
      v61 = v58 * ((v58 * *v36 + v36[1]) * v58 + v36[2]) + v36[3];
      if ( v61 > v34 )
      {
        v34 = v61;
        *((double *)v2 + 3) = v58;
      }
      v36 += 4;
      v47 = v35;
    }
    while ( v35 < *((_DWORD *)v2 + 8) );
  }
  v38 = 0;
  v51 = 1.0 / v34;
  if ( v33 > 0 )
  {
    v39 = 0;
    do
    {
      ++v38;
      *(double *)(v39 + *((_DWORD *)v2 + 9)) = v51 * *(double *)(*((_DWORD *)v2 + 9) + v39);
      *(double *)(*((_DWORD *)v2 + 9) + v39 + 8) = v51 * *(double *)(*((_DWORD *)v2 + 9) + v39 + 8);
      *(double *)(*((_DWORD *)v2 + 9) + v39 + 16) = v51 * *(double *)(*((_DWORD *)v2 + 9) + v39 + 16);
      v40 = (double *)(*((_DWORD *)v2 + 9) + v39 + 24);
      v39 += 32;
      *v40 = v51 * *v40;
    }
    while ( v38 < *((_DWORD *)v2 + 8) );
  }
  *((double *)v2 + 1) = (1.0 - *(double *)v62) / (*(double *)v63 * *((double *)v2 + 3));
  *((double *)v2 + 2) = *(double *)v62;
  j_j__free(v20);
}
