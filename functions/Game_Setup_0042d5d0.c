int __thiscall sub_42D5D0(_DWORD *this)
{
  *this = 2;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 430) )
    DebugLogWrite(&dword_8AD25C, aEnteredGameSet);
  UtilityFunction_9160(dword_5EC488);
  HWInput_Setup(&ppvOut);
  SimpleZeroInit(&dword_8AB6E4);
  if ( Options_Setup(&unk_7CE24D) )
    return 1;
  SpecialFX_Setup(&dword_8ACEA0);
  Steward_Setup(&dword_8ACEE0);
  DynMan_Setup();
  Sound_Setup(&byte_8AC494);
  OnScreen_Setup(&dword_7CE048);
  sub_4A1830(&unk_7CE2A4);
  VidMan_Setup(&unk_8AFE18);
  if ( PlayerFile_Setup(&byte_7CE498) )
    return 1;
  sub_463EF0(&dword_7CD25C);
  return 0;
}
