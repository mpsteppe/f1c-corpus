int __thiscall PitSessionTransition(F1CPitMachine *this)
{
  int status; // eax
  int v2; // eax
  int result; // eax

  status = this->status;
  if ( !status )
    return PitStateChangeRequest(this, 1);
  v2 = status - 1;
  if ( !v2 )
    return PitStateChangeRequest(this, 0);
  result = v2 - 3;
  if ( !result )
    return PitStateChangeRequest(this, 1);
  return result;
}

