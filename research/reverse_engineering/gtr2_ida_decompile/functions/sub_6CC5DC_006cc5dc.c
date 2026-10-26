int __thiscall sub_6CC5DC(_DWORD *this)
{
  int v2; // ebx
  int v3; // eax
  int result; // eax
  _DWORD *v5; // edi
  int v6; // [esp+Ch] [ebp-20h] BYREF
  int v7; // [esp+10h] [ebp-1Ch] BYREF
  int v8; // [esp+14h] [ebp-18h] BYREF
  int v9; // [esp+18h] [ebp-14h] BYREF
  int v10; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h]
  int v13; // [esp+28h] [ebp-4h] BYREF

  v2 = *(_DWORD *)this[64] & 0xFFFFF;
  v3 = (*(int (__stdcall **)(int))(*this + 92))(18);
  result = sub_6CB0CE((int)this, v3);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v13,
               &v8,
               &v9);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 v2,
                 &v10,
                 v9);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 100))(this, v13, v10, v8);
        if ( result >= 0 )
        {
          v11 = 0;
          v12 = 0;
          while ( 1 )
          {
            v5 = (_DWORD *)(v12 + *(_DWORD *)(this[64] + 8));
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                       this,
                       *(_DWORD *)(this[5] + 4 * *v5),
                       &v13,
                       &v7);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v5, v2, v10, &v6);
            if ( result < 0 )
              break;
            result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v13, v6, v7);
            if ( result < 0 )
              break;
            ++v11;
            v12 += 4 * v2;
            if ( v11 >= 3 )
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
