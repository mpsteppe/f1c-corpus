int __thiscall sub_4F18E0(int this, char *a2)
{
  float *v3; // edi
  float *v4; // esi
  float *v5; // esi
  int v6; // eax
  void *v7; // eax
  int v8; // eax
  int result; // eax
  char String[256]; // [esp+Ch] [ebp-100h] BYREF

  String[0] = 0;
  sub_4F1880((_DWORD *)this);
  if ( sub_577ED0(a2, aReaction, String, 0) )
  {
    if ( !strcmp(String, aDust) )
    {
      *(_DWORD *)(this + 4) = 0;
    }
    else if ( !strcmp(String, aWhitesmoke) )
    {
      *(_DWORD *)(this + 4) = 1;
    }
    else if ( !strcmp(String, aTiresmoke) )
    {
      *(_DWORD *)(this + 4) = 2;
    }
    else if ( !strcmp(String, aBlacksmoke) )
    {
      *(_DWORD *)(this + 4) = 3;
    }
    else if ( !strcmp(String, aFlames) )
    {
      *(_DWORD *)(this + 4) = 4;
    }
    else if ( !strcmp(String, aSkid) )
    {
      *(_DWORD *)(this + 4) = 6;
    }
    else if ( !strcmp(String, aSoftskid) )
    {
      *(_DWORD *)(this + 4) = 7;
    }
    else if ( !strcmp(String, aSpray) )
    {
      *(_DWORD *)(this + 4) = 5;
    }
    else if ( !strcmp(String, aWetskid) )
    {
      *(_DWORD *)(this + 4) = 8;
    }
    else if ( !strcmp(String, aGroove) )
    {
      *(_DWORD *)(this + 4) = 9;
    }
    else if ( !strcmp(String, aWetgroove) )
    {
      *(_DWORD *)(this + 4) = 10;
    }
    else if ( !strcmp(String, aParticle) )
    {
      *(_DWORD *)(this + 4) = 11;
    }
    else if ( !strcmp(String, aSpark) )
    {
      *(_DWORD *)(this + 4) = 15;
    }
    else if ( !strcmp(String, aRain) )
    {
      *(_DWORD *)(this + 4) = 16;
    }
    else if ( !strcmp(String, aWhitest) )
    {
      *(_DWORD *)(this + 4) = 14;
    }
    else if ( !strcmp(String, aGreenst) )
    {
      *(_DWORD *)(this + 4) = 13;
    }
    else if ( !strcmp(String, aRedst) )
    {
      *(_DWORD *)(this + 4) = 12;
    }
    else if ( !strcmp(String, aWallskid) )
    {
      *(_DWORD *)(this + 4) = 17;
    }
    else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 651) )
    {
      sub_500FE0((int)&unk_7D7920, aUnrecognizedRe, (char)String);
    }
  }
  sub_578220(aScale, this + 12, this + 16, this + 20, 0, 0, 0, 0, 0);
  sub_578220(aGrowth, this + 24, this + 28, this + 32, 0, 0, 0, 0, 0);
  sub_578220(aGrowthvel, this + 36, this + 40, this + 44, 0, 0, 0, 0, 0);
  sub_578220(aDuration, this + 48, 0, 0, 0, 0, 0, 0, 0);
  if ( sub_578220(aAsdenvelope, this + 52, this + 56, this + 60, 0, 0, 0, 0, 0) )
    *(float *)(this + 48) = *(float *)(this + 52) + *(float *)(this + 56) + *(float *)(this + 60);
  v3 = (float *)(this + 68);
  v4 = (float *)(this + 64);
  if ( sub_578220(aDistrib, this + 64, this + 68, 0, 0, 0, 0, 0, 0) )
  {
    if ( *v4 >= 0.0 )
    {
      if ( *v4 > 1.0 )
        *v4 = 1.0;
    }
    else
    {
      *v4 = 0.0;
    }
    if ( *v3 >= 0.0 )
    {
      if ( *v3 > 1.0 )
        *v3 = 1.0;
    }
    else
    {
      *v3 = 0.0;
    }
  }
  sub_578220(aPower, this + 76, 0, 0, 0, 0, 0, 0, 0);
  v5 = (float *)(this + 80);
  if ( sub_578220(aRampspeed, this + 80, 0, 0, 0, 0, 0, 0, 0) )
  {
    if ( *v5 >= 1.0 )
    {
      if ( *v5 > 3.4028235e38 )
        *v5 = 3.4028235e38;
    }
    else
    {
      *v5 = 1.0;
    }
  }
  sub_578220(aOffsetvel, this + 84, 0, 0, 0, 0, 0, 0, 0);
  if ( sub_577ED0(a2, off_601268, String, 0) )
  {
    if ( !strcmp(String, aNumwaypoints) )
    {
      v6 = dword_6290C4;
    }
    else if ( !strcmp(String, aDswaypoints) )
    {
      if ( *(_DWORD *)dword_7689CC != 6 )
      {
        *(_DWORD *)(this + 96) = 0;
        goto LABEL_65;
      }
      v6 = dword_6290C4;
    }
    else
    {
      v6 = atol(String);
    }
    *(_DWORD *)(this + 96) = v6;
  }
