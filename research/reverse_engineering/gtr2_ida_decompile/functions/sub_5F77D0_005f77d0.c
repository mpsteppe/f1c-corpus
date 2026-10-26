int __thiscall sub_5F77D0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  _BYTE v12[12]; // [esp+8h] [ebp-10h] BYREF
  float v13; // [esp+14h] [ebp-4h]

  v4 = this[98];
  if ( !this[95] )
  {
    if ( (v4 & 0x20000) != 0 )
    {
      v9 = this[96];
      v10 = sub_5E8220(*(_DWORD **)(a3 + 4), 99);
      v11 = sub_5E80D0(*(_DWORD **)(a3 + 4), v9 + v10);
      (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 44))(
        dword_FB27A4,
        60,
        *(_DWORD *)(v11 + 108));
    }
    return 1;
  }
  if ( (v4 & 0x20000) != 0 )
  {
    v5 = this[96];
    v6 = sub_5E8220(*(_DWORD **)(a3 + 4), 99);
    v13 = *(float *)(sub_5E80D0(*(_DWORD **)(a3 + 4), v5 + v6) + 104);
    if ( v13 != flt_FB3F0C )
    {
      flt_FB3F0C = v13;
      (*(void (__stdcall **)(int, int, _BYTE *, int))(*(_DWORD *)dword_FB40C8 + 436))(dword_FB40C8, 4, v12, 1);
    }
  }
  if ( (this[98] & 0x40000) == 0 )
    return 1;
  v7 = 0;
  while ( *(float *)(v7 + 16461656) == *(float *)(v7 + 16465680) )
  {
    v7 += 4;
    if ( v7 >= 16 )
      return 1;
  }
  dword_FB3F10 = dword_FB2F58;
  dword_FB3F14 = dword_FB2F5C;
  dword_FB3F18 = dword_FB2F60;
  dword_FB3F1C = LODWORD(flt_FB2F64);
  (*(void (__stdcall **)(int, int, int *, int))(*(_DWORD *)dword_FB40C8 + 436))(dword_FB40C8, 5, &dword_FB2F58, 1);
  return 1;
}
