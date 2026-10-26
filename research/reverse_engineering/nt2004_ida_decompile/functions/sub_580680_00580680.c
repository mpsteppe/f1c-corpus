FILE *__thiscall sub_580680(const char *this)
{
  FILE *result; // eax
  FILE *v3; // esi

  result = fopen(FileName, aA);
  v3 = result;
  if ( result )
  {
    fprintf(result, "%s", this);
    return (FILE *)fclose(v3);
  }
  return result;
}
