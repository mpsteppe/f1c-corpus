unsigned int __thiscall sub_5D8F50(char *this, const char *a2)
{
  char *v2; // esi
  char v3; // cl
  unsigned int result; // eax

  v2 = this + 381;
  sub_630FE0(this + 381);
  if ( (int)strlen(a2) <= 255 )
  {
    result = strlen(a2);
    v2[result] = 0;
  }
  else
  {
    result = 255;
    v2[255] = v3;
  }
  return result;
}
