int __thiscall sub_4333E0(void *this)
{
  int result; // eax
  int v2; // ebp
  const char *v3; // edx
  unsigned int v4; // kr04_4
  const char *j; // eax
  unsigned int v6; // kr08_4
  char *v7; // ecx
  int v8; // esi
  char *v9; // eax
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  char *v13; // eax
  char *v14[2]; // [esp+Ch] [ebp-94h] BYREF
  int i; // [esp+14h] [ebp-8Ch]
  int v16; // [esp+18h] [ebp-88h]
  void *v17; // [esp+1Ch] [ebp-84h]
  _BYTE v18[128]; // [esp+20h] [ebp-80h] BYREF

  v17 = this;
  AISettingsFileResolver(v18, 128);
  result = 0;
  v16 = dword_5C329C;
  for ( i = 0; i < v16; result = ++i )
  {
    v2 = dword_7C54F0[result];
    if ( *(_DWORD *)(v2 + 13000) )
    {
      if ( byte_7D03E0 )
      {
        v14[0] = 0;
        v14[1] = (char *)-1;
        StringCopyWithBufferRealloc(v2 + 18196);
        v3 = v14[0];
        if ( !v14[0] )
          v3 = &byte_5EA438;
        v4 = strlen(v3) + 1;
        if ( (int)(v4 - 1) > 0 )
        {
          for ( j = &v3[v4 - 2]; j >= v3; *j-- = 0 )
          {
            if ( *j == 92 )
              break;
          }
        }
        v6 = strlen(NullSafePointerDereference(v14)) + 1;
        if ( (int)(v6 - 1) > 0 && NullSafePointerDereference(v14)[v6 - 2] != 92 )
          sub_5665B0(&word_5C2AAC);
        v7 = (char *)dword_7CE5EC;
        if ( !dword_7CE5EC )
          v7 = &byte_5EA438;
        v8 = SettingsFolderResolver(v7);
        v9 = NullSafePointerDereference(v14);
        StringCopyWithBufferRealloc(v9);
        sub_5665B0(v8);
        if ( IterationCountMap(dword_7C56A4) == 5 )
          sub_5665B0(aQual);
        else
          sub_5665B0(aRace_1);
        sub_5665B0(aSvm);
        v10 = sub_587DB0(&byte_5EA438, aR);
        if ( v10 )
        {
          FileCloseWithLock(v10);
          SafeStringCopy(255);
          goto LABEL_27;
        }
        v11 = v14[0];
        if ( !v14[0] )
          v11 = &byte_5EA438;
        StringCopyWithBufferRealloc(v11);
        sub_5665B0(v8);
        sub_5665B0(aSvm);
        v12 = sub_587DB0(&byte_5EA438, aR);
        if ( v12 )
          goto LABEL_26;
        v13 = v14[0];
        if ( !v14[0] )
          v13 = &byte_5EA438;
        StringCopyWithBufferRealloc(v13);
        sub_5665B0(aAiSvm);
        v12 = sub_587DB0(&byte_5EA438, aR);
        if ( v12 )
        {
LABEL_26:
          FileCloseWithLock(v12);
          sub_587DD0(v2 + 18324, &byte_5EA438, 255);
          *(_BYTE *)(v2 + 18579) = 0;
LABEL_27:
          if ( v14[0] )
            FreeWrapper_7bcf(v14[0]);
          continue;
        }
        if ( v14[0] )
          FreeWrapper_7bcf(v14[0]);
      }
      sub_587DD0(v2 + 18324, v18, 255);
      *(_BYTE *)(v2 + 18579) = 0;
    }
  }
  return result;
}
