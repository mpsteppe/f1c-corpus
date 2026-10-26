int __thiscall sub_4D6060(_DWORD *this, int *a2, _DWORD *a3, int *a4, int *a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // edx
  int v8; // eax
  __int32 v9; // edx
  int *v10; // edi
  int v11; // ebx
  int v12; // ebp
  int v13; // edi
  int v14; // esi
  int v15; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  int v21; // ebp
  bool v22; // zf
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // [esp+0h] [ebp-30h]
  int v28; // [esp+4h] [ebp-2Ch]
  __int32 v29[5]; // [esp+14h] [ebp-1Ch] BYREF
  int v30; // [esp+28h] [ebp-8h]
  int v31; // [esp+2Ch] [ebp-4h]

  v8 = (*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
  v10 = (int *)v8;
  if ( v8 )
  {
    v17 = *(_DWORD *)(v8 + 8);
    v18 = this[3];
    v19 = this[1];
    v20 = v10[1] - *v10;
    v21 = v10[3] - v17;
    v22 = v10[1] == *v10;
    v31 = v18;
    v30 = v19;
    if ( v20 >= 0 && !v22 && v21 > 0 )
    {
      v23 = v10[7];
      if ( v23 )
      {
        v29[0] = 0;
        v28 = v19;
        v27 = v18;
        v24 = sub_4DDFE0(&unk_B6E2A0, v23);
        sub_4D5E10(this, v10[7], *v10, v10[2], v24, v27, v28, v20);
        sub_4E2B30(v20, v21);
        v25 = v30;
        *a2 = v30;
        *a3 = v25 + v21;
        v26 = v31 + v20;
        *a4 = v31;
        *a5 = v26;
      }
    }
    return 0;
  }
  else
  {
    v11 = this[3];
    v12 = this[1];
    v13 = this[4] - v11;
    v14 = this[2] - v12;
    if ( v13 > 0 && v14 > 0 )
    {
      v29[0] = v9;
      v5 = __readeflags();
      v6 = dword_16C6D68 + 1962887392;
      __writeeflags(v5);
      v15 = sub_4DDFE0(&unk_B6E2A0, _InterlockedExchange(v29, v6));
      sub_4DD980(&unk_B6E2A0, v15, v11, v12, v13, v14, v29[0]);
    }
    *a2 = v12;
    *a3 = v12 + v14;
    *a4 = v11;
    *a5 = v11 + v13;
    return 0;
  }
}
