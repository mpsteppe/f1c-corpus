void *__fastcall sub_418840(char *FileName, size_t *a2)
{
  void *v3; // edi
  FILE *v4; // eax
  FILE *v5; // esi
  signed int v6; // eax
  size_t v7; // ebx

  v3 = 0;
  v4 = fopen(FileName, aRb);
  v5 = v4;
  if ( v4 )
  {
    fseek(v4, 0, 2);
    v6 = ftell(v5);
    v7 = v6;
    if ( v6 > 0 )
    {
      v3 = operator new(v6);
      fseek(v5, 0, 0);
      if ( sub_5BED6F(v3, v7, 1u, v5) <= 0 )
      {
        sub_5BE8AE(v3);
        v3 = 0;
      }
      if ( a2 )
        *a2 = v7;
    }
    fclose(v5);
  }
  return v3;
}
