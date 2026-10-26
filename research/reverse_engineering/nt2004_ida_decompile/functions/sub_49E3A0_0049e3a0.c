int __thiscall sub_49E3A0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int *v6; // eax
  int *v7; // edi
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  int v11; // esi
  int v12; // eax
  int v14; // ebx
  int v15; // ebp
  int v16; // eax
  char **v17; // [esp-18h] [ebp-30h]
  int v18; // [esp-14h] [ebp-2Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v6 = (int *)(*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
  v7 = v6;
  if ( v6 )
  {
    v14 = v6[1] - *v6;
    v15 = v6[3] - v6[2];
    v20 = this[3];
    v19 = this[1];
    if ( v14 > 0 && v15 > 0 && v6[7] )
    {
      v18 = this[1];
      v17 = (char **)this[3];
      v16 = sub_4AB570(&unk_765B00);
      sub_49CB80((char **)v7[7], *v7, v7[2], v16, v17, v18, v14, *(float *)&v15, 0, 0);
      sub_4B14A0(v14, v15);
      *a2 = v19;
      *a3 = v19 + v15;
      *a4 = v20;
      *a5 = v20 + v14;
    }
    return 0;
  }
  else
  {
    v8 = this[3];
    v9 = this[1];
    v10 = this[4] - v8;
    v11 = this[2] - v9;
    if ( v10 > 0 && v11 > 0 )
    {
      v12 = sub_4AB570(&unk_765B00);
      sub_4AB0E0(v12, v8, v9, v10, v11, 65793);
    }
    *a2 = v9;
    *a3 = v9 + v11;
    *a4 = v8;
    *a5 = v8 + v10;
    return 0;
  }
}
