int __thiscall sub_503120(_DWORD *this)
{
  const char *v2; // eax
  float v4; // [esp+0h] [ebp-124h]
  float v5; // [esp+4h] [ebp-120h]
  char Buffer[253]; // [esp+24h] [ebp-100h] BYREF
  __int16 v7; // [esp+121h] [ebp-3h]
  char v8; // [esp+123h] [ebp-1h]

  this[15] = 0;
  this[16] = 120;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v7 = 0;
  v8 = 0;
  v2 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s", v2, aIngameMas);
  v5 = (double)(int)this[16] * 0.0009765625;
  v4 = (double)(int)this[15] * 0.00078125001;
  return sub_506880(-1, off_612C00, v4, v5, 0.0, 0.40000001, 0.125, 0, (int)Buffer);
}
