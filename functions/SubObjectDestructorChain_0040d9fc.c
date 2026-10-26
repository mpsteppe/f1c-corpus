// positive sp value has been detected, the output may be wrong!
int __thiscall sub_40D9FC(LPVOID *this)
{
  if ( this[34] )
    FreeWrapper_7bcf(this[34]);
  ((void (__thiscall *)(LPVOID *))LinkedListDestructorWithInnerFree)(this + 19);
  return ConstraintSolverParamInit(this + 5);
}
