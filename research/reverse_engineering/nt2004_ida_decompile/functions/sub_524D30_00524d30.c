int __thiscall sub_524D30(float *this, char *Source, int a3, int a4)
{
  int v4; // ebx
  const char *v5; // esi
  int v6; // eax
  float *v7; // edi
  int v8; // esi
  int v10; // [esp+Ch] [ebp-398h] BYREF
  char v11[64]; // [esp+10h] [ebp-394h] BYREF
  int v12; // [esp+50h] [ebp-354h] BYREF
  int v13; // [esp+54h] [ebp-350h] BYREF
  int v14; // [esp+58h] [ebp-34Ch] BYREF
  int v15; // [esp+5Ch] [ebp-348h] BYREF
  int v16; // [esp+60h] [ebp-344h] BYREF
  int v17; // [esp+64h] [ebp-340h] BYREF
  float *v18; // [esp+68h] [ebp-33Ch]
  int v19; // [esp+6Ch] [ebp-338h]
  _DWORD v20[7]; // [esp+70h] [ebp-334h] BYREF
  char v21[384]; // [esp+8Ch] [ebp-318h] BYREF
  int v22; // [esp+20Ch] [ebp-198h]
  char v23; // [esp+210h] [ebp-194h]
  int v24; // [esp+218h] [ebp-18Ch]
  int v25; // [esp+21Ch] [ebp-188h]
  int v26; // [esp+220h] [ebp-184h]
  char Str1[384]; // [esp+224h] [ebp-180h] BYREF

  v18 = this;
  v4 = 1;
  sub_57A080(v20);
  memset(Str1, 0, sizeof(Str1));
  v22 = 0;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 1;
  *(float *)&v17 = 0.0;
  *(float *)&v14 = 0.0;
  *(float *)&v16 = 0.0;
  *(float *)&v12 = 0.0;
  *(float *)&v15 = 0.0;
  *(float *)&v13 = 0.0;
  sub_57A2F0(Source, 1);
  if ( v20[0] )
  {
    v19 = 0;
    while ( sub_57A490(Str1, 384) )
    {
      if ( !sub_577B60(v21) )
      {
        if ( !strncmp(Str1, aVsInside, 0xAu) )
        {
          v5 = &Str1[10];
LABEL_6:
          if ( sscanf(v5, "ENGINE_1=%s", v11) == 1
            || sscanf(v5, "ENGINE_2=%s", v11) == 1
            || sscanf(v5, "ENGINE_3=%s", v11) == 1
            || sscanf(v5, "ENGINE_4=%s", v11) == 1
            || sscanf(v5, "ENGINE_5=%s", v11) == 1
            || sscanf(v5, "WIND_NOISE=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_DRY=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_WET=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_GRASS=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_DIRT=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_GRAVEL=%s", v11) == 1
            || sscanf(v5, "ROADNOISE_RUMBLESTRIP=%s", v11) == 1
            || sscanf(v5, "SHIFT_UP_1=%s", v11) == 1
            || sscanf(v5, "SHIFT_UP_2=%s", v11) == 1
            || sscanf(v5, "SHIFT_UP_3=%s", v11) == 1
            || sscanf(v5, "SHIFT_DOWN_1=%s", v11) == 1
            || sscanf(v5, "SHIFT_DOWN_2=%s", v11) == 1
            || sscanf(v5, "SHIFT_DOWN_3=%s", v11) == 1
            || sscanf(v5, "BACKFIRE_1=%s", v11) == 1
            || sscanf(v5, "BACKFIRE_2=%s", v11) == 1
            || sscanf(v5, "BACKFIRE_3=%s", v11) == 1
            || sscanf(v5, "TIRE_SCRUB=%s", v11) == 1
            || sscanf(v5, "SKID_DRY=%s", v11) == 1
            || sscanf(v5, "SKID_WET=%s", v11) == 1
            || sscanf(v5, "SKID_GRASS=%s", v11) == 1
            || sscanf(v5, "SKID_DIRT=%s", v11) == 1
            || sscanf(v5, "SKID_GRAVEL=%s", v11) == 1
            || sscanf(v5, "SCRAPING=%s", v11) == 1
            || sscanf(v5, "HIT_WALL_1=%s", v11) == 1
            || sscanf(v5, "HIT_WALL_2=%s", v11) == 1
            || sscanf(v5, "HIT_WALL_3=%s", v11) == 1
            || sscanf(v5, "HIT_WALL_4=%s", v11) == 1
            || sscanf(v5, "HIT_WALL_5=%s", v11) == 1
            || sscanf(v5, "HIT_OTHERCAR_1=%s", v11) == 1
            || sscanf(v5, "HIT_OTHERCAR_2=%s", v11) == 1
            || sscanf(v5, "HIT_OTHERCAR_3=%s", v11) == 1
            || sscanf(v5, "HIT_OTHERCAR_4=%s", v11) == 1
            || sscanf(v5, "HIT_OTHERCAR_5=%s", v11) == 1
            || sscanf(v5, "HIT_CONE=%s", v11) == 1
            || sscanf(v5, "ENGINE_STARTING=%s", v11) == 1
            || sscanf(v5, "ENGINE_STARTER=%s", v11) == 1
            || sscanf(v5, "SPEED_LIMITER_TOGGLE=%s", v11) == 1
            || sscanf(v5, "LAUNCH_CONTROL_TOGGLE=%s", v11) == 1
            || sscanf(v5, "ON_FIRE=%s", v11) == 1
            || sscanf(v5, "HORN=%s", v11) == 1 )
          {
            sub_578600(v11);
          }
          continue;
        }
        if ( !strncmp(Str1, aVsOutside, 0xBu) )
        {
          v5 = &Str1[11];
          goto LABEL_6;
        }
        if ( sub_578110(aEnginerpmsound, (int)&v10, 0, 0, 0) )
        {
          v6 = sub_57A620(v20);
          v7 = v18;
          v8 = v6;
          sub_524540(v18 + 416, (int)v20, v10);
          sub_57A5B0(v8);
          sub_524540(v7 + 433, (int)v20, v10);
        }
        else if ( sub_578110(aEnginerpmsound_0, (int)&v10, 0, 0, 0) )
        {
          sub_524540(v18 + 416, (int)v20, v10);
        }
        else if ( sub_578110(aEnginerpmsound_1, (int)&v10, 0, 0, 0) )
        {
          sub_524540(v18 + 433, (int)v20, v10);
        }
        else
        {
          sub_578220(aPlayerenginevo, (int)&v17, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aPlayerenginevo_0, (int)&v14, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aPlayerenginevo_1, (int)&v16, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aNonPlayerengin, (int)&v12, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aNonPlayerengin_0, (int)&v15, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aNonPlayerengin_1, (int)&v13, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aEnginerange, (int)&dword_614D3C, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aEngineshape, (int)&dword_614D40, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aEngineambient, (int)&dword_614D44, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aShiftrange, (int)&dword_614D48, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aShiftshape, (int)&dword_614D4C, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aShiftambient, (int)&dword_614D50, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aOtherrange, (int)&flt_614D54, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aOthershape, (int)&flt_614D58, 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aOtherambient, (int)&flt_614D5C, 0, 0, 0, 0, 0, 0, 0);
        }
      }
    }
    sub_57A360(v20);
    v4 = v19;
  }
  if ( fabs(*(float *)&v16 + *(float *)&v14 + *(float *)&v17 - 1.0) < 0.0000099999997 )
  {
    dword_614D30 = v17;
    dword_614D34 = v14;
    dword_614D38 = v16;
  }
  if ( fabs(*(float *)&v13 + *(float *)&v15 + *(float *)&v12 - 1.0) < 0.0000099999997 )
  {
    dword_614D24 = v12;
    dword_614D28 = v15;
    dword_614D2C = v13;
  }
  sub_57A0A0(v20);
  return v4;
}
