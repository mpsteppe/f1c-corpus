char __thiscall sub_531AB0(const CHAR **this, _DWORD *a2, int a3)
{
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  int v7; // edi
  float *v8; // ebx

  if ( a2[1] )
  {
    if ( a3 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*a2 + 40))(a2, a3);
      (*(void (__thiscall **)(_DWORD *, const char *))(*a2 + 40))(a2, word_6F2E64);
    }
    v4 = *this;
    if ( !*this )
      v4 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "Name=\"%s\"\n", v4);
    v5 = this[2];
    if ( !v5 )
      v5 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "VehFile=\"%s\"\n", v5);
    v6 = this[4];
    if ( !v6 )
      v6 = WindowName;
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "RCDFile=\"%s\"\n", v6);
    v7 = 0;
    v8 = (float *)(this + 6);
    do
    {
      if ( *(int *)v8 < 0 )
        break;
      (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "FinishPosition%2.2d=%d\n", v7, *(_DWORD *)v8);
      (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "FinishPoints%2.2d=%f\n", v7, v8[48]);
      (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(
        a2,
        "CategoryFinishPosition%2.2d=%d\n",
        v7,
        *((_DWORD *)v8 + 96));
      (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "CategoryFinishPoints%2.2d=%f\n", v7++, v8[144]);
      ++v8;
    }
    while ( v7 < 48 );
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "SeasonPoints=%f\n", *((float *)this + 198));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "PointsPosition=%d\n", this[200]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "CategorySeasonPoints=%f\n", *((float *)this + 199));
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "CategoryPointsPosition=%d\n", this[201]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "PolesTaken=%d\n", this[202]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "OriginalGridPosition=%d\n", this[203]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "CurrentGridPosition=%d\n", this[204]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "TempGridPosition=%d\n", this[205]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "WeightPenalty=%d\n", this[206]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "LastRaceDQ=%d\n", *((_BYTE *)this + 828) != 0);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "LastRaceLapsDown=%d\n", this[208]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "ControlType=%d\n", this[209]);
    (*(void (**)(_DWORD *, const char *, ...))(*a2 + 32))(a2, "Active=%d\n", *((_BYTE *)this + 840) != 0);
    (*(void (__cdecl **)(_DWORD *, const char *))(*a2 + 32))(a2, word_6F2E64);
  }
  return 0;
}
