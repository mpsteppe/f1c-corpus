char __userpurge sub_60E820@<al>(_DWORD *a1@<ecx>, int a2@<ebx>, _DWORD *a3, char *a4, char *a5)
{
  _DWORD *v5; // edi
  char *v7; // ebp
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // edx
  _DWORD **v11; // eax
  _DWORD *v12; // eax
  char *v13; // ebx
  int v14; // ecx
  int v15; // eax
  _DWORD **v16; // eax
  int v18; // [esp+4h] [ebp-18h]
  int v19; // [esp+8h] [ebp-14h]

  v5 = a3;
  if ( (*a3 & 0x10000) == 0 )
    return 0;
  v7 = a4;
  if ( (*a4 & 0x40) == 0 )
    return 0;
  v8 = (_DWORD *)a3[149];
  a3[151] = v8;
  if ( !v8 || !*v8 )
    return 0;
  sub_5E4DD0(v7, &a4, &a3);
  *(float *)&v19 = *(float *)&a3 + 0.001;
  *(float *)&v18 = *(float *)&a4 + 0.00050000002;
  sub_5E54E0((int)v7, v18, v19);
  sub_5E5050(v7, 262);
  (*(void (__thiscall **)(_DWORD *, int, int, int, int))(*a1 + 20))(a1, 2304, 393221, 127, a2);
  if ( !a1[2412] )
  {
    sub_609BF0(6);
    sub_60A000(1);
    sub_60A790(a1 + 257);
    v9 = (*(int (__thiscall **)(_DWORD *))(*a1 + 532))(a1);
    v10 = *a1;
    a1[1212] = 255 - v9;
    (*(void (__thiscall **)(_DWORD *, int, int))(v10 + 44))(a1, 60, 255 - v9);
  }
  sub_60A500(0);
  sub_60A3A0(a1 + 705, 1);
  sub_60A3F0(a1 + 705, 1);
  v11 = (_DWORD **)v5[149];
  v5[151] = v11;
  if ( v11 )
  {
    v12 = *v11;
    if ( v12 )
    {
      v13 = a5;
      do
      {
        if ( (*(_BYTE *)v12 & 4) != 0 )
          v14 = *(_DWORD *)(v12[16] + 44);
        else
          v14 = v12[11];
        sub_60E1A0(a1, v14, (int)v7, v13, v12);
        v15 = v5[151];
        if ( !v15 )
          break;
        v16 = *(_DWORD ***)(v15 + 4);
        v5[151] = v16;
        if ( !v16 )
          break;
        v12 = *v16;
      }
      while ( v12 );
    }
  }
  sub_5E54E0((int)v7, (int)a4, (int)a3);
  sub_5E5050(v7, 262);
  return 1;
}
