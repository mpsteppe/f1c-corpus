int __usercall sub_529530@<eax>(int a1@<ecx>, char a2@<dil>)
{
  char v3; // bl
  const CHAR *v4; // edi
  char *v5; // eax
  char *v6; // edi
  const CHAR *v7; // eax
  int i; // eax
  const CHAR *v9; // eax
  int v10; // eax
  int v11; // ecx
  int result; // eax
  CHAR *Block; // [esp+1Ch] [ebp-4D0h]
  char *Str1; // [esp+24h] [ebp-4C8h]
  float v15[23]; // [esp+28h] [ebp-4C4h] BYREF
  _BYTE v16[8]; // [esp+84h] [ebp-468h] BYREF
  _BYTE v17[84]; // [esp+8Ch] [ebp-460h] BYREF
  _BYTE v18[1024]; // [esp+E0h] [ebp-40Ch] BYREF
  int v19; // [esp+4E8h] [ebp-4h]

  if ( *(_DWORD *)a1 == 2 )
  {
    v3 = 0;
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\Replay.cpp", 6604) )
      sub_561210((int)byte_FAE910, "Loading VCR File for playback", a2);
    v4 = *(const CHAR **)(*(_DWORD *)(a1 + 8) + 2892980);
    if ( !v4 )
      v4 = WindowName;
    sub_613B30(v15);
    v19 = 0;
    if ( !(unsigned __int8)sub_614460(v4, 0) )
      goto LABEL_24;
    v5 = sub_41D840(&byte_91CC38, "Prepping Replay");
    sub_4EB900(&unk_B6F134, (int)v5);
    Sleep(0xFAu);
    LODWORD(v15[0]) = operator new(0x80u);
    *(_BYTE *)LODWORD(v15[0]) = 0;
    LODWORD(v15[1]) = 128;
    sub_523690();
    v6 = Str1;
    if ( !Str1 )
      v6 = (char *)WindowName;
    if ( !strncmp(v6, Str2, 2u) )
      sub_614A60(v6);
    else
      sub_617680(v6);
    sub_613B30(v17);
    v7 = Str1;
    if ( !Str1 )
      v7 = WindowName;
    if ( (unsigned __int8)sub_6146B0(v7, 0, 0, 1, 1, v15) )
    {
      for ( i = sub_613CE0(v18, 1024); i > 0; i = sub_613CE0(v18, 1024) )
        sub_613C90(v18, i);
      sub_613C30(v16);
      v9 = Block;
      if ( !Block )
        v9 = WindowName;
      v3 = sub_528A30(*(int **)(a1 + 8), (int)v6, (int)v9, 0);
      if ( v3 )
      {
        sub_5255F0();
        *(_DWORD *)a1 = 2;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 2892972) = 5;
      }
    }
    sub_613C30(v15);
    LOBYTE(v19) = 1;
    sub_614140(v16);
    LOBYTE(v19) = 0;
    if ( Block )
      j_j__free(Block);
    if ( v3 )
    {
      sub_42C8A0(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 2892816));
      sub_42C8E0(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 2892816));
      v10 = *(_DWORD *)(a1 + 8);
      v15[0] = *(float *)(v10 + 2892844);
      v11 = LODWORD(v15[0]);
      *(float *)(v10 + 2892856) = v15[0];
      sub_522980(*(void **)(a1 + 8), v11);
    }
    else
    {
LABEL_24:
      *(_DWORD *)a1 = 0;
    }
    v19 = -1;
    result = sub_614140(v15);
  }
  else
  {
    *(_DWORD *)a1 = 1;
    result = sub_409B30();
    *(_DWORD *)a1 = !(_BYTE)result && ((result = dword_B71E40) != 0 || (result = dword_B71E64) != 0);
  }
  *(_BYTE *)(a1 + 5) = 1;
  return result;
}
