int __thiscall sub_53FD40(int *this, _DWORD *a2, char a3, _DWORD *a4, char a5, int a6)
{
  _DWORD *v6; // edi
  _DWORD *v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  _DWORD *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp+10h] [ebp-8h] BYREF
  _BYTE v19[4]; // [esp+14h] [ebp-4h] BYREF

  v6 = a2;
  sub_55C650(v19, a2[12], 0);
  v8 = a4;
  v9 = (a4[6] & 0x800) != 0 ? -16777216 : -65281;
  if ( sub_53F720((int)this, a4, a4[11]) )
    return -1;
  if ( (a6 & 0x1000000) == 0 )
  {
    if ( (a3 & 4) != 0 && (v10 = v6[4]) != 0 || (a3 & 8) != 0 && (v10 = v6[5]) != 0 )
    {
      v11 = (*(int (__stdcall **)(int, _DWORD, _DWORD **))(*(_DWORD *)v10 + 60))(v10, 0, &a2);
      *this = v11;
      if ( v11 )
        return -1;
    }
    else if ( (a3 & 1) != 0 && v6[2] )
    {
      a2 = (_DWORD *)v6[2];
    }
    else
    {
      if ( (a3 & 2) == 0 )
        return -1;
      v13 = (_DWORD *)v6[3];
      if ( !v13 )
        return -1;
      a2 = v13;
    }
    if ( (a5 & 4) != 0 && (v14 = v8[4]) != 0 || (a5 & 8) != 0 && (v14 = v8[5]) != 0 )
    {
      v15 = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v14 + 60))(v14, 0, &v18);
      *this = v15;
      if ( v15 )
        return -1;
    }
    else
    {
      if ( (a5 & 1) == 0 || (v16 = v8[2]) == 0 )
      {
        if ( (a5 & 2) == 0 )
          return -1;
        v16 = v8[3];
        if ( !v16 )
          return -1;
      }
      v18 = v16;
    }
    v17 = SurfaceBlitOperation(v18, 0, 0, (int)a2, 0, 0, 4, v9);
    *this = v17;
    if ( v17 )
      return -1;
    if ( (a3 & 0xC) != 0 )
      (*(void (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
    if ( (a5 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
    if ( (int)v8[11] > 1 )
      D3DSurfaceCopyBlit(v8[4], 0, 0xFFFFFFFF, 5);
  }
  return 0;
}

