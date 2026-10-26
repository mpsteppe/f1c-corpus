int _mtterm()
{
  if ( dword_912CA0 != -1 )
  {
    dword_FB81F4(dword_912CA0);
    dword_912CA0 = -1;
  }
  return _mtdeletelocks();
}
