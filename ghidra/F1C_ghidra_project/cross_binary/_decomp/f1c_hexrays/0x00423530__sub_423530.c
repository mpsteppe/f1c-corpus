// f1c  0x00423530  size=436
int __thiscall sub_423530(int *this, const char *a2, const char *a3)
{
  const char *v4; // ebx
  int v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // esi
  char *v13; // eax
  char *v14; // eax
  int v15; // eax
  void *v16; // ebx
  LPVOID *v17; // esi
  int v18; // edi
  _DWORD *v20; // [esp+10h] [ebp-4h]

  if ( !a2 )
    return -1;
  v4 = a3;
  if ( !a3 || !strlen(a2) || !strlen(a3) || !strcmp(a2, a3) )
    return -1;
  v5 = *this;
  if ( this[1] >= *this )
  {
    v6 = v5 + 128;
    *this = v5 + 128;
    v7 = (_DWORD *)sub_587C03(16 * (v5 + 128) + 4);
    if ( v7 )
    {
      v8 = v7 + 1;
      *v7 = v6;
      v9 = v7 + 1;
      if ( v6 - 1 >= 0 )
      {
        v10 = v6;
        do
        {
          *v9 = 0;
          v9[1] = -1;
          v9[2] = 0;
          v9[3] = -1;
          v9 += 4;
          --v10;
        }
        while ( v10 );
      }
      v20 = v8;
    }
    else
    {
      v20 = 0;
    }
    v11 = 0;
    if ( this[1] > 0 )
    {
      v12 = 0;
      do
      {
        v13 = *(char **)(v12 + this[2]);
        if ( !v13 )
          v13 = &byte_5EA438;
        sub_566650(v13);
        v14 = *(char **)(this[2] + v12 + 8);
        if ( !v14 )
          v14 = &byte_5EA438;
        sub_566650(v14);
        ++v11;
        v12 += 16;
      }
      while ( v11 < this[1] );
    }
    v15 = this[2];
    if ( v15 )
    {
      v16 = (void *)(v15 - 4);
      v17 = (LPVOID *)(v15 + 16 * *(_DWORD *)(v15 - 4));
      if ( *(_DWORD *)(v15 - 4) - 1 >= 0 )
      {
        v18 = *(_DWORD *)(v15 - 4);
        do
        {
          v17 -= 4;
          sub_414370(v17 + 2);
          sub_414370(v17);
          --v18;
        }
        while ( v18 );
      }
      sub_587BCF(v16);
    }
    v4 = a3;
    this[2] = (int)v20;
  }
  ++this[1];
  sub_566650(a2);
  sub_566650(v4);
  return 0;
}
