int __thiscall sub_6CB728(_DWORD *this)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // edi
  int result; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)this[64];
  v3 = v2 & 0xFFF00000;
  v4 = 0;
  v5 = v2 & 0xFFFFF;
  switch ( v3 )
  {
    case 0x74300000u:
      goto LABEL_9;
    case 0x74400000u:
      v7 = 5;
      goto LABEL_10;
    case 0x74500000u:
LABEL_9:
      v7 = 2;
      goto LABEL_10;
    case 0x74600000u:
      v7 = 4;
      goto LABEL_10;
    case 0x74700000u:
      v7 = 3;
LABEL_10:
      v4 = v7;
      break;
  }
  result = sub_6CB0CE((int)this, (v4 << 16) | 0x2D);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 8)),
               &v8,
               &v10);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int, int *))(*this + 120))(
                 this,
                 *(_DWORD *)(this[64] + 8),
                 v5,
                 983040,
                 &v9);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v8, v9, v10);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                     this,
                     *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v5 + *(_DWORD *)(this[64] + 8))),
                     &v8,
                     &v10);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, int, int, int, int *))(*this + 120))(
                       this,
                       4 * v5 + *(_DWORD *)(this[64] + 8),
                       v5,
                       983040,
                       &v9);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v8, v9, v10);
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
    }
  }
  return result;
}
