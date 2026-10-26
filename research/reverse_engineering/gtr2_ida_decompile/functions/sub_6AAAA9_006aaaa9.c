int __thiscall sub_6AAAA9(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  int v5; // ebx
  _DWORD *v6; // edi
  int result; // eax
  int v8; // edx
  _DWORD *v9; // [esp+Ch] [ebp-10h]
  _DWORD *v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h] BYREF
  unsigned int v12; // [esp+18h] [ebp-4h] BYREF

  v3 = (_DWORD *)this[64];
  v4 = (_DWORD *)v3[2];
  v5 = *v3 & 0xFFFFF;
  v6 = v5 != v3[1] ? &v4[v5] : 0;
  v10 = v4;
  v9 = (unsigned int)(2 * v5) < v3[1] ? &v4[2 * v5] : 0;
  result = sub_6CB0CE(a2);
  if ( result >= 0 )
  {
    v8 = *this;
    a2 = *(unsigned __int8 *)(*(_DWORD *)(this[5] + 4 * *v10) + 109);
    v12 = a2 & 0x7FF | 0xB0000000;
    result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, _DWORD))(v8 + 100))(this, v12, 983040, 0);
    if ( result >= 0 )
    {
      if ( !v6
        || (result = (*(int (__thiscall **)(_DWORD *, _DWORD, unsigned int *, int *))(*this + 116))(
                       this,
                       *(_DWORD *)(this[5] + 4 * *v6),
                       &v12,
                       &a2),
            result >= 0)
        && (result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                       this,
                       v6,
                       v5,
                       983040,
                       &v11),
            result >= 0)
        && (result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, int))(*this + 104))(this, v12, v11, a2),
            result >= 0) )
      {
        if ( !v9
          || (result = (*(int (__thiscall **)(_DWORD *, _DWORD, unsigned int *, int *))(*this + 116))(
                         this,
                         *(_DWORD *)(this[5] + 4 * *v9),
                         &v12,
                         &a2),
              result >= 0)
          && (result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(
                         this,
                         v9,
                         v5,
                         983040,
                         &v11),
              result >= 0)
          && (result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, int))(*this + 104))(this, v12, v11, a2),
              result >= 0) )
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
  return result;
}
