void __thiscall sub_4C6B60(F1CVehicle *this, char a2)
{
  int *v3; // edi
  char v4; // bl
  int *gap_32CC; // ecx
  _DWORD v6[3]; // [esp+Ch] [ebp-18h] BYREF
  float v7[3]; // [esp+18h] [ebp-Ch] BYREF

  v3 = (int *)&this->gap_3D80[692];
  sub_4BB8E0(&this->gap_3D80[692]);
  v4 = sub_4D1180(this, v7, v6);
  if ( a2 || !sub_4BC9B0(v3, 0, 0) )
  {
    AIVehiclePathPositionTracking((int)&this->gap_0004[8], v7, v6);
    SuspensionStateUpdate((int)&this->gap_0004[8]);
    ConditionalBufferCall(&this->gap_0004[8], v4 == 0);
    gap_32CC = (int *)this->gap_32CC;
    if ( v4 )
    {
      ObjectStateClear((int)gap_32CC);
    }
    else
    {
      StatePhaseSetter((int)gap_32CC);
      if ( this->VehicleSceneSlotId == (*(&dword_7C54F0 + dword_7C54E4))->VehicleSceneSlotId )
        GameStateBranchDispatch(&dword_5EA510);
    }
  }
  CameraViewportFrustumInitialization(this);
  if ( dword_7C56A4 == 7 && (dword_7C56A8 == 3 || dword_7C56A8 == 4) )
    VehicleClimbAdjust((int)&this->gap_0004[8], 1);
}

