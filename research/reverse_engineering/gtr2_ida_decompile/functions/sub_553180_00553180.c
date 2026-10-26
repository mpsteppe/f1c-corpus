void __userpurge sub_553180(int a1@<edi>, const CHAR *a2)
{
  const CHAR *v2; // eax
  struct tm *v3; // eax
  char v4; // al
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  char v7; // [esp-34h] [ebp-1BCh]
  int v8; // [esp-1Ch] [ebp-1A4h]
  int v9; // [esp-18h] [ebp-1A0h]
  int v10; // [esp-14h] [ebp-19Ch]
  int v11; // [esp-10h] [ebp-198h]
  int v12; // [esp-Ch] [ebp-194h]
  int v13; // [esp-8h] [ebp-190h]
  char v14; // [esp-8h] [ebp-190h]
  int v15; // [esp-4h] [ebp-18Ch]
  char v16; // [esp+0h] [ebp-188h]
  int v17; // [esp+0h] [ebp-188h]
  double v18; // [esp+0h] [ebp-188h]
  double v19; // [esp+0h] [ebp-188h]
  char v20; // [esp+4h] [ebp-184h]
  void *Block; // [esp+10h] [ebp-178h]
  char v22[4]; // [esp+1Ch] [ebp-16Ch] BYREF
  char ArgList[8]; // [esp+20h] [ebp-168h]
  int v24; // [esp+28h] [ebp-160h]
  __time32_t Time; // [esp+3Ch] [ebp-14Ch] BYREF
  int v26; // [esp+40h] [ebp-148h] BYREF
  int v27; // [esp+44h] [ebp-144h]
  const CHAR *v28; // [esp+48h] [ebp-140h]
  _DWORD v29[18]; // [esp+54h] [ebp-134h] BYREF
  char Buffer[61]; // [esp+9Ch] [ebp-ECh] BYREF
  __int16 v31; // [esp+D9h] [ebp-AFh]
  char v32; // [esp+DBh] [ebp-ADh]
  char v33; // [esp+140h] [ebp-48h]
  char v34; // [esp+178h] [ebp-10h]
  int v35; // [esp+184h] [ebp-4h]

  v29[0] = operator new(0x100u);
  *(_BYTE *)v29[0] = 0;
  v29[1] = 256;
  v28 = a2;
  v27 = 1;
  v26 = (int)v29;
  v35 = 0;
  if ( (unsigned __int8)sub_551DA0() )
  {
    sub_613B30(v29);
    v2 = v28;
    v34 = 1;
    if ( !v28 )
      v2 = WindowName;
    if ( (unsigned __int8)sub_6146B0(v2, 0, 1, 1, 1, v26, v27) == 1 )
    {
      v24 = a1;
      memset(Buffer, 0, sizeof(Buffer));
      v31 = 0;
      v32 = 0;
      time(&Time);
      v3 = localtime(&Time);
      sprintf(
        Buffer,
        "%d/%0.2d/%0.2d %0.2d:%0.2d:%0.2d",
        v3->tm_year + 1900,
        v3->tm_mon + 1,
        v3->tm_mday,
        v3->tm_hour,
        v3->tm_min,
        v3->tm_sec);
      sub_613D30((int)&v26, "[Header]\n", v16);
      sub_613D30((int)&v26, "Game=%s\n", (char)"GTR2");
      *(double *)ArgList = 1.0;
      sub_613D30((int)&v26, "Version=%.3f\n", ArgList[0]);
      sub_613D30((int)&v26, "TimeString=%s\n", (char)Buffer);
      *(_DWORD *)ArgList = (char)(((unsigned __int8)sub_501D80(&byte_B6F530, 0) != 0) + 48);
      sub_501D80(&byte_B6F530, 1);
      Block = (void *)(char)(((unsigned __int8)sub_501D80(&byte_B6F530, 3) != 0) + 48);
      sub_501D80(&byte_B6F530, 4);
      v17 = (char)(((unsigned __int8)sub_501D80(&byte_B6F530, 9) != 0) + 48);
      v13 = (char)(((unsigned __int8)sub_501D80(&byte_B6F530, 7) != 0) + 48);
      v11 = (char)(((unsigned __int8)sub_501D80(&byte_B6F530, 2) != 0) + 48);
      v9 = (char)(((unsigned __int8)sub_501D80(&byte_B6F530, 8) != 0) + 48);
      v4 = sub_501D80(&byte_B6F530, 5);
      sprintf(&Buffer[28], "%c,%c,%c,%c,%c,%c,%c,%c,%c", (char)((v4 != 0) + 48), v8, v9, v10, v11, v12, v13, v15, v17);
      sub_613D30((int)v22, "Aids=%s\n", (char)&Buffer[28]);
      sub_613D30((int)v22, (char *)word_6F2E64, v7);
      sub_613D30((int)v22, "[Race]\n", v20);
      sub_613D30((int)v22, "RaceMode=%d\n", dword_B72314[0]);
      LOBYTE(v5) = (_BYTE)dword_B6F68C;
      if ( !dword_B6F68C )
        v5 = WindowName;
      sub_613D30((int)v22, "Scene=%s\n", (char)v5);
      LOBYTE(v6) = dword_B6F6C4[0];
      if ( !*(_DWORD *)dword_B6F6C4 )
        v6 = WindowName;
      sub_613D30((int)v22, "AIDB=%s\n", (char)v6);
      v18 = flt_B728A4;
      sub_613D30((int)v22, "Race Length=%.3f\n", SLOBYTE(v18));
      v19 = flt_91BDE4;
      sub_613D30((int)v22, "Track Length=%.4f\n", SLOBYTE(v19));
      sub_613D30((int)v22, (char *)word_6F2E64, v14);
      if ( !byte_B72D9C )
        sub_473630(&dword_B6CBA8);
      sub_613C30(v22);
    }
    v33 = 0;
    sub_614140(v22);
  }
  if ( Block )
    j_j__free(Block);
}
