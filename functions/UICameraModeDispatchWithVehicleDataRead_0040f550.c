int __thiscall sub_40F550(int this, int a2)
{
  int result; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // esi

  result = *(_DWORD *)(this + 28);
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = PhysicsStateIntegration(a2, this + 12);
      *(_BYTE *)(this + 10) = 1;
      break;
    case 6:
      VehicleTelemetryPositionAccumulator(a2);
      v4 = (_DWORD *)(*(_DWORD *)(this + 32) + 13524);
      v5 = (_DWORD *)(this + 12);
      *v5 = *v4;
      result = v4[1];
      v5[1] = result;
      v5[2] = v4[2];
      break;
    default:
      return result;
  }
  return result;
}
