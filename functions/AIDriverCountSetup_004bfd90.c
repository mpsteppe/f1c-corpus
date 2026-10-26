int __stdcall sub_4BFD90(const char *a1)
{
  int v1; // eax
  char v2; // cl
  char *v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // ebp
  int v8; // ebx
  char *v9; // esi
  int v10; // eax
  char *v11; // eax
  int v13[4]; // [esp+4h] [ebp-110h] BYREF
  _BYTE v14[256]; // [esp+14h] [ebp-100h] BYREF

  if ( dword_5C329C > 0 )
  {
    ZeroInit4Ints(v13);
    if ( ScoringGateCheck() )
    {
      v3 = (char *)dword_7CE64C;
      if ( !dword_7CE64C )
        v3 = byte_5EA438;
      sub_587DD0(v14, v3, 255);
      v14[255] = 0;
    }
    else
    {
      v1 = 0;
      do
      {
        v2 = byte_5EA438[v1];
        v14[v1++] = v2;
      }
      while ( v2 );
    }
    if ( dword_7D0410 == 1 )
    {
      if ( dword_7D00C8 )
      {
        dword_5C329C = 1;
        BuildActiveVehiclePointerArray();
LABEL_20:
        LinkedListDestruction_f640(v13);
        goto LABEL_21;
      }
      dword_5C329C = DeterministicHashPseudoRandomGenerator(&dword_8AAE70) % 3 + 3;
      BuildActiveVehiclePointerArray();
    }
    if ( ScoringGateCheck() )
      v4 = dword_5C329C - 1;
    else
      v4 = dword_5C329C;
    if ( AIOpponentSelection(v13, v4, (int)v14, a1) == v4 )
    {
      v5 = ScoringGateCheck();
      v6 = v5;
      v7 = v5 + v4;
      if ( v5 < v5 + v4 )
      {
        v8 = 0;
        v9 = (char *)&unk_5EC6D8 + 18624 * v5;
        do
        {
          SessionStateTransition(1, 0);
          v10 = IndexedListLookup(v13, v8);
          NationalityDriverInfoLoader(v10);
          TeamIDSetter(v6++);
          ++v8;
          v9 += 18624;
        }
        while ( v6 < v7 );
      }
    }
    goto LABEL_20;
  }
LABEL_21:
  v11 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v11 = byte_5EA438;
  VehicleLookupByName(v11);
  NationalityDriverInfoLoader(dword_8AC38C);
  TeamIDSetter(0);
  if ( ScoringGateCheck() )
    SessionStateTransition(0, 0);
  else
    SessionStateTransition(1, 0);
  return 0;
}
