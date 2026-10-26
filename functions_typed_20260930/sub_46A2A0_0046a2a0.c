int __stdcall sub_46A2A0(int a1)
{
  int result; // eax
  int v2; // ebp
  const char *v3; // esi
  int v4; // ecx
  char *i; // eax
  const char *v6; // ecx
  int v7; // eax
  int v8; // [esp+4h] [ebp-118h]
  char v9[16]; // [esp+Ch] [ebp-110h] BYREF
  char v10[256]; // [esp+1Ch] [ebp-100h] BYREF

  LinkedListDestructionWithVTableCall();
  result = dword_8AC488;
  if ( dword_8AC488 > 0 )
  {
    v2 = 0;
    v8 = dword_8AC488;
    do
    {
      v3 = (const char *)(dword_8AC490 + v2 + 4);
      strcpy(v10, v3);
      v4 = strlen(v10);
      if ( v4 > 0 )
      {
        for ( i = &v9[v4 + 15]; i >= v10; *i-- = 0 )
        {
          if ( *i == 92 )
            break;
        }
      }
      v6 = &v3[strlen(v3)];
      if ( v6 > v3 )
      {
        while ( *v6 != 92 )
        {
          if ( --v6 <= v3 )
            goto LABEL_12;
        }
        ++v6;
      }
LABEL_12:
      StringFormatWithBufferOverflowCheck(v9, off_5C6660[0], v6);
      strcat(v10, v9);
      v7 = sub_497AD0(v10, 0);
      if ( !v7 )
        v7 = sub_497AD0(off_5C665C[0], 0);
      LinkedListNodeAppend(v7);
      v2 += 396;
      result = --v8;
    }
    while ( v8 );
  }
  return result;
}

