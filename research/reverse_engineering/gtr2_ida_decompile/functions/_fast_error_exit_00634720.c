void __cdecl __noreturn fast_error_exit(DWORD NumberOfBytesWritten)
{
  if ( dword_FB81E0 == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(NumberOfBytesWritten);
  __crtExitProcess(0xFFu);
}
