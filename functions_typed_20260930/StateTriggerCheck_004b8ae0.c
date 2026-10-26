char __thiscall sub_4B8AE0(float *this, float *a2)
{
  char v3; // bl

  v3 = 1;
  if ( this[973] - this[972] <= 0.0 )
    return 0;
  sub_4B8C40(*a2, 0);
  ConditionalMultiPathDispatcher(&dword_8AB6E4);
  WeatherParticleUpdate(&dword_8ACEA0);
  MultiPhaseProcessingStateMachine((int)dword_5EA2C0);
  sub_4D4580(&dword_8ACEE0);
  CollisionGlobalUpdateBroadcast((float *)&ppvOut);
  MainGameTickUpdate(&unk_5EC6D0);
  MainCameraDirectorUpdate((int)&dword_5EA510);
  RenderTickUpdate(&byte_8AC494);
  RenderScreenSave(byte_8AB678);
  ShortComputation_f070(&dword_7CE048);
  sub_4FA7E0(&unk_8AFE18);
  sub_4A1830();
  if ( dword_7CC4C8 || PackedFlagRead(byte_7CA594, 1) || FloatGetter(this) >= this[973] )
    return 0;
  return v3;
}

