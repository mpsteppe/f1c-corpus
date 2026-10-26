char __thiscall sub_41F070(int this, int a2, int a3)
{
  int v4; // ebp
  const char *v5; // eax
  int v7; // edi
  int v8; // eax
  const char *v9; // eax
  int v10; // edi
  const char *v11; // eax
  double v12; // st7
  double v13; // st7
  const char *v14; // eax
  int v15; // eax
  int v16; // eax
  float v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  float v19; // [esp+18h] [ebp+4h]

  v4 = -1;
  *(_BYTE *)this = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = -1;
  *(_BYTE *)(this + 12) = 1;
  *(_BYTE *)(this + 13) = 1;
  *(_BYTE *)(this + 14) = 0;
  *(_BYTE *)(this + 15) = 0;
  *(_BYTE *)(this + 16) = 1;
  v5 = Str;
  if ( !Str )
    v5 = WindowName;
  if ( !strstr(v5, "Custom") )
    return 0;
  *(_DWORD *)(this + 4) = a2;
  v7 = 0;
  v8 = sub_616840("MinPlacement");
  if ( v8 )
  {
    v9 = (const char *)sub_48D380(v8);
    v7 = atol(v9);
  }
  if ( a3 )
    v10 = a3 >= v7 ? -1 : 2;
  else
    v10 = 1;
  *(_DWORD *)(this + 8) = v10;
  v17 = 0.0;
  v11 = sub_41D920((_DWORD *)this, 0);
  if ( v11 && *((float *)v11 + 18) >= 0.0 )
    v17 = *((float *)v11 + 18);
  v12 = (double)a2;
  *(float *)&v18 = v12;
  v13 = v12 - v17;
  v19 = v13;
  if ( v13 < 0.0 )
    v19 = 0.0;
  v14 = sub_41D920((_DWORD *)this, 0);
  if ( v14 )
  {
    v15 = *((_DWORD *)v14 + 16);
    if ( v15 != -2 )
      v4 = v15;
  }
  v16 = v10;
  if ( v4 == 1 || v4 == 2 && v10 != 1 )
    v16 = -1;
  *(_BYTE *)(this + 14) = ((int (__thiscall *)(int, int, _DWORD))loc_41EA90)(this, v16, LODWORD(v19));
  sub_41E030((_DWORD *)this, v10, a3, *(float *)&v18, 0);
  sub_41DC90(this);
  *(_BYTE *)(this + 12) = 0;
  *(_BYTE *)(this + 16) = 0;
  return 1;
}
