unsigned int _FF_MSGBANNER()
{
  unsigned int result; // eax

  result = dword_FB81E0;
  if ( dword_FB81E0 == 1 || !dword_FB81E0 && dword_912B04 == 1 )
  {
    _NMSG_WRITE(0xFCu);
    if ( dword_FB8504 )
      dword_FB8504();
    return _NMSG_WRITE(0xFFu);
  }
  return result;
}
