int __thiscall sub_40D450(_DWORD *this)
{
  int result; // eax

  if ( this[5] == 3 )
  {
    this[5] = -1;
    return GameActionStateMachine(this, 3, 0);
  }
  return result;
}

