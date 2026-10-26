LPCSTR sub_4D24D0()
{
  char *v0; // eax
  const char *v1; // ebx
  unsigned int v2; // esi
  unsigned int v3; // kr04_4
  signed int v4; // ecx
  _DWORD *v5; // esi
  LPCSTR v6; // eax
  int v7; // edi
  int *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // ebx
  int i; // ebp
  int v13; // edi
  int v14; // esi
  int j; // edi
  double v16; // st7
  LPCSTR result; // eax
  unsigned __int64 v18; // [esp+0h] [ebp-4E4h]
  float v19; // [esp+28h] [ebp-4BCh]
  _BYTE v20[28]; // [esp+2Ch] [ebp-4B8h] BYREF
  int v21; // [esp+48h] [ebp-49Ch] BYREF
  LPCSTR lpPathName; // [esp+4Ch] [ebp-498h]
  int v23; // [esp+50h] [ebp-494h]
  char v24[4]; // [esp+54h] [ebp-490h] BYREF
  float v25; // [esp+5Ch] [ebp-488h]
  float v26; // [esp+60h] [ebp-484h]
  _BYTE v27[61]; // [esp+64h] [ebp-480h] BYREF
  __int16 v28; // [esp+A1h] [ebp-443h]
  char v29; // [esp+A3h] [ebp-441h]
  CHAR v30[64]; // [esp+A4h] [ebp-440h] BYREF
  CHAR PathName[1024]; // [esp+E4h] [ebp-400h] BYREF

  lpPathName = (LPCSTR)sub_587C03(256);
  *lpPathName = 0;
  v0 = (char *)dword_5EC438;
  v23 = 256;
  if ( !dword_5EC438 )
    v0 = byte_5EA438;
  sub_566650(v0);
  sub_5665B0(aResults);
  v1 = lpPathName;
  if ( !lpPathName )
    v1 = byte_5EA438;
  v2 = 0;
  v3 = strlen(v1) + 1;
  v4 = v3 - 1;
  if ( (int)(v3 - 1) > 0 )
  {
    do
    {
      if ( v2 >= 0x400 )
        break;
      if ( PathName[v2 + v1 - PathName] == 92 )
      {
        sub_587DD0(PathName, v1, v2);
        PathName[v2] = 0;
        sub_589671(PathName);
        v4 = v3 - 1;
      }
      ++v2;
    }
    while ( (int)v2 < v4 );
  }
  sub_589671(v1);
  v27[0] = byte_5EA438[0];
  memset(&v27[1], 0, 0x3Cu);
  v28 = 0;
  v29 = 0;
  sub_5896EE(v24);
  v5 = (_DWORD *)sub_589E6C(v24);
  sub_58815F(v27, "%d/%0.2d/%0.2d %0.2d:%0.2d:%0.2d", v5[5] + 1900, v5[4] + 1, v5[3], v5[2], v5[1], *v5);
  if ( byte_7D0B28 )
  {
    v18 = __PAIR64__(v5[3], v5[4] + 1);
    sub_58815F(v30, "%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d.txt", v5[5] + 1900, (_DWORD)v18, HIDWORD(v18), v5[2], v5[1], *v5);
    sub_5665B0(v30);
  }
  else
  {
    if ( dword_7C56A4 != 7 )
      goto LABEL_46;
    sub_5665B0(aRaceresultsTxt);
  }
  sub_5668B0(v20);
  v6 = lpPathName;
  if ( !lpPathName )
    v6 = byte_5EA438;
  if ( (unsigned __int8)sub_566940(v6, 0, 1, 1) == 1 )
  {
    sub_566C30(v20, aHeader);
    sub_566C30(v20, aGameS);
    sub_566C30(v20, aVersion3f);
    sub_566C30(v20, aTimestringS);
    sub_566C30(v20, &word_5C30B4);
    sub_566C30(v20, aRace);
    sub_566C30(v20, aRacemodeD);
    sub_566C30(v20, aSceneS);
    sub_566C30(v20, aAidbS);
    sub_566C30(v20, aQualifyLapsD);
    sub_566C30(v20, aRaceLapsD);
    v19 = (flt_8ACF94 - flt_8ACF90) * 0.016666668;
    v21 = (int)v19;
    sub_566C30(v20, aRaceTimeD);
    sub_566C30(v20, aRaceLength3f);
    sub_566C30(v20, aTrackLength4f);
    sub_566C30(v20, &word_5C30B4);
    if ( byte_7D0B28 )
    {
      sub_566C30(v20, aLocalSettings);
      sub_566C30(v20, aDriveaidsSteer);
      sub_566C30(v20, aDriveaidsSteer_0);
      sub_566C30(v20, aDriveaidsThrot);
      sub_566C30(v20, aDriveaidsBrake);
      sub_566C30(v20, aDriveaidsAntil);
      sub_566C30(v20, aDriveaidsSpinR);
      sub_566C30(v20, aDriveaidsInvul);
      sub_566C30(v20, aDriveaidsAutop);
      sub_566C30(v20, aDriveaidsOppos);
      sub_566C30(v20, aDriveaidsStabi);
      sub_566C30(v20, aDriveaidsNoAiC);
      sub_566C30(v20, aDriveaidsAllow);
      sub_566C30(v20, aDriveaidsAutoC);
      sub_566C30(v20, aDriveaidsAutoL);
      sub_566C30(v20, aDriveaidsAutoB);
      sub_566C30(v20, aDriveaidsShift);
      sub_566C30(v20, aDriveaidsAutoR);
      sub_566C30(v20, aDriveaidsSpeed);
      sub_566C30(v20, aDriveaidsHalfR);
      sub_566C30(v20, aDriveaidsExtra);
      sub_566C30(v20, aMechfailRateD);
      sub_566C30(v20, aGameoptDamagem);
      sub_566C30(v20, aFuelMultD);
      sub_566C30(v20, aTireMultD);
      sub_566C30(v20, aVehiclesAllowe);
      sub_566C30(v20, aMultiDataRateD);
      sub_566C30(v20, &word_5C30B4);
      sub_566C30(v20, aControls);
      v7 = 0;
      v8 = dword_7D1B08;
      do
      {
        sub_566C30(v20, aDDD_0);
        v8 += 7;
        ++v7;
      }
      while ( (int)v8 < (int)&dword_7D1FD8 );
      sub_566C30(v20, &word_5C30B4);
    }
    v9 = dword_5C329C;
    v10 = 0;
    if ( dword_5C329C > 0 )
    {
      do
      {
        v11 = 0;
        for ( i = v10 + 1; v11 < v9; ++v11 )
        {
          v13 = dword_7C54F0[v11];
          v14 = v13 + 16436;
          if ( *(_DWORD *)(v13 + 16480) == i )
          {
            sub_566C30(v20, aSlot03d);
            sub_566C30(v20, aDriverS);
            sub_566C30(v20, aVehicleS);
            sub_566C30(v20, aQualplaceD);
            if ( *(float *)(v13 + 16476) <= 0.0 )
            {
              sub_566C30(v20, aQualtime);
            }
            else
            {
              sub_5676C0(*(float *)(v13 + 16476));
              sub_566C30(v20, aQualtimeD063f);
            }
            sub_566C30(v20, aRaceplaceD);
            sub_566C30(v20, aRacelapsD);
            if ( byte_7D0B28 )
            {
              for ( j = 0; j < *(_DWORD *)(v14 + 8); ++j )
              {
                v16 = sub_4BC2A0((_DWORD *)v14, j);
                v26 = v16;
                if ( v16 > 0.0 )
                {
                  v25 = sub_4BC270((_DWORD *)v14, j);
                  sub_5676C0(v26);
                  sub_566C30(v20, aLapD3fD063f);
                }
              }
            }
            if ( *(float *)(v14 + 104) <= 0.0 )
            {
              sub_566C30(v20, aRacebesttime);
            }
            else
            {
              sub_5676C0(*(float *)(v14 + 104));
              sub_566C30(v20, aRacebestlapD06);
            }
            switch ( *(_DWORD *)(v14 + 48) )
            {
              case 0:
              case 2:
                sub_566C30(v20, aRacetimeDnf);
                sub_566C30(v20, aReasonD);
                break;
              case 1:
                sub_567700(*(float *)(v14 + 132), (int)&v21);
                sub_566C30(v20, aRacetimeD02d06);
                break;
              case 3:
                sub_566C30(v20, aRacetimeDq);
                break;
              default:
                break;
            }
            if ( *(float *)(v14 + 164) > 0.0 )
              sub_566C30(v20, aTotalFines1f);
            sub_566C30(v20, &word_5C30B4);
            v9 = dword_5C329C;
          }
        }
        v10 = i;
      }
      while ( i < v9 );
    }
    sub_566B90(v20);
  }
  sub_5668D0(v20);
LABEL_46:
  result = lpPathName;
  if ( lpPathName )
    return (LPCSTR)sub_587BCF((LPVOID)lpPathName);
  return result;
}
