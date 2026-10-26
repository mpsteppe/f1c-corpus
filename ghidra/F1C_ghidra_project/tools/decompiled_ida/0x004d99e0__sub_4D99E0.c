// Address: 0x004d99e0
// Size: 554 bytes
// Name: sub_4D99E0
// Type: int __thiscall(float *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4D99E0(float *this)
{
  const char *v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  char v7; // cl
  int v8; // [esp+4h] [ebp-94h]
  int v9; // [esp+8h] [ebp-90h]
  const char *v10; // [esp+Ch] [ebp-8Ch]
  char v11[8]; // [esp+10h] [ebp-88h] BYREF
  char v12[127]; // [esp+18h] [ebp-80h] BYREF
  char v13; // [esp+97h] [ebp-1h]

  if ( this[4] < 0.0 )
    return 1;
  v2 = 0;
  this[4] = this[4] - dbl_8AFE98;
  v10 = 0;
  if ( !sub_4C5840(0) )
    goto LABEL_12;
  v3 = sub_5679C0(off_5D4AF8[0]);
  if ( v3 )
    v2 = (const char *)sub_567970(v3);
  v4 = sub_5679C0(off_5D4AFC);
  if ( v4 )
    v10 = (const char *)sub_567970(v4);
  if ( v2 )
  {
    if ( sub_423A00(v2, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v2);
    sub_587DD0(v12, byte_5EC4CC, 127);
    v5 = 640;
    v13 = 0;
    sub_4D7E40((int)v12, 640, 818, 0xFFFFFF, 2, 0, 1.0, 1.0);
  }
  else
  {
LABEL_12:
    v5 = v8;
  }
  sub_58815F(v11, "%c", byte_5D4AEC);
  v6 = 0;
  do
  {
    v7 = byte_5EA438[v6];
    v12[v6++] = v7;
  }
  while ( v7 );
  v9 = 16;
  do
  {
    strcat(v12, v11);
    --v9;
  }
  while ( v9 );
  sub_4D7E40((int)v12, v5, 858, 0xFFFFFF, 2, 3, 1.0, 1.0);
  if ( v10 )
  {
    if ( sub_423A00(v10, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v10);
    sub_587DD0(v12, byte_5EC4CC, 127);
    v13 = 0;
    sub_4D7E40((int)v12, 640, 898, 0xFFFFFF, 2, 0, 1.0, 1.0);
  }
  return 0;
}
