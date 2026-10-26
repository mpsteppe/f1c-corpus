int __thiscall sub_603010(int this, int *a2, int *a3, int a4, int a5, int a6)
{
  int v6; // eax
  int v8; // edx
  int v10; // eax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char v17; // [esp+0h] [ebp-4h]

  LOBYTE(v6) = a5;
  if ( !a5 )
    v6 = *a2;
  v8 = *a2;
  if ( (*a2 & 0x2000) != 0 )
  {
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int *))(**(_DWORD **)(this + 9548) + 72))(
                              *(_DWORD *)(this + 9548),
                              0,
                              0,
                              0,
                              a3);
    return 0;
  }
  if ( (v6 & 0xC) != 0 )
  {
    if ( (v6 & 4) != 0 )
    {
      v10 = 4;
    }
    else
    {
      v11 = (v6 & 8) == 0;
      v10 = 8;
      if ( v11 )
        v10 = (int)a3;
    }
    if ( (v8 & 0x10) != 0 )
    {
      v12 = sub_5E7150(a2, v10);
      if ( !v12 )
        return 0;
      v13 = (*(int (__stdcall **)(int, int, int, int *))(*(_DWORD *)v12 + 72))(v12, a6, a4, a3);
    }
    else
    {
      v14 = sub_5E7150(a2, v10);
      if ( !v14 )
        return 0;
      v13 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v14 + 72))(v14, a4, a3);
    }
    *(_DWORD *)(this + 8) = v13;
    if ( !v13 )
      return 0;
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Invalid source MIP level specified for GetBestSurface", v17);
  }
  else if ( (v6 & 3) != 0 )
  {
    if ( (v6 & 1) != 0 )
    {
      v15 = 1;
    }
    else
    {
      v11 = (v6 & 2) == 0;
      v15 = 2;
      if ( v11 )
        v15 = (int)a3;
    }
    if ( (v8 & 0x10) == 0 )
    {
      v16 = sub_5E7120(a2, v15);
      *a3 = v16;
      if ( v16 )
        return 0;
    }
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Invalid source source specified for GetBestSurface", v17);
  }
  else
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Invalid source surface specified for GetBestSurface", v17);
  }
  return -1;
}
