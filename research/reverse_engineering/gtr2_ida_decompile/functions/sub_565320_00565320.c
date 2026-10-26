int __thiscall sub_565320(float *this)
{
  char *v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  unsigned int v6; // eax
  char *v7; // edi
  char *v9; // eax
  int v10; // [esp+8h] [ebp-94h]
  char *v11; // [esp+Ch] [ebp-90h]
  int v12; // [esp+10h] [ebp-8Ch]
  char Buffer[7]; // [esp+14h] [ebp-88h] BYREF
  char v14; // [esp+1Bh] [ebp-81h] BYREF
  _BYTE v15[127]; // [esp+1Ch] [ebp-80h] BYREF
  char v16; // [esp+9Bh] [ebp-1h]

  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_FB1D10;
  v2 = 0;
  v11 = 0;
  if ( sub_53A250(0) )
  {
    v3 = (_DWORD *)sub_616630(off_903BB0);
    if ( v3 )
      v2 = sub_48D380(v3);
    v4 = (_DWORD *)sub_616630(off_903BB4);
    if ( v4 )
      v11 = sub_48D380(v4);
    if ( v2 )
    {
      v5 = sub_41D840(&byte_91CC38, v2);
      sub_630FE0(v15, v5, 127);
      v16 = 0;
      v12 = 640;
      sub_562B70((int)v15, 640, 50, (int)byte_FFFFFF, 2, 0, 1.0, 1.0);
    }
  }
  sprintf(Buffer, "%c", byte_903BA4);
  v15[0] = 0;
  v10 = 16;
  do
  {
    v6 = strlen(Buffer) + 1;
    v7 = &v14;
    while ( *++v7 )
      ;
    qmemcpy(v7, Buffer, v6);
    --v10;
  }
  while ( v10 );
  sub_562B70((int)v15, v12, 90, (int)byte_FFFFFF, 2, 7, 1.0, 1.0);
  if ( v11 )
  {
    v9 = sub_41D840(&byte_91CC38, v11);
    sub_630FE0(v15, v9, 127);
    v16 = 0;
    sub_562B70((int)v15, 640, 130, (int)byte_FFFFFF, 2, 0, 1.0, 1.0);
  }
  return 0;
}
