char __thiscall sub_56DC20(_DWORD *this, int a2)
{
  double v3; // st7
  char *v4; // ebx
  char *v5; // eax
  void *v6; // eax
  _DWORD *v7; // ebp
  DWORD v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  bool v11; // zf
  char *v12; // eax
  int v13; // edx
  int v14; // ecx
  int *v15; // ecx

  v3 = sub_575000(this);
  v4 = (char *)a2;
  *(float *)(a2 + 48) = v3;
  *(float *)(a2 + 44) = v3;
  v5 = sub_56B290((char *)a2);
  sub_56C450(*(_DWORD *)v5, 1);
  v6 = (void *)this[687];
  v7 = this + 683;
  if ( v6 && ((v8 = WaitForSingleObject(v6, this[688])) == 0 || v8 == 128) )
    v9 = this + 683;
  else
    v9 = 0;
  while ( 1 )
  {
    v10 = (_DWORD *)*v9;
    v11 = *v9 == 0;
    v9[2] = *v9;
    if ( v11 || !*v10 )
      break;
    v12 = sub_56B280(v4);
    while ( (*(_DWORD *)(v13 + 4) != *((_DWORD *)v12 + 1) || *(_WORD *)(v13 + 2) != HIWORD(*(_DWORD *)v12))
         && (*(_DWORD *)(v13 + 20) != *((_DWORD *)v12 + 1) || *(_WORD *)(v13 + 18) != HIWORD(*(_DWORD *)v12)) )
    {
      v14 = v9[2];
      if ( v14 )
      {
        v15 = *(int **)(v14 + 4);
        v9[2] = v15;
        if ( v15 )
        {
          v13 = *v15;
          if ( *v15 )
            continue;
        }
      }
      v4 = (char *)a2;
      v7 = this + 683;
      goto LABEL_17;
    }
    sub_56DE40(v13, aDuplicateConne);
    v4 = (char *)a2;
    v7 = this + 683;
  }
LABEL_17:
  sub_5735F0(v4, 0);
  if ( v7[4] )
    ReleaseMutex((HANDLE)v7[4]);
  return 0;
}
