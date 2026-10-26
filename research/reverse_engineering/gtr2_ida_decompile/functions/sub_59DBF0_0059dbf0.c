char __thiscall sub_59DBF0(_DWORD *this, _DWORD *a2)
{
  char v3; // bl
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  void *v7; // eax
  _DWORD *v8; // ebp
  DWORD v9; // eax
  int **v10; // edi
  int *v11; // eax
  bool v12; // zf
  int v13; // esi
  int v14; // ecx
  int *v15; // eax
  int *v16; // eax
  _DWORD v18[4]; // [esp+10h] [ebp-10h] BYREF

  v3 = 0;
  htonl(0);
  htons(0);
  v4 = this[681];
  v18[0] = this[680];
  v5 = this[682];
  v18[1] = v4;
  v6 = this[683];
  v7 = (void *)this[701];
  v8 = this + 697;
  v18[2] = v5;
  v18[3] = v6;
  if ( v7 && ((v9 = WaitForSingleObject(v7, this[702])) == 0 || v9 == 128) )
    v10 = (int **)(this + 697);
  else
    v10 = 0;
  v11 = *v10;
  v12 = *v10 == 0;
  v10[2] = *v10;
  if ( !v12 )
  {
    v13 = *v11;
    if ( *v11 )
    {
      while ( 1 )
      {
        v14 = *(_DWORD *)(v13 + 28);
        if ( v14 )
        {
          if ( sub_59C230(v14, v18) )
            break;
        }
        v15 = v10[2];
        if ( v15 )
        {
          v16 = (int *)v15[1];
          v10[2] = v16;
          if ( v16 )
          {
            v13 = *v16;
            if ( *v16 )
              continue;
          }
        }
        goto LABEL_15;
      }
      *a2 = sub_5A6E90(v13);
      v3 = 1;
    }
  }
LABEL_15:
  if ( v8[4] )
    ReleaseMutex((HANDLE)v8[4]);
  return v3;
}
