int __thiscall sub_4D4BC0(_DWORD *this, int *a2, _DWORD *a3, int *a4, _DWORD *a5)
{
  int v5; // eax
  int v6; // ebx
  int v7; // edx
  int v8; // ebp
  int v9; // edi
  int *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  float v15; // [esp+0h] [ebp-34h]
  float v16; // [esp+4h] [ebp-30h]
  float v17; // [esp+8h] [ebp-2Ch]
  float v18; // [esp+Ch] [ebp-28h]
  int v19; // [esp+30h] [ebp-4h]

  v5 = dword_B6E198;
  v6 = this[1];
  v7 = this[2];
  v8 = this[4];
  v9 = this[3];
  v19 = v7;
  if ( dword_B6E198 )
  {
    if ( !this[67] )
    {
      if ( *(int *)(dword_B6E198 + 400) > 0 && (v10 = *(int **)(dword_B6E198 + 388)) != 0 )
        v11 = *v10;
      else
        v11 = 0;
      this[67] = v11;
      v5 = dword_B6E198;
    }
    if ( v5 && this[67] )
    {
      v18 = (double)(v7 - v6) * 0.0016666667;
      v17 = (double)(v8 - v9) * 0.00125;
      v16 = (double)v6 * 0.0016666667;
      v15 = (double)v9 * 0.00125;
      sub_5E53E0(v15, v16, v17, v18, 0x4000);
      sub_58F290(&unk_FB1E98);
      sub_5DCFA0(0);
      sub_58F2C0(&unk_FB1E98);
      v13 = sub_4DDFE0(&unk_B6E2A0, v12);
      sub_5E55E0(v13);
      sub_5E53E0(0.0, 0.0, 1.0, 1.0, 0x4000);
      sub_5E5050(286);
      v7 = v19;
    }
  }
  *a2 = v6;
  *a4 = v9;
  *a3 = v7;
  *a5 = v8;
  return 0;
}
