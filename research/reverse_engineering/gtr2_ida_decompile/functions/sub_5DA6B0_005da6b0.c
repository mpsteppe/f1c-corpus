unsigned int __thiscall sub_5DA6B0(char *this, const char *a2)
{
  char *v2; // esi
  char v3; // cl
  unsigned int result; // eax

  v2 = this + 400;
  sub_630FE0(this + 400);
  if ( (int)strlen(a2) <= 63 )
  {
    result = strlen(a2);
    v2[result] = 0;
  }
  else
  {
    result = 63;
    v2[63] = v3;
  }
  return result;
}
