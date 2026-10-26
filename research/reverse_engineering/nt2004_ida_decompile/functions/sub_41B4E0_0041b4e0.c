void __stdcall sub_41B4E0(const char *a1)
{
  if ( dword_7688A0 && flt_7678BC != 0.0 && byte_6292D8 && sub_4633A0(&unk_764D70) != 1 )
  {
    if ( !strcmp(a1, aDangerousDrivi) )
    {
      sub_4195D0(8, 1);
    }
    else if ( strcmp(a1, aRidingWall)
           && strcmp(a1, aJumpedStart)
           && strcmp(a1, aIgnoredStopGoP)
           && !strcmp(a1, aSpeedingInPitl) )
    {
      sub_4195D0(16, 1);
    }
  }
}
