int __thiscall sub_4336F0(const char **this, int a2)
{
  int v2; // eax
  int v3; // edi
  int result; // eax
  int v6; // ebx
  int v7; // ebp
  const CHAR *v8; // eax
  char **v9; // edi
  char *v10; // eax
  char *v11; // edi
  char *v12; // eax
  char *v13; // eax
  int v14; // [esp+Ch] [ebp-108h]
  int v15; // [esp+10h] [ebp-104h]
  _BYTE v16[128]; // [esp+14h] [ebp-100h] BYREF
  _BYTE v17[128]; // [esp+94h] [ebp-80h] BYREF

  v2 = dword_5C329C;
  v3 = a2;
  if ( a2 < 0 || a2 >= dword_5C329C )
    v3 = 0;
  else
    v2 = a2 + 1;
  v14 = v2;
  result = AISettingsFileResolver(v16, 128);
  v6 = v3;
  v15 = v3;
  if ( v3 < v14 )
  {
    while ( 1 )
    {
      v7 = dword_7C54F0[v6];
      if ( !*(_DWORD *)(v7 + 13000) )
        break;
      sub_587DD0(v7 + 18324, v16, 255);
      *(_BYTE *)(v7 + 18579) = 0;
LABEL_23:
      result = v14;
      v15 = ++v6;
      if ( v6 >= v14 )
        return result;
    }
    sub_432DF0(this, (int)&byte_7CE498);
    v8 = *this;
    if ( !*this )
      v8 = &byte_5EA438;
    FileAttributesExistenceCheck(v8);
    v9 = (char **)(this + 4);
    if ( !LookUpVehicleConfigEntry(v17, 128) )
    {
      StringCopyWithBufferRealloc(v17);
      if ( (unsigned __int8)sub_568B00() )
      {
LABEL_16:
        v11 = *v9;
        if ( !v11 )
          v11 = &byte_5EA438;
        StringCopyWithBufferRealloc(v11);
        v12 = (char *)*this;
        if ( !*this )
          v12 = &byte_5EA438;
        sub_587DD0(v7 + 18324, v12, 255);
        *(_BYTE *)(v7 + 18579) = 0;
        v13 = (char *)*this;
        if ( !*this )
          v13 = &byte_5EA438;
        ValidateVehicleConfigurationFile(v13, 0);
        v6 = v15;
        goto LABEL_23;
      }
      v10 = *v9;
      if ( !*v9 )
        v10 = &byte_5EA438;
      LinkedListRemovalByName(v10);
    }
    StringCopyWithBufferRealloc(&byte_5EA438);
    goto LABEL_16;
  }
  return result;
}

