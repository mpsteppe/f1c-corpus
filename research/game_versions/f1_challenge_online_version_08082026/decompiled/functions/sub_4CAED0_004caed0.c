char __thiscall sub_4CAED0(int this, int a2)
{
  int v2; // edi
  int v3; // ebp
  int v4; // eax

  if ( *(_DWORD *)(this + 4) != *(_DWORD *)(a2 + 4) )
    return 0;
  if ( *(float *)(this + 12) != *(float *)(a2 + 12) )
    return 0;
  if ( *(float *)(this + 16) != *(float *)(a2 + 16) )
    return 0;
  if ( *(float *)(this + 20) != *(float *)(a2 + 20) )
    return 0;
  if ( *(float *)(this + 24) != *(float *)(a2 + 24) )
    return 0;
  if ( *(float *)(this + 28) != *(float *)(a2 + 28) )
    return 0;
  if ( *(float *)(this + 32) != *(float *)(a2 + 32) )
    return 0;
  if ( *(float *)(this + 36) != *(float *)(a2 + 36) )
    return 0;
  if ( *(float *)(this + 40) != *(float *)(a2 + 40) )
    return 0;
  if ( *(float *)(this + 44) != *(float *)(a2 + 44) )
    return 0;
  if ( *(float *)(this + 68) != *(float *)(a2 + 68) )
    return 0;
  if ( *(float *)(this + 72) != *(float *)(a2 + 72) )
    return 0;
  if ( *(float *)(this + 76) != *(float *)(a2 + 76) )
    return 0;
  if ( *(float *)(this + 48) != *(float *)(a2 + 48) )
    return 0;
  if ( *(float *)(this + 52) != *(float *)(a2 + 52) )
    return 0;
  if ( *(float *)(this + 56) != *(float *)(a2 + 56) )
    return 0;
  if ( *(float *)(this + 60) != *(float *)(a2 + 60) )
    return 0;
  v2 = *(_DWORD *)(a2 + 80);
  v3 = *(_DWORD *)(this + 80);
  if ( *(_DWORD *)(v3 + 32) != *(_DWORD *)(v2 + 32)
    || strcmp((const char *)(v3 + 56), (const char *)(v2 + 56))
    || *(_DWORD *)(v3 + 88) != *(_DWORD *)(v2 + 88)
    || *(_DWORD *)(v3 + 92) != *(_DWORD *)(v2 + 92)
    || *(_DWORD *)(v3 + 96) != *(_DWORD *)(v2 + 96)
    || *(_DWORD *)(v3 + 100) != *(_DWORD *)(v2 + 100)
    || *(_DWORD *)(v3 + 104) != *(_DWORD *)(v2 + 104)
    || *(_DWORD *)(v3 + 108) != *(_DWORD *)(v2 + 108)
    || strcmp((const char *)(v3 + 112), (const char *)(v2 + 112))
    || strcmp((const char *)(v3 + 144), (const char *)(v2 + 144)) )
  {
    return 0;
  }
  v4 = *(_DWORD *)(a2 + 88);
  if ( v4 > *(_DWORD *)(this + 88) )
    *(_DWORD *)(this + 88) = v4;
  return 1;
}
