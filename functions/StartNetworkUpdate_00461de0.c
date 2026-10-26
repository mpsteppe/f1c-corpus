int __thiscall sub_461DE0(int *this)
{
  int result; // eax

  result = *this;
  if ( *(_DWORD *)(*this + 112540) )
  {
    if ( sub_563E70() )
      SetFlagIfPointerNonNull(*(_DWORD *)(*this + 112540));
    result = DirectDrawDisplayModeInit(*(_DWORD *)(*this + 112540));
    if ( !result )
    {
      if ( dword_7D0E74 == 1 )
      {
        result = InitWrapper(*(_DWORD *)(*this + 112540), 1);
        if ( dword_7C569C != 5 )
        {
          result = StringSplitLoop(1, aDDevF119992002_1, 5776);
          if ( (_BYTE)result )
            return DebugLogWrite(&dword_8AD25C, aStartingIntern);
        }
      }
      else
      {
        result = MultiStageInitializationChainWithErrorChecking(
                   (unsigned __int16)word_7D0FE8,
                   (unsigned __int16)word_7D0FE8 + 99,
                   1);
        if ( dword_7C569C != 5 )
        {
          result = StringSplitLoop(1, aDDevF119992002_1, 5765);
          if ( (_BYTE)result )
            return DebugLogWrite(&dword_8AD25C, aStartingLanUpd);
        }
      }
    }
  }
  return result;
}
