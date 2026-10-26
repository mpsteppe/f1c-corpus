int __thiscall sub_6CB8D2(_DWORD *this)
{
  int *v2; // ecx
  int v3; // edi
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // eax
  int result; // eax
  int v8; // [esp+Ch] [ebp-2Ch] BYREF
  int v9; // [esp+10h] [ebp-28h]
  int v10; // [esp+14h] [ebp-24h] BYREF
  _DWORD *v11; // [esp+18h] [ebp-20h] BYREF
  _DWORD *v12; // [esp+1Ch] [ebp-1Ch] BYREF
  _DWORD *v13; // [esp+20h] [ebp-18h] BYREF
  _DWORD *v14; // [esp+24h] [ebp-14h] BYREF
  int v15; // [esp+28h] [ebp-10h] BYREF
  int v16; // [esp+2Ch] [ebp-Ch] BYREF
  int v17; // [esp+30h] [ebp-8h] BYREF
  int v18; // [esp+34h] [ebp-4h] BYREF

  v2 = (int *)this[64];
  v3 = *v2;
  v9 = v2[3];
  v4 = v3 & 0xFFFFF;
  sub_680D41(v2, 0, &v13);
  sub_680D41((_DWORD *)this[64], 1, &v14);
  sub_680D41((_DWORD *)this[64], 2, &v12);
  sub_680D41((_DWORD *)this[64], 3, &v11);
  v5 = *(_DWORD **)(this[64] + 16);
  v6 = (*(int (__thiscall **)(_DWORD *, int))(*this + 92))(this, 93);
  result = sub_6CB0CE((int)this, v6);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * *v5),
               &v18,
               &v8,
               &v10);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int *, int))(*this + 112))(this, v5, v9, &v15, v10);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 100))(this, v18, v15, v8);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                     this,
                     *(_DWORD *)(this[5] + 4 * *v14),
                     &v18,
                     &v17);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                       this,
                       v14,
                       v4,
                       v15,
                       &v16);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v18, v16, v17);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                           this,
                           *(_DWORD *)(this[5] + 4 * *v13),
                           &v18,
                           &v17);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                             this,
                             v13,
                             v4,
                             v15,
                             &v16);
                  if ( result >= 0 )
                  {
                    result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v18, v16, v17);
                    if ( result >= 0 )
                    {
                      result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                                 this,
                                 *(_DWORD *)(this[5] + 4 * *v12),
                                 &v18,
                                 &v17);
                      if ( result >= 0 )
                      {
                        result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                                   this,
                                   v12,
                                   v4,
                                   v15,
                                   &v16);
                        if ( result >= 0 )
                        {
                          result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v18, v16, v17);
                          if ( result >= 0 )
                          {
                            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                                       this,
                                       *(_DWORD *)(this[5] + 4 * *v11),
                                       &v18,
                                       &v17);
                            if ( result >= 0 )
                            {
                              result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                                         this,
                                         v11,
                                         v4,
                                         v15,
                                         &v16);
                              if ( result >= 0 )
                              {
                                result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(
                                           this,
                                           v18,
                                           v16,
                                           v17);
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
            }
          }
        }
      }
    }
  }
  return result;
}
