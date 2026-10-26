void __thiscall sub_66278D(double *this, double *a2, double *a3, double *a4, char a5)
{
  int v5; // ebx
  double *v6; // edi
  double *v7; // eax
  double v8[4]; // [esp+14h] [ebp-20h] BYREF

  v8[0] = *a3 * *a4;
  v5 = 0;
  v8[1] = *a3 * a4[1];
  v8[2] = *a4 * a3[1];
  v8[3] = a3[1] * a4[1];
  *a2 = this[20];
  a2[1] = this[21];
  while ( 1 )
  {
    v6 = &v8[v5];
    if ( _isnan(*v6) )
      break;
LABEL_5:
    if ( *a2 > *v6 )
      *a2 = *v6;
    if ( a2[1] < *v6 )
      a2[1] = *v6;
    if ( (unsigned int)++v5 >= 4 )
      return;
  }
  if ( (a5 & 0x40) == 0 )
  {
    *v6 = 0.0;
    goto LABEL_5;
  }
  v7 = &v8[v5];
  *a2 = *v7;
  a2[1] = *v7;
}
