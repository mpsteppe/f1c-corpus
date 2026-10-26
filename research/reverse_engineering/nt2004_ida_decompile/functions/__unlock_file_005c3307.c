void __cdecl _unlock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_6253F8 || Stream > &stru_625658 )
    LeaveCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
  else
    _unlock((((char *)Stream - (char *)&off_6253F8) >> 5) + 28);
}
