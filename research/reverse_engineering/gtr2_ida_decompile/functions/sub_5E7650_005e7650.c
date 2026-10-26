_DWORD *__thiscall sub_5E7650(
        _DWORD *this,
        float a2,
        float a3,
        int a4,
        float a5,
        float a6,
        int a7,
        int a8,
        int a9,
        float a10,
        float a11)
{
  double v12; // st7
  double v13; // st6
  _DWORD *v14; // esi
  double v15; // st7
  double v16; // st6
  float v17; // ebx
  float v18; // ebp
  _DWORD *result; // eax
  int v20; // [esp+10h] [ebp-4h] BYREF

  v12 = (double)(int)this[1];
  v13 = (double)(int)this[2];
  v20 = (unsigned __int64)(a2 * v12);
  a2 = v13;
  LODWORD(a3) = (unsigned __int64)(v13 * a3);
  a7 = (unsigned __int64)(v12 * *(float *)&a7);
  v14 = (_DWORD *)a4;
  v15 = (double)*(int *)(a4 + 4);
  a8 = (unsigned __int64)(a2 * *(float *)&a8);
  v16 = (double)*(int *)(a4 + 8);
  LODWORD(v17) = (unsigned __int64)(a5 * v15);
  a5 = v17;
  *(float *)&a4 = v16;
  LODWORD(a2) = (unsigned __int64)(v16 * a6);
  LODWORD(v18) = (unsigned __int64)(v15 * a10);
  a6 = v18;
  a4 = (unsigned __int64)(*(float *)&a4 * a11);
  if ( v17 < 0.0 )
    v20 -= LODWORD(v17);
  if ( a2 < 0.0 )
    LODWORD(a3) -= LODWORD(a2);
  sub_5E6ED0(this, &v20, (int *)&a3, &a7, &a8);
  if ( v18 == 0.0 && *(float *)&a4 == 0.0 )
  {
    result = sub_5E6ED0(v14, (int *)&a5, (int *)&a2, &a7, &a8);
  }
  else
  {
    result = sub_5E6ED0(v14, (int *)&a5, (int *)&a2, (int *)&a6, &a4);
    v18 = a6;
  }
  if ( a7 > 0 )
  {
    result = (_DWORD *)a8;
    if ( a8 > 0 )
    {
      result = (_DWORD *)(*(int (__thiscall **)(int, _DWORD *, int, _DWORD, _DWORD *, _DWORD, _DWORD, int, int, int, float, int))(*(_DWORD *)dword_FB27A4 + 304))(
                           dword_FB27A4,
                           this,
                           v20,
                           LODWORD(a3),
                           v14,
                           LODWORD(a5),
                           LODWORD(a2),
                           a7,
                           a8,
                           a9,
                           COERCE_FLOAT(LODWORD(v18)),
                           a4);
      *v14 &= ~0x100u;
    }
  }
  return result;
}
