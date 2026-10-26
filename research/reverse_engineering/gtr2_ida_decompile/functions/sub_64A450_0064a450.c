int __thiscall sub_64A450(int this, unsigned __int8 *a2, unsigned int a3, _DWORD *a4, int a5)
{
  _DWORD *v6; // esi
  char *v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  void *v12; // ecx
  void *v13; // ecx
  bool v14; // cf
  _DWORD *i; // eax
  _DWORD *v17; // eax
  int v18; // edx
  _DWORD v19[9]; // [esp+Ch] [ebp-2Ch]
  char *Locale; // [esp+30h] [ebp-8h]
  int v21; // [esp+34h] [ebp-4h]

  if ( !a2 || !a3 )
    return -2005530516;
  v6 = a4;
  if ( a4 || a5 )
  {
    v19[0] = 0;
    v19[1] = 5;
    v19[2] = 4;
    v19[3] = 1;
    v19[4] = 3;
    v19[5] = 8;
    v19[6] = 7;
    v19[7] = 2;
    v19[8] = 6;
    v7 = setlocale(4, 0);
    v8 = _strdup(v7);
    Locale = v8;
    if ( !v8 || (v6 = a4, strcmp(v8, "C")) )
      setlocale(4, "C");
    v21 = 0;
    v9 = a3;
    do
    {
      *(_DWORD *)(this + 64) = a5;
      v10 = v19[v21];
      *(_DWORD *)(this + 68) = 3;
      *(_DWORD *)(this + 72) = v10;
      switch ( v10 )
      {
        case 0:
          v11 = sub_6493EF((int *)this, (int)a2, a3);
          goto LABEL_19;
        case 1:
          v11 = sub_6477EA((_DWORD *)this, (int)a2, a3);
          goto LABEL_19;
        case 2:
          v11 = sub_647CB3((int *)this, a2, a3);
          goto LABEL_19;
        case 3:
          v11 = sub_648787((int *)this, (int)a2, a3);
          goto LABEL_19;
        case 4:
          v11 = sub_648CDA((_DWORD *)this, (int)a2, a3);
          goto LABEL_19;
        case 5:
          v11 = sub_648285((_DWORD *)this, a2, a3);
          goto LABEL_19;
        case 6:
          v11 = sub_646667((int *)this, (int)a2, a3);
          goto LABEL_19;
        case 7:
          v11 = sub_649CC7((void *)this, a2, a3);
          goto LABEL_19;
        case 8:
          v11 = sub_649469((_DWORD *)this, (char *)a2, a3);
LABEL_19:
          v9 = v11;
          break;
        default:
          break;
      }
      if ( v9 >= 0 )
        break;
      if ( *(_DWORD *)(this + 4) && *(_DWORD *)(this + 56) )
        j__free(*(void **)(this + 4));
      if ( *(_DWORD *)(this + 8) && *(_DWORD *)(this + 60) )
        j__free(*(void **)(this + 8));
      v12 = *(void **)(this + 76);
      if ( v12 )
        sub_64651B(v12, 1);
      v13 = *(void **)(this + 80);
      if ( v13 )
        sub_64651B(v13, 1);
      v14 = (unsigned int)++v21 < 9;
      *(_DWORD *)(this + 4) = 0;
      *(_DWORD *)(this + 8) = 0;
      *(_DWORD *)(this + 56) = 0;
      *(_DWORD *)(this + 60) = 0;
      *(_DWORD *)(this + 76) = 0;
      *(_DWORD *)(this + 80) = 0;
    }
    while ( v14 );
    if ( Locale )
    {
      if ( strcmp(Locale, "C") )
        setlocale(4, Locale);
      free(Locale);
      v6 = a4;
    }
    if ( v21 == 9 )
      return -2005529767;
    if ( v6 )
    {
      memset(v6, 0, 0x1Cu);
      *v6 = *(_DWORD *)(this + 12);
      v6[1] = *(_DWORD *)(this + 16);
      v6[2] = *(_DWORD *)(this + 20);
      v6[3] = 1;
      v6[4] = sub_644779(*(_DWORD *)this);
      v6[5] = *(_DWORD *)(this + 68);
      v6[6] = *(_DWORD *)(this + 72);
      for ( i = (_DWORD *)(this + 76); *i; i = (_DWORD *)(*i + 76) )
        ++v6[3];
    }
    do
    {
      v17 = (_DWORD *)this;
      if ( this )
      {
        do
        {
          v17[8] = v17[3];
          v17[9] = v17[4];
          v18 = v17[5];
          v17[6] = 0;
          v17[7] = 0;
          v17[10] = 0;
          v17[11] = v18;
          v17 = (_DWORD *)v17[19];
        }
        while ( v17 );
      }
      this = *(_DWORD *)(this + 80);
    }
    while ( this );
  }
  return 0;
}
