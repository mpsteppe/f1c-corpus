char __thiscall sub_45DB30(unsigned __int8 *this, int a2, _DWORD *a3)
{
  unsigned __int8 *v3; // ebp
  int v4; // edi
  char *v5; // ebx
  int v6; // esi
  const char *v7; // eax

  v3 = this;
  v4 = 0;
  if ( dword_7D7918 <= 0 )
  {
LABEL_9:
    *a3 = 0;
    return 0;
  }
  v5 = (char *)a2;
  while ( 1 )
  {
    v6 = sub_500D60(v4);
    v7 = *(const char **)(v6 + 24);
    if ( !v7 )
      v7 = &byte_629120;
    if ( _strcmpi(v5, v7) )
      goto LABEL_8;
    if ( (unsigned __int8)sub_57B490(v5, v3[1], (int)&a2) )
      break;
    v3 = this;
LABEL_8:
    if ( ++v4 >= dword_7D7918 )
      goto LABEL_9;
  }
  *a3 = *(_DWORD *)(v6 + 32) + a2 + 279175584;
  return 1;
}
