void __thiscall PitStateUpdateMachine(F1CPitMachine *this, float a2)
{
  int status; // eax

  status = this->status;
  if ( !status || status == 4 )
  {
    if ( dword_7C5698 )
      return;
    if ( status == 4 )
      CollisionAvoidanceCheck(this);
  }
  if ( !*((_DWORD *)this->vehicle + 3250) && !VehicleControlEnabled((int *)this) )
  {
    if ( this->status == 2 && PitBoxAlignmentReady(this) && !*((_DWORD *)this->vehicle + 3250) )
    {
      dword_7CE258 = 1;
      PitStateChangeRequest(this, 4);
    }
    goto LABEL_24;
  }
  switch ( this->status )
  {
    case 1:
      if ( a2 - this->state_event_time > 150.0 )
        PitStateChangeRequest(this, 0);
      goto LABEL_24;
    case 2:
      if ( !PitBoxAlignmentReady(this) )
        goto LABEL_24;
      this->service_ready = 0;
      PitStateChangeRequest(this, 3);
      if ( (*(&dword_7C54F0 + dword_7C54DC))->VehicleSceneSlotId == this->pit_team_index )
        ConditionalIndexSetter(&dword_8AD298, 2);
      break;
    case 3:
      if ( this->service_ready )
      {
        PitStopProgress(this, a2);
        goto LABEL_24;
      }
      break;
    default:
      goto LABEL_24;
  }
  PitStopReadyCheck(this, a2);
LABEL_24:
  if ( this->pit_entry_latch && *(_DWORD *)(PositionChangeMonitor((_DWORD *)this->vehicle + 3) + 300) != 1 )
    PitExitUnderRed(this);
  if ( this->operation_sound_latch )
  {
    if ( this->status != 3 )
    {
      this->operation_sound_latch = 0;
      ShortComputation_d410((int)&dword_5EA510);
    }
  }
}

