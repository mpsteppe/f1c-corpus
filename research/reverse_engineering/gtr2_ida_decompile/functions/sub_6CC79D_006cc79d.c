int __thiscall sub_6CC79D(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int result; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  int v7; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-14h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-8h] BYREF
  int v14; // [esp+28h] [ebp-4h]

  v2 = *(_DWORD *)this[64] & 0xFFFFF;
  v3 = (*(int (__stdcall **)(int))(*this + 92))(4);
  result = sub_6CB0CE((int)this, v3);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v13,
               &v9,
               &v10);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 v2,
                 &v12,
                 v10);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 100))(this, v13, v12, v9);
        if ( result >= 0 )
        {
          v14 = 0;
          while ( 1 )
          {
            v5 = (_DWORD *)this[64];
            v6 = (_DWORD *)(v5[2] + 4 * v2 * v14);
            if ( v14 == 1 && (*v5 & 0xFFF00000) == 0x70400000 )
              v11 = (unsigned int)&dword_1000000;
            else
              v11 = 0;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                       this,
                       *(_DWORD *)(this[5] + 4 * *v6),
                       &v13,
                       &v8);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v6, v2, v12, &v7);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, int))(*this + 104))(this, v13 ^ v11, v7, v8);
            if ( result < 0 )
              break;
            if ( (unsigned int)++v14 >= 3 )
            {
              result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
              if ( result >= 0 )
              {
                result = sub_6C64E6(this);
                if ( result >= 0 )
                  return 0;
              }
              return result;
            }
          }
        }
      }
    }
  }
  return result;
}
