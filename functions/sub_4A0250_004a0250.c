int sub_4A0250()
{
  char v0; // al
  bool v1; // bl
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int i; // esi

  D3DResourceListCleanup(dword_8AFE88);
  while ( ShowCursor(1) <= 0 )
    ;
  if ( dword_7C56A4 == 7 && dword_7D0410 != 6 )
  {
    v0 = sub_4D21D0(&dword_8ACEE0);
    v1 = dword_7D0410 == 5;
    if ( v0 )
    {
      if ( !*(_DWORD *)(dword_7C54E8 + 13000) )
        sub_4BC060(1);
      if ( !v1 )
      {
        v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 33);
        v3 = v2;
        if ( v2 )
        {
          sub_46BA20(v2, 0);
          FieldSetter(v3);
        }
      }
      LookupDispatch((_DWORD *)dword_7CD8C0, (int)aPostRaceMonito, -1);
    }
    else if ( dword_7D0410 != 5 && !dword_7CEC90 )
    {
      GlobalFlagSetter(&unk_7CE24D);
      sub_42D210(&dword_7C569C, 1);
      ArithmeticComparison_8d60(&byte_8AC494);
    }
  }
  ResourceDestroy(&dword_8AD238);
  GlobalStateSetter(1);
  if ( ScoringGateCheck() )
  {
    ConditionalGate(dword_7C54E8 + 12);
    SceneRenderUpdate(0);
  }
  VirtualCallOnDAT008ac4c4_8d80(&byte_8AC494);
  VirtualCallOnDAT008ac4c4(&flt_8AC4B0);
  for ( i = 0; i < dword_5C329C; ++i )
  {
    if ( *(_BYTE *)(dword_7C54F0[i] + 196) )
      StateHandlerDispatch(0);
  }
  ShortComputation_d410((int)&dword_5EA510);
  GameStateDispatchChain(&dword_5EA510, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580));
  SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.0);
  sub_4D8760(-1, 0);
  return 0;
}
