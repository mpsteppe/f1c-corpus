int __thiscall sub_4B0540(int this, int a2)
{
  char v4; // al
  char *v5; // eax
  int v6; // edi
  int v7; // eax
  char *v8; // esi
  _BYTE v9[28]; // [esp+8h] [ebp-21Ch] BYREF
  char v10[509]; // [esp+24h] [ebp-200h] BYREF
  __int16 v11; // [esp+221h] [ebp-3h]
  char v12; // [esp+223h] [ebp-1h]

  v10[0] = byte_5EA438[0];
  memset(&v10[1], 0, 0x1FCu);
  v11 = 0;
  v12 = 0;
  ZeroInitSmallStruct(v9);
  if ( (GetFileAttributesA((LPCSTR)(this + 20)) & 1) != 0 )
    *(_DWORD *)(this + 276) = 1;
  sub_568620(512);
  if ( (unsigned __int8)AudioStreamOpen(v10, 1) )
  {
    sub_568910(512);
    strcpy((char *)(this + 20), v10);
    if ( (byte_7CB710 & 1) != 0 )
      sub_4AE750((int *)this, 2);
    else
      sub_4AE750((int *)this, 1);
    LinkedListWalker((_DWORD *)this, (int)v9);
    v4 = *(_BYTE *)(this + 12040);
    *(_DWORD *)(this + 7936) = *(_DWORD *)(this + 7936) > 0;
    if ( v4 && *(int *)(this + 12172) < 34 )
      *(_DWORD *)(this + 12172) = 34;
    if ( *(_BYTE *)(this + 11992) && *(int *)(this + 12172) < 33 )
      *(_DWORD *)(this + 12172) = 33;
    v5 = *(char **)(this + 312);
    if ( !v5 )
      v5 = byte_5EA438;
    SceneDataParser(v5);
    v6 = *(_DWORD *)(this + 36 * *(_DWORD *)(this + 8056) + 9464);
    v7 = v6 + ScoringGateCheck();
    if ( v7 >= 1 )
    {
      if ( v7 > 104 )
        v7 = 104;
    }
    else
    {
      v7 = 1;
    }
    if ( *(_DWORD *)(this + 8056) == 5 )
      v7 = 0;
    dword_5C329C = v7;
    BuildActiveVehiclePointerArray();
    F_5StepInit(this);
    sub_4B0EF0(*(_DWORD *)(this + 8056));
    AutoLoadEntryListLoader((int)&dword_7C73E8);
    v8 = *(char **)(this + 436);
    if ( !v8 )
      v8 = byte_5EA438;
    ShortComputation_5730((int **)&dword_5EA5E8, (int)v8);
    SubCallWithConditionalFieldFree(v9);
    return 0;
  }
  else
  {
    SubCallWithConditionalFieldFree(v9);
    return -1;
  }
}
