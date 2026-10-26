int __thiscall sub_6CBE5C(_DWORD *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // edi
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // [esp-14h] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-24h]
  int v11; // [esp+4h] [ebp-14h] BYREF
  int v12; // [esp+8h] [ebp-10h] BYREF
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  if ( !this[13] )
    return -2147467263;
  v4 = *(_DWORD *)this[64];
  v5 = v4 & 0xFFF00000;
  v6 = v4 & 0xFFFFF;
  switch ( v5 )
  {
    case 0x10F00000u:
      goto LABEL_11;
    case 0x73500000u:
      v10 = 3;
      goto LABEL_12;
    case 0x73600000u:
      v10 = 4;
      goto LABEL_12;
    case 0x73700000u:
LABEL_11:
      v10 = 5;
      goto LABEL_12;
    case 0x73800000u:
      v10 = 2;
LABEL_12:
      v2 = v10;
      break;
  }
  result = sub_6CB0CE((int)this, (v2 << 16) | 0x5E);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v15,
               0,
               &v11);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 &v12,
                 v11);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v15, v12, 0);
        if ( result >= 0 )
        {
          v7 = this[64];
          v8 = *this;
          v9 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v7 + 8));
          if ( (*(_DWORD *)v7 & 0xFFF00000) == 0x10F00000 )
          {
            result = (*(int (__thiscall **)(_DWORD *, int, int *, int *))(v8 + 116))(this, v9, &v15, &v14);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int, int *))(*this + 120))(
                       this,
                       *(_DWORD *)(this[64] + 8),
                       *(_DWORD *)(this[64] + 12),
                       v12,
                       &v13);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v15, v13, v14);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, int, unsigned int, int))(*this + 104))(
                       this,
                       v15,
                       (unsigned int)&dword_1000000 ^ v13,
                       v14);
          }
          else
          {
            result = (*(int (__thiscall **)(_DWORD *, int, int *, int *))(v8 + 116))(this, v9, &v15, &v14);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int, int *))(*this + 120))(
                       this,
                       *(_DWORD *)(this[64] + 8),
                       v6,
                       v12,
                       &v13);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v15, v13, v14);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                       this,
                       *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v6 + *(_DWORD *)(this[64] + 8))),
                       &v15,
                       &v14);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, int, int, int, int *))(*this + 120))(
                       this,
                       4 * v6 + *(_DWORD *)(this[64] + 8),
                       v6,
                       v12,
                       &v13);
            if ( result < 0 )
              return result;
            result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v15, v13, v14);
          }
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
            if ( result >= 0 )
            {
              result = sub_6C64E6(this);
              if ( result >= 0 )
                return 0;
            }
          }
        }
      }
    }
  }
  return result;
}
