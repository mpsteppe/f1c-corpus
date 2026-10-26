int __thiscall sub_59F2A0(void *this, int ArgList, _DWORD *a3, unsigned int *a4)
{
  FILE *v5; // eax
  FILE *v6; // esi
  void *v7; // eax
  int v8; // ebp
  const char *v9; // edi
  FILE *v10; // eax
  FILE *v11; // esi
  void *v12; // eax
  int v13; // esi
  int v14; // edi
  char String[768]; // [esp+14h] [ebp-600h] BYREF
  char Buffer[768]; // [esp+314h] [ebp-300h] BYREF

  if ( !a3 )
  {
    sub_591C60((int)this, -1, "Invalid mem file pointer for %s", (const char *)ArgList);
    return -1;
  }
  if ( !a4 )
  {
    sub_591C60((int)this, -1, "Invalid file size for %s", (const char *)ArgList);
    return -1;
  }
  if ( !ArgList )
    return 0;
  if ( strlen((const char *)ArgList) > 0x300 )
    *(_BYTE *)(ArgList + 767) = 0;
  strcpy(String, (const char *)ArgList);
  _strupr(String);
  v5 = fopen(String, aRb);
  v6 = v5;
  if ( v5 )
  {
    fseek(v5, 0, 2);
    *a4 = ftell(v6);
    fseek(v6, 0, 0);
    v7 = operator new(*a4);
    *a3 = v7;
    sub_5BED6F(v7, 1u, *a4, v6);
    fclose(v6);
    return 0;
  }
  v8 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v9 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(Buffer, "%s\\%s", v9, String);
      v10 = fopen(Buffer, aRb);
      v11 = v10;
      if ( v10 )
        break;
      ++v8;
      v9 += 132;
      if ( v8 >= dword_7E8D58 )
        goto LABEL_17;
    }
    fseek(v10, 0, 2);
    *a4 = ftell(v11);
    fseek(v11, 0, 0);
    v12 = operator new(*a4);
    *a3 = v12;
    sub_5BED6F(v12, 1u, *a4, v11);
    fclose(v11);
  }
LABEL_17:
  if ( v8 == dword_7E8D58 )
  {
    v13 = ElementCount;
    v14 = 0;
    if ( ElementCount )
    {
      do
      {
        if ( !sub_5AED80(v13, String, (int)a3, (int)a4) )
          break;
        v13 = *(_DWORD *)(v13 + 304);
        ++v14;
      }
      while ( v13 );
    }
  }
  else
  {
    v14 = -1;
  }
  if ( v14 != dword_7E5D54 )
    return 0;
  sub_591C60((int)this, -2, "Could not locate bitmap file %s", String);
  return -2;
}
