char __thiscall sub_4B1410(const char **this, const char *a2)
{
  char *v3; // eax
  const char **v4; // ebp
  const char *v5; // ecx
  const char *v6; // eax
  const char *v7; // eax
  _BYTE v9[253]; // [esp+Ch] [ebp-100h] BYREF
  __int16 v10; // [esp+109h] [ebp-3h]
  char v11; // [esp+10Bh] [ebp-1h]

  v3 = (char *)this[2023];
  v4 = this + 2023;
  if ( !v3 )
    v3 = byte_5EA438;
  if ( !sub_588410(a2, v3) )
    return 0;
  v9[0] = byte_5EA438[0];
  memset(&v9[1], 0, 0xFCu);
  v10 = 0;
  v11 = 0;
  v5 = *v4;
  if ( !*v4 )
    v5 = byte_5EA438;
  v6 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v6 = byte_5EA438;
  if ( (int)StringFormatProcessingWithNullTerm(v9, 255, "%s%s", v6, v5) < 0 )
    return 0;
  ObjectIDLookupAcross9Arrays(v9);
  v7 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v7 = byte_5EA438;
  if ( (int)StringFormatProcessingWithNullTerm(v9, 255, "%s%s", v7, a2) < 0
    || (unsigned __int8)AudioFileLoadDecode(v9, 0) != 1 )
  {
    return 0;
  }
  SettingsFileInit(this);
  StringCopyWithBufferRealloc(a2);
  F_5StepInit(this);
  return 1;
}
