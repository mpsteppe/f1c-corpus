int __thiscall sub_42D8A0(_DWORD *this)
{
  int v1; // eax
  char v2; // bl

  *this = 5;
  while ( 1 )
  {
    ConditionalInit(&unk_8AFE18);
    if ( SessionStateCheck(&dword_7CD25C) == 1 )
    {
      v2 = 1;
      goto LABEL_4;
    }
    v1 = RestartGate(&unk_7CE24D);
    v2 = byte_7CE254;
    if ( v1 != 5 )
      break;
LABEL_4:
    ConditionalMultiPathDispatcher(&dword_8AB6E4);
    sub_463CA0(&dword_7CD25C);
    ConditionalStateUpdate(&dword_8AB6E4);
    BufferReset(&dword_7D2E50);
    MultiPhaseProcessingStateMachine((int)dword_5EA2C0);
    sub_4D4580(&dword_8ACEE0);
    CollisionGlobalUpdateBroadcast(&ppvOut);
    MainGameTickUpdate(&unk_5EC6D0);
    IterateVehicles(&dword_83EE60);
    SessionScoringUpdate(&dword_7CD25C);
    CollisionResponseStatus(&dword_7CD25C);
    TwoPathDispatch(&dword_8AB6E4);
    BufferReset(&dword_83EE60);
    if ( v2 )
    {
      WeatherParticleUpdate(&dword_8ACEA0);
    }
    else
    {
      MainCameraDirectorUpdate((int)&dword_5EA510);
      WeatherParticleUpdate(&dword_8ACEA0);
      RenderScreenSave(&byte_8AB678);
      ShortComputation_f070(&dword_7CE048);
    }
    ConditionalStateReset(&unk_8AFE18);
    RenderTickUpdate(&byte_8AC494);
    sub_4FA7E0(&unk_8AFE18);
    sub_4FCEE0(&unk_8AFEC0);
    sub_4A1830(&unk_7CE2A4);
    if ( SessionStateCheck(&dword_7CD25C) == 1 )
      return 0;
  }
  if ( v1 == 4 )
    return 0;
  if ( v1 != 6 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_11, 628) )
    DebugLogWrite(&dword_8AD25C, aNextStateDWasN);
  return 1;
}

