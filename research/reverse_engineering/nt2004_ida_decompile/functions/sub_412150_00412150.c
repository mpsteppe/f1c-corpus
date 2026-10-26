int __thiscall sub_412150(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  int v3; // edx
  int v4; // eax
  char *v5; // edi
  void *v6; // ecx
  char Destination[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v8; // [esp+89h] [ebp-3h]
  char v9; // [esp+8Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x7Cu);
  v8 = 0;
  v9 = 0;
  v1 = this[23];
  if ( !v1
    || !(*(unsigned __int8 (__thiscall **)(_DWORD *, int, char *, int))(*this + 44))(this, v1, Destination, 127)
    || (result = sub_4ED590(Destination), !(_BYTE)result) )
  {
    sub_4CD5B0(Destination, 127);
    v3 = dword_5FC048;
    v4 = dword_5FC04C;
    v5 = &Destination[strlen(Destination)];
    *(_DWORD *)v5 = dword_5FC044;
    v6 = off_5FC050;
    *((_DWORD *)v5 + 1) = v3;
    *((_DWORD *)v5 + 2) = v4;
    *((_DWORD *)v5 + 3) = v6;
    return sub_4ED590(Destination);
  }
  return result;
}
