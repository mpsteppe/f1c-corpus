char __thiscall sub_44F540(_DWORD *this, const char *a2)
{
  const char *v3; // eax
  HANDLE ImageA; // eax
  _DWORD *v5; // ecx
  CHAR name[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v8; // [esp+105h] [ebp-3h]
  char v9; // [esp+107h] [ebp-1h]

  name[0] = byte_5EA438[0];
  memset(&name[1], 0, 0xFCu);
  v8 = 0;
  v9 = 0;
  v3 = (const char *)dword_5EC408;
  if ( !dword_5EC408 )
    v3 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(name, "%s%s", v3, a2);
  ImageA = LoadImageA(0, name, 2u, 0, 0, 0x10u);
  if ( ImageA )
  {
    v5 = &this[5 * this[42] + 12];
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = 0;
    this[5 * this[42]++ + 12] = ImageA;
  }
  return 0;
}
