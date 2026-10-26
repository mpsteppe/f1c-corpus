_DWORD *__userpurge sub_5C3FD0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  int v4; // edi
  _DWORD *v5; // eax
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // ebp
  int v12; // eax
  int v13; // edi
  void *v14; // eax
  int v15; // ecx
  int v17; // [esp-4h] [ebp-18h]
  int v19; // [esp+10h] [ebp-4h]

  v4 = a1;
  v5 = operator new(0x14u);
  v6 = 0;
  if ( v5 )
  {
    *v5 = &off_729DB8;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = a3;
    v7 = v5;
  }
  else
  {
    v7 = 0;
  }
  v19 = *(_DWORD *)(v4 + 4);
  if ( v19 > 0 )
  {
    v17 = a2;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)(v4 + 12) + 4 * v6);
      v9 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 12))(v8, a3, a4);
      v10 = v7[2];
      v11 = v9;
      v12 = v7[1] + 1;
      v7[1] = v12;
      if ( v10 < v12 )
      {
        v13 = v12 + 1;
        sub_4F14D0(v17);
        v14 = sub_5A8CF0((void *)v7[3], 4 * v13, 2, 16, 2);
        v7[2] = v13;
        v4 = a1;
        v7[3] = v14;
      }
      v15 = v7[3];
      if ( v15 + 4 * v7[1] != 4 )
        *(_DWORD *)(v15 + 4 * v7[1] - 4) = v11;
      ++v6;
    }
    while ( v6 < v19 );
  }
  return v7;
}
