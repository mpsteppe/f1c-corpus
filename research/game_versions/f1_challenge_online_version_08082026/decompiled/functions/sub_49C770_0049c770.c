int __stdcall sub_49C770(int a1, int a2)
{
  double v2; // st7
  int v3; // eax
  int v4; // eax
  char v5; // cl
  int v7; // eax
  float v8; // [esp+Ch] [ebp-14h]
  char v9[16]; // [esp+10h] [ebp-10h] BYREF

  v8 = *(float *)(dword_7C54E0 + 14724);
  v2 = *(float *)(dword_7C54E0 + 13384);
  if ( v2 <= 0.0 )
  {
    v4 = 0;
    do
    {
      v5 = byte_5CCEA0[v4];
      v9[v4++] = v5;
    }
    while ( v5 );
  }
  else
  {
    v3 = sub_587BDC(v2 * v8);
    sub_58815F(v9, &off_5CCEA4, v3);
  }
  if ( dword_7D0450 == 1 )
  {
    sub_58815F(a1, " %.1f%s", v8 * 0.26417205, v9);
  }
  else
  {
    v7 = sub_587BDC(v8 + 0.5);
    sub_58815F(a1, " %d%s", v7, v9);
  }
  return 0;
}
