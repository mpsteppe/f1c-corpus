int __usercall sub_46DE10@<eax>(int a1@<ecx>, int a2@<esi>)
{
  char v3; // bl
  int v4; // esi
  int v5; // eax
  int v6; // eax
  char *v7; // esi
  int v9; // eax
  int *v10; // esi
  _BYTE v12[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v13; // [esp+89h] [ebp-3h]
  char v14; // [esp+8Bh] [ebp-1h]

  v3 = 0;
  v4 = -1;
  if ( *(float *)(a1 + 228) > 0.0 )
  {
    v3 = 1;
    *(float *)(a1 + 228) = *(float *)(a1 + 228) - FloatFieldAccessor(*(_DWORD *)(a1 + 64));
  }
  v5 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a1 + 64) + 28))(*(_DWORD *)(a1 + 64), 34, a2);
  if ( v5 && FieldGetter(v5) < 0 )
  {
    v3 = 1;
    v12[0] = 1;
  }
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 56))(a1, *(_DWORD *)v12);
  if ( v3
    && (v12[0] = byte_5EA438[0],
        memset(&v12[1], 0, 0x7Cu),
        v13 = 0,
        v14 = 0,
        (v6 = EnumToEnumTranslator(dword_7CD25C, (int)v12)) != 0) )
  {
    v7 = sub_462DA0(v6);
    if ( BinarySearchInStringTable(byte_5EC4C0, v7, byte_5EC4CC) )
    {
      if ( v7 )
        strcpy(byte_5EC4CC, v7);
      else
        byte_5EC4CC[0] = 0;
    }
    StringCopyWithBufferRealloc(byte_5EC4CC);
    LookupDispatch(aJoinFailurePag, -1);
    *(_DWORD *)(a1 + 228) = 0;
    return -1;
  }
  else
  {
    if ( SessionStateCheck(dword_7CD25C) == 3 )
    {
      FAILWRONGDESCRIPTION(v12);
      if ( UniqueID(dword_7CD25C, (int)v12) )
      {
        if ( dword_7C569C != 5 )
        {
          if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6802) )
            DebugLogWrite(&dword_8AD25C, aJoinSessionWas);
          if ( dword_7C569C != 5 )
          {
            if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6803) )
              DebugLogWrite(&dword_8AD25C, aSessionNameS);
            if ( dword_7C569C != 5 )
            {
              if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6804) )
                DebugLogWrite(&dword_8AD25C, aSceneBaseS);
              if ( dword_7C569C != 5 )
              {
                if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6805) )
                  DebugLogWrite(&dword_8AD25C, aAiOppD);
                if ( dword_7C569C != 5 )
                {
                  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6806) )
                    DebugLogWrite(&dword_8AD25C, aHumanOppD);
                  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_28, 6807) )
                    DebugLogWrite(&dword_8AD25C, aMaxPlayersD);
                }
              }
            }
          }
        }
        v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 64) + 28))(*(_DWORD *)(a1 + 64), 34);
        if ( v9 )
          StateCleanupNotification(v9);
        ShortComputation_e170();
        PathPathRegistryWriter(&byte_7CE498);
        SessionConfigWriteback((int)v12);
        sub_4A0AF0(&unk_7CE24C);
        v10 = (int *)&MEMORY[0x5EC6E4];
        do
        {
          SessionStateTransition(-1, 0);
          v10 += 4656;
        }
        while ( (int)v10 < (int)&dword_7C54E4 );
        v4 = 0;
        dword_5C329C = 0;
        BuildActiveVehiclePointerArray();
        byte_7C5690 = 1;
        dword_7C56A0 = 2;
        LookupDispatch(aClientTeamSele, -1);
        *(_DWORD *)(a1 + 228) = 0;
      }
      EmptyStub_0170(v12);
    }
    return v4;
  }
}

