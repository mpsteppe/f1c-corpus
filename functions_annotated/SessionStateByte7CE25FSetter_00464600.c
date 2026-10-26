// ==== CALL-GRAPH CONTEXT (static, from IDB) ====
// Function: SessionStateByte7CE25FSetter  @ 00464600
// Direct callers (1):
//   0042da30  Game_Post
// Direct callees: 4
// Frame-path: NOT_FOUND — no static path from the per-frame tick root. May be reached indirectly (vtable/fnptr) or be init/event-only. Call frequency UNKNOWN — do NOT infer it from function body structure.
// NOTE: direct calls only; indirect (vtable/fnptr) edges not shown.
// ================================================

// SessionStateByte7CE25FSetter: Sets byte_7CE25F = 1 when byte_7CE260 == 0 AND object bytes at +0xC5 or +0xC6 are nonzero. Persistent flag (never cleared here).
char __thiscall SessionStateByte7CE25FSetter(int *this)
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
