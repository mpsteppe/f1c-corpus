int __usercall sub_4A24A0@<eax>(int *a1@<ecx>, int a2@<edi>)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  bool v7; // cc
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int *v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // [esp-8h] [ebp-14h]
  int v25; // [esp+4h] [ebp-8h] BYREF
  int v26; // [esp+8h] [ebp-4h] BYREF
  int retaddr; // [esp+Ch] [ebp+0h]

  if ( sub_49D1D0(a1) )
    return -1;
  sub_4AE870(&v25, &v26);
  v4 = a1[205];
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v6 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
        v7 = v25 <= v6;
        v8 = *a1;
        if ( !v7 )
        {
          (*(void (__thiscall **)(int *, int))(v8 + 44))(a1, 4);
          v9 = *a1;
          a1[209] = 0;
          (*(void (__thiscall **)(int *, _DWORD))(v9 + 176))(a1, 0);
LABEL_21:
          sub_4A1BB0(a1, 0);
          goto LABEL_22;
        }
        v10 = (*(int (__thiscall **)(int *))(v8 + 12))(a1);
        v11 = *a1;
        v24 = 3;
        v12 = a1;
        if ( v25 <= v10 )
        {
          (*(void (__thiscall **)(int *, int))(v11 + 44))(a1, 3);
          v13 = *a1;
          a1[209] = 0;
          (*(void (__thiscall **)(int *, int))(v13 + 176))(a1, 1);
          (*(void (__thiscall **)(int *))(*a1 + 172))(a1);
          sub_4A1BB0(a1, 1);
          goto LABEL_22;
        }
        goto LABEL_19;
      }
    }
    else
    {
      v14 = (*(int (__thiscall **)(int *, int))(*a1 + 4))(a1, a2);
      v15 = *a1;
      if ( v26 < v14 )
      {
        (*(void (__thiscall **)(int *, int))(v15 + 44))(a1, 3);
LABEL_20:
        v23 = *a1;
        a1[209] = 0;
        (*(void (__thiscall **)(int *))(v23 + 176))(a1);
        goto LABEL_21;
      }
      v7 = retaddr < (*(int (__thiscall **)(int *))(v15 + 12))(a1);
      v16 = *a1;
      if ( v7 )
      {
        (*(void (__thiscall **)(int *, int))(v16 + 44))(a1, 4);
        v17 = *a1;
        a1[209] = 0;
        (*(void (__thiscall **)(int *, int))(v17 + 176))(a1, 1);
        goto LABEL_21;
      }
      (*(void (__thiscall **)(int *, int))(v16 + 44))(a1, 4);
      v18 = *a1;
      a1[209] = 0;
      (*(void (__thiscall **)(int *, int))(v18 + 176))(a1, 1);
      (*(void (__thiscall **)(int *))(*a1 + 172))(a1);
      sub_4A1BB0(a1, 1);
    }
  }
  else
  {
    v19 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
    v7 = v25 < v19;
    v20 = *a1;
    if ( v7 )
    {
      (*(void (__thiscall **)(int *, int))(v20 + 44))(a1, 3);
      v21 = *a1;
      a1[209] = 0;
      (*(void (__thiscall **)(int *, _DWORD))(v21 + 176))(a1, 0);
      goto LABEL_21;
    }
    v22 = (*(int (__thiscall **)(int *))(v20 + 12))(a1);
    if ( v25 > v22 )
    {
      v11 = *a1;
      v24 = 4;
      v12 = a1;
LABEL_19:
      (*(void (__thiscall **)(int *, int, int))(v11 + 44))(v12, v24, a2);
      goto LABEL_20;
    }
  }
LABEL_22:
  if ( !(*(int (__thiscall **)(int *))(*a1 + 144))(a1) )
    sub_49D0F0(a1);
  return 0;
}
