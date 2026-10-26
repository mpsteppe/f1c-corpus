void __cdecl _lock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_6253F8 || Stream > &stru_625658 )
    EnterCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
  else
    _lock((((char *)Stream - (char *)&off_6253F8) >> 5) + 28);
}
