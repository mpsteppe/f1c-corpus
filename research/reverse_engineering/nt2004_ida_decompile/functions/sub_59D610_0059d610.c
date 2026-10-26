int __thiscall sub_59D610(char *String, const char *a2, int a3)
{
  char *v3; // esi

  v3 = strcpy(String, a2);
  _strupr(v3);
  return -(sub_59D750((int)v3, a3) != 0);
}
