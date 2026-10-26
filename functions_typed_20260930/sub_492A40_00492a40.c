_DWORD *__thiscall sub_492A40(int this, const char *a2)
{
  _DWORD *v3; // ebp
  int v5; // eax
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  __int16 v9; // ax
  __int16 v10; // ax
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // edx
  const char *v14; // eax
  const char **v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char **v18; // esi
  const char *v19; // eax
  int v20; // [esp-Ch] [ebp-130h]
  int v21; // [esp-8h] [ebp-12Ch]
  int v22; // [esp-4h] [ebp-128h]
  int v23; // [esp-4h] [ebp-128h]
  int v24; // [esp-4h] [ebp-128h]
  __int16 v25; // [esp-4h] [ebp-128h]
  __int16 v26; // [esp-4h] [ebp-128h]
  __int16 v27; // [esp-4h] [ebp-128h]
  char v28; // [esp+12h] [ebp-112h]
  char v29; // [esp+13h] [ebp-111h]
  float v30; // [esp+14h] [ebp-110h] BYREF
  float v31; // [esp+18h] [ebp-10Ch] BYREF
  float v32; // [esp+1Ch] [ebp-108h] BYREF
  float v33; // [esp+20h] [ebp-104h] BYREF
  CHAR v34[125]; // [esp+24h] [ebp-100h] BYREF
  __int16 v35; // [esp+A1h] [ebp-83h]
  char v36; // [esp+A3h] [ebp-81h]
  CHAR SrcStr[125]; // [esp+A4h] [ebp-80h] BYREF
  __int16 v38; // [esp+121h] [ebp-3h]
  char v39; // [esp+123h] [ebp-1h]

  v34[0] = byte_5EA438[0];
  memset(&v34[1], 0, 0x7Cu);
  v35 = 0;
  v36 = 0;
  SrcStr[0] = byte_5EA438[0];
  memset(&SrcStr[1], 0, 0x7Cu);
  v38 = 0;
  v39 = 0;
  v30 = 0.0;
  v32 = 0.0;
  v31 = 0.0;
  v33 = 0.0;
  v28 = 0;
  v29 = 0;
  if ( !a2 )
    sub_493C80(2, aNullGizmonameP);
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  ++*(_DWORD *)(this + 404);
  v3 = (_DWORD *)sub_493FC0(SrcStr);
  if ( v3 )
  {
    v3[16] = *(_DWORD *)(this + 420);
    v3[38] = *(_DWORD *)(this + 424);
    v3[39] = *(_DWORD *)(this + 428);
    while ( sub_491FB0((_DWORD *)this) )
    {
      if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
        break;
      if ( sub_5654A0(aName_2, v34) )
      {
        if ( *(_BYTE *)(this + 410) && *(_DWORD *)(this + 412) < 4u )
          ResourcePathBuilder(v34);
        sub_49AD50(v34);
      }
      else if ( sub_5654A0(aSourceVariable, v34) || sub_5654A0(aVariable, v34) || sub_5654A0(aVariableValue, v34) )
      {
        StringCopyWithBufferRealloc(v34);
      }
      else if ( sub_565870(aPosWH, &v30, &v32, &v31, &v33, 0, 0, 0, 0) )
      {
        v22 = CRTFtol(v31 + v30);
        v21 = CRTFtol(v30);
        v20 = CRTFtol(v33 + v32);
        v5 = CRTFtol(v32);
        ShortComputation_a9c0(v5, v20, v21, v22);
        v28 = 1;
      }
      else if ( sub_565870(aPosition, &v31, &v30, 0, 0, 0, 0, 0, 0) )
      {
        v23 = CRTFtol(v30);
        v6 = CRTFtol(v31);
        OffsetAccumulator(v6, v23);
      }
      else if ( sub_565870(aWidthHeight, &v30, &v31, 0, 0, 0, 0, 0, 0) )
      {
        v24 = CRTFtol(v31);
        v7 = CRTFtol(v30);
        PositionUpdate(v7, v24);
        v28 = 1;
      }
      else if ( sub_565870(aPos2Offset, &v30, &v32, &v31, &v33, 0, 0, 0, 0) )
      {
        v25 = CRTFtol(v32);
        v8 = CRTFtol(v30);
        ObjectConstructor_adc0(v8, v25);
        v26 = CRTFtol(v33);
        v9 = CRTFtol(v31);
        ObjectConstructor_adc0(v9, v26);
        v29 = 1;
      }
      else if ( sub_565870(aOffset, &v30, &v31, 0, 0, 0, 0, 0, 0) )
      {
        v27 = CRTFtol(v31);
        v10 = CRTFtol(v30);
        ObjectConstructor_adc0(v10, v27);
      }
      else if ( sub_5654A0(aCaption1, byte_7CDCF0)
             || sub_5654A0(aTooltip, byte_7CDCF0)
             || sub_5654A0(aCaption2, byte_7CDCF0) )
      {
        StringCopyWithBufferRealloc(byte_7CDCF0);
      }
      else if ( sub_5654A0(aChild, v34) )
      {
        v11 = (_DWORD *)sub_492A40(v34);
        if ( v11 )
          sub_486340(v3, v11, 0);
      }
      else if ( sub_5654A0(aActions, v34) )
      {
        sub_493480(v3, v34);
      }
      else if ( sub_5654A0(aAttributeset, v34) )
      {
        v12 = StringMatchedLinkedListSearch(v34);
        v3[50] = v12;
        if ( v12 )
        {
          LOBYTE(v13) = v29 == 0;
          LOBYTE(v12) = v28 == 0;
          ConditionalMultiParamDispatch(v12, v13);
        }
      }
      else if ( sub_5654A0(aFriendgizmo, byte_7CDCF0) )
      {
        LinkedListNodeInsert_6580(v3, (int)byte_7CDCF0);
      }
    }
    v14 = (const char *)v3[44];
    v15 = (const char **)(v3 + 44);
    if ( !v14 )
      v14 = byte_5EA438;
    if ( strlen(v14) )
    {
      v16 = *v15;
      if ( !*v15 )
        v16 = byte_5EA438;
      if ( !BinarySearchInStringTable(byte_5EC4C0, v16, byte_7CDCF0) )
        StringCopyWithBufferRealloc(byte_7CDCF0);
    }
    v17 = (const char *)v3[48];
    v18 = (const char **)(v3 + 48);
    if ( !v17 )
      v17 = byte_5EA438;
    if ( strlen(v17) )
    {
      v19 = *v18;
      if ( !*v18 )
        v19 = byte_5EA438;
      if ( !BinarySearchInStringTable(byte_5EC4C0, v19, byte_7CDCF0) )
        StringCopyWithBufferRealloc(byte_7CDCF0);
    }
    --*(_DWORD *)(this + 404);
    return v3;
  }
  else
  {
    StringFormatWithBufferOverflowCheck(byte_7CDCF0, "undefined gizmo type %s", SrcStr);
    sub_493C80(1, byte_7CDCF0);
    TokenMatchingLoop((_DWORD *)this);
    return 0;
  }
}

