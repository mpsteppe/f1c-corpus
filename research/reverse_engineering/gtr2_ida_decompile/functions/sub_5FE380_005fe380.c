char *__thiscall sub_5FE380(char *this, const char *a2)
{
  char *v2; // edi
  char v3; // cl

  v2 = this + 8;
  sub_630FE0(this + 8);
  if ( (int)strlen(a2) <= 31 )
    v2[strlen(a2)] = 0;
  else
    v2[31] = v3;
  return _strupr(v2);
}
