int __thiscall sub_432E70(int this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  void *v5; // ebp
  int result; // eax
  LPVOID *v7; // eax
  LPVOID *v8; // esi
  int v9; // eax
  _DWORD v10[7]; // [esp+10h] [ebp-434h] BYREF
  char v11[384]; // [esp+2Ch] [ebp-418h] BYREF
  int v12; // [esp+1ACh] [ebp-298h]
  char v13; // [esp+1B0h] [ebp-294h]
  int v14; // [esp+1B8h] [ebp-28Ch]
  int v15; // [esp+1BCh] [ebp-288h]
  int v16; // [esp+1C0h] [ebp-284h]
  _BYTE v17[384]; // [esp+1C4h] [ebp-280h] BYREF
  _BYTE v18[256]; // [esp+344h] [ebp-100h] BYREF

  sub_432DF0((const char **)this, (int)&byte_7CE498);
  v2 = *(_DWORD *)(this + 28);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = (void *)*v3;
      if ( *v3 )
      {
        PhysicsObjectDestructor(*v3);
        FreeWrapper_7bcf(v5);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  result = PhysicsFilePathBuild((int)&byte_7CE498, (int)v18, 256);
  if ( !result )
  {
    ZeroInitSmallStruct(v10);
    if ( (unsigned __int8)AudioStreamOpen(v18, 1) )
    {
      memset(v17, 0, sizeof(v17));
      v12 = 0;
      v16 = 0;
      v14 = 0;
      v15 = 0;
      v13 = 1;
      while ( ConditionalDispatchBasedOnFlag(v17, 384) )
      {
        if ( !sub_5651B0(v11) && !sub_588410(v17, off_5C3F88[0]) )
        {
          v7 = (LPVOID *)OperatorNewNhMallocWrapper(28);
          v8 = v7;
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = (LPVOID)-1;
            v7[2] = 0;
            v7[3] = (LPVOID)-1;
            v7[5] = 0;
            v7[6] = (LPVOID)-1;
            SessionConfigDefaultInit(v7);
            if ( TrackSessionClassesReader(v8, v10) )
            {
              SessionConfigDefaultInit(v8);
              if ( v8[5] )
                FreeWrapper_7bcf(v8[5]);
              if ( v8[2] )
                FreeWrapper_7bcf(v8[2]);
              if ( *v8 )
                FreeWrapper_7bcf(*v8);
              FreeWrapper_7bcf(v8);
            }
            else
            {
              v9 = OperatorNewNhMallocWrapper(12);
              if ( v9 )
              {
                *(_DWORD *)v9 = v8;
                *(_DWORD *)(v9 + 4) = 0;
                *(_BYTE *)(v9 + 8) = 1;
              }
              else
              {
                v9 = 0;
              }
              if ( *(_DWORD *)(this + 28) )
              {
                *(_DWORD *)(*(_DWORD *)(this + 32) + 4) = v9;
              }
              else
              {
                *(_DWORD *)(this + 28) = v9;
                *(_DWORD *)(this + 36) = v9;
              }
              *(_DWORD *)(this + 32) = v9;
              ++*(_DWORD *)(this + 40);
            }
          }
        }
      }
      ConditionalFileHandleCloseWithFlagDispatch(v10);
    }
    result = SubCallWithConditionalFieldFree(v10);
  }
  *(_BYTE *)(this + 24) = 1;
  return result;
}
