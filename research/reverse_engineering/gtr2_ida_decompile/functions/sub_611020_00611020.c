int __cdecl sub_611020(int a1, _DWORD *a2)
{
  int *v2; // ecx
  int *v3; // ebx
  int v4; // edx
  _DWORD *v5; // esi
  char *v6; // ebp
  int v7; // eax
  int **v8; // eax
  int *i; // eax
  int v10; // eax
  int **v11; // eax
  int **v12; // eax
  int *j; // eax
  int v14; // eax
  int **v15; // eax
  int **v16; // eax
  int *k; // eax
  int v18; // eax
  int **v19; // eax
  int v21; // [esp+2Ch] [ebp-38h]
  int v22; // [esp+38h] [ebp-2Ch]
  int v23; // [esp+54h] [ebp-10h] BYREF
  char *v24; // [esp+58h] [ebp-Ch] BYREF
  int v25; // [esp+5Ch] [ebp-8h] BYREF
  _DWORD *v26; // [esp+60h] [ebp-4h] BYREF

  v3 = v2;
  sub_5E4DD0(a2, &v24, &v23);
  sub_5E4DB0(a2, &v26, &v25);
  if ( !*((_BYTE *)v3 + 4844) )
  {
    v4 = *v3;
    *((_BYTE *)v3 + 4844) = 1;
    (*(void (__thiscall **)(int *, int, int))(v4 + 44))(v3, 136, 1);
  }
  v5 = v26;
  if ( (*v26 & 4) != 0 )
  {
    *v26 &= ~4u;
    v22 = (int)v5;
    (*(void (__thiscall **)(int *))(*v3 + 592))(v3);
  }
  if ( v3[2253] )
    (*(void (__thiscall **)(int *, int, int))(*v3 + 44))(v3, 28, 1);
  v21 = 0;
  (*(void (__thiscall **)(int *))(*v3 + 76))(v3);
  sub_5F6B80((int)v5, a2);
  sub_5F6310();
  v6 = v24;
  v7 = 0;
  v23 = 0;
  do
  {
    switch ( v7 )
    {
      case 0:
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD))(*v3 + 472))(v3, a2, 0);
        sub_5E54E0((int)a2, 1065353216, 1176256512);
        sub_5E5050((char *)a2, 262);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, _DWORD, int, char *))(*v3 + 72))(v3, v5, a2, 0, 1, v6);
        break;
      case 1:
        sub_5E54E0((int)a2, 1065353216, 1176256512);
        sub_5E5050((char *)a2, 262);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, int, _DWORD))(*v3 + 72))(v3, v5, a2, 1, 0);
        sub_5E54E0((int)a2, v21, (int)v6);
        sub_5E5050((char *)a2, 262);
        break;
      case 2:
        (*(void (__thiscall **)(int *, _DWORD *, int))(*v3 + 472))(v3, a2, 0x20000000);
        (*(void (__thiscall **)(int *, int))(*v3 + 76))(v3, 1);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, int, int, char *))(*v3 + 72))(v3, v5, a2, 2, 1, v6);
        if ( (*(_BYTE *)a2 & 0x20) != 0 )
        {
          v8 = (int **)v5[165];
          v5[167] = v8;
          if ( v8 )
          {
            for ( i = *v8; i; i = *v11 )
            {
              sub_5FDB90(i, *(float *)&v3, (int)v6, (int)a2, (int)v5, a2);
              v10 = v5[167];
              if ( !v10 )
                break;
              v11 = *(int ***)(v10 + 4);
              v5[167] = v11;
              if ( !v11 )
                break;
            }
          }
        }
        break;
      case 3:
        (*(void (__thiscall **)(int *, _DWORD))(*v3 + 76))(v3, 0);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, int, _DWORD, char *))(*v3 + 72))(v3, v5, a2, 3, 0, v6);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, _DWORD *))(*v3 + 64))(v3, v5 + 145, a2, v5);
        (*(void (__thiscall **)(int *, _DWORD *, _DWORD *))(*v3 + 60))(v3, v5, a2);
        if ( (*(_BYTE *)a2 & 0x20) != 0 )
        {
          v12 = (int **)v5[173];
          v5[175] = v12;
          if ( v12 )
          {
            for ( j = *v12; j; j = *v15 )
            {
              sub_5FDB90(j, *(float *)&v3, (int)v6, (int)a2, (int)v5, a2);
              v14 = v5[175];
              if ( !v14 )
                break;
              v15 = *(int ***)(v14 + 4);
              v5[175] = v15;
              if ( !v15 )
                break;
            }
          }
        }
        break;
      case 4:
        sub_610910(v3, (int)v3, v5, (char *)a2, v6, v21);
        if ( (*(_BYTE *)a2 & 0x20) != 0 )
        {
          v16 = (int **)v5[169];
          v5[171] = v16;
          if ( v16 )
          {
            for ( k = *v16; k; k = *v19 )
            {
              sub_5FDB90(k, *(float *)&v3, (int)v6, (int)a2, (int)v5, a2);
              v18 = v5[171];
              if ( !v18 )
                break;
              v19 = *(int ***)(v18 + 4);
              v5[171] = v19;
              if ( !v19 )
                break;
            }
          }
        }
        break;
      default:
        break;
    }
    v7 = ++v22;
  }
  while ( v22 <= 4 );
  (*(void (__thiscall **)(int *, int))(*v3 + 76))(v3, 1);
  return off_16C924C();
}
