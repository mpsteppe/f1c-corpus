_DWORD *__thiscall sub_5E6F50(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *result; // eax
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  v8 = a3;
  v9 = a2;
  a2 = a4;
  a3 = a5;
  result = sub_5E6ED0(this, &v9, &v8, &a2, &a3);
  if ( a2 > 0 )
  {
    result = (_DWORD *)a3;
    if ( a3 > 0 )
      return (_DWORD *)(*(int (__thiscall **)(int, _DWORD *, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 308))(
                         dword_FB27A4,
                         this,
                         v9,
                         v8,
                         a2,
                         a3,
                         a6);
  }
  return result;
}
