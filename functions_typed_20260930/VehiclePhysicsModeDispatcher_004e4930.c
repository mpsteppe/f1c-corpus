int __thiscall sub_4E4930(int this, float *a2)
{
  int v3; // eax
  int v4; // eax
  int result; // eax

  v3 = *(_DWORD *)(this + 12988);
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      result = v4 - 1;
      if ( !result )
      {
        *(float *)(this + 13484) = *(float *)&a2;
        return TeamColorLoader(*(float *)&a2);
      }
    }
    else
    {
      PitStateUpdateMachine(this + 12992, a2);
      return PhysicsIntegrationStateMachine(a2);
    }
  }
  else
  {
    PitStateUpdateMachine(this + 12992, a2);
    VehiclePhysicsIntegrationStep((int *)&dbl_7C7428, *(float *)&a2);
    *(float *)(this + 13484) = *(float *)&a2;
    return VehicleSetupInitialization(this);
  }
  return result;
}

