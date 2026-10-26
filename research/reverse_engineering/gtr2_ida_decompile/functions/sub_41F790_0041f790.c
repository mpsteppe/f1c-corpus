int __cdecl sub_41F790(const char **a1, const char **a2)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = *a2;
  if ( !*a2 )
    v2 = WindowName;
  v3 = *a1;
  if ( !*a1 )
    v3 = WindowName;
  return strcmp(v3, v2);
}
