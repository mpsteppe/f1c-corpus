char __thiscall sub_41E760(_DWORD *this, char *Buffer, int a3)
{
  const char *v3; // edi
  char v5[1024]; // [esp+Ch] [ebp-400h] BYREF

  if ( this[34] )
    v3 = (const char *)this[34];
  else
    v3 = &byte_629120;
  if ( !Buffer || !_strcmpi(v3, &byte_629120) )
    return 0;
  strcpy(v5, Buffer);
  sprintf(Buffer, "%s%s", v3, v5);
  return 1;
}
