int __thiscall PitEnterCalledState(F1CPitMachine *this)
{
  int result; // eax

  result = this->status;
  if ( !result || result == 4 )
    return PitStateChangeRequest(this, 1);
  return result;
}

