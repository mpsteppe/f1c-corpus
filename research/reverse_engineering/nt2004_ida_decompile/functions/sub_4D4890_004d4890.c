int __thiscall sub_4D4890(int this, int a2)
{
  unsigned int v3; // edx
  unsigned int v4; // kr04_4
  char *v5; // esi
  int v6; // edi
  char *v7; // eax
  void *v8; // esi
  int v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  char Source[512]; // [esp+10h] [ebp-200h] BYREF

  sub_4D3ED0((_DWORD *)this);
  strncpy((char *)(this + 1), (const char *)(a2 + 24772), 0x3Fu);
  v3 = a2 + 24992;
  *(_BYTE *)(this + 64) = 0;
  v4 = strlen((const char *)(a2 + 24992)) + 1;
  v5 = (char *)(a2 + 24992 + v4 - 1);
  if ( v3 + v4 - 1 > v3 )
  {
    while ( *v5 != 92 )
    {
      if ( (unsigned int)--v5 <= v3 )
        goto LABEL_6;
    }
    ++v5;
  }
LABEL_6:
  strncpy((char *)(this + 65), v5, 0x1Fu);
  *(_BYTE *)(this + 96) = 0;
  *(_BYTE *)(this + 97) = 0;
  v6 = *(_DWORD *)(a2 + 2040);
  sub_4E76F0(v5);
  if ( sub_4E7760(&unk_7D6A50) && (unsigned __int8)sub_4E7140(v6, Source, 512) )
  {
    v7 = &Source[strlen(Source)];
    if ( v7 > Source )
    {
      while ( *v7 != 92 )
      {
        if ( --v7 <= Source )
          goto LABEL_13;
      }
      ++v7;
    }
LABEL_13:
    strncpy((char *)(this + 97), v7, 0x1Fu);
    *(_BYTE *)(this + 128) = 0;
  }
  v8 = *(void **)(this + 140);
  if ( v8 )
  {
    sub_4D4A50(*(_DWORD *)(this + 140));
    sub_5BE8AE(v8);
    *(_DWORD *)(this + 140) = 0;
  }
  v9 = a2;
  if ( *(_DWORD *)(a2 + 2044) )
  {
    v10 = operator new(0x58u);
    v11 = v10;
    if ( v10 )
    {
      *v10 = 0;
      v10[1] = -1;
      v10[2] = 0;
      v10[3] = -1;
      v10[4] = 0;
      v10[5] = -1;
      sub_578600(a100);
      v11[6] = 0;
      v11[7] = -1;
      v11[8] = 0;
      v11[9] = -1;
      v11[10] = 0;
      v11[11] = 0;
      v11[12] = 0;
      v11[13] = 0;
      sub_414400(v11 + 14);
      sub_414400(v11 + 18);
      v9 = a2;
    }
    else
    {
      v11 = 0;
    }
    *(_DWORD *)(this + 140) = v11;
    sub_509660(*(_DWORD *)(v9 + 2044));
  }
  *(_BYTE *)this = *(_BYTE *)(v9 + 25248);
  return this;
}
