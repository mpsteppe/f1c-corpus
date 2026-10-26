unsigned int __thiscall sub_40C650(_DWORD *this, int a2)
{
  int v3; // eax
  unsigned int result; // eax

  if ( a2 == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
  {
    v3 = this[5];
    if ( v3 != -1 )
    {
      GameActionStateMachine(v3, 0);
      this[5] = -1;
    }
  }
  else if ( this[3] <= 2u )
  {
    ConditionalModeDispatchWithGlobalGate(this);
  }
  else
  {
    this[5] = -1;
  }
  if ( this[3] == 3 && *(_BYTE *)(dword_7C54E0 + 13388) )
  {
    if ( a2 == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
      GameActionStateMachine(2, 0);
    else
      GameActionStateMachine(5, 0);
    this[5] = 3;
  }
  result = dword_7C54F0[dword_7C54E4];
  if ( a2 != *(_DWORD *)(result + 18580) )
  {
    result = this[3];
    if ( result <= 2 )
      return ConditionalModeDispatchWithGlobalGate(this);
  }
  return result;
}

