_DWORD *__thiscall sub_5E7490(_DWORD *this, int a2, int a3, float a4, float a5, int a6)
{
  double v7; // st7
  double v8; // st6
  _DWORD *result; // eax
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h] BYREF

  v7 = (double)(int)this[1];
  v8 = (double)(int)this[2];
  v11 = (unsigned __int64)(*(float *)&a2 * v7);
  *(float *)&a2 = v8;
  v10 = (unsigned __int64)(v8 * *(float *)&a3);
  a3 = (unsigned __int64)(v7 * a4);
  a2 = (unsigned __int64)(*(float *)&a2 * a5);
  result = sub_5E6ED0(this, &v11, &v10, &a3, &a2);
  if ( a3 > 0 )
  {
    result = (_DWORD *)a2;
    if ( a2 > 0 )
    {
      (*(void (__thiscall **)(int, _DWORD *, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 308))(
        dword_FB27A4,
        this,
        v11,
        v10,
        a3,
        a2,
        a6);
      result = (_DWORD *)(*this & 0xFFFFFEFF);
      *this = result;
    }
  }
  return result;
}
