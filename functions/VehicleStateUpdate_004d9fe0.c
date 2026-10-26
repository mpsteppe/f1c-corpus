int __thiscall VehicleStateUpdate(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  v6 = 0;
  if ( *(_DWORD *)(dword_7C54E0 + 16592) )
  {
    *(_BYTE *)(this + 24) = 1;
    v2 = *(_DWORD *)(dword_7C54E0 + 16592);
    *(_DWORD *)(this + 28) = v2;
    v3 = LapTimeGapCalculation(v2, dword_7C54E0, (float *)(this + 20), &v6);
  }
  else
  {
    if ( !*(_DWORD *)(dword_7C54E0 + 16596) )
      goto LABEL_6;
    *(_BYTE *)(this + 24) = 0;
    v4 = *(_DWORD *)(dword_7C54E0 + 16596);
    *(_DWORD *)(this + 28) = v4;
    v3 = LapTimeGapCalculation(dword_7C54E0, v4, (float *)(this + 20), &v6);
  }
  if ( v3 )
    return VTableDispatchWithFieldClear((int *)this);
LABEL_6:
  if ( *(float *)(this + 20) <= 0.0 )
    return VTableDispatchWithFieldClear((int *)this);
  result = v6;
  if ( v6 )
    return VTableDispatchWithFieldClear((int *)this);
  return result;
}
