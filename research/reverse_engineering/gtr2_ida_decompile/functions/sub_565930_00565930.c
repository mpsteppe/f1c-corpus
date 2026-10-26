char __thiscall sub_565930(int this)
{
  int v1; // eax

  if ( *(float *)(this + 20) < 0.0 )
    return 0;
  v1 = *(_DWORD *)(this + 28);
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(this + 24) )
  {
    if ( v1 == *((_DWORD *)dword_91E07C + 4874) )
      return 1;
  }
  else if ( v1 == *((_DWORD *)dword_91E07C + 4875) )
  {
    return 1;
  }
  return 0;
}
