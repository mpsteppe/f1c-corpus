char __thiscall sub_40DD30(int *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = this[34];
  if ( !v2 )
    return 0;
  v3 = *(_DWORD *)(v2 + 4);
  if ( !v3 || !ShortComputation_adb0(v3) )
    return 0;
  v4 = ShortComputation_adb0(*(_DWORD *)(this[34] + 4));
  return RaceCommentaryDirectorSystem(this[34], v4);
}
