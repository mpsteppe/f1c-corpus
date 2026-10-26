int __thiscall sub_473EF0(_DWORD *this)
{
  const char *v2; // eax
  _DWORD *v3; // esi
  int result; // eax
  char Buffer[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v6; // [esp+105h] [ebp-3h]
  char v7; // [esp+107h] [ebp-1h]

  (*(void (__thiscall **)(_DWORD *))(*this + 176))(this);
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v6 = 0;
  v7 = 0;
  v2 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v2 = &byte_629120;
  sub_405480(Buffer, 0xFFu, "%s%s", v2, aCareerMas);
  v3 = this + 90;
  result = sub_5924D0(dword_7DA988, (int)v3, (int)Buffer);
  if ( result )
    *v3 = 0;
  return result;
}
