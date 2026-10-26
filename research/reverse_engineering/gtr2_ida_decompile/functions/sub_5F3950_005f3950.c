int __thiscall sub_5F3950(int this, int *a2, int a3, LONG a4, int a5, int a6, FILE *Stream)
{
  FILE *v8; // eax
  int v9; // eax
  LONG x; // esi
  LONG y; // edi
  LONG v13; // ecx
  struct tagRECT *p_Rect; // eax
  int v15; // [esp+24h] [ebp-134h]
  char v16; // [esp+28h] [ebp-130h]
  struct tagRECT Rect; // [esp+34h] [ebp-124h] BYREF
  int v18; // [esp+44h] [ebp-114h] BYREF
  struct tagPOINT Point; // [esp+48h] [ebp-110h] BYREF
  WCHAR Buffer[128]; // [esp+58h] [ebp-100h] BYREF

  if ( Stream )
  {
    sprintf((char *const)Buffer, "%s", (const char *)Stream);
  }
  else
  {
    while ( 1 )
    {
      v15 = dword_FB2E9C++;
      if ( byte_FB2D8C )
        sprintf((char *const)Buffer, "%s\\GRAB_%.3d.BMP", &byte_FB2D8C, v15);
      else
        sprintf((char *const)Buffer, "GRAB_%.3d.BMP", v15);
      v8 = fopen((const char *)Buffer, "r");
      if ( !v8 )
        break;
      fclose(v8);
    }
  }
  if ( !_stricmp((const char *)Buffer, "shadowmap.dds") )
  {
    v9 = sub_5E7120(a2, 2);
    sub_644996(Buffer, 4, v9, 0, 0);
    return 0;
  }
  x = a2[1];
  y = a2[2];
  if ( *(_DWORD *)(this + 9432)
    && !(*(int (__stdcall **)(_DWORD, _DWORD, struct tagPOINT *))(**(_DWORD **)(this + 9548) + 32))(
          *(_DWORD *)(this + 9548),
          0,
          &Point) )
  {
    x = Point.x;
    y = Point.y;
  }
  if ( (*(int (__stdcall **)(_DWORD, LONG, LONG, int, int, int *, _DWORD))(**(_DWORD **)(this + 9548) + 144))(
         *(_DWORD *)(this + 9548),
         x,
         y,
         21,
         2,
         &v18,
         0) )
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error creating screen save surface", v16);
    return -1;
  }
  if ( (*(int (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 9548) + 132))(*(_DWORD *)(this + 9548), 0, v18) )
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error getting front buffer data to surface", v16);
    return -1;
  }
  if ( *(_DWORD *)(this + 9432) )
  {
    GetWindowRect(dword_FB2784, &Rect);
    Point.x = 0;
    Point.y = 0;
    ClientToScreen(dword_FB2784, &Point);
    if ( a3 || a4 || a5 || a6 )
    {
      Rect.left = Point.x + a3;
      Rect.right = a5 + Point.x + a3;
      Rect.top = a4 + Point.y;
      Rect.bottom = a6 + a4 + Point.y;
LABEL_34:
      p_Rect = &Rect;
      goto LABEL_35;
    }
    Rect.left = Point.x;
    Rect.right -= 3;
    Rect.top = Point.y;
    v13 = Rect.bottom - 3;
LABEL_33:
    Rect.bottom = v13;
    goto LABEL_34;
  }
  if ( a3 || a4 || a5 || a6 )
  {
    Rect.left = a4;
    v13 = a6 + a4;
    Rect.top = a3;
    Rect.right = a5 + a3;
    goto LABEL_33;
  }
  p_Rect = 0;
LABEL_35:
  if ( sub_644996(Buffer, 0, v18, 0, (int)p_Rect) )
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error saving surface to file %s", (char)Stream);
    return -1;
  }
  if ( !(*(int (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18) )
    return 0;
  sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error releasing screen save surface", v16);
  return -1;
}
