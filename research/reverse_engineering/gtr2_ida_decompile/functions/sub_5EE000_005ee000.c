int __thiscall sub_5EE000(void *this, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  char v10; // [esp+0h] [ebp-1Ch]

  if ( a2 )
  {
    v6 = operator new(0x30u);
    v7 = v6;
    if ( v6 )
    {
      sub_5D9010(v6);
      *v7 = 0;
      v7[1] = 0;
      v7[5] = 0;
      v7[6] = 0;
      v7[7] = 0;
      v7[2] = 0;
      v7[3] = 0;
      v7[9] = 0;
      v7[10] = 0;
      v7[8] = 0;
      v7[4] = 2;
      v7[11] = 0;
    }
    else
    {
      v7 = 0;
    }
    sub_5FDFB0(v7, 1);
    if ( a3 )
      sub_5EDA60((int)v7, a3, 4);
    if ( a4 )
      v7[9] = a4;
    if ( a3 == 2 )
    {
      v8 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
             dword_FB27A4,
             "L0NOLIGHTING",
             0);
    }
    else
    {
      if ( a3 != 1 )
      {
LABEL_14:
        v7[2] = a5;
        v7[3] = a6;
        *a2 = v7;
        return 0;
      }
      v8 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
             dword_FB27A4,
             "L0SCREENT0",
             0);
    }
    v7[10] = v8;
    goto LABEL_14;
  }
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid pointer address for CreatePolygon", v10);
  return -1;
}
