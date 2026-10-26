void __tzset()
{
  if ( !dword_7FF328 )
  {
    _lock(11);
    if ( !dword_7FF328 )
    {
      _tzset_lk();
      ++dword_7FF328;
    }
    _unlock(11);
  }
}
