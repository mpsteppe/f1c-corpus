char __thiscall sub_4DA0D0(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // esi
  unsigned int v5; // eax
  CHAR *v6; // eax
  CHAR v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // ebp
  int v11; // eax
  unsigned int v12; // eax
  CHAR *v13; // eax
  CHAR v14; // cl
  int v15; // eax
  char v16; // cl
  int v17; // ebp
  int v18; // eax
  unsigned int v20; // [esp+18h] [ebp-90h]
  int v21; // [esp+1Ch] [ebp-8Ch]
  char v22[8]; // [esp+20h] [ebp-88h] BYREF
  CHAR v23[128]; // [esp+28h] [ebp-80h] BYREF

  LOBYTE(v2) = *(_BYTE *)(this + 24);
  if ( (_BYTE)v2 )
  {
    v3 = dword_7C54E0;
    v4 = *(_DWORD *)(this + 28);
    v21 = dword_7C54E0;
  }
  else
  {
    v2 = *(_DWORD *)(this + 28);
    v4 = dword_7C54E0;
    v21 = v2;
    v3 = v2;
  }
  if ( v4 && v3 )
  {
    v5 = *(_DWORD *)(v4 + 16480) - 1;
    if ( v5 <= 0x18 )
    {
      StringFormatWithBufferOverflowCheck(v23, (int)"%c", (char)(v5 + byte_5D4AE8));
      UITextRenderWithScale((int)v23, 100, 818, 0xFFFFFF, 0, 3, 3.0, 3.0);
    }
    v6 = (CHAR *)(v4 + 18168);
    do
    {
      v7 = *v6;
      v23[(_DWORD)v6 - 18168 - v4] = *v6;
      ++v6;
    }
    while ( v7 );
    sub_589901(v23);
    UITextRenderWithScale((int)v23, 210, 818, 0xFFFFFF, 0, 0, 1.0, 1.0);
    v8 = 0;
    do
    {
      v9 = byte_5EA438[v8];
      v23[v8++] = v9;
    }
    while ( v9 );
    v10 = 0;
    if ( dword_5D4AF4 > 0 )
    {
      do
      {
        StringFormatWithBufferOverflowCheck(v22, (int)"%c", v10 + byte_5D4AF0);
        v20 = strlen(v22) + 1;
        v11 = dword_5D4AF4;
        qmemcpy(&v23[strlen(v23)], v22, v20);
        ++v10;
      }
      while ( v10 < v11 );
      v3 = v21;
    }
    UITextRenderWithScale((int)v23, 210, 868, 0xFFFFFF, 0, 3, 1.0, 1.0);
    StringFormatWithBufferOverflowCheck(v23, (int)"%6.3f", (double)fabs(*(float *)(this + 20)));
    UITextRenderWithScale((int)v23, 640, 858, 16776960, 2, 0, 1.0, 1.0);
    v12 = *(_DWORD *)(v3 + 16480) - 1;
    if ( v12 <= 0x18 )
    {
      StringFormatWithBufferOverflowCheck(v23, (int)"%c", (char)(v12 + byte_5D4AE8));
      UITextRenderWithScale((int)v23, 1180, 818, 0xFFFFFF, 1, 3, 3.0, 3.0);
    }
    v13 = (CHAR *)(v3 + 18168);
    do
    {
      v14 = *v13;
      v23[(_DWORD)v13 - 18168 - v3] = *v13;
      ++v13;
    }
    while ( v14 );
    sub_589901(v23);
    UITextRenderWithScale((int)v23, 1070, 818, 0xFFFFFF, 1, 0, 1.0, 1.0);
    v15 = 0;
    do
    {
      v16 = byte_5EA438[v15];
      v23[v15++] = v16;
    }
    while ( v16 );
    v17 = 0;
    if ( dword_5D4AF4 > 0 )
    {
      do
      {
        StringFormatWithBufferOverflowCheck(v22, (int)"%c", v17 + byte_5D4AF1);
        v20 = strlen(v22) + 1;
        v18 = dword_5D4AF4;
        qmemcpy(&v23[strlen(v23)], v22, v20);
        ++v17;
      }
      while ( v17 < v18 );
    }
    LOBYTE(v2) = UITextRenderWithScale((int)v23, 1070, 868, 0xFFFFFF, 1, 3, 1.0, 1.0);
  }
  return v2;
}
