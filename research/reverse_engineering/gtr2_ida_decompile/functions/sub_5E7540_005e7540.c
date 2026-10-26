_DWORD *__thiscall sub_5E7540(
        _DWORD *this,
        int a2,
        int a3,
        _DWORD *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  int v15; // ecx
  int v16; // eax
  bool v17; // sf
  _DWORD *v18; // esi
  _DWORD *result; // eax
  int *v20; // [esp-8h] [ebp-20h]
  int *v21; // [esp-4h] [ebp-1Ch]
  int v22; // [esp+10h] [ebp-8h] BYREF
  int v23; // [esp+14h] [ebp-4h] BYREF

  v11 = a3;
  v12 = a10;
  v13 = a6;
  v15 = a2;
  a2 = a7;
  a3 = a8;
  v16 = a5;
  v17 = a5 < 0;
  v23 = v15;
  v22 = v11;
  a8 = a5;
  a7 = a6;
  a6 = a10;
  a5 = a11;
  if ( v17 )
    v23 = v15 - v16;
  if ( v13 < 0 )
    v22 = v11 - v13;
  sub_5E6ED0(this, &v23, &v22, &a2, &a3);
  if ( v12 || a11 )
  {
    v21 = &a5;
    v20 = &a6;
  }
  else
  {
    v21 = &a3;
    v20 = &a2;
  }
  v18 = a4;
  result = sub_5E6ED0(a4, &a8, &a7, v20, v21);
  if ( a2 > 0 )
  {
    result = (_DWORD *)a3;
    if ( a3 > 0 )
    {
      result = (_DWORD *)(*(int (__thiscall **)(int, _DWORD *, int, int, _DWORD *, int, int, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 304))(
                           dword_FB27A4,
                           this,
                           v23,
                           v22,
                           v18,
                           a8,
                           a7,
                           a2,
                           a3,
                           a9,
                           a6,
                           a5);
      *v18 &= ~0x100u;
    }
  }
  return result;
}
