void __thiscall sub_49A5D0(_DWORD *this, int a2)
{
  int v3; // ebx
  const CHAR *v4; // eax
  int v5; // ebx
  char *v6; // eax
  int v7; // eax
  char *v8; // esi
  int v9; // esi
  char *v10; // esi
  const CHAR *v11; // eax
  int v12; // edi
  char *v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // ebx
  char *v17; // ebx
  const CHAR *v18; // eax
  char *v19; // eax
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  const CHAR *v23; // eax
  char *v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // ebx
  const CHAR *v28; // eax
  char *v29; // eax
  int v30; // eax
  int v31; // esi
  int v32; // ebx
  const CHAR *v33; // eax
  char *v34; // eax
  int v35; // eax
  char *v36; // esi
  char *v37; // eax
  const char *v38; // esi
  char *v39; // esi
  int v40; // eax
  int v41; // esi

  v3 = 0;
  switch ( *this )
  {
    case 1:
      v3 = 1;
      goto LABEL_3;
    case 2:
LABEL_3:
      v4 = (const CHAR *)this[1];
      v5 = v3 + 1;
      if ( !v4 )
        v4 = byte_5EA438;
      v6 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v4);
      if ( v6 )
      {
        v7 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v6);
      }
      else
      {
        v8 = (char *)this[1];
        if ( !v8 )
          v8 = byte_5EA438;
        v7 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v8);
      }
      v9 = v7;
      if ( v7 )
      {
        if ( v5 == 1 )
        {
          UtilityFunction_7890(*(_DWORD *)(a2 + 64), v7, 0);
        }
        else if ( v5 == 2 )
        {
          UtilityFunction_7890(*(_DWORD *)(a2 + 64), v7, -1);
        }
        v10 = *(char **)(v9 + 52);
        if ( !v10 )
          v10 = byte_5EA438;
        StringReverseCopyLookup((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), aCurrentPage_0, (int)v10);
      }
      return;
    case 3:
      v11 = (const CHAR *)this[1];
      if ( !v11 )
        v11 = byte_5EA438;
      v12 = a2;
      v13 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v11);
      if ( !v13 )
      {
        v13 = (char *)this[1];
        if ( !v13 )
          v13 = byte_5EA438;
      }
      v14 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v13);
      v15 = this[5];
      v16 = v14;
      if ( v15 )
        TwoFieldSetter(*(_DWORD *)(a2 + 64), v15);
      UtilityFunction_7890(*(_DWORD *)(a2 + 64), v16, 1);
      v17 = *(char **)(v16 + 52);
      if ( !v17 )
        goto LABEL_44;
      goto LABEL_54;
    case 4:
      v18 = (const CHAR *)this[1];
      if ( !v18 )
        v18 = byte_5EA438;
      v12 = a2;
      v19 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v18);
      if ( !v19 )
      {
        v19 = (char *)this[1];
        if ( !v19 )
          v19 = byte_5EA438;
      }
      v20 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v19);
      v21 = this[5];
      v22 = v20;
      if ( v21 )
        TwoFieldSetter(*(_DWORD *)(a2 + 64), v21);
      UtilityFunction_7890(*(_DWORD *)(a2 + 64), v22, 2);
      v17 = *(char **)(v22 + 52);
      if ( !v17 )
        goto LABEL_44;
      goto LABEL_54;
    case 5:
      v23 = (const CHAR *)this[1];
      if ( !v23 )
        v23 = byte_5EA438;
      v12 = a2;
      v24 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v23);
      if ( !v24 )
      {
        v24 = (char *)this[1];
        if ( !v24 )
          v24 = byte_5EA438;
      }
      v25 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v24);
      v26 = this[5];
      v27 = v25;
      if ( v26 )
        TwoFieldSetter(*(_DWORD *)(a2 + 64), v26);
      UtilityFunction_7890(*(_DWORD *)(a2 + 64), v27, 3);
      v17 = *(char **)(v27 + 52);
      if ( v17 )
        goto LABEL_54;
LABEL_44:
      StringReverseCopyLookup((_DWORD *)(*(_DWORD *)(v12 + 64) + 5772), aCurrentPage_0, (int)byte_5EA438);
      break;
    case 6:
      v28 = (const CHAR *)this[1];
      if ( !v28 )
        v28 = byte_5EA438;
      v12 = a2;
      v29 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v28);
      if ( !v29 )
      {
        v29 = (char *)this[1];
        if ( !v29 )
          v29 = byte_5EA438;
      }
      v30 = UIListSearchByName_76c0(*(_DWORD **)(a2 + 64), (int)v29);
      v31 = this[5];
      v32 = v30;
      if ( v31 )
        TwoFieldSetter(*(_DWORD *)(a2 + 64), v31);
      UtilityFunction_7890(*(_DWORD *)(a2 + 64), v32, 4);
      v17 = *(char **)(v32 + 52);
      if ( !v17 )
        v17 = byte_5EA438;
LABEL_54:
      StringReverseCopyLookup((_DWORD *)(*(_DWORD *)(v12 + 64) + 5772), aCurrentPage_0, (int)v17);
      break;
    case 7:
      v33 = (const CHAR *)this[1];
      if ( !v33 )
        v33 = byte_5EA438;
      v34 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v33);
      if ( v34 )
      {
        v35 = UIListItemSearchByName(*(_DWORD **)(a2 + 64), (int)v34);
      }
      else
      {
        v36 = (char *)this[1];
        if ( !v36 )
          v36 = byte_5EA438;
        v35 = UIListItemSearchByName(*(_DWORD **)(a2 + 64), (int)v36);
      }
      if ( v35 )
        LinkedListSearchWithAction(*(_DWORD *)(a2 + 64), v35);
      break;
    case 9:
      v37 = (char *)this[3];
      if ( !v37 )
        v37 = byte_5EA438;
      v38 = (const char *)this[1];
      if ( !v38 )
        v38 = byte_5EA438;
      StringReverseCopyLookup((_DWORD *)(*(_DWORD *)(a2 + 64) + 5772), v38, (int)v37);
      break;
    case 0xA:
      ThunkPollingLoopViaFUN00498f70(*(_DWORD **)(a2 + 64));
      break;
    case 0xB:
      dword_5CC9E8 = -1;
      break;
    case 0xC:
      v39 = (char *)this[3];
      if ( !v39 )
        v39 = byte_5EA438;
      v40 = RenderingContextSetup(*(void **)(a2 + 64), (int)v39);
      v41 = v40;
      if ( v40 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v40 + 140))(v40);
        Setter(*(_DWORD **)(a2 + 64), v41);
        (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 144))(v41);
      }
      break;
    default:
      return;
  }
}
