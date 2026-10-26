char __thiscall sub_5BE300(int this, int a2, int a3, int a4, int a5)
{
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp+10h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch] BYREF
  int v14; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h]

  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a2 + 120))(a2) )
    return 0;
  v7 = *(_DWORD *)(this + 36);
  LOBYTE(v11) = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( v7 != 1 || *(_DWORD *)(this + 40) )
    v8 = (*(int (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 4))(a2, &v13, 12);
  else
    v8 = (*(int (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 4))(a2, &v11, 8);
  if ( !v8 )
    return 0;
  v9 = sub_5BE2B0();
  if ( v9 )
    return (*(int (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v9 + 4))(v9, a2, a3, a4, a5);
  if ( *(_DWORD *)(this + 36) == 1 && !*(_DWORD *)(this + 40) )
  {
    v10 = v12;
    if ( v12 < 0 )
    {
      if ( *(_BYTE *)(this + 31) )
      {
        sub_643E40("Chunk has a negative size. Returning.");
        return 0;
      }
      return 0;
    }
    if ( *(_BYTE *)(this + 31) )
    {
      sub_643E40("Importer::ProcessChunk() - Unknown chunk (ID=%d  Size=%d bytes), skipping...", (char)v11, v12);
      v10 = v12;
    }
    goto LABEL_21;
  }
  v10 = v14;
  if ( v14 >= 0 && v15 >= 0 )
  {
    if ( *(_BYTE *)(this + 31) )
    {
      sub_643E40("Importer::ProcessChunk() - Unknown chunk (ID=%d  Size=%d bytes), skipping...", v13, v14);
      v10 = v14;
    }
LABEL_21:
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 140))(a2, v10);
    return 1;
  }
  if ( !*(_BYTE *)(this + 31) )
    return 0;
  sub_643E40("Chunk has a negative size or version number. Returning.");
  return 0;
}
