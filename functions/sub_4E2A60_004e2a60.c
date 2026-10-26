void __thiscall sub_4E2A60(char **this)
{
  int v1; // eax
  char *v2; // edx
  char *v3; // esi
  char **v4; // ecx

  v1 = dword_8AC394 + 1060 * *((_DWORD *)*this + 4646);
  v2 = 0;
  if ( *this == (char *)dword_7C54E8 )
  {
    v2 = (char *)dword_7CFE0C;
    if ( !dword_7CFE0C )
      v2 = byte_5EA438;
  }
  v3 = this[36];
  v4 = this + 36;
  if ( !v3 )
    v3 = byte_5EA438;
  if ( *v3 )
  {
    v2 = *v4;
    if ( !*v4 )
      v2 = byte_5EA438;
  }
  PitCrewInstanceSetup(v1, v2, (int)v4, 0);
}
