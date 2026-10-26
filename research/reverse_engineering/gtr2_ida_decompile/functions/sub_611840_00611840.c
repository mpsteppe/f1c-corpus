void __thiscall sub_611840(_DWORD *this, int a2, _DWORD *a3)
{
  int v5; // ebx
  int v6; // ebp
  int v7; // ecx
  int v8; // ebp
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // [esp+28h] [ebp-8h]
  int v13; // [esp+2Ch] [ebp-4h]
  int *v14; // [esp+38h] [ebp+8h]

  v12 = 0;
  v13 = 65538;
  if ( a3 )
  {
    v5 = a3[16];
    v6 = sub_5E3450(*(_DWORD **)(v5 + 4), 0, 0);
    v14 = (int *)v6;
    if ( v6 )
    {
      if ( !(*(int (__thiscall **)(_DWORD *, int))(*this + 328))(this, v6) )
        return;
      v12 = 256;
      if ( (*a3 & 0x800) == 0 )
        v12 = 260;
      if ( (**(_BYTE **)(v5 + 4) & 0x40) != 0 )
        v12 |= 0x400u;
      if ( *(char *)(v6 + 136) < 0 )
      {
        v12 |= 1u;
        sub_60A000(3);
      }
      v7 = *(_DWORD *)(v5 + 4);
      if ( (*(_BYTE *)v7 & 0x20) != 0 )
      {
        v12 |= 0x800u;
        v13 = *(_DWORD *)(v7 + 236) | (*(_DWORD *)(v7 + 240) << 16);
        sub_60A000(2);
      }
    }
    v8 = *this;
    v9 = sub_5FC600(a3);
    (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v8 + 40))(this, 0, v9, 0, 0);
    (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 28))(this, v5, 0);
    v10 = (_DWORD *)sub_5FC600(a3);
    v11 = sub_5F7B60(v10, 0, 0);
    sub_5FA770(v11, a2, v5, 0);
    (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 20))(this, v12, v13, 63);
    sub_609BF0(7);
    sub_60A000(2);
    sub_60A790(this + 257);
    sub_60A820(this + 705, v14);
    sub_60A3A0(this + 705, 0);
    sub_60A3F0(this + 705, 0);
    this[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)this[2387] + 328))(
                this[2387],
                4,
                *(_DWORD *)(*(_DWORD *)(v5 + 44) + 8),
                0,
                a3[12] * a3[9],
                *(_DWORD *)(*(_DWORD *)(v5 + 48) + 8),
                a3[12] * a3[10] / 3);
  }
}
