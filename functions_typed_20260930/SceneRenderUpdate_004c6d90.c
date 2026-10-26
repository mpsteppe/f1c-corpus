void __thiscall SceneRenderUpdate(F1CVehicle *this, float a2)
{
  _DWORD v3[3]; // [esp+Ch] [ebp-18h] BYREF
  float v4[3]; // [esp+18h] [ebp-Ch] BYREF

  VehicleRespawnReset((char *)this->RenderObject, SLOBYTE(a2));
  LargeConfigFunctionWithPhysicsConstants((int)&this->gap_0004[8]);
  DelegationWrapperToFUN0040ed10(dword_5EA560, (int)&this->gap_0004[8]);
  if ( LOBYTE(a2) )
    sub_4BB810(&this->gap_3D80[692]);
  SingleFunctionDispatch_10e0((int)this, v4, v3);
  ConditionalDelegateDispatch(this, v4, v3);
  RenderCallWithGuard(this, v4, v3);
  if ( LOBYTE(a2) )
  {
    sub_4D1180(this, v4, v3);
    AIVehiclePathPositionTracking((int)&this->gap_0004[8], v4, v3);
  }
  AIDriverStructInit(this, a2);
  sub_4C6B60(this, 1);
  *(_DWORD *)&this->gap_48A8[12] = -8388609;
  sub_4D1670(dword_8ACEE0);
  if ( flt_5EA408 <= 0.0 )
    CollisionWrapperWithLock((int)&this->gap_0004[8], flt_5EA408);
}

