int __thiscall sub_45D130(char *this, int a2)
{
  int result; // eax
  int v4; // esi
  int i; // [esp+Ch] [ebp-F4h]
  char v6[4]; // [esp+10h] [ebp-F0h] BYREF
  char v7[32]; // [esp+14h] [ebp-ECh] BYREF
  char v8[64]; // [esp+34h] [ebp-CCh] BYREF
  char v9[4]; // [esp+74h] [ebp-8Ch] BYREF
  char v10[124]; // [esp+78h] [ebp-88h] BYREF
  __int16 v11; // [esp+F4h] [ebp-Ch]
  __int16 v12; // [esp+FAh] [ebp-6h]

  result = sub_462370(dword_7CD25C);
  v4 = 0;
  for ( i = result; v4 < i; ++v4 )
  {
    sub_461470(v9);
    if ( (unsigned __int8)sub_462410(v4, v9, v6) )
    {
      v7[0] = 0;
      v8[0] = 0;
      sub_58815F(v7, "player_%d", v4);
      sub_45CE30(v7, v10, this);
      sub_58815F(v7, "score_%d", v4);
      sub_58815F(v8, "%d", v11);
      sub_45CE30(v7, v8, this);
      sub_58815F(v7, "ping_%d", v4);
      sub_58815F(v8, "%d", v12);
      sub_45CE30(v7, v8, this);
    }
    nullsub_3(v9);
    result = i;
  }
  return result;
}
