int __thiscall sub_4C6B60(int *this, char a2)
{
  int *v3; // edi
  char v4; // bl
  int v5; // ecx
  int v6; // ecx
  int result; // eax
  _BYTE v8[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v9[12]; // [esp+18h] [ebp-Ch] BYREF

  v3 = this + 4109;
  sub_4BB8E0(this + 4109);
  v4 = sub_4D1180(this, v9, v8);
  if ( a2 || !sub_4BC9B0(v3, 0, 0) )
  {
    AIVehiclePathPositionTracking(v9, v8);
    SuspensionStateUpdate(this + 3);
    LOBYTE(v5) = v4 == 0;
    ConditionalBufferCall(v5);
    v6 = (int)(this + 3251);
    if ( v4 )
    {
      ObjectStateClear(v6);
    }
    else
    {
      StatePhaseSetter(v6);
      if ( this[4645] == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
        GameStateBranchDispatch(&dword_5EA510);
    }
  }
  result = CameraViewportFrustumInitialization((int)this);
  if ( dword_7C56A4 == 7 )
  {
    result = dword_7C56A8;
    if ( dword_7C56A8 == 3 || dword_7C56A8 == 4 )
      return VehicleClimbAdjust(1);
  }
  return result;
}
