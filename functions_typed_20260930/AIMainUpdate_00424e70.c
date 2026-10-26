// AIMainUpdate: Per-frame AI tick. Entry guard on this+13000 (0-1 pass, 2+ reject). Computes heading from yaw at +0x34F0. Pit scheduling writes this+17680 (0x4510) = 4/5. State machine switch on +0x4510. Value 2 at +0x4064 clears one AI flag byte.
void __thiscall AIMainUpdate(F1CVehicle *this)
{
  char AIControlFlag; // al
  int v3; // eax
  double v4; // st7
  int v5; // eax
  unsigned __int8 *v6; // edi
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // eax
  double v11; // st6
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // edx
  double v17; // st7
  unsigned __int8 *v18; // edi
  int v19; // ebp
  double bestLap; // st7
  int v21; // ebx
  double v22; // st7
  int driverStatus; // ecx
  int v24; // eax
  double v25; // st6
  double v26; // st4
  double v27; // st5
  double Speed; // st7
  long double v29; // st7
  long double v30; // st7
  double v31; // st7
  int v32; // eax
  float v33; // [esp+10h] [ebp-1Ch]
  float v34; // [esp+10h] [ebp-1Ch]
  float v35[3]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v36[3]; // [esp+20h] [ebp-Ch] BYREF

  if ( this->WearTickGate__was__slot_live_marker_ > 1u )
    return;
  AIControlFlag = this->AIControlFlag;
  *(float *)&this->gap_4454[44] = dbl_8AFEA0;
  if ( !AIControlFlag && *(_DWORD *)(LODWORD(this->postProcessInput) + 13000) == 1 )
  {
    v3 = *(_DWORD *)&this->gap_4444[8];
    *(_DWORD *)&this->gap_3D80[680] = 0;
    *(_DWORD *)&this->gap_4414[32] = 0;
    if ( dword_7C56A8 != v3 )
    {
      v4 = *(float *)&this->gap_4444[4] - 0.025;
      *(float *)&this->gap_4444[4] = v4;
      if ( v4 < 0.0 )
      {
        AIRingBufferFieldInit(&this->postProcessInput);
        v5 = dword_7C56A8;
        if ( dword_7C56A8 == 5 || dword_7C56A8 == 1 )
        {
          SessionCleanupFlagClear(this);
          v5 = dword_7C56A8;
        }
        *(_DWORD *)&this->gap_4444[8] = v5;
        if ( LOBYTE(this->AIControlFlag) == 1 && byte_5C3160 == 1 )
        {
          v6 = &this->gap_4140[4];
          v7 = 5;
          *(float *)&this->PitDecisionTimer = dbl_8AFEA0 + 2.0;
          do
          {
            v8 = *((_DWORD *)v6 + 1);
            if ( v8 != 4 || *(_DWORD *)v6 )
            {
              if ( v8 == 5 && !*(_DWORD *)v6 )
              {
                ConditionalGate(&this->gap_0004[8]);
                v9 = RandLCGRandomNumberGenerator() % 4;
                v10 = v9 ? (v9 != 1 ? 8 : 3) : 7;
                if ( !this->ReasonCode )
                  this->ReasonCode = v10;
              }
            }
            else
            {
              ConditionalGate(&this->gap_0004[8]);
              *(float *)&this->gap_4140[48] = (double)(RandLCGRandomNumberGenerator() & 0x14) + dbl_8AFEA0 + 10.0;
            }
            v6 += 8;
            --v7;
          }
          while ( v7 );
        }
      }
    }
    if ( *(_DWORD *)&this->gap_4444[8] == 4 )
    {
      byte_5C3160 = 1;
      RaceStartCountdownStateUpdate((int)&this->gap_0004[8], 0);
      v11 = dbl_8AFEA0 - flt_8ACFB8;
      if ( v11 <= 0.2 )
      {
        if ( dbl_8AFEA0 < *(float *)&this->gap_4554[16] )
        {
          v14 = dbl_8AFEA0 - *(float *)&this->gap_4554[12];
          if ( v14 > 1.0 )
            v14 = 1.0;
          v15 = v14 * -25.0;
          if ( *(_DWORD *)&this->gap_4554[20] )
            *(_DWORD *)&this->gap_4414[32] = *((_DWORD *)&unk_5C30E0 - CRTFtol(v15));
          else
            *(_DWORD *)&this->gap_4414[32] = dword_5C3144[(unsigned int)CRTFtol(v15)];
          *(_DWORD *)&this->gap_4414[36] = 1065353216;
          *(_DWORD *)&this->gap_4414[24] = 0;
          goto LABEL_86;
        }
        v16 = *(_DWORD *)&this->gap_4554[20];
        *(float *)&this->gap_4554[12] = dbl_8AFEA0;
        *(_DWORD *)&this->gap_4554[20] = v16 == 0;
        if ( v16 )
          v17 = (double)(RandLCGRandomNumberGenerator() % 100) * 0.02 + dbl_8AFEA0 + 1.0;
        else
          v17 = (double)(RandLCGRandomNumberGenerator() % 100) * 0.0099999998 + dbl_8AFEA0;
        *(float *)&this->gap_4554[16] = v17;
      }
      else
      {
        v33 = v11;
        v12 = (v33 - 0.2) * 0.55555558;
        if ( v12 <= 1.0 )
          v13 = 1250.0 - v12 * 1000.0;
        else
          v13 = 250.0;
        *(float *)&this->gap_4414[32] = (*(float *)&this->gap_3994[8] - this->EngineRPM) / v13 + 0.5;
        if ( *(float *)&this->gap_4414[32] < 0.0 )
        {
          *(_DWORD *)&this->gap_4414[32] = 0;
          *(_DWORD *)&this->gap_4414[36] = 1065353216;
          *(_DWORD *)&this->gap_4414[24] = 0;
LABEL_86:
          if ( this->carConditions == 2 )
          {
            v29 = *(float *)&this->gap_4414[20];
            *(_DWORD *)&this->gap_4414[32] = 0;
            v30 = fabs(v29);
            v34 = v30;
            if ( v30 <= 7.0 )
            {
              if ( v34 >= 5.0 )
                *(float *)&this->gap_4414[36] = (v34 - 5.0) * 0.1 + 0.0099999998;
              else
                *(_DWORD *)&this->gap_4414[36] = 1008981770;
            }
            else
            {
              *(_DWORD *)&this->gap_4414[36] = 1045891645;
            }
          }
          *(float *)this->gap_3580 = *(float *)&this->gap_4414[24];
          v31 = *(float *)&this->gap_4414[36];
          *(_DWORD *)&this->gap_45F8[4] = 0;
          this->BrakeFactor = v31;
          this->ThrottleFactor = *(float *)&this->gap_4414[32];
          return;
        }
        if ( *(float *)&this->gap_4414[32] > 1.0 )
        {
          *(_DWORD *)&this->gap_4414[32] = 1065353216;
          *(_DWORD *)&this->gap_4414[36] = 1065353216;
          *(_DWORD *)&this->gap_4414[24] = 0;
          goto LABEL_86;
        }
      }
    }
    *(_DWORD *)&this->gap_4414[36] = 1065353216;
    *(_DWORD *)&this->gap_4414[24] = 0;
    goto LABEL_86;
  }
  *(float *)&this->gap_4454[56] = -sin(this->RenderX);
  *(float *)&this->gap_4454[64] = -cos(this->RenderX);
  if ( !sub_426430(this) || *(_DWORD *)(LODWORD(this->postProcessInput) + 13000) != 1 )
    return;
  if ( dbl_8AFEA0 > *(float *)&this->PitDecisionTimer )
  {
    this->PitDecisionTimer = 2139095039;
    if ( dword_7C56A8 == 8 )
      SetCallToBox(this, 1u);
    else
      AIPushLap(&this->postProcessInput);
    v18 = &this->gap_4140[8];
    v19 = 5;
    do
    {
      if ( this->lapNumber == *((_DWORD *)v18 - 1) && *(int *)v18 < 4 )
      {
        bestLap = this->bestLap;
        *(float *)&this->gap_4140[44] = this->bestLap;
        if ( bestLap < 40.0 )
          *(_DWORD *)&this->gap_4140[44] = 1109393408;
        v21 = RandLCGRandomNumberGenerator();
        v22 = (double)(v21 % (int)CRTFtol(*(float *)&this->gap_4140[44]));
        *(float *)&this->gap_4140[44] = v22;
        *(&this->EngineLifeRemaining + *(_DWORD *)v18) = v22;
      }
      v18 += 8;
      --v19;
    }
    while ( v19 );
  }
  if ( *(float *)&this->gap_4454[44] > (double)*(float *)&this->gap_4358[172] )
  {
    *(float *)&this->gap_4358[172] = *(float *)&this->gap_4454[44] + 4.0;
    AIAbility(&this->postProcessInput);
  }
  if ( *(float *)&this->gap_4140[48] < (double)*(float *)&this->gap_4454[44] )
  {
    *(_DWORD *)&this->gap_4414[40] = 0;
    *(_DWORD *)&this->gap_4358[160] = 0;
    AIClearStateFlags((int)this);
    if ( dword_7C56A4 == 7 )
      this->driverStatus = 4;
    else
      this->driverStatus = 5;
    *(_DWORD *)&this->gap_4514[16] = 0;
    *(_DWORD *)&this->gap_4414[36] = 1065353216;
    *(_DWORD *)&this->gap_4414[32] = 0;
    this->CallToBox = 0;
    this->WaypointSetSelector = 1;
    *(_DWORD *)&this->gap_4414[16] = 0;
    sub_426430(this);
    *(_DWORD *)&this->gap_4140[48] = 2139095039;
    *(float *)&this->gap_4454[40] = dbl_8AFEA0 + 4.0;
    VehicleClimbAdjust((int)&this->gap_0004[8], 0);
  }
  driverStatus = this->driverStatus;
  if ( driverStatus != 4 && driverStatus != 5 )
  {
    if ( !*(_DWORD *)&this->gap_45F8[4] && this->carConditions != 2 && this->FuelLevel > 0.001 )
      *(_DWORD *)&this->gap_4414[12] = 0;
    OpponentProximityScanTeamRecognition((char *)this);
    *(_DWORD *)&this->gap_4454[48] = 1232348144;
    AIRacingLine(this);
    if ( this->WaypointSetSelector < dword_5EA2CC )
      AISteering((char *)this);
    sub_426100((int)this);
    AISteeringCorrection((int)this);
    PhysicsGearShiftLogicWithThresholds((int)this);
    v24 = this->driverStatus;
    switch ( v24 )
    {
      case 0:
      case 6:
        SteeringAngleController((int)this);
        break;
      case 1:
        sub_4258C0((int)this);
        break;
      case 3:
        ArrayOfStructIndexedFieldCopy(dword_5EA2C0, *(_DWORD *)(LODWORD(this->postProcessInput) + 18596), v35, v36);
        v25 = v35[2] - this->WorldPositionZ;
        v26 = v35[0] - this->WorldPositionX;
        v27 = v25 * v25 + v26 * v26;
        if ( v27 > *(float *)&this->gap_45F8[36] )
          this->driverStatus = 0;
        else
          *(float *)&this->gap_45F8[36] = v27;
        break;
      case 2:
        FieldZeroSetter(this);
        return;
      case 7:
        Speed = this->Speed;
        *(_DWORD *)&this->gap_4414[24] = 0;
        *(_DWORD *)&this->gap_4414[36] = 1065353216;
        *(_DWORD *)&this->gap_4414[32] = 0;
        if ( Speed < 0.2 )
          this->driverStatus = 0;
        break;
    }
    goto LABEL_86;
  }
  if ( dbl_8AFEA0 > this->timeOfNextExit || driverStatus == 4 )
  {
    if ( *(_DWORD *)&this->gap_45D4[12] >= *(_DWORD *)&this->gap_4578[16] && dword_7C56A4 != 7 )
      LOBYTE(this->AIControlFlag) = 0;
    if ( this->FinishState == 2 )
      LOBYTE(this->AIControlFlag) = 0;
    if ( sub_4A4110((float *)dword_7CE2F0, (int)this) && LOBYTE(this->AIControlFlag) )
    {
      if ( this->driverStatus == 5 )
      {
        v32 = RandomWeightedTierSelection(this);
        LoopWithConditionalSubCall(&this->gap_0004[8], v32, 1);
        VehicleClimbAdjust((int)&this->gap_0004[8], 0);
        this->driverStatus = 3;
      }
      else
      {
        this->driverStatus = 0;
      }
    }
    else
    {
      this->timeOfNextExit = dbl_8AFEA0 + 4.0;
    }
  }
  *(_DWORD *)this->gap_3580 = 0;
  this->BrakeFactor = 1.0;
  this->ThrottleFactor = 0.0;
}

