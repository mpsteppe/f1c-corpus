int __thiscall sub_605580(_DWORD *this, int a2, int a3, _DWORD *a4, int a5, unsigned int a6)
{
  int v7; // ebp
  int v8; // ebx
  int v9; // eax
  unsigned int v10; // edi
  int v12; // eax
  char v13; // [esp+4h] [ebp-30h]
  int v14; // [esp+14h] [ebp-20h]
  _BYTE v15[12]; // [esp+18h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+24h] [ebp-10h]
  int v17; // [esp+30h] [ebp-4h]

  v14 = 0;
  if ( (*a4 & 0x200) != 0 )
  {
    v14 = -65281;
    if ( a4[7] )
      v14 = a4[7];
  }
  v7 = a3;
  v8 = a2;
  v9 = sub_64479A(a2, a3, v15);
  this[2] = v9;
  if ( v9 )
  {
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error reading image file info", v13);
    return -1;
  }
  a3 = 0;
  v10 = a6;
  if ( a6 >= v16 )
    return 0;
  while ( v17 == 4 )
  {
    if ( sub_6033B0(this, v8, v7, a4, a5, v10, a3) )
    {
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error from LoadDDSImage", v13);
      return -1;
    }
LABEL_15:
    ++v10;
    ++a3;
    if ( v10 >= v16 )
      return 0;
  }
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int *, unsigned int, _DWORD, int))(*this + 12))(
         this,
         a4,
         &a2,
         v10,
         0,
         2) )
  {
    return -1;
  }
  v12 = sub_6458B7(a2, 0, 0, v8, v7, 0, 1, v14, v15);
  this[2] = v12;
  if ( !v12 )
  {
    if ( (a5 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)a2 + 8))(a2);
    goto LABEL_15;
  }
  sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x from D3DXLoadSurfaceFromSurface", v12);
  return -1;
}
