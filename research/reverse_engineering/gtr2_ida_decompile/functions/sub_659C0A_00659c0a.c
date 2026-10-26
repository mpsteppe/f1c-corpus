LONG sub_659C0A()
{
  LeaveCriticalSection(&CriticalSection);
  while ( InterlockedCompareExchange(&Destination, 1, 0) == 1 )
    Sleep(1u);
  if ( !--dword_FB9258 )
    DeleteCriticalSection(&CriticalSection);
  return InterlockedExchange(&Destination, 0);
}
