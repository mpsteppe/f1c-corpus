// ==== CALL-GRAPH CONTEXT (static, from IDB) ====
// Function: AIStateMachineWithModeDispatch  @ 004a5d10
// Direct callers (2):
//   004a5c80  StateChangeNotify
//   004b3400  sub_4B3400
// Direct callees: 9
// Frame-path: ON_FRAME_PATH — statically reachable from MainGameTickUpdate (per-frame tick trunk). Fields this function writes are refreshed regularly; an external poke to them will NOT persist.
// NOTE: direct calls only; indirect (vtable/fnptr) edges not shown.
// ================================================

// AIStateMachineWithModeDispatch: Calls sub_4A5EA0 (PitsUnderRed) when (*this)[3250] (+0x32C8) == 2||3 AND this[97] == 2. Plus dispatch to steering/physics per AI mode.
int __thiscall sub_4A5D10(float *this, int a2)
{
  int v2; // eax
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  int result; // eax
  _DWORD *v8; // ecx
  char v9; // al
  _DWORD *v10; // ecx
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  _BYTE v13[12]; // [esp+8h] [ebp-18h] BYREF
  _DWORD v14[3]; // [esp+14h] [ebp-Ch] BYREF

  v2 = *(char *)(a2 + 8);
  if ( *((_DWORD *)this + 97) != v2 )
  {
    *((_DWORD *)this + 97) = v2;
    AIPitStrategyState(*(_DWORD **)this);
  }
  v4 = *(_DWORD **)this;
  this[98] = *(float *)(a2 + 4);
  v5 = v4[3250];
  if ( v5 == 2 || v5 == 3 )
  {
    v6 = *((_DWORD *)this + 97);
    if ( v6 )
    {
      if ( v6 == 2 )
        sub_4A5EA0(this);
    }
    else
    {
      sub_4A5F20(this);
    }
  }
  ConditionalDispatch_55e0(this);
  result = *((_DWORD *)this + 97);
  if ( result )
  {
    if ( result == 1 || result == 2 )
    {
      v9 = VehicleControlEnabled(this);
      v10 = (_DWORD *)*((_DWORD *)this + 2);
      if ( v10 )
        sub_4A3390(v10, v9 == 0);
      result = ConditionalDelegateDispatch(*(_DWORD *)this, v14, v13);
      v11 = (_DWORD *)*((_DWORD *)this + 4);
      if ( v11 )
        result = sub_4A3320(v11, v14, (int)v13);
      v12 = (_DWORD *)*((_DWORD *)this + 3);
      if ( v12 )
        return sub_4A3320(v12, v14, (int)v13);
    }
  }
  else
  {
    v8 = (_DWORD *)*((_DWORD *)this + 2);
    if ( v8 )
      return FlagBasedLoopConditionalCall(v8);
  }
  return result;
}
