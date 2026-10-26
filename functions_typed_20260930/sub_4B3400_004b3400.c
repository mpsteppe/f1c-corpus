void __usercall sub_4B3400(char *this@<ecx>, double a2@<st0>)
{
  unsigned int v3; // ecx
  F1CVehicle *v4; // esi
  int v5; // eax
  F1CVehicle *v6; // esi
  F1CVehicle *v7; // eax
  char *v8; // ebp
  unsigned __int8 *v9; // eax
  int v10; // eax
  double v11; // st7
  int v12; // edx
  double v13; // st7
  int v14; // eax
  double v15; // st7
  int v16; // edx
  double v17; // st7
  float v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // edi
  unsigned __int8 *v22; // esi
  int v23; // ebx
  float *v24; // eax
  float *v25; // ecx
  int v26; // edx
  double v27; // st7
  F1CVehicle *v28; // ecx
  int WearTickGate__was__slot_live_marker; // eax
  int v30; // eax
  F1CVehicle *v31; // ecx
  F1CVehicle *v32; // esi
  int v33; // [esp+18h] [ebp-1Ch]
  int v34; // [esp+18h] [ebp-1Ch]
  int v35; // [esp+18h] [ebp-1Ch]
  int v36; // [esp+18h] [ebp-1Ch]
  int v37; // [esp+18h] [ebp-1Ch]
  int v38; // [esp+18h] [ebp-1Ch]
  float v39[3]; // [esp+1Ch] [ebp-18h] BYREF
  float v40[3]; // [esp+28h] [ebp-Ch] BYREF

  v3 = *(_DWORD *)this;
  switch ( v3 >> 29 )
  {
    case 1u:
      switch ( (v3 >> 18) & 0x3F )
      {
        case 0u:
        case 7u:
          if ( (unsigned __int8)v3 < 0x68u )
          {
            v4 = &stru_5EC6D8 + (unsigned __int8)v3;
            if ( v4->WearTickGate__was__slot_live_marker_ == 2 )
            {
              CollisionParameterDispatch((unsigned __int8)v3, (int)this);
              v5 = ShortComputation_2b00((_DWORD *)this + 2);
              PropertySetter(v4, v5);
            }
          }
          break;
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
          if ( *(_DWORD *)&stru_5EC6D8.gap_1066[18624 * (unsigned __int8)v3 + 8802] == 2 )
            WheelControllerInputDecoder(dword_5EA560, (int)this);
          break;
        default:
          return;
      }
      break;
    case 2u:
      switch ( (v3 >> 18) & 0x3F )
      {
        case 0u:
          if ( (unsigned __int8)v3 < 0x68u )
          {
            v6 = &stru_5EC6D8 + (unsigned __int8)v3;
            ScoringGateValueSelect((int)v6->RenderObject, a2);
            RandomParameterDispatch((float *)&v6->gap_0004[16]);
          }
          break;
        case 2u:
          if ( (unsigned __int8)v3 < 0x68u )
          {
            v7 = &stru_5EC6D8 + (unsigned __int8)v3;
            if ( v7->WearTickGate__was__slot_live_marker_ >= 2u )
            {
              if ( (v3 & 0x3FF00) == 0x600 )
              {
                this[14] = 0;
                *((_DWORD *)this + 4) = 0;
              }
              v8 = this + 8;
              v9 = &v7->gap_0D59[719];
              *(_DWORD *)v9 = *(_DWORD *)v8;
              *((_DWORD *)v9 + 1) = *((_DWORD *)v8 + 1);
              *((_DWORD *)v9 + 2) = *((_DWORD *)v8 + 2);
              *((_DWORD *)v9 + 3) = *((_DWORD *)v8 + 3);
              *((_WORD *)v9 + 8) = *((_WORD *)v8 + 8);
            }
          }
          break;
        case 4u:
          CarPositionTargetCheck((int)&unk_8AFEC0, (int)this);
          break;
        case 5u:
          StringNameMatching((int)&unk_8AFFC8, (int)this);
          break;
        case 6u:
          flt_8AFEDC = (double)(unsigned __int8)this[8] * 0.0039215689;
          break;
        case 7u:
          if ( (unsigned __int8)v3 < 0x68u )
          {
            v10 = this[10];
            v11 = (double)this[8];
            v33 = this[9];
            v12 = this[11];
            v40[0] = v11 * 0.0078740157 + v11 * 0.0078740157;
            v13 = (double)v33;
            v34 = v10;
            v14 = this[12];
            v40[1] = v13 * 0.0078740157 * 1.5;
            v15 = (double)v34;
            v35 = v12;
            v16 = this[13];
            v40[2] = v15 * 0.0078740157 * 3.5;
            v17 = (double)v35;
            v36 = v14;
            v18 = *(float *)(this + 14);
            v39[0] = v17 * 0.0078740157;
            v39[1] = (double)v36 * 0.0078740157;
            v39[2] = (double)v16 * 0.0078740157;
            RepeatedPositionOffsetTransform((int)&stru_5EC6D8.RenderObject[18624 * (unsigned __int8)v3], v18, v40, v39);
          }
          break;
        case 8u:
          if ( (unsigned __int8)v3 < 0x68u )
            VehicleWheelCountIterator(&stru_5EC6D8.RenderObject[18624 * (unsigned __int8)v3], *((float *)this + 2));
          break;
        default:
          return;
      }
      break;
    case 3u:
      v19 = ((v3 >> 18) & 0x3F) - 6;
      if ( v19 )
      {
        if ( v19 == 1 )
        {
          ListSearchWithGlobalMatch(&flt_8AC4B0);
          flt_8AC4B0 = *((float *)this + 1);
        }
      }
      else if ( !byte_7CE254 )
      {
        *(float *)&v37 = (double)(unsigned __int8)this[8] * 0.0039215689;
        v20 = RandLCGRandomNumberGenerator();
        SoundEffectLoadPlay(v20 % 3 + 5, v37);
      }
      break;
    case 4u:
      switch ( (v3 >> 18) & 0x3F )
      {
        case 7u:
          v21 = 0;
          v38 = ((v3 >> 8) & 0x3FF) - 12;
          if ( v38 > 0 )
          {
            do
            {
              v22 = &stru_5EC6D8.gap_3D80[18624 * (unsigned __int8)this[v21 + 20] + 692];
              v23 = v21 + 1;
              ConditionalFieldSetter((int)v22, v21 + 1);
              if ( v21 <= 0 )
                *((_DWORD *)v22 + 39) = 0;
              else
                *((_DWORD *)v22 + 39) = &stru_5EC6D8 + (unsigned __int8)this[v21 + 19];
              if ( v21 >= v38 - 1 )
                *((_DWORD *)v22 + 40) = 0;
              else
                *((_DWORD *)v22 + 40) = &stru_5EC6D8 + (unsigned __int8)this[v21 + 21];
              if ( !v21 && *((float *)this + 2) > 0.0 )
              {
                v24 = (float *)(this + 8);
                v25 = (float *)(v22 + 116);
                v26 = 3;
                do
                {
                  v27 = *v24++;
                  *v25++ = v27;
                  --v26;
                }
                while ( v26 );
              }
              byte_8AD008[v21] = this[v21 + 20];
              ++v21;
            }
            while ( v23 < v38 );
          }
          break;
        case 8u:
          if ( (unsigned __int8)v3 < 0x68u )
          {
            v28 = &stru_5EC6D8 + (unsigned __int8)v3;
            WearTickGate__was__slot_live_marker = v28->WearTickGate__was__slot_live_marker_;
            if ( WearTickGate__was__slot_live_marker == 2 || WearTickGate__was__slot_live_marker == 3 )
              LapCompletion(
                (_DWORD **)&v28->gap_3D80[692],
                *((float *)this + 2),
                *((float *)this + 1),
                *((__int16 *)this + 6),
                *((__int16 *)this + 7));
          }
          break;
        case 0xAu:
        case 0xBu:
          ParseMidiBitstream(dword_8ACEE0, this);
          break;
        case 0x14u:
          if ( dword_8AB6E4 != 2 )
            PitTimerStateInit((int)dword_8ACEE0, (int)this);
          break;
        case 0x15u:
          FieldSetterWithInit((int)dword_8ACEE0, (int)this);
          break;
        case 0x17u:
          AccumulatorWithFixedArray(&stru_5EC6D8.gap_3D80[18624 * (unsigned __int8)v3 + 692], (int)this);
          break;
        case 0x18u:
          ArrayShiftConditionalDispatch(&stru_5EC6D8.gap_3D80[18624 * (unsigned __int8)v3 + 692]);
          break;
        case 0x1Au:
        case 0x1Bu:
          PitCrewStateMachine((_BYTE **)&stru_5EC6D8.gap_3D80[18624 * (unsigned __int8)v3 + 692], (int)this);
          break;
        case 0x1Cu:
          *(&stru_5EC6D8.FinishState + 4656 * (unsigned __int8)v3) = 3;
          break;
        case 0x21u:
          byte_8ACFE4 = 1;
          break;
        case 0x22u:
          byte_8ACFE4 = 0;
          break;
        default:
          return;
      }
      break;
    case 6u:
      v30 = (v3 >> 18) & 0x3F;
      if ( v30 )
      {
        if ( v30 == 1 )
        {
          v31 = &stru_5EC6D8 + (unsigned __int8)v3;
          if ( v31->WearTickGate__was__slot_live_marker_ == 2 )
            PitStateEventApply((F1CPitMachine *)v31->gap_32CC, this);
        }
      }
      else if ( (unsigned __int8)v3 < 0x68u )
      {
        v32 = &stru_5EC6D8 + (unsigned __int8)v3;
        ActorMotionPostProcessingUpdate((int)&v32->gap_0004[8]);
        UIElementMultiDispatch(v32->RenderObject, *((float *)this + 2));
      }
      break;
    default:
      return;
  }
}

