int __thiscall sub_46BA20(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // ebx
  int i; // eax
  const char *v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // [esp+10h] [ebp-54h]
  char v14; // [esp+14h] [ebp-50h] BYREF
  int v15; // [esp+15h] [ebp-4Fh]
  int v16; // [esp+19h] [ebp-4Bh]
  int v17; // [esp+1Dh] [ebp-47h]
  __int16 v18; // [esp+21h] [ebp-43h]
  char v19; // [esp+23h] [ebp-41h]
  char v20[61]; // [esp+24h] [ebp-40h] BYREF
  __int16 v21; // [esp+61h] [ebp-3h]
  char v22; // [esp+63h] [ebp-1h]
  int v23; // [esp+68h] [ebp+4h]

  v20[0] = byte_5EA438[0];
  memset(&v20[1], 0, 0x3Cu);
  v21 = 0;
  v22 = 0;
  if ( a2 )
  {
LABEL_16:
    StateCleanupNotification(this);
    v8 = dword_5C329C;
    v9 = 0;
    result = 0;
    do
    {
      v10 = 0;
      if ( v8 <= 0 )
        break;
      v11 = result + 1;
      while ( 1 )
      {
        result = dword_7C54F0[v10];
        if ( *(_DWORD *)(result + 16480) == v11 )
          break;
        if ( ++v10 >= v8 )
          return result;
      }
      if ( *(_DWORD *)(dword_7C54F0[v10] + 13000) != -1 )
      {
        FTIMTimerBitmapSelector(this, v10, byte_7CD718, v20);
        v12 = dword_7C54F0[v10];
        v15 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v14 = byte_5EA438[0];
        StringFormatWithBufferOverflowCheck(&v14, "%d", *(_DWORD *)(v12 + 18580));
        UIMenuItemCreator(byte_7CD718, 0, 0, &v14, 0);
        UIItemNameSetter(v9, v20);
        v8 = dword_5C329C;
        ++v9;
      }
      result = v11;
    }
    while ( v11 < 104 );
  }
  else
  {
    v3 = dword_5C329C;
    v23 = dword_5C329C;
    v4 = 0;
    while ( 1 )
    {
      for ( i = 0; i < v3; ++i )
      {
        if ( *(_DWORD *)(dword_7C54F0[i] + 16480) - 1 == v4 )
          break;
      }
      if ( i >= v23 || *(_DWORD *)(dword_7C54F0[i] + 13000) == -1 )
      {
        result = UIListItemByIndex(v4);
      }
      else
      {
        FTIMTimerBitmapSelector(this, i, byte_7CD718, v20);
        v6 = (const char *)UIListItemByIndex(v4);
        v13 = UIItemTextAccessor(v4);
        if ( !v6 || strcmp(v6, byte_7CD718) )
          goto LABEL_16;
        result = sub_588410(v20, v13);
      }
      if ( result )
        goto LABEL_16;
      if ( ++v4 >= 104 )
        break;
      v3 = dword_5C329C;
    }
  }
  return result;
}

