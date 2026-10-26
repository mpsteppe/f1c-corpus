_DWORD *sub_431BC0()
{
  int v0; // eax

  v0 = OperatorNewNhMallocWrapper(64);
  if ( v0 )
    dword_7C73E0[0] = PhysicsBufferAlloc(v0);
  else
    dword_7C73E0[0] = 0;
  return dword_7C73E0;
}
