int __usercall sub_58A4E5@<eax>(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        PEXCEPTION_RECORD ExceptionRecord,
        _DWORD *TargetFrame,
        int a4)
{
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    TargetFrame[9] = 1;
    return 1;
  }
  else
  {
    sub_593446(ExceptionRecord, TargetFrame[3], a4, 0, TargetFrame[2], TargetFrame[4], TargetFrame[5], 1);
    if ( !TargetFrame[9] )
      sub_58A331(a1, TargetFrame, ExceptionRecord);
    return ((int (*)(void))TargetFrame[6])();
  }
}
