std::_Lockit *__thiscall std::_Lockit::_Lockit(std::_Lockit *this)
{
  LONG v2; // eax

  if ( Target == 2 )
    goto LABEL_10;
  if ( !Target )
  {
    v2 = InterlockedExchange(&Target, 1);
    if ( !v2 )
    {
      InitializeCriticalSection(&CriticalSection);
      atexit(loc_5D1A43);
      Target = 2;
LABEL_10:
      EnterCriticalSection(&CriticalSection);
      return this;
    }
    if ( v2 == 2 )
      Target = 2;
  }
  while ( Target == 1 )
    Sleep(1u);
  if ( Target == 2 )
    goto LABEL_10;
  return this;
}
