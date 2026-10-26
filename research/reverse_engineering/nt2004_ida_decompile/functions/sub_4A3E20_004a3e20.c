int __thiscall sub_4A3E20(int this)
{
  int v2; // eax
  int *v3; // edi
  int v4; // ebp
  CHAR *v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // eax
  CHAR *v8; // eax
  int v9; // eax
  int v10; // eax
  bool v11; // zf
  CHAR *v13; // [esp+10h] [ebp-8h]

  v2 = *(_DWORD *)(this + 268);
  v3 = (int *)(this + 268);
  v4 = 0;
  if ( v2 )
    sub_5A9130(v2);
  v5 = *(CHAR **)(this + 160);
  if ( !v5 )
    v5 = &byte_629120;
  sub_578600(v5);
  v13 = (CHAR *)operator new(0x80u);
  *v13 = 0;
  v6 = (CHAR *)dword_62A080;
  if ( !dword_62A080 )
    v6 = &byte_629120;
  sub_578600(v6);
  v7 = *(CHAR **)(this + 168);
  if ( !v7 )
    v7 = &byte_629120;
  sub_578560(v7);
  v8 = v13;
  if ( !v13 )
    v8 = &byte_629120;
  v9 = sub_5A9070(v3, v8, 0, 0);
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 272) = 0;
  if ( v9 )
  {
    *v3 = 0;
    v4 = 1;
  }
  else
  {
    v10 = *v3;
    v11 = *v3 == 0;
    *(_BYTE *)(this + 288) = 0;
    if ( !v11 )
    {
      *(_DWORD *)(this + 280) = *(_DWORD *)(v10 + 268);
      *(_DWORD *)(this + 284) = *(_DWORD *)(v10 + 272);
    }
  }
  if ( v13 )
    sub_5BE8AE(v13);
  return v4;
}
