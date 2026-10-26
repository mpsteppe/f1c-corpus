void __thiscall sub_45F950(int this, float a2)
{
  int v3; // eax
  double v4; // st7
  int v5; // ecx
  int *v6; // ebp
  int v7; // edi
  double v8; // st7
  __int16 v9; // ax
  int v10; // ecx
  char v11; // cl
  double v12; // st7
  int v13; // edi
  double v14; // st7
  long double v15; // st7
  long double v16; // st7
  int v17; // eax
  char v18; // cl
  int v19; // eax
  float v20; // [esp+0h] [ebp-21Ch]
  int v21; // [esp+0h] [ebp-21Ch]
  int v22; // [esp+8h] [ebp-214h]
  float v23; // [esp+14h] [ebp-208h] BYREF
  float v24; // [esp+18h] [ebp-204h] BYREF
  double v25; // [esp+1Ch] [ebp-200h]
  char *v26; // [esp+24h] [ebp-1F8h] BYREF
  _BYTE v27[4]; // [esp+28h] [ebp-1F4h] BYREF
  _BYTE v28[64]; // [esp+2Ch] [ebp-1F0h] BYREF
  _BYTE v29[8]; // [esp+6Ch] [ebp-1B0h] BYREF
  __int16 v30; // [esp+74h] [ebp-1A8h]

  v3 = *(_DWORD *)(this + 16324);
  if ( v3 == 2 || v3 == 1 )
  {
    v4 = a2 + *(float *)(this + 908);
    *(float *)(this + 908) = v4;
    if ( v4 > 5.0 )
    {
      v5 = *(_DWORD *)(this + 15892);
      *(_DWORD *)(this + 908) = 0;
      LODWORD(v25) = 0;
      if ( v5 > 0 )
      {
        v6 = (int *)(this + 15476);
        v7 = this + 916;
        do
        {
          if ( !(unsigned __int8)FlagBitTest(1)
            && (unsigned __int8)FlagBitTest(2)
            && TerrainSurfaceRoughnessHeightSampling(
                 (unsigned __int8 *)(this + 107456),
                 *(char *)(v7 + 124),
                 &v23,
                 COERCE_FLOAT(1)) )
          {
            v20 = dbl_8AFEA0;
            ProgressBarEventEncode(4, 42, 2, 255, LODWORD(v20), 0);
            v8 = v23;
            if ( v23 >= -5.0 )
            {
              if ( v23 > 5.0 )
                v8 = 5.0;
            }
            else
            {
              v8 = -5.0;
            }
            v9 = CRTFtol(v8 / 0.00025000001 + 0.5);
            v21 = *v6;
            v30 = v9;
            TextureCreationWrapper(v29, 2, v21, -1);
          }
          v10 = *(_DWORD *)(this + 15892);
          ++v6;
          v7 += 140;
          ++LODWORD(v25);
        }
        while ( SLODWORD(v25) < v10 );
      }
    }
  }
  else
  {
    v11 = 0;
    v12 = *(float *)(this + 16) - a2;
    *(float *)(this + 16) = v12;
    if ( v12 < 0.0 )
    {
      if ( *(_BYTE *)(this + 20) )
      {
        v11 = 1;
        *(_BYTE *)(this + 20) = 0;
      }
      *(_DWORD *)(this + 16) = *(_DWORD *)(this + 12);
      if ( v11 )
      {
        *(float *)&v22 = dbl_8AFEA0;
        UtilityFunction_e570(this, v22);
      }
    }
    if ( (unsigned __int8)AnimationValueFetchWithTiming(&v24, &v26, v27) )
    {
      v13 = *v26;
      if ( dword_7C56A4 != v13 && v13 < 8 )
      {
        *(_BYTE *)(this + 884) = 1;
        if ( !byte_7CE254 )
          sub_4A0250(&unk_7CE24C);
        MultiplayerVehiclePlacement(&dword_7C569C, v13);
        GlobalFlagSetter(&unk_7CE24D);
        *(_DWORD *)(this + 16) = 0x40000000;
      }
      v25 = v24;
      v14 = TimeOffsetGetter(&unk_8AFE18);
      v15 = v25 - v14;
      *(float *)&v25 = v15;
      v16 = fabs(v15);
      v23 = v16;
      if ( v16 > 0.001 )
      {
        if ( v23 > 0.1 )
        {
          v28[0] = 0;
          if ( BinarySearchInStringTable(byte_5EC4C0, aSynchronizingG, byte_5EC4CC) )
          {
            v17 = 0;
            do
            {
              v18 = aSynchronizingG[v17];
              byte_5EC4CC[v17++] = v18;
            }
            while ( v18 );
          }
          v19 = CRTFtol(*(float *)&v25 * 1000.0);
          StringFormatWithBufferOverflowCheck(v28, "%s (%d ms)", byte_5EC4CC, v19);
          TextLineWrappingAndRendering(&dword_7CD204, (int)v28, 3, 16909060);
        }
        if ( v23 > 0.5 )
          TimerConversionWithSin(v24);
        sub_4F9FC0(v24);
      }
    }
  }
}
