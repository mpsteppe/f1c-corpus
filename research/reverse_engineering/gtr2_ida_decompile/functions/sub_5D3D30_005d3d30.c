_DWORD *__userpurge sub_5D3D30@<eax>(int a1@<ecx>, int a2@<ebp>, int a3)
{
  _DWORD *v3; // ebx
  void *v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  _DWORD *v13; // eax
  _DWORD *v14; // ebp
  int v15; // ecx
  int v16; // eax
  int v17; // ebp
  int v18; // ecx
  int v20; // [esp-8h] [ebp-3Ch]
  int v21; // [esp+8h] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-28h]
  _UNKNOWN **v23; // [esp+14h] [ebp-20h] BYREF
  _DWORD *v24; // [esp+18h] [ebp-1Ch]
  _UNKNOWN **v25; // [esp+1Ch] [ebp-18h] BYREF
  int v26; // [esp+20h] [ebp-14h]
  int v27; // [esp+2Ch] [ebp-8h]
  int v28; // [esp+30h] [ebp-4h]
  _DWORD *retaddr; // [esp+34h] [ebp+0h]

  v3 = 0;
  v23 = 0;
  v5 = operator new(0x74u);
  v28 = 1;
  if ( v5 )
    v6 = sub_5D3BE0(v5, a1 + 4);
  else
    v6 = 0;
  LOBYTE(v27) = 0;
  v25 = &off_7296CC;
  v26 = 0;
  sub_5BD2D0(&v25, v6);
  v7 = v26;
  v27 = 2;
  if ( v26 )
    v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 12))(v26);
  else
    v8 = 0;
  *(_DWORD *)(v8 + 32) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(v8 + 36) = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v8 + 40) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(v8 + 44) = *(_DWORD *)(a1 + 44);
  *(_DWORD *)(v8 + 48) = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(v8 + 52) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(v8 + 56) = *(_DWORD *)(a1 + 56);
  *(_DWORD *)(v8 + 60) = *(_DWORD *)(a1 + 60);
  *(_DWORD *)(v8 + 64) = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(v8 + 68) = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(v8 + 72) = *(_DWORD *)(a1 + 72);
  *(_DWORD *)(v8 + 76) = *(_DWORD *)(a1 + 76);
  *(_DWORD *)(v8 + 80) = *(_DWORD *)(a1 + 80);
  *(_DWORD *)(v8 + 84) = *(_DWORD *)(a1 + 84);
  *(_DWORD *)(v8 + 88) = *(_DWORD *)(a1 + 88);
  *(_DWORD *)(v8 + 92) = *(_DWORD *)(a1 + 92);
  *(_DWORD *)(v8 + 96) = *(_DWORD *)(a1 + 96);
  *(_DWORD *)(v8 + 100) = *(_DWORD *)(a1 + 100);
  *(_DWORD *)(v8 + 104) = *(_DWORD *)(a1 + 104);
  *(_DWORD *)(v8 + 108) = *(_DWORD *)(a1 + 108);
  *(_BYTE *)(v8 + 112) = *(_BYTE *)(a1 + 112);
  *(_BYTE *)(v8 + 113) = *(_BYTE *)(a1 + 113);
  v22 = *(_DWORD *)(a1 + 20);
  v21 = 0;
  if ( v22 > 0 )
  {
    v20 = a2;
    v9 = v8 + 20;
    v23 = &off_72A3D0;
    do
    {
      v10 = *(_DWORD *)(a1 + 28) + 8 * v21;
      if ( *(_DWORD *)(v10 + 4) )
        v11 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 4) + 12))(*(_DWORD *)(v10 + 4));
      else
        v11 = 0;
      v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 4))(v11);
      if ( v12 )
      {
        v13 = operator new(0xCu);
        if ( v13 )
        {
          v13[2] = v12;
          v13[1] = 0;
          *v13 = off_72A438;
          v14 = v13;
          (*(void (__thiscall **)(_DWORD *))*v13)(v13);
        }
        else
        {
          v14 = 0;
        }
        v3 = v14;
      }
      v24 = v3;
      v15 = *(_DWORD *)(v9 + 4);
      v16 = *(_DWORD *)v9 + 1;
      LOBYTE(v27) = 3;
      *(_DWORD *)v9 = v16;
      if ( v15 < v16 )
      {
        v17 = v16 + 1;
        sub_4F14D0(v20);
        *(_DWORD *)(v9 + 8) = sub_5A8CF0(*(void **)(v9 + 8), 8 * v17, 2, 16, 2);
        *(_DWORD *)(v9 + 4) = v17;
      }
      sub_5C6B40((_DWORD *)v9, *(_DWORD *)v9 - 1, (int)&v23);
      LOBYTE(v27) = 2;
      v24 = 0;
      if ( v3 )
        (*(void (__thiscall **)(_DWORD *))(*v3 + 4))(v3);
      v3 = 0;
      ++v21;
    }
    while ( v21 < v22 );
    v7 = v26;
  }
  *retaddr = &off_7296CC;
  retaddr[1] = 0;
  if ( v7 )
    (**(void (__thiscall ***)(int))v7)(v7);
  v18 = retaddr[1];
  retaddr[1] = v7;
  if ( v18 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v18 + 4))(v18);
  LOBYTE(v27) = 0;
  if ( v7 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(v7);
  return retaddr;
}
