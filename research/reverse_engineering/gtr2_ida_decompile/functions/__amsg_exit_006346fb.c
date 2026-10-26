void __cdecl __noreturn _amsg_exit(DWORD NumberOfBytesWritten)
{
  if ( dword_FB81E0 == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(NumberOfBytesWritten);
  off_912B00(255);
}
