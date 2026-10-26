int __usercall sub_6365D0@<eax>(
        int a1@<ebx>,
        struct EHExceptionRecord *a2,
        struct EHRegistrationNode *a3,
        struct EHRegistrationNode *a4,
        struct _CONTEXT *a5,
        struct _s_TryBlockMapEntry *a6,
        struct _s_FuncInfo *a7,
        struct EHRegistrationNode *a8,
        unsigned __int8 a9)
{
  int (__cdecl *pForwardCompat)(); // ecx

  if ( (dword_16C99D8 & a6->tryLow) != 0x19930520 )
    sub_635D4C();
  if ( (a2->ExceptionFlags & 0x66) != 0 )
  {
    if ( a6->tryHigh )
    {
      if ( !a7 )
        __FrameUnwindToState(a3, a5, a6, -1);
    }
  }
  else if ( a6->nCatches )
  {
    if ( a2->ExceptionCode == -529697949 && a2->params.magicNumber > 0x19930520 )
    {
      pForwardCompat = a2->params.pThrowInfo->pForwardCompat;
      if ( pForwardCompat )
        return ((int (__cdecl *)(struct EHExceptionRecord *, struct EHRegistrationNode *, struct EHRegistrationNode *, struct _CONTEXT *, struct _s_TryBlockMapEntry *, struct _s_FuncInfo *, struct EHRegistrationNode *, _DWORD))pForwardCompat)(
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9);
    }
    FindHandler(a1, 429065504, a6, a2, a3, a4, a5, (struct _s_FuncInfo *)a6, a9, a7, a8);
  }
  return 1;
}
