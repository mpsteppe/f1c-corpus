// SessionStateByte7CE25FSetter: Sets byte_7CE25F = 1 when byte_7CE260 == 0 AND object bytes at +0xC5 or +0xC6 are nonzero. Persistent flag (never cleared here).
char __thiscall sub_464600(int *this)
{
  char result; // al
  int v3; // esi

  result = byte_7CE260;
  if ( !byte_7CE260 )
  {
    TrackConfigurationNameBuilder(&byte_7CE498);
    if ( *(_DWORD *)(*this + 16324) )
    {
      ShortComputation_3140(this);
      GuardedInitCall((_BYTE *)(*this + 112528));
    }
    SingleFunctionCallWrapper_a910(*(_DWORD *)(*this + 16312));
    v3 = *this;
    result = *(_BYTE *)(v3 + 197);
    if ( result || (result = *(_BYTE *)(v3 + 198)) != 0 )
      byte_7CE25F = 1;
  }
  return result;
}

