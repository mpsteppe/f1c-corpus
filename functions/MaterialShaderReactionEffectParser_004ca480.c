int __thiscall sub_4CA480(int this, int a2)
{
  float *v3; // esi
  float *v4; // edi
  float *v5; // ebx
  float *v6; // esi
  int v7; // eax
  void *v8; // esi
  int v9; // eax
  int v10; // eax
  int result; // eax
  char v12[256]; // [esp+Ch] [ebp-100h] BYREF

  v12[0] = 0;
  FloatStructInitializer((_DWORD *)this);
  if ( sub_565520(aReaction, v12, 0) )
  {
    if ( !strcmp(v12, aDust) )
    {
      *(_DWORD *)(this + 4) = 0;
    }
    else if ( !strcmp(v12, aWhitesmoke) )
    {
      *(_DWORD *)(this + 4) = 1;
    }
    else if ( !strcmp(v12, aBluesmoke) )
    {
      *(_DWORD *)(this + 4) = 2;
    }
    else if ( !strcmp(v12, aBlacksmoke) )
    {
      *(_DWORD *)(this + 4) = 3;
    }
    else if ( !strcmp(v12, aFlames) )
    {
      *(_DWORD *)(this + 4) = 4;
    }
    else if ( !strcmp(v12, aSkid) )
    {
      *(_DWORD *)(this + 4) = 6;
    }
    else if ( !strcmp(v12, aSoftskid) )
    {
      *(_DWORD *)(this + 4) = 7;
    }
    else if ( !strcmp(v12, aSpray) )
    {
      *(_DWORD *)(this + 4) = 5;
    }
    else if ( !strcmp(v12, aWetskid) )
    {
      *(_DWORD *)(this + 4) = 8;
    }
    else if ( !strcmp(v12, aGroove) )
    {
      *(_DWORD *)(this + 4) = 9;
    }
    else if ( !strcmp(v12, aWetgroove) )
    {
      *(_DWORD *)(this + 4) = 10;
    }
    else if ( !strcmp(v12, aParticle) )
    {
      *(_DWORD *)(this + 4) = 11;
    }
    else if ( !strcmp(v12, aSpark) )
    {
      *(_DWORD *)(this + 4) = 12;
    }
    else if ( !strcmp(v12, aRain) )
    {
      *(_DWORD *)(this + 4) = 13;
    }
    else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_25, 615) )
    {
      DebugLogWrite(&dword_8AD25C, aUnrecognizedRe);
    }
  }
  sub_565870(aScale, this + 12, this + 16, this + 20, 0, 0, 0, 0, 0);
  sub_565870(aGrowth, this + 24, this + 28, this + 32, 0, 0, 0, 0, 0);
  sub_565870(aGrowthvel, this + 36, this + 40, this + 44, 0, 0, 0, 0, 0);
  sub_565870(aDuration, this + 48, 0, 0, 0, 0, 0, 0, 0);
  v3 = (float *)(this + 60);
  v4 = (float *)(this + 56);
  v5 = (float *)(this + 52);
  if ( sub_565870(aAsdenvelope, this + 52, this + 56, this + 60, 0, 0, 0, 0, 0) )
  {
    if ( *(_DWORD *)(this + 4) == 5 && PathDispatch(&unk_8AFE18) < 24 )
    {
      *v5 = *v5 * 0.30000001;
      *v4 = *v4 * 0.30000001;
      *v3 = *v3 * 0.30000001;
    }
    *(float *)(this + 48) = *v5 + *v4 + *v3;
  }
  sub_565870(aPower, this + 68, 0, 0, 0, 0, 0, 0, 0);
  v6 = (float *)(this + 72);
  if ( sub_565870(aRampspeed, this + 72, 0, 0, 0, 0, 0, 0, 0) )
  {
    if ( *v6 >= 1.0 )
    {
      if ( *v6 > 3.4028235e38 )
        *v6 = 3.4028235e38;
    }
    else
    {
      *v6 = 1.0;
    }
  }
  sub_565870(aOffsetvel, this + 76, 0, 0, 0, 0, 0, 0, 0);
  if ( sub_565520(&off_5C67A8, v12, 0) )
  {
    if ( !strcmp(v12, aNumwaypoints) )
      v7 = dword_5EA3F0;
    else
      v7 = sub_587ECE(v12);
    *(_DWORD *)(this + 88) = v7;
  }
  v8 = *(void **)(this + 80);
  if ( v8 )
  {
    EmptyStub_0170();
    FreeWrapper_7bcf(v8);
    *(_DWORD *)(this + 80) = 0;
  }
  if ( !*(_DWORD *)(this + 80) )
  {
    v9 = OperatorNewNhMallocWrapper(176);
    if ( v9 )
      v10 = sub_557350(v9);
    else
      v10 = 0;
    *(_DWORD *)(this + 80) = v10;
  }
  *(_BYTE *)(*(_DWORD *)(this + 80) + 112) = 0;
  *(_BYTE *)(*(_DWORD *)(this + 80) + 56) = 0;
  *(_BYTE *)(*(_DWORD *)(this + 80) + 144) = 0;
  *(_DWORD *)(*(_DWORD *)(this + 80) + 88) = 16432;
  *(_DWORD *)(*(_DWORD *)(this + 80) + 92) = 0;
  *(_DWORD *)(*(_DWORD *)(this + 80) + 96) = -2130706433;
  *(_DWORD *)(*(_DWORD *)(this + 80) + 32) = 529;
  *(_DWORD *)(*(_DWORD *)(this + 80) + 100) = 262146;
  if ( sub_565520(&off_5D35A0, v12, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 80) + 112), v12);
    if ( !sub_587C20(*(_DWORD *)(this + 80) + 112, &word_5BEB48) )
      strcat((char *)(*(_DWORD *)(this + 80) + 112), ".BMP");
  }
  if ( sub_565520(aMts_0, v12, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 80) + 56), v12);
    if ( !sub_587C20(*(_DWORD *)(this + 80) + 56, &word_5BEB48) )
      strcat((char *)(*(_DWORD *)(this + 80) + 56), ".MTS");
  }
  if ( sub_565520(aEmap, v12, 0) )
  {
    strcpy((char *)(*(_DWORD *)(this + 80) + 144), v12);
    if ( !sub_587C20(*(_DWORD *)(this + 80) + 144, &word_5BEB48) )
      strcat((char *)(*(_DWORD *)(this + 80) + 144), ".BMP");
  }
  if ( sub_565520(aVertex, v12, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 80) + 88) = 0;
    if ( sub_566810(v12, aNoshade) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 4u;
    if ( sub_566810(v12, aFlatshade) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 8u;
    if ( sub_566810(v12, aGouraudshade) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 0x10u;
    if ( sub_566810(v12, aAlphachannel) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 0x20u;
    if ( sub_566810(v12, aSpecular) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 0x40u;
    if ( sub_566810(v12, aEnvirmap) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 0x80u;
    if ( sub_566810(v12, aGlobalshadow) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 88) |= 0x4000u;
  }
  if ( sub_565520(aPixel, v12, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 80) + 92) = 0;
    if ( sub_566810(v12, aNoreducedetail) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 92) |= 1u;
    if ( sub_566810(v12, aChromakey) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 92) |= 0x80u;
  }
  if ( sub_565520(aChroma, v12, 0) )
    *(_DWORD *)(*(_DWORD *)(this + 80) + 104) = HexStringParser(v12);
  if ( sub_565520(aColor, v12, 0) )
    *(_DWORD *)(*(_DWORD *)(this + 80) + 96) = HexStringParser(v12);
  if ( sub_565520(aParticle, v12, 0) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 80) + 32) = 0;
    if ( sub_566810(v12, aPlane) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 1u;
    if ( sub_566810(v12, &off_5D34F8) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 2u;
    if ( sub_566810(v12, aCross) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 4u;
    if ( sub_566810(v12, aMtsfile) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 8u;
    if ( sub_566810(v12, aStamps) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 0x10u;
    if ( sub_566810(v12, aBillboards) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 0x20u;
    if ( sub_566810(v12, aDeformable) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 0x80u;
    if ( sub_566810(v12, aSinglesided) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 0x200u;
    if ( sub_566810(v12, aAlphafade) )
      *(_DWORD *)(*(_DWORD *)(this + 80) + 32) |= 0x800u;
  }
  if ( sub_565520(aDestblend, v12, 0) )
  {
    *(_WORD *)(*(_DWORD *)(this + 80) + 102) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 80) + 100) |= sub_4CADA0(v12) << 16;
  }
  result = sub_565520(aSrcblend, v12, 0);
  if ( result )
  {
    *(_WORD *)(*(_DWORD *)(this + 80) + 100) = 0;
    result = sub_4CADA0(v12);
    *(_DWORD *)(*(_DWORD *)(this + 80) + 100) |= result;
  }
  return result;
}
