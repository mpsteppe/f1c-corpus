int __thiscall sub_54457F(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  bool v4; // zf
  int v5; // ecx
  int result; // eax
  char v7; // [esp+Ch] [ebp-24h] BYREF
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v2 = this[1046];
  v3 = this[1050];
  v12 = v2;
  v11 = this[1049];
  v10 = this[6];
  v9 = this[11];
  v8 = this[4];
  this[1049] = v3;
  v4 = this[2] == 1;
  this[1046] = 1;
  this[6] = &v7;
  this[11] = &unk_617348;
  this[4] = 0;
  if ( !v4 )
  {
    v14 = this[1042];
    v5 = this[1043];
    this[1042] = 1;
    v13 = v5;
    this[1043] = this + 7;
    sub_543AE8(this, (int)(this + 7));
    this[1042] = v14;
    this[1043] = v13;
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD *))(*this + 8))(this, 0, 0, this + 7);
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD *))(*this + 4))(this, 0, 0, this + 7);
  this[1046] = v12;
  this[1049] = v11;
  this[6] = v10;
  this[11] = v9;
  result = v8;
  this[4] = v8;
  return result;
}
