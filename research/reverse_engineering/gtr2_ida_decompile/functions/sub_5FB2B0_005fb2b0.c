int __thiscall sub_5FB2B0(_DWORD *this, int ArgList, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // eax

  v8 = (_DWORD *)this[72];
  this[74] = v8;
  if ( v8 && (v9 = (_DWORD *)*v8) != 0 )
  {
    while ( v9[2] != ArgList || v9[3] != a3 || v9[5] != a4 || a7 && v9[6] != a7 )
    {
      v10 = this[74];
      if ( v10 )
        this[74] = *(_DWORD *)(v10 + 4);
      v11 = (_DWORD *)this[74];
      if ( v11 )
      {
        v9 = (_DWORD *)*v11;
        if ( v9 )
          continue;
      }
      goto LABEL_12;
    }
    *(_DWORD *)(dword_FB27A4 + 9408) = ArgList;
    *(_DWORD *)(dword_FB27A4 + 9412) = a3;
    *(_DWORD *)(dword_FB27A4 + 9424) = a4;
    *(_DWORD *)(dword_FB27A4 + 9432) = a5 & 1;
    v12 = (*(int (__thiscall **)(int, _DWORD *, int, int, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 120))(
            dword_FB27A4,
            this,
            dword_FB2780,
            ArgList,
            a3,
            a4,
            a5,
            a6,
            a7);
  }
  else
  {
LABEL_12:
    if ( (a5 & 1) == 0 )
      return -1;
    sub_5FB180(this, ArgList, a3, a4, 0);
    *(_DWORD *)(dword_FB27A4 + 9408) = ArgList;
    *(_DWORD *)(dword_FB27A4 + 9412) = a3;
    *(_DWORD *)(dword_FB27A4 + 9424) = a4;
    *(_DWORD *)(dword_FB27A4 + 9432) = a5 & 1;
    v12 = (*(int (__thiscall **)(int, _DWORD *, int, int, int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 120))(
            dword_FB27A4,
            this,
            dword_FB2780,
            ArgList,
            a3,
            a4,
            a5,
            a6,
            a7);
  }
  if ( v12 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error setting %d x %d x %d video mode", ArgList);
    return -1;
  }
  return 0;
}
