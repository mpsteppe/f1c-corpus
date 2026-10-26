int __thiscall sub_492710(int this, int a2)
{
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v11; // [esp-Ch] [ebp-1B4h]
  int v12; // [esp-Ch] [ebp-1B4h]
  int v13; // [esp-Ch] [ebp-1B4h]
  int v14; // [esp-8h] [ebp-1B0h]
  int v15; // [esp-8h] [ebp-1B0h]
  int v16; // [esp-8h] [ebp-1B0h]
  int v17; // [esp-4h] [ebp-1ACh]
  int v18; // [esp-4h] [ebp-1ACh]
  int v19; // [esp-4h] [ebp-1ACh]
  float v20; // [esp+8h] [ebp-1A0h] BYREF
  float v21; // [esp+Ch] [ebp-19Ch] BYREF
  float v22; // [esp+10h] [ebp-198h] BYREF
  float v23; // [esp+14h] [ebp-194h] BYREF
  float v24; // [esp+18h] [ebp-190h] BYREF
  float v25; // [esp+1Ch] [ebp-18Ch] BYREF
  float v26; // [esp+20h] [ebp-188h] BYREF
  float v27; // [esp+24h] [ebp-184h] BYREF
  _BYTE v28[128]; // [esp+28h] [ebp-180h] BYREF
  CHAR v29[125]; // [esp+A8h] [ebp-100h] BYREF
  __int16 v30; // [esp+125h] [ebp-83h]
  char v31; // [esp+127h] [ebp-81h]
  _BYTE v32[128]; // [esp+128h] [ebp-80h] BYREF

  v29[0] = byte_5EA438[0];
  memset(&v29[1], 0, 0x7Cu);
  v30 = 0;
  v31 = 0;
  if ( OperatorNewNhMallocWrapper(104) )
    v3 = FunctionCallWrapper_91e0(0);
  else
    v3 = 0;
  NodeInsertionIntoTree(v3);
  v4 = *(_DWORD *)(this + 404) + 1;
  *(_DWORD *)(this + 428) = v3;
  *(_DWORD *)(this + 404) = v4;
  while ( sub_491FB0((_DWORD *)this) )
  {
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
      break;
    if ( sub_5654A0(aName_2, v29) )
    {
      if ( *(_BYTE *)(this + 410) && *(_DWORD *)(this + 412) < 4u )
        ResourcePathBuilder(v29);
      sub_49AD50(v29);
    }
    else if ( sub_5654A0(aEntertarget, v28) || sub_5654A0(aEsctarget, v28) )
    {
      StringCopyWithBufferRealloc(v28);
    }
    else if ( sub_565870(aLocation, &v23, &v21, &v20, &v22, 0, 0, 0, 0) )
    {
      v17 = CRTFtol(v22);
      v14 = CRTFtol(v20);
      v11 = CRTFtol(v21);
      v5 = CRTFtol(v23);
      ShortComputation_a9c0(v5, v11, v14, v17);
    }
    else if ( sub_565870(aPosWH, &v25, &v24, &v27, &v26, 0, 0, 0, 0) )
    {
      v18 = CRTFtol(v25 + v27);
      v15 = CRTFtol(v25);
      v12 = CRTFtol(v24 + v26);
      v6 = CRTFtol(v24);
      ShortComputation_a9c0(v6, v12, v15, v18);
    }
    else if ( sub_565870(aLocation2, &v23, &v21, &v20, &v22, 0, 0, 0, 0) )
    {
      v19 = CRTFtol(v22);
      v16 = CRTFtol(v20);
      v13 = CRTFtol(v21);
      v7 = CRTFtol(v23);
      RectangleEdgeOffsetCalculator(v7, v13, v16, v19);
    }
    else if ( sub_5654A0(aSurface, v28) )
    {
      sub_497AD0(v28, 1);
      v8 = sub_497BA0(v28);
      sub_4992E0(v8, 1);
    }
    else if ( sub_5654A0(aGizmo, v32) )
    {
      v9 = sub_492A40(v32);
      if ( v9 )
        DualFieldSetterProcessCall(v9, *(_DWORD *)(this + 424), *(_DWORD *)(this + 428));
    }
  }
  --*(_DWORD *)(this + 404);
  *(_DWORD *)(this + 428) = 0;
  return 0;
}

