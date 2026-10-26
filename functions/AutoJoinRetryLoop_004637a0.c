char __thiscall sub_4637A0(_DWORD *this)
{
  char result; // al
  void *v3; // ecx
  int v4; // ebp
  int v5; // eax
  char v6; // cl
  double v7; // st7
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int *v11; // esi
  char *v12; // edi
  float v13; // [esp+0h] [ebp-100h]
  float v14; // [esp+18h] [ebp-E8h]
  int v15; // [esp+1Ch] [ebp-E4h]
  int v16; // [esp+20h] [ebp-E0h]
  int v17; // [esp+24h] [ebp-DCh]
  float v18; // [esp+28h] [ebp-D8h]
  _BYTE v19[8]; // [esp+2Ch] [ebp-D4h] BYREF
  _BYTE v20[76]; // [esp+34h] [ebp-CCh] BYREF
  _BYTE v21[128]; // [esp+80h] [ebp-80h] BYREF

  result = 0;
  if ( *(_BYTE *)(*this + 198) )
  {
    dword_7D0410 = 5;
    if ( dword_7D0418 <= 5 )
    {
      if ( dword_7D041C < 5 )
        dword_7D0410 = dword_7D041C;
    }
    else
    {
      dword_7D0410 = dword_7D0418;
    }
    SingleFunctionCallWrapper_a920(*(_DWORD *)(*this + 16312));
    v16 = ConstantOffsetAccessor(this, 0);
    if ( CollisionSpatialQuery(v3, *this + 200, v16) )
    {
      if ( LookupDispatch(aAutojoinWaitPa, -1) )
      {
        StructZeroInit_8ba0(v20);
        QPCTimerInitialization(1);
        TimerResetUsingQueryPerformanceCounter(v20);
        v14 = 0.0;
        v4 = 0;
        v15 = 1;
        while ( 1 )
        {
          if ( BinarySearchInStringTable(byte_5EC4C0, aJoiningSession, byte_5EC4CC) )
          {
            v5 = 0;
            do
            {
              v6 = aJoiningSession[v5];
              byte_5EC4CC[v5++] = v6;
            }
            while ( v6 );
          }
          StringCopyWithBufferRealloc(byte_5EC4CC);
          sub_5665B0(asc_5C65C4);
          v19[0] = 0;
          v7 = PerformanceCounterDiffWithScaling(v20);
          v8 = CRTFtol(flt_7D0F28 - v7);
          StringFormatWithBufferOverflowCheck(v19, "%d", v8);
          sub_5665B0(v19);
          v13 = dbl_8AFE90;
          sub_4537B0((int)&ppvOut, v13);
          v9 = v4;
          LOBYTE(v10) = 0;
          ++v4;
          sub_485B90(v9, v10);
          ArithmeticComparison_9ad0(&unk_8AFE18);
          sub_4A1830(&unk_7CE2A4);
          if ( dword_5CC9E8 == -1 )
            goto LABEL_32;
          v18 = HighResolutionTimerDelta(v20);
          if ( SessionStateCheck(this) == 3 )
          {
            if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7303) )
              DebugLogWrite(&dword_8AD25C, aAutojoinAttemp);
            FAILWRONGDESCRIPTION(v21);
            if ( UniqueID(dword_7CD25C, (int)v21) )
            {
              PathPathRegistryWriter(&byte_7CE498);
              SessionConfigWriteback((int)v21);
              v11 = (int *)&unk_5EC6E4;
              do
              {
                SessionStateTransition(-1, 0);
                v11 += 4656;
              }
              while ( (int)v11 < (int)&dword_7C54E4 );
              dword_5C329C = 0;
              BuildActiveVehiclePointerArray();
              byte_7C5690 = 1;
              dword_7C56A0 = 2;
              sub_4A0AF0(&unk_7CE24C);
              LookupDispatch(aClientTeamSele, -1);
              EmptyStub_0170(v20);
              return 1;
            }
          }
          else if ( PerformanceCounterDiffWithScaling(v20) > flt_7D0F28 || (v17 = EnumToEnumTranslator(this, 0)) != 0 )
          {
            v12 = sub_462DA0(5);
            if ( BinarySearchInStringTable(byte_5EC4C0, v12, byte_5EC4CC) )
            {
              if ( v12 )
                strcpy(byte_5EC4CC, v12);
              else
                byte_5EC4CC[0] = 0;
            }
            CallWrapper(byte_5EC4CC);
            if ( v17 != 3 )
            {
              LookupDispatch(aAutojoinFailur, -1);
              ShortComputation_7250(1);
LABEL_32:
              EmptyStub_0170(v20);
              return 0;
            }
          }
          if ( v14 > 10.0 )
          {
            CollisionSpatialQuery(this, *this + 200, v16);
            ++v15;
            v14 = 0.0;
          }
          v14 = v18 + v14;
        }
      }
      if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7381) )
      {
        DebugLogWrite(&dword_8AD25C, aCouldNotSwitch);
        return 0;
      }
    }
    else if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 7387) )
    {
      DebugLogWrite(&dword_8AD25C, aCouldNotAutojo);
    }
    return 0;
  }
  return result;
}
