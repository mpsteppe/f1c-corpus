int __thiscall sub_492460(int this, const char *a2)
{
  int v3; // ebp
  bool v4; // zf
  CHAR *v5; // eax
  CHAR v6; // cl
  CHAR *v7; // eax
  CHAR v8; // cl
  int v9; // eax
  CHAR SrcStr[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v12; // [esp+8Dh] [ebp-3h]
  char v13; // [esp+8Fh] [ebp-1h]

  SrcStr[0] = byte_5EA438[0];
  memset(&SrcStr[1], 0, 0x7Cu);
  v12 = 0;
  v3 = 0;
  v13 = 0;
  if ( a2 )
  {
    strcpy(SrcStr, a2);
    sub_589901(SrcStr);
  }
  ++*(_DWORD *)(this + 404);
  if ( !sub_588410(SrcStr, aNormal) )
  {
    if ( OperatorNewNhMallocWrapper(188) )
    {
      v3 = ConstructorWithVTableAndSubInit_9140(0);
      goto LABEL_11;
    }
    goto LABEL_6;
  }
  if ( sub_588410(SrcStr, aModal) )
  {
    StringFormatWithBufferOverflowCheck(&byte_7CDCF0, "undefined layer type %s", a2);
    sub_493C80(3, &byte_7CDCF0);
  }
  else
  {
    if ( !OperatorNewNhMallocWrapper(188) )
    {
LABEL_6:
      v3 = 0;
      goto LABEL_11;
    }
    v3 = ConstructorWithVTableAndSubInit_9140(1);
  }
LABEL_11:
  *(_DWORD *)(this + 424) = v3;
  ShortComputation_a9c0(0, 599, 0, 799);
  DoublyLinkedListNodeInsert(v3);
  while ( sub_491FB0((_DWORD *)this) )
  {
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
      break;
    if ( sub_5654A0(aName_2, SrcStr) )
    {
      if ( *(_BYTE *)(this + 410) && *(_DWORD *)(this + 412) < 4u )
        ResourcePathBuilder(SrcStr);
      sub_49AD50(SrcStr);
    }
    else
    {
      v4 = sub_5654A0(aSoundFocus, SrcStr) == 0;
      v5 = SrcStr;
      if ( v4 )
      {
        if ( !sub_5654A0(aSoundLostfocus, SrcStr) )
        {
          if ( sub_5654A0(aGizmo, SrcStr) )
          {
            v9 = sub_492A40(SrcStr);
            if ( v9 )
              SetInitCall(v9, *(_DWORD *)(this + 424));
          }
          else if ( sub_5654A0(aPage, SrcStr) )
          {
            sub_492710(SrcStr);
          }
          continue;
        }
        v7 = SrcStr;
        do
        {
          v8 = *v7;
          v7[v3 - (_DWORD)SrcStr + 148] = *v7;
          ++v7;
        }
        while ( v8 );
      }
      else
      {
        do
        {
          v6 = *v5;
          v5[v3 - (_DWORD)SrcStr + 108] = *v5;
          ++v5;
        }
        while ( v6 );
      }
      TextureSurfaceLoader(SrcStr);
    }
  }
  --*(_DWORD *)(this + 404);
  *(_DWORD *)(this + 424) = 0;
  return 0;
}
