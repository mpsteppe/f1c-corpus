int __thiscall sub_6481DD(void *this, int a2)
{
  bool v3; // zf
  __int16 v4; // ax
  int result; // eax
  char Buffer[3]; // [esp+8h] [ebp-18h] BYREF
  __int16 v7; // [esp+Bh] [ebp-15h]
  __int16 v8; // [esp+Dh] [ebp-13h]
  char v9; // [esp+Fh] [ebp-11h]
  __int16 v10; // [esp+10h] [ebp-10h]
  __int16 v11; // [esp+12h] [ebp-Eh]
  __int16 v12; // [esp+14h] [ebp-Ch]
  __int16 v13; // [esp+16h] [ebp-Ah]
  unsigned __int8 v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+19h] [ebp-7h]
  DWORD NumberOfBytesWritten; // [esp+1Ch] [ebp-4h] BYREF

  v3 = *(_DWORD *)this == 21;
  v12 = *((_WORD *)this + 6);
  v4 = *((_WORD *)this + 8);
  Buffer[0] = 13;
  Buffer[1] = 0;
  Buffer[2] = 2;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v13 = v4;
  if ( v3 )
  {
    v14 = 32;
    v15 = 40;
  }
  else
  {
    v14 = 24;
    v15 = 32;
  }
  NumberOfBytesWritten = 0;
  result = sub_6462BB(a2, Buffer, 0x12u, &NumberOfBytesWritten);
  if ( result >= 0 )
  {
    result = sub_6462BB(a2, "Saved by D3DX", 0xDu, &NumberOfBytesWritten);
    if ( result >= 0 )
      return sub_6462BB(
               a2,
               *((char **)this + 1),
               *((_DWORD *)this + 4) * *((_DWORD *)this + 3) * (v14 >> 3),
               &NumberOfBytesWritten);
  }
  return result;
}
