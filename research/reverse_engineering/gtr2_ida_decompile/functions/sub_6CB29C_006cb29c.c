int __thiscall sub_6CB29C(
        _DWORD *this,
        int a2,
        _DWORD *a3,
        int a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  int v12; // ebx
  int v14; // eax
  int result; // eax
  _DWORD *v16; // edi
  _DWORD *v17; // edi
  _DWORD *v18; // edi
  _DWORD *v19; // edi
  int v20; // [esp+8h] [ebp-14h] BYREF
  int v21; // [esp+Ch] [ebp-10h] BYREF
  int v22; // [esp+10h] [ebp-Ch] BYREF
  int v23; // [esp+14h] [ebp-8h] BYREF
  int v24; // [esp+18h] [ebp-4h] BYREF

  v12 = a2;
  v14 = (*(int (__thiscall **)(_DWORD *, int))(*this + 92))(this, a2);
  result = sub_6CB0CE((int)this, v14);
  if ( result < 0 )
    return result;
  v16 = a3;
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *, int *))(*this + 108))(
             this,
             *(_DWORD *)(this[5] + 4 * *a3),
             &v24,
             &v20,
             &v21);
  if ( result < 0 )
    return result;
  result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int *, int))(*this + 112))(this, v16, a4, &a2, v21);
  if ( result < 0 )
    return result;
  result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 100))(
             this,
             v24 | (a12 != 0 ? 0x400000 : 0),
             a2,
             v20);
  if ( result < 0 )
    return result;
  switch ( v12 )
  {
    case 8:
      a2 = 458752;
      break;
    case 9:
      goto LABEL_16;
    case 90:
      a2 = 196608;
      break;
    case 6:
    case 14:
    case 15:
    case 7:
      a2 = 0x10000;
      break;
    case 37:
LABEL_16:
      a2 = 983040;
      break;
  }
  v17 = a5;
  if ( !a5
    || (result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                   this,
                   *(_DWORD *)(this[5] + 4 * *a5),
                   &v24,
                   &v23),
        result >= 0)
    && (result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v17, a8, a2, &v22),
        result >= 0)
    && (result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, a9 ^ v24, v22, v23), result >= 0) )
  {
    v18 = a6;
    if ( !a6
      || (result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                     this,
                     *(_DWORD *)(this[5] + 4 * *a6),
                     &v24,
                     &v23),
          result >= 0)
      && (result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v18, a8, a2, &v22),
          result >= 0)
      && (result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, a10 ^ v24, v22, v23), result >= 0) )
    {
      v19 = a7;
      if ( !a7
        || (result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                       this,
                       *(_DWORD *)(this[5] + 4 * *a7),
                       &v24,
                       &v23),
            result >= 0)
        && (result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v19, a8, a2, &v22),
            result >= 0)
        && (result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, a11 ^ v24, v22, v23),
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
  return result;
}
