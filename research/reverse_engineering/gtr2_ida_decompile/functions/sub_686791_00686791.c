int sub_686791(int a1, int a2, int a3, char *Format, ...)
{
  int v4; // eax
  int v5; // edx
  char Buffer[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+118h] [ebp+18h] BYREF

  va_start(va, Format);
  _vsnprintf(Buffer, 0x100u, Format, va);
  v4 = 0;
  Buffer[255] = 0;
  if ( a2 )
  {
    v5 = *(_DWORD *)(a2 + 4);
    switch ( v5 )
    {
      case 3:
        v4 = a2 + 16;
        break;
      case 6:
        v4 = *(_DWORD *)(a2 + 20) + 16;
        break;
      case 13:
        v4 = a2 + 48;
        break;
    }
  }
  sub_65DD1F(*(_DWORD **)(a1 + 196), v4, a3, "%s", Buffer);
  *(_DWORD *)(a1 + 212) = 1;
  return 0;
}
