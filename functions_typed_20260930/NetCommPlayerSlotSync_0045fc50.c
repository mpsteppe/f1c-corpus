char __thiscall NetCommPlayerSlotSync(_DWORD *this)
{
  _DWORD *v1; // ebx
  char result; // al
  int v3; // esi
  char *v4; // ebp
  int v5; // ebx
  char *v6; // esi
  int v7; // edi
  _BYTE *v8; // eax
  _BYTE *v9; // eax
  int v10; // edi
  int v11; // eax
  char v12; // cl
  bool v13; // cc
  char *v14; // ebp
  int v15; // eax
  char v16; // cl
  int v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // kr08_4
  char *v20; // esi
  _BYTE **v21; // eax
  _BYTE *v22; // edi
  int v23; // eax
  _BYTE **v24; // eax
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  char i; // [esp+18h] [ebp-180h]
  char v30; // [esp+19h] [ebp-17Fh]
  char v31; // [esp+1Ah] [ebp-17Eh]
  char v32; // [esp+1Bh] [ebp-17Dh]
  char *v33; // [esp+1Ch] [ebp-17Ch]
  int v34; // [esp+1Ch] [ebp-17Ch]
  int v35; // [esp+20h] [ebp-178h]
  int v36; // [esp+20h] [ebp-178h]
  int v37; // [esp+24h] [ebp-174h]
  int v39; // [esp+2Ch] [ebp-16Ch]
  _BYTE v40[104]; // [esp+30h] [ebp-168h] BYREF
  _BYTE v41[256]; // [esp+98h] [ebp-100h] BYREF

  v1 = this;
  result = *((_BYTE *)this + 884);
  v3 = 0;
  if ( !result )
  {
    memset(v40, 0, sizeof(v40));
    i = 0;
    v30 = 0;
    v32 = 0;
    v37 = 0;
    v35 = 0;
    if ( (int)this[3973] > 0 )
    {
      v4 = (char *)(this + 244);
      v33 = (char *)(this + 244);
      do
      {
        if ( FlagBitTest(v4 - 60, 2) )
        {
          ++v37;
          if ( strlen(v4) )
          {
            v5 = v4[64];
            v6 = (char *)&stru_5EC6D8 + 18624 * v5;
            v7 = *((_DWORD *)v6 + 445);
            v39 = v5;
            v31 = 0;
            v8 = PathFilenameExtractor((int)v6);
            if ( sub_588410(v8, v4) || !v7 || *((_DWORD *)v6 + 3250) == -1 )
            {
              TwoCallDelegation(v6, v4);
              StringCopyWithBufferRealloc((int)(v6 + 1920), v4 + 32);
              v9 = PathFilenameExtractor((int)v6);
              if ( !sub_588410(v9, v4) || !v7 )
              {
                sub_45C030(&this[14 * v5 + 28136]);
                ThunkWithStructInitSubCalls(&this[218 * v5 + 4192]);
                PerElementArrayReset(this + 26864, v5);
                if ( v5 == IDLookupInArray((void *)*this) )
                {
                  if ( !*((_DWORD *)v6 + 4121) || *((_DWORD *)v6 + 3250) == -1 )
                    SessionStateTransition((float *)v6 + 3, 0, 0);
                  SetPlayerVehicleIndex_bc40(v5);
                }
                else
                {
                  SessionStateTransition((float *)v6 + 3, (_DWORD *)2, 0);
                }
                ConditionalFieldSetter((int)(v6 + 16436), v5 + 1);
                FieldCopy((int)(v6 + 16436));
                if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 4014) )
                  DebugLogWrite(
                    (int)dword_8AD25C,
                    (int)"*** LOADING Slot (index %d, \"%s\") @ et=%8.4f",
                    v5,
                    v4,
                    dbl_8AFEA0);
                ++dword_5C329C;
                BuildActiveVehiclePointerArray();
                VehgenScnFileLoader((int)v6, 1);
                SceneRenderUpdate((int *)v6, COERCE_FLOAT(1));
                LoopOverTwoParallelArrays(dword_8ACEE0);
                if ( *((_DWORD *)v6 + 3250) )
                {
                  v31 = 1;
                  v30 = 1;
                  ShortComputation_5430(*((_DWORD *)v6 + 4645), v4[65]);
                }
                else
                {
                  if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 4038) )
                    DebugLogWrite((int)dword_8AD25C, (int)aSlotIsTaggedAs);
                  v10 = 0;
                  for ( i = 1; v10 < dword_5C329C; ++v10 )
                    AudioSoundEffectController((_DWORD *)(LODWORD(dword_7C54F0[v10]) + 1776), 0);
                  SetPlayerVehicleIndex(v5);
                  GameStateBranchDispatch(&dword_5EA510);
                  CockpitDashboardLEDGaugeSetup(&dword_7CE058);
                  PhysicsSubsystemStep((const char **)&dword_7C73E8, v5);
                }
              }
            }
            sub_587DD0(v6 + 18016, v33 - 24, 0x17u);
            v6[18039] = 0;
            if ( strcmp(v6 + 17952, v33 - 56) )
              SetDriverName(v6, (int)(v33 - 56));
            if ( v31 )
            {
              if ( BinarySearchInStringTable(byte_5EC4C0, aHasEnteredTheG, byte_5EC4CC) )
              {
                v11 = 0;
                do
                {
                  v12 = aHasEnteredTheG[v11];
                  byte_5EC4CC[v11++] = v12;
                }
                while ( v12 );
              }
              StringFormatWithBufferOverflowCheck(v41, (int)"%s %s", v6 + 17952, byte_5EC4CC);
              TextLineWrappingAndRendering(&dword_7CD204, (int)v41, 3, 16909060);
            }
            v4 = v33;
            v1 = this;
            v40[v39] = 1;
          }
        }
        v4 += 140;
        v13 = ++v35 < v1[3973];
        v33 = v4;
      }
      while ( v13 );
      v3 = 0;
    }
    v34 = 0;
    v36 = 0;
    v14 = (char *)&stru_5EC6D8;
    do
    {
      if ( !v40[v3] && *((_DWORD *)v14 + 3250) != -1 )
      {
        if ( BinarySearchInStringTable(byte_5EC4C0, aLeftTheGame, byte_5EC4CC) )
        {
          v15 = 0;
          do
          {
            v16 = aLeftTheGame[v15];
            byte_5EC4CC[v15++] = v16;
          }
          while ( v16 );
        }
        StringFormatWithBufferOverflowCheck(v41, (int)"%s %s", v14 + 17952, byte_5EC4CC);
        TextLineWrappingAndRendering(&dword_7CD204, (int)v41, 3, 16909060);
        if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 4111) )
          DebugLogWrite(
            (int)dword_8AD25C,
            (int)"*** UNLOADING Slot (index %d) @ et=%8.4f",
            *((_DWORD *)v14 + 4645),
            dbl_8AFEA0);
        v17 = v1[4081];
        v32 = 1;
        if ( v17 == 2 || v17 == 1 )
        {
          v18 = (unsigned int)(v14 + 18196);
          v19 = strlen(v14 + 18196) + 1;
          v20 = &v14[v19 + 18195];
          if ( v18 + v19 - 1 > v18 )
          {
            while ( *v20 != 92 )
            {
              if ( (unsigned int)--v20 <= v18 )
                goto LABEL_54;
            }
            ++v20;
          }
LABEL_54:
          v21 = (_BYTE **)v1[4082];
          v1[4084] = v21;
          if ( v21 )
          {
            v22 = *v21;
            if ( *v21 )
            {
              while ( sub_588410(v22, v20) )
              {
                v23 = v1[4084];
                if ( v23 )
                  v1[4084] = *(_DWORD *)(v23 + 4);
                v24 = (_BYTE **)v1[4084];
                if ( v24 )
                {
                  v22 = *v24;
                  if ( *v24 )
                    continue;
                }
                goto LABEL_77;
              }
              if ( v22 )
              {
                v25 = v1[4082];
                v26 = 0;
                if ( v25 )
                {
                  while ( *(_BYTE **)v25 != v22 )
                  {
                    v26 = v25;
                    v25 = *(_DWORD *)(v25 + 4);
                    if ( !v25 )
                      goto LABEL_77;
                  }
                  if ( v25 == v1[4084] )
                    v1[4084] = *(_DWORD *)(v25 + 4);
                  if ( v26 )
                    *(_DWORD *)(v26 + 4) = *(_DWORD *)(v25 + 4);
                  else
                    v1[4082] = *(_DWORD *)(v25 + 4);
                  if ( v1[4083] == v25 )
                    v1[4083] = v26;
                  --v1[4085];
                  if ( *(_BYTE *)(v25 + 8) )
                    FreeWrapper_7bcf(*(LPVOID *)v25);
                  FreeWrapper_7bcf((LPVOID)v25);
                }
              }
            }
          }
        }
