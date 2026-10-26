int __thiscall sub_42DA30(_DWORD *this)
{
  int result; // eax

  *this = 6;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 645) )
    DebugLogWrite(&dword_8AD25C, aEnteredGamePos);
  GuardedDispatchWithStateCheck(&dword_8AB6E4);
  F_65xNestedCallLoop(&dword_8AB710);
  Sound_Post(&byte_8AC494);
  TwoCallDelegation_d6d0(&unk_8AFEC0);
  SpecialFX_Post(&dword_8ACEA0);
  ShortComputation_45f0((int)dword_5EA2C0);
  GlobalFlagClear(&unk_7CE24D);
  Steward_Post(&dword_8ACEE0);
  HWInput_Post(&ppvOut);
  DynMan_Post();
  CamMan_Post((int)&dword_5EA510);
  Render_Post(&byte_8AB678);
  OnScreen_Post(&dword_7CE048);
  VidMan_Post(&unk_8AFE18);
  sub_4A1830(&unk_7CE2A4);
  PlayerFile_Post(&byte_7CE498);
  result = SessionStateByte7CE25FSetter(&dword_7CD25C);
  dword_7C56A0 = 3;
  return result;
}
