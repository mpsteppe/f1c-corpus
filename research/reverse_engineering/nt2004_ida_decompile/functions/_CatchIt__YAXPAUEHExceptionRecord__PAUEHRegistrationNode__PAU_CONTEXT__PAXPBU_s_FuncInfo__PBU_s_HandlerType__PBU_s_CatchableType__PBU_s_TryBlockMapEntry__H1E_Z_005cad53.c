void __cdecl CatchIt(
        struct EHExceptionRecord *ExceptionRecord,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        struct _s_HandlerType *a6,
        const struct _s_CatchableType *a7,
        const struct _s_TryBlockMapEntry *a8,
        int a9,
        PVOID TargetFrame)
{
  void (__stdcall *v10)(void *, struct EHRegistrationNode *); // eax

  if ( a7 )
    BuildCatchObject(ExceptionRecord, a2, a6, a7);
  if ( TargetFrame )
    _UnwindNestedFrames((struct _EXCEPTION_REGISTRATION_RECORD **)a6, TargetFrame, (PEXCEPTION_RECORD)ExceptionRecord);
  else
    _UnwindNestedFrames((struct _EXCEPTION_REGISTRATION_RECORD **)a6, a2, (PEXCEPTION_RECORD)ExceptionRecord);
  __FrameUnwindToState((int)a2, (int)a4, (int)a5, a8->tryLow);
  a2->state = a8->tryHigh + 1;
  v10 = (void (__stdcall *)(void *, struct EHRegistrationNode *))CallCatchBlock(
                                                                   ExceptionRecord,
                                                                   a2,
                                                                   a3,
                                                                   a5,
                                                                   a6->addressOfHandler,
                                                                   a9,
                                                                   0x100u);
  if ( v10 )
    _JumpToContinuation(v10, a2);
}
