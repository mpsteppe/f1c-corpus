int __thiscall sub_499929(int this)
{
  unsigned int v1; // kr00_4
  int result; // eax

  v1 = __getcallerseflags();
  result = *(_DWORD *)(dword_16C6E14 + 1321720321);
  __writeeflags(v1);
  if ( result
    || dword_BE1D0C
    && (dword_BE1D10 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_BE1D0C + 96))(dword_BE1D0C),
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_BE1D10 + 28))(dword_BE1D10, LODWORD(flt_B709FC)),
        (result = dword_BE1D10) != 0) )
  {
    *(_BYTE *)(this + 16) = 1;
    *(_DWORD *)(this + 20) = 0;
    return (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_BE1D10 + 28))(dword_BE1D10, LODWORD(flt_B709FC));
  }
  return result;
}
