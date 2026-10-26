_DWORD **__thiscall sub_4B7500(int this, char a2)
{
  int i; // edi
  int v4; // edx
  int v5; // eax
  char v6; // cl
  int v7; // eax
  char *v8; // ecx
  char *v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  char v13; // cl
  const CHAR *v14; // eax
  char *v15; // eax
  char *v16; // eax
  int *v17; // eax
  int v18; // eax
  int v19; // eax
  int v21[7]; // [esp+10h] [ebp-41Ch] BYREF
  _BYTE v22[1024]; // [esp+2Ch] [ebp-400h] BYREF

  ListRebuildWithNodeTransfer((_DWORD *)(this + 3908));
  if ( *(_DWORD *)(this + 1764) )
  {
    if ( *(_DWORD *)(this + 1792) == 1 )
    {
      for ( i = 0; i < 104; ++i )
        sub_4B6190((_DWORD *)this, i);
      QueuePop(this);
      if ( dword_7C569C != 4 && *(float *)(this + 3892) - *(float *)(this + 3888) > 0.0 && a2 )
      {
        if ( BinarySearchInStringTable(byte_5EC4C0, aSavingReplay, byte_5EC4CC) )
        {
          v5 = 0;
          do
          {
            v6 = aSavingReplay[v5];
            byte_5EC4CC[v5++] = v6;
          }
          while ( v6 );
        }
        if ( SessionTypeGuard((int)&unk_7CE24D, v4, byte_5EC4CC) )
          Sleep(0x64u);
        ZeroInitSmallStruct(v21);
        switch ( *(_DWORD *)(this + 2468) )
        {
          case 0:
            v7 = 0;
            break;
          case 1:
            v7 = 1;
            break;
          case 2:
            v7 = 2;
            break;
          case 3:
            v7 = 3;
            break;
          default:
            v7 = 4;
            break;
        }
        v8 = *(char **)(this + 1804);
        if ( !v8 )
          v8 = byte_5EA438;
        sub_566940(v8, v7, 0, 1);
        VehicleForceAerodynamicsComputation(this, (int)v21, *(float *)(this + 3888), *(float *)(this + 3892));
        ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
        v9 = *(char **)(this + 1796);
        if ( !v9 )
          v9 = byte_5EA438;
        AudioStreamOpen(v9, 0);
        while ( 1 )
        {
          v10 = FileWriteWithBackendDispatch(v22, 1024);
          if ( v10 <= 0 )
            break;
          ConditionalDispatch_6bd0(v22, v10);
        }
        ConditionalFileHandleCloseWithFlagDispatch(v21);
        SubCallWithConditionalFieldFree(v21);
      }
      ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
      FileSettingExistenceCheck(this);
    }
    else if ( *(_BYTE *)(this + 1744) )
    {
      *(_BYTE *)(this + 1744) = 0;
      if ( BinarySearchInStringTable(byte_5EC4C0, aSavingReplay, byte_5EC4CC) )
      {
        v12 = 0;
        do
        {
          v13 = aSavingReplay[v12];
          byte_5EC4CC[v12++] = v13;
        }
        while ( v13 );
      }
      if ( SessionTypeGuard((int)&unk_7CE24D, v11, byte_5EC4CC) )
        Sleep(0x64u);
      v14 = *(const CHAR **)(this + 3988);
      if ( !v14 )
        v14 = byte_5EA438;
      FileAttributesExistenceCheck(v14);
      ZeroInitSmallStruct(v21);
      v15 = *(char **)(this + 3988);
      if ( !v15 )
        v15 = byte_5EA438;
      if ( (unsigned __int8)sub_566940(v15, 4, 0, 1) )
      {
        v16 = *(char **)(this + 1768);
        if ( !v16 )
          v16 = byte_5EA438;
        StringCopyWithBufferRealloc(v16);
        VehicleForceAerodynamicsComputation(this, (int)v21, *(float *)(this + 3888), *(float *)(this + 3892));
        v17 = *(int **)(this + 1812);
        *(_DWORD *)(this + 1820) = v17;
        if ( v17 )
        {
          v18 = *v17;
          if ( v18 )
          {
            sub_566DB0(*(_DWORD *)(v18 + 4));
            while ( 1 )
            {
              v19 = FileWriteWithBackendDispatch(v22, 1024);
              if ( v19 <= 0 )
                break;
              ConditionalDispatch_6bd0(v22, v19);
            }
            ConditionalFileHandleCloseWithFlagDispatch(v21);
            ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
            FileAttributesExistenceCheck(byte_5EA438);
          }
        }
      }
      SubCallWithConditionalFieldFree(v21);
    }
    else
    {
      ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
    }
  }
  *(_DWORD *)(this + 1792) = 0;
  return LinkedBufferTransfer((_DWORD *)this);
}

