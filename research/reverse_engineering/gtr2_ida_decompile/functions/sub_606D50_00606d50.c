unsigned int __thiscall sub_606D50(char *this, const char *a2)
{
  char *v2; // esi
  char v3; // cl
  unsigned int result; // eax

  v2 = this + 4;
  sub_630FE0(this + 4);
  if ( (int)strlen(a2) <= 31 )
  {
    result = strlen(a2);
    v2[result] = 0;
  }
  else
  {
    result = 31;
    v2[31] = v3;
  }
  return result;
}
