// positive sp value has been detected, the output may be wrong!
int __stdcall sub_5E9106(const char *a1, int a2)
{
  int result; // eax
  int v3; // ecx
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  int v7; // ebp
  char *v8; // ebx
  char *v9; // edi
  char *v10; // eax
  char v11; // cl
  bool v12; // [esp-1FDh] [ebp-20Dh]
  int v13; // [esp-1FCh] [ebp-20Ch]
  int v14; // [esp-1F4h] [ebp-204h]
  char v15[256]; // [esp-1F0h] [ebp-200h] BYREF
  char v16[256]; // [esp-F0h] [ebp-100h] BYREF

  strcpy(v16, a1);
  _strupr(v16);
  v12 = sub_5E8030(v16) == 0;
  dword_FB2D80 = (int)dword_FB2D78;
  if ( !dword_FB2D78 )
    return 0;
  result = *(_DWORD *)dword_FB2D78;
  v13 = *(_DWORD *)dword_FB2D78;
  if ( !*(_DWORD *)dword_FB2D78 )
    return 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(result + 212);
    v14 = v3;
    if ( v3 < a2 )
      goto LABEL_20;
    if ( v3 != 1 )
      break;
    v4 = (char *)(result + 140);
    v5 = (char *)(v15 - v4);
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 );
    if ( v12 )
      sub_5E8080(v15);
    if ( !strcmp(v15, v16) )
      return v13;
LABEL_20:
    dword_FB2D80 = *(_DWORD *)(dword_FB2D80 + 4);
    if ( !dword_FB2D80 )
      return 0;
    result = *(_DWORD *)dword_FB2D80;
    v13 = *(_DWORD *)dword_FB2D80;
    if ( !*(_DWORD *)dword_FB2D80 )
      return result;
  }
  v7 = 0;
  if ( v3 <= 0 )
    goto LABEL_20;
  v8 = (char *)(result + 140);
  v9 = &v15[-result - 140];
  while ( 1 )
  {
    v10 = v8;
    do
    {
      v11 = *v10;
      v10[(_DWORD)v9] = *v10;
      ++v10;
    }
    while ( v11 );
    if ( v12 )
      sub_5E8080(v15);
    if ( !strcmp(v15, v16) )
      return v13 + 216 * v7;
    ++v7;
    v9 -= 216;
    v8 += 216;
    if ( v7 >= v14 )
      goto LABEL_20;
  }
}
