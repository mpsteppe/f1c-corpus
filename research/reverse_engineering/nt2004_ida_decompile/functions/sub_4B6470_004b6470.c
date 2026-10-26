int __thiscall sub_4B6470(void *this)
{
  const char *v1; // eax
  int v2; // esi
  float v4; // [esp+0h] [ebp-114h]
  float v5; // [esp+4h] [ebp-110h]
  float v6; // [esp+10h] [ebp-104h]
  char Buffer[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v8; // [esp+111h] [ebp-3h]
  char v9; // [esp+113h] [ebp-1h]

  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v8 = 0;
  v9 = 0;
  v1 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v1 = &byte_629120;
  sprintf(Buffer, "%s%s", v1, (const char *)off_609054);
  v6 = flt_609124 * 6.0;
  v2 = sub_5071F0(off_609110, dword_609118, off_609120, 1.0, 1.0, 1.0, 0.30000001, v6, 6, 4, (int)Buffer);
  if ( !v2 )
  {
    v5 = (double)dword_6152EC * 0.0009765625 * flt_609114;
    v4 = (double)dword_6152E8 * 0.00078125001 * flt_609114;
    sub_506C80(LODWORD(v4), LODWORD(v5));
  }
  return v2;
}
