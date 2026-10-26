// AIStateMachineWithModeDispatch: Calls sub_4A5EA0 (PitsUnderRed) when (*this)[3250] (+0x32C8) == 2||3 AND this[97] == 2. Plus dispatch to steering/physics per AI mode.
int __thiscall PitStateEventApply(F1CPitMachine *this, void *a2)
{
  int v2; // eax
  _DWORD *vehicle; // ecx
  int v5; // eax
  int status; // eax
  int result; // eax
  _DWORD *v8; // ecx
  bool v9; // al
  _DWORD *v10; // ecx
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  _DWORD v13[3]; // [esp+8h] [ebp-18h] BYREF
  _DWORD v14[3]; // [esp+14h] [ebp-Ch] BYREF

  v2 = *((char *)a2 + 8);
  if ( this->status != v2 )
  {
    this->status = v2;
    AIPitStrategyState((F1CVehicle *)this->vehicle);
  }
  vehicle = this->vehicle;
  this->state_event_time = *((float *)a2 + 1);
  v5 = vehicle[3250];
  if ( v5 == 2 || v5 == 3 )
  {
    status = this->status;
    if ( status )
    {
      if ( status == 2 )
        PitEnterUnderRed(this);
    }
    else
    {
      PitExitUnderRed(this);
    }
  }
  ConditionalDispatch_55e0(this);
  result = this->status;
  if ( result )
  {
    if ( result == 1 || result == 2 )
    {
      v9 = VehicleControlEnabled((int *)this);
      v10 = *(_DWORD **)this->gap_008;
      if ( v10 )
        sub_4A3390(v10, !v9);
      result = (int)ConditionalDelegateDispatch(this->vehicle, v14, v13);
      v11 = *(_DWORD **)&this->gap_008[8];
      if ( v11 )
        result = sub_4A3320(v11, v14, (int)v13);
      v12 = *(_DWORD **)&this->gap_008[4];
      if ( v12 )
        return sub_4A3320(v12, v14, (int)v13);
    }
  }
  else
  {
    v8 = *(_DWORD **)this->gap_008;
    if ( v8 )
      return FlagBasedLoopConditionalCall(v8);
  }
  return result;
}

