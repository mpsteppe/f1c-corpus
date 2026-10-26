char __thiscall sub_59F510(char *this, int a2)
{
  int v3; // eax
  int v4; // edi
  void *v5; // eax
  int **v6; // ebp
  DWORD v7; // eax
  int *v8; // eax
  bool v9; // zf
  int v10; // edi
  int *v11; // eax
  int *v12; // eax
  int v13; // eax
  int *v14; // eax
  int v15; // edi
  int *v16; // eax
  int *v17; // eax
  int v18; // edi
  int v20; // [esp+32h] [ebp-58h]
  int v21; // [esp+32h] [ebp-58h]
  int v22; // [esp+36h] [ebp-54h]
  int v23; // [esp+36h] [ebp-54h]
  int v24; // [esp+3Ah] [ebp-50h]
  int v25; // [esp+3Ah] [ebp-50h]
  int v26; // [esp+3Eh] [ebp-4Ch]
  int v27; // [esp+3Eh] [ebp-4Ch]
  int v28; // [esp+42h] [ebp-48h]
  int v29; // [esp+42h] [ebp-48h]
  char v30; // [esp+58h] [ebp-32h]
  char v31; // [esp+59h] [ebp-31h]
  char v32; // [esp+5Ah] [ebp-30h]
  _DWORD v33[7]; // [esp+5Eh] [ebp-2Ch] BYREF
  int v34; // [esp+7Ah] [ebp-10h] BYREF
  int v35; // [esp+86h] [ebp-4h]

  v31 = 0;
  v30 = 0;
  sub_5A6CF0(v33, 0, 0, 0);
  v33[0] = &off_725FFC;
  v34 = 0;
  v3 = *(_DWORD *)this;
  v35 = 0;
  if ( (*(unsigned __int8 (__thiscall **)(char *, int, _DWORD *))(v3 + 212))(this, a2, v33) )
  {
    v4 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 88))(this);
    sub_5A6B10(v4, 0, 7, 1, 2, -1);
    (*(void (__thiscall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(v4 + 72) + 12))(
      *(_DWORD *)(v4 + 72),
      v34,
      v20,
      v22,
      v24,
      v26,
      v28);
    sub_59D860();
    (*(void (__thiscall **)(char *, int, int, _DWORD))(*(_DWORD *)this + 92))(this, v4, v4, 0);
    v5 = (void *)*((_DWORD *)this + 701);
    v6 = (int **)(this + 2788);
    if ( !v5 || (v7 = WaitForSingleObject(v5, *((_DWORD *)this + 702))) != 0 && v7 != 128 )
      v6 = 0;
    v8 = *v6;
    v9 = *v6 == 0;
    v6[2] = *v6;
    if ( !v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        while ( sub_5A6E90(v10) != a2 )
        {
          v11 = v6[2];
          if ( v11 )
          {
            v12 = (int *)v11[1];
            v6[2] = v12;
            if ( v12 )
            {
              v10 = *v12;
              if ( *v12 )
                continue;
            }
          }
          goto LABEL_18;
        }
        if ( sub_6442E0(v10) == 2 )
          v30 = 1;
        v13 = *(_DWORD *)(v10 + 28);
        if ( v13 )
        {
          *(_BYTE *)(v13 + 40) = 1;
          *(_DWORD *)(*(_DWORD *)(v10 + 28) + 36) = 0;
        }
        sub_40BAA0(v6, v10, 1);
        v31 = 1;
      }
    }
LABEL_18:
    v14 = *v6;
    v9 = *v6 == 0;
    v6[2] = *v6;
    if ( v9 )
      v15 = 0;
    else
      v15 = *v14;
    v32 = 0;
    if ( v15 )
    {
      do
      {
        sub_5A6EA0(v32);
        sub_5A6EC0(1);
        v16 = v6[2];
        ++v32;
        if ( !v16 )
          break;
        v17 = (int *)v16[1];
        v6[2] = v17;
        if ( !v17 )
          break;
      }
      while ( *v17 );
    }
    if ( *((_DWORD *)this + 701) )
      ReleaseMutex(*((HANDLE *)this + 701));
    if ( sub_5A4330(this) == 4 )
    {
      v18 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 88))(this);
      sub_5A6B10(v18, 0, 9, 1, 2, -1);
      sub_5A6970(&v34, 4);
      *(_BYTE *)(*(_DWORD *)(v18 + 72) + 4) = 1;
      sub_59D860();
      (*(void (__thiscall **)(char *, int, int, _DWORD, int, int, int, int, int))(*(_DWORD *)this + 92))(
        this,
        v18,
        v18,
        0,
        v21,
        v23,
        v25,
        v27,
        v29);
    }
    if ( v30 && sub_5A4330(this) == 3 )
      (*(void (__thiscall **)(char *))(*(_DWORD *)this + 116))(this);
  }
  v35 = -1;
  v33[0] = &off_725FFC;
  sub_5A6D70(v33);
  return v31;
}
