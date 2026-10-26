char __thiscall sub_4D55D0(int this, _DWORD *a2, signed int a3)
{
  char result; // al
  signed int v5; // edi
  signed int v6; // eax
  const CHAR *v7; // eax
  int v8; // eax
  _BYTE v9[253]; // [esp+18h] [ebp-100h] BYREF
  __int16 v10; // [esp+115h] [ebp-3h]
  char v11; // [esp+117h] [ebp-1h]

  result = 0;
  if ( a2[1] )
  {
    memset(v9, 0, sizeof(v9));
    v10 = 0;
    v11 = 0;
    v5 = a3;
    v6 = 0;
    if ( a3 > 0 )
    {
      memset(v9, 0x20u, a3);
      v6 = a3;
      v5 = a3;
    }
    v9[v6] = 0;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "%s%s\n", v9, "CUSTOMDATA");
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "%s{\n", v9);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s%s=%d\n", v9, "TabWidth", *(_DWORD *)(this + 296));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s%s=%d\n", v9, "TabHeight", *(_DWORD *)(this + 300));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=%d\n",
      v9,
      "TabSpaceHorizontal",
      *(_DWORD *)(this + 304));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=%d\n",
      v9,
      "TabSpaceVertical",
      *(_DWORD *)(this + 308));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "ColorNotSelected_ARGB",
      HIBYTE(*(_DWORD *)(this + 312)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 312)),
      BYTE1(*(_DWORD *)(this + 312)),
      (unsigned __int8)*(_DWORD *)(this + 312));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "ColorSelected_ARGB",
      HIBYTE(*(_DWORD *)(this + 316)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 316)),
      BYTE1(*(_DWORD *)(this + 316)),
      (unsigned __int8)*(_DWORD *)(this + 316));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "ColorRollover_ARGB",
      HIBYTE(*(_DWORD *)(this + 320)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 320)),
      BYTE1(*(_DWORD *)(this + 320)),
      (unsigned __int8)*(_DWORD *)(this + 320));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=%.3f\n",
      v9,
      "RolloverPulseTime",
      *(float *)(this + 324));
    v7 = *(const CHAR **)(this + 288);
    if ( !v7 )
      v7 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "  %s%s=\"%s\"\n", v9, "Texture", v7);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=%.3f\n",
      v9,
      "TabFontScale",
      *(float *)(this + 328));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "TabFontColorNotSelected",
      HIBYTE(*(_DWORD *)(this + 332)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 332)),
      BYTE1(*(_DWORD *)(this + 332)),
      (unsigned __int8)*(_DWORD *)(this + 332));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "TabFontColorSelected",
      HIBYTE(*(_DWORD *)(this + 336)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 336)),
      BYTE1(*(_DWORD *)(this + 336)),
      (unsigned __int8)*(_DWORD *)(this + 336));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
      a2,
      "  %s%s=(%d, %d, %d, %d)\n",
      v9,
      "TabFontColorRollover",
      HIBYTE(*(_DWORD *)(this + 340)),
      (unsigned __int8)BYTE2(*(_DWORD *)(this + 340)),
      BYTE1(*(_DWORD *)(this + 340)),
      (unsigned __int8)*(_DWORD *)(this + 340));
    v8 = *(_DWORD *)(this + 268);
    if ( v8 )
      sub_4D34A0(v8, (int)a2, v5 + 2);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "%s}\n", v9);
    return 1;
  }
  return result;
}
