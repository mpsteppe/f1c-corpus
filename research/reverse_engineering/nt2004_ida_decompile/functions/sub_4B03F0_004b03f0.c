LPVOID *__thiscall sub_4B03F0(int this)
{
  char *v2; // eax
  char **v3; // ebx
  int v4; // edx
  const char *v5; // eax
  const char *v6; // eax
  char *v7; // eax
  LPVOID *result; // eax
  char *v9; // eax
  char Buffer[64]; // [esp+8h] [ebp-40h] BYREF

  v2 = *(char **)(this + 4);
  v3 = (char **)(this + 4);
  if ( !v2 )
    v2 = &byte_629120;
  v4 = sub_4ADBB0((_DWORD *)dword_7655CC, v2);
  if ( v4 || !*(_BYTE *)(this + 12) )
    return (LPVOID *)v4;
  v5 = *(const char **)(this + 20);
  if ( !v5 )
    v5 = &byte_629120;
  if ( !strlen(v5) )
    return (LPVOID *)v4;
  v6 = *(const char **)(this + 20);
  if ( !v6 )
    v6 = &byte_629120;
  sub_405480(Buffer, 0x3Fu, "%s_%d_%d", v6, *(__int16 *)(this + 14), *(__int16 *)(this + 16));
  sub_578600(Buffer);
  v7 = *v3;
  if ( !*v3 )
    v7 = &byte_629120;
  result = (LPVOID *)sub_4ADBB0((_DWORD *)dword_7655CC, v7);
  if ( !result )
  {
    v9 = *v3;
    if ( !*v3 )
      v9 = &byte_629120;
    return sub_4ADAF0((_DWORD *)dword_7655CC, v9, *(__int16 *)(this + 14), *(__int16 *)(this + 16));
  }
  return result;
}
