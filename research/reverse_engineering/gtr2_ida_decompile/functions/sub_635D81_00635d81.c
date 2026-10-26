struct _EXCEPTION_REGISTRATION_RECORD **__cdecl sub_635D81(int a1, int a2, int a3)
{
  void *v5; // esp
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-4h] [ebp-4h] BYREF
  int v8; // [esp+8h] [ebp+8h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v5 = alloca(a3);
  v8 = -1;
  return &ExceptionList;
}
