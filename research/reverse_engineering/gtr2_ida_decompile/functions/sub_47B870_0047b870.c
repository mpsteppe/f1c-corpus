char __thiscall sub_47B870(char *this, int a2, int a3, _BYTE *a4)
{
  char *v4; // edi
  char *v5; // esi
  int v6; // ebx
  const char *v7; // eax
  int v8; // ecx
  char v9; // al
  float *v10; // ebx
  bool v11; // al
  char v12; // al
  const char *v13; // eax
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  int v18; // [esp+30h] [ebp-124h]
  int v19; // [esp+34h] [ebp-120h]
  char v20; // [esp+3Dh] [ebp-117h]
  char v21; // [esp+3Eh] [ebp-116h]
  int v22; // [esp+40h] [ebp-114h]
  int v23; // [esp+44h] [ebp-110h]
  char Buffer[4]; // [esp+48h] [ebp-10Ch] BYREF
  int v25; // [esp+4Ch] [ebp-108h]
  char *v26; // [esp+50h] [ebp-104h]
  int v27; // [esp+148h] [ebp-Ch]
  int v28; // [esp+14Ch] [ebp-8h]
  _BYTE *retaddr; // [esp+154h] [ebp+0h]

  v4 = &this[528 * a2];
  v5 = (char *)&unk_9204A0 + 22616 * a3;
  *a4 = 1;
  v6 = *((_DWORD *)v5 + 678);
  v26 = this;
  Buffer[1] = 0;
  v25 = v6;
  v7 = (const char *)sub_53E440(v5);
  if ( _stricmp(v7, v4 + 2292) || !v6 || *((_DWORD *)v5 + 3705) == -1 )
  {
    Buffer[3] = sub_4735E0(&dword_B6CBA8);
    if ( *(_DWORD *)(dword_B6CBA8 + 113328) == 4 )
    {
      v8 = *(_DWORD *)(dword_B6CBA8 + 113316);
      if ( v8 )
      {
        if ( sub_59B670(v8) == 3 )
          *(_DWORD *)(dword_B6CBA8 + 113328) = 3;
      }
    }
    if ( !*(_DWORD *)(dword_B6CBA8 + 113328) || byte_B6F118 || (Buffer[2] = 1, dword_B640C0 != 5) )
      Buffer[2] = 0;
    v11 = 0;
    if ( dword_B73474 == 2 && (unsigned __int8)sub_4735A0() )
    {
      if ( (v9 = sub_577B20(dword_91E084 + 16), v10 = (float *)dword_91E084, v9)
        && sub_41FE50((float *)(dword_91E084 + 16)) < flt_B734BC
        || sqrt(v10[4003] * v10[4003] + v10[4004] * v10[4004] + v10[4005] * v10[4005]) < 1.5 )
      {
        v11 = 1;
      }
    }
    if ( Buffer[3] || !Buffer[2] || v11 || !dword_B73474 )
    {
      v12 = v5[22608];
      Buffer[1] = 1;
      if ( v12 )
      {
        sub_53F7C0(v5);
        sub_53E6A0(v5, -1);
        *(_DWORD *)Buffer = 0;
      }
      sub_53FFB0(v5, v4 + 2292);
      sub_615860(v4 + 2324);
      sub_630FE0(v5 + 22484, v4 + 2612, 63);
      v5[22547] = 0;
      sub_53F190(v5, 1, v18, v19);
      *retaddr = 1;
      v13 = (const char *)sub_53E440(v5);
      if ( !_stricmp(v13, v4 + 2292) || !v22 )
      {
        v14 = *(_DWORD *)(v23 + 113328);
        if ( v14 != 2 && v14 != 1 || !sub_473630(&dword_B6CBA8) )
        {
          v15 = sub_41D840(&byte_91CC38, "Loading");
          sprintf(Buffer, "%s - %s", v15, v4 + 2236);
          if ( v21 )
            sub_4730C0((int **)&dword_B6CB98, Buffer, 1, (int)&byte_1020304, 1084227584);
          else
            sub_4EB900(&unk_B6F134, Buffer);
        }
        sub_479AC0((char *)v23, v27, v28);
        v16 = *((_DWORD *)v5 + 3705);
        v5[22608] = 1;
        if ( v16 )
          v5[22589] = 1;
      }
      else
      {
        v20 = 0;
      }
    }
    else
    {
      v5[22589] = 1;
      *a4 = 0;
    }
  }
  *((_DWORD *)v5 + 5446) = 1;
  sub_630FE0(v5 + 21632, v4 + 2268, 23);
  v5[21655] = 0;
  sub_53F530(v5, 0, v4 + 2236, 1);
  if ( !v5[22589] || v5[22590] )
    return v20;
  sub_41D840(&byte_91CC38, "has entered the game.");
  return off_16C9630(a2, a3, a4);
}
