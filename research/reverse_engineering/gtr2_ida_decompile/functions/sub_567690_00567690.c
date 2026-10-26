int __thiscall sub_567690(_DWORD *this)
{
  int v1; // eax
  char *v2; // eax
  char *v3; // eax
  int v4; // edi
  int v6; // edi
  int v7; // ebx
  int v8; // [esp+Ch] [ebp-48h]
  char Buffer[63]; // [esp+14h] [ebp-40h] BYREF
  char v10; // [esp+53h] [ebp-1h]

  v1 = this[5];
  if ( v1 )
  {
    v6 = 2 * v1 + 1;
    v7 = 2 * v1 + 2;
    sub_5671E0(2 * v1 - 1, 2 * v1, 100.0, 384.0);
    sub_5671E0(v6, v7, 740.0, 384.0);
    return 0;
  }
  else
  {
    v2 = sub_41D840(&byte_91CC38, "STARTING");
    sub_630FE0(Buffer, v2, 63);
    v10 = 0;
    sub_562B70((int)Buffer, 320, 320, (int)dword_FFFF00, 2, 0, 1.5, 5.0);
    v3 = sub_41D840(&byte_91CC38, "GRID");
    sub_630FE0(Buffer, v3, 63);
    v10 = 0;
    sub_562B70((int)Buffer, 320, 500, (int)dword_FFFF00, 2, 0, 3.25, 5.0);
    sprintf(Buffer, "%c", byte_903BA6);
    v4 = 0;
    v8 = 0;
    do
    {
      sub_562B70((int)Buffer, 640, 256 - (unsigned __int64)((double)v8 * -127.65), (int)byte_FFFFFF, 2, 7, 1.5, 3.45);
      v8 = ++v4;
    }
    while ( v4 < 4 );
    sub_5671E0(1, 2, 740.0, 384.0);
    return 0;
  }
}
