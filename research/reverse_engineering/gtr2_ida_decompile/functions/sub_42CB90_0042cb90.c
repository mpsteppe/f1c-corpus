void sub_42CB90()
{
  _DWORD v0[132]; // [esp+4h] [ebp-21Ch] BYREF
  int v1; // [esp+21Ch] [ebp-4h]

  LOBYTE(dword_757C1C) = 1;
  sub_4744D0(v0);
  v1 = 0;
  if ( (unsigned __int8)sub_473720(&dword_B6CBA8, v0) == 1 && v0[0] != 3
    || dword_B763D8
    || (unsigned __int8)sub_473630(&dword_B6CBA8) == 1 )
  {
    LOBYTE(dword_757C1C) = 0;
  }
  v1 = -1;
  nullsub_7(v0);
}
