int __usercall sub_4CDB20@<eax>(int a1@<ecx>, double a2@<st0>)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      result = ParticleInstanceUpdate(a1, a2);
      break;
    case 5:
      result = WheelRenderObjectPerFrameUpdate(a1, a2);
      break;
    case 6:
    case 7:
      result = ScoringGateTimeoutCheck((_DWORD *)a1, a2);
      break;
    case 8:
      result = TelemetryBarIndicatorRenderer(a1, a2);
      break;
    case 12:
      result = ParticleSystemUpdateWithWindAndDamping((float *)a1, a2);
      break;
    case 13:
      result = ParticleEffectPhysics(a1, a2);
      break;
    default:
      return result;
  }
  return result;
}
