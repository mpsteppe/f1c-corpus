char __stdcall sub_4B4BA0(const char *a1, int a2, int a3)
{
  int v3; // esi
  const CHAR *v4; // eax
  int v5; // eax
  _BYTE *Block; // [esp+10h] [ebp-21Ch]
  int v8; // [esp+18h] [ebp-214h] BYREF
  _BYTE v9[4]; // [esp+1Ch] [ebp-210h] BYREF
  char FileName[256]; // [esp+20h] [ebp-20Ch] BYREF
  char v11[256]; // [esp+120h] [ebp-10Ch] BYREF
  int v12; // [esp+228h] [ebp-4h]

  if ( strcmp(off_759F1C[0], a1) )
    return 0;
  sub_4DE540(v9, &v8);
  v3 = sub_4D0D20(v8);
  if ( v3 <= 0 )
    return 0;
  Block = operator new(0x50u);
  *Block = 0;
  v12 = 0;
  v4 = sub_436620((const CHAR ***)&dword_B65FF8);
  sub_615860(v4);
  sub_40D6E0();
  v5 = sub_4CE2D0(v3);
  sub_615A50(v5);
  sub_40D6E0();
  sub_615A50(a2);
  sub_615A50(".svm");
  sub_617930(256);
  sub_4ABA50();
  sub_617680(FileName);
  if ( !(unsigned __int8)sub_617D00(v11, FileName) )
  {
    if ( Block )
      j_j__free(Block);
    return 0;
  }
  if ( Block )
    j_j__free(Block);
  return 1;
}
