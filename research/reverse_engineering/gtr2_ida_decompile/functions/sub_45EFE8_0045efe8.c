int __userpurge sub_45EFE8@<eax>(int a1@<eax>, _DWORD *a2@<ecx>, int a3@<edi>, int a4, int a5)
{
  int v6; // edx
  char *v7; // eax
  _DWORD *v8; // edi
  int v10; // ecx
  int v11; // eax
  _DWORD v12[6]; // [esp+0h] [ebp-50h] BYREF
  void *v13; // [esp+18h] [ebp-38h]
  _DWORD *v14; // [esp+1Ch] [ebp-34h]
  int v15; // [esp+20h] [ebp-30h]
  char *v16; // [esp+2Ch] [ebp-24h]
  int v17; // [esp+30h] [ebp-20h]
  char v18; // [esp+3Ch] [ebp-14h] BYREF

  a2[8] = 1028443341;
  a2[190] = a1;
  a2[9] = 1028443341;
  a2[191] = a1;
  a2[10] = 1028443341;
  a2[192] = a1;
  a2[11] = 1028443341;
  a2[193] = a1;
  a2[12] = 1028443341;
  a2[194] = a1;
  a2[13] = 1028443341;
  a2[195] = a1;
  a2[14] = 1028443341;
  a2[196] = a1;
  a2[15] = 1028443341;
  a2[197] = a1;
  if ( a2[189] != 20 )
  {
    dword_B6A3F0 = 0;
    if ( (*(int (__cdecl **)(int, int, int (__stdcall *)(const void *, int), int, int))(*(_DWORD *)dword_B69668 + 16))(
           dword_B69668,
           4,
           sub_45E800,
           20,
           1)
      || a2[189] != 20 )
    {
      return -1;
    }
  }
  v6 = *(_DWORD *)dword_B69668;
  v17 = 0;
  v16 = &v18;
  if ( (*(int (__cdecl **)(int, _DWORD *))(v6 + 12))(dword_B69668, a2 + 34) )
    return -1;
  v7 = v16;
  v15 = a3;
  v8 = a2 + 32;
  v14 = a2 + 32;
  v13 = &unk_726A04;
  a2[32] = 0;
  if ( (**(int (__cdecl ***)(char *, void *, _DWORD *))v7)(v7, v13, v14) )
    return -1;
  if ( !*v8 )
    return -1;
  (*(void (__cdecl **)(int))(*(_DWORD *)v15 + 8))(v15);
  (*(void (__cdecl **)(_DWORD))(*(_DWORD *)*v8 + 32))(*v8);
  if ( (*(int (__cdecl **)(_DWORD, void *))(*(_DWORD *)*v8 + 44))(*v8, &unk_7268BC) )
    return -1;
  if ( (*(int (__cdecl **)(_DWORD, char *, int))(*(_DWORD *)*v8 + 52))(*v8, v16, 9) )
    return -1;
  v10 = *v8;
  a2[178] = 44;
  if ( (*(int (__cdecl **)(int, _DWORD *))(*(_DWORD *)v10 + 12))(v10, a2 + 178) )
    return -1;
  v11 = *v8;
  v12[1] = 16;
  v12[0] = 20;
  memset(&v12[2], 0, 12);
  (*(void (__cdecl **)(int, int, _DWORD *))(*(_DWORD *)v11 + 24))(v11, 5, v12);
  (*(void (**)(void))(*(_DWORD *)*v8 + 28))();
  return sub_45DFC0((int)a2);
}
