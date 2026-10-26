void sub_41DAF0()
{
  int v0; // edx
  int v1; // eax
  int v2; // edx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  char *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char *v9; // eax
  char *v10; // ebp
  int v11; // edi
  int v12; // ebx
  int v13; // ebp
  bool v14; // cc
  char *v15; // eax
  char *v16; // ecx
  const char *v17; // eax
  const char *v18; // eax
  bool v19; // zf
  const char *v20; // ecx
  int v21; // ebx
  int v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  char *v30; // eax
  char *v31; // ecx
  const char *v32; // edi
  char *v33; // ebp
  const char *v34; // esi
  char *v35; // ecx
  const char *v36; // eax
  char *v37; // eax
  char *v38; // ecx
  const char *v39; // edi
  char *v40; // ebp
  const char *v41; // esi
  char *v42; // ecx
  const char *v43; // eax
  char *v44; // eax
  char *v45; // ecx
  const char *v46; // edi
  char *v47; // ebp
  const char *v48; // esi
  char *v49; // ecx
  const char *v50; // eax
  char *v51; // eax
  char *v52; // ecx
  const char *v53; // edi
  char *v54; // ebp
  const char *v55; // esi
  char *v56; // ecx
  const char *v57; // eax
  char *v58; // eax
  char *v59; // ecx
  const char *v60; // eax
  char *v61; // eax
  char *v62; // ecx
  const char *v63; // eax
  char *v64; // eax
  char *v65; // ecx
  const char *v66; // eax
  char *v67; // eax
  char *v68; // ecx
  const char *v69; // eax
  int v70; // ecx
  int v71; // [esp-18h] [ebp-48h]
  int v72; // [esp-18h] [ebp-48h]
  int v73; // [esp-18h] [ebp-48h]
  int v74; // [esp-18h] [ebp-48h]
  int v75; // [esp-18h] [ebp-48h]
  int v76; // [esp-18h] [ebp-48h]
  int v77; // [esp-18h] [ebp-48h]
  int v78; // [esp-18h] [ebp-48h]
  int v79; // [esp-18h] [ebp-48h]
  int v80; // [esp-18h] [ebp-48h]
  int v81; // [esp-18h] [ebp-48h]
  int v82; // [esp-18h] [ebp-48h]
  int v83; // [esp-18h] [ebp-48h]
  int v84; // [esp-18h] [ebp-48h]
  int v85; // [esp-18h] [ebp-48h]
  int v86; // [esp-18h] [ebp-48h]
  int v87; // [esp-14h] [ebp-44h]
  int v88; // [esp-14h] [ebp-44h]
  int v89; // [esp-14h] [ebp-44h]
  int v90; // [esp-14h] [ebp-44h]
  float v91[8]; // [esp+10h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v91);
    CommentaryEventQueue(v91, 478, -1, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v91);
    StructInitWithSentinelValues(v91);
    LOBYTE(v0) = 0;
    v1 = BestLapEntrantFinder(0, v0);
    LOBYTE(v2) = 0;
    v3 = v1;
    v4 = ScoringSessionStatsAggregator(0, v2);
    v5 = LinkedListDereference(&dword_7D2DB0);
    if ( FlagsGetter(v5) == 1 )
    {
      if ( !v3 )
        return;
    }
    else
    {
      if ( *(_DWORD *)(LinkedListDereference(&dword_7D2DB0) + 45380) == 3 )
      {
        if ( v3 )
        {
          v58 = (char *)dword_7D0434;
          if ( !dword_7D0434 )
            v58 = &byte_5EA438;
          if ( sub_588410(v58, aF11999Gdb) )
          {
            v61 = (char *)dword_7D0434;
            if ( !dword_7D0434 )
              v61 = &byte_5EA438;
            if ( sub_588410(v61, aF12000Gdb) )
            {
              v64 = (char *)dword_7D0434;
              if ( !dword_7D0434 )
                v64 = &byte_5EA438;
              if ( sub_588410(v64, aF12001Gdb) )
              {
                v67 = (char *)dword_7D0434;
                if ( !dword_7D0434 )
                  v67 = &byte_5EA438;
                if ( !sub_588410(v67, aF12002Gdb) )
                {
                  v68 = *(char **)(v3 + 8);
                  if ( !v68 )
                    v68 = &byte_5EA438;
                  v69 = *(const char **)v3;
                  if ( !*(_DWORD *)v3 )
                    v69 = &byte_5EA438;
                  v86 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v69, (int)v68);
                  CommentaryEventQueue(v91, 502, v86, -1, -1, -1, -2.0, -2.0);
                }
              }
              else
              {
                v65 = *(char **)(v3 + 8);
                if ( !v65 )
                  v65 = &byte_5EA438;
                v66 = *(const char **)v3;
                if ( !*(_DWORD *)v3 )
                  v66 = &byte_5EA438;
                v85 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v66, (int)v65);
                CommentaryEventQueue(v91, 498, v85, -1, -1, -1, -2.0, -2.0);
              }
            }
            else
            {
              v62 = *(char **)(v3 + 8);
              if ( !v62 )
                v62 = &byte_5EA438;
              v63 = *(const char **)v3;
              if ( !*(_DWORD *)v3 )
                v63 = &byte_5EA438;
              v84 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v63, (int)v62);
              CommentaryEventQueue(v91, 494, v84, -1, -1, -1, -2.0, -2.0);
            }
          }
          else
          {
            v59 = *(char **)(v3 + 8);
            if ( !v59 )
              v59 = &byte_5EA438;
            v60 = *(const char **)v3;
            if ( !*(_DWORD *)v3 )
              v60 = &byte_5EA438;
            v83 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v60, (int)v59);
            CommentaryEventQueue(v91, 490, v83, -1, -1, -1, -2.0, -2.0);
          }
        }
        else
        {
          v21 = 0;
          v22 = 0;
          v23 = LinkedListDereference(&dword_7D2DB0);
          if ( !*(_DWORD *)(FixedOffsetReturn(v23) + 412) )
          {
            v24 = LinkedListDereference(&dword_7D2DB0);
            v21 = FixedOffsetReturn(v24);
          }
          v25 = 0;
          v26 = LinkedListDereference(&dword_7D2DB0);
          if ( ActiveEntityCounter(v26) > 0 )
          {
            do
            {
              LinkedListDereference(&dword_7D2DB0);
              if ( !*(_DWORD *)(ShortComputation_13a0(v25) + 412) )
              {
                LinkedListDereference(&dword_7D2DB0);
                v27 = ShortComputation_13a0(v25);
                if ( v21 )
                {
                  if ( ObjectComparisonWithTiebreak(v21, v27) == v21 )
                  {
                    LinkedListDereference(&dword_7D2DB0);
                    v28 = ShortComputation_13a0(v25);
                    if ( ObjectComparisonWithTiebreak(v22, v28) != v22 )
                    {
                      LinkedListDereference(&dword_7D2DB0);
                      v22 = ShortComputation_13a0(v25);
                    }
                  }
                  else
                  {
                    v22 = v21;
                    LinkedListDereference(&dword_7D2DB0);
                    v21 = ShortComputation_13a0(v25);
                  }
                }
                else
                {
                  v21 = v27;
                }
              }
              ++v25;
              v29 = LinkedListDereference(&dword_7D2DB0);
            }
            while ( v25 < ActiveEntityCounter(v29) );
          }
          if ( v21 )
          {
            v30 = (char *)dword_7D0434;
            if ( !dword_7D0434 )
              v30 = &byte_5EA438;
            if ( sub_588410(v30, aF11999Gdb) )
            {
              v37 = (char *)dword_7D0434;
              if ( !dword_7D0434 )
                v37 = &byte_5EA438;
              if ( sub_588410(v37, aF12000Gdb) )
              {
                v44 = (char *)dword_7D0434;
                if ( !dword_7D0434 )
                  v44 = &byte_5EA438;
                if ( sub_588410(v44, aF12001Gdb) )
                {
                  v51 = (char *)dword_7D0434;
                  if ( !dword_7D0434 )
                    v51 = &byte_5EA438;
                  if ( !sub_588410(v51, aF12002Gdb) )
                  {
                    if ( v22 )
                    {
                      v52 = *(char **)(v22 + 8);
                      if ( !v52 )
                        v52 = &byte_5EA438;
                      v53 = *(const char **)v22;
                      if ( !v53 )
                        v53 = &byte_5EA438;
                      v54 = *(char **)(v21 + 8);
                      if ( !v54 )
                        v54 = &byte_5EA438;
                      v55 = *(const char **)v21;
                      if ( !*(_DWORD *)v21 )
                        v55 = &byte_5EA438;
                      v90 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v53, (int)v52);
                      v81 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v55, (int)v54);
                      CommentaryEventQueue(v91, 503, v81, v90, -1, -1, -2.0, -2.0);
                    }
                    else
                    {
                      v56 = *(char **)(v21 + 8);
                      if ( !v56 )
                        v56 = &byte_5EA438;
                      v57 = *(const char **)v21;
                      if ( !*(_DWORD *)v21 )
                        v57 = &byte_5EA438;
                      v82 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v57, (int)v56);
                      CommentaryEventQueue(v91, 502, v82, -1, -1, -1, -2.0, -2.0);
                    }
                  }
                }
                else if ( v22 )
                {
                  v45 = *(char **)(v22 + 8);
                  if ( !v45 )
                    v45 = &byte_5EA438;
                  v46 = *(const char **)v22;
                  if ( !v46 )
                    v46 = &byte_5EA438;
                  v47 = *(char **)(v21 + 8);
                  if ( !v47 )
                    v47 = &byte_5EA438;
                  v48 = *(const char **)v21;
                  if ( !*(_DWORD *)v21 )
                    v48 = &byte_5EA438;
                  v89 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v46, (int)v45);
                  v79 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v48, (int)v47);
                  CommentaryEventQueue(v91, 499, v79, v89, -1, -1, -2.0, -2.0);
                }
                else
                {
                  v49 = *(char **)(v21 + 8);
                  if ( !v49 )
                    v49 = &byte_5EA438;
                  v50 = *(const char **)v21;
                  if ( !*(_DWORD *)v21 )
                    v50 = &byte_5EA438;
                  v80 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v50, (int)v49);
                  CommentaryEventQueue(v91, 498, v80, -1, -1, -1, -2.0, -2.0);
                }
              }
              else if ( v22 )
              {
                v38 = *(char **)(v22 + 8);
                if ( !v38 )
                  v38 = &byte_5EA438;
                v39 = *(const char **)v22;
                if ( !v39 )
                  v39 = &byte_5EA438;
                v40 = *(char **)(v21 + 8);
                if ( !v40 )
                  v40 = &byte_5EA438;
                v41 = *(const char **)v21;
                if ( !*(_DWORD *)v21 )
                  v41 = &byte_5EA438;
                v88 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v39, (int)v38);
                v77 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v41, (int)v40);
                CommentaryEventQueue(v91, 495, v77, v88, -1, -1, -2.0, -2.0);
              }
              else
              {
                v42 = *(char **)(v21 + 8);
                if ( !v42 )
                  v42 = &byte_5EA438;
                v43 = *(const char **)v21;
                if ( !*(_DWORD *)v21 )
                  v43 = &byte_5EA438;
                v78 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v43, (int)v42);
                CommentaryEventQueue(v91, 494, v78, -1, -1, -1, -2.0, -2.0);
              }
            }
            else if ( v22 )
            {
              v31 = *(char **)(v22 + 8);
              if ( !v31 )
                v31 = &byte_5EA438;
              v32 = *(const char **)v22;
              if ( !v32 )
                v32 = &byte_5EA438;
              v33 = *(char **)(v21 + 8);
              if ( !v33 )
                v33 = &byte_5EA438;
              v34 = *(const char **)v21;
              if ( !*(_DWORD *)v21 )
                v34 = &byte_5EA438;
              v87 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v32, (int)v31);
              v75 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v34, (int)v33);
              CommentaryEventQueue(v91, 491, v75, v87, -1, -1, -2.0, -2.0);
            }
            else
            {
              v35 = *(char **)(v21 + 8);
              if ( !v35 )
                v35 = &byte_5EA438;
              v36 = *(const char **)v21;
              if ( !*(_DWORD *)v21 )
                v36 = &byte_5EA438;
              v76 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v36, (int)v35);
              CommentaryEventQueue(v91, 490, v76, -1, -1, -1, -2.0, -2.0);
            }
            InsertDriverTableEntry(flt_5EA618, v91);
          }
        }
        goto LABEL_155;
      }
      if ( !v3 )
      {
LABEL_155:
        InsertDriverTableEntry(flt_5EA618, v91);
        LOBYTE(v70) = 0;
        PositionChangeDetector(v70);
        return;
      }
      if ( v4 || (LOBYTE(v8) = 1, (v4 = ScoringSessionStatsAggregator(0, v8)) != 0) )
      {
        if ( v3 == v4 )
        {
          v9 = *(char **)v3;
          v10 = *(char **)v3;
          if ( !*(_DWORD *)v3 )
            v10 = &byte_5EA438;
          v11 = *(_DWORD *)(v3 + 408);
          if ( !v9 )
            v9 = &byte_5EA438;
          LOBYTE(v8) = 1;
          v12 = *(_DWORD *)(BestLapEntrantFinder(v9, v8) + 408);
          v13 = CRTMathHelper(v10);
          v14 = CRTMathHelper(0) - v13 < v11 - v12;
          v15 = *(char **)(v3 + 8);
          v16 = v15;
          if ( v14 )
          {
            if ( !v15 )
              v16 = &byte_5EA438;
            v17 = *(const char **)v3;
            if ( !*(_DWORD *)v3 )
              v17 = &byte_5EA438;
            v72 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v17, (int)v16);
            CommentaryEventQueue(v91, 481, v72, -1, -1, -1, -2.0, -2.0);
          }
          else
          {
            if ( !v15 )
              v16 = &byte_5EA438;
            v18 = *(const char **)v3;
            if ( !*(_DWORD *)v3 )
              v18 = &byte_5EA438;
            v73 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v18, (int)v16);
            CommentaryEventQueue(v91, 397, v73, 1, -1, -1, -2.0, -2.0);
          }
          goto LABEL_155;
        }
        v19 = (unsigned __int8)ChampionshipScore(v3) == 0;
        v6 = *(char **)(v3 + 8);
        if ( !v19 )
        {
          if ( !v6 )
            v6 = &byte_5EA438;
          v20 = *(const char **)v3;
          if ( !*(_DWORD *)v3 )
            v20 = &byte_5EA438;
          v74 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v20, (int)v6);
          CommentaryEventQueue(v91, 480, v74, -1, -1, -1, -2.0, -2.0);
          goto LABEL_155;
        }
        goto LABEL_6;
      }
    }
    v6 = *(char **)(v3 + 8);
LABEL_6:
    if ( !v6 )
      v6 = &byte_5EA438;
    v7 = *(const char **)v3;
    if ( !*(_DWORD *)v3 )
      v7 = &byte_5EA438;
    v71 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v7, (int)v6);
    CommentaryEventQueue(v91, 479, v71, -1, -1, -1, -2.0, -2.0);
    goto LABEL_155;
  }
}

