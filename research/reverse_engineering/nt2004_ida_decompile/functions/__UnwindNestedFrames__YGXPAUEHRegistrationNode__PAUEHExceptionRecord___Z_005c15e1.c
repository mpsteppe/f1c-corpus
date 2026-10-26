void __userpurge _UnwindNestedFrames(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        PVOID TargetFrame,
        PEXCEPTION_RECORD ExceptionRecord)
{
  DWORD ExceptionFlags; // eax

  RtlUnwind(TargetFrame, &_ReturnPoint_16567, ExceptionRecord, 0);
  ExceptionFlags = ExceptionRecord->ExceptionFlags;
  LOBYTE(ExceptionFlags) = ExceptionFlags & 0xFD;
  ExceptionRecord->ExceptionFlags = ExceptionFlags;
  *a1 = NtCurrentTeb()->NtTib.ExceptionList;
}
