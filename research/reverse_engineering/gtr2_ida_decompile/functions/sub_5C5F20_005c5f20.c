char __userpurge sub_5C5F20@<al>(int a1@<ecx>, int a2@<edi>, int a3, int a4, char a5, int a6)
{
  char v9; // cl
  bool v10; // bl
  char v11; // al
  char v12; // al
  char v13; // al
  const char *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // [esp+8h] [ebp-20h] BYREF
  char v18; // [esp+Ch] [ebp-1Ch]
  char v19; // [esp+Dh] [ebp-1Bh]
  int v20; // [esp+10h] [ebp-18h] BYREF
  const char *v21; // [esp+14h] [ebp-14h]
  int v22; // [esp+24h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+28h] [ebp+0h]
  char v24; // [esp+30h] [ebp+8h]
  char v25; // [esp+34h] [ebp+Ch]

  if ( a4 )
  {
    (*(void (__thiscall **)(int, int *, int, int))(*(_DWORD *)a3 + 4))(a3, &v17, 4, a2);
    sub_5BE610((int)&v20, a3);
    v24 = v19 & 1;
    v9 = v18 & 1;
    v10 = (v18 & 0x10) != 0;
    retaddr = 0;
    v25 = v18 & 1;
    if ( *(_BYTE *)(a1 + 12) )
    {
      sub_643E40("- Repositioning node name = '%s'", v21);
      v9 = v25;
      if ( *(_BYTE *)(a1 + 12) )
      {
        sub_643E40("  - Repositioning mask");
        v9 = v25;
      }
    }
    v11 = *(_BYTE *)(a1 + 12);
    if ( v9 )
    {
      if ( v11 )
        sub_643E40("     + Position = true");
    }
    else if ( v11 )
    {
      sub_643E40("     + Position = false");
    }
    v12 = *(_BYTE *)(a1 + 12);
    if ( v10 )
    {
      if ( v12 )
        sub_643E40("     + Rotation = true");
    }
    else if ( v12 )
    {
      sub_643E40("     + Rotation = false");
    }
    v13 = *(_BYTE *)(a1 + 12);
    if ( v24 )
    {
      if ( v13 )
        sub_643E40("     + Scale    = true");
    }
    else if ( v13 )
    {
      sub_643E40("     + Scale    = false");
    }
    v14 = v21;
    v15 = ((int (__thiscall *)(int, const char *))loc_405290)(a4, v21);
    if ( v15 )
    {
      *(_DWORD *)(a4 + 528) = v15;
      v16 = v24 != 0;
      if ( v10 )
        v16 |= 0x10u;
      if ( (_BYTE)a3 )
        v16 |= 0x100u;
      *(_DWORD *)(a4 + 548) = v16;
    }
    else
    {
      sub_643E40("Repositioning node '%s' has not been found.", v14);
    }
    v22 = -1;
    sub_5A8840();
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
