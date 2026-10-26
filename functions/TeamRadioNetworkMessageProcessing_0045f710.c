void __thiscall TeamRadioNetworkMessageProcessing(char *this)
{
  int v2; // ebp
  int *v3; // edi
  int v4; // eax
  bool v5; // bl
  ULONG_PTR *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ebp
  char *v10; // ebx
  int v11; // edi
  int v12; // ecx
  float v13; // [esp+0h] [ebp-258h]
  int v14; // [esp+14h] [ebp-244h] BYREF
  int v15; // [esp+18h] [ebp-240h]
  int v16[107]; // [esp+1Ch] [ebp-23Ch] BYREF
  int v17; // [esp+1C8h] [ebp-90h] BYREF
  _BYTE v18[140]; // [esp+1CCh] [ebp-8Ch] BYREF

  if ( ReferencesGlobalState(this) )
  {
    ResourceManagerFrameCleanup((float **)&dword_7CD2A8);
    v2 = 0;
    v3 = dword_5EF9A0;
    do
    {
      if ( *v3 != -1 )
        ShortComputation_52d0(&dword_7CD2A8, v2);
      v3 += 4656;
      ++v2;
    }
    while ( (int)v3 < (int)dword_7C87A0 );
  }
  v4 = *((_DWORD *)this + 4081);
  v5 = v4 == 2 || v4 == 1;
  while ( 1 )
  {
    v6 = (ULONG_PTR *)*((_DWORD *)this + 4078);
    v14 = 432;
    if ( SEHProtectedDataCopy(v6, (int)v16, &v14, &v17) )
      break;
    *((_DWORD *)this + 226) = 0;
    if ( v5 )
    {
      v7 = LinearSearchIn104ElementArray(this, v17);
      v16[0] = v7 | v16[0] & 0xFFFFFF00;
    }
    v13 = dbl_8AFEA0;
    CollisionContactSolver((_DWORD *)this + 26864, (float *)v16, v13);
    NetCommSessionMessageDispatcher(this, (unsigned int *)v16);
  }
  if ( v5 )
  {
    if ( ReferencesGlobalState(this) )
    {
      SessionDataCopy(&dword_7D2E50);
      while ( AdvanceRingBuffer(&dword_7D2E50, v16) )
        sub_465300(&dword_7CD2A8, v16);
    }
    else
    {
      ThunkToFUN00461480(v18);
      v15 = SingleFunctionDispatch(*(void **)this);
      v8 = *((_DWORD *)this + 3973);
      v9 = 0;
      v14 = 0;
      if ( v8 > 0 )
      {
        v10 = this + 1040;
        do
        {
          if ( TwoStageCheck() )
          {
            v11 = *(_DWORD *)&this[4 * *v10 + 15896];
            if ( v11 != v15 )
            {
              SessionDataCopy(&dword_7D2E50);
              while ( AdvanceRingBuffer(&dword_7D2E50, v16) )
              {
                if ( v11 != v17 )
                {
                  TextureCreationWrapper(*(void **)this, v16, 1, v11, 1000);
                  ++v9;
                }
              }
            }
          }
          v12 = *((_DWORD *)this + 3973);
          v10 += 140;
          ++v14;
        }
        while ( v14 < v12 );
      }
      if ( !dword_7D0F04 && dword_7D0E98 > 8 && v9 > 0 )
        sub_57A730(*((ULONG_PTR **)this + 4078), 0);
      EmptyStub_0170();
    }
  }
}
