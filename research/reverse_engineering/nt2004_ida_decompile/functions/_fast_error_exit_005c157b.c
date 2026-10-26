void __cdecl __noreturn fast_error_exit(DWORD NumberOfBytesWritten)
{
  if ( dword_7FF164 == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(NumberOfBytesWritten);
  ExitProcess(0xFFu);
}
