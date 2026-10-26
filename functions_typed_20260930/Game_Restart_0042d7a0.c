int __thiscall sub_42D7A0(_DWORD *this)
{
  *this = 4;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 509) )
    DebugLogWrite(&dword_8AD25C, aEnteredGameRes);
  SynchronizeWithServer(&dword_7CD25C);
  Sound_Restart(&byte_8AC494);
  ArrayZeroInit(&dword_7CE2F0);
  GlobalZeroInit(&unk_7CE24D);
  Steward_Restart(&dword_8ACEE0);
  sub_4FCC30(&unk_8AFEC0);
  SurfaceHeightfieldCollisionCallback((int)dword_5EA2C0);
  SpecialFX_Restart(&dword_8ACEA0);
  HWInput_Restart(&ppvOut);
  DynMan_Restart();
  CamMan_Restart((int)&dword_5EA510);
  Render_Restart(&byte_8AB678);
  OnScreen_Restart(&dword_7CE048);
  sub_4BA460(&dword_8AB6E4);
  VidMan_Restart(&unk_8AFE18);
  sub_4A1830(&unk_7CE2A4);
  PlayerFile_Restart(&byte_7CE498);
  HUDDisplayDataReset(dword_5EB978);
  sub_4D7B00(&dword_8AD264);
  return 0;
}

