int __thiscall sub_602F60(_DWORD *this, int *a2, _DWORD *a3, int a4, int a5)
{
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v11; // edx
  int v12; // eax
  char v13; // [esp+0h] [ebp-4h]

  LOBYTE(v5) = a5;
  if ( !a5 )
    v5 = *a2;
  if ( (*(_BYTE *)a2 & 0x20) == 0 )
    goto LABEL_21;
  if ( (v5 & 0xC) != 0 )
  {
    if ( (v5 & 4) != 0 )
    {
      v7 = 4;
    }
    else
    {
      v7 = 8;
      if ( (v5 & 8) == 0 )
        v7 = (int)a3;
    }
    if ( (v5 & 0x20) != 0 )
    {
      v8 = sub_6CE7B0(v7);
      if ( v8 )
      {
        v9 = (*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v8 + 72))(v8, a4, a3);
        this[2] = v9;
        if ( !v9 )
          return 0;
        goto LABEL_20;
      }
    }
LABEL_21:
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Invalid source surface specified for GetBestSurface", v13);
    return -1;
  }
  if ( (v5 & 3) == 0 )
    goto LABEL_21;
  if ( (v5 & 1) != 0 )
  {
    v11 = 1;
  }
  else
  {
    v11 = 2;
    if ( (v5 & 2) == 0 )
      v11 = (int)a3;
  }
  if ( (v5 & 0x20) == 0 )
    goto LABEL_21;
  v12 = sub_6CE7B0(v11);
  *a3 = v12;
  if ( v12 )
    return 0;
LABEL_20:
  sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Invalid source MIP level specified for GetBestSurface", v13);
  return -1;
}
