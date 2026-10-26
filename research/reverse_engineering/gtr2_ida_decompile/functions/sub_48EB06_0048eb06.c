int __thiscall sub_48EB06(_DWORD *this, const char *a2, char a3)
{
  _DWORD *v3; // edx
  int result; // eax
  char *v5; // eax
  char *v6; // eax
  int v7; // esi
  float v8; // [esp+0h] [ebp-154h]
  char v10[64]; // [esp+14h] [ebp-140h] BYREF
  char v11[64]; // [esp+54h] [ebp-100h] BYREF
  char Buffer[192]; // [esp+94h] [ebp-C0h] BYREF

  v3 = this;
  result = this[27];
  if ( !result )
  {
    if ( a2 && !*(_DWORD *)(*this + 14820) && strcmp(a2, "Ignored Blue Flags") )
    {
      v5 = sub_41D840(&byte_91CC38, "Stop/Go Penalty:");
      sub_630FE0(v11, v5, 63);
      v11[63] = 0;
      v6 = sub_41D840(&byte_91CC38, a2);
      sub_630FE0(v10, v6, 63);
      v10[63] = 0;
      sprintf(Buffer, "%s %s", v11, v10);
      sub_4730C0((int **)&dword_B6CB98, Buffer, 3, (int)&byte_1020304, 1084227584);
      v3 = this;
    }
    if ( dword_82F4A0 >= 1023 )
    {
      v7 = off_9034A4;
    }
    else
    {
      ++dword_82F4A0;
      v7 = off_9034A4;
      off_9034A4 += 848;
    }
    v8 = dbl_FB1D18;
    result = sub_51B2A0(4, 22, 1, v3[1], LODWORD(v8), 3);
    *(_BYTE *)(v7 + 8) = a3;
  }
  return result;
}
