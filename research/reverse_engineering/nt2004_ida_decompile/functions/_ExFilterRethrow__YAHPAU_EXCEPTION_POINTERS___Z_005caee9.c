BOOL __cdecl ExFilterRethrow(struct _EXCEPTION_POINTERS *a1)
{
  PEXCEPTION_RECORD ExceptionRecord; // eax

  ExceptionRecord = a1->ExceptionRecord;
  return a1->ExceptionRecord->ExceptionCode == -529697949
      && ExceptionRecord->NumberParameters == 3
      && ExceptionRecord->ExceptionInformation[0] == 429065504
      && !ExceptionRecord->ExceptionInformation[2];
}
