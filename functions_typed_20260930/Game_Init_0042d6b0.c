int __thiscall sub_42D6B0(_DWORD *this)
{
  *this = 3;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 467) )
    DebugLogWrite(&dword_8AD25C, aEnteredGameIni);
  sub_4BA1F0(&dword_8AB6E4);
  if ( VidMan_Init(&unk_8AFE18) )
    return 1;
  SceneExtentComputation(&dword_8AB710);
  sub_4FCAA0(&unk_8AFEC0);
  AIDatabase_Init((float *)dword_5EA2C0);
  EmptyStub_0170(&unk_7CE24D);
  Steward_Init(&dword_8ACEE0);
  HWInput_Init(&ppvOut);
  SpecialFX_Init(&dword_8ACEA0);
  DynMan_Init();
  CamMan_Init((int)&dword_5EA510);
  Sound_Init(&byte_8AC494);
  Render_Init(&byte_8AB678);
  LargeBufferZeroInit(&dword_7CE2F0);
  OnScreen_Init(&dword_7CE048);
  sub_4A1830(&unk_7CE2A4);
  SessionTypeSetter(&dword_7CD25C);
  return 0;
}

