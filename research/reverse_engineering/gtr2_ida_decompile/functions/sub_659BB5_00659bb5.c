void sub_659BB5()
{
  while ( InterlockedCompareExchange(&Destination, 1, 0) == 1 )
    Sleep(1u);
  if ( !dword_FB9258 )
    InitializeCriticalSection(&CriticalSection);
  ++dword_FB9258;
  InterlockedExchange(&Destination, 0);
  EnterCriticalSection(&CriticalSection);
}
