// f1c  0x0059a54d  size=156
void *__thiscall sub_59A54D(void *this)
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
      sub_587B3E((int)&loc_59A5CB);
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
