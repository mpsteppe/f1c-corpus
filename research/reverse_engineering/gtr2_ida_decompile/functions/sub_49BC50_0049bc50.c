int __thiscall sub_49BC50(_DWORD *this)
{
  const CHAR *v2; // eax
  const CHAR *v3; // eax
  const CHAR *v4; // eax
  void *Block; // [esp+0h] [ebp-1Ch]
  const CHAR *v7; // [esp+8h] [ebp-14h]

  v7 = (const CHAR *)operator new(0x80u);
  *v7 = 0;
  v2 = (const CHAR *)dword_91CAD0;
  if ( !dword_91CAD0 )
    v2 = WindowName;
  sub_615860(v2);
  v3 = (const CHAR *)this[42];
  if ( !v3 )
    v3 = WindowName;
  sub_615A50(v3);
  v4 = v7;
  if ( !v7 )
    v4 = WindowName;
  sub_590B70(&unk_FB1E98, v4, 1);
  if ( Block )
    j_j__free(Block);
  return 0;
}
