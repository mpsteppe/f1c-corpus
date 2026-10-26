char sub_5246E0()
{
  char *v0; // esi
  char v1; // bl
  char *Str1; // [esp+4h] [ebp-18h]

  sub_523690();
  v0 = Str1;
  if ( !Str1 )
    v0 = (char *)WindowName;
  if ( !strncmp(v0, Str2, 2u) )
  {
    sub_614A60(v0);
    v1 = 1;
  }
  else
  {
    v1 = sub_617680(v0);
  }
  if ( Str1 )
    j_j__free(Str1);
  return v1;
}
