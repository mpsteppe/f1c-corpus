int __thiscall sub_682468(void **this, const char *a2)
{
  char *v2; // ebx
  unsigned int v3; // kr00_4

  v2 = 0;
  if ( a2 )
  {
    v3 = strlen(a2);
    v2 = (char *)operator new(v3 + 1);
    if ( !v2 )
      return -2147024882;
    qmemcpy(v2, a2, v3 + 1);
  }
  j__free(this[52]);
  this[52] = v2;
  return 0;
}
