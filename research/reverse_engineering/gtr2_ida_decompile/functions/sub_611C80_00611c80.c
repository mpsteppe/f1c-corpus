int __thiscall sub_611C80(_DWORD *this, int a2, int a3, int a4, int a5, char **a6, _DWORD *a7, int a8, char a9)
{
  bool v9; // zf
  char *v11; // edx
  int v12; // eax
  int v13; // edi
  char **v14; // eax
  char *v15; // esi
  int v16; // eax
  char **v17; // eax
  int v18; // edi
  _DWORD *v19; // eax
  char v21; // [esp-4h] [ebp-24h]
  _DWORD *v22; // [esp+10h] [ebp-10h]
  int v23; // [esp+24h] [ebp+4h]

  v9 = a2 == 0;
  v11 = (char *)a2;
  v22 = (_DWORD *)a2;
  v23 = a3;
  if ( v9 )
  {
    v22 = this + 168;
    v11 = (char *)(this + 168);
  }
  if ( a9 )
    v12 = this[172];
  else
    v12 = this[167];
  if ( a3 >= v12 )
    v23 = v12;
  v13 = a4;
  if ( a4 > v23 )
    v23 = a4;
  if ( a3 <= 0
    || (v14 = *(char ***)v11, v9 = *(_DWORD *)v11 == 0, *((_DWORD *)v11 + 2) = *(_DWORD *)v11, v9)
    || (v15 = *v14) == 0 )
  {
LABEL_21:
    v18 = 262146;
    if ( a9 )
      v18 = 262150;
    if ( *((char *)this + 4) < 0 )
      v18 |= 0x40u;
    v19 = operator new(0x50u);
    v15 = 0;
    if ( v19 )
      v15 = (char *)sub_60ADA0(v19);
    *(_DWORD *)v15 |= v18;
    if ( sub_60B2D0(v15, this[2387], v23, a5) )
    {
      nullsub_7(v15);
      j__free(v15);
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error creating new static vertex buffer", v21);
      return -1;
    }
    *((_DWORD *)v15 + 7) = a8;
    sub_5FDFB0(v22, (int)v15, 0);
    (*(void (__thiscall **)(_DWORD *, char *, _DWORD, _DWORD, int))(*this + 412))(this, v15, 0, 0, a5);
    v13 = a4;
  }
  else
  {
    while ( *((_DWORD *)v15 + 6) != a5
         || a9 && *((_DWORD *)v15 + 7) != a8
         || a4 > *((_DWORD *)v15 + 1) - *((_DWORD *)v15 + 2)
         || *v15 >= 0 )
    {
      v16 = *((_DWORD *)v11 + 2);
      if ( v16 )
      {
        v17 = *(char ***)(v16 + 4);
        *((_DWORD *)v11 + 2) = v17;
        if ( v17 )
        {
          v15 = *v17;
          if ( *v17 )
            continue;
        }
      }
      goto LABEL_21;
    }
  }
  ++*((_DWORD *)v15 + 3);
  if ( a6 )
    *a6 = v15;
  if ( a7 )
    *a7 = *((_DWORD *)v15 + 2);
  *((_DWORD *)v15 + 2) += v13;
  return 0;
}
