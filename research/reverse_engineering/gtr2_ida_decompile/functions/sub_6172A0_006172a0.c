int __thiscall sub_6172A0(int this, void *a2, int a3)
{
  int v3; // esi
  int v5; // ebx
  unsigned int v6; // ecx
  unsigned int v8; // ebp
  _BYTE v9[1024]; // [esp+Ch] [ebp-400h] BYREF

  v3 = a3;
  v5 = sub_613CE0((_DWORD *)this, (int)v9, a3);
  if ( *(_BYTE *)(this + 92) )
  {
    v8 = v5;
    if ( v5 < a3 )
      v3 = v5;
    else
      v8 = a3;
    qmemcpy(
      a2,
      (const void *)(*(int (__thiscall **)(int, _BYTE *, int, _DWORD))(*(_DWORD *)(this + 96) + 24))(
                      this + 96,
                      v9,
                      v3,
                      *(unsigned __int8 *)(this + 132)),
      v8);
    return v5;
  }
  else
  {
    v6 = v5;
    if ( v5 >= a3 )
      v6 = a3;
    qmemcpy(a2, v9, v6);
    return v5;
  }
}
