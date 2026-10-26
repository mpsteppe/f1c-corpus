void __thiscall sub_4ED030(int this)
{
  _DWORD *v2; // edi

  v2 = (_DWORD *)(this + 1764);
  LazyInitCallback((_DWORD *)(this + 1764), this + 3272);
  LazyInitCallback(v2, (int)(v2 + 394));
  StateTransition((_DWORD *)(this + 12992), 0);
  if ( *(_DWORD *)(this + 15712) == 1 )
    *(_DWORD *)(this + 15712) = 0;
  if ( *(float *)(this + 14956) != *(float *)(this + 14968) )
    *(float *)(this + 14956) = (*(float *)(this + 14968) + *(float *)(this + 14956)) * 0.5;
  if ( *(_DWORD *)(this + 3340) && !*(_BYTE *)(this + 3404) )
    *(_DWORD *)(this + 14960) = *(_DWORD *)(this + 14976);
  else
    *(_DWORD *)(this + 14960) = *(_DWORD *)(this + 14972);
  TireBrushModelForceSolver(this, 0);
  if ( !*(_DWORD *)(this + 12988) )
    PhysicsForceVelocityClamping(&dbl_7C7428);
}
