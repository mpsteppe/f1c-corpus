int __thiscall sub_4D2C60(int this)
{
  int v2; // eax
  int *v3; // edi
  int v4; // ebp
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  const CHAR *v7; // eax
  const CHAR *v8; // eax
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // ecx
  CHAR *Block; // [esp+10h] [ebp-14h]

  v2 = *(_DWORD *)(this + 276);
  v3 = (int *)(this + 276);
  v4 = 0;
  if ( v2 )
    sub_5F5280(v2);
  v5 = *(const CHAR **)(this + 160);
  if ( !v5 )
    v5 = WindowName;
  sub_615860(v5);
  Block = (CHAR *)operator new(0x80u);
  *Block = 0;
  v6 = (const CHAR *)dword_91CA98;
  if ( !dword_91CA98 )
    v6 = WindowName;
  sub_615860(v6);
  v7 = *(const CHAR **)(this + 168);
  if ( !v7 )
    v7 = WindowName;
  sub_615A50(v7);
  v8 = Block;
  if ( !Block )
    v8 = WindowName;
  v9 = sub_5F5190(dword_FB1CE0, v3, v8, 0, 0);
  *(_DWORD *)(this + 284) = 0;
  *(_DWORD *)(this + 280) = 0;
  if ( v9 )
  {
    *v3 = 0;
    v4 = 1;
  }
  else
  {
    v10 = *v3 == 0;
    *(_BYTE *)(this + 296) = 0;
    if ( !v10 )
    {
      v11 = sub_5F4570();
      v12 = *v3;
      *(_DWORD *)(this + 288) = v11;
      *(_DWORD *)(this + 292) = sub_5F4580(v12);
    }
  }
  if ( Block )
    j_j__free(Block);
  return v4;
}
