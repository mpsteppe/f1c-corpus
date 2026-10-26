enum _EXCEPTION_DISPOSITION __cdecl CatchGuardHandler(
        struct EHExceptionRecord *a1,
        struct CatchGuardRN *a2,
        struct _CONTEXT *a3)
{
  return __InternalCxxFrameHandler(
           a1,
           *((struct EHRegistrationNode **)a2 + 3),
           a3,
           0,
           *((struct _s_FuncInfo **)a2 + 2),
           *((_DWORD *)a2 + 4),
           (struct EHRegistrationNode *)a2,
           0);
}
