void __usercall sub_5C0B97(int a1@<ecx>, _DWORD *a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // ecx
  void (__thiscall ***v8)(_DWORD); // ecx
  int *v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  void (__thiscall ***v13)(_DWORD, _DWORD); // ecx
  int *v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  void (__thiscall ***v18)(_DWORD, _DWORD); // ecx
  int *v19; // esi
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  void (__thiscall ***v23)(_DWORD); // ecx
  int v24; // [esp-10h] [ebp-34h]
  int v25; // [esp-10h] [ebp-34h]
  int v26; // [esp-10h] [ebp-34h]
  int v27; // [esp-10h] [ebp-34h]
  void *v28; // [esp+0h] [ebp-24h]
  int v29; // [esp+4h] [ebp-20h]
  int i; // [esp+4h] [ebp-20h]
  int v31; // [esp+8h] [ebp-1Ch]

  v31 = a4;
  v29 = a3;
  *(_DWORD *)a1 = &off_729D60;
  sub_5C0250((_DWORD *)a1);
  v5 = (_DWORD *)(a1 + 288);
  if ( *(_DWORD *)(a1 + 288) )
  {
    while ( 1 )
    {
      v6 = v5[2] + 8 * *v5 - 8;
      v7 = *(_DWORD *)(v6 + 4);
      *(_DWORD *)(v6 + 4) = 0;
      if ( v7 )
      {
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v7 + 4))(v7, v29, v31);
        v5 = (_DWORD *)(a1 + 288);
      }
      v8 = (void (__thiscall ***)(_DWORD))(v5[2] + 8 * --*v5);
      v28 = 0;
      (**v8)(v8);
      if ( !*a2 )
        break;
      v5 = a2;
    }
  }
  v9 = (int *)(a1 + 300);
  while ( *v9 )
  {
    v10 = *(_DWORD *)(a1 + 308);
    v11 = *(_DWORD *)(v10 + 8 * *v9 - 4);
    *(_DWORD *)(v10 + 8 * *v9 - 8 + 4) = 0;
    if ( v11 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(v11);
    v12 = *v9 - 1;
    v13 = (void (__thiscall ***)(_DWORD, _DWORD))(*(_DWORD *)(a1 + 308) + 8 * v12);
    *v9 = v12;
    (**v13)(v13, 0);
  }
  v14 = (int *)(a1 + 312);
  while ( *v14 )
  {
    v15 = *(_DWORD *)(a1 + 320) + 8 * *(_DWORD *)(a1 + 312) - 8;
    v16 = *(_DWORD *)(v15 + 4);
    *(_DWORD *)(v15 + 4) = 0;
    if ( v16 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 4))(v16);
    v17 = *v14 - 1;
    v18 = (void (__thiscall ***)(_DWORD, _DWORD))(*(_DWORD *)(a1 + 320) + 8 * v17);
    *v14 = v17;
    (**v18)(v18, 0);
  }
  v19 = (int *)(a1 + 324);
  while ( *v19 )
  {
    v20 = *(_DWORD *)(a1 + 332) + 8 * *(_DWORD *)(a1 + 324) - 8;
    v21 = *(_DWORD *)(v20 + 4);
    *(_DWORD *)(v20 + 4) = 0;
    if ( v21 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v21 + 4))(v21);
    v22 = *v19 - 1;
    *v19 = v22;
    (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)(a1 + 332) + 8 * v22))(*(_DWORD *)(a1 + 332) + 8 * v22, 0);
  }
  v23 = *(void (__thiscall ****)(_DWORD))(a1 + 396);
  if ( v23 )
  {
    v24 = 1;
    (**v23)(v23);
  }
  *(_DWORD *)(a1 + 336) = 0;
  *(_DWORD *)(a1 + 340) = 0;
  sub_4F14D0(v24);
  sub_5A8D10(*(void **)(a1 + 344));
  *(_DWORD *)(a1 + 344) = 0;
  sub_5A8840();
  sub_4F14D0(v25);
  sub_5A8D10(*(void **)(a1 + 368));
  for ( i = 0; i < *(_DWORD *)(a1 + 348); ++i )
    nullsub_7((void *)(*(_DWORD *)(a1 + 356) + 8 * i));
  sub_4F14D0(v26);
  sub_5A8D10(*(void **)(a1 + 356));
  sub_4F14D0(v27);
  sub_5A8D10(*(void **)(a1 + 344));
  sub_5BCCE0((void *)(a1 + 324));
  sub_5BCCE0((void *)(a1 + 312));
  sub_5BCCE0((void *)(a1 + 300));
  sub_5BCCE0(v28);
}
