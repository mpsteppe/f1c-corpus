int __thiscall sub_4F7460(float *this, int a2, int a3, int a4)
{
  int v4; // ebx
  _BYTE *v5; // esi
  int v6; // eax
  float *v7; // edi
  int v8; // esi
  unsigned int v10; // [esp+Ch] [ebp-398h] BYREF
  char v11[64]; // [esp+10h] [ebp-394h] BYREF
  float v12; // [esp+50h] [ebp-354h] BYREF
  float v13; // [esp+54h] [ebp-350h] BYREF
  float v14; // [esp+58h] [ebp-34Ch] BYREF
  float v15; // [esp+5Ch] [ebp-348h] BYREF
  float v16; // [esp+60h] [ebp-344h] BYREF
  float v17; // [esp+64h] [ebp-340h] BYREF
  float *v18; // [esp+68h] [ebp-33Ch]
  int v19; // [esp+6Ch] [ebp-338h]
  _DWORD v20[7]; // [esp+70h] [ebp-334h] BYREF
  char v21[384]; // [esp+8Ch] [ebp-318h] BYREF
  int v22; // [esp+20Ch] [ebp-198h]
  char v23; // [esp+210h] [ebp-194h]
  int v24; // [esp+218h] [ebp-18Ch]
  int v25; // [esp+21Ch] [ebp-188h]
  int v26; // [esp+220h] [ebp-184h]
  _BYTE v27[384]; // [esp+224h] [ebp-180h] BYREF

  v18 = this;
  v4 = 1;
  sub_5668B0(v20);
  memset(v27, 0, sizeof(v27));
  v22 = 0;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 1;
  v17 = 0.0;
  v14 = 0.0;
  v16 = 0.0;
  v12 = 0.0;
  v15 = 0.0;
  v13 = 0.0;
  sub_566B20(a2, 1);
  if ( v20[0] )
  {
    v19 = 0;
    while ( sub_566CC0(v27, 384) )
    {
      if ( !sub_5651B0(v21) )
      {
        if ( !sub_588640(v27, aVsInside, 10) )
        {
          v5 = &v27[10];
LABEL_6:
          if ( sub_5887ED(v5, "ENGINE_1=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_2=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_3=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_4=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_5=%s", v11) == 1
            || sub_5887ED(v5, "WIND_NOISE=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_DRY=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_WET=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_GRASS=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_DIRT=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_GRAVEL=%s", v11) == 1
            || sub_5887ED(v5, "ROADNOISE_RUMBLESTRIP=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_UP_1=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_UP_2=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_UP_3=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_DOWN_1=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_DOWN_2=%s", v11) == 1
            || sub_5887ED(v5, "SHIFT_DOWN_3=%s", v11) == 1
            || sub_5887ED(v5, "BACKFIRE_1=%s", v11) == 1
            || sub_5887ED(v5, "BACKFIRE_2=%s", v11) == 1
            || sub_5887ED(v5, "BACKFIRE_3=%s", v11) == 1
            || sub_5887ED(v5, "SKID_DRY=%s", v11) == 1
            || sub_5887ED(v5, "SKID_WET=%s", v11) == 1
            || sub_5887ED(v5, "SKID_GRASS=%s", v11) == 1
            || sub_5887ED(v5, "SKID_DIRT=%s", v11) == 1
            || sub_5887ED(v5, "SKID_GRAVEL=%s", v11) == 1
            || sub_5887ED(v5, "SCRAPING=%s", v11) == 1
            || sub_5887ED(v5, "HIT_WALL_1=%s", v11) == 1
            || sub_5887ED(v5, "HIT_WALL_2=%s", v11) == 1
            || sub_5887ED(v5, "HIT_WALL_3=%s", v11) == 1
            || sub_5887ED(v5, "HIT_WALL_4=%s", v11) == 1
            || sub_5887ED(v5, "HIT_WALL_5=%s", v11) == 1
            || sub_5887ED(v5, "HIT_OTHERCAR_1=%s", v11) == 1
            || sub_5887ED(v5, "HIT_OTHERCAR_2=%s", v11) == 1
            || sub_5887ED(v5, "HIT_OTHERCAR_3=%s", v11) == 1
            || sub_5887ED(v5, "HIT_OTHERCAR_4=%s", v11) == 1
            || sub_5887ED(v5, "HIT_OTHERCAR_5=%s", v11) == 1
            || sub_5887ED(v5, "HIT_CONE=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_STARTING=%s", v11) == 1
            || sub_5887ED(v5, "ENGINE_STARTER=%s", v11) == 1
            || sub_5887ED(v5, "SPEED_LIMITER_TOGGLE=%s", v11) == 1
            || sub_5887ED(v5, "LAUNCH_CONTROL_TOGGLE=%s", v11) == 1
            || sub_5887ED(v5, "ON_FIRE=%s", v11) == 1
            || sub_5887ED(v5, "HORN=%s", v11) == 1
            || sub_5887ED(v5, "TRACTION_CONTROL=%s", v11) == 1 )
          {
            sub_566650(v11);
          }
          continue;
        }
        if ( !sub_588640(v27, aVsOutside, 11) )
        {
          v5 = &v27[11];
          goto LABEL_6;
        }
        if ( sub_565760(aEnginerpmsound, &v10, 0, 0, 0) )
        {
          v6 = sub_566E20(v20);
          v7 = v18;
          v8 = v6;
          sub_4F6BF0(v18 + 405, (int)v20, v10);
          sub_566DB0(v8);
          sub_4F6BF0(v7 + 422, (int)v20, v10);
        }
        else if ( sub_565760(aEnginerpmsound_0, &v10, 0, 0, 0) )
        {
          sub_4F6BF0(v18 + 405, (int)v20, v10);
        }
        else if ( sub_565760(aEnginerpmsound_1, &v10, 0, 0, 0) )
        {
          sub_4F6BF0(v18 + 422, (int)v20, v10);
        }
        else
        {
          sub_565870(aPlayerenginevo, &v17, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aPlayerenginevo_0, &v14, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aPlayerenginevo_1, &v16, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aNonPlayerengin, &v12, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aNonPlayerengin_0, &v15, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aNonPlayerengin_1, &v13, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aEnginerange, &dword_5D67B0, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aEngineshape, &dword_5D67B4, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aEngineambient, &dword_5D67B8, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aShiftrange, &dword_5D67BC, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aShiftshape, &dword_5D67C0, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aShiftambient, &dword_5D67C4, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aOtherrange, &flt_5D67C8, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aOthershape, &flt_5D67CC, 0, 0, 0, 0, 0, 0, 0);
          sub_565870(aOtherambient, &flt_5D67D0, 0, 0, 0, 0, 0, 0, 0);
        }
      }
    }
    sub_566B90(v20);
    v4 = v19;
  }
  if ( fabs(v16 + v14 + v17 - 1.0) < 0.0000099999997 )
  {
    dword_5D67A4 = LODWORD(v17);
    dword_5D67A8 = LODWORD(v14);
    dword_5D67AC = LODWORD(v16);
  }
  if ( fabs(v13 + v15 + v12 - 1.0) < 0.0000099999997 )
  {
    dword_5D6798 = LODWORD(v12);
    dword_5D679C = LODWORD(v15);
    dword_5D67A0 = LODWORD(v13);
  }
  sub_5668D0(v20);
  return v4;
}
