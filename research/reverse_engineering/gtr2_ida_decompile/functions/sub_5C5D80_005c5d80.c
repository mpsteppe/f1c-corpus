char __userpurge sub_5C5D80@<al>(int a1@<ecx>, int a2@<ebx>, int a3, int a4, int a5, int a6)
{
  char v8; // al
  char v9; // cl
  bool v10; // bl
  char v11; // al
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  char v16; // [esp+Ch] [ebp-8Ah]
  char v17; // [esp+Dh] [ebp-89h]
  char v18[2]; // [esp+Eh] [ebp-88h] BYREF
  __int16 v19; // [esp+10h] [ebp-86h]
  char v20[128]; // [esp+12h] [ebp-84h] BYREF
  int v21; // [esp+92h] [ebp-4h]

  v21 = dword_912B08;
  if ( a4 )
  {
    (*(void (__thiscall **)(int, char *, int, int))(*(_DWORD *)a3 + 4))(a3, v18, 132, a2);
    v8 = *(_BYTE *)(a1 + 12);
    v9 = v21 & 1;
    v10 = (v21 & 0x10) != 0;
    v19 = v21 & 0x101;
    if ( v8 )
    {
      sub_643E40("- Repositioning node name = '%s'", v20);
      v9 = v19;
      if ( *(_BYTE *)(a1 + 12) )
      {
        sub_643E40("  - Repositioning mask");
        v9 = v19;
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
    if ( HIBYTE(v19) )
    {
      if ( v13 )
        sub_643E40("     + Scale    = true");
    }
    else if ( v13 )
    {
      sub_643E40("     + Scale    = false");
    }
    v14 = ((int (__thiscall *)(int, char *))loc_405290)(a4, v20);
    if ( v14 )
    {
      *(_DWORD *)(a4 + 528) = v14;
      v15 = v16 != 0;
      if ( v10 )
        v15 |= 0x10u;
      if ( v17 )
        v15 |= 0x100u;
      *(_DWORD *)(a4 + 548) = v15;
    }
    else
    {
      sub_643E40("Repositioning node '%s' has not been found.", v18);
    }
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
