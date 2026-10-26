int __thiscall sub_49D6F0(int this)
{
  int v1; // eax
  const CHAR *v2; // eax
  const CHAR *v3; // eax
  char *v4; // esi
  bool v5; // zf
  CHAR *v6; // eax
  FILE *v7; // eax
  char *v9; // ecx
  const CHAR *v10; // ecx
  const CHAR *v11; // eax
  char *FileName; // [esp+8h] [ebp-19Ch]
  _BYTE *Block; // [esp+10h] [ebp-194h]
  char String[128]; // [esp+18h] [ebp-18Ch] BYREF
  char v15[256]; // [esp+98h] [ebp-10Ch] BYREF
  int v16; // [esp+1A0h] [ebp-4h]

  if ( *(_BYTE *)(this + 276) )
  {
    byte_B6E08C = 0;
    return 0;
  }
  v1 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 41);
  if ( !v1 || !sub_4CE170(v1) )
    return 0;
  sub_617930(256);
  Block = operator new(0x100u);
  *Block = 0;
  v2 = Path;
  v16 = 0;
  if ( !Path )
    v2 = WindowName;
  sub_615A50(v2);
  sub_615A50(v15);
  sub_615A50(&dword_6F1D80);
  sub_6178E0(&byte_B6DC90);
  sub_617930(128);
  FileName = (char *)operator new(0x80u);
  *FileName = 0;
  v3 = Path;
  LOBYTE(v16) = 1;
  if ( !Path )
    v3 = WindowName;
  sub_615A50(v3);
  sub_615A50(String);
  sub_615A50(&dword_6F1D80);
  v4 = _strupr(String);
  v5 = strcmp(_strupr(v15), v4) == 0;
  v6 = FileName;
  if ( v5 )
  {
LABEL_29:
    if ( v6 )
      j_j__free(v6);
    if ( Block )
      j_j__free(Block);
    return 0;
  }
  if ( !FileName )
    v6 = (CHAR *)WindowName;
  v7 = fopen(v6, "rb");
  if ( !v7 )
  {
LABEL_22:
    v10 = FileName;
    if ( !FileName )
      v10 = WindowName;
    v11 = Block;
    if ( !Block )
      v11 = WindowName;
    if ( !sub_633A7E(v11, v10) )
      sub_48F4A0();
    v6 = FileName;
    goto LABEL_29;
  }
  fclose(v7);
  if ( byte_B6E08C )
  {
    v9 = FileName;
    if ( !FileName )
      v9 = (char *)WindowName;
    sub_617680(v9);
    goto LABEL_22;
  }
  byte_B6E08C = 1;
  sub_4E1810("REPLAY OVERWRITE CONFIRM", 0);
  if ( FileName )
    j_j__free(FileName);
  if ( Block )
    j_j__free(Block);
  return -1;
}
