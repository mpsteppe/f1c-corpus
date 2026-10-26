void __thiscall sub_573B50(char *this)
{
  int *v2; // eax
  char *v3; // ebp
  int i; // eax
  int v5; // eax
  int *v6; // eax

  *(_DWORD *)this = off_5F6398;
  v2 = (int *)*((_DWORD *)this + 71);
  v3 = this + 284;
  *((_DWORD *)this + 73) = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v6 )
    {
      sub_5765C0(i, 0);
      v5 = *((_DWORD *)v3 + 2);
      if ( !v5 )
        break;
      v6 = *(int **)(v5 + 4);
      *((_DWORD *)v3 + 2) = v6;
      if ( !v6 )
        break;
    }
  }
  if ( this[1608] && CloseHandle(*((HANDLE *)this + 400)) )
    *((_DWORD *)this + 400) = 0;
  sub_577160(this + 1572);
  if ( this[1568] && CloseHandle(*((HANDLE *)this + 390)) )
    *((_DWORD *)this + 390) = 0;
  if ( this[1472] && CloseHandle(*((HANDLE *)this + 366)) )
    *((_DWORD *)this + 366) = 0;
  if ( this[1456] && CloseHandle(*((HANDLE *)this + 362)) )
    *((_DWORD *)this + 362) = 0;
  sub_576730(this + 1432);
  if ( this[1428] && CloseHandle(*((HANDLE *)this + 355)) )
    *((_DWORD *)this + 355) = 0;
  sub_576730(this + 1404);
  if ( this[1400] && CloseHandle(*((HANDLE *)this + 348)) )
    *((_DWORD *)this + 348) = 0;
  sub_576730(this + 1376);
  sub_576480(this + 1348);
  sub_576730(this + 1348);
  nullsub_6(this + 300);
  sub_5762D0(v3);
  sub_5762D0(this + 268);
  sub_5762D0(this + 268);
  sub_5766B0(this + 252);
  if ( this[248] && CloseHandle(*((HANDLE *)this + 60)) )
    *((_DWORD *)this + 60) = 0;
  if ( this[220] && CloseHandle(*((HANDLE *)this + 53)) )
    *((_DWORD *)this + 53) = 0;
  sub_5736C0((int)(this + 132));
  `eh vector destructor iterator'(this + 4, 0x28u, 1, sub_573B10);
}
