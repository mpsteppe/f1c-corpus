int __thiscall sub_6158D0(int this, int a2, const char *a3, signed int a4)
{
  signed int v5; // edi
  signed int v6; // ebx
  int v7; // ebp
  signed int v8; // eax
  _BYTE *v9; // eax
  int v10; // eax
  signed int v11; // ecx
  int v12; // ebx
  char *v13; // ebp
  signed int i; // eax
  char v15; // dl
  int v16; // ecx
  signed int j; // eax
  char v18; // dl
  int v19; // ecx
  unsigned int v21; // [esp+10h] [ebp-4h]

  v5 = strlen(a3);
  if ( *(_DWORD *)this )
  {
    v21 = strlen(*(const char **)this);
    v6 = v21;
  }
  else
  {
    v6 = 0;
    v21 = 0;
  }
  v7 = a2;
  if ( a2 < 0 || a2 > v6 )
    return -1;
  if ( *(_DWORD *)this )
  {
    v10 = *(_DWORD *)(this + 4);
    if ( v10 < v10 + v5 )
    {
      v11 = a4;
      if ( v5 > a4 )
        v11 = v5;
      v12 = v10 + v11;
      v13 = (char *)operator new(v10 + v11 + 1);
      strcpy(v13, *(const char **)this);
      j__free(*(void **)this);
      *(_DWORD *)this = v13;
      v7 = a2;
      *(_DWORD *)(this + 4) = v12;
      v6 = v21;
    }
  }
  else
  {
    v8 = a4;
    if ( v5 > a4 )
      v8 = v5;
    *(_DWORD *)(this + 4) = v8;
    v9 = operator new(v8 + 1);
    *(_DWORD *)this = v9;
    *v9 = 0;
  }
  for ( i = v6; i >= v7; *(_BYTE *)(v16 + v5) = v15 )
  {
    v15 = *(_BYTE *)(*(_DWORD *)this + i);
    v16 = i + *(_DWORD *)this;
    --i;
  }
  for ( j = 0; j < v5; *(_BYTE *)(v19 + v7) = v18 )
  {
    v18 = a3[j];
    v19 = j + *(_DWORD *)this;
    ++j;
  }
  return 0;
}
