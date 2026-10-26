int __thiscall sub_6CC6F7(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edi
  bool v5; // zf
  int result; // eax
  _DWORD v7[4]; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v8; // [esp+1Ch] [ebp-4h]

  v2 = (_DWORD *)this[64];
  v3 = (_DWORD *)v2[4];
  v4 = *v2 & 0xFFFFF;
  v5 = this[34] == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v3) + 4);
  v8 = v3;
  if ( !v5 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
               this,
               this[63],
               v7,
               v4,
               0,
               0);
    if ( result < 0 )
      return result;
    v8 = v7;
    v3 = v7;
  }
  result = sub_6CB29C(this, 36, v3, v4, *(_DWORD **)(this[64] + 8), 0, 0, v4, 0, 0, 0, 0);
  if ( result >= 0 )
  {
    if ( v8 != v7 )
      return 0;
    result = sub_6CB29C(this, 1, *(_DWORD **)(this[64] + 16), v4, v7, 0, 0, v4, 0, 0, 0, 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
