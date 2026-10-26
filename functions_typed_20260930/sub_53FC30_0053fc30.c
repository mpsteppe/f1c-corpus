int __thiscall sub_53FC30(int *this, _DWORD *a2, _DWORD *a3, int a4)
{
  int v4; // eax
  int v5; // edi
  int v7; // ecx
  int v8; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp+Ch] [ebp-4h] BYREF

  v4 = a2[6];
  v5 = a4;
  if ( (v4 & 4) != 0 && (v7 = a2[4]) != 0 || (v4 & 8) != 0 && (v7 = a2[5]) != 0 )
  {
    v8 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v7 + 60))(v7, a4, &a4);
    *this = v8;
    if ( v8 )
      return -1;
  }
  else if ( (v4 & 1) != 0 && a2[2] )
  {
    a4 = a2[2];
  }
  else
  {
    if ( (v4 & 2) == 0 || !a2[3] )
      return -1;
    a4 = a2[3];
  }
  v10 = a3[6];
  if ( (v10 & 4) != 0 && (v11 = a3[4]) != 0 || (v10 & 8) != 0 && (v11 = a3[5]) != 0 )
  {
    v12 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v11 + 60))(v11, v5, &v15);
    *this = v12;
    if ( v12 )
      return -1;
  }
  else
  {
    if ( (v10 & 1) == 0 || (v13 = a3[2]) == 0 )
    {
      if ( (v10 & 2) == 0 )
        return -1;
      v13 = a3[3];
      if ( !v13 )
        return -1;
    }
    v15 = v13;
  }
  v14 = SurfaceBlitOperation(v15, 0, 0, a4, 0, 0, 1, 0);
  *this = v14;
  if ( v14 )
    return -1;
  if ( (a2[6] & 0xC) != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 8))(a4);
  if ( (a3[6] & 0xC) != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(v15);
  return 0;
}

