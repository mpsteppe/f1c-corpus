int __thiscall sub_4F6360(int *this, const char *a2)
{
  int v3; // esi
  int i; // edi
  char String[64]; // [esp+Ch] [ebp-40h] BYREF

  strcpy(String, a2);
  _strupr(String);
  v3 = 0;
  if ( this[2] <= 0 )
    return -1;
  for ( i = 0; !sub_4F56E0((const char **)(i + this[3]), String); i += 104 )
  {
    if ( ++v3 >= this[2] )
      return -1;
  }
  return v3;
}
