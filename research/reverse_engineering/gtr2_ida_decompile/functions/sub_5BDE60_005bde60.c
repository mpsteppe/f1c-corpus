char __thiscall sub_5BDE60(_DWORD *this, int *a2)
{
  int v3; // eax
  char v4; // bl
  char v5; // al
  int v6; // edx
  bool v7; // zf
  int v8; // eax
  char v9; // al
  int v10; // edx
  _BYTE v12[4]; // [esp+14h] [ebp-14h] BYREF
  char v13; // [esp+18h] [ebp-10h]
  char v14; // [esp+19h] [ebp-Fh]
  _BYTE v15[4]; // [esp+1Ch] [ebp-Ch] BYREF
  char v16; // [esp+20h] [ebp-8h]
  char v17; // [esp+21h] [ebp-7h]
  char v18; // [esp+22h] [ebp-6h]
  int v19; // [esp+24h] [ebp-4h]

  v19 = dword_912B08;
  v3 = *a2;
  v4 = 1;
  qmemcpy(v15, "LMA ", sizeof(v15));
  (*(void (__thiscall **)(int *, _BYTE *, int))(v3 + 4))(a2, v15, 7);
  v5 = v16;
  v6 = v16;
  this[10] = v17;
  v7 = v15[0] == 76;
  this[9] = v6;
  if ( !v7 || v15[1] != 77 || v15[2] != 65 || v15[3] != 32 )
    v4 = 0;
  if ( v5 != 1 )
    v4 = 0;
  if ( !v18 || !v4 )
  {
    (*(void (__thiscall **)(int *, _DWORD))(*a2 + 144))(a2, 0);
    v8 = *a2;
    v4 = 1;
    qmemcpy(v12, "FXA ", sizeof(v12));
    (*(void (__thiscall **)(int *, _BYTE *, int))(v8 + 4))(a2, v12, 6);
    v9 = v13;
    v10 = v13;
    this[10] = v14;
    v7 = v12[0] == 70;
    this[9] = v10;
    if ( !v7 || v12[1] != 88 || v12[2] != 65 || v12[3] != 32 )
      v4 = 0;
    if ( v9 != 1 )
      return 0;
  }
  return v4;
}
