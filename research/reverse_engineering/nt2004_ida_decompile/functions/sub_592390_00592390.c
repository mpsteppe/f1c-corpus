int __thiscall sub_592390(void *this, int ArgList)
{
  FILE *v3; // eax
  int v5; // edi
  const char *v6; // esi
  FILE *v7; // eax
  size_t v8; // esi
  int i; // edi
  char String[768]; // [esp+Ch] [ebp-600h] BYREF
  char Buffer[768]; // [esp+30Ch] [ebp-300h] BYREF

  if ( !ArgList )
    return 0;
  if ( strlen((const char *)ArgList) > 0x300 )
    *(_BYTE *)(ArgList + 767) = 0;
  strcpy(String, (const char *)ArgList);
  _strupr(String);
  v3 = fopen(String, aRb);
  if ( v3 )
  {
    fclose(v3);
    return 0;
  }
  v5 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v6 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(Buffer, "%s\\%s", v6, String);
      v7 = fopen(Buffer, aRb);
      if ( v7 )
        break;
      ++v5;
      v6 += 132;
      if ( v5 >= dword_7E8D58 )
        goto LABEL_13;
    }
    fclose(v7);
  }
LABEL_13:
  if ( v5 == dword_7E8D58 )
  {
    v8 = ElementCount;
    for ( i = 0; v8; ++i )
    {
      if ( !sub_5AF100((char *)ArgList) )
        break;
      v8 = *(_DWORD *)(v8 + 304);
    }
  }
  else
  {
    i = -1;
  }
  if ( i != dword_7E5D54 )
    return 0;
  sub_591C60((int)this, -2, "Could not locate bitmap %s", (const char *)ArgList);
  return -2;
}
