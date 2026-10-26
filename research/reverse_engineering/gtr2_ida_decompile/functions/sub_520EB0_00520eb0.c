double __thiscall sub_520EB0(_DWORD *this, float a2)
{
  float v2; // esi
  int v4; // eax
  double v5; // st7
  char v7[8]; // [esp+10h] [ebp-8h] BYREF

  v2 = a2;
  (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(a2) + 44))(COERCE_FLOAT(LODWORD(a2)));
  v4 = *(_DWORD *)LODWORD(v2);
  strcpy(v7, "xxxx");
  a2 = -1.0;
  (*(void (__thiscall **)(float, char *, int))(v4 + 28))(COERCE_FLOAT(LODWORD(v2)), v7, 4);
  (*(void (__thiscall **)(float, float *, int))(*(_DWORD *)LODWORD(v2) + 28))(COERCE_FLOAT(LODWORD(v2)), &a2, 4);
  if ( this[723229] == 1 )
  {
    if ( strcmp(v7, off_9034C4) )
      return 0.0;
    v5 = flt_9034C8;
  }
  else
  {
    if ( strcmp(v7, off_9034B0) )
      return 0.0;
    if ( a2 == flt_9034B4 || a2 == flt_9034B8 || a2 == flt_9034BC )
      return a2;
    v5 = flt_9034C0;
  }
  if ( a2 == v5 )
    return a2;
  return 0.0;
}
