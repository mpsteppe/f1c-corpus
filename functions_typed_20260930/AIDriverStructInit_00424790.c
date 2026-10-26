// AIDriverStructInit: Initializes this[4430] (+0x4538)=999999.0f (abs max speed sentinel), this[4431] (+0x453C)=1.0f (speed multiplier). These are defaults, not runtime recalculations.
int __thiscall AIDriverStructInit(F1CVehicle *this, float a2)
{
  int v2; // ebx
  unsigned __int8 *gap_42D8; // eax
  unsigned __int8 *v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  int v9; // ecx
  F1CVehicle *v10; // ecx
  float postProcessInput; // eax
  unsigned __int8 *v12; // edi
  int result; // eax
  int v14; // [esp+10h] [ebp-1Ch]
  const char *v15; // [esp+10h] [ebp-1Ch]
  float v16[3]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v17[3]; // [esp+20h] [ebp-Ch] BYREF
  int v18; // [esp+30h] [ebp+4h]
  float v19; // [esp+30h] [ebp+4h]

  v2 = 0;
  LOBYTE(this->RetiredFlag) = 0;
  this->gap_4140[0] = 0;
  *(_DWORD *)&this->gap_4454[40] = 0;
  *(_DWORD *)&this->gap_44FC[12] = 0;
  *(_DWORD *)&this->gap_44FC[16] = 0;
  *(_DWORD *)&this->gap_4414[12] = 0;
  *(_DWORD *)&this->gap_4140[48] = 2139095039;
  gap_42D8 = this->gap_42D8;
  v5 = &this->gap_4140[116];
  v6 = 5;
  do
  {
    *((_DWORD *)v5 - 3) = 1232348144;
    *((_DWORD *)gap_42D8 - 3) = 0;
    *(_DWORD *)v5 = -1;
    *((_DWORD *)v5 - 16) = 0;
    *(_DWORD *)gap_42D8 = -998653952;
    *((_DWORD *)gap_42D8 - 4) = -1;
    *((_DWORD *)gap_42D8 - 2) = -1;
    v5 += 68;
    gap_42D8 += 28;
    --v6;
  }
  while ( v6 );
  this->gap_4578[0] = 1;
  *(_DWORD *)&this->gap_4414[28] = 0;
  *(_DWORD *)&this->gap_4514[16] = 0;
  *(_DWORD *)&this->gap_4454[12] = -1082130432;
  *(_DWORD *)&this->gap_4454[16] = 1065353216;
  *(_DWORD *)&this->gap_4444[8] = 0;
  AIClearStateFlags((int)this);
  v14 = -*(_DWORD *)this->gap_0004;
  *(float *)&this->gap_4454[96] = *(float *)&this->gap_3928[68];
  this->LivePaceFactor = 1.0;
  *(_DWORD *)this->gap_4554 = 1065353216;
  this->TrackAggressionEffective = 1.0;
  this->PassingNorm = 1.0;
  *(float *)this->gap_4454 = (double)v14 * 7.0;
  *(_DWORD *)&this->gap_45F8[4] = 0;
  *(_DWORD *)&this->gap_4414[24] = 0;
  *(_DWORD *)&this->gap_4454[48] = 1232348144;
  this->MaxSpeed = 999999.0;
  *(_DWORD *)this->gap_4540 = 1086324736;
  *(_DWORD *)&this->gap_4540[4] = 1;
  LOBYTE(this->PitLaneRouteFlag) = 0;
  *(_DWORD *)&this->gap_4554[8] = 0;
  this->CallToBox = 0;
  this->WaypointSetSelector = 0;
  this->driverStatus = 0;
  *(_DWORD *)&this->gap_4554[4] = 50;
  *(_DWORD *)&this->gap_4554[12] = 0;
  *(_DWORD *)&this->gap_4554[16] = 0;
  *(_DWORD *)&this->gap_4414[40] = 0;
  *(_DWORD *)&this->gap_4358[172] = -1082130432;
  *(_DWORD *)&this->gap_4454[4] = -1;
  *(_DWORD *)&this->gap_4454[92] = -1;
  *(_DWORD *)&this->gap_4454[24] = 0;
  *(_DWORD *)&this->gap_4358[160] = 0;
  LOBYTE(this->AIControlFlag) = 0;
  *(_DWORD *)&this->gap_45F8[36] = 1232348144;
  if ( LOBYTE(a2) )
  {
    this->timeOfNextExit = 0.0;
    v7 = &this->gap_4140[4];
    v8 = 5;
    do
    {
      *(_DWORD *)v7 = -1;
      v7 += 8;
      --v8;
    }
    while ( v8 );
    sub_424080((char *)this);
    if ( *(_DWORD *)&this->gap_4454[84] )
      FreeWrapper_7bcf(*(LPVOID *)&this->gap_4454[84]);
    *(_DWORD *)&this->gap_4454[88] = 10;
    *(_DWORD *)&this->gap_4454[84] = OperatorNewNhMallocWrapper(80);
    AICommandMessageQueueDispatcher(this, 0, 0);
    *(_DWORD *)&this->gap_4444[8] = 0;
    *(_DWORD *)&this->gap_4454[92] = -1;
    *(_DWORD *)this->gap_45F8 = 0;
    v9 = 0;
    v18 = 0;
    if ( dword_5C329C > 0 )
    {
      v15 = (const char *)(LODWORD(this->postProcessInput) + 18104);
      do
      {
        v10 = *(&dword_7C54F0 + v9);
        if ( !strcmp(v15, &v10->CarName[64]) && v10 != this )
          *(_DWORD *)this->gap_45F8 = v10;
        v9 = ++v18;
      }
      while ( v18 < dword_5C329C );
    }
    postProcessInput = this->postProcessInput;
    *(_DWORD *)&this->gap_0004[4] = dword_5EA2D0 + *(_DWORD *)(LODWORD(this->postProcessInput) + 18596);
    ArrayOfStructIndexedFieldCopy(dword_5EA2C0, *(_DWORD *)(LODWORD(postProcessInput) + 18596), v16, v17);
    *(_DWORD *)&this->gap_4358[168] = SpatialTreeNearestNeighborSearch(
                                        dword_5EA2C0,
                                        v16,
                                        0,
                                        *(_DWORD *)&this->gap_0004[4],
                                        0);
    sub_429960(this);
  }
  v12 = &this->gap_45F8[8];
  do
  {
    *(_DWORD *)v12 = GuardedCallWithCheck(this->gap_32CC, v2++);
    v12 += 4;
  }
  while ( v2 < 7 );
  this->PitDecisionTimer = 2139095039;
  v19 = AIDifficultyInterpolation();
  if ( dword_7C56A4 != 3 && dword_7C56A4 != 4 && dword_7C56A4 != 5 )
    v19 = flt_5EA3E8 * v19;
  ScaleAudioPitch((int)&this->gap_0004[8], v19);
  return result;
}

