char __thiscall sub_5225A0(_DWORD *this)
{
  char v2; // bl
  const char *v3; // ecx
  char *v4; // eax
  char *v5; // edi
  char *v7; // edx
  unsigned int v8; // eax
  char *v9; // edi
  char *v11; // edi
  void *v13; // ecx
  int v14; // eax
  char *v15; // eax
  float v17; // [esp+18h] [ebp-270h]
  float v18; // [esp+18h] [ebp-270h]
  float v19; // [esp+1Ch] [ebp-26Ch]
  int v20[22]; // [esp+20h] [ebp-268h] BYREF
  char v21; // [esp+7Bh] [ebp-20Dh] BYREF
  char ArgList[512]; // [esp+7Ch] [ebp-20Ch] BYREF
  int v23; // [esp+284h] [ebp-4h]

  v17 = *(float *)(dword_91E084 + 19436);
  v2 = 0;
  if ( v17 != -1.0 && v17 > 0.0 )
  {
    v19 = *(float *)(dword_91E084 + 19460);
    v3 = (const char *)this[723247];
    v18 = v19 + v17;
    if ( !v3 )
      v3 = WindowName;
    strcpy(ArgList, v3);
    v4 = &ArgList[strlen(ArgList)];
    if ( v4 > ArgList )
    {
      while ( *v4 != 46 )
      {
        if ( --v4 <= ArgList )
          goto LABEL_10;
      }
      *v4 = 0;
    }
LABEL_10:
    v5 = &v21;
    while ( *++v5 )
      ;
    *(_WORD *)v5 = 32;
    v7 = sub_41D840(&byte_91CC38, "HOT LAP");
    v8 = strlen(v7) + 1;
    v9 = &v21;
    while ( *++v9 )
      ;
    qmemcpy(v9, v7, v8);
    v11 = &v21;
    while ( *++v11 )
      ;
    strcpy(v11, ".Vcr");
    sub_613B30(v20);
    v13 = (void *)this[722644];
    v23 = 0;
    v14 = sub_5207A0(v13);
    if ( (unsigned __int8)sub_6146B0(ArgList, v14, 0, 1, 1) )
    {
      v15 = sub_41D840(&byte_91CC38, "Saving Hotlap");
      sub_4EB900(&unk_B6F134, (int)v15);
      if ( sub_521FC0((int)this, v20, v19, v18) && sub_522450(this, (int)(this + 445), (int)v20, v19, v18) )
        v2 = 1;
      sub_613C30(v20);
    }
    else if ( dword_B640C0 != 5
           && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\Replay.cpp", 3973) )
    {
      sub_561210((int)byte_FAE910, "Failed to create hotlap replay file: \"%s\"", (char)ArgList);
    }
    v23 = -1;
    sub_614140(v20);
  }
  return v2;
}
