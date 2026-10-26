// f1c  0x0049db00  size=116
int __stdcall sub_49DB00(float a1, int a2)
{
  float v3; // [esp+8h] [ebp+4h]

  if ( dword_7D0450 != 1 )
    return sub_58815F(a2, "%4d %s", (int)a1, &byte_5C3734);
  v3 = (a1 - -40.0) * 1.8 - 40.0;
  return sub_58815F(a2, "%4d %s", (int)v3, &byte_5C3738);
}
