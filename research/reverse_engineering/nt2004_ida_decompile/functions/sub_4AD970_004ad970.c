int __thiscall sub_4AD970(_DWORD *this, char *String2, char a3, char a4, char a5)
{
  _DWORD *v5; // ebp
  int result; // eax
  char *v7; // eax
  char *v8; // edi
  char v9; // cl
  int v10; // esi
  void *v11; // eax
  int v12; // edi
  int i; // eax
  _DWORD *v14; // [esp+Ch] [ebp-104h]
  char ArgList[256]; // [esp+10h] [ebp-100h] BYREF

  v5 = this;
  v14 = this;
  if ( !String2 )
    return 0;
  result = sub_4ADBB0(String2);
  if ( !result )
  {
    strcpy(ArgList, String2);
    v7 = &ArgList[strlen(ArgList)];
    if ( v7 > ArgList )
    {
      while ( *v7 != 46 )
      {
        if ( --v7 <= ArgList )
          goto LABEL_9;
      }
      *v7 = 0;
    }
LABEL_9:
    v8 = &ArgList[strlen(ArgList) + 1];
    v9 = byte_608FDC;
    *(_DWORD *)--v8 = *(_DWORD *)dword_608FD8;
    v8[4] = v9;
    if ( sub_592390(dword_7DA988, (char)ArgList) && sub_592390(dword_7DA988, (char)String2) )
    {
      return 0;
    }
    else
    {
      v10 = v5[83];
      v11 = operator new(0x2Cu);
      if ( v11 )
        v12 = sub_4B0680(v11);
      else
        v12 = 0;
      sub_4B06B0(String2);
      *(_BYTE *)(v12 + 28) = a5;
      if ( a4 )
      {
        if ( (unsigned __int8)sub_4B07E0(v12) || !a3 )
        {
          v5 = v14;
        }
        else
        {
          sprintf(byte_765B18, "Unable to load surface \"%s\"", String2);
          v5 = v14;
          sub_4AE6B0(byte_765B18);
        }
      }
      if ( v10 )
      {
        for ( i = *(_DWORD *)(v10 + 40); i; i = *(_DWORD *)(i + 40) )
          v10 = i;
        *(_DWORD *)(v10 + 40) = v12;
      }
      else
      {
        v5[83] = v12;
      }
      ++v5[84];
      return v12;
    }
  }
  return result;
}
