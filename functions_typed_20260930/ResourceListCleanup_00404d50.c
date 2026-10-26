char __thiscall sub_404D50(void *this, char a2)
{
  char result; // al
  bool v3; // zf
  int *v4; // ebx
  int v5; // esi
  LPVOID **v6; // ebp
  char v7; // al
  LPVOID *v8; // edi
  char *v9; // eax
  const char *i; // edx

  result = a2;
  v3 = a2 == 0;
  *(_BYTE *)(*(_DWORD *)this + 36) = a2;
  if ( !v3 )
  {
    v4 = (int *)(*(_DWORD *)this + 64);
    v5 = *v4;
    while ( v5 )
    {
      v6 = (LPVOID **)v5;
      v7 = *(_BYTE *)(v5 + 8);
      v5 = *(_DWORD *)(v5 + 4);
      if ( v7 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          if ( *v8 )
            FreeWrapper_7bcf(*v8);
          FreeWrapper_7bcf(v8);
        }
      }
      FreeWrapper_7bcf(v6);
    }
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    AllocateStructWithDefaultValues(&a2);
    v9 = (char *)lpPathName;
    if ( !lpPathName )
      v9 = &byte_5EA438;
    sub_565F80(FileName, 1, (int)v9, 0);
    LinkedListPopFront_5f50(&a2);
    for ( i = (const char *)DirectoryEntryIterator(&a2); i; i = (const char *)DirectoryEntryIterator(&a2) )
    {
      if ( strlen(i) )
        LinkedListNodeInsertion(i);
      if ( !(unsigned __int8)LinkedListNodePeek(&a2) )
        break;
    }
    return LinkedListDestructorWithChildCleanup(&a2);
  }
  return result;
}

