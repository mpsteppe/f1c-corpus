int __thiscall sub_5BA290(const char *this)
{
  int v2; // edi
  _DWORD v4[2]; // [esp+10h] [ebp-8h]

  v4[0] = aQueryid;
  v4[1] = aFinal_0;
  v2 = 0;
  while ( strcmp(this, (const char *)v4[v2]) )
  {
    if ( (unsigned int)++v2 >= 2 )
      return 1;
  }
  return 0;
}
