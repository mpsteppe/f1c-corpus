char __thiscall sub_40DCD0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax

  v3 = this[34];
  this[33] = 0;
  *this = 1;
  StructFieldInit(v3);
  v4 = AudioChannelStop(a2);
  this[33] = v4;
  if ( !v4 )
    return 0;
  *this = 2;
  if ( (unsigned __int8)CinematicEventStateMachine(this) )
    return 1;
  *this = -1;
  return 0;
}
