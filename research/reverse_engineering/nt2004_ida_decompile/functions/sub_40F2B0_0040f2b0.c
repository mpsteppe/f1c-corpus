int *__thiscall sub_40F2B0(int this)
{
  int *result; // eax
  int v3; // edi
  int v4; // eax

  result = *(int **)(this + 28);
  if ( result )
  {
    v3 = *result;
    v4 = sub_40EBD0((const char **)this);
    return (int *)(*(int (__thiscall **)(_DWORD, int))(v3 + 184))(*(_DWORD *)(this + 28), v4);
  }
  return result;
}
