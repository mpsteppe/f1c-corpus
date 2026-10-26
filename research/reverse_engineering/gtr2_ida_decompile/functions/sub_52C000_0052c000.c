void __thiscall sub_52C000(int *this, const char *a2)
{
  char *v3; // eax
  char *v4; // eax
  _DWORD *v5; // ecx
  int v6; // [esp+4h] [ebp-150h]
  char v7[64]; // [esp+14h] [ebp-140h] BYREF
  char v8[64]; // [esp+54h] [ebp-100h] BYREF
  char Buffer[192]; // [esp+94h] [ebp-C0h] BYREF

  if ( this[27] != 3 )
  {
    if ( a2 && !*(_DWORD *)(*this + 14820) )
    {
      v3 = sub_41D840(&byte_91CC38, "Disqualified:");
      sub_630FE0(v7, v3, 63);
      v7[63] = 0;
      v4 = sub_41D840(&byte_91CC38, a2);
      sub_630FE0(v8, v4, 63);
      v8[63] = 0;
      sprintf(Buffer, "%s %s", v7, v8);
      sub_4730C0((int **)&dword_B6CB98, Buffer, 3, (int)&byte_1020304, 1084227584);
    }
    sub_54F160(&byte_FADF20, *this);
    v5 = (_DWORD *)off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v6 = dbl_FB1D18;
    sub_51B2A0(v5, 4, 26, 0, this[1], v6, 3);
  }
}
