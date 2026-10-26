int __fastcall sub_485B90(int a1, char a2)
{
  _DWORD *v4; // eax
  int result; // eax
  int v6; // eax

  dword_5CC9E8 = 5;
  if ( dword_7CD8C0 )
  {
    if ( a1 )
      goto LABEL_10;
    dword_5CC9E4 = 2;
    while ( ShowCursor(1) <= 0 )
      ;
    if ( dword_7C569C == 5 )
      sub_4A0A80(&unk_7CE24C);
    else
      SystemOSAPICall(&unk_7CE24C);
    goto LABEL_9;
  }
  v4 = (_DWORD *)OperatorNewNhMallocWrapper(8612);
  if ( v4 )
    dword_7CD8C0 = (int)ScreenDataStructInit(v4);
  else
    dword_7CD8C0 = 0;
  Accessor();
  SingleCallWrapper_1760(0, 0, 800, 600);
  sub_4944A0(dword_7CD8C0, 0, 0, 1);
  FieldSetter_63c0(dword_7CD8C0);
  PlayerNameNeverUsedProfileFileCreateRead(&byte_7CE498);
  LinkedListSummationWithIterator(dword_7CD8C0);
  dword_5CC9E0 = LODWORD(flt_7CF2CC);
  AudioMixerDeviceInit(&byte_8AC494);
  ShortComputation_0ad0(&unk_7CE24C);
  while ( ShowCursor(1) <= 0 )
    ;
  AutoJoinRetryLoop(dword_7CD25C);
  sub_463BC0(dword_7CD25C);
  result = -1;
  if ( dword_5CC9E8 == -1 )
    return result;
  if ( !a1 )
  {
LABEL_9:
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_7CD8C0 + 36))(dword_7CD8C0);
    Accessor();
    SingleCallWrapper_1760(0, 0, 800, 600);
    v6 = Accessor();
    sub_491770(v6);
  }
LABEL_10:
  if ( byte_7D2E40 )
  {
    byte_7D2E40 = 0;
    LookupDispatch(aPopupAddprofil, -1);
    sub_4988D0(aAddProfileForc);
  }
  UILargeRender(dword_7CD8C0);
  if ( dword_5CC9E8 == 5 )
  {
    sub_496E90(0);
    if ( dword_5CC9E8 == 5 )
      dword_5CC9E8 = 0;
  }
  SoundAudioPlayback(-1.0);
  if ( a2 )
    dword_5CC9E8 = -1;
  if ( dword_5CC9E8 == -1 )
  {
    GlobalManagerShutdownSequence();
    return dword_5CC9E8;
  }
  if ( dword_5CC9E8 != 1 )
  {
    if ( dword_5CC9E8 == 2 )
    {
      sub_4A00A0(&unk_7CE24C);
      return dword_5CC9E8;
    }
    return dword_5CC9E8;
  }
  LinkedListTraversalWithVirtualCall(dword_7CD8C0);
  while ( ShowCursor(0) >= 0 )
    ;
  sub_47F230();
  SceneFilenameMatchAgainstBasePath();
  sub_4A0030(&unk_7CE24C);
  return dword_5CC9E8;
}

