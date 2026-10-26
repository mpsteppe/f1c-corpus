int __thiscall CameraViewportFrustumInitialization(F1CVehicle *this)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // ecx
  int v4; // edx
  int result; // eax
  int v6; // [esp+Ch] [ebp-4h]

  this->PitDecisionTimer = 2139095039;
  *(_DWORD *)&this->gap_4454[28] = 0;
  *(_DWORD *)&this->gap_4454[36] = 0;
  *(_DWORD *)&this->gap_4454[32] = 1148829696;
  v2 = &this->gap_4140[116];
  v3 = &this->gap_4140[396];
  v4 = 5;
  do
  {
    *((_DWORD *)v2 - 3) = 1232348144;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)v2 = -1;
    *((_DWORD *)v2 - 16) = 0;
    v3 += 28;
    v2 += 68;
    --v4;
  }
  while ( v4 );
  *(_DWORD *)&this->gap_4414[40] = 0;
  *(_DWORD *)&this->gap_4414[28] = 0;
  *(_DWORD *)&this->gap_4514[16] = 0;
  *(_DWORD *)&this->gap_4454[12] = -1082130432;
  *(_DWORD *)&this->gap_4454[16] = 1065353216;
  AIClearStateFlags((int)this);
  *(_DWORD *)&this->gap_4454[4] = -1;
  *(_DWORD *)&this->gap_4454[92] = -1;
  v6 = -*(_DWORD *)this->gap_0004;
  *(_DWORD *)&this->gap_4414[24] = 0;
  *(_DWORD *)&this->gap_4454[48] = 1232348144;
  this->MaxSpeed = 999999.0;
  *(float *)this->gap_4454 = (double)v6 * 7.0;
  *(_DWORD *)this->gap_4540 = 1086324736;
  *(_DWORD *)&this->gap_4540[4] = 1;
  LOBYTE(this->PitLaneRouteFlag) = 0;
  this->CallToBox = 0;
  this->WaypointSetSelector = 0;
  *(_DWORD *)this->gap_4554 = 1065353216;
  this->driverStatus = 0;
  *(_DWORD *)&this->gap_4554[4] = 50;
  *(_DWORD *)&this->gap_4554[12] = 0;
  *(_DWORD *)&this->gap_4554[16] = 0;
  *(_DWORD *)&this->gap_4358[172] = -1082130432;
  *(_DWORD *)&this->gap_4454[24] = 0;
  *(_DWORD *)&this->gap_4358[160] = 0;
  LOBYTE(this->AIControlFlag) = 0;
  *(_DWORD *)&this->gap_45F8[36] = 1232348144;
  AICommandMessageQueueDispatcher(this, 0, 0);
  *(_DWORD *)&this->gap_4444[8] = 0;
  AIRingBufferFieldInit(&this->postProcessInput);
  LOBYTE(result) = sub_426430(this);
  this->gap_4578[12] = 0;
  return result;
}

