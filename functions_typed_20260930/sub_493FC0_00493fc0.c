int __thiscall sub_493FC0(int this, const char *a2)
{
  int v3; // esi
  int i; // edi
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  int v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  char v29[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v30; // [esp+8Dh] [ebp-3h]
  char v31; // [esp+8Fh] [ebp-1h]

  if ( !a2 )
    return 0;
  v3 = (*(int (__thiscall **)(_DWORD, const char *))(**(_DWORD **)(this + 420) + 24))(*(_DWORD *)(this + 420), a2);
  if ( !v3 )
  {
    for ( i = 0; i < 23; ++i )
    {
      if ( !sub_588410(a2, off_5CC270[i]) )
      {
        switch ( i )
        {
          case 0:
            v5 = OperatorNewNhMallocWrapper(228);
            if ( !v5 )
              return 0;
            v6 = (_DWORD *)ConstructorWithByteParams(v5, 0, 0);
            goto LABEL_21;
          case 1:
            v7 = OperatorNewNhMallocWrapper(228);
            if ( !v7 )
              return 0;
            v6 = (_DWORD *)ConstructorWithByteParams(v7, 1, 0);
            goto LABEL_21;
          case 2:
            v8 = OperatorNewNhMallocWrapper(228);
            if ( !v8 )
              return 0;
            v6 = (_DWORD *)UIObjectInitWithByteParams(v8, 0, 0);
            goto LABEL_21;
          case 3:
            v9 = OperatorNewNhMallocWrapper(236);
            v3 = v9;
            if ( !v9 )
              return 0;
            ConstructorWithByteParams(v9, 0, 0);
            *(_DWORD *)v3 = &off_5AC8D8;
            *(_BYTE *)(v3 + 228) = 0;
            *(_DWORD *)(v3 + 232) = 0;
            goto LABEL_22;
          case 4:
            v10 = (_DWORD *)OperatorNewNhMallocWrapper(240);
            v3 = (int)v10;
            if ( !v10 )
              return 0;
            ShortComputation_5e30(v10);
            *(_DWORD *)v3 = &off_5AC1D0;
            F_5FieldInit(v3);
            goto LABEL_22;
          case 5:
            v11 = OperatorNewNhMallocWrapper(236);
            if ( !v11 )
              return 0;
            v6 = (_DWORD *)ConstructorInitVTable(v11, 1, -1);
            goto LABEL_21;
          case 6:
            v12 = OperatorNewNhMallocWrapper(236);
            if ( !v12 )
              return 0;
            v6 = (_DWORD *)ConstructorInitVTable(v12, 2, -1);
            goto LABEL_21;
          case 7:
            v13 = OperatorNewNhMallocWrapper(236);
            if ( !v13 )
              return 0;
            v6 = (_DWORD *)ConstructorInitVTable(v13, 3, -1);
            goto LABEL_21;
          case 8:
            v14 = (_DWORD *)OperatorNewNhMallocWrapper(272);
            if ( !v14 )
              return 0;
            v6 = ObjectInitWithFieldZeroing(v14);
            goto LABEL_21;
          case 9:
            v15 = OperatorNewNhMallocWrapper(772);
            if ( !v15 )
              return 0;
            v6 = (_DWORD *)ConstructorWithStringCopy(v15, 0, 0, 0, 0, 0, 0);
            goto LABEL_21;
          case 10:
            v16 = OperatorNewNhMallocWrapper(372);
            if ( !v16 )
              return 0;
            v6 = (_DWORD *)sub_4893C0(v16);
            goto LABEL_21;
          case 11:
            v17 = (_DWORD *)OperatorNewNhMallocWrapper(236);
            v3 = (int)v17;
            if ( !v17 )
              return 0;
            ShortComputation_5e30(v17);
            *(_DWORD *)v3 = &off_5AC830;
            *(_DWORD *)(v3 + 224) = &unk_7C7C7C;
            *(_DWORD *)(v3 + 228) = 3289650;
            *(_DWORD *)(v3 + 232) = 789516;
            goto LABEL_22;
          case 12:
            v18 = OperatorNewNhMallocWrapper(280);
            if ( !v18 )
              return 0;
            v6 = (_DWORD *)UITextDisplayConstructor(v18);
            goto LABEL_21;
          case 13:
            v19 = OperatorNewNhMallocWrapper(228);
            if ( !v19 )
              return 0;
            v6 = (_DWORD *)InitWithVTableFlags(v19, 0, 0);
            goto LABEL_21;
          case 15:
            v20 = (_DWORD *)OperatorNewNhMallocWrapper(296);
            if ( !v20 )
              return 0;
            v6 = LargeZeroInitConstructor(v20);
            goto LABEL_21;
          case 16:
            v21 = (_DWORD *)OperatorNewNhMallocWrapper(240);
            if ( !v21 )
              return 0;
            v6 = ConstructorDualSubInit(v21);
            goto LABEL_21;
          case 17:
            v22 = (_DWORD *)OperatorNewNhMallocWrapper(240);
            if ( !v22 )
              return 0;
            v6 = Constructor_e070(v22);
            goto LABEL_21;
          case 18:
            v23 = (_DWORD *)OperatorNewNhMallocWrapper(260);
            if ( !v23 )
              return 0;
            v6 = ShortComputation_e300(v23);
            goto LABEL_21;
          case 19:
            v24 = (_DWORD *)OperatorNewNhMallocWrapper(240);
            if ( !v24 )
              return 0;
            v6 = UIStructInit(v24);
            goto LABEL_21;
          case 20:
            v25 = OperatorNewNhMallocWrapper(384);
            if ( !v25 )
              return 0;
            v6 = (_DWORD *)LargeConstructor(v25);
            goto LABEL_21;
          case 21:
            v26 = (_DWORD *)OperatorNewNhMallocWrapper(232);
            if ( !v26 )
              return 0;
            v6 = UIComponentInit5(v26);
            goto LABEL_21;
          case 22:
            v27 = (_DWORD *)OperatorNewNhMallocWrapper(244);
            if ( !v27 )
              return 0;
            v6 = ObjectInitWithFieldZeroing_0250(v27);
LABEL_21:
            v3 = (int)v6;
LABEL_22:
            if ( v3 )
              goto LABEL_23;
            return v3;
          default:
            return v3;
        }
      }
    }
    return v3;
  }
LABEL_23:
  if ( !*(_DWORD *)(v3 + 140) )
    return v3;
  v29[0] = byte_5EA438[0];
  memset(&v29[1], 0, 0x7Cu);
  v30 = 0;
  v31 = 0;
  StringFormatWithBufferOverflowCheck(v29, "Prelinked Gizmo - %s", a2);
  sub_493C80((_DWORD *)this, 1, v29);
  return 0;
}

