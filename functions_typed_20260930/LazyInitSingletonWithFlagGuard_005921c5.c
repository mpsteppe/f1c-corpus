void sub_5921C5()
{
  if ( !dword_8D4078 )
  {
    CriticalSectionLazyInitEnter(11);
    if ( !dword_8D4078 )
    {
      sub_5921F3();
      ++dword_8D4078;
    }
    CritSectLeave(11);
  }
}

