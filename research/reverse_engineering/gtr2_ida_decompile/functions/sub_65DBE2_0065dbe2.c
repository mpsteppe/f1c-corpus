int __thiscall sub_65DBE2(_DWORD *this, char *a2, int *a3)
{
  char *v3; // edi
  int v4; // ebx
  int v6; // eax
  int v7; // [esp-4h] [ebp-10h]

  v3 = a2;
  v4 = 5;
  if ( (unsigned int)a2 >= this[1] )
    return 0;
  v6 = sub_635155(*a2) - 102;
  if ( !v6 )
  {
    v7 = 7;
    goto LABEL_7;
  }
  if ( v6 == 2 )
  {
    v7 = 6;
LABEL_7:
    v4 = v7;
    v3 = a2 + 1;
  }
  if ( a3 )
    *a3 = v4;
  return v3 - a2;
}
