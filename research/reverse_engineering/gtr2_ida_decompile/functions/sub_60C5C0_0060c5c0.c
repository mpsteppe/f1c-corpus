int __thiscall sub_60C5C0(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // ebx
  unsigned int i; // edi
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int v20; // [esp+20h] [ebp-C4h]
  int v21; // [esp+20h] [ebp-C4h]
  int v22; // [esp+20h] [ebp-C4h]
  char String1[64]; // [esp+24h] [ebp-C0h] BYREF
  char v24[64]; // [esp+64h] [ebp-80h] BYREF
  char v25[64]; // [esp+A4h] [ebp-40h] BYREF

  strcpy(String1, (const char *)sub_5E8320(*(_DWORD **)(a2 + 4), 3));
  sub_5F6680(String1);
  if ( !strcmp(String1, "L2USEVERTEXPIXEL") )
  {
    *(_DWORD *)(a2 + 88) = 0;
  }
  else
  {
    v3 = this[30];
    if ( v3 == 1032 || v3 == 1028 )
    {
      v4 = (*(int (__thiscall **)(_DWORD *, char *, _DWORD))(*this + 632))(this, String1, 0);
      v5 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(a2 + 88) = v4;
      *(_DWORD *)(v5 + 252) = 3;
    }
  }
  if ( !*(_DWORD *)(a2 + 88) )
  {
    strcpy(v24, (const char *)sub_5E8320(*(_DWORD **)(a2 + 4), 2));
    sub_5F6680(v24);
    if ( !strcmp(v24, "L1USEVERTEXONLY") )
    {
      *(_DWORD *)(a2 + 88) = 0;
    }
    else if ( this[30] != 257 )
    {
      v6 = (*(int (__thiscall **)(_DWORD *, char *, _DWORD))(*this + 632))(this, v24, 0);
      v7 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(a2 + 88) = v6;
      *(_DWORD *)(v7 + 252) = 2;
    }
    if ( !*(_DWORD *)(a2 + 88) )
    {
      strcpy(v25, (const char *)sub_5E8320(*(_DWORD **)(a2 + 4), 1));
      sub_5F6680(v25);
      *(_DWORD *)(a2 + 88) = !strcmp(v25, "L0NOLIGHTING")
                           ? 0
                           : (*(int (__thiscall **)(_DWORD *, char *, _DWORD))(*this + 632))(this, v25, 0);
      *(_DWORD *)(*(_DWORD *)(a2 + 4) + 252) = 1;
      if ( !*(_DWORD *)(a2 + 88) )
      {
        if ( (*(_BYTE *)a2 & 8) != 0 )
          v8 = (*(int (__thiscall **)(_DWORD *, const char *, _DWORD))(*this + 632))(this, "L0BUMPT0", 0);
        else
          v8 = (*(int (__thiscall **)(_DWORD *, const char *, _DWORD))(*this + 632))(this, "L0DIFFUSET0", 0);
        v9 = *(_DWORD **)(a2 + 4);
        *(_DWORD *)(a2 + 88) = v8;
        sub_5E8260(v9, 1, 0);
        sub_5E82E0(*(_DWORD **)(a2 + 4), 1, 1);
        *(_DWORD *)(*(_DWORD *)(a2 + 4) + 252) = 1;
      }
    }
  }
  v10 = *(_DWORD *)(a2 + 4);
  if ( v10 && strstr((const char *)(v10 + 4), "RREFLECT") )
    sub_5F6260(a2);
  if ( *(_DWORD *)(sub_5F7B60(*(_DWORD **)(a2 + 88), 0, 0) + 344) != dword_FB4120 )
    *(_DWORD *)a2 &= ~4u;
  if ( sub_5F7BF0(*(_DWORD **)(a2 + 88), 0) )
  {
    v11 = sub_5E8220(*(_DWORD **)(a2 + 4), 99);
    v12 = sub_5E82A0(*(_DWORD **)(a2 + 4), 99);
    v13 = v11 + v12;
    for ( i = 0; v11 < v13; *(_DWORD *)(v18 + 148) = v22 )
    {
      v15 = (_DWORD *)sub_5F7BF0(*(_DWORD **)(a2 + 88), 0);
      v20 = *(_DWORD *)(sub_5F6520(v15, i) + 216);
      *(_DWORD *)(sub_5E80D0(*(_DWORD **)(a2 + 4), v11) + 140) = v20;
      v16 = (_DWORD *)sub_5F7BF0(*(_DWORD **)(a2 + 88), 0);
      v21 = *(_DWORD *)(sub_5F6520(v16, i) + 220);
      *(_DWORD *)(sub_5E80D0(*(_DWORD **)(a2 + 4), v11) + 144) = v21;
      v17 = (_DWORD *)sub_5F7BF0(*(_DWORD **)(a2 + 88), 0);
      v22 = *(_DWORD *)(sub_5F6520(v17, i) + 224);
      v18 = sub_5E80D0(*(_DWORD **)(a2 + 4), v11);
      ++i;
      ++v11;
    }
  }
  return 0;
}
