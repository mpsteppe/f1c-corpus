char *__thiscall sub_644450(void **this, const char *a2, const char *a3)
{
  char *v4; // eax
  char *result; // eax

  v4 = (char *)realloc(this[1], strlen(a2) + 1);
  this[1] = v4;
  strcpy(v4, a2);
  result = (char *)realloc(this[2], strlen(a3) + 1);
  this[2] = result;
  strcpy(result, a3);
  return result;
}
