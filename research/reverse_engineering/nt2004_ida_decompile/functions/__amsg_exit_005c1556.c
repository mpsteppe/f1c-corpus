void __cdecl __noreturn _amsg_exit(DWORD NumberOfBytesWritten)
{
  if ( dword_7FF164 == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(NumberOfBytesWritten);
  off_625270(255);
}
