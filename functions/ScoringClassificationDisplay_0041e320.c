void sub_41E320()
{
  int v0; // esi
  int v1; // eax
  int v2; // eax
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  LPVOID *v7; // ebp
  int v8; // edx
  LPVOID *v9; // edi
  char *v10; // eax
  char *v11; // eax
  int v12; // eax
  char *v13; // eax
  int v14; // ecx
  int v15; // edx
  char **v16; // eax
  int v17; // edx
  LPVOID *v18; // ebx
  char *v19; // ecx
  char **v20; // eax
  LPVOID *v21; // esi
  char *v22; // eax
  char *v23; // edi
  int v24; // eax
  int v25; // ecx
  char *v26; // eax
  int v27; // eax
  char *v28; // ecx
  char *v29; // eax
  char *v30; // edi
  int v31; // eax
  int v32; // esi
  char *v33; // edi
  char *v34; // ecx
  int v35; // ebx
  int v36; // eax
  bool v37; // zf
  bool v38; // cc
  char *v39; // eax
  int v40; // eax
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  char *v46; // eax
  int v47; // eax
  char *v48; // eax
  int v49; // [esp-18h] [ebp-50h]
  int v50; // [esp-18h] [ebp-50h]
  int v51; // [esp-14h] [ebp-4Ch]
  char **v52; // [esp+10h] [ebp-28h]
  LPVOID *v53; // [esp+14h] [ebp-24h]
  float v54[8]; // [esp+18h] [ebp-20h] BYREF

  if ( !dword_7D0308 || flt_7CF3C8 == 0.0 )
    return;
  StructInitWithSentinelValues(v54);
  v0 = 0;
  v53 = 0;
  v1 = LinkedListDereference(&dword_7D2DB0);
  v2 = FlagsGetter(v1);
  LOBYTE(v3) = 0;
  v4 = v2;
  v5 = sub_41F340(0, v3);
  LOBYTE(v6) = 0;
  v7 = (LPVOID *)v5;
  v9 = (LPVOID *)sub_41F5D0(0, v6);
  v52 = (char **)v9;
  if ( v7 )
  {
    v10 = (char *)*v7;
    if ( !*v7 )
      v10 = &byte_5EA438;
    LOBYTE(v8) = 1;
    v53 = (LPVOID *)sub_41F340(v10, v8);
  }
  if ( v9 )
  {
    v11 = (char *)*v9;
    if ( !*v9 )
      v11 = &byte_5EA438;
    LOBYTE(v8) = 1;
    v0 = sub_41F5D0(v11, v8);
  }
  v12 = LinkedListDereference(&dword_7D2DB0);
  if ( FlagsGetter(v12) == 1 )
  {
    if ( !v7 )
      return;
    v13 = (char *)*v7;
    if ( !*v7 )
      v13 = &byte_5EA438;
    v49 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v13);
    DriverDataTableLookupAndTimeConversion(v54, 483, v49, -1, -1, -1, -2.0, -2.0);
    goto LABEL_16;
  }
  if ( *(_DWORD *)(LinkedListDereference(&dword_7D2DB0) + 45380) == 3 )
  {
    GdbSeasonSelector(v7);
    goto LABEL_76;
  }
  if ( !v7 )
  {
    LOBYTE(v15) = 1;
    v16 = (char **)sub_41F340(0, v15);
    v18 = (LPVOID *)v16;
    if ( v16 )
    {
      v19 = *v16;
      if ( !*v16 )
        v19 = &byte_5EA438;
      LOBYTE(v17) = 1;
      v20 = (char **)sub_41F340(v19, v17);
      v21 = (LPVOID *)v20;
      if ( v20 )
      {
        v22 = *v20;
        if ( !*v21 )
          v22 = &byte_5EA438;
        v23 = (char *)*v18;
        if ( !*v18 )
          v23 = &byte_5EA438;
        v51 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v22);
        v24 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v23);
        DriverDataTableLookupAndTimeConversion(v54, 427, v24, v51, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v54);
        if ( *v21 )
          FreeWrapper_7bcf(*v21);
        FreeWrapper_7bcf(v21);
        v9 = (LPVOID *)v52;
      }
      if ( *v18 )
        FreeWrapper_7bcf(*v18);
      FreeWrapper_7bcf(v18);
      LOBYTE(v25) = 0;
      ConstructorStandingsParser(v25);
      goto LABEL_76;
    }
    goto LABEL_17;
  }
  if ( !v9 )
  {
    LOBYTE(v15) = 1;
    v9 = (LPVOID *)sub_41F5D0(0, v15);
    v52 = (char **)v9;
    if ( !v9 )
    {
      v26 = (char *)*v7;
      if ( !*v7 )
        v26 = &byte_5EA438;
LABEL_38:
      v27 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v26);
      DriverDataTableLookupAndTimeConversion(v54, 483, v27, -1, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v54);
      goto LABEL_17;
    }
  }
  v28 = (char *)*v9;
  if ( !*v9 )
    v28 = &byte_5EA438;
  v29 = (char *)*v7;
  if ( !*v7 )
    v29 = &byte_5EA438;
  if ( !sub_588410(v29, v28) )
  {
    if ( v53 && v0 )
    {
      v30 = *v52;
      if ( !*v52 )
        v30 = &byte_5EA438;
      v31 = ((int (*)(void))ChampionshipPointsAccumulator)();
      v32 = ChampionshipPointsAccumulator(v30, v4 - 1) - v31;
      v33 = (char *)*v7;
      if ( !*v7 )
        v33 = &byte_5EA438;
      v34 = (char *)*v53;
      if ( !*v53 )
        v34 = &byte_5EA438;
      v35 = ChampionshipPointsAccumulator(v34, -1);
      v36 = ChampionshipPointsAccumulator(v33, -1) - v35;
      v37 = v32 == v36;
      v38 = v32 < v36;
      v39 = (char *)*v7;
      if ( v38 )
      {
        if ( !v39 )
          v39 = &byte_5EA438;
        v40 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v39);
        DriverDataTableLookupAndTimeConversion(v54, 485, v40, -1, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v54);
        v9 = (LPVOID *)v52;
        LOBYTE(v41) = 0;
        ConstructorStandingsParser(v41);
      }
      else if ( v37 )
      {
        if ( !v39 )
          v39 = &byte_5EA438;
        v42 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v39);
        DriverDataTableLookupAndTimeConversion(v54, 486, v42, -1, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v54);
        v9 = (LPVOID *)v52;
        LOBYTE(v43) = 0;
        ConstructorStandingsParser(v43);
      }
      else
      {
        if ( !v39 )
          v39 = &byte_5EA438;
        v44 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v39);
        DriverDataTableLookupAndTimeConversion(v54, 487, v44, -1, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v54);
        v9 = (LPVOID *)v52;
        LOBYTE(v45) = 0;
        ConstructorStandingsParser(v45);
      }
      goto LABEL_76;
    }
    v46 = (char *)*v7;
    if ( !*v7 )
      v46 = &byte_5EA438;
    v47 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v46);
    DriverDataTableLookupAndTimeConversion(v54, 486, v47, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v54);
    goto LABEL_17;
  }
  v48 = (char *)*v7;
  if ( !*v7 )
    v48 = &byte_5EA438;
  v37 = (unsigned __int8)ConstructorChampionshipClinchDetection(v48) == 0;
  v26 = (char *)*v7;
  if ( v37 )
  {
    if ( !v26 )
      v26 = &byte_5EA438;
    goto LABEL_38;
  }
  if ( !v26 )
    v26 = &byte_5EA438;
  v50 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v26);
  DriverDataTableLookupAndTimeConversion(v54, 484, v50, -1, -1, -1, -2.0, -2.0);
LABEL_16:
  InsertDriverTableEntry(flt_5EA618, v54);
LABEL_17:
  LOBYTE(v14) = 0;
  ConstructorStandingsParser(v14);
LABEL_76:
  if ( v7 )
  {
    if ( *v7 )
      FreeWrapper_7bcf(*v7);
    FreeWrapper_7bcf(v7);
  }
  if ( v9 )
  {
    if ( *v9 )
      FreeWrapper_7bcf(*v9);
    FreeWrapper_7bcf(v9);
  }
  if ( v53 )
  {
    if ( *v53 )
      FreeWrapper_7bcf(*v53);
    FreeWrapper_7bcf(v53);
  }
}
