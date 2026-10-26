int __thiscall sub_6036F0(_DWORD *this, int *a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v7; // ecx
  int v8; // esi
  bool v9; // zf
  int *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v16; // [esp+0h] [ebp-18h]
  char v17; // [esp+4h] [ebp-14h]
  _DWORD v18[2]; // [esp+10h] [ebp-8h] BYREF

  v5 = *a2;
  v7 = *a2 & 0x10;
  if ( v7 )
  {
    switch ( a5 )
    {
      case 0:
        v8 = 0;
        break;
      case 1:
        v8 = 1;
        break;
      case 2:
        v8 = 2;
        break;
      case 3:
        v8 = 3;
        break;
      case 4:
        v8 = 4;
        break;
      case 5:
        v8 = 5;
        break;
      default:
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v8 = a3;
  }
  if ( a4 )
    LOBYTE(v5) = a4;
  if ( (v5 & 4) != 0 )
  {
    v9 = v7 == 0;
    v16 = 4;
    v10 = a2;
    if ( !v9 )
      goto LABEL_14;
    v13 = sub_5E7150(a2, 4);
    if ( !v13 )
      goto LABEL_29;
    v12 = (*(int (__stdcall **)(int, int, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v13 + 76))(v13, a3, v18, 0, 0);
    goto LABEL_27;
  }
  if ( (v5 & 8) == 0 )
  {
    if ( (v5 & 1) != 0 )
    {
      v9 = v7 == 0;
      v16 = 1;
      v10 = a2;
      if ( !v9 )
      {
LABEL_14:
        v11 = sub_5E7150(v10, v16);
        if ( v11 )
        {
          v12 = (*(int (__stdcall **)(int, int, int, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v11 + 76))(
                  v11,
                  v8,
                  a3,
                  v18,
                  0,
                  0);
          goto LABEL_27;
        }
LABEL_29:
        sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Invalid source surface specified for LockSurface", v17);
        return 0;
      }
    }
    else
    {
      if ( (v5 & 2) == 0 )
        goto LABEL_29;
      v9 = v7 == 0;
      v16 = 2;
      v10 = a2;
      if ( !v9 )
        goto LABEL_14;
    }
    v14 = sub_5E7120(v10, v16);
    if ( !v14 )
      goto LABEL_29;
    v12 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v14 + 52))(v14, v18, 0, 0);
LABEL_27:
    this[2] = v12;
    if ( !v12 )
    {
      a2[4] = v18[0];
      return v18[1];
    }
    goto LABEL_29;
  }
  sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Cannot lock video memory texture.", v17);
  return 0;
}
