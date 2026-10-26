int __thiscall sub_64FF67(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int result; // eax
  char v10; // [esp+Ch] [ebp-24h] BYREF
  int v11; // [esp+1Ch] [ebp-14h]
  int v12; // [esp+20h] [ebp-10h]
  int v13; // [esp+24h] [ebp-Ch]
  int v14; // [esp+28h] [ebp-8h]
  int v15; // [esp+2Ch] [ebp-4h]

  v2 = this[8];
  v3 = this[30];
  v4 = this[29];
  v13 = v2;
  v12 = this[13];
  v5 = this[6];
  this[6] = 0;
  this[29] = v3;
  v11 = v5;
  this[8] = &v10;
  v6 = this[2];
  v7 = this[26];
  this[26] = 1;
  this[13] = &unk_914348;
  if ( v6 != 1 && v6 != 4 )
  {
    v15 = this[21];
    v8 = this[22];
    this[21] = 1;
    v14 = v8;
    this[22] = this + 9;
    sub_64EB2A(this, (int)(this + 9));
    this[21] = v15;
    this[22] = v14;
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD *))(*this + 8))(this, 0, 0, this + 9);
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD *))(*this + 4))(this, 0, 0, this + 9);
  this[8] = v13;
  this[13] = v12;
  result = v11;
  this[26] = v7;
  this[29] = v4;
  this[6] = result;
  return result;
}
