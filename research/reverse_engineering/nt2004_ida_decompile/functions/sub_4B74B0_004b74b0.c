int __thiscall sub_4B74B0(_DWORD *this)
{
  const char *v2; // eax
  int v3; // esi
  float v5; // [esp+0h] [ebp-114h]
  float v6; // [esp+4h] [ebp-110h]
  float v7; // [esp+10h] [ebp-104h]
  char Buffer[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v9; // [esp+111h] [ebp-3h]
  char v10; // [esp+113h] [ebp-1h]

  (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
  this[19] = 1;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v9 = 0;
  v10 = 0;
  v2 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s", v2, (const char *)off_609054);
  v7 = flt_609124 * 13.0;
  v3 = sub_5071F0(off_609110, dword_609118, off_609120, 1.0, 1.0, 1.0, 0.30000001, v7, 13, 4, (int)Buffer);
  if ( !v3 )
  {
    v6 = (double)dword_6152EC * 0.0009765625 * flt_609114;
    v5 = (double)dword_6152E8 * 0.00078125001 * flt_609114;
    sub_506C80(LODWORD(v5), LODWORD(v6));
  }
  return v3;
}
