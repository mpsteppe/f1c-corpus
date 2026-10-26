LONG (__stdcall *sub_5CE823())(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  LONG (__stdcall *result)(struct _EXCEPTION_POINTERS *); // eax

  result = SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  lpfn = result;
  return result;
}
