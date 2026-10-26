_DWORD *__userpurge sub_5C1290@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  _DWORD *v5; // ebp
  int i; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  void (__thiscall ***v10)(_DWORD, int); // ecx
  int v12; // [esp+8h] [ebp-30h]
  _DWORD *v13; // [esp+Ch] [ebp-2Ch]
  int v14; // [esp+10h] [ebp-28h]
  _DWORD *v15; // [esp+14h] [ebp-24h]
  int v16; // [esp+18h] [ebp-20h]
  char v17; // [esp+25h] [ebp-13h]
  void *v18; // [esp+28h] [ebp-10h]
  char v19; // [esp+30h] [ebp-8h]

  v18 = operator new(0x198u);
  v5 = 0;
  if ( v18 )
  {
    v16 = a3;
    v15 = a1 + 93;
    v5 = (_DWORD *)sub_5C0780();
  }
  v5[53] = a1[53];
  v5[54] = a1[54];
  v5[55] = a1[55];
  v5[56] = a1[56];
  v14 = a2;
  qmemcpy(v5 + 1, a1 + 1, 0x40u);
  qmemcpy(v5 + 17, a1 + 17, 0x40u);
  qmemcpy(v5 + 33, a1 + 33, 0x40u);
  v5[60] = a1[60];
  v5[61] = a1[61];
  v5[62] = a1[62];
  v5[57] = a1[57];
  v5[58] = a1[58];
  v5[59] = a1[59];
  v5[63] = a1[63];
  v5[64] = a1[64];
  v5[65] = a1[65];
  v5[97] = 0;
  v5[66] = a1[66];
  v5[67] = a1[67];
  v5[68] = a1[68];
  v5[49] = a1[49];
  v5[50] = a1[50];
  v5[51] = a1[51];
  v5[52] = a1[52];
  v5[69] = a1[69];
  v5[70] = a1[70];
  v5[71] = a1[71];
  v13 = a1 + 72;
  v5[101] = a1[101];
  sub_5C0690();
  v12 = (int)(a1 + 78);
  sub_5C0690();
  if ( (v19 & 1) != 0 )
  {
    for ( i = 0; i < a1[90]; ++i )
    {
      v7 = *(_DWORD *)(a1[92] + 4 * i);
      v12 = (*(int (__thiscall **)(int, _DWORD *, int, _DWORD *, int))(*(_DWORD *)v7 + 12))(v7, v13, v14, v15, v16);
      sub_5C0710();
    }
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD *, void *, int))(*v5 + 8))(v5, a1, v18, v12);
  if ( (v17 & 0x10) != 0 )
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(*v5 + 12))(v5, a1);
  v8 = a1[99];
  if ( v8 )
  {
    v9 = (*(int (__thiscall **)(int, _DWORD *))(*(_DWORD *)v8 + 24))(v8, v5);
    if ( v9 )
    {
      v10 = (void (__thiscall ***)(_DWORD, int))v5[99];
      if ( v10 )
        (**v10)(v10, 1);
      v5[99] = v9;
    }
  }
  return v5;
}
