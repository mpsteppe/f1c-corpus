// f1c  0x004a0af0  size=45
int sub_4A0AF0()
{
  int result; // eax
  char *v1; // eax

  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 23);
  if ( result )
  {
    v1 = (char *)sub_5681F0(aGameFilter);
    return sub_476F90(v1);
  }
  return result;
}
