int __thiscall sub_6CC065(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // [esp+4h] [ebp-1Ch]
  int v13; // [esp+8h] [ebp-18h] BYREF
  int v14; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+10h] [ebp-10h] BYREF
  int v16; // [esp+14h] [ebp-Ch] BYREF
  int v17; // [esp+18h] [ebp-8h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-4h]

  if ( !this[13] )
    return -2147467263;
  v3 = this[64];
  if ( !*(_DWORD *)(v3 + 12) )
    return 0;
  v4 = *(_DWORD **)(this[5] + 4 * **(_DWORD **)(v3 + 16));
  v12 = v4;
  for ( i = 0; i < 2; ++i )
  {
    v5 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * i * *(_DWORD *)(this[64] + 12)));
    if ( v5[1] != v4[1] || v5[2] != v4[2] || v5[3] != v4[3] || v5[4] != v4[4] )
    {
      result = sub_6CB0CE((int)this, 1);
      if ( result < 0 )
        return result;
      v6 = *(_DWORD *)(this[5] + 4 * v5[5]);
      v7 = *(_DWORD *)(v6 + 12);
      v8 = *(_DWORD *)(v6 + 16);
      v9 = v7 & 0x7FF | 0xB0001000;
      if ( v8 )
      {
        v10 = v8 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 == 1 )
              v9 |= (unsigned int)dword_FF0000;
          }
          else
          {
            v9 |= (unsigned int)&unk_AA0000;
          }
        }
        else
        {
          v9 |= 0x550000u;
        }
      }
      if ( !v5[6] )
        v9 |= 0xD000000u;
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, int *))(*this + 108))(
                 this,
                 *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
                 &v17,
                 0,
                 &v15);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 &v16,
                 v15);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *, int, int, unsigned int))(*this + 100))(this, v17, v16, v9);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                 this,
                 *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * i * *(_DWORD *)(this[64] + 12))),
                 &v17,
                 &v14);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, _DWORD, int, int *))(*this + 120))(
                 this,
                 *(_DWORD *)(this[64] + 8) + 4 * i * *(_DWORD *)(this[64] + 12),
                 *(_DWORD *)(this[64] + 12),
                 v16,
                 &v13);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v17, v13, v14);
      if ( result < 0 )
        return result;
      result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
      if ( result < 0 )
        return result;
      result = sub_6C64E6(this);
      if ( result < 0 )
        return result;
      v4 = v12;
    }
  }
  return 0;
}
