int __thiscall sub_53FED0(int *this, int a2, int a3, _DWORD *a4, int a5, int a6)
{
  _DWORD *v6; // esi
  int v7; // eax
  int v9; // eax
  int v10; // eax
  int v12; // ebp
  int v13; // ebx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  unsigned int v19; // [esp+10h] [ebp-20h]
  _DWORD v20[7]; // [esp+14h] [ebp-1Ch] BYREF

  v6 = a4;
  v7 = a4[6];
  v19 = 0;
  if ( (v7 & 0x800) != 0 )
  {
    v9 = a4[13];
    if ( v9 )
    {
      v19 = v9 | 0xFF000000;
      goto LABEL_6;
    }
  }
  else if ( ((unsigned int)&unk_800000 & v7) != 0 )
  {
    goto LABEL_6;
  }
  v19 = -65281;
LABEL_6:
  v10 = LockUnlockWrapper(a2, a3, (int)v20);
  *this = v10;
  if ( v10 )
    return -1;
  v12 = a6;
  v13 = a5;
  if ( !a6 )
  {
    v14 = v20[0];
    v6[8] = v20[1];
    v15 = v13 | v6[6];
    v6[7] = v14;
    v6[6] = v15;
    sub_55C450(v20[4], v6 + 9, v6 + 12);
    if ( sub_53F720((int)this, v6, v6[11]) )
      return -1;
  }
  if ( v13 == 4 )
  {
    v16 = (*(int (__stdcall **)(_DWORD, int, _DWORD **))(*(_DWORD *)v6[4] + 60))(v6[4], v12, &a4);
    *this = v16;
    if ( v16 )
      return -1;
  }
  else if ( v13 == 8 )
  {
    v17 = (*(int (__stdcall **)(_DWORD, int, _DWORD **))(*(_DWORD *)v6[5] + 60))(v6[5], v12, &a4);
    *this = v17;
    if ( v17 )
      return -1;
  }
  else if ( (v13 & 1) != 0 )
  {
    a4 = (_DWORD *)v6[2];
  }
  else if ( (v13 & 2) != 0 )
  {
    a4 = (_DWORD *)v6[3];
  }
  v18 = sub_5008E4((int)a4, 0, 0, a2, a3, 0, 1, v19, (int)v20);
  *this = v18;
  if ( v18 )
    return -1;
  if ( v13 == 4 || v13 == 8 )
    (*(void (__stdcall **)(_DWORD *))(*a4 + 8))(a4);
  return 0;
}

