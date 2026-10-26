int __thiscall sub_4CD8D0(_BYTE *this)
{
  char *v2; // eax
  const char *v3; // edx
  const char *v4; // eax
  int v5; // eax
  int v6; // edi
  char v8[4]; // [esp+8h] [ebp-10Ch] BYREF
  char Buffer[8]; // [esp+Ch] [ebp-108h] BYREF
  char v10[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v11; // [esp+111h] [ebp-3h]
  char v12; // [esp+113h] [ebp-1h]

  sub_578870(v8);
  Buffer[0] = 0;
  sprintf(Buffer, off_60F750, aPlr);
  v2 = *(char **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v2 = &byte_629120;
  sub_578A30(Buffer, 1, v2, 1);
  sub_578E30(2);
  v3 = (const char *)sub_578D80(v8);
  if ( v3 )
  {
    v10[0] = byte_629120;
    memset(&v10[1], 0, 0xFCu);
    v11 = 0;
    v12 = 0;
    v4 = *(const char **)dword_62A0D0;
    if ( !*(_DWORD *)dword_62A0D0 )
      v4 = &byte_629120;
    sprintf(v10, "%s%s", v4, v3);
    v5 = sub_4CD9C0(v10, 1);
  }
  else
  {
    sub_4CDED0(aPlayer);
    v5 = sub_4CD8D0(this);
    this[22432] = 1;
    this[22433] = 1;
  }
  v6 = v5;
  sub_5788D0(v8);
  return v6;
}
