unsigned int __usercall sub_5A03A0@<eax>(char *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  unsigned int result; // eax
  int v6; // edi
  void *v7; // eax
  DWORD (__stdcall *v8)(HANDLE, DWORD); // ebp
  DWORD v9; // eax
  int **v10; // edi
  int *v11; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  int *v16; // eax
  void *v17; // ebx
  void *v18; // eax
  DWORD v19; // eax
  int **v20; // edi
  int *v21; // eax
  int i; // eax
  int *v23; // eax
  void *v24; // eax
  _DWORD *v25; // esi
  DWORD v26; // eax
  _DWORD *v27; // ecx
  void *v28; // esi
  int v29; // [esp-20h] [ebp-24h]
  int v30; // [esp-1Ch] [ebp-20h]
  int v31; // [esp-18h] [ebp-1Ch]
  int v32; // [esp-14h] [ebp-18h]
  int v33; // [esp-10h] [ebp-14h]
  int v34; // [esp-10h] [ebp-14h]

  result = sub_5A4330(a1);
  if ( result >= 2 )
  {
    sub_5A42E0(a1, 0, a4, a3, a2);
    sub_5A4030(a1);
    v6 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)a1 + 88))(a1, v33);
    sub_5A6B10(v6, 0, 7, 1, 2, -1);
    *(_BYTE *)(*(_DWORD *)(v6 + 72) + 4) = 1;
    sub_59D860();
    (*(void (__thiscall **)(char *, int, int, _DWORD, int, int, int, int, int))(*(_DWORD *)a1 + 92))(
      a1,
      v6,
      v6,
      0,
      v29,
      v30,
      v31,
      v32,
      v34);
    sub_5A5A90(a1);
    sub_5A5BD0(a1);
    v7 = (void *)*((_DWORD *)a1 + 701);
    v8 = WaitForSingleObject;
    if ( v7 && ((v9 = WaitForSingleObject(v7, *((_DWORD *)a1 + 702))) == 0 || v9 == 128) )
      v10 = (int **)(a1 + 2788);
    else
      v10 = 0;
    v11 = *v10;
    v12 = *v10 == 0;
    v10[2] = *v10;
    if ( !v12 )
    {
      v13 = *v11;
      if ( v13 )
      {
        do
        {
          v14 = *(_DWORD *)a1;
          v15 = sub_5A6E90(v13);
          (*(void (__thiscall **)(char *, int))(v14 + 148))(a1, v15);
          v16 = *v10;
          v12 = *v10 == 0;
          v10[2] = *v10;
          if ( v12 )
            break;
          v13 = *v16;
        }
        while ( v13 );
        v8 = WaitForSingleObject;
      }
    }
    v17 = (void *)*((_DWORD *)a1 + 701);
    if ( v17 )
      ReleaseMutex(v17);
    v18 = (void *)*((_DWORD *)a1 + 694);
    if ( v18 && ((v19 = v8(v18, *((_DWORD *)a1 + 695))) == 0 || v19 == 128) )
      v20 = (int **)(a1 + 2760);
    else
      v20 = 0;
    v21 = *v20;
    v12 = *v20 == 0;
    v20[2] = *v20;
    if ( !v12 )
    {
      for ( i = *v21; i; i = *v23 )
      {
        sub_59FB30(a1, i, (int)"Leaving Current Session");
        v23 = *v20;
        v12 = *v20 == 0;
        v20[2] = *v20;
        if ( v12 )
          break;
      }
    }
    if ( *((_DWORD *)a1 + 694) )
      ReleaseMutex(*((HANDLE *)a1 + 694));
    v24 = (void *)*((_DWORD *)a1 + 404);
    v25 = a1 + 1588;
    if ( v24 && ((v26 = v8(v24, v25[8])) == 0 || v26 == 128) )
      v27 = v25;
    else
      v27 = 0;
    result = sub_5A6D80(v27);
    v28 = (void *)v25[7];
    if ( v28 )
      return ReleaseMutex(v28);
  }
  return result;
}
