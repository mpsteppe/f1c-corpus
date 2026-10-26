int __thiscall sub_6CC8DB(_DWORD *this)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int result; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // [esp-4h] [ebp-28h]
  int v13; // [esp+Ch] [ebp-18h] BYREF
  int v14; // [esp+10h] [ebp-14h] BYREF
  int v15; // [esp+14h] [ebp-10h] BYREF
  int v16; // [esp+18h] [ebp-Ch] BYREF
  int v17; // [esp+1Ch] [ebp-8h] BYREF
  int v18; // [esp+20h] [ebp-4h] BYREF

  v2 = *(_DWORD *)this[64];
  v3 = v2 & 0xFFFFF;
  v4 = v2 - 1884291075;
  if ( v4 )
  {
    v5 = v4 - 0x100000;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 0xFFFFF;
        if ( v7 )
        {
          if ( v7 != 1 )
          {
            v8 = v13;
            goto LABEL_13;
          }
          v12 = 20;
        }
        else
        {
          v12 = 22;
        }
      }
      else
      {
        v12 = 21;
      }
    }
    else
    {
      v12 = 23;
    }
  }
  else
  {
    v12 = 24;
  }
  v8 = v12;
LABEL_13:
  result = sub_6CB0CE((int)this, v8);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v18,
               &v13,
               &v14);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 &v17,
                 v14);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 100))(this, v18, v17, v13);
        if ( result >= 0 )
        {
          v10 = this[5];
          v11 = this[64];
          v17 = v3 != 3 ? 983040 : 458752;
          result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                     this,
                     *(_DWORD *)(v10 + 4 * **(_DWORD **)(v11 + 8)),
                     &v18,
                     &v16);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int, int *))(*this + 120))(
                       this,
                       *(_DWORD *)(this[64] + 8),
                       v3,
                       v17,
                       &v15);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v18, v15, v16);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                           this,
                           *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v3 + *(_DWORD *)(this[64] + 8))),
                           &v18,
                           &v16);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(_DWORD *, int, int, int, int *))(*this + 120))(
                             this,
                             4 * v3 + *(_DWORD *)(this[64] + 8),
                             v3,
                             v17,
                             &v15);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v18, v15, v16);
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
      }
    }
  }
  return result;
}
