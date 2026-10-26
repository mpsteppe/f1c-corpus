int __thiscall sub_47DD10(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // edi
  LPVOID **v5; // ebx
  char v6; // al
  LPVOID *v7; // ebp
  const char *v8; // eax
  int v9; // eax
  char v10; // cl
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // [esp-4h] [ebp-11Ch]
  const char *v23; // [esp-4h] [ebp-11Ch]
  const char *v24; // [esp-4h] [ebp-11Ch]
  const char *v25; // [esp-4h] [ebp-11Ch]
  const char *v26; // [esp-4h] [ebp-11Ch]
  const char *v27; // [esp-4h] [ebp-11Ch]
  char v28; // [esp+10h] [ebp-108h] BYREF
  __int16 v29; // [esp+11h] [ebp-107h]
  char v30; // [esp+13h] [ebp-105h]
  int v31; // [esp+14h] [ebp-104h]
  _BYTE v32[256]; // [esp+18h] [ebp-100h] BYREF

  StateCleanupNotification(this);
  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 17);
  if ( result )
  {
    result = LinkedListIndexedAccessor_f590(result);
    if ( result )
    {
      v31 = *(_DWORD *)(result + 60);
      v3 = v31;
      if ( v31 )
      {
        v4 = this[17];
        v29 = 0;
        v28 = byte_5EA438[0];
        v30 = 0;
        if ( v4 )
        {
          do
          {
            v5 = (LPVOID **)v4;
            v6 = *(_BYTE *)(v4 + 8);
            v4 = *(_DWORD *)(v4 + 4);
            if ( v6 )
            {
              v7 = *v5;
              if ( *v5 )
              {
                if ( *v7 )
                  FreeWrapper_7bcf(*v7);
                FreeWrapper_7bcf(v7);
              }
            }
            FreeWrapper_7bcf(v5);
          }
          while ( v4 );
          v3 = v31;
        }
        this[17] = 0;
        this[18] = 0;
        this[19] = 0;
        this[20] = 0;
        LinkedListInsertWithNodeAllocation(aDriver_2, -1);
        LinkedListInsertWithNodeAllocation(aNationality_0, -1);
        LinkedListInsertWithNodeAllocation(aDateOfBirth, -1);
        LinkedListInsertWithNodeAllocation(aStarts, -1);
        LinkedListInsertWithNodeAllocation(aPolePositions, -1);
        LinkedListInsertWithNodeAllocation(aWins, -1);
        LinkedListInsertWithNodeAllocation(aDriversChampio, -1);
        StrlenOverwrite(&v28);
        StringFormatWithBufferOverflowCheck(v32, "%s", &v28);
        UIMenuItemCreator(v32, 0, 0, 0, 0);
        result = AudioChannelStop(v3 + 188);
        if ( result )
        {
          if ( v3 != -188 )
          {
            v8 = (const char *)UIListIndexedAccessor(0);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v8, &v28, (const char *)(v3 + 188));
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          if ( BinarySearchInStringTable(byte_5EC4C0, aNationality, byte_5EC4CC) )
          {
            v9 = 0;
            do
            {
              v10 = aNationality[v9];
              byte_5EC4CC[v9++] = v10;
            }
            while ( v10 );
          }
          v11 = StringKeyedLinkedListSearch(byte_5EC4CC);
          if ( v11 )
          {
            v22 = (const char *)DataEntryAccessor(v11);
            v12 = (const char *)UIListIndexedAccessor(1);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v12, &v28, v22);
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          v13 = StringKeyedLinkedListSearch(aDateofbirth);
          if ( v13 )
          {
            v23 = (const char *)DataEntryAccessor(v13);
            v14 = (const char *)UIListIndexedAccessor(2);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v14, &v28, v23);
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          v15 = StringKeyedLinkedListSearch(aStarts_0);
          if ( v15 )
          {
            v24 = (const char *)DataEntryAccessor(v15);
            v16 = (const char *)UIListIndexedAccessor(3);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v16, &v28, v24);
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          v17 = StringKeyedLinkedListSearch(aPoles);
          if ( v17 )
          {
            v25 = (const char *)DataEntryAccessor(v17);
            v18 = (const char *)UIListIndexedAccessor(4);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v18, &v28, v25);
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          v19 = StringKeyedLinkedListSearch(aWins_0);
          if ( v19 )
          {
            v26 = (const char *)DataEntryAccessor(v19);
            v20 = (const char *)UIListIndexedAccessor(5);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v20, &v28, v26);
            UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
          result = StringKeyedLinkedListSearch(aDriverschampio);
          if ( result )
          {
            v27 = (const char *)DataEntryAccessor(result);
            v21 = (const char *)UIListIndexedAccessor(6);
            StringFormatWithBufferOverflowCheck(v32, "%s%s%s", v21, &v28, v27);
            return UIMenuItemCreator(v32, 0, 0, 0, 0);
          }
        }
      }
    }
  }
  return result;
}

