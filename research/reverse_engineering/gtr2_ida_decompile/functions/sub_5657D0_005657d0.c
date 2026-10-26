int sub_5657D0()
{
  int v0; // esi
  char *v1; // eax
  int v3[31]; // [esp+8h] [ebp-80h] BYREF
  char v4; // [esp+87h] [ebp-1h]

  v0 = sub_5656D0();
  if ( !v0 )
  {
    v1 = sub_41D840(&byte_91CC38, "JUMP START PENALTY");
    sub_630FE0(v3, v1, 127);
    v4 = 0;
    sub_562B70((int)v3, 1180, 50, (int)dword_FFFF00, 1, 0, 1.0, 1.0);
  }
  return v0;
}
