int __thiscall InputCommandDispatchToEntities(_DWORD *this)
{
  int v2; // edi
  char *v3; // ebx
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  char *v7; // ebx
  int v8; // eax
  int v9; // edi
  int v11; // [esp+Ch] [ebp-24Ch]
  int v12; // [esp+Ch] [ebp-24Ch]
  char *v13; // [esp+10h] [ebp-248h] BYREF
  int v14; // [esp+14h] [ebp-244h]
  int *v15; // [esp+18h] [ebp-240h]
  unsigned __int8 v16[432]; // [esp+1Ch] [ebp-23Ch] BYREF
  _BYTE v17[140]; // [esp+1CCh] [ebp-8Ch] BYREF

  SessionDataCopy(&dword_83EE60);
  while ( AdvanceRingBuffer(&dword_83EE60, v16) )
  {
    if ( (*(_DWORD *)v16 & 0x10000000) == 0 )
    {
      if ( ReferencesGlobalState(this) )
      {
        sub_465300(&dword_7CD2A8, v16);
      }
      else
      {
        v14 = SingleFunctionForward((void *)*this);
        v2 = 0;
        v11 = 0;
        if ( (int)this[3973] > 0 )
        {
          v3 = (char *)(this + 229);
          v15 = this + 3869;
          v13 = (char *)(this + 229);
          do
          {
            if ( v2 != v14
              && (this[4081] != 3 || FlagBitTest(v3, 1))
              && ((*(_DWORD *)v16 & 0x8000000) != 0 || TwoStageCheck()) )
            {
              v4 = *v15;
              if ( TwoStageCheck() && v16[0] < 0x68u )
                *(_DWORD *)v16 = *(_DWORD *)v16 & 0xFFFFFF00 | SLOBYTE(this[35 * v14 + 260]);
              TextureCreationWrapper((void *)*this, v16, 1, v4, 2000);
              v2 = v11;
              v3 = v13;
            }
            v5 = this[3973];
            ++v2;
            v3 += 140;
            v11 = v2;
            ++v15;
            v13 = v3;
          }
          while ( v2 < v5 );
        }
      }
    }
  }
  if ( ReferencesGlobalState(this) )
  {
    v14 = SingleFunctionForward((void *)*this);
    ThunkToFUN00461480(v17);
    SingleFunctionDispatch((void *)*this);
    v6 = 0;
    v12 = 0;
    if ( (int)this[3973] > 0 )
    {
      v7 = (char *)(this + 260);
      do
      {
        if ( v6 != v14 && (this[4081] != 3 || FlagBitTest(v7 - 124, 1)) )
        {
          if ( TwoStageCheck() )
          {
            v8 = *v7;
            v9 = this[v8 + 3974];
            EntityVisibilityGridManager((int **)&dword_7CD2A8, v8, v9);
            while ( LinkedListPopFront(&dword_7CD2A8, &v13) )
              TextureCreationWrapper((void *)*this, v13, 1, v9, 500);
          }
        }
        v6 = v12 + 1;
        v7 += 140;
        ++v12;
      }
      while ( v12 < this[3973] );
    }
    EmptyStub_0170();
  }
  return sub_57A730((ULONG_PTR *)this[4078], 0);
}

