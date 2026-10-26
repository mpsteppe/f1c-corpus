int _FF_MSGBANNER()
{
  int result; // eax

  result = dword_7FF164;
  if ( dword_7FF164 == 1 || !dword_7FF164 && dword_625274 == 1 )
  {
    _NMSG_WRITE(0xFCu);
    if ( dword_7FF45C )
      dword_7FF45C();
    return _NMSG_WRITE(0xFFu);
  }
  return result;
}