LABEL_77:
        sub_4C6E80(v14);
        SessionStateTransition((float *)v14 + 3, (_DWORD *)0xFFFFFFFF, 0);
        v3 = v36;
        ++v34;
        if ( *(_DWORD *)(LODWORD(dword_7C54F0[dword_7C54DC]) + 18580) == v36 )
        {
          v27 = *(_DWORD *)(LODWORD(dword_7C54F0[dword_7C54E4]) + 18580);
          if ( MEMORY[0x5EF9A0][4656 * v27] == -1 )
          {
            v28 = 0;
            if ( dword_5C329C > 0 )
            {
              while ( *(_DWORD *)(LODWORD(dword_7C54F0[v28]) + 13000) == -1 )
              {
                if ( ++v28 >= dword_5C329C )
                  goto LABEL_85;
              }
              dword_7C54DC = v28;
              dword_7C54E0 = LODWORD(dword_7C54F0[v28]);
            }
          }
          else
          {
            SetPlayerVehicleIndex(v27);
          }
        }
LABEL_85:
        if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_1, 4164) )
          DebugLogWrite((int)dword_8AD25C, (int)"*** Unsetting Slot (index %d)", v36);
      }
      ++v3;
      v14 += 18624;
      v36 = v3;
    }
    while ( (int)v14 < (int)byte_7C54D8 );
    if ( v34 > 0 )
    {
      ClearPlayerSlots(v1, 1);
      dword_5C329C -= v34;
      BuildActiveVehiclePointerArray();
    }
    if ( v1[4081] != 1 )
    {
      if ( i )
        SoundEffectLoadPlay(0, 1065353216);
      if ( v30 )
        SoundEffectLoadPlay(1u, 1065353216);
      if ( v32 )
        SoundEffectLoadPlay(2u, 1065353216);
    }
    result = v37;
    if ( v37 != dword_5C329C )
    {
      dword_5C329C = v37;
      return BuildActiveVehiclePointerArray();
    }
  }
  return result;
}

