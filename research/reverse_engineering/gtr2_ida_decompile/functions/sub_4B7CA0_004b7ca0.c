int __userpurge sub_4B7CA0@<eax>(int *a1@<ecx>, int a2@<edi>, int a3, int a4, int a5, int a6)
{
  int v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  const char *v11; // edx
  unsigned int v12; // eax
  char *v13; // edi
  char *v15; // edi
  const char *v16; // esi
  char v17; // cl
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // ecx
  int v23; // esi
  int v24; // eax
  int v25; // edx
  int v27; // [esp-8h] [ebp-110h]
  int v29; // [esp-4h] [ebp-10Ch]
  char v30; // [esp+7h] [ebp-101h] BYREF
  char String2[32]; // [esp+8h] [ebp-100h] BYREF
  char v32[224]; // [esp+28h] [ebp-E0h] BYREF

  v7 = *a1;
  String2[0] = 0;
  (*(void (__thiscall **)(int *, char *, int))(v7 + 168))(a1, String2, 255);
  v8 = (const char *)a1[88];
  if ( !v8 )
    v8 = WindowName;
  if ( !_stricmp(v8, String2) )
  {
    sub_4CFC30(a1);
  }
  else
  {
    sub_4CFC70(a1);
    sub_4B77F0(a1 + 21);
    sub_615860(String2);
    v9 = &String2[strlen(String2)];
    if ( v9 > String2 )
    {
      while ( *v9 != 46 )
      {
        if ( --v9 <= String2 )
          goto LABEL_9;
      }
      *v9 = 0;
    }
LABEL_9:
    v10 = (const char *)a1[40];
    if ( !v10 )
      v10 = WindowName;
    v11 = v10;
    v12 = strlen(v10) + 1;
    v13 = &v30;
    while ( *++v13 )
      ;
    qmemcpy(v13, v11, 4 * (v12 >> 2));
    v16 = &v11[4 * (v12 >> 2)];
    v15 = &v13[4 * (v12 >> 2)];
    v17 = v12;
    v18 = *a1;
    qmemcpy(v15, v16, v17 & 3);
    (*(void (__thiscall **)(int *, int))(v18 + 172))(a1, a2);
    v19 = sub_4E0080(a1[12], v32, 0, 1, 1, 0, 0, 0, 0);
    v20 = v19;
    if ( v19 )
      sub_4E3DF0(v19);
    (*(void (__thiscall **)(int *))(*a1 + 176))(a1);
    if ( !v20 )
    {
      v25 = *a1;
      a1[85] = 0;
      (*(void (__thiscall **)(int *, _DWORD))(v25 + 44))(a1, 0);
      return 0;
    }
    sub_4D3B60(a1, v20, 1);
    v21 = a1[3];
    a1[85] = v20;
    v22 = *(_DWORD *)(v20 + 20);
    v23 = *(_DWORD *)(v20 + 24);
    a1[78] = v21;
    a1[79] = v22 + v21;
    v24 = a1[1];
    a1[80] = v24;
    a1[81] = v23 + v24;
    (*(void (__thiscall **)(int *, int, int, int))(*a1 + 44))(a1, 1, v27, v29);
  }
  return sub_4D6060(a3, a4, a5, a6);
}
