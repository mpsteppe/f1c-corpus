void __thiscall sub_438C10(char *this, char *a2)
{
  bool v3; // zf

  v3 = *a2 == 0;
  *this = *a2;
  if ( !v3 )
  {
    *((_DWORD *)this + 1) = *((_DWORD *)a2 + 7);
    *((_DWORD *)this + 2) = *((_DWORD *)a2 + 8);
    *((_DWORD *)this + 3) = *((_DWORD *)a2 + 9);
    *((_DWORD *)this + 4) = *((_DWORD *)a2 + 10);
    *((_DWORD *)this + 5) = *((_DWORD *)a2 + 11);
    *((_DWORD *)this + 6) = *((_DWORD *)a2 + 12);
    *((_DWORD *)this + 7) = *((_DWORD *)a2 + 1);
    *((_DWORD *)this + 8) = *((_DWORD *)a2 + 2);
    *((_DWORD *)this + 9) = *((_DWORD *)a2 + 3);
    *((_DWORD *)this + 10) = *((_DWORD *)a2 + 4);
    *((_DWORD *)this + 11) = *((_DWORD *)a2 + 5);
    *((_DWORD *)this + 12) = *((_DWORD *)a2 + 6);
    sub_438AF0(
      (double *)(this + 68),
      *((_DWORD *)a2 + 13),
      *((_DWORD *)a2 + 14),
      *(double *)(a2 + 60),
      *(double *)(a2 + 68));
    *((_DWORD *)this + 25) = 0;
    *((_DWORD *)this + 26) = 0;
    *((_DWORD *)this + 27) = 0;
    *((_DWORD *)this + 28) = 0;
    *((_DWORD *)this + 29) = 0;
    *((_DWORD *)this + 30) = 0;
  }
}
