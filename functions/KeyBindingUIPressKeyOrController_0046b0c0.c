char __thiscall sub_46B0C0(int this, char a2, int a3)
{
  int v4; // ebx
  int v5; // eax
  const char *v6; // esi
  bool v7; // zf
  int v8; // eax
  char v9; // cl
  int v10; // ecx
  int v12; // [esp-4h] [ebp-6Ch]
  int v13; // [esp+10h] [ebp-58h] BYREF
  int v14; // [esp+14h] [ebp-54h]
  char v15[77]; // [esp+18h] [ebp-50h] BYREF
  __int16 v16; // [esp+65h] [ebp-3h]
  char v17; // [esp+67h] [ebp-1h]

  v4 = FieldGetter();
  LOBYTE(v5) = a2;
  if ( a2 )
    *(_DWORD *)(this + 508) = 1;
  if ( v4 >= 0 && v4 < dword_7D1424 )
  {
    v5 = (int)ArrayIndexedAccessor(&ppvOut, v4);
    v6 = (const char *)v5;
    if ( v5 )
    {
      v15[0] = byte_5EA438[0];
      memset(&v15[1], 0, 0x4Cu);
      v16 = 0;
      v17 = 0;
      if ( *(_DWORD *)(this + 508) == 1 )
      {
        v10 = *(_DWORD *)(this + 64);
        *(_DWORD *)(this + 500) = v4;
        *(_DWORD *)(this + 504) = BitmapSpriteAccessor(v10);
        LookupDispatch(aPopupControlSe, -1);
        *(_BYTE *)(*(_DWORD *)(this + 64) + 5513) = 0;
        BinarySearchInStringTable(byte_5EC4C0, aPressKeyOrCont, (char *)(this + 372));
        *(_WORD *)(this + 372 + strlen((const char *)(this + 372))) = word_5C32D8;
        if ( BinarySearchInStringTable(byte_5EC4C0, v6, byte_5EC4CC) )
          strcpy(byte_5EC4CC, v6);
        LOBYTE(v5) = 0;
        strcat((char *)(this + 372), byte_5EC4CC);
        *(_DWORD *)(this + 520) = 1;
        *(_DWORD *)(this + 508) = 2;
      }
      else if ( *(_DWORD *)(this + 508) == 2 )
      {
        v12 = *(_DWORD *)(this + 520);
        v13 = 0;
        v14 = 89;
        LOBYTE(v5) = ParameterLookupWithFallback(&ppvOut, v15, &v13, v12);
        *(_DWORD *)(this + 520) = 0;
        if ( (_BYTE)v5 )
        {
          v7 = v13 == 0;
          v5 = v14;
          *(_DWORD *)(this + 508) = 3;
          if ( v7 )
          {
            v5 = EnumToIDMappingWithDefaultFallthrough(v5);
            if ( v5 != 89 )
            {
              if ( v5 >= 0 )
              {
                v5 = v14;
              }
              else
              {
                if ( BinarySearchInStringTable(byte_5EC4C0, aReservedKey, byte_5EC4CC) )
                {
                  v8 = 0;
                  do
                  {
                    v9 = aReservedKey[v8];
                    byte_5EC4CC[v8++] = v9;
                  }
                  while ( v9 );
                }
                SpriteTextureEnumeration(byte_5EC4CC);
                v5 = 89;
                *(_DWORD *)(this + 508) = 2;
              }
            }
          }
          *(_DWORD *)(this + 512) = v13;
          *(_DWORD *)(this + 516) = v5;
        }
      }
      else
      {
        v5 = *(_DWORD *)(this + 508) - 3;
        if ( *(_DWORD *)(this + 508) == 3 )
        {
          ((void (__thiscall *)(int))((char *)&unk_46A9BF + 1))(this);
          *(_BYTE *)(*(_DWORD *)(this + 64) + 5513) = 1;
          sub_4988C0(1);
          LOBYTE(v5) = LookupDispatch(*(_DWORD *)(this + 504), -1);
          *(_DWORD *)(this + 508) = 0;
        }
      }
    }
  }
  return v5;
}
