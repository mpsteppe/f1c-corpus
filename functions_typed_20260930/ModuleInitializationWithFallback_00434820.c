int __thiscall sub_434820(_DWORD *this)
{
  ConstraintSolverParamInit(this);
  this[2] = VirtualDispatchHelper(&dword_5EA510);
  if ( sub_4348B0(this) )
    return 1;
  GameActionStateMachine(&dword_5EA510, 5, 1);
  *(_BYTE *)this = 1;
  return 0;
}

