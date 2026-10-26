int __thiscall sub_4AB200(int this)
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

  if ( *(_DWORD *)(this + 276) != 851 )
    return 0;
  v1 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 53);
  if ( !v1 || !sub_4CE170(v1) )
    return 0;
  sub_617930(256);
  Block = operator new(0x100u);
  *Block = 0;
  v2 = *(const CHAR **)dword_BE121C;
  v16 = 0;
  if ( !*(_DWORD *)dword_BE121C )
    v2 = WindowName;
  sub_615A50(v2);
  sub_615A50(v15);
  sub_615A50(&stru_6F59D0.ExceptionRecord);
  sub_6178E0(&byte_B6DF10);
  sub_617930(128);
  FileName = (char *)operator new(0x80u);
  *FileName = 0;
  v3 = *(const CHAR **)dword_BE121C;
  LOBYTE(v16) = 1;
  if ( !*(_DWORD *)dword_BE121C )
    v3 = WindowName;
  sub_615A50(v3);
  sub_615A50(String);
  sub_615A50(&stru_6F59D0.ExceptionRecord);
  v4 = _strupr(String);
  v5 = strcmp(_strupr(v15), v4) == 0;
  v6 = FileName;
  if ( v5 )
  {
LABEL_28:
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
LABEL_21:
    v10 = FileName;
    if ( !FileName )
      v10 = WindowName;
    v11 = Block;
    if ( !Block )
      v11 = WindowName;
    if ( !sub_633A7E(v11, v10) )
      sub_497320();
    v6 = FileName;
    goto LABEL_28;
  }
  fclose(v7);
  if ( byte_B6E08F )
  {
    v9 = FileName;
    if ( !FileName )
      v9 = (char *)WindowName;
    sub_617680(v9);
    goto LABEL_21;
  }
  byte_B6E08F = 1;
  sub_4E1810("TIMETRIAL RENAME CONFIRM", 0);
  if ( FileName )
    j_j__free(FileName);
  if ( Block )
    j_j__free(Block);
  return -1;
}
