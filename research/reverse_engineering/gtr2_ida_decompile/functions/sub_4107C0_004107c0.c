BOOL __thiscall sub_4107C0(_DWORD *this)
{
  int v2; // eax
  const CHAR *v3; // eax
  const CHAR *v4; // eax
  const char *v5; // eax
  int v6; // eax
  const CHAR *v7; // ecx
  const CHAR *v8; // eax
  BOOL v9; // esi
  char *Block; // [esp+8h] [ebp-14h]

  if ( !this[11] )
  {
    if ( operator new(0x54u) )
      v2 = sub_40E080();
    else
      v2 = 0;
    this[11] = v2;
  }
  Block = (char *)operator new(0x100u);
  *Block = 0;
  v3 = *(const CHAR **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v3 = WindowName;
  sub_615860(v3);
  v4 = (const CHAR *)dword_91CAE0;
  if ( !dword_91CAE0 )
    v4 = WindowName;
  sub_615A50(v4);
  v5 = Block;
  if ( !Block )
    v5 = WindowName;
  v6 = strlen(v5);
  if ( v6 > 0 )
  {
    v7 = Block;
    if ( !Block )
      v7 = WindowName;
    if ( v7[v6 - 1] != 92 )
      sub_615A50(word_6F1F78);
  }
  sub_615A50("pitviews.cam");
  v8 = Block;
  if ( !Block )
    v8 = WindowName;
  v9 = (*(int (__thiscall **)(_DWORD, const CHAR *))(*(_DWORD *)this[11] + 4))(this[11], v8) != 0;
  if ( Block )
    j_j__free(Block);
  return v9;
}
