char __fastcall sub_420490(char a1)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  char *v16; // ecx
  const char *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // eax
  int v30; // edi
  int v31; // eax
  char *v32; // ecx
  const char *v33; // eax
  int v34; // eax
  char result; // al
  char v36; // [esp+12h] [ebp-26h]
  char v37; // [esp+13h] [ebp-25h]
  float v39[8]; // [esp+18h] [ebp-20h] BYREF

  v1 = 0;
  v2 = 0;
  v36 = 0;
  v37 = 0;
  v3 = LinkedListDereference(&dword_7D2DB0);
  if ( *(_DWORD *)(FixedOffsetReturn(v3) + 412) == 1 )
  {
    v4 = LinkedListDereference(&dword_7D2DB0);
    v5 = FixedOffsetReturn(v4);
  }
  else
  {
    v6 = 0;
    v7 = LinkedListDereference(&dword_7D2DB0);
    if ( ActiveEntityCounter(v7) <= 0 )
      goto LABEL_24;
    while ( 1 )
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( *(_DWORD *)(ShortComputation_13a0(v6) + 412) == 1 )
        break;
      ++v6;
      v8 = LinkedListDereference(&dword_7D2DB0);
      if ( v6 >= ActiveEntityCounter(v8) )
        goto LABEL_24;
    }
    LinkedListDereference(&dword_7D2DB0);
    v5 = ShortComputation_13a0(v6);
  }
  v2 = v5;
  if ( v5 )
  {
    v9 = LinkedListDereference(&dword_7D2DB0);
    if ( v2 != FixedOffsetReturn(v9) )
    {
      v10 = *(_DWORD *)(v2 + 408);
      v11 = LinkedListDereference(&dword_7D2DB0);
      if ( v10 == *(_DWORD *)(FixedOffsetReturn(v11) + 408) )
        v36 = 1;
    }
    v12 = 0;
    v13 = LinkedListDereference(&dword_7D2DB0);
    if ( ActiveEntityCounter(v13) > 0 )
    {
      do
      {
        LinkedListDereference(&dword_7D2DB0);
        if ( v2 != ShortComputation_13a0(v12) )
        {
          v14 = *(_DWORD *)(v2 + 408);
          LinkedListDereference(&dword_7D2DB0);
          if ( v14 == *(_DWORD *)(ShortComputation_13a0(v12) + 408) )
            v36 = 1;
        }
        ++v12;
        v15 = LinkedListDereference(&dword_7D2DB0);
      }
      while ( v12 < ActiveEntityCounter(v15) );
    }
    if ( !v36 && a1 )
    {
      StructInitWithSentinelValues(v39);
      v16 = *(char **)(v2 + 8);
      if ( !v16 )
        v16 = &byte_5EA438;
      v17 = *(const char **)v2;
      if ( !*(_DWORD *)v2 )
        v17 = &byte_5EA438;
      v18 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v17, (int)v16);
      DriverDataTableLookupAndTimeConversion(v39, 397, v18, 2, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v39);
    }
  }
LABEL_24:
  v19 = LinkedListDereference(&dword_7D2DB0);
  if ( *(_DWORD *)(FixedOffsetReturn(v19) + 412) == 2 )
  {
    v20 = LinkedListDereference(&dword_7D2DB0);
    v21 = FixedOffsetReturn(v20);
  }
  else
  {
    v22 = 0;
    v23 = LinkedListDereference(&dword_7D2DB0);
    if ( ActiveEntityCounter(v23) <= 0 )
      goto LABEL_47;
    while ( 1 )
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( *(_DWORD *)(ShortComputation_13a0(v22) + 412) == 2 )
        break;
      ++v22;
      v24 = LinkedListDereference(&dword_7D2DB0);
      if ( v22 >= ActiveEntityCounter(v24) )
        goto LABEL_47;
    }
    LinkedListDereference(&dword_7D2DB0);
    v21 = ShortComputation_13a0(v22);
  }
  v1 = v21;
  if ( !v21 )
    goto LABEL_47;
  v25 = LinkedListDereference(&dword_7D2DB0);
  if ( v1 != FixedOffsetReturn(v25) )
  {
    v26 = *(_DWORD *)(v1 + 408);
    v27 = LinkedListDereference(&dword_7D2DB0);
    if ( v26 == *(_DWORD *)(FixedOffsetReturn(v27) + 408) )
      v37 = 1;
  }
  v28 = 0;
  v29 = LinkedListDereference(&dword_7D2DB0);
  if ( ActiveEntityCounter(v29) > 0 )
  {
    do
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( v1 != ShortComputation_13a0(v28) )
      {
        v30 = *(_DWORD *)(v1 + 408);
        LinkedListDereference(&dword_7D2DB0);
        if ( v30 == *(_DWORD *)(ShortComputation_13a0(v28) + 408) )
          v37 = 1;
      }
      ++v28;
      v31 = LinkedListDereference(&dword_7D2DB0);
    }
    while ( v28 < ActiveEntityCounter(v31) );
  }
  if ( v37 )
  {
LABEL_47:
    result = a1;
    if ( a1 )
      return result;
    goto LABEL_48;
  }
  if ( a1 )
  {
    StructInitWithSentinelValues(v39);
    v32 = *(char **)(v1 + 8);
    if ( !v32 )
      v32 = &byte_5EA438;
    v33 = *(const char **)v1;
    if ( !*(_DWORD *)v1 )
      v33 = &byte_5EA438;
    v34 = NamedEntryLookupInFormatList((char ****)&dword_5EA5E8, v33, (int)v32);
    DriverDataTableLookupAndTimeConversion(v39, 397, v34, 3, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v39);
    goto LABEL_47;
  }
LABEL_48:
  result = v36;
  if ( !v36 )
  {
    result = v37;
    if ( !v37 )
    {
      if ( v2 )
      {
        if ( v1 )
          return StructInitWithSentinelValues(v39);
      }
    }
  }
  return result;
}
