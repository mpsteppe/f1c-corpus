char __thiscall sub_45A8E0(int this, float a2, int a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st6
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st7
  long double v15; // st6
  long double v16; // st5
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c2
  unsigned __int8 v24; // c0
  unsigned __int8 v25; // c2
  unsigned __int8 v27; // c0
  unsigned __int8 v28; // c2
  float v29; // [esp+Ch] [ebp-2Ch]
  float v30; // [esp+10h] [ebp-28h]
  _BYTE v31[36]; // [esp+14h] [ebp-24h] BYREF

  v4 = *(float *)(this + 28);
  *(float *)(this + 36) = a2;
  if ( *(float *)(this + 32) <= v4 )
    v5 = *(float *)(this + 32);
  else
    v5 = *(float *)(this + 28);
  if ( a2 <= v5 )
  {
    if ( *(_DWORD *)(this + 208) )
    {
      VehiclePhysicsVelocityAngularVelocityIntegrator(this, 0.0125);
      VehiclePhysicsVelocityAngularVelocityIntegrator(this, 0.0125);
      v29 = *(double *)(this + 232);
      v30 = *(double *)(this + 224);
      *(float *)a3 = *(double *)(this + 216);
      *(float *)(a3 + 4) = v30;
      *(float *)(a3 + 8) = v29;
      v13 = *(double *)(this + 280);
      FloatConvertWrapper();
      v14 = -v13;
      if ( fabs(*(double *)(this + 280)) == 1.0 )
      {
        v15 = atan2(-*(double *)(this + 288), *(double *)(this + 240));
        v16 = 0.0;
      }
      else
      {
        v15 = atan2(*(double *)(this + 256), *(double *)(this + 304));
        v16 = atan2(*(double *)(this + 264), *(double *)(this + 272));
      }
      *(float *)v31 = v14;
      *(float *)&v31[4] = v15;
      *(float *)&v31[8] = v16;
      sub_54B4D0(*(_DWORD *)a3, SLODWORD(v30), SLODWORD(v29), *(float *)v31, *(float *)&v31[4], *(float *)&v31[8]);
      if ( *(double *)(this + 320) < -100.0 || v18 | v19 && v21 | v22 && v24 | v25 && v27 | v28 )
      {
        memset(&v31[12], 0, 24);
        qmemcpy((void *)(this + 312), &v31[12], 0x18u);
        Copy6DwordsToStructCall(&v31[12]);
        *(_DWORD *)(this + 32) = *(_DWORD *)(this + 36);
        return 1;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v6 = flt_7D0AB0 + *(float *)(this + 32);
    if ( *(float *)(this + 28) < v6 )
      v6 = *(float *)(this + 28);
    if ( a2 <= v6 )
    {
      memset(&v31[12], 0, 24);
      qmemcpy((void *)(this + 312), &v31[12], 0x18u);
      Copy6DwordsToStructCall(&v31[12]);
      v11 = *(double *)(this + 232);
      v12 = *(double *)(this + 224);
      *(float *)a3 = *(double *)(this + 216);
      *(float *)(a3 + 4) = v12;
      *(float *)(a3 + 8) = v11;
      return 1;
    }
    else
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)this + 4))(this) )
      {
        strcpy(v31, "(knN(knN(knN");
        ThreeFieldSetterWithSubCall(1315859240, 1315859240, 1315859240);
        FlagFieldBitManipulation(0, 0, 0, 0);
        memset(&v31[13], 0, 23);
        qmemcpy((void *)(this + 312), &v31[12], 0x18u);
        Copy6DwordsToStructCall(&v31[12]);
        v7 = *(_DWORD *)&v31[4];
        *(_DWORD *)&v31[12] = 0;
        *(_DWORD *)&v31[16] = 1104006501;
        *(_DWORD *)&v31[20] = 0;
        *(_DWORD *)&v31[24] = 1104006501;
        *(_DWORD *)&v31[28] = 0;
        *(_DWORD *)&v31[32] = 1104006501;
        qmemcpy((void *)(this + 216), &v31[12], 0x18u);
        *(_DWORD *)(this + 192) = *(_DWORD *)v31;
        *(_DWORD *)(this + 196) = v7;
        *(_DWORD *)(this + 200) = *(_DWORD *)&v31[8];
      }
      v8 = *(double *)(this + 232);
      v9 = *(double *)(this + 224);
      *(float *)a3 = *(double *)(this + 216);
      *(float *)(a3 + 4) = v9;
      *(float *)(a3 + 8) = v8;
      return 0;
    }
  }
}

