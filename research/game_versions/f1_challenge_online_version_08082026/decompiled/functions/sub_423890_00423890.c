int __thiscall sub_423890(int *this, int a2, int a3)
{
  int v4; // ebp
  int v5; // esi
  char v7[128]; // [esp+Ch] [ebp-480h] BYREF
  char v8[509]; // [esp+8Ch] [ebp-400h] BYREF
  __int16 v9; // [esp+289h] [ebp-203h]
  char v10; // [esp+28Bh] [ebp-201h]
  char v11[256]; // [esp+28Ch] [ebp-200h] BYREF
  char v12[256]; // [esp+38Ch] [ebp-100h] BYREF

  v4 = 0;
  if ( a3 )
  {
    if ( a2 )
      sub_58815F(v7, "%s%s", a2, a3);
  }
  else
  {
    sub_58815F(v7, "%s%s", a2, aGameDic);
  }
  v5 = sub_534B00();
  if ( !v5 )
    return -1;
  v8[0] = byte_5EA438;
  memset(&v8[1], 0, 0x1FCu);
  v9 = 0;
  v10 = 0;
  while ( sub_5351D0(256) )
  {
    if ( sub_4236F0(v8, v12, v11) != -1 && !sub_423530(this, v12, v11) )
      ++v4;
  }
  sub_5355A0(v5);
  sub_5890AA(this[2], this[1], 16, sub_423830);
  v7[0] = 0;
  if ( !sub_423A00(aOscLocaleStrin, v7) )
  {
    if ( strlen(v7) )
      sub_588A34(2, v7);
  }
  return v4;
}
