int __usercall TranslatorGuardHandler@<eax>(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        struct EHExceptionRecord *ExceptionRecord,
        PVOID TargetFrame,
        struct _CONTEXT *a4)
{
  int (*v5)(void); // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)TargetFrame + 2) == dword_912B08 )
  {
    if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
    {
      *((_DWORD *)TargetFrame + 9) = 1;
      return 1;
    }
    else
    {
      sub_6365D0(
        ExceptionRecord,
        *((struct EHRegistrationNode **)TargetFrame + 4),
        a4,
        0,
        *((struct _s_FuncInfo **)TargetFrame + 3),
        *((_DWORD *)TargetFrame + 5),
        *((struct EHRegistrationNode **)TargetFrame + 6),
        1u);
      if ( !*((_DWORD *)TargetFrame + 9) )
        _UnwindNestedFrames(a1, TargetFrame, (PEXCEPTION_RECORD)ExceptionRecord);
      _CallSETranslator((struct EHExceptionRecord *)0x123, (struct EHRegistrationNode *)&v5, 0, 0, 0, 0, 0);
      return v5();
    }
  }
  else
  {
    ExceptionRecord->ExceptionFlags |= 8u;
    return 1;
  }
}
