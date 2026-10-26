BOOL __thiscall sub_42DB20(_DWORD *this)
{
  *this = 7;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 678) )
    DebugLogWrite(&dword_8AD25C, aEnteredGameExi);
  Sound_Exit(&byte_8AC494);
  SpecialFX_Exit(&dword_8ACEA0);
  EmptyStub_0170(dword_5EA2C0);
  EmptyStub_0170(&unk_7CE24D);
  HWInput_Exit(&ppvOut);
  DynMan_Exit();
  sub_4BA770(&dword_8AB6E4);
  OnScreen_Exit(&dword_7CE048);
  VidMan_Exit(&unk_8AFE18);
  ConditionalObjectCleanup(&dword_7CD25C);
  SessionReset();
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_19, 433) )
    DebugLogWrite(&dword_8AD25C, aEnteredOsmanEx);
  return CloseHandle(hObject);
}

