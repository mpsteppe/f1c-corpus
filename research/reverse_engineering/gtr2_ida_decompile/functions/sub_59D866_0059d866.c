// positive sp value has been detected, the output may be wrong!
char __fastcall sub_59D866(int a1, int a2, int a3, _DWORD *a4)
{
  void *v5; // eax
  void *v6; // ebp
  DWORD v7; // eax
  int **v8; // edi
  int *v9; // eax
  bool v10; // zf
  int v11; // esi
  int *v12; // eax
  int *v13; // eax
  DWORD v14; // eax
  int *v15; // eax
  int v16; // edi
  int *v17; // ebp
  char v18; // bl
  int i; // esi
  int v20; // ecx
  int v21; // eax
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // esi
  int v25; // eax
  int v26; // eax
  int *v27; // eax
  int v29; // [esp-608h] [ebp-618h]
  int **v30; // [esp-604h] [ebp-614h]
  void *v31; // [esp-600h] [ebp-610h]
  void *v32; // [esp-5FCh] [ebp-60Ch]
  void *v33; // [esp-5F8h] [ebp-608h] BYREF
  int v34; // [esp-5F4h] [ebp-604h] BYREF

  v34 = a1;
  sub_59C8D0();
  v5 = *(void **)(a1 + 2776);
  v6 = (void *)(a1 + 2760);
  v31 = (void *)(HIWORD(v34) + (unsigned __int16)v34 + 4);
  if ( a4 )
  {
    if ( v5 && ((v7 = WaitForSingleObject(v5, *((_DWORD *)v6 + 5))) == 0 || v7 == 128) )
      v8 = (int **)v6;
    else
      v8 = 0;
    v9 = *v8;
    v10 = *v8 == 0;
    v8[2] = *v8;
    if ( !v10 )
    {
      v11 = *v9;
      if ( *v9 )
      {
        while ( !sub_59C230(v11, a4) )
        {
          v12 = v8[2];
          if ( v12 )
          {
            v13 = (int *)v12[1];
            v8[2] = v13;
            if ( v13 )
            {
              v11 = *v13;
              if ( *v13 )
                continue;
            }
          }
          goto LABEL_42;
        }
        if ( (void *)sub_59CA30(v32, v11, (char *)&v34, (int)v31) != v31 )
          HIBYTE(v29) = 0;
      }
    }
  }
  else
  {
    v33 = v6;
    if ( v5 && ((v14 = WaitForSingleObject(v5, *((_DWORD *)v6 + 5))) == 0 || v14 == 128) )
      v30 = (int **)v6;
    else
      v30 = 0;
    v15 = *v30;
    v10 = *v30 == 0;
    v30[2] = *v30;
    if ( !v10 )
    {
      v16 = *v15;
      if ( *v15 )
      {
        do
        {
          v17 = *(int **)(a3 + 72);
          v18 = 0;
          for ( i = 0; ; ++i )
          {
            v20 = i;
            if ( i < 0 || i >= v17[5] )
              break;
            v21 = v17[2];
            if ( i > 0 )
            {
              while ( v21 )
              {
                v21 = *(_DWORD *)(v21 + 4);
                if ( --v20 <= 0 )
                  goto LABEL_29;
              }
              break;
            }
LABEL_29:
            if ( !v21 )
              break;
            v22 = *(_DWORD **)v21;
            if ( !v22 )
              break;
            if ( sub_59C230(v16, v22) )
              v18 = 1;
          }
          if ( v18
            || (v23 = *(_DWORD *)(v16 + 36)) != 0
            && (v24 = *v17, v25 = sub_5A6E90(v23), (*(unsigned __int8 (__thiscall **)(int *, int))(v24 + 16))(v17, v25)) )
          {
            sub_59CA30(v31, v16, (char *)&v33, (int)v30);
          }
          v26 = *(_DWORD *)(v29 + 8);
          if ( !v26 )
            break;
          v27 = *(int **)(v26 + 4);
          *(_DWORD *)(v29 + 8) = v27;
          if ( !v27 )
            break;
          v16 = *v27;
        }
        while ( *v27 );
        v6 = v32;
      }
    }
  }
LABEL_42:
  if ( *((_DWORD *)v6 + 4) )
    ReleaseMutex(*((HANDLE *)v6 + 4));
  return HIBYTE(v29);
}
