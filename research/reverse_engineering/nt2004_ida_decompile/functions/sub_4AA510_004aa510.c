int __thiscall sub_4AA510(_DWORD *this, const char *a2)
{
  _DWORD *v2; // ebx
  const char *v3; // esi
  int v4; // edx
  int v6; // ebx
  const char *v7; // edi
  char ArgList[256]; // [esp+14h] [ebp-100h] BYREF

  v2 = this;
  v3 = a2;
  v4 = 4 * this[119];
  memset(ArgList, 0, sizeof(ArgList));
  if ( !a2 )
    return -1;
  if ( !strlen(a2) )
    return -1;
  if ( v4 > 0 )
  {
    v6 = v4;
    do
    {
      v7 = asc_5FE194;
      if ( v4 > 4 )
        v7 = word_5FBEBC;
      strcat(ArgList, v7);
      --v6;
    }
    while ( v6 );
    v3 = a2;
    v2 = this;
  }
  strcat(ArgList, v3);
  *(_WORD *)&ArgList[strlen(ArgList)] = *(_WORD *)asc_5FB9D8;
  if ( *((_BYTE *)v2 + 482) )
  {
    if ( v2[7] )
      sub_57A400((int)(v2 + 7), aS_0, (char)ArgList);
  }
  return 0;
}
