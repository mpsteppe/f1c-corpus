// f1c  0x00477640  size=58
int sub_477640()
{
  int result; // eax
  char **v1; // esi
  char *v2; // eax

  result = sub_48F590();
  if ( result )
  {
    v1 = *(char ***)(result + 60);
    if ( v1 )
    {
      v2 = *v1;
      if ( !*v1 )
        v2 = byte_5EA438;
      sub_566650(v2);
      return sub_566650(v1 + 47);
    }
  }
  return result;
}
