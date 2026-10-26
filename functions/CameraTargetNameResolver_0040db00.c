int __thiscall sub_40DB00(int this, int a2)
{
  int result; // eax

  if ( !a2 )
    return 0;
  if ( !sub_588410(aPlayer_1, a2) )
    return ModeDispatchedSubsystemCall(&dword_5EA510);
  if ( !sub_588410(aOriginal, a2) )
    return *(_DWORD *)(this + 140);
  if ( !sub_588410(aLast, a2) )
    return *(_DWORD *)(this + 144);
  if ( !sub_588410(aAnyTrackside, a2) )
    return 0;
  result = sub_588410(aNone, a2);
  if ( result )
    return TracksideCameraTargetLookup(*(_DWORD ***)(this + 4), a2);
  return result;
}
