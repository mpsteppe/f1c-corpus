int __thiscall sub_4EAD30(_DWORD *this, char a2, CHAR *a3)
{
  CHAR *v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  char Buffer[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v9; // [esp+105h] [ebp-3h]
  char v10; // [esp+107h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v9 = 0;
  v10 = 0;
  v4 = a3;
  if ( !a3 )
    v4 = sub_4EAD00(this);
  sub_4EADE0(v4);
  if ( !a2 )
    return sub_4EB1C0(this);
  v5 = (const char *)dword_62A120;
  if ( !dword_62A120 )
    v5 = &byte_629120;
  v6 = *(const char **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v6 = &byte_629120;
  sub_405480(Buffer, 0xFFu, "%s%s%s", v6, v5, aCreateacarTga);
  return sub_4EB530(Buffer);
}
