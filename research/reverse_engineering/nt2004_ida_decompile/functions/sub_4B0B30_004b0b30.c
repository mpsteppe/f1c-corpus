char __thiscall sub_4B0B30(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // eax
  CHAR *v5; // eax
  char Buffer[125]; // [esp+8h] [ebp-100h] BYREF
  __int16 v7; // [esp+85h] [ebp-83h]
  char v8; // [esp+87h] [ebp-81h]
  char v9[125]; // [esp+88h] [ebp-80h] BYREF
  __int16 v10; // [esp+105h] [ebp-3h]
  char v11; // [esp+107h] [ebp-1h]

  sub_4B0C50(this);
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v7 = 0;
  v8 = 0;
  v9[0] = byte_629120;
  memset(&v9[1], 0, 0x7Cu);
  v10 = 0;
  v11 = 0;
  v2 = (const char *)this[2];
  if ( !v2 )
    v2 = &byte_629120;
  sub_405480(Buffer, 0x7Fu, "%s%s", v2, aTga);
  v3 = (const char *)this[2];
  if ( !v3 )
    v3 = &byte_629120;
  sub_405480(v9, 0x7Fu, "%s%s", v3, aBmp);
  if ( sub_592A60(this + 4, Buffer, 0x20000) && sub_592A60(this + 4, v9, 0x20000) )
    return 0;
  v5 = (CHAR *)this[2];
  if ( !v5 )
    v5 = &byte_629120;
  sub_592D90(v5, this[5], 32, 64, *(_DWORD *)(this[4] + 164), *(_DWORD *)(this[4] + 168));
  return 1;
}
