int __cdecl __InternalCxxFrameHandler(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        void *a4,
        struct _s_FuncInfo *a5,
        int a6,
        struct EHRegistrationNode *a7,
        unsigned __int8 a8)
{
  int (__cdecl *pForwardCompat)(); // ecx

  if ( *(_DWORD *)a5 != 429065504 )
    sub_5CB21D();
  if ( (a1->ExceptionFlags & 0x66) != 0 )
  {
    if ( a5->maxState )
    {
      if ( !a6 )
        __FrameUnwindToState(a2, a4, a5, -1);
    }
  }
  else if ( a5->nTryBlocks )
  {
    if ( a1->ExceptionCode == -529697949 && a1->params.magicNumber > 0x19930520 )
    {
      pForwardCompat = a1->params.pThrowInfo->pForwardCompat;
      if ( pForwardCompat )
        return ((int (__cdecl *)(struct EHExceptionRecord *, struct EHRegistrationNode *, struct _CONTEXT *, void *, struct _s_FuncInfo *, int, struct EHRegistrationNode *, _DWORD))pForwardCompat)(
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8);
    }
    FindHandler(a1, a2, a3, a4, a5, a8, a6, a7);
  }
  return 1;
}
