int __usercall TranslatorGuardHandler@<eax>(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        struct EHExceptionRecord *ExceptionRecord,
        PVOID TargetFrame,
        struct _CONTEXT *a4)
{
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    *((_DWORD *)TargetFrame + 9) = 1;
    return 1;
  }
  else
  {
    __InternalCxxFrameHandler(
      ExceptionRecord,
      *((struct EHRegistrationNode **)TargetFrame + 3),
      a4,
      0,
      *((struct _s_FuncInfo **)TargetFrame + 2),
      *((_DWORD *)TargetFrame + 4),
      *((struct EHRegistrationNode **)TargetFrame + 5),
      1);
    if ( !*((_DWORD *)TargetFrame + 9) )
      _UnwindNestedFrames(a1, TargetFrame, (PEXCEPTION_RECORD)ExceptionRecord);
    return (*((int (**)(void))TargetFrame + 6))();
  }
}
