int __thiscall sub_4D4A80(int *this)
{
  int result; // eax
  int v3; // ebx
  bool v4; // zf
  const char *v5; // edi
  char *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int j; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  const char *v17; // edx
  int k; // ebx
  const char *v19; // ebp
  int v20; // edi
  const char *v21; // ecx
  char *v22; // eax
  char v23; // cl
  char *v24; // eax
  char *v25; // eax
  char v26; // al
  char *v27; // edi
  char *v28; // eax
  char *v29; // ebp
  const char *v30; // edx
  const char *v31; // ecx
  int v32; // ebx
  int v33; // edi
  char *v34; // eax
  int *v35; // [esp-8h] [ebp-3CC4h]
  int v36; // [esp-4h] [ebp-3CC0h]
  char v37; // [esp+13h] [ebp-3CA9h] BYREF
  int v38; // [esp+14h] [ebp-3CA8h] BYREF
  int i; // [esp+18h] [ebp-3CA4h]
  _BYTE v40[2]; // [esp+1Ch] [ebp-3CA0h] BYREF
  unsigned __int8 v41; // [esp+1Eh] [ebp-3C9Eh]
  unsigned __int8 v42; // [esp+1Fh] [ebp-3C9Dh]
  int v43; // [esp+20h] [ebp-3C9Ch] BYREF
  char *v44; // [esp+24h] [ebp-3C98h]
  int v45; // [esp+28h] [ebp-3C94h]
  int v46; // [esp+2Ch] [ebp-3C90h] BYREF
  int v47; // [esp+30h] [ebp-3C8Ch] BYREF
  int v48; // [esp+34h] [ebp-3C88h] BYREF
  char v49[509]; // [esp+38h] [ebp-3C84h] BYREF
  __int16 v50; // [esp+235h] [ebp-3A87h]
  char v51; // [esp+237h] [ebp-3A85h]
  char v52[256]; // [esp+238h] [ebp-3A84h] BYREF
  _BYTE v53[256]; // [esp+338h] [ebp-3984h] BYREF
  char v54[256]; // [esp+438h] [ebp-3884h] BYREF
  LPVOID v55[3]; // [esp+538h] [ebp-3784h] BYREF
  LPVOID v56; // [esp+544h] [ebp-3778h]
  LPVOID v57; // [esp+54Ch] [ebp-3770h]
  LPVOID v58; // [esp+554h] [ebp-3768h]
  LPVOID v59; // [esp+55Ch] [ebp-3760h]
  LPVOID v60; // [esp+564h] [ebp-3758h]
  char v61[104]; // [esp+1FA0h] [ebp-1D1Ch] BYREF
  LPVOID v62; // [esp+2008h] [ebp-1CB4h]
  int v63[235]; // [esp+3910h] [ebp-3ACh] BYREF

  ResourceDestroy(this);
  result = ScoringGateCheck();
  if ( (_BYTE)result )
  {
    v3 = 0;
    result = 0;
    for ( i = 0; result < dword_5C329C; ++result )
    {
      v3 = dword_7C54F0[result];
      v4 = *(_DWORD *)(v3 + 13000) == 0;
      i = v3;
      if ( v4 )
        break;
    }
    if ( result != dword_5C329C )
    {
      v5 = (const char *)dword_7CEA34;
      if ( !dword_7CEA34 )
        v5 = byte_5EA438;
      result = 0;
      if ( strlen(v5) && dword_7CE9D0 > 0 && (dword_7C56A4 != 7 || dword_7CE9F4) )
      {
        v6 = (char *)dword_7CEA34;
        if ( !dword_7CEA34 )
          v6 = byte_5EA438;
        result = sub_587DB0(v6, &unk_5C2AB0);
        v7 = result;
        *this = result;
        if ( result )
        {
          v8 = 10 * CRTFtol(40.0 / (double)dword_7CE9D0 + 0.5);
          this[1] = v8;
          if ( v8 >= 1 )
          {
            if ( v8 > 40 )
              this[1] = 40;
          }
          else
          {
            this[1] = 1;
          }
          v48 = 0;
          FileReadWrapperWithLock(&v48, 4, 1, v7);
          for ( j = 0; j < 4; ++j )
            v40[j] = RandLCGRandomNumberGenerator(v9);
          FileReadWrapperWithLock(v40, 4, 1, *this);
          v11 = v40[1];
          v12 = v40[0];
          v36 = 4;
          this[6] = 0;
          v13 = v12 + v11 + 18;
          v14 = v41;
          v15 = v41 + v11 + 77;
          this[3] = v13;
          v16 = v42;
          this[4] = v15;
          v35 = &v47;
          this[5] = v16 + v14 + 15;
          v47 = 1028443341;
          sub_4D5BE0(v35, v36);
          sub_4D5BE0(v3 + 17952, strlen((const char *)(v3 + 17952)) + 1);
          sub_4D5BE0(v3 + 18040, strlen((const char *)(v3 + 18040)) + 1);
          sub_4D5BE0(v3 + 18196, strlen((const char *)(v3 + 18196)) + 1);
          v17 = (const char *)dword_7CE5EC;
          if ( !dword_7CE5EC )
            v17 = byte_5EA438;
          sub_4D5BE0(v17, strlen(v17) + 1);
          v46 = 57;
          sub_4D5BE0(&v46, 4);
          v37 = 4;
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aElapsedTimeS, strlen(aElapsedTimeS) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aPosXM, strlen(aPosXM) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aPosYM, strlen(aPosYM) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aPosZM, strlen(aPosZM) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aYawRads, strlen(aYawRads) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aLatAccelMS, strlen(aLatAccelMS) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aVertAccelMS, strlen(aVertAccelMS) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aLongAccelMS, strlen(aLongAccelMS) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aEngineRpm, strlen(aEngineRpm) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aClutchRpm, strlen(aClutchRpm) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aUnfilteredThro, strlen(aUnfilteredThro) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aThrottle, strlen(aThrottle) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aUnfilteredBrak, strlen(aUnfilteredBrak) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aBrake, strlen(aBrake) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aUnfilteredStee, strlen(aUnfilteredStee) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aSteering, strlen(aSteering) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aUnfilteredClut, strlen(aUnfilteredClut) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aClutch, strlen(aClutch) + 1);
          for ( k = 0; k < 4; ++k )
          {
            if ( k )
            {
              if ( k == 1 )
              {
                v19 = aFr;
              }
              else
              {
                v19 = aRl;
                if ( k != 2 )
                  v19 = aRr;
              }
            }
            else
            {
              v19 = aFl;
            }
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aWheelspinRadsS, strlen(aWheelspinRadsS) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aSuspensionDefl, strlen(aSuspensionDefl) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aUndertrayRideH, strlen(aUndertrayRideH) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aTyreLeftTempK, strlen(aTyreLeftTempK) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aTyreCenterTemp, strlen(aTyreCenterTemp) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aTyreRightTempK, strlen(aTyreRightTempK) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aTyrePressureKp, strlen(aTyrePressureKp) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aTyreWear, strlen(aTyreWear) + 1);
            sub_4D5BE0(&v37, 1);
            sub_4D5BE0(v19, strlen(v19));
            sub_4D5BE0(aCornerWeight, strlen(aCornerWeight) + 1);
          }
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aGear, strlen(aGear) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aWaterTemperatu, strlen(aWaterTemperatu) + 1);
          sub_4D5BE0(&v37, 1);
          sub_4D5BE0(aOilTemperature, strlen(aOilTemperature) + 1);
          v20 = i;
          v52[0] = 0;
          v53[0] = 0;
          if ( i )
          {
            v21 = *(const char **)(1060 * *(_DWORD *)(i + 18584) + dword_8AC394 + 8);
            if ( !v21 )
              v21 = byte_5EA438;
            strcpy(v52, v21);
            v22 = (char *)(v20 + 18324);
            do
            {
              v23 = *v22;
              v53[(_DWORD)v22 - 18324 - v20] = *v22;
              ++v22;
            }
            while ( v23 );
          }
          sub_4CEEF0((int)v54, 256);
          v49[0] = byte_5EA438[0];
          memset(&v49[1], 0, 0x1FCu);
          v50 = 0;
          v51 = 0;
          v24 = (char *)dword_7CE5D0;
          if ( !dword_7CE5D0 )
            v24 = byte_5EA438;
          sub_587DD0(v49, v24, 511);
          v51 = 0;
          v25 = &v49[strlen(v49)];
          if ( v25 > v49 )
          {
            while ( *v25 != 46 )
            {
              if ( --v25 <= v49 )
                goto LABEL_43;
            }
            *v25 = 0;
          }
LABEL_43:
          v26 = byte_5C5D28;
          v27 = &v49[strlen(v49)];
          *(_DWORD *)v27 = dword_5C5D24;
          v27[4] = v26;
          TireModelDataInit(v55);
          SessionStructInit(v61);
          TheSvmHdvVehicleFileParser(v52, v61, 2);
          v38 = DeterministicHashPseudoRandomGenerator(&dword_8AAE70);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(40, &v38);
          v38 = (v38 ^ 0x12F3DCAA) + 1559;
          sub_4D5BE0(&v38, 4);
          v38 = 355 * ((int)v55[2] ^ 0xFFFAFE11);
          sub_4D5BE0(&v38, 4);
          v43 = LODWORD(flt_7C935C) ^ 0x516141F2;
          sub_4D5BE0(&v43, 4);
          UtilityFunction_8a60(151, &v38);
          v38 = (v38 ^ 0x2033DAAA) - 1559;
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(4, &v38);
          v38 = 1559 * (v38 ^ 0x7711DAAB);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(148, &v38);
          v38 = 69017 * (v38 ^ 0x7123456C);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(153, &v38);
          v38 = 59015 * (v38 ^ 0x99009977);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(26, &v38);
          v38 = 49414 * (v38 ^ 0xEEAC5370);
          sub_4D5BE0(&v38, 4);
          v38 = DeterministicHashPseudoRandomGenerator(&dword_8AAE70);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(161, &v38);
          v38 = 330358 * (v38 ^ 0x4940AF7E);
          sub_4D5BE0(&v38, 4);
          v38 = (1121110 * dword_8ACED8 + 1819630500) ^ 0x12131415;
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(82, &v38);
          v38 = (v38 ^ 0x3940AF73) + 330358;
          sub_4D5BE0(&v38, 4);
          v38 = 9 * ((dword_7C56B8 + 468717589) ^ 0xABBA717E);
          sub_4D5BE0(&v38, 4);
          v38 = DeterministicHashPseudoRandomGenerator(&dword_8AAE70);
          sub_4D5BE0(&v38, 4);
          UtilityFunction_8a60(242, &v38);
          v38 = 15833346 * (v38 ^ 0xF12003);
          sub_4D5BE0(&v38, 4);
          v28 = (char *)dword_7CE5D0;
          if ( !dword_7CE5D0 )
            v28 = byte_5EA438;
          v44 = 0;
          v45 = -1;
          StringCopyWithBufferRealloc(v28);
          v29 = v44;
          v30 = v44;
          if ( !v44 )
            v30 = byte_5EA438;
          v31 = &v30[strlen(v30)];
          if ( v31 > v30 )
          {
            while ( *v31 != 46 )
            {
              if ( --v31 <= v30 )
                goto LABEL_52;
            }
            *v31 = 0;
            v29 = v44;
          }
LABEL_52:
          v38 = 0;
          if ( dword_8AC488 > 0 )
          {
            v32 = 0;
            i = dword_8AC488;
            while ( 1 )
            {
              v33 = v32 + dword_8AC490;
              v34 = v29;
              if ( !v29 )
                v34 = byte_5EA438;
              if ( !sub_588410(v34, v33 + 4) )
                v38 = (445 * *(_DWORD *)(v33 + 392)) ^ 0xFEC950A4;
              v32 += 396;
              if ( !--i )
                break;
              v29 = v44;
            }
          }
          sub_4D5BE0(&v38, 4);
          FileReadWithXORDecode(v53);
          if ( v44 )
            FreeWrapper_7bcf(v44);
          ScoreSlotDeallocator(v63);
          if ( v62 )
            FreeWrapper_7bcf(v62);
          if ( v60 )
            FreeWrapper_7bcf(v60);
          if ( v59 )
            FreeWrapper_7bcf(v59);
          if ( v58 )
            FreeWrapper_7bcf(v58);
          if ( v57 )
            FreeWrapper_7bcf(v57);
          if ( v56 )
            FreeWrapper_7bcf(v56);
          result = (int)v55[0];
          if ( v55[0] )
            return FreeWrapper_7bcf(v55[0]);
        }
      }
    }
  }
  return result;
}

