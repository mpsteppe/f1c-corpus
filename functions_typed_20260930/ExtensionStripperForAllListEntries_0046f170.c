int __thiscall ExtensionStripperForAllListEntries(int *this)
{
  int result; // eax
  int v3; // ebp
  char *v4; // eax
  char *v5; // esi
  const char *v6; // edx
  const char *v7; // ecx
  char *v8; // eax
  int i; // [esp+8h] [ebp-Ch]
  LPVOID v10[2]; // [esp+Ch] [ebp-8h] BYREF

  StateCleanupNotification(this);
  result = VirtualPropertyAccessor(dword_7C73E0);
  v3 = 0;
  for ( i = result; v3 < i; ++v3 )
  {
    v10[0] = 0;
    v10[1] = (LPVOID)-1;
    v4 = IndexedEntryAccessor(dword_7C73E0, v3);
    StringCopyWithBufferRealloc((int)v10, v4);
    v5 = (char *)v10[0];
    v6 = (const char *)v10[0];
    if ( !v10[0] )
      v6 = byte_5EA438;
    v7 = &v6[strlen(v6)];
    if ( v7 > v6 )
    {
      while ( *v7 != 46 )
      {
        if ( --v7 <= v6 )
          goto LABEL_9;
      }
      *v7 = 0;
      v5 = (char *)v10[0];
    }
LABEL_9:
    v8 = v5;
    if ( !v5 )
      v8 = byte_5EA438;
    UIMenuItemCreator(this, (int)v8, 0, 0, 0, 0);
    if ( v10[0] )
      FreeWrapper_7bcf(v10[0]);
    result = i;
  }
  return result;
}

