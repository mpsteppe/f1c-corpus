// f1c  0x00546330  size=49
int __thiscall sub_546330(char *lpSrcStr, const char *a2, int a3)
{
  char *v3; // esi
  int result; // eax

  v3 = strcpy(lpSrcStr, a2);
  sub_589901(v3);
  result = a3;
  *((_DWORD *)v3 + 46) = a3;
  return result;
}
