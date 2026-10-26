void __stdcall sub_5F5F30(int a1)
{
  char *v1; // esi
  int v2; // edi
  int v3; // ebx

  if ( a1 < dword_910EF8 )
  {
    v1 = (char *)dword_FB277C + 96 * a1;
    if ( *((double *)v1 + 1) != 0.0 )
    {
      sub_5F5760((double *)v1, (LONG *)v1 + 11, (DWORD *)v1 + 10, 0);
      v2 = *((_DWORD *)v1 + 10);
      *((double *)v1 + 3) = 0.0;
      v3 = *((_DWORD *)v1 + 11);
      *((_DWORD *)v1 + 12) = v2;
      *((_DWORD *)v1 + 16) = v2;
      *((_DWORD *)v1 + 13) = v3;
      *((_DWORD *)v1 + 17) = v3;
      *((_DWORD *)v1 + 14) = 0;
      *((_DWORD *)v1 + 15) = 0;
    }
  }
}
