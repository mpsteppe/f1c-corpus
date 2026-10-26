int __thiscall sub_5F3690(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v5; // ecx
  int v6; // eax
  int result; // eax
  int v8; // ecx
  int v9; // eax
  _DWORD v10[6]; // [esp+8h] [ebp-18h] BYREF

  v2 = *(_DWORD *)(a2 + 100);
  v10[0] = *(_DWORD *)(a2 + 120);
  v3 = *(_DWORD *)(a2 + 104);
  v5 = *(_DWORD *)(a2 + 116);
  v10[2] = v2;
  v10[3] = v3;
  v6 = this[2387];
  v10[1] = v5;
  v10[4] = 0;
  v10[5] = 1065353216;
  this[2] = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v6 + 188))(v6, v10);
  result = this[1202];
  v8 = 3;
  if ( (*(_BYTE *)a2 & 0x10) == 0 )
    v8 = 2;
  if ( result != v8 )
  {
    v9 = this[2387];
    this[1202] = v8;
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 228))(v9, 22, v8);
    this[2] = result;
    this[192] &= ~4u;
  }
  return result;
}
