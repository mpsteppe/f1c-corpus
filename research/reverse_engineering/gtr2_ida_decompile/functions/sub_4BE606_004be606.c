struct _EXCEPTION_REGISTRATION_RECORD *sub_4BE606()
{
  struct _EXCEPTION_REGISTRATION_RECORD *result; // eax
  unsigned int v1; // kr00_4
  __int32 v2; // [esp+0h] [ebp-4h] BYREF

  result = NtCurrentTeb()->NtTib.ExceptionList;
  v1 = __readeflags();
  _InterlockedExchange(&v2, dword_16C6F20 ^ 0x3668016C);
  __writeeflags(v1);
  return result;
}
