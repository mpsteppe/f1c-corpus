int __stdcall sub_4DB7F0(char a1, int a2, int a3)
{
  char *v3; // ebp
  int v4; // edi
  int v5; // ebx
  char *v7; // [esp+10h] [ebp-Ch]
  char *v8; // [esp+14h] [ebp-8h]
  char *v9; // [esp+18h] [ebp-4h]

  v3 = (char *)&loc_444444 + ((a1 & 1) != 0 ? 0xFFBCBABC : 0);
  v7 = (char *)&loc_444444 + ((a1 & 2) != 0 ? 0xBBBABC : 0);
  v8 = (char *)&loc_444444 + ((a1 & 4) != 0 ? 0xBB87BC : 0);
  v9 = (char *)&loc_444444 + ((a1 & 8) != 0 ? 0xBABBBC : 0);
  StringFormatWithBufferOverflowCheck(&a1, "%c", byte_5D4AE9);
  v4 = a3;
  v5 = a2;
  UITextRenderWithScale((int)&a1, a2 - 163, a3, (int)v3, 0, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 + 163, v4, (int)v3, 1, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 - 136, v4, (int)v7, 0, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 + 136, v4, (int)v7, 1, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 - 109, v4, (int)v8, 0, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 + 109, v4, (int)v8, 1, 3, 1.0, 1.0);
  UITextRenderWithScale((int)&a1, v5 - 82, v4, (int)v9, 0, 3, 1.0, 1.0);
  return UITextRenderWithScale((int)&a1, v5 + 82, v4, (int)v9, 1, 3, 1.0, 1.0);
}
