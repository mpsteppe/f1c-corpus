int __thiscall sub_5B5190(int *this, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v6; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  int result; // eax
  int v16; // eax
  bool v17; // cc
  int *v18; // ecx
  int v19; // ebp
  int v20; // eax
  int v21; // [esp+60h] [ebp-4Ch]
  _DWORD *v22; // [esp+64h] [ebp-48h]
  float *v23; // [esp+68h] [ebp-44h]
  _DWORD v24[8]; // [esp+6Ch] [ebp-40h] BYREF
  int v25; // [esp+8Ch] [ebp-20h]
  int v26; // [esp+90h] [ebp-1Ch]
  int v27; // [esp+98h] [ebp-14h]

  v5 = a3;
  v6 = *(_DWORD *)(a3 + 4);
  v22 = (_DWORD *)v6;
  sub_5A9F40(v24);
  if ( this[1292] )
  {
    v8 = this[1112];
    this[1292] = 0;
    *this = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v8 + 148))(v8, 256, this + 2078);
  }
  if ( this[2135] )
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 28, 1);
  if ( this[1290] != 1 )
  {
    v9 = this[1112];
    this[1290] = 1;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 200))(v9, 136, 1);
  }
  sub_5AAD80(this, 1);
  this[1140] = 256;
  if ( (*(_BYTE *)(v6 + 156) & 0x20) != 0 )
  {
    sub_5AAD80(this, 0);
    this[1140] |= 0x800u;
  }
  if ( (*(_BYTE *)(v6 + 156) & 0x40) != 0 )
    this[1140] |= 0x400u;
  if ( *(char *)(*(_DWORD *)(v6 + 176) + 64) < 0 )
    this[1140] |= 1u;
  sub_5AA930(this, this[1140], *(_DWORD *)(v6 + 180), *(_DWORD *)(*(_DWORD *)(v6 + 176) + 132));
  v10 = *(_DWORD *)(v6 + 172);
  v11 = 0;
  v21 = 0;
  if ( v10 > 0 )
  {
    while ( 1 )
    {
      v12 = 0;
      if ( v11 < v10 )
      {
        v13 = 148 * v11;
        v23 = (float *)&this[17 * v11 + 1142];
        while ( v12 < this[1284] )
        {
          v14 = sub_5A2870(v22, 0, v11);
          if ( v14 )
          {
            result = sub_5AB250((int)this, a2, v14);
            if ( !result )
              return result;
            v16 = *(_DWORD *)(v22[44] + v13 + 64);
            v25 = 7;
            v26 = 2;
            v27 = v14;
            if ( (v16 & 0x80u) != 0 )
              v26 = 3;
          }
          else
          {
            v25 = 0;
            v27 = 0;
          }
          sub_5AA830(v23, (int)v24, v12);
          v13 += 148;
          ++v12;
          v17 = v21 + 1 < v22[43];
          v23 += 17;
          v5 = a3;
          ++v21;
          if ( !v17 )
            break;
          v11 = v21;
        }
      }
      sub_5AA130(&this[17 * v12 + 1142], v12);
      sub_5AA8A0(this, *(_DWORD **)(v5 + 28));
      *this = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1112] + 340))(
                this[1112],
                *(_DWORD *)(*(_DWORD *)(v5 + 36) + 24),
                *(_DWORD *)(v5 + 44));
      if ( (*(_DWORD *)(v5 + 56) & 0x1000) != 0 )
        *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 200))(
                  this[1112],
                  47,
                  *(_DWORD *)(v5 + 60));
      v18 = (int *)this[1112];
      v19 = *v18;
      v20 = (*(_BYTE *)v5 & 0x10) != 0
          ? (*(int (__stdcall **)(int *, int, _DWORD, int, _DWORD, int))(v19 + 284))(
              v18,
              2,
              0,
              a4,
              *(_DWORD *)(v5 + 48),
              a5 / 2)
          : (*(int (__stdcall **)(int *, int, _DWORD, int, _DWORD, int))(v19 + 284))(
              v18,
              4,
              0,
              a4,
              *(_DWORD *)(v5 + 48),
              a5 / 3);
      *this = v20;
      if ( (*(_DWORD *)(v5 + 56) & 0x1000) != 0 )
        *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 200))(this[1112], 47, 0);
      v10 = v22[43];
      if ( v21 >= v10 )
        break;
      v11 = v21;
    }
  }
  result = this[2135];
  if ( result )
  {
    result = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 200))(this[1112], 28, 0);
    *this = result;
  }
  return result;
}
