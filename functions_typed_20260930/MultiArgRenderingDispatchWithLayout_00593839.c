int (*__cdecl sub_593839(
        PEXCEPTION_RECORD ExceptionRecord,
        _DWORD *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int *a8,
        int a9,
        PVOID TargetFrame))(void)
{
  int (*result)(void); // eax

  if ( a7 )
    sub_5939F9(ExceptionRecord, a2, a6, a7);
  if ( TargetFrame )
    SEHUnwindHandler((struct _EXCEPTION_REGISTRATION_RECORD **)a6, TargetFrame, ExceptionRecord);
  else
    SEHUnwindHandler((struct _EXCEPTION_REGISTRATION_RECORD **)a6, a2, ExceptionRecord);
  SEHAwareVirtualCallDispatchLoop((int)a2, a4, a5, *a8);
  a2[2] = a8[1] + 1;
  result = (int (*)(void))SEHWrapperAroundCRTFunctionCall(ExceptionRecord, a2, a3, a5, *(_DWORD *)(a6 + 12), a9, 256);
  if ( result )
    return (int (*)(void))SEHUnwindWithIndirectJump(result, (int)a2);
  return result;
}

