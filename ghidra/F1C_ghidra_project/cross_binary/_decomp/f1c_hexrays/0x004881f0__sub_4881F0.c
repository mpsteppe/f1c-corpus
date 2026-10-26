// f1c  0x004881f0  size=273
int __thiscall sub_4881F0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int v8; // ebp
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ebp
  int v15; // eax
  int v17; // [esp-18h] [ebp-30h]
  int v18; // [esp-14h] [ebp-2Ch]
  int v19; // [esp-10h] [ebp-28h]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]

  v6 = (_DWORD *)(*(int (__thiscall **)(_DWORD *))(*this + 168))(this);
  v7 = v6;
  if ( v6 )
  {
    v13 = v6[1] - *v6;
    v14 = v6[3] - v6[2];
    v22 = this[3];
    v21 = this[1];
    if ( v13 > 0 && v14 > 0 && *(_DWORD *)(v6[8] + 12) )
    {
      v18 = this[1];
      v17 = this[3];
      v15 = sub_495150(&unk_7CDE00);
      sub_494A30(*(_DWORD *)(v7[8] + 12), *v7, v7[2], v15, v17, v18, v13, v14, 0, 0);
      sub_49AA70(v13, v14);
      *a2 = v21;
      *a3 = v21 + v14;
      *a4 = v22;
      *a5 = v22 + v13;
    }
  }
  else
  {
    v8 = this[3];
    v9 = this[1];
    v10 = this[4] - v8;
    v11 = this[2] - v9;
    v20 = v9;
    if ( v10 > 0 && v11 > 0 )
    {
      v19 = this[1];
      v12 = sub_495150(&unk_7CDE00);
      sub_494BF0(v12, v8, v19, v10, v11, 65793);
      v9 = v20;
    }
    *a2 = v9;
    *a3 = v9 + v11;
    *a4 = v8;
    *a5 = v8 + v10;
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  return 0;
}
