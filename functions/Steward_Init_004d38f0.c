int __thiscall sub_4D38F0(float *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // edi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int result; // eax
  int v14; // edi
  _DWORD *v15; // eax
  float *v16; // eax
  int v17; // [esp+8h] [ebp-14h]
  float v18; // [esp+Ch] [ebp-10h]
  float v19; // [esp+10h] [ebp-Ch] BYREF
  _BYTE v20[4]; // [esp+14h] [ebp-8h] BYREF
  _BYTE v21[4]; // [esp+18h] [ebp-4h] BYREF

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_3, 2345) )
    DebugLogWrite(&dword_8AD25C, aEnteredSteward_0);
  StewardLightGlowNodeFinder((_DWORD *)this + 55, (int)aStlite, (int)aStglow);
  StewardLightGlowNodeFinder((_DWORD *)this + 58, (int)aPtlit02, (int)aPtglow02);
  StewardLightGlowNodeFinder((_DWORD *)this + 61, (int)aPtlit01, (int)aPtglow01);
  v2 = *((_DWORD *)this + 62);
  this[64] = 0.0;
  if ( v2 )
  {
    SceneNodePositionGetter(&v19, v20, v21);
    v3 = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, &v19, 0);
    if ( v3 )
      this[64] = *(float *)(v3 + 72);
  }
  v4 = CRTFtol(flt_5EA3FC * 0.0049999999 + 1.0);
  *((_DWORD *)this + 67) = v4;
  *((_DWORD *)this + 68) = OperatorNewNhMallocWrapper(8 * v4);
  *((_DWORD *)this + 69) = OperatorNewNhMallocWrapper(4 * *((_DWORD *)this + 67));
  v17 = *((_DWORD *)this + 67);
  v5 = 0;
  v18 = flt_5EA3FC / (double)v17;
  if ( v17 > 0 )
  {
    do
    {
      v6 = v5 + 1;
      *(float *)(*((_DWORD *)this + 68) + 8 * v5 + 4) = (double)(v5 + 1) * v18;
      ShortComputation_0f00((_DWORD *)(8 * v5 + *((_DWORD *)this + 68)), 0);
      *(_DWORD *)(*((_DWORD *)this + 69) + 4 * v7) = 0;
      v5 = v6;
    }
    while ( v6 < *((_DWORD *)this + 67) );
  }
  *(float *)(*((_DWORD *)this + 68) + 8 * *((_DWORD *)this + 67) - 4) = flt_5EA3FC;
  if ( flt_5EA3FC <= 0.0 )
    this[66] = 0.0;
  else
    this[66] = (double)*((int *)this + 67) / flt_5EA3FC;
  v8 = EvaluateSceneNodeProperty(aXpitin, 0);
  *((_DWORD *)this + 101) = v8;
  if ( v8 )
  {
    RenderFlagSetter(-11, 2048);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 2413) )
  {
    DebugLogWrite(&dword_8AD25C, aNoPitInPolyFou);
  }
  v9 = EvaluateSceneNodeProperty(aXpitout, 0);
  *((_DWORD *)this + 102) = v9;
  if ( v9 )
  {
    RenderFlagSetter(-25, 2048);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 2419) )
  {
    DebugLogWrite(&dword_8AD25C, aNoPitOutPolyFo);
  }
  v10 = EvaluateSceneNodeProperty(aXfinish, 0);
  *((_DWORD *)this + 103) = v10;
  if ( v10 )
  {
    RenderFlagSetter(0, 2048);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 2425) )
  {
    DebugLogWrite(&dword_8AD25C, aNoFinishPolyFo);
  }
  v11 = EvaluateSceneNodeProperty(aXsector1, 0);
  *((_DWORD *)this + 104) = v11;
  if ( v11 )
  {
    RenderFlagSetter(1, 2048);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 2431) )
  {
    DebugLogWrite(&dword_8AD25C, aNoSector1PolyF);
  }
  v12 = EvaluateSceneNodeProperty(aXsector2, 0);
  *((_DWORD *)this + 105) = v12;
  if ( v12 )
  {
    RenderFlagSetter(2, 2048);
  }
  else if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 2437) )
  {
    DebugLogWrite(&dword_8AD25C, aNoSector2PolyF);
  }
  switch ( dword_7D0410 )
  {
    case 1:
      MultiplayerVehiclePlacement(&dword_7C569C, 0);
      break;
    case 2:
      MultiplayerVehiclePlacement(&dword_7C569C, 7);
      break;
    case 3:
    case 5:
      MultiplayerVehiclePlacement(&dword_7C569C, 1);
      break;
    default:
      break;
  }
  result = EvaluateSceneNodeProperty(aHelicopter, 0);
  v14 = result;
  if ( result )
  {
    v15 = (_DWORD *)OperatorNewNhMallocWrapper(28);
    if ( v15 )
    {
      v16 = (float *)ObjectConstructor(v15);
      *((_DWORD *)this + 42) = v16;
      return sub_448140(v16, v14);
    }
    else
    {
      this[42] = 0.0;
      return sub_448140(0, v14);
    }
  }
  return result;
}
