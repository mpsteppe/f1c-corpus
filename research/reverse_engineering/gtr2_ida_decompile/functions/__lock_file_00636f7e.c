void __cdecl _lock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_912DD0 || Stream > &stru_913030 )
    EnterCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
  else
    _lock((((char *)Stream - (char *)&off_912DD0) >> 5) + 16);
}
