void __thiscall sub_498440(int this, const char *a2)
{
  int v3; // edi
  int v4; // ebp
  int v5; // eax
  HWND DesktopWindow; // eax
  HWND v7; // eax
  char *v8; // eax
  char v9; // cl
  CHAR Text[128]; // [esp+10h] [ebp-80h] BYREF

  if ( a2 && strlen(a2) )
  {
    DriverNameStringHandler((_DWORD *)this, a2);
    v3 = 0;
    if ( *(int *)(this + 5396) <= 0 )
    {
LABEL_8:
      DesktopWindow = GetDesktopWindow();
      MessageBoxA(DesktopWindow, ::Text, aError, 0);
    }
    else
    {
      v4 = this + 276;
      do
      {
        if ( !sub_588410(v4, a2) )
        {
          strcpy((char *)(this + 5740), a2);
          return;
        }
        v5 = *(_DWORD *)(this + 5396);
        ++v3;
        v4 += 80;
      }
      while ( v3 < v5 );
      if ( v5 <= 0 )
        goto LABEL_8;
      StringFormatWithBufferOverflowCheck(
        Text,
        "Specified system font \"%s\" not found, using \"%s\" instead",
        a2,
        (const char *)(this + 276));
      v7 = GetDesktopWindow();
      MessageBoxA(v7, Text, aError, 0);
      v8 = (char *)(this + 276);
      do
      {
        v9 = *v8;
        v8[5464] = *v8;
        ++v8;
      }
      while ( v9 );
    }
  }
}
