int __thiscall sub_60D5E0(_DWORD *this, int *a2)
{
  int *v2; // esi
  int v4; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int i; // edi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp+4h] [ebp-18h]
  char v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+18h] [ebp-4h] BYREF

  v2 = a2;
  v4 = 0;
  if ( sub_5E7150(a2, 8) )
    return -2;
  (*(void (__thiscall **)(_DWORD *, int **, int, _DWORD))(*this + 168))(this, &a2, v2[6], 0);
  if ( (*v2 & 0x40) != 0 )
  {
    if ( (*v2 & 0x40000) == 0
      && !v2[29]
      && (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, _DWORD))(*this + 244))(this, 0, v2, 0, 0) )
    {
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error creating z buffer for texture cache surface", v16);
      return -1;
    }
    v4 = 1;
  }
  if ( (*(_BYTE *)v2 & 0x10) == 0 )
  {
    v11 = v2[5];
    if ( v11 <= 1 )
      v11 = 1;
    v12 = sub_644DB8(this[2387], v2[1], v2[2], v11, v4, a2, 0, &v17);
    this[2] = v12;
    if ( !v12 )
    {
      v13 = sub_5E7150(v2, 4);
      v14 = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v13 + 84))(v13, 0);
      v15 = v17;
      this[2] = v14;
      sub_5E71A0(v2, v15, 8);
      *v2 |= 8u;
      return 0;
    }
LABEL_21:
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error creating texture cache surface", v16);
    return -1;
  }
  v6 = v2[5];
  if ( v6 <= 1 )
    v6 = 1;
  v7 = v2[2];
  if ( v2[1] > v7 )
    v7 = v2[1];
  v8 = sub_644E28(this[2387], v7, v6, v4, a2, 0, &v17);
  this[2] = v8;
  if ( v8 )
    goto LABEL_21;
  for ( i = 0; i < 6; ++i )
  {
    v10 = sub_5E7150(v2, 4);
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v10 + 84))(v10, i, 0);
  }
  sub_5E71A0(v2, v17, 8);
  *v2 |= 8u;
  return 0;
}
