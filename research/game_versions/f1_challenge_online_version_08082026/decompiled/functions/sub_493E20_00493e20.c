int __thiscall sub_493E20(_DWORD *this, const char *a2)
{
  _DWORD *v2; // ebx
  const char *v3; // esi
  int v4; // edx
  int v6; // ebx
  __int16 *v7; // edi
  int v8; // eax
  char v10[256]; // [esp+14h] [ebp-100h] BYREF

  v2 = this;
  v3 = a2;
  v4 = 4 * this[101];
  memset(v10, 0, sizeof(v10));
  if ( !a2 )
    return -1;
  if ( !strlen(a2) )
    return -1;
  if ( v4 > 0 )
  {
    v6 = v4;
    do
    {
      v7 = &word_5C406C;
      if ( v4 > 4 )
        v7 = &word_5C32D8;
      strcat(v10, (const char *)v7);
      --v6;
    }
    while ( v6 );
    v3 = a2;
    v2 = this;
  }
  strcat(v10, v3);
  *(_WORD *)&v10[strlen(v10)] = word_5C30B4;
  if ( *((_BYTE *)v2 + 410) )
  {
    v8 = v2[1];
    if ( v8 )
      sub_5887B1(v8, aS_4);
  }
  return 0;
}
