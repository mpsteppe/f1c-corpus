FILE *__thiscall sub_4FD8A0(int this)
{
  FILE *result; // eax
  const char *v3; // ebx
  bool v4; // zf
  const char *v5; // edi
  const char *v6; // eax
  int v7; // eax
  int j; // edi
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  CHAR *v12; // edx
  int k; // ebx
  char *v14; // ebp
  int v15; // edi
  const char *v16; // ecx
  char *v17; // eax
  char v18; // cl
  const char *v19; // eax
  char *v20; // eax
  char *v21; // edi
  char v22; // cl
  char *v23; // eax
  char *v24; // ecx
  char *v25; // ecx
  char *v26; // ecx
  char *v27; // ecx
  char *v28; // ecx
  CHAR *v29; // eax
  char *v30; // ebp
  char *v31; // edx
  char *v32; // ecx
  int v33; // ebx
  int v34; // edi
  const char *v35; // eax
  FILE *v36; // [esp-4h] [ebp-3F3Ch]
  char v37; // [esp+13h] [ebp-3F25h] BYREF
  int v38; // [esp+14h] [ebp-3F24h] BYREF
  _BYTE v39[2]; // [esp+18h] [ebp-3F20h] BYREF
  unsigned __int8 v40; // [esp+1Ah] [ebp-3F1Eh]
  unsigned __int8 v41; // [esp+1Bh] [ebp-3F1Dh]
  int i; // [esp+1Ch] [ebp-3F1Ch]
  int v43; // [esp+20h] [ebp-3F18h] BYREF
  char *String1; // [esp+24h] [ebp-3F14h]
  int v45; // [esp+28h] [ebp-3F10h]
  int v46; // [esp+2Ch] [ebp-3F0Ch] BYREF
  int v47; // [esp+30h] [ebp-3F08h] BYREF
  int v48; // [esp+34h] [ebp-3F04h] BYREF
  float v49; // [esp+38h] [ebp-3F00h]
  int v50; // [esp+3Ch] [ebp-3EFCh]
  char FileName[256]; // [esp+40h] [ebp-3EF8h] BYREF
  char Destination[509]; // [esp+140h] [ebp-3DF8h] BYREF
  __int16 v53; // [esp+33Dh] [ebp-3BFBh]
  char v54; // [esp+33Fh] [ebp-3BF9h]
  char v55[256]; // [esp+340h] [ebp-3BF8h] BYREF
  char Buffer[256]; // [esp+440h] [ebp-3AF8h] BYREF
  char *v57[3]; // [esp+540h] [ebp-39F8h] BYREF
  char *v58; // [esp+54Ch] [ebp-39ECh]
  char *v59; // [esp+554h] [ebp-39E4h]
  char *v60; // [esp+55Ch] [ebp-39DCh]
  char *v61; // [esp+564h] [ebp-39D4h]
  char *v62; // [esp+56Ch] [ebp-39CCh]
  int v63[1628]; // [esp+2218h] [ebp-1D20h] BYREF
  _DWORD v64[236]; // [esp+3B88h] [ebp-3B0h] BYREF

  sub_4FE670(this);
  result = (FILE *)sub_42DBA0();
  if ( (_BYTE)result )
  {
    v3 = 0;
    result = 0;
    for ( i = 0; (int)result < (int)NumOfElements; result = (FILE *)((char *)result + 1) )
    {
      v3 = (const char *)dword_75AAD0[(_DWORD)result];
      v4 = *((_DWORD *)v3 + 4146) == 0;
      i = (int)v3;
      if ( v4 )
        break;
    }
    if ( result != (FILE *)NumOfElements )
    {
      v5 = dword_766B44;
      if ( !dword_766B44 )
        v5 = &byte_629120;
      result = 0;
      if ( strlen(v5) && dword_766AE0 > 0 && (dword_75CBB0 != 7 || dword_766B04) )
      {
        v6 = dword_766B44;
        if ( !dword_766B44 )
          v6 = &byte_629120;
        result = fopen(v6, aWb);
        *(_DWORD *)this = result;
        if ( result )
        {
          v49 = 40.0 / (double)dword_766AE0;
          v50 = (int)v49;
          v7 = 8 * v50;
          *(_DWORD *)(this + 4) = 8 * v50;
          if ( v7 >= 8 )
          {
            if ( v7 > 320 )
              *(_DWORD *)(this + 4) = 320;
          }
          else
          {
            *(_DWORD *)(this + 4) = 8;
          }
          v36 = *(FILE **)this;
          v46 = 0;
          sub_5BF5A6(&v46, 4u, 1u, v36);
          for ( j = 0; j < 4; ++j )
            v39[j] = rand();
          sub_5BF5A6(v39, 4u, 1u, *(FILE **)this);
          v9 = v39[1];
          v10 = v39[0];
          *(_DWORD *)(this + 24) = 0;
          v47 = 1028443341;
          *(_DWORD *)(this + 12) = v10 + v9 + 18;
          v11 = v41 + v40 + 15;
          *(_DWORD *)(this + 16) = v40 + v9 + 77;
          *(_DWORD *)(this + 20) = v11;
          sub_4FEA10(&v47, 4u);
          sub_4FEA10((void *)(v3 + 24772), strlen(v3 + 24772) + 1);
          sub_4FEA10((void *)(v3 + 24836), strlen(v3 + 24836) + 1);
          sub_4FEA10((void *)(v3 + 24992), strlen(v3 + 24992) + 1);
          v12 = dword_766594;
          if ( !dword_766594 )
            v12 = &byte_629120;
          sub_4FEA10(v12, strlen(v12) + 1);
          v48 = 57;
          sub_4FEA10(&v48, 4u);
          v37 = 4;
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aElapsedTimeS, strlen(aElapsedTimeS) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aPosXM, strlen(aPosXM) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aPosYM, strlen(aPosYM) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aPosZM, strlen(aPosZM) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aYawRads, strlen(aYawRads) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aLatAccelMS, strlen(aLatAccelMS) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aVertAccelMS, strlen(aVertAccelMS) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aLongAccelMS, strlen(aLongAccelMS) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aEngineRpm, strlen(aEngineRpm) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aClutchRpm, strlen(aClutchRpm) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aUnfilteredThro, strlen(aUnfilteredThro) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aThrottle, strlen(aThrottle) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aUnfilteredBrak, strlen(aUnfilteredBrak) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aBrake, strlen(aBrake) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aUnfilteredStee, strlen(aUnfilteredStee) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aSteering, strlen(aSteering) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aUnfilteredClut, strlen(aUnfilteredClut) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aClutch, strlen(aClutch) + 1);
          for ( k = 0; k < 4; ++k )
          {
            if ( k )
            {
              if ( k == 1 )
              {
                v14 = aFr;
              }
              else
              {
                v14 = aRl;
                if ( k != 2 )
                  v14 = aRr;
              }
            }
            else
            {
              v14 = aFl;
            }
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aWheelspinRadsS, strlen(aWheelspinRadsS) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aSuspensionDefl, strlen(aSuspensionDefl) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aUndertrayRideH, strlen(aUndertrayRideH) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aTyreLeftTempK, strlen(aTyreLeftTempK) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aTyreCenterTemp, strlen(aTyreCenterTemp) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aTyreRightTempK, strlen(aTyreRightTempK) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aTyrePressureKp, strlen(aTyrePressureKp) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aTyreWear, strlen(aTyreWear) + 1);
            sub_4FEA10(&v37, 1u);
            sub_4FEA10(v14, strlen(v14));
            sub_4FEA10(aCornerWeight, strlen(aCornerWeight) + 1);
          }
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aGear, strlen(aGear) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aWaterTemperatu, strlen(aWaterTemperatu) + 1);
          sub_4FEA10(&v37, 1u);
          sub_4FEA10(aOilTemperature, strlen(aOilTemperature) + 1);
          v15 = i;
          FileName[0] = 0;
          v55[0] = 0;
          if ( i )
          {
            v16 = *(const char **)(1232 * *(_DWORD *)(i + 25252) + dword_7D6A5C + 8);
            if ( !v16 )
              v16 = &byte_629120;
            strcpy(FileName, v16);
            v17 = (char *)(v15 + 25120);
            do
            {
              v18 = *v17;
              v55[(_DWORD)v17 - 25120 - v15] = *v17;
              ++v17;
            }
            while ( v18 );
          }
          sub_4F6A10(Buffer, 256);
          Destination[0] = byte_629120;
          memset(&Destination[1], 0, 0x1FCu);
          v53 = 0;
          v54 = 0;
          v19 = dword_766578;
          if ( !dword_766578 )
            v19 = &byte_629120;
          strncpy(Destination, v19, 0x1FFu);
          v54 = 0;
          v20 = &Destination[strlen(Destination)];
          if ( v20 > Destination )
          {
            while ( *v20 != 46 )
            {
              if ( --v20 <= Destination )
                goto LABEL_43;
            }
            *v20 = 0;
          }
LABEL_43:
          v21 = &Destination[strlen(Destination) + 1];
          v22 = byte_5FFC78;
          *(_DWORD *)--v21 = dword_5FFC74;
          v21[4] = v22;
          sub_5208C0(v57);
          sub_430BC0((char *)v63);
          sub_521740((char)FileName, (int)v63, 2);
          v38 = sub_4D1A80(&dword_7D3C50);
          sub_4FEA10(&v38, 4u);
          sub_57B490(FileName, 40, (int)&v38);
          v38 = (v38 ^ 0x12F3DCAA) + 1559;
          sub_4FEA10(&v38, 4u);
          v38 = 355 * ((int)v57[2] ^ 0xFFFAFE11);
          sub_4FEA10(&v38, 4u);
          v43 = LODWORD(flt_760B10) ^ 0x516141F2;
          sub_4FEA10(&v43, 4u);
          v23 = v57[0];
          if ( !v57[0] )
            v23 = &byte_629120;
          sub_57B490(v23, 151, (int)&v38);
          v38 = (v38 ^ 0x2033DAAA) - 1559;
          sub_4FEA10(&v38, 4u);
          v24 = v58;
          if ( !v58 )
            v24 = &byte_629120;
          sub_57B490(v24, 4, (int)&v38);
          v38 = 1559 * (v38 ^ 0x7711DAAB);
          sub_4FEA10(&v38, 4u);
          v25 = v59;
          if ( !v59 )
            v25 = &byte_629120;
          sub_57B490(v25, 148, (int)&v38);
          v38 = 69017 * (v38 ^ 0x7123456C);
          sub_4FEA10(&v38, 4u);
          v26 = v60;
          if ( !v60 )
            v26 = &byte_629120;
          sub_57B490(v26, 153, (int)&v38);
          v38 = 59015 * (v38 ^ 0x99009977);
          sub_4FEA10(&v38, 4u);
          v27 = v61;
          if ( !v61 )
            v27 = &byte_629120;
          sub_57B490(v27, 26, (int)&v38);
          v38 = 49414 * (v38 ^ 0xEEAC5370);
          sub_4FEA10(&v38, 4u);
          v38 = sub_4D1A80(&dword_7D3C50);
          sub_4FEA10(&v38, 4u);
          v28 = v62;
          if ( !v62 )
            v28 = &byte_629120;
          sub_57B490(v28, 161, (int)&v38);
          v38 = 330358 * (v38 ^ 0x4940AF7E);
          sub_4FEA10(&v38, 4u);
          v38 = (1121110 * dword_7D741C + 822149884) ^ 0x12131415;
          sub_4FEA10(&v38, 4u);
          sub_57B490(Buffer, 82, (int)&v38);
          v38 = (v38 ^ 0x3940AF73) + 330358;
          sub_4FEA10(&v38, 4u);
          v38 = 9 * ((dword_75CBC4 + 363585918) ^ 0xABBA717E);
          sub_4FEA10(&v38, 4u);
          v38 = sub_4D1A80(&dword_7D3C50);
          sub_4FEA10(&v38, 4u);
          sub_57B490(Destination, 242, (int)&v38);
          v38 = 15833346 * (v38 ^ 0xF12003);
          sub_4FEA10(&v38, 4u);
          v29 = dword_766578;
          if ( !dword_766578 )
            v29 = &byte_629120;
          String1 = 0;
          v45 = -1;
          sub_578600(v29);
          v30 = String1;
          v31 = String1;
          if ( !String1 )
            v31 = &byte_629120;
          v32 = &v31[strlen(v31)];
          if ( v32 > v31 )
          {
            while ( *v32 != 46 )
            {
              if ( --v32 <= v31 )
                goto LABEL_64;
            }
            *v32 = 0;
            v30 = String1;
          }
LABEL_64:
          v38 = 0;
          if ( dword_7D6B50 > 0 )
          {
            v33 = 0;
            i = dword_7D6B50;
            while ( 1 )
            {
              v34 = v33 + dword_7D6B58;
              v35 = v30;
              if ( !v30 )
                v35 = &byte_629120;
              if ( !_strcmpi(v35, (const char *)(v34 + 4)) )
                v38 = (445 * *(_DWORD *)(v34 + 396)) ^ 0xFEC950A4;
              v33 += 400;
              if ( !--i )
                break;
              v30 = String1;
            }
          }
          sub_4FEA10(&v38, 4u);
          sub_4FE920(v55);
          if ( String1 )
            sub_5BE8AE();
          sub_430670(v64);
          if ( v63[26] )
            sub_5BE8AE();
          if ( v62 )
            sub_5BE8AE();
          if ( v61 )
            sub_5BE8AE();
          if ( v60 )
            sub_5BE8AE();
          if ( v59 )
            sub_5BE8AE();
          if ( v58 )
            sub_5BE8AE();
          result = (FILE *)v57[0];
          if ( v57[0] )
            return (FILE *)sub_5BE8AE();
        }
      }
    }
  }
  return result;
}
