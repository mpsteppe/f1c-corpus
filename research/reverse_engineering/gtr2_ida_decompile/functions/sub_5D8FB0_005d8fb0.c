unsigned int __thiscall sub_5D8FB0(char *this, const char *a2)
{
  char *v2; // esi
  char v3; // cl
  unsigned int result; // eax

  v2 = this + 125;
  sub_630FE0(this + 125);
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
