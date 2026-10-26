int sub_4953B0()
{
  int v1; // eax
  int v2; // eax
  int v3; // [esp-4h] [ebp-28h]
  char v4; // [esp+4h] [ebp-20h] BYREF
  int v5; // [esp+5h] [ebp-1Fh]
  int v6; // [esp+9h] [ebp-1Bh]
  int v7; // [esp+Dh] [ebp-17h]
  int v8; // [esp+11h] [ebp-13h]
  int v9; // [esp+15h] [ebp-Fh]
  int v10; // [esp+19h] [ebp-Bh]
  int v11; // [esp+1Dh] [ebp-7h]
  __int16 v12; // [esp+21h] [ebp-3h]
  char v13; // [esp+23h] [ebp-1h]

  if ( !(unsigned __int8)sub_54B750(&unk_BE27B0) )
    return sub_4CE020(WindowName);
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v4 = 0;
  v13 = 0;
  if ( sub_54B3E0(&unk_BE27B0) )
  {
    v1 = sub_54B2F0(&unk_BE27B0);
    v2 = sub_54B390(&unk_BE27B0, v1);
    sub_632041(&v4, 32, "%d/%d", v2, v3);
  }
  return sub_4CE020(&v4);
}
