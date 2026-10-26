// f1c  0x0057dd40  size=232
char __thiscall sub_57DD40(int **this, _DWORD *a2, int a3)
{
  int *v3; // eax
  int **v4; // edi
  char v5; // bl
  DWORD v6; // eax
  int **v7; // edx
  int *v8; // eax
  int v9; // ecx
  int *v10; // eax
  int *v11; // eax
  int v13; // edx
  int v14; // ecx

  v3 = this[687];
  v4 = this + 683;
  v5 = 0;
  if ( v3 && ((v6 = WaitForSingleObject(v3, (DWORD)this[688])) == 0 || v6 == 128) )
    v7 = v4;
  else
    v7 = 0;
  v8 = *v7;
  v7[2] = *v7;
  if ( v8 )
  {
    v9 = *v8;
    if ( *v8 )
    {
      while ( (*(_DWORD *)(v9 + 4) != a2[1] || *(_WORD *)(v9 + 2) != HIWORD(*a2))
           && (*(_DWORD *)(v9 + 20) != a2[1] || *(_WORD *)(v9 + 18) != HIWORD(*a2)) )
      {
        v10 = v7[2];
        if ( v10 )
        {
          v11 = (int *)v10[1];
          v7[2] = v11;
          if ( v11 )
          {
            v9 = *v11;
            if ( *v11 )
              continue;
          }
        }
        v5 = 0;
        goto LABEL_16;
      }
      sub_57B6C0((_DWORD *)v9, a3);
      *(_DWORD *)(v13 + 28) = v14;
      v5 = 1;
    }
  }
LABEL_16:
  if ( v4[4] )
    ReleaseMutex(v4[4]);
  return v5;
}
