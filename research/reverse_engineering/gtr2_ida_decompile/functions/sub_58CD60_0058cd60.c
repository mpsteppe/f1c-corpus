int __thiscall sub_58CD60(float *this, int a2, int a3, int a4)
{
  unsigned int v4; // kr00_4
  __int32 v5; // eax
  int v7; // esi
  int v8; // eax
  const char *v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // esi
  int v15; // eax
  __int16 v16; // fps
  bool v17; // c0
  char v18; // c2
  bool v19; // c3
  double v20; // st7
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  __int16 v25; // fps
  bool v26; // c0
  char v27; // c2
  bool v28; // c3
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  float v32; // eax
  int v33; // ecx
  int v34; // edx
  int v35; // eax
  __int32 v37[5]; // [esp+0h] [ebp-514h] BYREF
  int v38; // [esp+14h] [ebp-500h] BYREF
  int v39; // [esp+18h] [ebp-4FCh] BYREF
  float v40; // [esp+1Ch] [ebp-4F8h] BYREF
  int v41; // [esp+20h] [ebp-4F4h] BYREF
  float v42; // [esp+24h] [ebp-4F0h] BYREF
  float v43; // [esp+28h] [ebp-4ECh] BYREF
  _BYTE v44[64]; // [esp+2Ch] [ebp-4E8h] BYREF
  int v45; // [esp+6Ch] [ebp-4A8h] BYREF
  float v46; // [esp+70h] [ebp-4A4h] BYREF
  float v47; // [esp+74h] [ebp-4A0h] BYREF
  int v48; // [esp+78h] [ebp-49Ch] BYREF
  int v49; // [esp+7Ch] [ebp-498h] BYREF
  int v50; // [esp+80h] [ebp-494h] BYREF
  int v51; // [esp+84h] [ebp-490h] BYREF
  int v52; // [esp+88h] [ebp-48Ch] BYREF
  int v53; // [esp+8Ch] [ebp-488h] BYREF
  int v54; // [esp+90h] [ebp-484h]
  _BYTE v55[4]; // [esp+94h] [ebp-480h] BYREF
  int v56; // [esp+98h] [ebp-47Ch]
  _BYTE v57[512]; // [esp+F0h] [ebp-424h] BYREF
  int v58; // [esp+2F0h] [ebp-224h]
  char v59; // [esp+2F4h] [ebp-220h]
  int v60; // [esp+2FCh] [ebp-218h]
  int v61; // [esp+300h] [ebp-214h]
  int v62; // [esp+304h] [ebp-210h]
  char Str1[512]; // [esp+308h] [ebp-20Ch] BYREF
  int v64; // [esp+510h] [ebp-4h]

  v7 = 1;
  sub_613B30(v55);
  memset(Str1, 0, sizeof(Str1));
  v64 = 0;
  v58 = 0;
  v62 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 1;
  v48 = 1051931443;
  v52 = 1053609165;
  v51 = 1048576000;
  v53 = 1051931443;
  v50 = 1053609165;
  v49 = 1048576000;
  sub_614460(a2, 1);
  if ( v56 )
  {
    v54 = 0;
    if ( sub_613DE0(Str1, 512) )
    {
      while ( 1 )
      {
        v8 = sub_612EB0(v57);
        if ( v8 )
          goto LABEL_192;
        if ( !strncmp(Str1, aVsInside, 0xAu) )
        {
          v9 = &Str1[10];
          goto LABEL_6;
        }
        if ( !strncmp(Str1, aVsOutside, 0xBu) )
          break;
        if ( strncmp(Str1, aEnginerpm, 9u) )
        {
          v15 = strncmp(Str1, "TRANNY", 6u);
          v37[0] = 0;
          if ( v15 )
          {
            if ( sub_6134B0("EngineLoadBlendInside", (int)&v47, (int)&v46, 0, 0, 0, 0, 0, v37[0]) )
              sub_58BCB0(this + 550, v47, v46);
            if ( sub_6134B0("EngineLoadBlendOutside", (int)&v47, (int)&v46, 0, 0, 0, 0, 0, 0) )
              sub_58BCB0(this + 610, v47, v46);
            sub_6134B0("playerEngineVolumeMinimum", (int)&v48, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("playerEngineVolumeThrottleFraction", (int)&v52, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("playerEngineVolumeRevFraction", (int)&v51, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("non-playerEngineVolumeMinimum", (int)&v53, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("non-playerEngineVolumeThrottleFraction", (int)&v50, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("non-playerEngineVolumeRevFraction", (int)&v49, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("EngineRange", (int)&dword_903E74, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("EngineShape", (int)&dword_903E78, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("EngineAmbient", (int)&dword_903E7C, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("ShiftRange", (int)&dword_903E80, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("ShiftShape", (int)&dword_903E84, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("ShiftAmbient", (int)&dword_903E88, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("OtherRange", (int)&flt_903E8C, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("OtherShape", (int)&flt_903E90, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("OtherAmbient", (int)&flt_903E94, 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("SplutterAmount", (int)(this + 47), 0, 0, 0, 0, 0, 0, 0);
            sub_6134B0("BackfireAmount", (int)(this + 48), 0, 0, 0, 0, 0, 0, 0);
            if ( sub_6134B0("BrakeRampSpeed", (int)&v41, 0, 0, 0, 0, 0, 0, 0) )
              this[54] = *(float *)&v41 * 3.3333333;
            if ( sub_6134B0("BrakeBlendSpeeds", (int)&v41, (int)&v45, 0, 0, 0, 0, 0, 0)
              && *(float *)&v45 > (double)*(float *)&v41 )
            {
              v21 = *(float *)&v41 * 3.3333333;
              this[55] = v21;
              v22 = *(float *)&v45 * 3.3333333;
              this[56] = v22;
              this[57] = 1.0 / (v22 - v21);
            }
            if ( sub_6134B0("BrakeFadeSpeeds", (int)&v41, (int)&v45, 0, 0, 0, 0, 0, 0)
              && *(float *)&v45 > (double)*(float *)&v41 )
            {
              v23 = *(float *)&v41 * 3.3333333;
              this[58] = v23;
              v24 = *(float *)&v45 * 3.3333333;
              this[59] = v24;
              this[60] = 1.0 / (v24 - v23);
            }
            v8 = sub_6134B0("BrakePressure", (int)&v41, 0, 0, 0, 0, 0, 0, 0);
            if ( v8 )
            {
              v26 = *(float *)&v41 < 0.0;
              v27 = 0;
              v28 = *(float *)&v41 == 0.0;
              LOWORD(v8) = v25;
              if ( *(float *)&v41 > 0.0 )
                this[61] = 1.0 / *(float *)&v41;
            }
          }
          else if ( sub_6134B0("TrannyCoastBlendRPMInside", (int)&v43, (int)&v42, 0, 0, 0, 0, 0, v37[0]) )
          {
            sub_58BE20(this + 550, v43, v42);
          }
          else if ( sub_6134B0("TrannyCoast1RPMTorqueInside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 550, 10, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyCoast2RPMTorqueInside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 550, 11, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyPowerBlendRPMInside", (int)&v43, (int)&v42, 0, 0, 0, 0, 0, 0) )
          {
            sub_58BE60(this + 550, v43, v42);
          }
          else if ( sub_6134B0("TrannyPower1RPMTorqueInside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 550, 12, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyPower2RPMTorqueInside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 550, 13, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyCoastBlendRPMOutside", (int)&v43, (int)&v42, 0, 0, 0, 0, 0, 0) )
          {
            sub_58BE20(this + 610, v43, v42);
          }
          else if ( sub_6134B0("TrannyCoast1RPMTorqueOutside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 610, 10, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyCoast2RPMTorqueOutside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 610, 11, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyPowerBlendRPMOutside", (int)&v43, (int)&v42, 0, 0, 0, 0, 0, 0) )
          {
            sub_58BE60(this + 610, v43, v42);
          }
          else if ( sub_6134B0("TrannyPower1RPMTorqueOutside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 610, 12, *(float *)&v39, v40);
          }
          else if ( sub_6134B0("TrannyPower2RPMTorqueOutside", (int)&v39, (int)&v40, 0, 0, 0, 0, 0, 0) )
          {
            v8 = sub_58BEA0(this + 610, 13, *(float *)&v39, v40);
          }
          else
          {
            v8 = sub_6134B0("TrannyInitialRampRPM", (int)&v39, 0, 0, 0, 0, 0, 0, 0);
            if ( v8 )
            {
              v17 = *(float *)&v39 < 1.0;
              v18 = 0;
              v19 = *(float *)&v39 == 1.0;
              LOWORD(v8) = v16;
              if ( *(float *)&v39 >= 1.0 )
                v20 = *(float *)&v39;
              else
                v20 = 1.0;
              this[53] = 1.0 / (v20 * 0.1047197551196598);
            }
          }
          goto LABEL_192;
        }
        if ( sub_6133A0("EngineRPM", (int)&v38, 0, 0, 0) )
        {
          v10 = sub_614040(v55);
          sub_58C1F0(this + 553, (int)v55, v38);
          sub_613FE0(v10);
          sub_58C1F0(this + 574, (int)v55, v38);
          sub_613FE0(v10);
          sub_58C1F0(this + 613, (int)v55, v38);
          sub_613FE0(v10);
          v8 = sub_58C1F0(this + 634, (int)v55, v38);
          goto LABEL_192;
        }
        if ( sub_6133A0("EngineRPMPower", (int)&v38, 0, 0, 0) || sub_6133A0("EngineRPMSound", (int)&v38, 0, 0, 0) )
        {
          v14 = sub_614040(v55);
          sub_58C1F0(this + 574, (int)v55, v38);
          sub_613FE0(v14);
          v8 = sub_58C1F0(this + 634, (int)v55, v38);
        }
        else
        {
          if ( !sub_6133A0("EngineRPMPowerInside", (int)&v38, 0, 0, 0)
            && !sub_6133A0("EngineRPMSoundInside", (int)&v38, 0, 0, 0)
            && !sub_6133A0("EngineRPMPowerOutside", (int)&v38, 0, 0, 0)
            && !sub_6133A0("EngineRPMSoundOutside", (int)&v38, 0, 0, 0) )
          {
            if ( sub_6133A0("EngineRPMCoast", (int)&v38, 0, 0, 0) )
            {
              v11 = sub_614040(v55);
              v37[0] = v38;
              sub_58C430();
              sub_613FE0(v11);
              v37[0] = v38;
              v8 = sub_58C430();
              goto LABEL_192;
            }
            if ( !sub_6133A0("EngineRPMCoastInside", (int)&v38, 0, 0, 0)
              && !sub_6133A0("EngineRPMCoastOutside", (int)&v38, 0, 0, 0) )
            {
              if ( sub_6133A0("EngineRPMInside", (int)&v38, 0, 0, 0)
                || (v8 = sub_6133A0("EngineRPMOutside", (int)&v38, 0, 0, 0)) != 0 )
              {
                v12 = sub_614040(v55);
                v37[0] = v38;
                v13 = v12;
                sub_58C430();
                sub_613FE0(v13);
                v37[0] = v38;
                v8 = sub_58C430();
              }
              goto LABEL_192;
            }
          }
          v37[0] = v38;
          v8 = sub_58C430();
        }
LABEL_192:
        v37[0] = v8;
        v4 = __readeflags();
        v5 = __ROL4__(off_16C6DE8, *(&loc_1007D1F + 1));
        __writeeflags(v4);
        _InterlockedExchange(v37, v5);
        if ( !sub_613DE0(Str1, v37[0]) )
          goto LABEL_185;
      }
      v9 = &Str1[11];
LABEL_6:
      if ( sscanf(v9, "COAST_ENGINE_1=%s", v44) == 1 )
        goto LABEL_181;
      if ( sscanf(v9, "COAST_ENGINE_2=%s", v44) == 1 )
      {
        v37[0] = (__int32)v44;
      }
      else
      {
        if ( sscanf(v9, "COAST_ENGINE_3=%s", v44) != 1 )
        {
          if ( sscanf(v9, "COAST_ENGINE_4=%s", v44) != 1 )
          {
            if ( sscanf(v9, "COAST_ENGINE_5=%s", v44) == 1 )
            {
              v37[0] = (__int32)v44;
              goto LABEL_182;
            }
            if ( sscanf(v9, "POWER_ENGINE_1=%s", v44) == 1 )
            {
              v37[0] = (__int32)v44;
              goto LABEL_182;
            }
            if ( sscanf(v9, "POWER_ENGINE_2=%s", v44) != 1 )
            {
              if ( sscanf(v9, "POWER_ENGINE_3=%s", v44) == 1 )
              {
                v37[0] = (__int32)v44;
                goto LABEL_182;
              }
              if ( sscanf(v9, "POWER_ENGINE_4=%s", v44) == 1 )
              {
                v37[0] = (__int32)v44;
                goto LABEL_182;
              }
              if ( sscanf(v9, "POWER_ENGINE_5=%s", v44) != 1 )
              {
                if ( sscanf(v9, "ENGINE_1=%s", v44) == 1 )
                {
                  v37[0] = (__int32)v44;
                  goto LABEL_182;
                }
                if ( sscanf(v9, "ENGINE_2=%s", v44) == 1 )
                {
                  v37[0] = (__int32)v44;
                  goto LABEL_182;
                }
                if ( sscanf(v9, "ENGINE_3=%s", v44) != 1 )
                {
                  if ( sscanf(v9, "ENGINE_4=%s", v44) == 1 )
                  {
                    v37[0] = (__int32)v44;
                    goto LABEL_182;
                  }
                  if ( sscanf(v9, "ENGINE_5=%s", v44) == 1 )
                  {
                    v37[0] = (__int32)v44;
                    goto LABEL_182;
                  }
                  if ( sscanf(v9, "COAST_TRANNY_1=%s", v44) != 1 )
                  {
                    if ( sscanf(v9, "COAST_TRANNY_2=%s", v44) == 1 )
                    {
                      v37[0] = (__int32)v44;
                      goto LABEL_182;
                    }
                    if ( sscanf(v9, "POWER_TRANNY_1=%s", v44) == 1 )
                    {
                      v37[0] = (__int32)v44;
                      goto LABEL_182;
                    }
                    if ( sscanf(v9, "POWER_TRANNY_2=%s", v44) != 1 )
                    {
                      if ( sscanf(v9, "WIND_NOISE=%s", v44) == 1 )
                      {
                        v37[0] = (__int32)v44;
                        goto LABEL_182;
                      }
                      if ( sscanf(v9, "BRAKES_LOW=%s", v44) == 1 )
                      {
                        v37[0] = (__int32)v44;
                        goto LABEL_182;
                      }
                      if ( sscanf(v9, "BRAKES_HIGH=%s", v44) != 1 )
                      {
                        if ( sscanf(v9, "RAIN_NOISE=%s", v44) == 1 )
                        {
                          v37[0] = (__int32)v44;
                          goto LABEL_182;
                        }
                        if ( sscanf(v9, "ROADNOISE_DRY=%s", v44) == 1 )
                        {
                          v37[0] = (__int32)v44;
                          goto LABEL_182;
                        }
                        if ( sscanf(v9, "ROADNOISE_WET=%s", v44) != 1 )
                        {
                          if ( sscanf(v9, "ROADNOISE_GRASS=%s", v44) == 1 )
                          {
                            v37[0] = (__int32)v44;
                            goto LABEL_182;
                          }
                          if ( sscanf(v9, "ROADNOISE_DIRT=%s", v44) == 1 )
                          {
                            v37[0] = (__int32)v44;
                            goto LABEL_182;
                          }
                          if ( sscanf(v9, "ROADNOISE_GRAVEL=%s", v44) != 1 )
                          {
                            if ( sscanf(v9, "ROADNOISE_RUMBLESTRIP=%s", v44) == 1 )
                            {
                              v37[0] = (__int32)v44;
                              goto LABEL_182;
                            }
                            if ( sscanf(v9, "SHIFT_UP_1=%s", v44) == 1 )
                            {
                              v37[0] = (__int32)v44;
                              goto LABEL_182;
                            }
                            if ( sscanf(v9, "SHIFT_UP_2=%s", v44) != 1 )
                            {
                              if ( sscanf(v9, "SHIFT_UP_3=%s", v44) == 1 )
                              {
                                v37[0] = (__int32)v44;
                                goto LABEL_182;
                              }
                              if ( sscanf(v9, "SHIFT_DOWN_1=%s", v44) == 1 )
                              {
                                v37[0] = (__int32)v44;
                                goto LABEL_182;
                              }
                              if ( sscanf(v9, "SHIFT_DOWN_2=%s", v44) != 1 )
                              {
                                if ( sscanf(v9, "SHIFT_DOWN_3=%s", v44) == 1 )
                                {
                                  v37[0] = (__int32)v44;
                                  goto LABEL_182;
                                }
                                if ( sscanf(v9, "BACKFIRE_1=%s", v44) == 1 )
                                {
                                  v37[0] = (__int32)v44;
                                  goto LABEL_182;
                                }
                                if ( sscanf(v9, "BACKFIRE_2=%s", v44) != 1 )
                                {
                                  if ( sscanf(v9, "BACKFIRE_3=%s", v44) == 1 )
                                  {
                                    v37[0] = (__int32)v44;
                                    goto LABEL_182;
                                  }
                                  if ( sscanf(v9, "SPLUTTER=%s", v44) == 1 )
                                  {
                                    v37[0] = (__int32)v44;
                                    goto LABEL_182;
                                  }
                                  if ( sscanf(v9, "TIRE_SCRUB=%s", v44) != 1 )
                                  {
                                    if ( sscanf(v9, "SKID_DRY=%s", v44) == 1 )
                                    {
                                      v37[0] = (__int32)v44;
                                      goto LABEL_182;
                                    }
                                    if ( sscanf(v9, "SKID_WET=%s", v44) == 1 )
                                    {
                                      v37[0] = (__int32)v44;
                                      goto LABEL_182;
                                    }
                                    if ( sscanf(v9, "SKID_GRASS=%s", v44) != 1 )
                                    {
                                      if ( sscanf(v9, "SKID_DIRT=%s", v44) == 1 )
                                      {
                                        v37[0] = (__int32)v44;
                                        goto LABEL_182;
                                      }
                                      if ( sscanf(v9, "SKID_GRAVEL=%s", v44) == 1 )
                                      {
                                        v37[0] = (__int32)v44;
                                        goto LABEL_182;
                                      }
                                      if ( sscanf(v9, "SCRAPING=%s", v44) != 1 )
                                      {
                                        if ( sscanf(v9, "HIT_WALL_1=%s", v44) == 1 )
                                        {
                                          v37[0] = (__int32)v44;
                                          goto LABEL_182;
                                        }
                                        if ( sscanf(v9, "HIT_WALL_2=%s", v44) == 1 )
                                        {
                                          v37[0] = (__int32)v44;
                                          goto LABEL_182;
                                        }
                                        if ( sscanf(v9, "HIT_WALL_3=%s", v44) != 1 )
                                        {
                                          if ( sscanf(v9, "HIT_WALL_4=%s", v44) == 1 )
                                          {
                                            v37[0] = (__int32)v44;
                                            goto LABEL_182;
                                          }
                                          if ( sscanf(v9, "HIT_WALL_5=%s", v44) == 1 )
                                          {
                                            v37[0] = (__int32)v44;
                                            goto LABEL_182;
                                          }
                                          if ( sscanf(v9, "HIT_OTHERCAR_1=%s", v44) != 1 )
                                          {
                                            if ( sscanf(v9, "HIT_OTHERCAR_2=%s", v44) == 1 )
                                            {
                                              v37[0] = (__int32)v44;
                                              goto LABEL_182;
                                            }
                                            if ( sscanf(v9, "HIT_OTHERCAR_3=%s", v44) == 1 )
                                            {
                                              v37[0] = (__int32)v44;
                                              goto LABEL_182;
                                            }
                                            if ( sscanf(v9, "HIT_OTHERCAR_4=%s", v44) != 1 )
                                            {
                                              if ( sscanf(v9, "HIT_OTHERCAR_5=%s", v44) == 1 )
                                              {
                                                v37[0] = (__int32)v44;
                                                goto LABEL_182;
                                              }
                                              if ( sscanf(v9, "HIT_CONE=%s", v44) == 1 )
                                              {
                                                v37[0] = (__int32)v44;
                                                goto LABEL_182;
                                              }
                                              if ( sscanf(v9, "ENGINE_STARTING=%s", v44) != 1 )
                                              {
                                                if ( sscanf(v9, "ENGINE_STARTER=%s", v44) == 1 )
                                                {
                                                  v37[0] = (__int32)v44;
                                                  goto LABEL_182;
                                                }
                                                if ( sscanf(v9, "SPEED_LIMITER_TOGGLE=%s", v44) == 1 )
                                                {
                                                  v37[0] = (__int32)v44;
                                                  goto LABEL_182;
                                                }
                                                if ( sscanf(v9, "LAUNCH_CONTROL_TOGGLE=%s", v44) != 1 )
                                                {
                                                  if ( sscanf(v9, "ON_FIRE=%s", v44) == 1 )
                                                  {
                                                    v37[0] = (__int32)v44;
                                                    goto LABEL_182;
                                                  }
                                                  if ( sscanf(v9, "HORN=%s", v44) == 1 )
                                                  {
                                                    v37[0] = (__int32)v44;
                                                    goto LABEL_182;
                                                  }
                                                  v8 = sscanf(v9, "TRACTION_CONTROL=%s", v44);
                                                  if ( v8 != 1 )
                                                    goto LABEL_192;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LABEL_181:
          v37[0] = (__int32)v44;
          goto LABEL_182;
        }
        v37[0] = (__int32)v44;
      }
LABEL_182:
      v8 = sub_615860(v37[0]);
      goto LABEL_192;
    }
LABEL_185:
    sub_613C30(v55);
    v7 = v54;
  }
  if ( sub_53F260(*(_DWORD **)this) )
  {
    v29 = v48;
    v30 = v52;
    *((_DWORD *)this + 62) = dword_B709B4;
    v31 = v51;
    *((_DWORD *)this + 38) = 3;
    *((_DWORD *)this + 35) = v29;
    *((_DWORD *)this + 36) = v30;
    *((_DWORD *)this + 37) = v31;
  }
  else
  {
    v32 = *this;
    *((_DWORD *)this + 62) = dword_B709D8;
    if ( *(_DWORD *)(LODWORD(v32) + 14820) == 4 )
      this[62] = this[62] * 0.5;
    v33 = v53;
    v34 = v50;
    v35 = v49;
    *((_DWORD *)this + 38) = 2;
    *((_DWORD *)this + 35) = v33;
    *((_DWORD *)this + 36) = v34;
    *((_DWORD *)this + 37) = v35;
  }
  v64 = -1;
  sub_614140(v55);
  return v7;
}
