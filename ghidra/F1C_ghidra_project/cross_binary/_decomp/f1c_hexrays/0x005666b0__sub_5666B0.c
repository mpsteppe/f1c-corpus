// f1c  0x005666b0  size=247
int __thiscall sub_5666B0(int this, int a2, const char *a3, signed int a4)
{
  unsigned int v5; // kr04_4
  signed int v6; // ebp
  signed int v7; // ebx
  int v8; // edi
  unsigned int v9; // eax
  _BYTE *v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // edi
  char *v14; // ebx
  signed int i; // eax
  _BYTE *v16; // ecx
  signed int j; // eax
  int v18; // ecx
  char v19; // dl
  unsigned int v21; // [esp+10h] [ebp-4h]

  v5 = strlen(a3) + 1;
  v6 = v5 - 1;
  if ( *(_DWORD *)this )
  {
    v21 = strlen(*(const char **)this);
    v7 = v21;
  }
  else
  {
    v7 = 0;
    v21 = 0;
  }
  v8 = a2;
  if ( a2 < 0 || a2 > v7 )
    return -1;
  if ( *(_DWORD *)this )
  {
    v11 = *(_DWORD *)(this + 4);
    if ( v11 < v11 + v6 )
    {
      v12 = a4;
      if ( v6 > a4 )
        v12 = v5 - 1;
      v13 = v11 + v12;
      v14 = (char *)sub_587C03(v11 + v12 + 1);
      strcpy(v14, *(const char **)this);
      sub_587BCF(*(LPVOID *)this);
      *(_DWORD *)this = v14;
      v7 = v21;
      *(_DWORD *)(this + 4) = v13;
      v8 = a2;
    }
  }
  else
  {
    v9 = a4;
    if ( v6 > a4 )
      v9 = v5 - 1;
    *(_DWORD *)(this + 4) = v9;
    v10 = (_BYTE *)sub_587C03(v9 + 1);
    *(_DWORD *)this = v10;
    *v10 = 0;
  }
  for ( i = v7; i >= v8; v16[v6] = *v16 )
  {
    v16 = (_BYTE *)(i + *(_DWORD *)this);
    --i;
  }
  for ( j = 0; j < v6; *(_BYTE *)(v18 + v8) = v19 )
  {
    v18 = j + *(_DWORD *)this;
    v19 = a3[j++];
  }
  return 0;
}
