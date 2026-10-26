void sub_551D30()
{
  int v0; // eax

  v0 = 0;
  if ( dword_757C10 > 0 )
  {
    while ( *(_DWORD *)(*(&dword_91E088 + v0) + 19380) )
    {
      if ( ++v0 >= dword_757C10 )
        return;
    }
    sub_52D900((_DWORD *)(*(&dword_91E088 + v0) + 19272));
  }
}