LABEL_65:
  if ( *(_DWORD *)(this + 88) )
  {
    nullsub_6(*(void **)(this + 88));
    sub_5BE8AE();
    *(_DWORD *)(this + 88) = 0;
  }
  if ( !*(_DWORD *)(this + 88) )
  {
    v7 = operator new(0xB0u);
    if ( v7 )
      v8 = sub_5AF210(v7);
    else
      v8 = 0;
    *(_DWORD *)(this + 88) = v8;
  }
  *(_BYTE *)(*(_DWORD *)(this + 88) + 112) = 0;
  *(_BYTE *)(*(_DWORD *)(this + 88) + 56) = 0;
  *(_BYTE *)(*(_DWORD *)(this + 88) + 144) = 0;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 88) = 16432;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 92) = 0;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 96) = -2130706433;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 32) = 529;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 100) = 262146;
  if ( sub_577ED0(a2, off_6114B0, String, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 88) + 112), String);
    if ( !strstr((const char *)(*(_DWORD *)(this + 88) + 112), word_5FC804) )
      strcat((char *)(*(_DWORD *)(this + 88) + 112), ".BMP");
  }
  if ( sub_577ED0(a2, off_6114AC, String, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 88) + 56), String);
    if ( !strstr((const char *)(*(_DWORD *)(this + 88) + 56), word_5FC804) )
      strcat((char *)(*(_DWORD *)(this + 88) + 56), ".MTS");
  }
  if ( sub_577ED0(a2, aEmap, String, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 88) + 144), String);
    if ( !strstr((const char *)(*(_DWORD *)(this + 88) + 144), word_5FC804) )
      strcat((char *)(*(_DWORD *)(this + 88) + 144), ".BMP");
  }
  if ( sub_577ED0(a2, aVertex, String, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 88) + 88) = 0;
    if ( sub_579060(String, aNoshade) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 4u;
    if ( sub_579060(String, aFlatshade) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 8u;
    if ( sub_579060(String, aGouraudshade) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 0x10u;
    if ( sub_579060(String, aAlphachannel) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 0x20u;
    if ( sub_579060(String, aSpecular) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 0x40u;
    if ( sub_579060(String, aEnvirmap) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 0x80u;
    if ( sub_579060(String, aGlobalshadow) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 88) |= 0x4000u;
  }
  if ( sub_577ED0(a2, aPixel, String, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 88) + 92) = 0;
    if ( sub_579060(String, aNoreducedetail) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 92) |= 1u;
    if ( sub_579060(String, aChromakey) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 92) |= 0x80u;
  }
  if ( sub_577ED0(a2, aChroma, String, 0) )
    *(_DWORD *)(*(_DWORD *)(this + 88) + 104) = sub_4F2260(String);
  if ( sub_577ED0(a2, EndPtr, String, 0) )
    *(_DWORD *)(*(_DWORD *)(this + 88) + 96) = sub_4F2260(String);
  if ( sub_577ED0(a2, aParticle, String, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 88) + 32) = 0;
    if ( sub_579060(String, aPlane) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 1u;
    if ( sub_579060(String, &off_611400) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 2u;
    if ( sub_579060(String, aCross) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 4u;
    if ( sub_579060(String, aMtsfile) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 8u;
    if ( sub_579060(String, aStamps) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 0x10u;
    if ( sub_579060(String, aBillboards) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 0x20u;
    if ( sub_579060(String, aDeformable) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 0x80u;
    if ( sub_579060(String, aSinglesided) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 0x200u;
    if ( sub_579060(String, aAlphafade) )
      *(_DWORD *)(*(_DWORD *)(this + 88) + 32) |= 0x800u;
  }
  if ( sub_577ED0(a2, aDestblend, String, 0) )
  {
    *(_WORD *)(*(_DWORD *)(this + 88) + 102) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 88) + 100) |= sub_4F22D0((char)String) << 16;
  }
  result = sub_577ED0(a2, aSrcblend, String, 0);
  if ( result )
  {
    *(_WORD *)(*(_DWORD *)(this + 88) + 100) = 0;
    result = sub_4F22D0((char)String);
    *(_DWORD *)(*(_DWORD *)(this + 88) + 100) |= result;
  }
  return result;
}
