int __thiscall sub_408CB0(char *this, const char *a2, int a3)
{
  char *v3; // edi
  char v4; // dl
  unsigned int v5; // ecx
  const char *v6; // esi
  char *v7; // edi
  char v8; // al
  unsigned int v9; // ecx
  void (__thiscall ***v10)(_DWORD, int, _DWORD); // esi
  int v12; // eax
  int v13; // edi
  int v14; // ebp
  void (__thiscall ***v15)(_DWORD, int, _DWORD); // [esp-4h] [ebp-60h]
  void *v16; // [esp+0h] [ebp-5Ch]
  int v17; // [esp+Ch] [ebp-50h]
  char **v18; // [esp+10h] [ebp-4Ch]
  void *Block; // [esp+18h] [ebp-44h]
  char (**v20)[4]; // [esp+20h] [ebp-3Ch] BYREF
  char *v21; // [esp+24h] [ebp-38h]
  unsigned int v22; // [esp+28h] [ebp-34h] BYREF
  int v23; // [esp+2Ch] [ebp-30h]
  _DWORD v24[3]; // [esp+30h] [ebp-2Ch] BYREF
  char *v25; // [esp+3Ch] [ebp-20h]
  unsigned int v26; // [esp+40h] [ebp-1Ch] BYREF
  int v27; // [esp+44h] [ebp-18h]
  int v28; // [esp+48h] [ebp-14h]
  int v29; // [esp+4Ch] [ebp-10h]
  void *v30; // [esp+50h] [ebp-Ch]
  int v31; // [esp+58h] [ebp-4h]

  v21 = this;
  v22 = 0;
  v23 = -1;
  v31 = 0;
  v20 = &off_757558;
  while ( 1 )
  {
    sub_615860((char *)*v20);
    sub_615A50(a2);
    v26 = (unsigned int)&off_6F197C;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    sub_5A8860(&v26, strlen(a2), 0);
    v3 = v25;
    if ( v25 )
    {
      v4 = v26;
      v5 = v26 >> 2;
      qmemcpy(v25, a2, 4 * (v26 >> 2));
      qmemcpy(&v3[4 * v5], &a2[4 * v5], v4 & 3);
    }
    v6 = (const char *)v20;
    LOBYTE(v30) = 1;
    if ( !v20 )
      v6 = WindowName;
    v22 = (unsigned int)&off_6F197C;
    v23 = 0;
    v24[0] = 0;
    v24[1] = 0;
    sub_5A8860(&v22, strlen(v6), 0);
    v7 = v21;
    if ( v21 )
    {
      v8 = v22;
      v9 = v22 >> 2;
      qmemcpy(v21, v6, 4 * (v22 >> 2));
      qmemcpy(&v7[4 * v9], &v6[4 * v9], v8 & 3);
    }
    LOBYTE(v28) = 2;
    sub_408560();
    v10 = (void (__thiscall ***)(_DWORD, int, _DWORD))sub_5BF900(&v20, v24, 0);
    LOBYTE(v28) = 1;
    sub_5A8840(&v20);
    LOBYTE(v28) = 0;
    sub_5A8840(v24);
    if ( v10 )
      break;
    if ( (int)++v18 >= (int)&off_75756C )
    {
      if ( Block )
      {
        j_j__free(Block);
        return 0;
      }
      return 0;
    }
  }
  v30 = operator new(0x38u);
  LOBYTE(v28) = 3;
  if ( v30 )
  {
    v15 = v10;
    v12 = sub_4066C0();
    v29 = v12;
  }
  else
  {
    v30 = 0;
    v12 = 0;
  }
  LOBYTE(v27) = 0;
  v17 = v12;
  if ( !v12 )
  {
    (**v10)(v10, 1, v15);
    if ( v18 )
      j_j__free(v18);
    return 0;
  }
  if ( (_BYTE)v30 )
    sub_405580();
  v13 = *(_DWORD *)(v17 + 20);
  v14 = sub_4055D0();
  sub_408B90();
  *(_DWORD *)(v13 + 4) = v14;
  **(_DWORD **)(v14 + 4) = v14;
  if ( v16 )
    j_j__free(v16);
  return v24[2];
}
