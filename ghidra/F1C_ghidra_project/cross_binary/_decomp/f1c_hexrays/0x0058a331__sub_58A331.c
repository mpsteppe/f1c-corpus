// f1c  0x0058a331  size=79
struct _EXCEPTION_REGISTRATION_RECORD *__userpurge sub_58A331@<eax>(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        PVOID TargetFrame,
        PEXCEPTION_RECORD ExceptionRecord)
{
  DWORD ExceptionFlags; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *result; // eax

  RtlUnwind(TargetFrame, &loc_58A359, ExceptionRecord, 0);
  ExceptionFlags = ExceptionRecord->ExceptionFlags;
  LOBYTE(ExceptionFlags) = ExceptionFlags & 0xFD;
  ExceptionRecord->ExceptionFlags = ExceptionFlags;
  result = NtCurrentTeb()->NtTib.ExceptionList;
  *a1 = result;
  return result;
}
