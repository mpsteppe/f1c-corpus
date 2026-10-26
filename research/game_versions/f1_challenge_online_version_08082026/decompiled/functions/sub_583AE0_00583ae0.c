int __thiscall sub_583AE0(char *this)
{
  int *v2; // eax
  char *v3; // ebp
  int i; // eax
  int v5; // eax
  int *v6; // eax

  *(_DWORD *)this = off_5B8B60;
  v2 = (int *)*((_DWORD *)this + 71);
  v3 = this + 284;
  *((_DWORD *)this + 73) = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v6 )
    {
      sub_583210((_DWORD *)this + 67, i, 0);
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
  sub_5870D0(this + 1572);
  if ( this[1568] && CloseHandle(*((HANDLE *)this + 390)) )
    *((_DWORD *)this + 390) = 0;
  if ( this[1472] && CloseHandle(*((HANDLE *)this + 366)) )
    *((_DWORD *)this + 366) = 0;
  if ( this[1456] && CloseHandle(*((HANDLE *)this + 362)) )
    *((_DWORD *)this + 362) = 0;
  sub_5833E0((_DWORD *)this + 358);
  if ( this[1428] && CloseHandle(*((HANDLE *)this + 355)) )
    *((_DWORD *)this + 355) = 0;
  sub_5833E0((_DWORD *)this + 351);
  if ( this[1400] && CloseHandle(*((HANDLE *)this + 348)) )
    *((_DWORD *)this + 348) = 0;
  sub_5833E0((_DWORD *)this + 344);
  sub_582310((int)(this + 1348));
  sub_5833E0((_DWORD *)this + 337);
  nullsub_3();
  sub_585FB0(v3);
  sub_585FB0(this + 268);
  sub_585FB0(this + 268);
  sub_586460(this + 252);
  if ( this[248] && CloseHandle(*((HANDLE *)this + 60)) )
    *((_DWORD *)this + 60) = 0;
  if ( this[220] && CloseHandle(*((HANDLE *)this + 53)) )
    *((_DWORD *)this + 53) = 0;
  sub_583650();
  return sub_58A5F7(this + 4, 40, 1, sub_583AA0);
}
