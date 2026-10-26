void __thiscall sub_426330(int this)
{
  int v1; // edx
  int v2; // eax

  if ( *(float *)(this + 14864) > 0.0 )
    return;
  v1 = *(_DWORD *)(this + 14844);
  if ( *(_DWORD *)(this + 17680) == 6 )
  {
    if ( v1 != -1 )
      RaceStartCountdownStateUpdate(-1);
    return;
  }
  if ( *(_DWORD *)(this + 15724) == 2 )
  {
    RaceStartCountdownStateUpdate(0);
    return;
  }
  if ( !v1 || v1 == -1 )
    goto LABEL_12;
  if ( *(float *)(this + 14872) < (double)*(float *)(this + 14752) )
  {
    if ( *(float *)(this + 14284) <= 0.80000001 || *(float *)(this + 14532) <= 0.80000001 )
      return;
LABEL_12:
    v2 = *(_DWORD *)(this + 14844);
    if ( v2 < *(_DWORD *)(this + 14852) )
      RaceStartCountdownStateUpdate(v2 + 1);
    return;
  }
  if ( v1 > 1 )
    JUMPOUT(0x4F62E6);
}

