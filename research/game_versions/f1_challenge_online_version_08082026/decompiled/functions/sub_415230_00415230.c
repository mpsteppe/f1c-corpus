int __thiscall sub_415230(char ****this, const char *a2, int a3)
{
  const char *v3; // ebx
  int result; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  char ***v10; // eax
  char **v11; // eax
  char *v12; // eax
  int v13; // ecx
  char ***v14; // eax
  char **v15; // eax
  char *v16; // eax
  _DWORD *v17; // eax
  int v18; // esi
  _DWORD *v19; // edi
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  LPVOID *v23; // edi
  int v24; // ebx
  int v25; // [esp+10h] [ebp-84h]
  char v26[128]; // [esp+14h] [ebp-80h] BYREF

  v3 = a2;
  result = -1;
  if ( !a2 )
    return result;
  v25 = (int)this[3];
  sub_4B0B20(v26, 127);
  if ( !strcmp(a2, v26) )
  {
    v6 = (char *)dword_7CE64C;
    if ( !dword_7CE64C )
      v6 = &byte_5EA438;
    sub_4C3F80(v6);
    v7 = sub_4C4080(&unk_8AC388);
    if ( v7 )
    {
      a2 = (const char *)(v7 + 188);
      v3 = (const char *)(v7 + 188);
    }
  }
  v8 = 0;
  if ( v25 <= 0 )
    return -1;
  do
  {
    v9 = v8;
    if ( v8 < 0 || v8 >= (int)this[3] )
      goto LABEL_14;
    v10 = *this;
    if ( v8 > 0 )
    {
      while ( v10 )
      {
        v10 = (char ***)v10[1];
        if ( --v9 <= 0 )
          goto LABEL_13;
      }
LABEL_14:
      v11 = 0;
      goto LABEL_16;
    }
LABEL_13:
    if ( !v10 )
      goto LABEL_14;
    v11 = *v10;
LABEL_16:
    v12 = *v11;
    if ( !v12 )
      v12 = &byte_5EA438;
    if ( sub_588410(v12, v3) )
      goto LABEL_30;
    v13 = v8;
    if ( v8 < 0 || v8 >= (int)this[3] )
      goto LABEL_25;
    v14 = *this;
    if ( v8 > 0 )
    {
      while ( v14 )
      {
        v14 = (char ***)v14[1];
        if ( --v13 <= 0 )
          goto LABEL_24;
      }
LABEL_25:
      v15 = 0;
      goto LABEL_27;
    }
LABEL_24:
    if ( !v14 )
      goto LABEL_25;
    v15 = *v14;
LABEL_27:
    v16 = *(char **)(dword_8AC394 + 1060 * (_DWORD)v15[2]);
    if ( !v16 )
      v16 = &byte_5EA438;
    if ( !sub_588410(v16, a3) )
      return v8;
LABEL_30:
    ++v8;
  }
  while ( v8 < v25 );
  v17 = (_DWORD *)sub_587C03(176);
  v18 = (int)v17;
  if ( v17 )
  {
    *v17 = 0;
    v17[1] = -1;
    v19 = v17 + 4;
    v20 = 2;
    do
    {
      sub_415520(v19);
      v19 += 5;
      --v20;
    }
    while ( v20 );
    sub_401000(v18 + 56, 20, 2, sub_415520);
    sub_401000(v18 + 96, 20, 2, sub_415520);
    sub_401000(v18 + 136, 20, 2, sub_415520);
    sub_4149A0(v18);
    v3 = a2;
  }
  else
  {
    v18 = 0;
  }
  sub_566650(v3);
  *(_DWORD *)(v18 + 8) = -1;
  if ( sub_414600((const char **)v18, 1) )
  {
    sub_4149A0(v18);
    v23 = (LPVOID *)(v18 + 176);
    v24 = 2;
    do
    {
      v23 -= 5;
      sub_414370(v23);
      --v24;
    }
    while ( v24 );
    sub_401030(v18 + 96, 20, 2, (int (__thiscall *)(int))sub_414370);
    sub_401030(v18 + 56, 20, 2, (int (__thiscall *)(int))sub_414370);
    sub_401030(v18 + 16, 20, 2, (int (__thiscall *)(int))sub_414370);
    sub_414370((LPVOID *)v18);
    sub_587BCF((LPVOID)v18);
    return -1;
  }
  v21 = sub_587C03(12);
  if ( v21 )
  {
    *(_DWORD *)v21 = v18;
    *(_DWORD *)(v21 + 4) = 0;
    *(_BYTE *)(v21 + 8) = 1;
  }
  else
  {
    v21 = 0;
  }
  if ( *this )
  {
    this[1][1] = (char **)v21;
  }
  else
  {
    *this = (char ***)v21;
    this[2] = (char ***)v21;
  }
  this[1] = (char ***)v21;
  v22 = (int)this[3] + 1;
  this[3] = (char ***)v22;
  return v22 - 1;
}
