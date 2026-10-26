_DWORD *__thiscall sub_47D800(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // esi
  _DWORD *v3; // ebx
  int v4; // esi
  int v5; // esi
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  char *v8; // eax
  char *v9; // [esp-8h] [ebp-11Ch]
  char v10; // [esp+Ch] [ebp-108h] BYREF
  __int16 v11; // [esp+Dh] [ebp-107h]
  char v12; // [esp+Fh] [ebp-105h]
  _DWORD *v13; // [esp+10h] [ebp-104h]
  _BYTE v14[256]; // [esp+14h] [ebp-100h] BYREF

  v11 = 0;
  v12 = 0;
  v13 = this;
  v10 = byte_5EA438[0];
  StateCleanupNotification(this);
  StrlenOverwrite(&v10);
  result = (_DWORD *)SeasonRacesSectionFinder(0);
  if ( result )
  {
    result = StringKeyedLinkedListSearch(result, (int)aPrevyear);
    if ( result )
    {
      result = StringKeyedLinkedListSearch(result, (int)aGrid_1);
      v2 = result;
      if ( result )
      {
        v3 = StringKeyedLinkedListSearch(result, (int)aDrivers_0);
        result = StringKeyedLinkedListSearch(v2, (int)aTimes);
        if ( v3 )
        {
          if ( result )
          {
            v4 = LinkedListCount(result);
            result = (_DWORD *)LinkedListCount(v3);
            if ( result == (_DWORD *)v4 )
            {
              v5 = 0;
              result = (_DWORD *)LinkedListCount(v3);
              if ( (int)result > 0 )
              {
                do
                {
                  v6 = (_DWORD *)NullCheckWrapper(v5);
                  v7 = (_DWORD *)NullCheckWrapper(v5);
                  if ( v6 )
                  {
                    if ( v7 )
                    {
                      v9 = DataEntryAccessor(v7);
                      v8 = DataEntryAccessor(v6);
                      StringFormatWithBufferOverflowCheck(v14, (int)"%s%s%s", v8, &v10, v9);
                    }
                  }
                  UIMenuItemCreator(v13, (int)v14, 0, 0, 0, 0);
                  ++v5;
                  result = (_DWORD *)LinkedListCount(v3);
                }
                while ( v5 < (int)result );
              }
            }
          }
        }
      }
    }
  }
  return result;
}
