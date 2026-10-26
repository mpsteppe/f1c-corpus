int __thiscall sub_455BF0(char *this)
{
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5205) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput);
  sub_44F4E0();
  while ( ShowCursor(0) >= 0 )
    ;
  InputActionRegistration();
  if ( byte_7D13A0 == 1 )
    DualSourceAcquireWithFallback(this + 6928);
  return 0;
}

