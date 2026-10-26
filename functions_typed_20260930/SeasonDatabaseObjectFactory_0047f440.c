_DWORD *__thiscall SeasonDatabaseObjectFactory(_DWORD *this, int a2)
{
  int v2; // edi
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *result; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  int v16; // eax
  _DWORD *v17; // esi
  _DWORD *v18; // eax
  int v19; // eax
  _DWORD *v20; // esi
  _DWORD *v21; // eax
  int v22; // eax
  _DWORD *v23; // esi
  int v24; // eax
  _DWORD *v25; // esi
  int v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  int v30; // eax
  _DWORD *v31; // esi
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  _DWORD *v34; // esi
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  _DWORD *v37; // eax
  int v38; // eax
  _DWORD *v39; // esi
  _BYTE *v40; // eax
  _DWORD *v41; // eax
  int v42; // eax
  _DWORD *v43; // eax

  v2 = a2 - 1;
  if ( a2 - 1 < 0 || v2 >= 508 || this[v2 + 1607] )
    return 0;
  if ( a2 > 436 )
    return (_DWORD *)this[v2 + 1607];
  if ( a2 == 436 )
  {
    v43 = (_DWORD *)OperatorNewNhMallocWrapper(772);
    if ( v43 )
    {
      result = ConstructorWithBulkInitAndVTable(v43);
      this[v2 + 1607] = result;
      return result;
    }
LABEL_62:
    this[v2 + 1607] = 0;
    return (_DWORD *)this[v2 + 1607];
  }
  switch ( a2 )
  {
    case 1:
      v4 = OperatorNewNhMallocWrapper(236);
      v5 = (_DWORD *)v4;
      if ( !v4 )
        goto LABEL_53;
      ConstructorWithByteParams(v4, 0, 0);
      v5[57] = 0;
      v5[58] = -1;
      *v5 = &off_5A7638;
      StringCopyWithBufferRealloc((int)(v5 + 57), aF12002Gdb);
      this[v2 + 1607] = v5;
      return v5;
    case 2:
      v32 = (_DWORD *)OperatorNewNhMallocWrapper(380);
      if ( !v32 )
        goto LABEL_62;
      result = FunctionCallWrapper_85b0(v32);
      this[v2 + 1607] = result;
      return result;
    case 3:
      v33 = (_DWORD *)OperatorNewNhMallocWrapper(1108);
      v34 = v33;
      if ( !v33 )
        goto LABEL_53;
      ObjectConstructorWithZeroedFields(v33);
      v34[273] = 0;
      v34[274] = 0;
      v34[275] = 0;
      v34[276] = 0;
      *v34 = &off_5A6F48;
      this[v2 + 1607] = v34;
      return v34;
    case 4:
      JUMPOUT(0x47F867);
    case 5:
    case 6:
      v7 = (_DWORD *)OperatorNewNhMallocWrapper(848);
      if ( !v7 )
        goto LABEL_62;
      result = ObjectConstructorWithVTable(v7);
      this[v2 + 1607] = result;
      return result;
    case 7:
      v8 = (_DWORD *)OperatorNewNhMallocWrapper(232);
      v9 = v8;
      if ( !v8 )
        goto LABEL_53;
      UIComponentInit5(v8);
      *v9 = &off_5A7588;
      this[v2 + 1607] = v9;
      return v9;
    case 8:
      v10 = (_DWORD *)OperatorNewNhMallocWrapper(232);
      v11 = v10;
      if ( !v10 )
        goto LABEL_53;
      UIComponentInit5(v10);
      *v11 = &off_5A74D8;
      this[v2 + 1607] = v11;
      return v11;
    case 9:
      v12 = (_DWORD *)OperatorNewNhMallocWrapper(232);
      v13 = v12;
      if ( !v12 )
        goto LABEL_53;
      UIComponentInit5(v12);
      *v13 = &off_5A7428;
      this[v2 + 1607] = v13;
      return v13;
    case 10:
      v14 = (_DWORD *)OperatorNewNhMallocWrapper(232);
      v15 = v14;
      if ( !v14 )
        goto LABEL_53;
      UIComponentInit5(v14);
      *v15 = &off_5A7378;
      this[v2 + 1607] = v15;
      return v15;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 19:
    case 25:
    case 26:
      v19 = OperatorNewNhMallocWrapper(384);
      v20 = (_DWORD *)v19;
      if ( !v19 )
        goto LABEL_53;
      LargeConstructor(v19);
      *v20 = &off_5A7218;
      this[v2 + 1607] = v20;
      return v20;
    case 16:
    case 22:
      v22 = OperatorNewNhMallocWrapper(412);
      v23 = (_DWORD *)v22;
      if ( !v22 )
        goto LABEL_53;
      LargeConstructor(v22);
      ShortComputation_5db0(v23 + 96);
      *v23 = &off_5A7168;
      this[v2 + 1607] = v23;
      return v23;
    case 17:
    case 24:
      v21 = (_DWORD *)OperatorNewNhMallocWrapper(396);
      if ( !v21 )
        goto LABEL_62;
      result = sub_477410(v21, a2);
      this[v2 + 1607] = result;
      return result;
    case 18:
      v24 = OperatorNewNhMallocWrapper(384);
      v25 = (_DWORD *)v24;
      if ( !v24 )
        goto LABEL_53;
      LargeConstructor(v24);
      *v25 = &off_5A70B8;
      this[v2 + 1607] = v25;
      return v25;
    case 20:
      v16 = OperatorNewNhMallocWrapper(388);
      v17 = (_DWORD *)v16;
      if ( !v16 )
        goto LABEL_53;
      LargeConstructor(v16);
      v17[96] = 0;
      *v17 = &off_5A72C8;
      this[v2 + 1607] = v17;
      return v17;
    case 21:
    case 23:
      v18 = (_DWORD *)OperatorNewNhMallocWrapper(400);
      if ( !v18 )
        goto LABEL_62;
      result = ShortComputation_66f0(v18, a2);
      this[v2 + 1607] = result;
      return result;
    case 27:
      v26 = OperatorNewNhMallocWrapper(380);
      if ( !v26 )
        goto LABEL_62;
      result = (_DWORD *)ConstructorWithVTableAndSubInit(v26);
      this[v2 + 1607] = result;
      return result;
    case 28:
      v27 = (_DWORD *)OperatorNewNhMallocWrapper(524);
      if ( !v27 )
        goto LABEL_62;
      result = ConstructorFieldsVTable(v27);
      this[v2 + 1607] = result;
      return result;
    case 30:
    case 32:
    case 33:
      v35 = (_DWORD *)OperatorNewNhMallocWrapper(384);
      if ( !v35 )
        goto LABEL_62;
      result = ShortComputation_b580(v35, 0, 0);
      this[v2 + 1607] = result;
      return result;
    case 31:
      v28 = (_DWORD *)OperatorNewNhMallocWrapper(384);
      if ( !v28 )
        goto LABEL_62;
      result = ShortComputation_b580(v28, 0, 1);
      this[v2 + 1607] = result;
      return result;
    case 34:
      v29 = (_DWORD *)OperatorNewNhMallocWrapper(384);
      if ( !v29 )
        goto LABEL_62;
      result = sub_4750F0(v29);
      this[v2 + 1607] = result;
      return result;
    case 35:
    case 36:
      v30 = OperatorNewNhMallocWrapper(372);
      v31 = (_DWORD *)v30;
      if ( !v30 )
        goto LABEL_53;
      sub_4893C0(v30);
      *v31 = &off_5A7008;
      this[v2 + 1607] = v31;
      return v31;
    case 37:
      v36 = (_DWORD *)OperatorNewNhMallocWrapper(288);
      if ( !v36 )
        goto LABEL_62;
      result = sub_47A9E0(v36);
      this[v2 + 1607] = result;
      return result;
    case 38:
      v37 = (_DWORD *)OperatorNewNhMallocWrapper(376);
      if ( !v37 )
        goto LABEL_62;
      result = InitWithVTable_be70(v37);
      this[v2 + 1607] = result;
      return result;
    case 39:
    case 40:
    case 41:
    case 42:
      v38 = OperatorNewNhMallocWrapper(376);
      v39 = (_DWORD *)v38;
      if ( v38 )
      {
        sub_4893C0(v38);
        *v39 = &off_5A6E98;
        v39[93] = 1;
        this[v2 + 1607] = v39;
        return v39;
      }
      else
      {
LABEL_53:
        this[v2 + 1607] = 0;
        return 0;
      }
    case 43:
      v40 = (_BYTE *)OperatorNewNhMallocWrapper(376);
      if ( !v40 )
        goto LABEL_62;
      result = ShortComputation_e7d0(v40);
      this[v2 + 1607] = result;
      break;
    case 44:
      v41 = (_DWORD *)OperatorNewNhMallocWrapper(376);
      if ( !v41 )
        goto LABEL_62;
      result = ObjectInitWithVTableState(v41);
      this[v2 + 1607] = result;
      break;
    case 45:
      v42 = OperatorNewNhMallocWrapper(228);
      if ( !v42 )
        goto LABEL_62;
      result = (_DWORD *)ConstructorWithByteParams(v42, 0, 0);
      this[v2 + 1607] = result;
      break;
    default:
      return (_DWORD *)this[v2 + 1607];
  }
  return result;
}

