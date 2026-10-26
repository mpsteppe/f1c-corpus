int __thiscall sub_598540(char *String, const char *a2, int a3)
{
  char *v3; // esi
  int result; // eax

  v3 = strcpy(String, a2);
  _strupr(v3);
  result = a3;
  *((_DWORD *)v3 + 48) = a3;
  return result;
}
