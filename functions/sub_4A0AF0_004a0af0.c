int sub_4A0AF0()
{
  int result; // eax
  char *v1; // eax

  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 23);
  if ( result )
  {
    v1 = (char *)ConditionalDispatch_81f0(aGameFilter);
    return SingleFunctionDispatch_6f90(v1);
  }
  return result;
}
