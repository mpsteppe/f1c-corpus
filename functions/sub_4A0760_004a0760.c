int sub_4A0760()
{
  const char *v0; // eax
  int v1; // eax
  int v2; // esi
  int v3; // eax
  const char *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  _BYTE v8[256]; // [esp+0h] [ebp-100h] BYREF

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  sub_4B17B0(&byte_7CE498);
  if ( ScoringGateCheck() && *(_DWORD *)(dword_7C54E8 + 16480) == 1 && dword_7D032C == 1 )
  {
    v0 = (const char *)dword_5EC418;
    if ( !dword_5EC418 )
      v0 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v8, "%s%s", v0, aWinraceBik);
    FileLoadWithRetryLoop(v8, 1);
  }
  v1 = LinkedListDereference(&dword_7D2DB0);
  v2 = v1;
  if ( v1 )
  {
    PitStopPhaseAdvance(v1);
    if ( DelegatedFieldGetter(&dword_7D2DB0) == 3 )
    {
      v3 = FixedOffsetReturn(v2);
      if ( v3 )
      {
        if ( !*(_DWORD *)(v3 + 412) )
        {
          IncrementFieldAt0x34(&dword_7D2DB0);
          if ( dword_7D032C == 1 )
          {
            v4 = (const char *)dword_5EC418;
            if ( !dword_5EC418 )
              v4 = byte_5EA438;
            StringFormatWithBufferOverflowCheck(v8, "%s%s", v4, aWindriversBik);
            FileLoadWithRetryLoop(v8, 1);
          }
        }
      }
    }
    else
    {
      SeasonScoringInfoUpdater(&dword_7D2DB0);
      ArrayCheckInit(&dword_7D2DB0);
    }
  }
  v5 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 40);
  v6 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 42);
  if ( v5 )
    sub_47C360(v5, 1);
  if ( v6 )
    sub_47C360(v6, 0);
  SeasonDisplayIDResolver();
  dword_5CC9E8 = 3;
  return 0;
}
