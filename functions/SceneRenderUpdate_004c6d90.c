void __thiscall sub_4C6D90(int *this, float a2)
{
  _BYTE v3[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v4[12]; // [esp+18h] [ebp-Ch] BYREF

  VehicleRespawnReset(SLOBYTE(a2));
  LargeConfigFunctionWithPhysicsConstants(this + 3);
  DelegationWrapperToFUN0040ed10(dword_5EA560, (int)(this + 3));
  if ( LOBYTE(a2) )
    sub_4BB810(this + 4109);
  SingleFunctionDispatch_10e0(this, v4, v3);
  ConditionalDelegateDispatch(this, v4, v3);
  RenderCallWithGuard(this, v4, v3);
  if ( LOBYTE(a2) )
  {
    sub_4D1180(this, v4, v3);
    AIVehiclePathPositionTracking(v4, v3);
  }
  AIDriverStructInit(this, a2);
  sub_4C6B60(this, 1);
  this[4653] = -8388609;
  sub_4D1670(&dword_8ACEE0);
  if ( flt_5EA408 <= 0.0 )
    CollisionWrapperWithLock(this + 3);
}
