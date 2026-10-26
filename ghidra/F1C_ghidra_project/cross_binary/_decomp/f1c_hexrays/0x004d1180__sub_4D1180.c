// f1c  0x004d1180  size=79
char __stdcall sub_4D1180(_DWORD *a1, float *a2, _DWORD *a3)
{
  if ( dword_7C56A4 == 7 && (dword_7C56A8 == 2 || dword_7C56A8 == 3 || dword_7C56A8 == 4) )
  {
    sub_4D10E0((int)a1, a2, a3);
    return 1;
  }
  else
  {
    sub_4D1140(a1, a2, a3);
    return 0;
  }
}
