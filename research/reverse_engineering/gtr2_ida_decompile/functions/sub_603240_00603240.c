int __thiscall sub_603240(_DWORD *this, int a2, int a3, int *a4, int a5, __int16 a6)
{
  int v7; // eax
  int v8; // ebp
  int v9; // edx
  bool v10; // zf
  int v11; // ebx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v16; // [esp+34h] [ebp-14h] BYREF
  int v17; // [esp+38h] [ebp-10h] BYREF
  int v18; // [esp+3Ch] [ebp-Ch]
  int v19; // [esp+40h] [ebp-8h]
  int v20; // [esp+44h] [ebp-4h] BYREF
  int v21; // [esp+5Ch] [ebp+14h]

  (*(void (__thiscall **)(_DWORD *, int *, _DWORD, _DWORD))(*this + 168))(this, &v20, *(_DWORD *)(a2 + 24), 0);
  v7 = *a4;
  v8 = (*a4 & 0x200) != 0 ? -16777216 : -65281;
  if ( a6 < 0 )
    return 0;
  v9 = *(_DWORD *)(a2 + 20);
  v18 = a4[5];
  v10 = (*(_BYTE *)a2 & 0x10) == 0;
  v19 = v9;
  v21 = 1;
  if ( !v10 && (v7 & 0x10) != 0 )
    v21 = 6;
  v11 = 0;
  while ( 1 )
  {
    v12 = 0;
    if ( v18 > 0 )
      break;
LABEL_17:
    if ( ++v11 >= v21 )
      return 0;
  }
  while ( 1 )
  {
    v13 = v19 - 1;
    if ( v12 < v19 - 1 )
      v13 = v12;
    if ( (*(int (__thiscall **)(_DWORD *, int, int *, int, int, int))(*this + 12))(this, a2, &v16, v13, a3, v11)
      || (*(int (__thiscall **)(_DWORD *, int *, int *, int, int, int))(*this + 12))(this, a4, &v17, v12, a5, v11) )
    {
      return -1;
    }
    v14 = sub_645971(v17, 0, 0, v16, 0, 0, 4, v8);
    this[2] = v14;
    if ( v14 )
    {
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x from D3DXLoadSurfaceFromSurface", v14);
      return -1;
    }
    if ( (*(_BYTE *)a2 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
    if ( (*(_BYTE *)a4 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
    if ( ++v12 >= v18 )
      goto LABEL_17;
  }
}
