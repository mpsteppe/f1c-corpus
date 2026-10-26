int __thiscall sub_49D4C0(_DWORD *this)
{
  BOOL v2; // eax
  int v3; // eax
  bool v4; // al
  bool v5; // al
  int v7; // [esp-4h] [ebp-8h]
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]

  if ( sub_49B9A0() )
    RandomCollisionEvent(this[12]);
  else
    AudioEffectTrigger(0, this[12]);
  v7 = this[13];
  v2 = sub_49BA30();
  AudioEffectTrigger(v2, v7);
  v8 = this[14];
  v3 = sub_49BA30();
  AudioEffectTrigger(v3 == 2, v8);
  if ( FuelWeightComputation() )
    RandomCollisionEvent(this[15]);
  else
    AudioEffectTrigger(0, this[15]);
  if ( DisqualificationCheck() )
  {
    RandomCollisionEvent(this[16]);
  }
  else if ( PitStateFlagCheck() )
  {
    AudioEffectTrigger(1, this[16]);
  }
  else
  {
    AudioEffectTrigger(0, this[16]);
  }
  v4 = ShortComputation_bad0();
  AudioEffectTrigger(v4, this[17]);
  v9 = this[18];
  v5 = VehicleFlagCheck();
  return AudioEffectTrigger(v5, v9);
}
