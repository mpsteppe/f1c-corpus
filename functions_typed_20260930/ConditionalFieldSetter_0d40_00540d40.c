void __stdcall sub_540D40(_DWORD *a1, int a2)
{
  if ( a1 )
  {
    if ( (a2 & 4) != 0 )
      a1[8] = BufferLockAllocate(a1[7], a2, a1[11], a1[2]);
    if ( (a2 & 8) != 0 )
      a1[10] = SurfaceBlitLockWithFlagCheck(a1[9], a2, a1[12], a1[4]);
  }
}

