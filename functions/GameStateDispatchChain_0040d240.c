int __thiscall sub_40D240(_DWORD *this, int a2)
{
  SetPlayerVehicleIndex(a2);
  CameraTargetUpdateOnPlayerChange(this);
  CameraViewAssignment(this, a2);
  VirtualDispatchConditionalAudio(this);
  AIOutOfTrackEvent(a2);
  return sub_4D8760(1, 0);
}
