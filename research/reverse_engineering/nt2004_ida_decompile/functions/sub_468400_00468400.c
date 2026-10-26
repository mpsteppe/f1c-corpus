void __cdecl sub_468400()
{
  if ( (byte_764EC8 & 1) == 0 )
  {
    byte_764EC8 |= 1u;
    if ( byte_764EE8 )
    {
      if ( CloseHandle(hMutex) )
        hMutex = 0;
    }
  }
}
