void __thiscall sub_5A66A0(char *this)
{
  int *v2; // eax
  int v3; // edi
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int *v8; // eax

  *(_DWORD *)this = off_7263F0;
  v2 = (int *)*((_DWORD *)this + 75);
  *((_DWORD *)this + 77) = v2;
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      do
      {
        v4 = operator new(0xCu);
        if ( v4 )
        {
          *v4 = v3;
          v4[1] = 0;
          *((_BYTE *)v4 + 8) = 0;
        }
        else
        {
          v4 = 0;
        }
        v5 = *((_DWORD *)this + 71);
        if ( v5 )
        {
          v4[1] = v5;
        }
        else
        {
          *((_DWORD *)this + 72) = v4;
          *((_DWORD *)this + 73) = v4;
        }
        v6 = *((_DWORD *)this + 74) + 1;
        *((_DWORD *)this + 71) = v4;
        *((_DWORD *)this + 74) = v6;
        v7 = *((_DWORD *)this + 77);
        if ( !v7 )
          break;
        v8 = *(int **)(v7 + 4);
        *((_DWORD *)this + 77) = v8;
        if ( !v8 )
          break;
        v3 = *v8;
      }
      while ( *v8 );
    }
  }
  if ( this[1624] && CloseHandle(*((HANDLE *)this + 404)) )
    *((_DWORD *)this + 404) = 0;
  sub_5A6D70(this + 1588);
  if ( this[1584] && CloseHandle(*((HANDLE *)this + 394)) )
    *((_DWORD *)this + 394) = 0;
  if ( this[1488] && CloseHandle(*((HANDLE *)this + 370)) )
    *((_DWORD *)this + 370) = 0;
  if ( this[1472] && CloseHandle(*((HANDLE *)this + 366)) )
    *((_DWORD *)this + 366) = 0;
  sub_59FA70((int *)this + 362);
  if ( this[1444] && CloseHandle(*((HANDLE *)this + 359)) )
    *((_DWORD *)this + 359) = 0;
  sub_59FA70((int *)this + 355);
  if ( this[1416] && CloseHandle(*((HANDLE *)this + 352)) )
    *((_DWORD *)this + 352) = 0;
  sub_59FA70((int *)this + 348);
  if ( this[1388] && CloseHandle(*((HANDLE *)this + 345)) )
    *((_DWORD *)this + 345) = 0;
  sub_59FA70((int *)this + 341);
  nullsub_7(this + 316);
  sub_5A4DF0((int *)this + 75);
  sub_5A6380((int *)this + 67);
  if ( this[264] && CloseHandle(*((HANDLE *)this + 64)) )
    *((_DWORD *)this + 64) = 0;
  if ( this[232] && CloseHandle(*((HANDLE *)this + 56)) )
    *((_DWORD *)this + 56) = 0;
  nullsub_7(this + 144);
  `eh vector destructor iterator'(this + 8, 0x28u, 1, sub_5A4660);
}
