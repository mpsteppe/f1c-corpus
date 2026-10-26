int __thiscall sub_4D9420(_DWORD *this)
{
  int v1; // ecx
  int v2; // eax
  char v3; // cl
  int v4; // eax
  char v5; // cl
  int v6; // edi
  int v7; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // [esp+Ch] [ebp-44h]
  int v12[15]; // [esp+10h] [ebp-40h] BYREF
  char v13; // [esp+4Fh] [ebp-1h]

  v1 = this[5];
  if ( v1 )
  {
    v9 = 2 * v1 + 1;
    v10 = 2 * v1 + 2;
    sub_4D95D0(2 * v1 - 1, 2 * v1, 100.0, 384.0);
    sub_4D95D0(v9, v10, 740.0, 384.0);
    return 0;
  }
  else
  {
    if ( sub_423A00(byte_5EC4C0, aStarting, byte_5EC4CC) )
    {
      v2 = 0;
      do
      {
        v3 = aStarting[v2];
        byte_5EC4CC[v2++] = v3;
      }
      while ( v3 );
    }
    sub_587DD0(v12, byte_5EC4CC, 63);
    v13 = 0;
    sub_4D7E40((int)v12, 320, 320, 16776960, 2, 0, 1.5, 5.0);
    if ( sub_423A00(byte_5EC4C0, aGrid_0, byte_5EC4CC) )
    {
      v4 = 0;
      do
      {
        v5 = aGrid_0[v4];
        byte_5EC4CC[v4++] = v5;
      }
      while ( v5 );
    }
    sub_587DD0(v12, byte_5EC4CC, 63);
    v13 = 0;
    sub_4D7E40((int)v12, 320, 500, 16776960, 2, 0, 3.25, 5.0);
    sub_58815F(v12, "%c", byte_5D4AEF);
    v6 = 0;
    v11 = 0;
    do
    {
      v7 = sub_587BDC((double)v11 * -127.65);
      sub_4D7E40((int)v12, 640, 256 - v7, 0xFFFFFF, 2, 3, 1.5, 3.45);
      v11 = ++v6;
    }
    while ( v6 < 4 );
    sub_4D95D0(1, 2, 740.0, 384.0);
    return 0;
  }
}
