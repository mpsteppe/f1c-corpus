char __thiscall sub_5325D0(int this, _DWORD *a2, int a3)
{
  int i; // ebx
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  if ( a2[1] )
  {
    if ( a3 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*a2 + 40))(a2, a3);
      (*(void (__thiscall **)(_DWORD *, const char *))(*a2 + 40))(a2, word_6F2E64);
    }
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "SeasonStatus=%d\n", *(_DWORD *)(this + 95732));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "RaceSession=%d\n", *(_DWORD *)(this + 95740));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "RaceQuarter=%d\n", *(_DWORD *)(this + 95760));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "RaceOver=%d\n", *(_BYTE *)(this + 95744) != 0);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "CurrentRace=%d\n", *(_DWORD *)(this + 95736));
    sub_531AB0((const CHAR **)(this + 94760), a2, (int)"[PLAYER]");
    for ( i = 0; i < 103; ++i )
    {
      if ( *(_BYTE *)(this + 840) )
      {
        sprintf(Buffer, "%s%2.2d]", "[OPPONENT", i);
        sub_531AB0((const CHAR **)this, a2, (int)Buffer);
      }
      this += 920;
    }
    (*(void (__cdecl **)(_DWORD *, const char *))(*a2 + 32))(a2, word_6F2E64);
  }
  return 0;
}
