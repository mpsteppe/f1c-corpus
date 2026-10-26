int __thiscall sub_6AE808(_DWORD *this)
{
  int *v2; // eax
  int v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int result; // eax
  unsigned int v8; // eax
  bool v9; // cf
  int v10; // [esp-14h] [ebp-70h]
  _DWORD v11[4]; // [esp+Ch] [ebp-50h] BYREF
  _DWORD v12[4]; // [esp+1Ch] [ebp-40h] BYREF
  _DWORD v13[4]; // [esp+2Ch] [ebp-30h] BYREF
  _DWORD v14[4]; // [esp+3Ch] [ebp-20h] BYREF
  int v15; // [esp+4Ch] [ebp-10h]
  int v16; // [esp+50h] [ebp-Ch]
  unsigned int v17; // [esp+54h] [ebp-8h]
  unsigned int i; // [esp+58h] [ebp-4h]

  v2 = (int *)this[64];
  v3 = *v2;
  v17 = v2[3];
  v4 = v2[4];
  v5 = v2[2];
  v15 = v4;
  v10 = this[63];
  v16 = v5;
  v6 = v3 & 0xFFFFF;
  result = (*(int (__thiscall **)(_DWORD *, int, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(this, v10, v13, 4, 0, 0);
  if ( result >= 0 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v8 = i;
      v9 = i < v17;
      v12[v8] = this[136];
      v11[v8] = this[137];
      if ( v9 )
        v14[v8] = v13[*(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v8 * 4 + v15)) + 16)];
    }
    sub_6CB29C(2, v14, v17, v16, v16 + 4 * v6, 0, v6, 0, &dword_1000000, 0, 0);
    return sub_6CB29C(88, v15, v17, v14, v11, v12, v6, 0, 0, 0, 0);
  }
  return result;
}
